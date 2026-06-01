#include<iostream>

using namespace std;

class Animal {

    protected:

 
            int age = 0 ; 

  public :

        Animal (int age) {
            this->age = age;
              
        }


        ~Animal () {

            cout<<" Animal age is ended\n";
            
        }
        
};


class Dog : public Animal {
    
  public:

        Dog (int age) : Animal (age) {
             cout <<"Dog Age is : " << age << " \n" ;
        } 
         
        ~Dog() {
             
             cout<<" Dog age is ended\n";
        }
};

int main () {

 Dog d(29);
 return 0;
}