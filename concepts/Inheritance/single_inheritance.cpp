#include<iostream>
using namespace std;
 
class Animal {

    protected :
       int x = 20 ;

        void eat () {

             cout << "Animal eat not food he eat our food \n";  
        }
 };


class Dog  {

    public :

       void Dogfood ()  
          
        {

         cout << "Dog eat biscits\n";

       }

};


class Tiger : public Animal , public Dog {
        
     public:

            void tigerfood() {

                eat();

                cout << x << endl;

                cout << "Tiger eat non-veg food \n";

            }

};

int main () {

    Dog g;


    g.Dogfood();


    Tiger t;     


    t.tigerfood();


    return 0;

}