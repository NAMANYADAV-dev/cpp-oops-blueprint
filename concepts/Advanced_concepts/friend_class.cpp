#include<iostream>

class Teacher;

class Students{

        private:

                int marks ;


        public :

                Students(int m) {

                        if(m >= 0) {

                             this->marks = m ; 

                        }else{

                             std::cout << "Invalid marks\n";

                        }

                }


               friend class Teacher;     



};



class Teacher {

    public:



            void show(Students& s) {

                    std:: cout << s.marks << std::endl;

            }    

          

};




int main () {


        Students s1(59);

        Teacher t2;

        t2.show(s1);

        return 0 ; 

}