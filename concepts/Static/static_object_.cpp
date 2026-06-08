#include<iostream>

class Test {

    public :

         Test() {

            std:: cout << "Constructor call ...\n";

         }

         ~Test() {

             std:: cout << "Destructor call ...\n";

         }



};


void fun () {

    static Test obj ; 

    std:: cout << "Inside object function ...\n";



}


int main (){

fun();
fun();
fun();
fun();

return 0 ;

}