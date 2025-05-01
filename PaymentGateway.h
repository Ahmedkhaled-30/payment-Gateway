#pragma once
#include <vector>
#include <memory>
#include "TransactionCommand.h"
#include "Transaction.h"
#include "Account.h"
#include "PaymentMethod.h"

class PaymentGateway {
private:
    std::vector<std::shared_ptr<TransactionCommand>> transactionQueue;
public:
    void addTransaction(std::shared_ptr<TransactionCommand> command) {
        transactionQueue.push_back(command);
    }
    
    void processTransactions() {
        for (auto& command : transactionQueue) {
            command->execute();
        }
        transactionQueue.clear();
    }
};

class PaymentCommand : public TransactionCommand {
private:
    std::shared_ptr<Transaction> transaction;
    std::shared_ptr<PaymentMethod> paymentMethod;
    std::shared_ptr<Account> account;
public:
    PaymentCommand(std::shared_ptr<Transaction> tx, 
                  std::shared_ptr<PaymentMethod> method,
                  std::shared_ptr<Account> acc)
        : transaction(tx), paymentMethod(method), account(acc) {}

    void execute() override {
        if (account->getBalance() >= transaction->getAmount()) { 
            paymentMethod->processPayment(transaction->getAmount()); 
            account->deductBalance(transaction->getAmount());
            transaction->process();
        } else {
            transaction->fail();
        }
    }
};

class RefundCommand : public TransactionCommand {
private:
    std::shared_ptr<Transaction> transaction;
    std::shared_ptr<Account> account;
public:
    RefundCommand(std::shared_ptr<Transaction> tx, 
                 std::shared_ptr<Account> acc)
        : transaction(tx), account(acc) {}

    void execute() override {
        // Note: Need to add refundBalance method to Account class
        // account->refundBalance(transaction->getAmount());
        transaction->process();
    }
};