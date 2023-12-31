/*
* This header is generated by classdump-dyld 1.0
* on Tuesday, October 12, 2021 at 10:43:07 PM Eastern Daylight Time
* Operating System: Version 11.1 (Build 20C5061b)
* Image Source: /System/Library/PrivateFrameworks/IMSharedUtilities.framework/Versions/A/IMSharedUtilities
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/


@class NSString, NSDate, NSURL, NSDictionary, NSArray, NSData;

@interface IMFileTransfer : NSObject {

    char _isIncoming;
    char _isDirectory;
    char _shouldAttemptToResume;
    char _wasRegisteredAsStandalone;
    char _shouldForceArchive;
    char _needsWrapper;
    char _isAuxImage;
    char _isAuxVideo;
    char _isSticker;
    char _hideAttachment;
    char _isLocation;
    char _isContact;
    char _appMessageFallbackImage;
    unsigned short _hfsFlags;
    unsigned _hfsType;
    unsigned _hfsCreator;
    double _lastUpdatedInterval;
    double _lastAveragedInterval;
    unsigned long long _lastAveragedBytes;
    NSString* _guid;
    NSString* _messageGUID;
    NSDate* _startDate;
    NSDate* _createdDate;
    long long _transferState;
    NSString* _filename;
    NSURL* _transferDataURL;
    NSString* _utiType;
    NSString* _mimeType;
    NSString* _accountID;
    NSString* _otherPerson;
    unsigned long long _currentBytes;
    unsigned long long _totalBytes;
    unsigned long long _averageTransferRate;
    long long _error;
    NSString* _errorDescription;
    NSDictionary* _localUserInfo;
    NSString* _transferredFilename;
    NSDictionary* _transcoderUserInfo;
    NSDictionary* _AuxTranscoderUserInfo;
    NSDictionary* _stickerUserInfo;
    NSArray* _attachmentSendContexts;
    long long _cloudKitSyncState;
    NSData* _cloudKitServerChangeTokenBlob;
    NSString* _cloudKitRecordID;
    long long _srCloudKitSyncState;
    NSData* _srCloudKitServerChangeTokenBlob;
    NSString* _srCloudKitRecordID;
    NSString* _sandboxToken;
    NSURL* _localURL;
    NSURL* _temporaryHighQualityLocalURL;
    NSDictionary* _attributionInfo;
    NSString* _originalGUID;

}

@property (assign,setter=_setLastUpdatedInterval:,nonatomic) double _lastUpdatedInterval;                   //@synthesize lastUpdatedInterval=_lastUpdatedInterval - In the implementation block
@property (assign,setter=_setLastAveragedInterval:,nonatomic) double _lastAveragedInterval;                 //@synthesize lastAveragedInterval=_lastAveragedInterval - In the implementation block
@property (nonatomic,readonly) unsigned long long _lastAveragedBytes;                                       //@synthesize lastAveragedBytes=_lastAveragedBytes - In the implementation block
@property (nonatomic,retain) NSString * guid;                                                               //@synthesize guid=_guid - In the implementation block
@property (nonatomic,retain) NSString * messageGUID;                                                        //@synthesize messageGUID=_messageGUID - In the implementation block
@property (nonatomic,retain) NSDate * createdDate;                                                          //@synthesize createdDate=_createdDate - In the implementation block
@property (setter=_setStartDate:,nonatomic,retain) NSDate * startDate;                                      //@synthesize startDate=_startDate - In the implementation block
@property (assign,setter=_setTransferState:,nonatomic) long long transferState;                             //@synthesize transferState=_transferState - In the implementation block
@property (assign,nonatomic) char isIncoming;                                                               //@synthesize isIncoming=_isIncoming - In the implementation block
@property (nonatomic,retain) NSString * transferredFilename;                                                //@synthesize transferredFilename=_transferredFilename - In the implementation block
@property (setter=_setTransferDataURL:,nonatomic,retain) NSURL * transferDataURL;                           //@synthesize transferDataURL=_transferDataURL - In the implementation block
@property (nonatomic,retain) NSString * filename;                                                           //@synthesize filename=_filename - In the implementation block
@property (setter=_setLocalPath:,nonatomic,retain) NSString * localPath;
@property (nonatomic,retain) NSString * type;                                                               //@synthesize utiType=_utiType - In the implementation block
@property (setter=_setLocalURL:,nonatomic,retain) NSURL * localURL;                                         //@synthesize localURL=_localURL - In the implementation block
@property (nonatomic,retain) NSURL * temporaryHighQualityLocalURL;                                          //@synthesize temporaryHighQualityLocalURL=_temporaryHighQualityLocalURL - In the implementation block
@property (assign,nonatomic) unsigned hfsType;                                                              //@synthesize hfsType=_hfsType - In the implementation block
@property (assign,nonatomic) unsigned hfsCreator;                                                           //@synthesize hfsCreator=_hfsCreator - In the implementation block
@property (assign,nonatomic) unsigned short hfsFlags;                                                       //@synthesize hfsFlags=_hfsFlags - In the implementation block
@property (nonatomic,retain) NSString * accountID;                                                          //@synthesize accountID=_accountID - In the implementation block
@property (nonatomic,retain) NSString * otherPerson;                                                        //@synthesize otherPerson=_otherPerson - In the implementation block
@property (assign,nonatomic) unsigned long long currentBytes;                                               //@synthesize currentBytes=_currentBytes - In the implementation block
@property (assign,nonatomic) unsigned long long totalBytes;                                                 //@synthesize totalBytes=_totalBytes - In the implementation block
@property (assign,nonatomic) unsigned long long averageTransferRate;                                        //@synthesize averageTransferRate=_averageTransferRate - In the implementation block
@property (assign,setter=_setNeedsWrapper:,nonatomic) char _needsWrapper;                                   //@synthesize needsWrapper=_needsWrapper - In the implementation block
@property (assign,nonatomic) char isDirectory;                                                              //@synthesize isDirectory=_isDirectory - In the implementation block
@property (assign,nonatomic) char shouldAttemptToResume;                                                    //@synthesize shouldAttemptToResume=_shouldAttemptToResume - In the implementation block
@property (assign,setter=_setForceArchive:,nonatomic) char shouldForceArchive;                              //@synthesize shouldForceArchive=_shouldForceArchive - In the implementation block
@property (assign,setter=_setError:,nonatomic) long long error;                                             //@synthesize error=_error - In the implementation block
@property (setter=_setErrorDescription:,nonatomic,retain) NSString * errorDescription;                      //@synthesize errorDescription=_errorDescription - In the implementation block
@property (nonatomic,retain) NSString * originalGUID;                                                       //@synthesize originalGUID=_originalGUID - In the implementation block
@property (nonatomic,readonly) char canBeAccepted;
@property (nonatomic,readonly) char isFinished;
@property (nonatomic,retain,readonly) NSString * displayName;
@property (nonatomic,readonly) char existsAtLocalPath;
@property (assign,nonatomic) char isAuxImage;                                                               //@synthesize isAuxImage=_isAuxImage - In the implementation block
@property (assign,nonatomic) char isAuxVideo;                                                               //@synthesize isAuxVideo=_isAuxVideo - In the implementation block
@property (assign,nonatomic) char isSticker;                                                                //@synthesize isSticker=_isSticker - In the implementation block
@property (nonatomic,readonly) char isRecipeBasedSticker;
@property (nonatomic,readonly) char isAnimojiV2;
@property (nonatomic,readonly) char wantsAlphaRemoved;
@property (nonatomic,readonly) char isAutoloopVideo;
@property (nonatomic,readonly) char isOpusAudioMessage;
@property (nonatomic,readonly) char isHEVCWithAlphaVideo;
@property (assign,nonatomic) char isLocation;                                                               //@synthesize isLocation=_isLocation - In the implementation block
@property (assign,nonatomic) char isContact;                                                                //@synthesize isContact=_isContact - In the implementation block
@property (assign,nonatomic) char hideAttachment;                                                           //@synthesize hideAttachment=_hideAttachment - In the implementation block
@property (nonatomic,readonly) char canMarkPurgable;
@property (nonatomic,copy) NSString * sandboxToken;                                                         //@synthesize sandboxToken=_sandboxToken - In the implementation block
@property (assign,nonatomic) NSDate * refreshDate;
@property (nonatomic,retain,readonly) NSString * temporaryHighQualityLocalPath;
@property (nonatomic,retain,readonly) NSString * permanentHighQualityLocalPath;
@property (nonatomic,retain,readonly) NSString * mimeType;                                                  //@synthesize mimeType=_mimeType - In the implementation block
@property (nonatomic,retain) NSDictionary * transcoderUserInfo;                                             //@synthesize transcoderUserInfo=_transcoderUserInfo - In the implementation block
@property (nonatomic,retain) NSDictionary * AuxTranscoderUserInfo;                                          //@synthesize AuxTranscoderUserInfo=_AuxTranscoderUserInfo - In the implementation block
@property (nonatomic,retain) NSDictionary * userInfo;                                                       //@synthesize localUserInfo=_localUserInfo - In the implementation block
@property (nonatomic,retain) NSArray * attachmentSendContexts;                                              //@synthesize attachmentSendContexts=_attachmentSendContexts - In the implementation block
@property (nonatomic,retain) NSDictionary * stickerUserInfo;                                                //@synthesize stickerUserInfo=_stickerUserInfo - In the implementation block
@property (nonatomic,retain) NSDictionary * attributionInfo;                                                //@synthesize attributionInfo=_attributionInfo - In the implementation block
@property (assign,setter=setRegisteredAsStandalone:,nonatomic) char wasRegisteredAsStandalone;              //@synthesize wasRegisteredAsStandalone=_wasRegisteredAsStandalone - In the implementation block
@property (assign,nonatomic) char appMessageFallbackImage;                                                  //@synthesize appMessageFallbackImage=_appMessageFallbackImage - In the implementation block
@property (assign,nonatomic) long long cloudKitSyncState;                                                   //@synthesize cloudKitSyncState=_cloudKitSyncState - In the implementation block
@property (nonatomic,retain) NSData * cloudKitServerChangeTokenBlob;                                        //@synthesize cloudKitServerChangeTokenBlob=_cloudKitServerChangeTokenBlob - In the implementation block
@property (nonatomic,retain) NSString * cloudKitRecordID;                                                   //@synthesize cloudKitRecordID=_cloudKitRecordID - In the implementation block
@property (assign,nonatomic) long long srCloudKitSyncState;                                                 //@synthesize srCloudKitSyncState=_srCloudKitSyncState - In the implementation block
@property (nonatomic,retain) NSData * srCloudKitServerChangeTokenBlob;                                      //@synthesize srCloudKitServerChangeTokenBlob=_srCloudKitServerChangeTokenBlob - In the implementation block
@property (nonatomic,retain) NSString * srCloudKitRecordID;                                                 //@synthesize srCloudKitRecordID=_srCloudKitRecordID - In the implementation block
+(id)whitelistedKeys;
+(char)_doesLocalURLRequireArchiving:(id)arg1 ;
+(id)guidForFileTransferDictionary:(id)arg1 ;
+(id)AuxGUIDFromFileTransferGUID:(id)arg1 ;
+(id)guidByStrippingAuxPrefix:(id)arg1 ;
-(void)dealloc;
-(id)description;
-(id)init;
-(void)setType:(NSString *)arg1 ;
-(NSDictionary *)userInfo;
-(NSString *)type;
-(long long)error;
-(char)isDirectory;
-(NSString *)displayName;
-(void)setUserInfo:(NSDictionary *)arg1 ;
-(void)_setError:(long long)arg1 ;
-(char)isFinished;
-(NSDate *)startDate;
-(NSString *)filename;
-(void)setFilename:(NSString *)arg1 ;
-(void)_clear;
-(char)isIncoming;
-(id)_dictionaryRepresentation;
-(NSString *)accountID;
-(void)setAccountID:(NSString *)arg1 ;
-(unsigned long long)totalBytes;
-(void)setOriginalGUID:(NSString *)arg1 ;
-(NSString *)guid;
-(NSString *)originalGUID;
-(void)setTotalBytes:(unsigned long long)arg1 ;
-(void)setGuid:(NSString *)arg1 ;
-(NSDate *)refreshDate;
-(NSDate *)createdDate;
-(void)setCreatedDate:(NSDate *)arg1 ;
-(void)setRefreshDate:(NSDate *)arg1 ;
-(NSString *)errorDescription;
-(NSURL *)localURL;
-(char)isContact;
-(long long)transferState;
-(char)isLocation;
-(NSString *)localPath;
-(NSString *)mimeType;
-(long long)cloudKitSyncState;
-(NSString *)cloudKitRecordID;
-(void)setCloudKitSyncState:(long long)arg1 ;
-(void)setCloudKitRecordID:(NSString *)arg1 ;
-(void)setCloudKitServerChangeTokenBlob:(NSData *)arg1 ;
-(void)setSrCloudKitSyncState:(long long)arg1 ;
-(void)setSrCloudKitRecordID:(NSString *)arg1 ;
-(NSData *)cloudKitServerChangeTokenBlob;
-(NSString *)srCloudKitRecordID;
-(long long)srCloudKitSyncState;
-(NSDictionary *)attributionInfo;
-(void)setAttributionInfo:(NSDictionary *)arg1 ;
-(void)setMessageGUID:(NSString *)arg1 ;
-(NSString *)messageGUID;
-(char)isSticker;
-(void)_setLocalURL:(id)arg1 ;
-(void)setCurrentBytes:(unsigned long long)arg1 ;
-(void)_setLocalPath:(id)arg1 ;
-(char)_updateWithDictionaryRepresentation:(id)arg1 ;
-(unsigned short)hfsFlags;
-(NSDictionary *)stickerUserInfo;
-(NSDictionary *)transcoderUserInfo;
-(char)hideAttachment;
-(NSURL *)temporaryHighQualityLocalURL;
-(void)_calculateTypeInformation;
-(NSString *)transferredFilename;
-(char)_isCloudKitEnabled;
-(char)existsAtLocalPath;
-(char)_missingAttachmentCanBeDownloadedFromCloudKit;
-(void)_setTransferState:(long long)arg1 ;
-(id)_initWithGUID:(id)arg0 filename:(id)arg1 isDirectory:(BOOL)arg2 localURL:(id)arg3 account:(id)arg4 otherPerson:(id)arg5 totalBytes:(NSUInteger)arg6 hfsType:(unsigned int)arg7 hfsCreator:(unsigned int)arg8 hfsFlags:(unsigned short)arg9 isIncoming:(BOOL)arg10 ;
-(void)_setAccount:(id)arg1 otherPerson:(id)arg2 ;
-(void)_setStartDate:(id)arg1 ;
-(void)_setCurrentBytes:(unsigned long long)arg1 totalBytes:(unsigned long long)arg2 ;
-(void)_setAveragedTransferRate:(unsigned long long)arg1 lastAveragedInterval:(double)arg2 lastAveragedBytes:(unsigned long long)arg3 ;
-(void)_setDirectory:(char)arg1 hfsType:(unsigned)arg2 hfsCreator:(unsigned)arg3 hfsFlags:(unsigned short)arg4 ;
-(void)_updateWithDictionaryRepresentationForWhitelistedKeys:(id)arg1 ;
-(id)_dictionaryToSend;
-(char)canBeAccepted;
-(char)isAnimojiV2;
-(char)wantsAlphaRemoved;
-(char)canMarkPurgable;
-(char)isRecipeBasedSticker;
-(char)isAutoloopVideo;
-(char)isOpusAudioMessage;
-(char)isHEVCWithAlphaVideo;
-(void)_setTransferDataURL:(id)arg1 ;
-(NSString *)temporaryHighQualityLocalPath;
-(NSString *)permanentHighQualityLocalPath;
-(unsigned)hfsType;
-(unsigned long long)currentBytes;
-(id)_auxVideoPathIfItExists;
-(void)_swizzleTransferStateIfMissingAttachmentCanBeDownloadedFromCloudKit;
-(void)setMimeType:(NSString *)arg1 ;
-(double)_lastUpdatedInterval;
-(void)_setLastUpdatedInterval:(double)arg1 ;
-(double)_lastAveragedInterval;
-(void)_setLastAveragedInterval:(double)arg1 ;
-(unsigned long long)_lastAveragedBytes;
-(void)setIsIncoming:(char)arg1 ;
-(NSURL *)transferDataURL;
-(void)setHfsType:(unsigned)arg1 ;
-(void)setHfsFlags:(unsigned short)arg1 ;
-(unsigned)hfsCreator;
-(void)setHfsCreator:(unsigned)arg1 ;
-(NSString *)otherPerson;
-(void)setOtherPerson:(NSString *)arg1 ;
-(unsigned long long)averageTransferRate;
-(void)setAverageTransferRate:(unsigned long long)arg1 ;
-(void)setIsDirectory:(char)arg1 ;
-(char)shouldAttemptToResume;
-(void)setShouldAttemptToResume:(char)arg1 ;
-(void)_setErrorDescription:(id)arg1 ;
-(char)wasRegisteredAsStandalone;
-(void)setRegisteredAsStandalone:(char)arg1 ;
-(char)shouldForceArchive;
-(void)_setForceArchive:(char)arg1 ;
-(char)_needsWrapper;
-(void)_setNeedsWrapper:(char)arg1 ;
-(void)setTransferredFilename:(NSString *)arg1 ;
-(void)setTranscoderUserInfo:(NSDictionary *)arg1 ;
-(char)isAuxImage;
-(void)setIsAuxImage:(char)arg1 ;
-(char)isAuxVideo;
-(void)setIsAuxVideo:(char)arg1 ;
-(NSDictionary *)AuxTranscoderUserInfo;
-(void)setAuxTranscoderUserInfo:(NSDictionary *)arg1 ;
-(void)setIsSticker:(char)arg1 ;
-(void)setStickerUserInfo:(NSDictionary *)arg1 ;
-(void)setHideAttachment:(char)arg1 ;
-(NSArray *)attachmentSendContexts;
-(void)setAttachmentSendContexts:(NSArray *)arg1 ;
-(void)setIsLocation:(char)arg1 ;
-(void)setIsContact:(char)arg1 ;
-(NSData *)srCloudKitServerChangeTokenBlob;
-(void)setSrCloudKitServerChangeTokenBlob:(NSData *)arg1 ;
-(NSString *)sandboxToken;
-(void)setSandboxToken:(NSString *)arg1 ;
-(void)setTemporaryHighQualityLocalURL:(NSURL *)arg1 ;
-(char)appMessageFallbackImage;
-(void)setAppMessageFallbackImage:(char)arg1 ;
@end
