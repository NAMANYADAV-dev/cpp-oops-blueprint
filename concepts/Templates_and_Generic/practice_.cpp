#include<iostream>

template<typename T1 ,typename T2>

class Employee{

    private:

            T1 id;
            T2 name;

    
    public :

            Employee(T1 id , T2 name) {

                    this->id = id;
                    this->name = name;

            }

            void displayInformation() {

                 std:: cout << id << " ,  " << name << std::endl;

            }


};


int main () {

    Employee<int , std::string> e1(19 , "Naman");

    e1.displayInformation();

    return 0 ;

}