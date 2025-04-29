#include <bits/stdc++.h>
using namespace std;
int main(){
    shared_ptr<Account> account = make_shared<Account>(1, 10000);
    shared_ptr<Transaction> transaction = make_shared<Transaction> (101, 500);
    shared_ptr<Payment Method> payment Method = make_shared<CreditCard>();

    shared_ptr<Payment Command> paymentCommand = make_shared<Payment Command>(transaction, paymentMethod, account);
    
    PaymentGateway geteway;
    gateway.addTransaction(paymentCommnd);

    shared_ptr<TransactionValidator> fraudValidator = make_shared<FraudDetectionValidator();
    shared_ptr<TransactionValidator> limitValidator = make_shared<LimitValidator();
    fraudValidator->setNext (limitValidator);

    if(fraudValidator->Validate(transaction)){
        gateway.processTransactions();
    }

    shared_ptr<Refund Command> refundCommand =make_shared<Refund Command> (transaction,account);
    gateway.addTransaction(refundCommand);
    gateway.processTransactions();
    return 0;
}