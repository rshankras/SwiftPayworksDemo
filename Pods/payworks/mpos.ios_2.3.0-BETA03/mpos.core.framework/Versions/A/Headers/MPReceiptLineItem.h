//
// PAYWORKS GMBH ("COMPANY") CONFIDENTIAL
// Copyright (c) 2013 payworks GmbH, All Rights Reserved.
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

#import <Foundation/Foundation.h>


/** Unique keys used by a receipt line item. */
typedef NS_ENUM(NSInteger, MPReceiptLineKey) {

    /** The type of the receipt. */
    MPReceiptLineKeyReceiptType = 0,

    /** The type of the transaction (charge or refund). */
    MPReceiptLineKeyTransactionType = 1,

    /** The subject of the receipt. */
    MPReceiptLineKeySubject = 2,

    /** The transaction identifier. */
    MPReceiptLineKeyIdentifier = 3,

    /** The amount and currency formatted for the used locale. */
    MPReceiptLineKeyAmountAndCurrency = 4,

    /**  The date formatted for the used locale. */
    MPReceiptLineKeyDate = 5,

    /** The time formatted for the used locale. */
    MPReceiptLineKeyTime = 6,

    /** The status text based on the transaction state. */
    MPReceiptLineKeyStatusText = 7,

    /** The status of the transaction. */
    MPReceiptLineKeyStatus = 8,

    /** The scheme or label of the used card. */
    MPReceiptLineKeyPaymentDetailsSchemeOrLabel = 100,

    /** The masked account number of the used card. */
    MPReceiptLineKeyPaymentDetailsMaskedAccount = 101,

    /** The actual source of the payment details. */
    MPReceiptLineKeyPaymentDetailsSource = 102,

    /** The application identifier of the used card. */
    MPReceiptLineKeyPaymentDetailsEMVApplicationID = 103,

    /** The sequence number of the card */
    MPReceiptLineKeyPaymentDetailsAccountSequenceNumber = 104,
    
    /** The verification used for the transaction */
    MPReceiptLineKeyPaymentDetailsCustomerVerification = 105,
    
    /** The transaction identifier set by the aquirer. */
    MPReceiptLineKeyClearingDetailsTransactionIdentifier = 200,

    /** The original transaction identifier set by the aquirer. */
    MPReceiptLineKeyClearingDetailsOriginalTransactionIdentifier = 201,

    /** The authorization code set by the aquirer. */
    MPReceiptLineKeyClearingDetailsAuthorizationCode = 202,

    /** The merchant identifier set by the aquirer. */
    MPReceiptLineKeyClearingDetailsMerchantId = 203,

    /** The terminal identifier used for the transaction. */
    MPReceiptLineKeyClearingDetailsTerminalId = 204,
    
};

/**
 * A localized entry on the receipt.
 * @since 2.1.0
 */
@interface MPReceiptLineItem : NSObject

/**
 * The key indentifying the content of the line item.
 * @since 2.1.0
 */
@property (readonly, assign, nonatomic) MPReceiptLineKey key;

/**
 * The localized label of the line item.
 * @since 2.1.0
 */
@property (readonly, strong, nonatomic) NSString *label;

/**
 * The (localized) value of the line item.
 * @since 2.1.0
 */
@property (readonly, strong, nonatomic) NSString *value;

@end
