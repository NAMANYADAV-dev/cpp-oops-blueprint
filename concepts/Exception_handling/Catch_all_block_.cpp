#include<iostream>

int main () {

        try {

                throw "Error";

        }
        catch(...) {


            std::cout << "Unknow Exception Caught" << std::endl;

        }

}