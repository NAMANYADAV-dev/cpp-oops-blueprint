#include<iostream>

using namespace std;


class Animal {

  public :

           virtual void type() {

                 cout << "Guess the type of animal \n";

            }

};

class Dog : public Animal {

   public :
             
            void type() override {

                cout << "This is Dog Animal\n";

            }

};

int main () {
 
   Animal *a;
   
   Dog d; 

   a = &d;

   a->type();

    return 0 ;

}