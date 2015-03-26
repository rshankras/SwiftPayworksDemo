//
// PAYWORKS GMBH ("COMPANY") CONFIDENTIAL
// Copyright (c) 2015 payworks GmbH, All Rights Reserved.
//
// NOTICE:  All information contained herein is, and remains the property of COMPANY. The intellectual and technical concepts contained
// herein are proprietary to COMPANY and may be covered by European or foreign Patents, patents in process, and are protected by trade secret or copyright law.
// Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
// from COMPANY.  Access to the source code contained herein is hereby forbidden to anyone except current COMPANY employees, managers or contractors who have executed
// Confidentiality and Non-disclosure agreements explicitly covering such access.
//
// The copyright notice above does not evidence any actual or intended publication or disclosure of this source code, which includes
// information that is confidential and/or proprietary, and is a trade secret, of COMPANY.
// ANY REPRODUCTION, MODIFICATION, DISTRIBUTION, PUBLIC  PERFORMANCE,
// OR PUBLIC DISPLAY OF OR THROUGH USE  OF THIS  SOURCE CODE  WITHOUT  THE EXPRESS WRITTEN CONSENT OF COMPANY IS STRICTLY PROHIBITED, AND IN VIOLATION OF APPLICABLE
// LAWS AND INTERNATIONAL TREATIES.  THE RECEIPT OR POSSESSION OF  THIS SOURCE CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY RIGHTS
// TO REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE, USE, OR SELL ANYTHING THAT IT  MAY DESCRIBE, IN WHOLE OR IN PART.

#import <Foundation/foundation.h>
#import <UIKit/UIKit.h>
#import <mpos.core/mpos-extended.h>

@class MPTransaction;
@class MPUPaymentControllerConfiguration;
@class MPUPaymentParameters;

/**
 * Enum describing the result of the payment.
 */
typedef NS_ENUM(NSUInteger, MPUPaymentControllerResult) {
    /**
     * The payment was approved.
     */
    MPUPaymentControllerResultApproved = 0,
    
    /**
     * The payment failed. This might be due an error or the transaction was declined / aborted.
     */
    MPUPaymentControllerResultFailed
};


typedef void (^MPUPaymentControllerCompleted)(MPUPaymentControllerResult, MPTransaction *transaction);

/**
 * The MPUPaymentController takes control over a payment.
 */
@interface MPUPaymentController : NSObject

@property(nonatomic, retain) MPTransaction *transaction;
@property(nonatomic, copy) MPUPaymentControllerCompleted completed;
@property(nonatomic, retain) MPUPaymentControllerConfiguration *configuration;


@property(nonatomic, retain) NSString *merchantIdentifier;
@property(nonatomic, retain) NSString *merchantSecret;
@property(nonatomic, assign) MPProviderMode providerMode;

@property (nonatomic, retain) MPUPaymentParameters *paymentParameters;

/**
 * Initializes the MPUPaymentController. The method *MUST* be called before any payment can be started.
 */
+ (id)initializePaymentControllerWithProviderMode:(MPProviderMode)providerMode merchantIdentifier:(NSString *)merchantIdentifier merchantSecret:(NSString *)merchantSecret;


/**
 * Creates an UIViewController that starts the payments und updates its views accordingly.
 */
- (UIViewController *)createPaymentViewControllerWithSessionIdentifier:(NSString *)sessionIdentifier completed:(MPUPaymentControllerCompleted)completed;


/**
 * Creates an UIViewController that starts the payments und updates its views accordingly.
 */
- (UIViewController *)createPaymentViewControllerWithAmount:(NSDecimalNumber *)amount currency:(MPCurrency)currency subject:(NSString *)subject customIdentifier:(NSString *)customIdentifier completed:(MPUPaymentControllerCompleted)completed;

/**
 * Returns an instance of the initialized payment controller.
 */
+(MPUPaymentController *)sharedInitializedInstance;

@end
