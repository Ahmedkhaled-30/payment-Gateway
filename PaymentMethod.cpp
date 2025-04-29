class PaymentMethod
{
  public:
    virtual void processPayment(double amount)=0;
};

// Concrete Payment Methods
class CreditCard : public PaymentMethod
{
    public:
        void processPayment(double amount)override
        {
            cout<< "Processing Credit Card payment of $ " << amount <<'\n';
        }
};
class Paypal : public PaymentMethod
{
    public:
        void processPayment(double amount)override
        {
            cout<<" Processing Paypa payment of $ "<<amount<<'\n';
        }
};