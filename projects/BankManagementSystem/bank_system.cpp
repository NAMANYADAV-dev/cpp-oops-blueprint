#include<iostream>
#include<vector>
#include<string>
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



                        void adjustBalance(double amount) {

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

                            adjustBalance(totalDeduction);

                 }else {

                            cout << "Overdraft limit exceeded\n";
                            

                 }

         }


                     void display() const override {




                    cout << "Account Holder Name: "      << accountHolderName << endl;
                    cout << "Account Number     : "      << accountNumber << endl;
                    cout << "Account Balance    : "      << (getBalance())  << endl;


            }


};



void Menu()  {


                    cout << "\n========== BANK MANAGEMENT SYSTEM ==========\n";

                    cout << "1. Create Saving Account\n";
                    cout << "2. Create Current Account\n";

                    cout << "3. Deposit Money\n";
                    cout << "4. Withdraw Money\n";

                    cout << "5. Search Account\n";
                    cout << "6. Display Account Details\n";
                    cout << "7. Display All Accounts\n";

                    cout << "8. Transfer Money\n";

                    cout << "9. Exit\n";

                
                    cout << "\nEnter Your Choice : ";

                 

}


int main () {
 
    vector<Account *> accounts;

    while(true) {
        
            Menu();

            int choice ;

            cin>>choice;

            if(choice == 1) {

                     string accountHolderName;

                        cin.ignore();

                        cout << "Enter Account Holder Name: ";
                        getline(cin, accountHolderName);

                        ll accountNumber;

                        cout << "Enter Account Number: ";
                        cin >> accountNumber;

                        double accountBalance;

                        cout << "Enter Initial Balance: ";
                        cin >> accountBalance;

                        double interestRate;

                        cout << "Enter Interest Rate: ";
                        cin >> interestRate;

                        double minimumBalance;

                        cout << "Enter Minimum Balance: ";
                        cin >> minimumBalance;


                    accounts.push_back(new SavingAccount (

                            accountHolderName,
                            accountNumber,
                            accountBalance,
                            interestRate,
                            minimumBalance

             
                        ));
                     
                        cout << "Size = " << accounts.size() << endl;

            }

            else if(choice == 2) {


                      string accountHolderName;

                        cin.ignore();

                        cout << "Enter Account Holder Name: ";
                        getline(cin, accountHolderName);

                        ll accountNumber;

                        cout << "Enter Account Number: ";
                        cin >> accountNumber;

                        double accountBalance;

                        cout << "Enter Initial Balance: ";
                        cin >> accountBalance;

                        double transactionFee;

                        cout << "Enter transactionFee: ";
                        cin >> transactionFee;

                        double overdraftLimit;

                        cout << "Enter overdraftLimit: ";
                        cin >> overdraftLimit;




                        accounts.push_back(new CurrentAccount(

                                    accountHolderName,
                                    accountNumber,
                                    accountBalance,
                                    transactionFee,
                                    overdraftLimit



                        ));




            }
     
            else if(choice == 7) {


                 cout << "Inside Choice 7\n";

    cout << "Size = "
         << accounts.size()
         << endl;


                    for(Account *acc : accounts) {

                            acc->display();

                            cout << endl;

                    }


            }
            else if (choice == 9) {

                    break;

            }



    }
    

 return 0 ;

}