//
// PAYWORKS GMBH ("COMPANY") CONFIDENTIAL
// Copyright (c) 2014 payworks GmbH, All Rights Reserved.
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

#import "MPTransaction.h"
@class UIImage;
@class MPTransactionActionSupport;
@class MPApplicationInformation;
@class MPTransaction;
@class MPPaymentProcess;
@class MPTransactionProvider;
@class MPAccessory;
@class MPPaymentProcessDetails;
@class MPReceiptFactory;

/**
 * Callback indicating a successful registration of the transaction and provides access it. Save the .sessionIdentifier or .identifier to query the status in case of an error.
 * @param paymentProcess The instance that called the block
 * @param transaction The transaction reference that was created (same as paymentProcess.transaction)
 * @since 2.2.0
 */
typedef void (^MPPaymentProcessRegistered)(MPPaymentProcess *paymentProcess, MPTransaction *transaction);

/**
 * Indicates a status change of the overall process and provides information about whats happening with process.
 * @param paymentProcess The instance that called the block
 * @param transaction The transaction that is currently being processed (same as paymentProcess.transaction)
 * @since 2.2.0
 */
typedef void (^MPPaymentProcessStatusChanged)(MPPaymentProcess *paymentProcess, MPTransaction *transaction, MPPaymentProcessDetails *details);

/**
 * Indicates that an explicit user interaction is required. The SDK blocks until a call to paymentProcess continueWith... is called.
 * @param paymentProcess The instance that called the block
 * @param transaction The transaction that is currently being processed (same as paymentProcess.transaction)
 * @param action The action that is required
 * @param support Additional data that might be necessary to complete the action
 * @since 2.2.0
 */
typedef void (^MPPaymentProcessActionRequired)(MPPaymentProcess *paymentProcess, MPTransaction *transaction, MPTransactionAction action, MPTransactionActionSupport *support);

/**
 * Indicates that the process has been completed. The paymentProcess.details provide additional information on the result of the process.
 * @param paymentProcess The instance that called the block
 * @param transaction The transaction that has been processed (same as paymentProcess.transaction)
 * @param details The latest details object for providing access to the overall processing status (same as paymentProcess.details)
 * @since 2.2.5
 */
typedef void (^MPPaymentProcessCompleted)(MPPaymentProcess *paymentProcess, MPTransaction *transaction, MPPaymentProcessDetails *details);


/**
 * Automated workflow that encapsulates all steps required for making a transaction.
 */
@interface MPPaymentProcess : NSObject

/**
 * The provider instance that is used by the process.
 * @since 2.2.0
 */
@property (strong, readonly, nonatomic) MPTransactionProvider *provider;

/**
 * The transaction object used by the process.
 * @since 2.2.0
 */
@property (strong, readonly, nonatomic) MPTransaction *transaction;

/**
 * The accessory object used by the process.
 * @since 2.2.0
 */
@property (strong, readonly, nonatomic) MPAccessory *accessory;

/**
 * The process details providing access to the current status.
 * @since 2.2.0
 */
@property (strong, readonly, nonatomic) MPPaymentProcessDetails *details;


/**
 * The factory to generate transaction receipts for the customer and merchant;
 * @since 2.2.0
 */
@property (strong, readonly, nonatomic) MPReceiptFactory *receiptFactory;

/**
 * Continues a transaction with a signature after a respective actionRequired callback was called.
 * @param signature The digital signature of the cusomter
 * @param verified Indicates if the signature matches the one on the card
 * @since 2.2.0
 */
- (void)continueWithCustomerSignature:(UIImage *)signature
                             verified:(BOOL)verified;

/**
 * Continues a transaction indicating that the signature will be captured on the receipt after the transaction. Continues after a respective actionRequired callback was called.
 * @since 2.2.5
 */
- (void)continueWithCustomerSignatureOnReceipt;

/**
 * Continues a transaction with with a identity verification a respective actionRequired callback was called.
 * @param verified Indicates if the identity was verified
 * @since 2.2.0
 */
- (void)continueWithCustomerIdentityVerified:(BOOL)verified;

/**
 * Continue a transaction after an application selection actionRequired callback was called.
 * @param application The application to use for the transaction
 * @since 2.2.0
 */
- (void)continueWithSelectedApplication:(MPApplicationInformation *)application;

/**
 * Requests an abort at the next possible moment. Repeated calls are ignored.
 * @returns Returns NO if the transaction can not be aborted, and YES if the abort has been queued but is not guaranteed to happen
 * @since 2.0.0
 */
- (BOOL)requestAbort;

@end
