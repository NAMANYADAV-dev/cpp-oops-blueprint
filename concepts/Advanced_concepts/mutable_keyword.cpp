#include<iostream>

class Student {

    public:

       mutable int marks ;


       Student () {

            std:: cout << "hello bro ...\n";

       }

        void update(int m) {

                this->marks = m;

        }
        
        int getMarks() const {
            
            return marks;

        }


};


int main () {

const Student s;

 s.marks = 40;

 std:: cout <<  s.getMarks() << std::endl;

 return 0 ;

}