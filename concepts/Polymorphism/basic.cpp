#include<iostream>

using namespace std;

class Student {
  
    public :

            void eat () {
              
                 cout << "hello i am student and i eat vegetables .."<< endl;
            
            }

};


class Teacher {

  public :

        void eat () {

             cout << "hello i am teacher and i eat non-veg ..." << endl;
        }

};

int main () {
  
    Student s;
    s.eat();
    Teacher t;
    t.eat();

    return 0 ;
     
}