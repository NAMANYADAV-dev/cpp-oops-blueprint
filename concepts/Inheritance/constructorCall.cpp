#include<iostream>
using namespace std;

class Parent {

   public :

            Parent () {

                cout << "Parent constructor call\n";
            }

            ~Parent () {
                cout << "Parent destructor finish\n";
            }
            
        };
        
        class Child : public Parent {
            
            public :
            
            Child () {
                
                cout << "Child constructor call\n";
                
            }
            
            ~Child () {
                
                cout << "Parent destructor finish\n";

            }

};

int main ()  {

  Child c;

}