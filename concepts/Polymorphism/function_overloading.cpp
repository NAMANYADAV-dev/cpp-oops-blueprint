#include<iostream>
using namespace std;

class Calculator {

    public:

    void add(int a , int b ) {

        cout << a + b   << endl;
    }

    void add(int a , int b , int c) {

        cout << a + b + c << endl;
    }

    void add(double a , double b) {

         cout << a + b << endl;
    }
};

int main() {

   Calculator c;
   c.add(10 ,19);
   c.add(10 ,19 , 20);
   c.add(10.34,19.66);
   return 0 ;
}