
class Account
{
    private:
        int accountId;
        double balance;
    public:
        Account(int id , double bal):accountId(id),balance(bal){}
        
    int getId()const{return accountId; }
    double getBalance()const {return balance; }
    
    void deductBalance(double amount)
    {
        if(balance >= amount)
        {
            balance -= amount;
            cout<<"Balance after payment: $ " <<balance<<'\n';
        }
        else
        {
            cout<< "Insufficient funds for transaction.\n";
        }
    }
};