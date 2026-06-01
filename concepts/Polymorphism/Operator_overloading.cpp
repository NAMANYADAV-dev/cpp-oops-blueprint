#include<iostream>
using namespace std;
class Complex{
    public:
       int real , imag;

       Complex(int real , int imag){
            this->real = real;
            this->imag = imag;
       }

       Complex operator+(Complex obj){
         return Complex( real + obj.real , imag + obj.imag);
       }

       void display(){
         cout<<real<<" + "<<imag<<" i\n";
       }
};
int main(){
   Complex c1(2,1), c2(4,5);
   Complex c3 = c1 + c2;
   c1.display();
   return 0 ;
}