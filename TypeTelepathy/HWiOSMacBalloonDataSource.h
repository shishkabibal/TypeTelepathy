//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Jun  9 2015 22:53:21).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//


@interface HWiOSMacBalloonDataSource : NSObject {}

@property (nonatomic) BOOL datasourceIsFromMe;

- (id) initWithPluginPayload:(id)arg1;
- (void) createWrappedDatasource;
- (BOOL) canProvideSize;
- (struct CGSize) sizeThatFits:(struct CGSize)arg1;
- (void) pluginPayloadDidChange:(unsigned long)arg1;
- (void) generateImageForSize:(struct CGSize)arg1 completionHandler:(id)arg2;
- (BOOL) datasourceIsFromMe;
- (void) setDatasourceIsFromMe:(BOOL)arg1;

@end
