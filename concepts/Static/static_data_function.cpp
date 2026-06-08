#include<iostream>

class Student{

    public:

            static int count;

        static void show  () {


            std:: cout << count << std::endl;


        }

};

int Student::count = 0 ;

int main () {

    Student::show();
    return 0 ;

}