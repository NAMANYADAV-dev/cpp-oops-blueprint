#include<iostream>
#include<cctype>
using namespace std;

using  ll = long long ;

class Account {

    private:
            double accountBalance ;
    protected :
            string accountHolderName;
            ll accountNumber;

                        void updateBalance(double amount ) {
            
                             if(amount > 0  && amount <= accountBalance) {
            
                                    accountBalance -= amount;
            
                             }
                             else {

                                    cout << "Insufficient balace\n";

                             }
                        
                        }



                        void currentAccountBalanceUpdate(double amount) {

                                    if(amount <= 0) {

                                        accountBalance +=amount;
                                    }else {

                                        accountBalance -=amount;

                                    }


                        }

    public :    

            Account (string holderName , ll accountNumber  , double accountbalance ){

                bool isValid = true ;


                for (int i = 0 ; i < holderName.length(); i++ ) {

                       char letterName = holderName[i];

                       if (!isalpha(letterName) && !isspace(letterName)){

                            isValid = false;
                            break;

                       }

                }

                if(isValid && !holderName.empty()) {

                        this->accountHolderName = holderName;


                }
                else {
                     
                       this->accountHolderName = "";

                        cout << "Invalid Account Name. Only Alphabets and Space Allowed ..." << endl;

                }


                if(accountNumber > 0) {

                    this->accountNumber = accountNumber;

                }else{

                        this->accountNumber = 0;

                        cout << "Invalid account number\n";

                }



                if(accountbalance > 0) {

                    this->accountBalance = accountbalance;

                }else {

                    this->accountBalance = 0 ;

                    cout << "Invalid Your amout submited is fail .."<< endl;
                }



            }

            virtual void withdraw(double amount) = 0;

            void deposit(double amount){


                if(amount > 0) {

                     this->accountBalance += amount;

                }else{

                   cout << "Invalid deposit amount\n";

                }


            }

            virtual void display() const = 0;

            virtual ~Account () {}

            double getBalance ()  const {

                return accountBalance ;

            }


};


class SavingAccount : public Account {

    private :
       double interestRate; 
        double minimumBalance;
    public :
                SavingAccount (string holderName , ll accountNumber , double accountbalance , double interestRate , double minimumBalance ) : Account (holderName , accountNumber , accountbalance),
                
                interestRate (interestRate < 0  ? 0 : interestRate ) ,
                  minimumBalance (minimumBalance)

                {
                          cout << "Saving Account Created\n";      
                }

            void withdraw(double amount) override {

                   double balance = getBalance();

                   if(amount <= balance && (balance - amount ) >= minimumBalance) {

                                updateBalance(amount) ; 

                   }
                        else {

                            cout << "Minimum balance must be maintained\n";

                        }


            }

            void display() const override {


                    double interestRateAmount = ((getBalance())*interestRate)/100;




                    cout << "Account Holder Name: "      << accountHolderName << endl;
                    cout << "Account Number     : "      << accountNumber << endl;
                    cout << "Account Balance    : "      << (getBalance())  << endl;
                    cout << "InterestRateAmount : "      << interestRateAmount << endl;
                    cout << "Minimum Balance    : "      << minimumBalance << endl;
                    cout << "Total Balance Amount : "      << (getBalance() + interestRateAmount) << endl;


            }
        

};



class CurrentAccount : public Account {

    private :
        double transactionFee ;
        double overdraftLimit ;
    public : 

         CurrentAccount(string holderName , ll accountNumber , double accountbalance , double transactionFee , double overdraftLimit) : Account(holderName , accountNumber , accountbalance),
         transactionFee(transactionFee < 0 ? 0 : transactionFee ),
         overdraftLimit(overdraftLimit < 0 ? 0 : overdraftLimit)  {
 

                 cout << "CurrentAccount is created ..." << endl;
        

         }

         void withdraw( double amount) override {

                 double totalDeduction = amount + transactionFee ;

                 if(totalDeduction <= (getBalance() + overdraftLimit)) {


                            double finalAmount = getBalance() - totalDeduction ;

                            cout << finalAmount << endl;

                            currentAccountBalanceUpdate(finalAmount);

                 }

         }


                     void display() const override {




                    cout << "Account Holder Name: "      << accountHolderName << endl;
                    cout << "Account Number     : "      << accountNumber << endl;
                    cout << "Account Balance    : "      << (getBalance())  << endl;


            }


};


int main () {

CurrentAccount c("Naman",3534,5000,20,10000);

c.withdraw(12000.0);


c.display();
c.deposit(2040);

c.display();


 return 0 ;

}