/*
 * Copyright © 2018 Intel Corporation. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <WebRTC/RTCMacros.h>
#import <ICS/ICSMediaFormat.h>

NS_ASSUME_NONNULL_BEGIN

@class RTCLegacyStatsReport;
@class ICSConferenceSubscription;

RTC_EXPORT
@protocol ICSConferenceSubscriptionDelegate <NSObject>

@optional

- (void)subscriptionDidEnd:(ICSConferenceSubscription*)subscription;
- (void)subscriptionDidMute:(ICSConferenceSubscription*)subscription
                  trackKind:(ICSTrackKind)kind;
- (void)subscriptionDidUnmute:(ICSConferenceSubscription*)subscription
                    trackKind:(ICSTrackKind)kind;

@end

RTC_EXPORT
@interface ICSConferenceSubscription : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (void)stop;
- (void)statsWithOnSuccess:(void (^)(NSArray<RTCLegacyStatsReport*>*))onSuccess
                 onFailure:(nullable void (^)(NSError*))onFailure;

@property(nonatomic, weak) id<ICSConferenceSubscriptionDelegate> delegate;

@end


RTC_EXPORT
/// Options for subscribing a remote stream.
@interface ICSConferenceAudioSubscriptionConstraints : NSObject

@property(nonatomic, strong) NSArray<ICSAudioCodecParameters*>* codecs;

@end

RTC_EXPORT
/// Options for subscribing a remote stream.
@interface ICSConferenceVideoSubscriptionConstraints : NSObject

@property(nonatomic, assign) CGSize resolution;
@property(nonatomic, assign) float frameRate;
@property(nonatomic, assign) float bitrateMultiplier;
@property(nonatomic, assign) NSUInteger keyFrameInterval;
@property(nonatomic, strong) NSArray<ICSVideoCodecParameters*>* codecs;

@end

RTC_EXPORT
@interface ICSConferenceSubscribeOptions : NSObject

- (instancetype)initWithAudio:(ICSConferenceAudioSubscriptionConstraints*)audio
                        video:(ICSConferenceVideoSubscriptionConstraints*)video;

@property(nonatomic, strong) ICSConferenceAudioSubscriptionConstraints* audio;
@property(nonatomic, strong) ICSConferenceVideoSubscriptionConstraints* video;

@end

NS_ASSUME_NONNULL_END