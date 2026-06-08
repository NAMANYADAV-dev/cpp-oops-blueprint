#include<iostream>

class Add {


   static int x  ; 


    public:



        Add() {

            x++;
        }

        int getValue() const {

            return x ; 

        }

        ~Add() {

            x--;

        }


};

int Add::x = 0 ;


int main () {

    Add a;
    Add a1;
    Add a2;
    
   std::cout << a.getValue() << std::endl ; 

   return 0 ; 

}