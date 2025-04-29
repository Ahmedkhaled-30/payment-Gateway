#include <bits/stdc++.h>
using namespace std;
class PaymentGateway {
    private:
    vector<shared_ptr<TransactionCommand>> transactionQueue;
    public:
    void addTransaction(shared_ptr<TransactionCommand> command) {
    transactionQueue.push_back(command);
    }
    void processTransactions() {
    for (auto& command: transactionQueue) {
         command->execute();
    }
    class PaymentCommand : public TransactionCommand {
        private:
        shared_ptr<Transaction> transaction;
        shared_ptr<Payment Method> paymentMethod;
        shared_ptr<Account> account;
        public:
        PaymentCommand(shared_ptr<Transaction> tx, shared_ptr<PaymentMethod> method,shared_ptr<Account> acc)
         : transaction(tx), payment Method (method), account (acc) {}

        void execute() override {
            if (account->getBalance() >= transaction->getAmount()) { 
                paymentMethod->processPayment (transaction->getAmount()); 
                account->deduct Balance (transaction->getAmount());
                 transaction->process();
            } else {
            transaction->fail();
            }
        }
    }

}
};
class RefundCommand: public TransactionCommand {
    private:
    std::shared_ptr<Transaction> transaction;
     std::shared_ptr<Account> account;
    public:
    RefundCommand(std::shared_ptr<Transaction> tx, std::shared_ptr<Account> acc)
    : transaction(tx), account (acc) {}

    void execute() override {
    account->refund Balance (transaction->getAmount());
    transaction->process();
    }
};        