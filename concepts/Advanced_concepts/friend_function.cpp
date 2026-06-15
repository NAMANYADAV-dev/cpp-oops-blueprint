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


                friend void show(Students& s , Teacher& t) ;



};



class Teacher {

    private :

            int number ;

    
    public :


            Teacher(int n) {

                if(n > 0) {

                    this->number = n ;

                }else{

                    std:: cout << "Invalid Number...\n";

                }

            }

             friend void show(Students& s  , Teacher& t);

};

        void show(Students& s , Teacher& t ) {

            std:: cout << s.marks << " , " << t.number <<  std::endl;

        }


int main () {


        Students s1(59);

        Teacher t2(12423);

        show(s1 , t2);

        return 0 ; 

}