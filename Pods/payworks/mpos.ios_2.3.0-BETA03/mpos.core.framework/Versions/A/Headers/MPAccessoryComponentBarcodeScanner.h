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


#import "MPAccessoryComponent.h"

@class MPAccessoryComponentBarcodeScannerConfiguration;
@class MPAccessoryComponentBarcodeScanner;

typedef void (^MPBarcodeComponentStartScanSuccess)(MPAccessoryComponentBarcodeScanner *component);
typedef void (^MPBarcodeComponentScan)(MPAccessoryComponentBarcodeScanner *component, NSData *data);
typedef void (^MPBarcodeComponentButton)(MPAccessoryComponentBarcodeScanner *component, NSUInteger buttonStatus);
typedef void (^MPBarcodeComponentStartScanFailure)(MPAccessoryComponentBarcodeScanner *component, NSError *error) ;


typedef void (^MPBarcodeComponentStopScanSuccess)(MPAccessoryComponentBarcodeScanner *component);
typedef void (^MPBarcodeComponentStopScanFailure)(MPAccessoryComponentBarcodeScanner *component, NSError *error);

@interface MPAccessoryComponentBarcodeScanner : MPAccessoryComponent

@property (strong, nonatomic) MPAccessoryComponentBarcodeScannerConfiguration *config;

- (void)startScan:(MPBarcodeComponentStartScanSuccess)success
             scan:(MPBarcodeComponentScan)scan
           button:(MPBarcodeComponentButton)button
          failure:(MPBarcodeComponentStartScanFailure)failure;


- (void)stopScan:(MPBarcodeComponentStopScanSuccess)success
         failure:(MPBarcodeComponentStopScanFailure)failure;
@end