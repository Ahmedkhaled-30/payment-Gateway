#include <bits/stdc++.h>
using namespace std;
class TransactionValidator {
    public:
    virtual bool validate(std::shared_ptr<Transaction> transaction) = 0;
    virtual void setNext(std::shared_ptr<TransactionValidator> nextValidator) = 0;
};
    class Fraud DetectionValidator : public TransactionValidator {
    private:
    std::shared_ptr<TransactionValidator> nextValidator;
    public:
    bool validate(std::shared_ptr<Transaction> transaction) override {
         if (transaction->getAmount()> 1000) {
                std::cout << "Transaction flagged for fraud detection.\n";
                 return false;
        }         
         if (nextValidator) return nextValidator->validate(transaction);
            return true;
    void setNext(std::shared_ptr<TransactionValidator> nextValidator) override {
        this->nextValidator = nextValidator;
    }    
    }
};

    class LimitValidator: public TransactionValidator {
        private:
        std::shared_ptr<TransactionValidator> nextValidator;

        public:
        bool validate(std::shared_ptr<Transaction> transaction) override {
        if (transaction->getAmount() > 5000) {
            std::cout << "Transaction exceeds limit. \n";
             return false;
        }
        if (nextValidator) return nextValidator->validate(transaction);
        return true;
    
    void setNext(std::shared_ptr<TransactionValidator> nextValidator) override {
         this->nextValidator = nextValidator;
    }
    }
};