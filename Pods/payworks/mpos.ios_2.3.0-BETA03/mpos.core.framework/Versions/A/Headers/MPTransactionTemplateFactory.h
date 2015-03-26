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

@class MPTransactionTemplate;
#import "MPTransaction.h"

/**
 * The transaction temnplate factory is used to create a new transaction template that can be used to create a new transaction via the MPServerSubsystem additions.
 * @since 2.0.0
 */
@interface MPTransactionTemplateFactory : NSObject

/**
 * Creates a new template for a new transaction.
 * @param amount The amount The amount of the transaction
 * @param currency The currency of the transaction
 * @param type The type of the transaction
 * @param subject The subject of the transaction
 * @param customIdentifier The custom identifier of the transaction
 * @return A new transaction templated that can be registered
 * @since 2.0.0
 */
- (MPTransactionTemplate *)transactionTemplateWithAmount:(NSDecimalNumber *)amount currency:(MPCurrency)currency type:(MPTransactionType)type subject:(NSString *)subject customIdentifier:(NSString *)customIdentifier;


/**
 * Creates a new template, linking to a previous transaction.
 * @param referencedTransactionIdentifier The transaction to reference
 * @param type The type of the transaction
 * @param subject The subject of the transaction
 * @param customIdentifier The custom identifier of the transaction
 * @return A new transaction templated that can be registered
 * @since 2.0.0
 */
- (MPTransactionTemplate *)transactionTemplateWithReferenceToPreviousTransaction:(NSString *)referencedTransactionIdentifier type:(MPTransactionType)type subject:(NSString *)subject customIdentifier:(NSString *)customIdentifier;


/**
 * Creates a new template, linking to a previous transaction and providing additional payment related properties.
 * @param referencedTransactionIdentifier The transaction to reference
 * @param amount The amount The amount of the transaction
 * @param currency The currency of the transaction
 * @param type The type of the transaction
 * @param subject The subject of the transaction
 * @param customIdentifier The custom identifier of the transaction
 * @return A new transaction templated that can be registered
 * @since 2.0.0
 */
- (MPTransactionTemplate *)transactionTemplateWithReferenceToPreviousTransaction:(NSString *)referencedTransactionIdentifier amount:(NSDecimalNumber *)amount currency:(MPCurrency)currency type:(MPTransactionType)type subject:(NSString *)subject customIdentifier:(NSString *)customIdentifier;


@end
