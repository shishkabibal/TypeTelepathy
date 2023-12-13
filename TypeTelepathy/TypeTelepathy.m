//
//  TypeTelepathy.m
//  TypeTelepathy
//
//  Created by Brian "Shishkabibal" on 12/9/23.
//  Copyright (c) 2023 Brian "Shishkabibal". All rights reserved.
//

#pragma mark - Library/Header Imports

@import AppKit;

#import <objc/runtime.h>

#import "IMTextMessagePartChatItem.h"
#import "IMHandle.h"
#import "IMPerson.h"
#import "IMAccount.h"
#import "IMAccountController.h"
#import "IMService.h"
#import "IMChat.h"
#import "IMMessage.h"
#import "IMMessageItem.h"
#import "IMMessageItem-IMChat_Internal.h"
#import "IMChatRegistry.h"
#import "IMHandleRegistrar.h"
#import "IMCore.h"
#import "IMChatHistoryController.h"
#import "IMPinnedConversationsController.h"
#import "IMDPersistentAttachmentController.h"
#import "IMFileTransfer.h"
#import "IMFileTransferCenter.h"
#import "IMAggregateAttachmentMessagePartChatItem.h"
#import "IMTranscriptPluginChatItem.h"
#import "ETiOSMacBalloonPluginDataSource.h"
#import "HWiOSMacBalloonDataSource.h"
#import "IMHandleAvailabilityManager.h"
#import "IDSIDQueryController.h"
#import "IDS.h"
#import "IDSDestination-Additions.h"
#import "IMDDController.h"
#import "IMNicknameController.h"
#import "IMNickname.h"
#import "IMNicknameAvatarImage.h"
#import "IMFMFSession.h"
#import "FMFSession.h"
#import "FMFLocation.h"

#import "ZKSwizzle.h"

#include <os/log.h>
#define DLog(N, ...) os_log_with_type(os_log_create("com.shishkabibal.TypeTelepathy", "DEBUG"),OS_LOG_TYPE_DEFAULT,N ,##__VA_ARGS__)


#pragma mark - Global Variables

NSBundle *bundle;
NSStatusItem *statusItem;
NSMutableArray *typers;

static NSString *const preferencesSuiteName = @"com.shishkabibal.TypeTelepathy";


#pragma mark - Main Interface

@interface TypeTelepathy : NSObject
+ (instancetype)sharedInstance;
@end

TypeTelepathy* plugin;


#pragma mark - Typer Interface

@interface Typer : NSObject

@property (nonatomic, strong) NSString *uuid;
@property (nonatomic, strong) NSString *handle;
@property (nonatomic, assign) BOOL isFinished;

- (instancetype)init;
- (void)uuid:(NSString *)uuid;
- (void)handle:(NSString *)handle;
- (void)isFinished:(BOOL *)handle;

@end

@implementation Typer

- (instancetype)init {
    self = [super init];
    if (self) {}
    return self;
}

- (void)uuid:(NSString *)uuid {
    _uuid = [uuid copy];
}

- (void)handle:(NSString *)handle {
    _handle = [handle copy];
}

- (void)isFinished:(BOOL *)isFinished {
    _isFinished = isFinished;
}

@end


#pragma mark - Button Interface

@interface StatusBarHandler : NSObject

@end

@implementation StatusBarHandler

+ (void)handleStatusItemClick {
    DLog("%{public}@: Clicked", [self className]);
    
    if ([typers count]) {
        // Get last number added to typers
        Typer *typer = [typers lastObject];
                
        // Open chat with last number from typers
        NSString *smsURLString = [NSString stringWithFormat:@"sms://%@", typer.handle];
        NSURL *smsURL = [NSURL URLWithString:smsURLString];
        if (smsURL)
            [[NSWorkspace sharedWorkspace] openURL:smsURL];
    } else {
        
    }
}

@end


#pragma mark - Main Implementation

@implementation TypeTelepathy

+ (TypeTelepathy*)sharedInstance {
	static TypeTelepathy* plugin = nil;
	
	if (!plugin)
		plugin = [[TypeTelepathy alloc] init];
	
	return plugin;
}

// Called on MacForge plugin initialization
+ (void)load {
    // Create plugin singleton + bundle & statusItem
	plugin = [TypeTelepathy sharedInstance];
    
    // Initialize empty typers array
    typers = [NSMutableArray array];
    
    // Adding status item before launch finished crashes app
    // Register to finished launching notification
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(applicationDidFinishLaunching:) name:NSApplicationDidFinishLaunchingNotification object:nil];
    
    // Log loading
    NSUInteger major = [[NSProcessInfo processInfo] operatingSystemVersion].majorVersion;
    NSUInteger minor = [[NSProcessInfo processInfo] operatingSystemVersion].minorVersion;
    DLog("%{public}@: Loaded (%{public}@ - macOS %ld.%ld)", [self className], [[NSBundle mainBundle] bundleIdentifier], (long)major, (long)minor);
}

+ (void)applicationDidFinishLaunching:(NSNotification *)notification {
    // Unregister from finished launching notification
    [[NSNotificationCenter defaultCenter] removeObserver:self name:NSApplicationDidFinishLaunchingNotification object:nil];
    
    // Add and set status item
    bundle = [NSBundle bundleWithIdentifier:preferencesSuiteName];
    statusItem = [[NSStatusBar systemStatusBar] statusItemWithLength:NSVariableStatusItemLength];
    statusItem.length = -1;
    statusItem.button.target = StatusBarHandler.class;
    statusItem.button.action = @selector(handleStatusItemClick);
    [plugin setStatus];
}


#pragma mark - Status Handling

// Lookup full name associated with passed phone number
- (NSString *)getNameForHandle:(NSString *)handleID {
    IMAccountController *controller = [IMAccountController sharedInstance];
    IMAccount *account = [controller activeIMessageAccount];
    IMHandle *handle = [account imHandleWithID:(handleID)];
    return handle.fullName ?: handleID;
}

- (void)setStatus {
    static NSImage *BlankIcon;
    static NSImage *TypingIcon;
//    static NSImage *ReadIcon;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        BlankIcon = [bundle imageForResource:@"Blank.tiff"];
        [BlankIcon setTemplate:YES];
        BlankIcon.size = CGSizeMake(22.f, 22.f);
        
        TypingIcon = [bundle imageForResource:@"Typing.tiff"];
        [TypingIcon setTemplate:YES];
        TypingIcon.size = CGSizeMake(22.f, 22.f);
        
//        ReadIcon = [bundle imageForResource:@"Read.tiff"];
//        [ReadIcon setTemplate:YES];
//        ReadIcon.size = CGSizeMake(22.f, 22.f);
    });
    
    if ([typers count]) {
        statusItem.image = TypingIcon;
        Typer *typer = [typers lastObject];
        statusItem.title = [plugin getNameForHandle:typer.handle];
    } else {
        statusItem.image = BlankIcon;
        statusItem.title = nil;
    }
}


#pragma mark - Timeout Handling

// Removes typer after 60 second whether or not they have removed themselves (via erased and sent cases)
- (void)removeTyperOnTimeout:(Typer*)typer {
    // Wait 60 seconds (this is the timeout period set by Apple)
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(60.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF.uuid != %@.uuid", typer];
        NSArray *filteredArray = [typers filteredArrayUsingPredicate:predicate];
        [typers setArray:filteredArray];
        [plugin setStatus];
    });
}
	
@end


#pragma mark - Typing Handling

ZKSwizzleInterface(BS_IMChat, IMChat, NSObject)
@implementation BS_IMChat

- (BOOL)_handleIncomingItem:(IMMessageItem*)item {
    // Handle normally expected function
    BOOL expectedOutput = ZKOrig(BOOL, item);
    
    // Set up missingSelectors to see if plugin is broken
    NSArray *requiredSelectors = @[@"guid", @"handle", @"isFinished", @"isIncomingTypingMessage"];
    NSMutableArray *missingSelectors = [NSMutableArray array];
    for (NSString *selector in requiredSelectors) {
        if (![item respondsToSelector:NSSelectorFromString(selector)])
            [missingSelectors addObject:selector];
    }
    
    // Count of missingSelectors should always be 0, otherwise the plugin is broken
    if (![missingSelectors count]) {
        // Set up typer
        Typer *typer = [[Typer alloc] init];
        typer.uuid = [item guid]; // IMMessageItem UUID (e.g., 9DB6F1F7-FC0E-43D2-90BF-44C0D75FA316)
        typer.handle = [item handle]; // Sender's handle (e.g., +15552255726)
        typer.isFinished = [item isFinished];
        
        // NSString *guid = (NSString *)ZKHookIvar(self, NSString*, "_guid"); // e.g., iMessage;-;+15552255726
        
        if (typer.uuid) {
            // Method 3... works, but doesn't detect the 60 second timeout
            if (typer.isFinished) { // use isFinished instead of isCancelTypingMessage to cover both erased and sent cases
                DLog("%{public}@: %{public}@ is finished", [self className], typer.handle);
                
                // Remove handle from typers (by filtering it out)
                NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF.uuid != %@.uuid", typer];
                NSArray *filteredArray = [typers filteredArrayUsingPredicate:predicate];
                [typers setArray:filteredArray];
            } else {
                DLog("%{public}@: %{public}@ is not finished", [self className], typer.handle);
                
                if ([item isIncomingTypingMessage]) { // without this, messages you type will also be added
                    // Add handle to typers if not already there
                    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF.uuid == %@.uuid", typer];
                    NSArray *filteredArray = [typers filteredArrayUsingPredicate:predicate];
                    if (![filteredArray count]) {
                        [typers addObject:typer];
                        [plugin removeTyperOnTimeout :typer]; // handle 60 second timeout
                    }
                }
            }
            
            // Method 2... works, but has no way of detecting if the typed message has been sent
//            if ([item respondsToSelector:@selector(isIncomingTypingMessage)] && [item isIncomingTypingMessage]) {
//                DLog("%{public}@: %{public}@ started typing", [self className], [item handle]);
//            } else if ([item respondsToSelector:@selector(isCancelTypingMessage)] && [item isCancelTypingMessage]) {
//                DLog("%{public}@: %{public}@ stopped typing", [self className], [item handle]);
//            }
            
            // Method 1... doesn't work, because doesn't become false until later
//            if ([item respondsToSelector:@selector(isTypingMessage)]) {
//                DLog("%{public}@", [[item message] isTypingMessage] ? @"YES" : @"NO");
//                if ([[item message] isTypingMessage]) {
//                    DLog("%{public}@: %{public}@ is typing", [self className], [item handle]);
//                } else {
//                    DLog("%{public}@: %{public}@ is not typing", [self className], [item handle]);
//                }
//            }
            
            // Set status after changed to typers made
            [plugin setStatus];
        }
    }
    
    // Return normally expected output
    return expectedOutput;
}

@end
