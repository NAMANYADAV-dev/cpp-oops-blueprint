#include<iostream>

class Student {

    public:

        void displayName(const std::string& name)  {

                // name = "rahul"; 

                std:: cout << name << std::endl;

        }


};

int main () {
    
    
    Student s;

    s.displayName("Naman");

    return 0 ; 

}