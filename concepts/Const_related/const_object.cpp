#include<iostream>

class Student {

    public:

        void display() const {

            std:: cout << "What is your name ...\n";

        }


};

int main () {

    const Student s;

    s.display();

    return 0 ; 

}