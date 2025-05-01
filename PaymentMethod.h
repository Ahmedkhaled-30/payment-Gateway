#pragma once
#include <iostream>

class PaymentMethod {
public:
    virtual ~PaymentMethod() = default;
    virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod {
public:
    void processPayment(double amount) override {
        std::cout << "Processing Credit Card payment of $ " << amount << '\n';
    }
};

class Paypal : public PaymentMethod {
public:
    void processPayment(double amount) override {
        std::cout << "Processing Paypal payment of $ " << amount << '\n';
    }
};