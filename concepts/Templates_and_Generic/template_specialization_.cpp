#include<iostream>

template<typename T>
void print(T value) {

    std:: cout << "General Template: " << value << std::endl;

}


template<>
void  print<std::string>(std::string value) {

        std::cout << "String specialization : " << value << std::endl;

}

int main () {

    print(10);
    print(10.0395);
    print(std::string("Naman"));

    return 0 ; 

}