#include <iostream>
#include <memory>
#include "Account.h"
#include "Transaction.h"
#include "PaymentMethod.h"
#include "PaymentGateway.h"
#include "TransactionValidator.h"

int main() {
    std::shared_ptr<Account> account = std::make_shared<Account>(1, 10000);
    std::shared_ptr<Transaction> transaction = std::make_shared<Transaction>(101, 500);
    std::shared_ptr<PaymentMethod> paymentMethod = std::make_shared<CreditCard>();

    std::shared_ptr<PaymentCommand> paymentCommand = std::make_shared<PaymentCommand>(transaction, paymentMethod, account);
    
    PaymentGateway gateway;
    gateway.addTransaction(paymentCommand);

    std::shared_ptr<TransactionValidator> fraudValidator = std::make_shared<FraudDetectionValidator>();
    std::shared_ptr<TransactionValidator> limitValidator = std::make_shared<LimitValidator>();
    fraudValidator->setNext(limitValidator);

    if(fraudValidator->validate(transaction)) {
        gateway.processTransactions();
    }

    std::shared_ptr<RefundCommand> refundCommand = std::make_shared<RefundCommand>(transaction, account);
    gateway.addTransaction(refundCommand);
    gateway.processTransactions();
    return 0;
}