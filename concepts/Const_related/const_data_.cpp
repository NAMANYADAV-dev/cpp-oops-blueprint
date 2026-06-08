#include<iostream>

class Student{

    public:

      const int totalStudent ;

        Student(int totalStudent) : totalStudent(totalStudent) {



        }

        void displayData() const {

            std:: cout << totalStudent << std::endl;

        }

};

int main () {

    Student s(10);

    s.displayData();

    return 0 ;

}