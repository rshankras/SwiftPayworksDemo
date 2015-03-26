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
 * The range of models you can to connect to during a checkout.
 * @since 2.2.0
 */
typedef NS_ENUM(NSUInteger, MPAccessoryFamily){
    /** Use the Miura MPI devices  */
    MPAccessoryFamilyMiuraMPI,
    /** Use the Verifone e-Series (except e105) */
    MPAccessoryFamilyVerifoneESeries,
    /** Use the Verifone e105 */
    MPAccessoryFamilyVerifoneE105,
    /** Use a mock */
    MPAccessoryFamilyMock
};


@class MPTransactionTemplate;
#import "MPPaymentProcess.h"
#import "MPTransaction.h"


/**
 * Callback block for a transaction query with session identifier.
 * @param transaction The transaction with the provided sessionIdentifier
 * @param error The error that might have occured
 * @since 2.2.0
 */
typedef void (^MPTransactionProviderQueryBySessionIdentifierCompleted)(MPTransaction *transaction, NSError *error);


/**
 * Provider that simplifies the process of making a single transaction by encapsulating the necessary steps inbetween.
 * @since 2.2.0
 */
@interface MPTransactionProvider : NSObject

/**
 * Creates a new template for a new transaction.
 * @param amount The amount The amount of the transaction
 * @param currency The currency of the transaction
 * @param subject The subject of the transaction
 * @param customIdentifier The custom identifier of the transaction
 * @return A new transaction templated that can be used to start a transaction locally
 * @since 2.2.0
 */
- (MPTransactionTemplate *)chargeTransactionTemplateWithAmount:(NSDecimalNumber *)amount
                                                      currency:(MPCurrency)currency
                                                       subject:(NSString *)subject
                                              customIdentifier:(NSString *)customIdentifier;

/**
 * Creates a new template, linking to a previous transaction.
 * @param referencedTransactionIdentifier The transaction to reference
 * @param subject The subject of the transaction
 * @param customIdentifier The custom identifier of the transaction
 * @return A new transaction templated that can be used to start a transaction locally
 * @since 2.2.0
 */
- (MPTransactionTemplate *)refundTransactionTemplateWithReferenceToPreviousTransaction:(NSString *)referencedTransactionIdentifier
                                                                               subject:(NSString *)subject
                                                                      customIdentifier:(NSString *)customIdentifier;


/**
 * Starts and returns a new payment process which guide you through a complete transaction. This method is used if the session has already been created on the backend.
 * @param sessionIdentifier The sessionIdentifier of the transaction to start
 * @param accessoryFamily The kind of accessory you want to use for the transaction
 * @param statusChanged The status of the process changed and new information can be displayed to the user
 * @param actionRequired An explicit action by the merchant or customer is required
 * @param completed The paymentProcess ended and a new one can be started
 * @since 2.2.0
 */
- (MPPaymentProcess *)startPaymentWithSessionIdentifier:(NSString *)sessionIdentifier
                                         usingAccessory:(MPAccessoryFamily)accessoryFamily
                                          statusChanged:(MPPaymentProcessStatusChanged)statusChanged
                                         actionRequired:(MPPaymentProcessActionRequired)actionRequired
                                              completed:(MPPaymentProcessCompleted)completed;

/**
 * Starts and returns a new payment process which guide you through a complete transaction. This method registers the transaction locally without requiring a backend for this.
 * @param template The template describing the general transaction parameters
 * @param accessoryFamily The kind of accessory you want to use for the transaction
 * @param registered Callback when the transaction has been registered with the backend. Use this information to save a reference to it.
 * @param statusChanged The status of the process changed and new information can be displayed to the user
 * @param actionRequired An explicit action by the merchant or customer is required
 * @param completed The paymentProcess ended and a new one can be started
 * @since 2.2.0
 */
- (MPPaymentProcess *)startPaymentWithTemplate:(MPTransactionTemplate *)template
                                usingAccessory:(MPAccessoryFamily)accessoryFamily
                                    registered:(MPPaymentProcessRegistered)registered
                                 statusChanged:(MPPaymentProcessStatusChanged)statusChanged
                                actionRequired:(MPPaymentProcessActionRequired)actionRequired
                                     completed:(MPPaymentProcessCompleted)completed;

/**
 * Queries a transaction by its session identifier.
 * @param sessionIdentifier The session identifier of the transaction
 * @param completed The asnyc completion callback
 * @since 2.2.0
 */
- (void)queryTransactionBySessionIdentifier:(NSString *)sessionIdentifier
                                  completed:(MPTransactionProviderQueryBySessionIdentifierCompleted)completed;


@end
