#include<iostream>

class Animal {

    private :

        int age ;

        public :

                void show () {

                        std:: cout << "What's your animal name ...\n";

                }


                void setAge(int animalAge) {

                        this->age = animalAge;

                }

                int getAge() const {

                    return age;

                }

};

int main () {


    Animal a;
    a.setAge(50);
    a.getAge();
    a.show();
    return 0 ;

}