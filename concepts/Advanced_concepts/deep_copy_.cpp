#include<iostream>

class Student {

    public :
            int *marks;
            Student( int n ) {

                    marks = new int(n);
            }

            Student (const Student& obj) {
                    marks = new int(*obj.marks);
            }
            ~Student() {

                delete marks;
            }
};


int main () {

    Student s(100);

    Student s1 = s ;

    std:: cout << s1.marks << std::endl << s.marks << std::endl;

    return 0 ;

}


