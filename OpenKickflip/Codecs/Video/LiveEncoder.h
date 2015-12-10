//
//  LXCaptureSession.h
//  
//
//  Created by Daniel Pourhadi on 10/22/15.
//
//

#import <Foundation/Foundation.h>
#import <VideoToolbox/VideoToolbox.h>

@class LiveEncoder;
@protocol LiveEncoderDelegate
@required
- (void)encoder:(LiveEncoder*)encoder didEncodeSampleBuffer:(CMSampleBufferRef)sampleBuffer;
@end

@interface LiveEncoder : NSObject
- (id)initWithHeight:(CGFloat)height width:(CGFloat)width bitrate:(SInt32)bitRate;

@property (nonatomic, weak) id<LiveEncoderDelegate> delegate;

- (void)setBitrate:(SInt32)bitrate average:(BOOL)average;

- (BOOL)encodeSampleBuffer:(CMSampleBufferRef)sampleBuffer;

- (BOOL)finish;
@end
