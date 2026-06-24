#include<iostream>

int main () {

    int age ;
    
    std::cout << "Enter Age: ";

    std::cin>> age;

    try {

        if(age < 18) {

                throw age;

        }

        std::cout << "Eligible" << std::endl;
    }catch (int a) {

        std::cout << "Not Eligible. Age = " << a << std::endl;

    }
     
     return 0 ; 

}