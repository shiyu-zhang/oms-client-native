/*
 * Intel License
 */

#import "ICS/ICSAVFoundationVideoSource+Woogeen.h"
#import "talk/ics/sdk/base/objc/ICSPeerConnectionFactory+Woogeen.h"
#import "ICS/ICSAVFoundationVideoSource+Woogeen.h"
#import "webrtc/sdk/objc/Framework/Classes/avfoundationvideocapturer.h"
#import "webrtc/sdk/objc/Framework/Classes/RTCAVFoundationVideoSource+Private.h"
#import "webrtc/sdk/objc/Framework/Classes/RTCMediaConstraints+Private.h"
#import "webrtc/sdk/objc/Framework/Classes/RTCVideoSource+Private.h"

#include "talk/ics/sdk/base/peerconnectiondependencyfactory.h"

@implementation RTCAVFoundationVideoSource (Woogeen)

- (instancetype)initWithConstraints:(RTCMediaConstraints*)constraints {
  RTCPeerConnectionFactory* factory = [RTCPeerConnectionFactory sharedInstance];
  return [self initWithFactory:factory constraints:constraints];
}

- (void)setFilter:(id<RTCVideoFrameFilterProtocol>)filter {
  self.capturer->SetFilter(filter);
}

- (void)removeFilter {
  self.capturer->RemoveFilter();
}

- (void)setOutputPixelFormat:(OSType)outputPixelFormat {
  self.capturer->SetOutputPixelFormat(outputPixelFormat);
}

@end