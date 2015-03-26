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

/**
 * Detailing the current state of the paymet process.
 * @since 2.2.0
 */
typedef NS_ENUM(NSUInteger, MPPaymentProcessDetailsState){
    /** The process has been initialized and awaits execution */
    MPPaymentProcessDetailsStateCreated,
    /** The process just started and the transaction is either registered or queried */
    MPPaymentProcessDetailsStateConnectingToAccessory,
    /** The transaction processing is ongoing and a card must be presented */
    MPPaymentProcessDetailsStateInitializingTransaction,
    /** The process is establishing a connection to an accessory */
    MPPaymentProcessWaitingForCardPresentation,
    /** The transaction processing is ongoing and a card must be removed */
    MPPaymentProcessWaitingForCardRemoval,
    /** The process is processing a transaction */
    MPPaymentProcessDetailsStateProcessing,
    /** The transaction was approved */
    MPPaymentProcessDetailsStateApproved,
    /** The transaction was declined */
    MPPaymentProcessDetailsStateDeclined,
    /** The transaction was aborted */
    MPPaymentProcessDetailsStateAborted,
    /** The process failed during one of its stages */
    MPPaymentProcessDetailsStateFailed
};

/**
 * More detailed information on the current state of the process.
 * @since 2.2.0
 */
typedef NS_ENUM(NSUInteger, MPPaymentProcessDetailsStateDetails){
    /** The process is initialized, nothing has happened yet */
    MPPaymentProcessDetailsStateDetailsCreated,
    
    /** A connection attempt with an accessory is ongoing */
    MPPaymentProcessDetailsStateDetailsConnectingToAccessory,
    /** An update check for the accessory is ongoing */
    MPPaymentProcessDetailsStateDetailsConnectingToAccessoryCheckingForUpdate,
    /** An update of the accessory is ongoing */
    MPPaymentProcessDetailsStateDetailsConnectingToAccessoryUpdating,

    /** The transaction template is registered with the server */
    MPPaymentProcessDetailsStateDetailsInitializingTransactionRegistering,
    /** The transaction details are queried from the server */
    MPPaymentProcessDetailsStateDetailsInitializingTransactionQuerying,

    /** The transaction processing is waiting for a card to be presented */
    MPPaymentProcessDetailsStateDetailsWaitingForCardPresentation,
    /** The transaction processing is waiting for a card removal */
    MPPaymentProcessDetailsStateDetailsWaitingForCardRemoval,
    
    /** The transaction processing is ongoing */
    MPPaymentProcessDetailsStateDetailsProcessing,
    /** The transaction requires an interactio before it can complete */
    MPPaymentProcessDetailsStateDetailsProcessingActionRequired,
    /** The transaction processing is waiting for a PIN entry */
    MPPaymentProcessDetailsStateDetailsProcessingWaitingForPIN,
    /** The transaction was completed */
    MPPaymentProcessDetailsStateDetailsProcessingCompleted,
    
    /** The transaction was approved */
    MPPaymentProcessDetailsStateDetailsApproved,
    /** The transaction was declined */
    MPPaymentProcessDetailsStateDetailsDeclined,
    /** The transaction was aborted */
    MPPaymentProcessDetailsStateDetailsAborted,
    /** The transaction processing failed at some point */
    MPPaymentProcessDetailsStateDetailsFailed
};


/**
 * Object holding representing the current status of the paymen process.
 * @since 2.2.0
 */
@interface MPPaymentProcessDetails : NSObject

/**
 * Provides a high level status of the current state of the process
 * @since 2.2.0
 */
@property (assign, readonly, nonatomic) MPPaymentProcessDetailsState state;

/**
 * Provides more details information on the current state of the process
 * @since 2.2.0
 */
@property (assign, readonly, nonatomic) MPPaymentProcessDetailsStateDetails stateDetails;

/**
 * Provides two lines of text (each with max 40 characters) that can be displayed on screen suitable for the current status
 * @since 2.2.0
 */
@property (strong, readonly, nonatomic) NSArray *information;

/**
 * Holds the error thrown by the underlying components in case of a failure. Only populated in case of state == MPPaymentProcessDetailsStateFailed
 * @since 2.2.0
 */
@property (strong, readonly, nonatomic) NSError *error;

@end
