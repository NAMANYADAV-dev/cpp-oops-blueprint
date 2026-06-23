#include<iostream>

template<typename T>

class Box{

    private :

            T data;

    public  :

            Box(T d) {

                this->data = d;

            }

            void display() {

                std:: cout << data << std::endl;

            }

};


int main () {

    Box<int>b1(300);
    Box<double>b2(300.35);
    Box<std::string>b3("Naman");

    b1.display();
    b2.display();
    b3.display();

    return 0;


}