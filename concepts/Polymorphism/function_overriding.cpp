#include<iostream>

using namespace std;


class Animal {

        public :


                virtual void show()= 0 ;

                virtual ~Animal () { cout << "hello i am animal " << endl; };


};

class Dog : public Animal {


    public :

            void show () override final {

                  cout << "Dog spark ..." << endl;

            }

            ~Dog ()  {

                cout << "ended .."<< endl;

            }

};


int main () {

 Animal *s;

 Dog d ;

 s = &d;

 s->show();

 return 0 ;


}