#include<iostream>

class Student{

    public :
            int *marks;
 
        Student(int n) {

            marks = new int(n);

        }   
};


int main () {

    Student s(39);

    Student s1 = s;

    std:: cout << s1.marks << std::endl << s.marks << std::endl;

    return 0;


}