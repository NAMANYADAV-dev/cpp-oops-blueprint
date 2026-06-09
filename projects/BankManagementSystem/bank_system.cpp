#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<memory>
using ll = long long ;

class Account {

    private:
            double accountBalance ;
    protected :
            std::string accountHolderName;
            ll accountNumber;

                        void updateBalance(double amount ) {
            
                             if(amount > 0  && amount <= accountBalance) {
            
                                    accountBalance -= amount;
            
                             }
                             else {

                                    std::cout << "Insufficient balace\n";

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

            Account (std::string holderName , ll accountNumber  , double accountbalance ){

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

                        std::cout << "Invalid Account Name. Only Alphabets and Space Allowed ..." << std::endl;

                }


                if(accountNumber > 0) {

                    this->accountNumber = accountNumber;

                }else{

                        this->accountNumber = 0;

                        std::cout << "Invalid account number\n";

                }



                if(accountbalance > 0) {

                    this->accountBalance = accountbalance;

                }else {

                    this->accountBalance = 0 ;

                    std::cout << "Invalid Your amout submited is fail .."<< std::endl;
                }



            }

            virtual void withdraw(double amount) = 0;

            void deposit(double amount){


                if(amount > 0) {

                     this->accountBalance += amount;

                }else{

                   std::cout << "Invalid deposit amount\n";

                }


            }

            virtual void display() const = 0;

            virtual ~Account () {}

            double getBalance ()  const {

                return accountBalance ;

            }


            ll numberAccount () const {


                 return accountNumber;

            }


};


class SavingAccount : public Account {

    private :
       double interestRate; 
        double minimumBalance;
    public :
                SavingAccount (std::string holderName , ll accountNumber , double accountbalance , double interestRate , double minimumBalance ) : Account (holderName , accountNumber , accountbalance),
                
                interestRate (interestRate < 0  ? 0 : interestRate ) ,
                  minimumBalance (minimumBalance)

                {
                          std::cout << "Saving Account Created\n";      
                }

            void withdraw(double amount) override {

                   double balance = getBalance();

                   if(amount <= balance && (balance - amount ) >= minimumBalance) {

                                updateBalance(amount) ; 

                   }
                        else {

                            std::cout << "Minimum balance must be maintained\n";

                        }


            }

            void display() const override {


                    double interestRateAmount = ((getBalance())*interestRate)/100;


                    std::cout << "\n========== SAVING BANK ACCOUNT  ==========" << std::endl;  

                    std::cout << "Account Holder Name: "      << accountHolderName << std::endl;
                    std::cout << "Account Number     : "      << accountNumber << std::endl;
                    std::cout << "Account Balance    : "      << (getBalance())  << std::endl;
                    std::cout << "InterestRateAmount : "      << interestRateAmount << std::endl;
                    std::cout << "Minimum Balance    : "      << minimumBalance << std::endl;
                    std::cout << "Total Balance Amount : "      << (getBalance() + interestRateAmount) << std::endl;


            }
        

};


class CurrentAccount : public Account {

    private :
        double transactionFee ;
        double overdraftLimit ;
    public : 

         CurrentAccount(std::string holderName , ll accountNumber , double accountbalance , double transactionFee , double overdraftLimit) : Account(holderName , accountNumber , accountbalance),
         transactionFee(transactionFee < 0 ? 0 : transactionFee ),
         overdraftLimit(overdraftLimit < 0 ? 0 : overdraftLimit)  {
 

                 std::cout << "CurrentAccount is created ..." << std::endl;
        

         }

         void withdraw( double amount) override {

                 double totalDeduction = amount + transactionFee ;

                 if(totalDeduction <= (getBalance() + overdraftLimit)) {

                            adjustBalance(totalDeduction);

                 }else {

                            std::cout << "Overdraft limit exceeded\n";
                            

                 }

         }


                     void display() const override {



                std::cout << "\n========== CURRENT BANK ACCOUNT  ==========" << std::endl;
                    
                    std::cout << "Account Holder Name: "      << accountHolderName << std::endl;
                    std::cout << "Account Number     : "      << accountNumber << std::endl;
                    std::cout << "Account Balance    : "      << (getBalance())  << std::endl;


            }


};



void Menu()  {


                    std::cout << "\n========== BANK MANAGEMENT SYSTEM ==========" << std::endl;

                    std::cout << "1. Create Saving Account\n";
                    std::cout << "2. Create Current Account\n";

                    std::cout << "3. Deposit Money\n";
                    std::cout << "4. Withdraw Money\n";

                    std::cout << "5. Search Account\n";
                    std::cout << "6. Display Account Details\n";
                    std::cout << "7. Display All Accounts\n";

                    std::cout << "8. Exit\n";
                    std::cout << "\nEnter Your Choice : ";

                 

}


int main () {
 
    std::vector<std::unique_ptr<Account>> accounts;

    while(true) {
        
            Menu();

            int choice ;

            std::cin>>choice;

            if(choice == 1) {

                     std::string accountHolderName;

                        std::cin.ignore();

                        std::cout << "Enter Account Holder Name: ";
                        std::getline(std::cin, accountHolderName);

                        ll accountNumber;

                        std::cout << "Enter Account Number: ";
                        std::cin >> accountNumber;

                        double accountBalance;

                        std::cout << "Enter Initial Balance: ";
                        std::cin >> accountBalance;

                        double interestRate;

                        std::cout << "Enter Interest Rate: ";
                        std::cin >> interestRate;

                        double minimumBalance;

                        std::cout << "Enter Minimum Balance: ";
                        std::cin >> minimumBalance;


                    accounts.push_back(std::make_unique<SavingAccount> (

                            accountHolderName,
                            accountNumber,
                            accountBalance,
                            interestRate,
                            minimumBalance

             
                        ));
                     
                        std::cout << "Size = " << accounts.size() << std::endl;

            }

            else if(choice == 2) {


                     std::string accountHolderName;

                        std::cin.ignore();

                        std::cout << "Enter Account Holder Name: ";
                        std::getline(std::cin, accountHolderName);

                        ll accountNumber;

                        std::cout << "Enter Account Number: ";
                        std::cin >> accountNumber;

                        double accountBalance;

                        std::cout << "Enter Initial Balance: ";
                        std::cin >> accountBalance;

                        double transactionFee;

                        std::cout << "Enter transactionFee: ";
                        std::cin >> transactionFee;

                        double overdraftLimit;

                        std::cout << "Enter overdraftLimit: ";
                        std::cin >> overdraftLimit;




                        accounts.push_back(std::make_unique<CurrentAccount>(

                                    accountHolderName,
                                    accountNumber,
                                    accountBalance,
                                    transactionFee,
                                    overdraftLimit



                        ));




            }else if (choice == 3) {

                   ll accountNumber;
                   std::cout << "Enter Account Number: ";
                  std::cin >> accountNumber;
                  double amount;   

                  bool found = false;


                  for(auto& acc : accounts) {

                        if(acc->numberAccount() == accountNumber){

                                std::cout << "Enter your deposit amount ...\n";

                                std:: cin>> amount;

                                acc->deposit(amount) ;

                                std::cout << "Successfully Deposited! New Balance: " << acc->getBalance()<< std::endl;

                                found = true;

                                break;
                                

                        }

                  }

             if(!found) {

                std:: cout << "Error: Account Number Not Found!" << std::endl;

             }     
            
            }   


              else if(choice == 4){

                   ll accountNumber;
                   std::cout << "Enter Account Number: ";
                   std::cin >> accountNumber;
                   double amount;   

                  bool found = false;


                  for(auto& acc : accounts) {

                        if(acc->numberAccount() == accountNumber){

                                std::cout << "Enter your withdraw amount ...\n";

                                std:: cin>> amount;

                                acc->withdraw(amount) ;

                                std::cout << "Successfully withdraw New Balance: " << acc->getBalance()<< std::endl;

                                found = true;

                                break;
                                

                        }

                  }

             if(!found) {

                std:: cout << "Error: Account Number Not Found!" << std::endl;

             }     

              }


              else if(choice == 5) {

                    ll accountNumber;
                    std::cout << "Enter Account Number: ";
                    std::cin >> accountNumber;  
                    bool found = false;


                  for(auto& acc : accounts) {

                        if(acc->numberAccount() == accountNumber){


                                std::cout << "Successfully Found Your account... "<< std::endl;

                                found = true;

                                break;
                                

                        }

                  }

             if(!found) {

                std:: cout << "Error: Account Number Not Found!" << std::endl;

                }     



                }
                  else if(choice == 6) {

                       ll accountNumber;
                       std::cout << "Enter Account Number: ";
                       std::cin >> accountNumber;
                        bool found = false;


                  for(auto& acc : accounts) {

                        if(acc->numberAccount() == accountNumber){


                                std::cout << "Successfully Found Your account... "<< std::endl;

                                acc->display();

                                found = true;

                                break;
                                

                        }

                  }

             if(!found) {

                std:: cout << "Error: Account Number Not Found!" << std::endl;

                }     

                  }
 


             else if(choice == 7) {


                     std::cout << "Inside Choice 7\n";

                       std::cout << "Size = "
                        << accounts.size()
                           << std::endl;
                        bool found = false;    



                   for(const auto& acc : accounts) {

                                acc->display();
                                found = true;
                   }

                   
                   if(!found) {
                       
                       std::cout << "No account founded ...\n";
                       
                    }
                    
                    break;

            }
            else if (choice == 8) {

                    break;

            }



    }
    

 return 0 ;

}