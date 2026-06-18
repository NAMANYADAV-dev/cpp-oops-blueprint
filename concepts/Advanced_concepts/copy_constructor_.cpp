#include<iostream>

class Student {

    public :


        std::string name;


        Student(std::string n) {

                this->name = n ;

        }

        Student(const Student& obj) {

                name = obj.name;

        }
};

int main () {

    Student s("NAMAN");

    Student s1 = s;

    std:: cout << s1.name << std::endl;

    return 0;
    

}