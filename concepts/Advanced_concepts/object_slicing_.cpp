#include<iostream>

class Animal {

 public:

        std::string name = "Animal";
};

class Dog : public Animal {

    public:

        int age = 6 ;
        std::string name1 = "rahul";
};


int main () {

    Dog d ;

    Animal *a = &d ;

    std:: cout << a->name << std::endl;

    return 0 ;

}