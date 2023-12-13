//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "NSObject-Protocol.h"

@class TUConversation, TUConversationManager;

@protocol TUConversationManagerDelegate

@optional
- (void)serverDisconnectedForConversationManager:(TUConversationManager *)arg1;
- (void)conversationManager:(TUConversationManager *)arg1 removedActiveConversation:(TUConversation *)arg2;
- (void)conversationManager:(TUConversationManager *)arg1 activeRemoteParticipantsChangedForConversation:(TUConversation *)arg2;
- (void)conversationManager:(TUConversationManager *)arg1 remoteMembersChangedForConversation:(TUConversation *)arg2;
- (void)conversationManager:(TUConversationManager *)arg1 localVideoToggledForConversation:(TUConversation *)arg2;
- (void)conversationManager:(TUConversationManager *)arg1 stateChangedForConversation:(TUConversation *)arg2;
- (void)conversationsChangedForConversationManager:(TUConversationManager *)arg1;
@end

