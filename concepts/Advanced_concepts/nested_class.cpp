#include<iostream>

class Outer {

    public:


    class Inner{


            public:

                void show() {

                    std::cout << "Hello world\n";

                }


    };


};


int main () {

    Outer::Inner i1;
    i1.show();

    return 0 ;

}