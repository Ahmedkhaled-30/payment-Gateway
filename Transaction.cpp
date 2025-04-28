// Abstract Command Pattern
class TransactionCommand
{
  public:
    virtual void execute() = 0 ;
};

// Transaction State (State Pattern)
enum class TransactionState
{
    pending,
    Completed,
    failed
};


class Transaction
{
    private:
        int TransactionId;
        double amount;
        TransactionState state;
    public:
    Transaction(int id , double amt):TransactionId(id),amount(amt),state(TransactionState::pending){} 
    
    void process()
    {
        state = TransactionState::Completed;
        cout<< "Transaction "<< TransactionId <<" completed.\n";
    }
    
    void fail()
    {
        state = TransactionState::failed;
        cout<< "Transaction "<< TransactionId <<" failed.\n";
    }
    
    int getId() const{return TransactionId; }
    double getAmount() const{return amount; }
    TransactionState getState()const {return state; }
};