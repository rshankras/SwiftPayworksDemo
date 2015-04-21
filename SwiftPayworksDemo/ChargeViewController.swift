//
//  ViewController.swift
//  SwiftPayworksDemo
//
//  Created by Ravi Shankar on 26/03/15.
//  Copyright (c) 2015 Ravi Shankar. All rights reserved.
//

import UIKit

class ChargeViewController: UIViewController {
    
    @IBOutlet weak var amountTxtField: UITextField!
    @IBOutlet weak var messageLabel: UILabel!
    
    let MERCHANT_IDENTIFIER = "YOUR_MERCHANT_IDENTIFIER"
    let MERCHANT_SECRET_KEY = "YOUR_SECRET_KEY"
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    @IBAction func chargeCard(sender: UIButton) {
        
        let amount:NSDecimalNumber = NSDecimalNumber(string: self.amountTxtField.text)
        
        let transactionProvider:MPTransactionProvider = MPMpos .transactionProviderForMode( MPProviderMode.MOCK, merchantIdentifier: MERCHANT_IDENTIFIER, merchantSecretKey: MERCHANT_SECRET_KEY)
        
        let template: MPTransactionTemplate = transactionProvider.chargeTransactionTemplateWithAmount(amount, currency: MPCurrency.EUR, subject: "subject", customIdentifier: "customIdentifier")
        
        let paymentProcess:MPPaymentProcess = transactionProvider.startPaymentWithTemplate(template, usingAccessory: MPAccessoryFamily.Mock, registered: { (let paymentProcess:MPPaymentProcess!, let transaction:MPTransaction!) -> Void in
            
            }, statusChanged: { (let paymentProcess:MPPaymentProcess!, let transaction:MPTransaction!, let paymentProcessDetails:MPPaymentProcessDetails!) -> Void in
                
                self.messageLabel.text = self.formatMessage(paymentProcessDetails.information)
                
            }, actionRequired: { (let paymentProcess:MPPaymentProcess!, let transaction:MPTransaction!, let transactionAction:MPTransactionAction, let transactionActionSupport:MPTransactionActionSupport!) -> Void in
                
            }) {(let paymentProcess:MPPaymentProcess!, let transaction:MPTransaction!, let paymentProcessDetails:MPPaymentProcessDetails!) -> Void in
                
                self.messageLabel.text = self.formatMessage(paymentProcessDetails.information)
        }
    }
    
    func formatMessage(information:AnyObject) -> String {
        let temp = ((information[0] as! NSString) as String) + "\n"
        return temp + ((information[1] as! NSString) as String)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

