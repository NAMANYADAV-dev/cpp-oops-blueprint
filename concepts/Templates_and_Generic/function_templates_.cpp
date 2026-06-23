#include<iostream>

template<typename T>
T add (T a , T b) {
    
    return a + b ; 
    
}


template<typename T , typename T1>
void show(T a , T1 b) {

    std:: cout << a  <<  " , " << b << std::endl; 
}


template<typename T, typename T2>

void display( T a  , T2 b) {

    std::cout << a << " , " << b << std::endl;

}

int main () {

    std:: cout << add(10 , 59)<< std::endl;
    std:: cout << add(10.6 , 59.34)<< std::endl;
    show(10 , 'x');
    std:: cout << add(std::string("Hello") ,std::string("Naman" ))<< std::endl;
    display(101 ,"Naman");
    return 0 ;

}