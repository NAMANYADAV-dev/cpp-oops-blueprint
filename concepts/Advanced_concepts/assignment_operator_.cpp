#include<iostream>
#include<cstring>

class Wallet{

    public:

        int money;

        Wallet(int amount) {

            money = amount;

        }


        Wallet& operator=(const Wallet& other) {

                this->money = other.money;

                return *this;

        }


};


int main () {

    
    Wallet myWallet(199);
    Wallet yWallet(19);

    std:: cout << "before copying :" << std::endl;

    std:: cout << "My wallet : $" << myWallet.money << std::endl;
    std:: cout << "My wallet : $" << yWallet.money << std::endl;


    yWallet = myWallet;

         // Look at the values after assignment
    std::cout << "\nAfter copying (yourWallet = myWallet):" << std::endl;
    std::cout << "My Wallet: $" << myWallet.money << std::endl;
    std::cout << "Your Wallet: $" << yWallet.money << std::endl;


    return 0 ;


}