#include<iostream>

using namespace std;

class School {

    public :

    School () {
         cout << "which types is this school..." << endl;
    }
    
    
    ~ School () {
         cout << "which types is this school... Destructor call " << endl;
    }

};


class Teacher : virtual public School {

    public :

         Teacher () {

                    cout << "How many teaher in here this school bro tell me " << endl;
         }


         ~ Teacher () {
 
                    cout << "How many teaher in here this school bro tell me  destructor call " << endl;
         }


        };
        

class Students : virtual public School {

        public :

          Students () {
             cout << "how much student in here this school bro tell me ..." << endl;
          }


          ~Students () {
             cout << "how much student in here this school bro tell me ... destructor call " << endl;
          }

};

class TeachingAssistant : public Teacher , public Students {

           public :

            TeachingAssistant () {

                  cout << "here a lot of teaching assistant bro in this school ..." << endl;
            }


            ~TeachingAssistant () {

                  cout << "here a lot of teaching assistant bro in this school ... Destructor call " << endl;
            }
};


int main () {
 

   TeachingAssistant ta;


    return 0 ;
     
}