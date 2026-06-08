#include<iostream>

void add () {

    static int counterValue = 0 ; 

        counterValue++ ;

        std:: cout << counterValue << std::endl;

}

int main () {

 add();
 add();
 add();
 add();

 return 0 ;

}