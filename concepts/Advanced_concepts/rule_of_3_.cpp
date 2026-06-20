#include<iostream>

class Students{

    private:

            int *marks;

    
    public:

            Students(int n ) {

                marks = new int(n);

            }

            ~Students() {

                 delete marks;

            }

            Students (const Students& other) {

                     marks = new int(*other.marks);

            }


            Students& operator=(const Students& other) {

                    if(this != &other) {


                        delete marks;

                        marks = new int(*other.marks);

                    }

                    return *this;

                }

                int getMarks () {

                    return *marks;

                }

};

int main () {

    Students s1(100);
    
    std:: cout << s1.getMarks() << std::endl;
    
    Students s2(s1);
    
    std:: cout << s2.getMarks() << std::endl;
    
    Students s3(599);
    
    std:: cout << s3.getMarks() << std::endl;
    
    s3 = s2;
    
    std:: cout << s3.getMarks() << std::endl;
    std:: cout << s2.getMarks() << std::endl;


    
    return 0 ;

}