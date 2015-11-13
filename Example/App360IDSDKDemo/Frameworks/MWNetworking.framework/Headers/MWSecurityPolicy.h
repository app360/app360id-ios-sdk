// MWSecurityPolicy.h
//
// Copyright (c) 2013-2015 MWNetworking (http://afnetworking.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import <Security/Security.h>

typedef NS_ENUM(NSUInteger, MWSSLPinningMode) {
    MWSSLPinningModeNone,
    MWSSLPinningModePublicKey,
    MWSSLPinningModeCertificate,
};

/**
 `MWSecurityPolicy` evaluates server trust against pinned X.509 certificates and public keys over secure connections.

 Adding pinned SSL certificates to your app helps prevent man-in-the-middle attacks and other vulnerabilities. Applications dealing with sensitive customer data or financial information are strongly encouraged to route all communication over an HTTPS connection with SSL pinning configured and enabled.
 */
@interface MWSecurityPolicy : NSObject

/**
 The criteria by which server trust should be evaluated against the pinned SSL certificates. Defaults to `MWSSLPinningModeNone`.
 */
@property (readonly, nonatomic, assign) MWSSLPinningMode SSLPinningMode;

/**
 Whether to evaluate an entire SSL certificate chain, or just the leaf certificate. Defaults to `YES`.
 */
@property (nonatomic, assign) BOOL validatesCertificateChain;

/**
 The certificates used to evaluate server trust according to the SSL pinning mode. By default, this property is set to any (`.cer`) certificates included in the app bundle.
 */
@property (nonatomic, strong) NSArray *pinnedCertificates;

/**
 Whether or not to trust servers with an invalid or expired SSL certificates. Defaults to `NO`.
 */
@property (nonatomic, assign) BOOL allowInvalidCertificates;

/**
 Whether or not to validate the domain name in the certificate's CN field. Defaults to `YES`.
 */
@property (nonatomic, assign) BOOL validatesDomainName;

///-----------------------------------------
/// @name Getting Specific Security Policies
///-----------------------------------------

/**
 Returns the shared default security policy, which does not allow invalid certificates, does not validate domain name, and does not validate against pinned certificates or public keys.

 @return The default security policy.
 */
+ (instancetype)defaultPolicy;

///---------------------
/// @name Initialization
///---------------------

/**
 Creates and returns a security policy with the specified pinning mode.

 @param pinningMode The SSL pinning mode.

 @return A new security policy.
 */
+ (instancetype)policyWithPinningMode:(MWSSLPinningMode)pinningMode;

///------------------------------
/// @name Evaluating Server Trust
///------------------------------

/**
 Whether or not the specified server trust should be accepted, based on the security policy.

 This method should be used when responding to an authentication challenge from a server.

 @param serverTrust The X.509 certificate trust of the server.

 @return Whether or not to trust the server.

 @warning This method has been deprecated in favor of `-evaluateServerTrust:forDomain:`.
 */
- (BOOL)evaluateServerTrust:(SecTrustRef)serverTrust DEPRECATED_ATTRIBUTE;

/**
 Whether or not the specified server trust should be accepted, based on the security policy.

 This method should be used when responding to an authentication challenge from a server.

 @param serverTrust The X.509 certificate trust of the server.
 @param domain The domain of serverTrust. If `nil`, the domain will not be validated.

 @return Whether or not to trust the server.
 */
- (BOOL)evaluateServerTrust:(SecTrustRef)serverTrust
                  forDomain:(NSString *)domain;

@end

///----------------
/// @name Constants
///----------------

/**
 ## SSL Pinning Modes

 The following constants are provided by `MWSSLPinningMode` as possible SSL pinning modes.

 enum {
 MWSSLPinningModeNone,
 MWSSLPinningModePublicKey,
 MWSSLPinningModeCertificate,
 }

 `MWSSLPinningModeNone`
 Do not used pinned certificates to validate servers.

 `MWSSLPinningModePublicKey`
 Validate host certificates against public keys of pinned certificates.

 `MWSSLPinningModeCertificate`
 Validate host certificates against pinned certificates.
*/
