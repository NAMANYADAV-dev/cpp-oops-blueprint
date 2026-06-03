#include<iostream>
#include<memory>

int main ()  {

    std::unique_ptr<int>ptr = std::make_unique<int>(50);

    std:: cout << *ptr << std:: endl;
    
    
    *ptr = 100;
    
    std:: cout << *ptr << std:: endl;



    return 0 ;

}