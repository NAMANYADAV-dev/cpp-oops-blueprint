#include<iostream>

template<typename...Args>

void show(Args... args) {

    show(args...);

}

int main () {

     show(10);
     show(10 , 30 );
     show(10 , 30 , 20 );
     show(10 , 20 , 30 , 40 );

     return 0 ; 

}