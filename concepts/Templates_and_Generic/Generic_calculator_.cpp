#include<iostream>

template<typename T>
class Calculator {

    private:

            T a;
            T b;

    
    public :

         Calculator( T x , T y) {

                    this->a = x;
                    this->b = y ;

         }


            T add() {

                return a + b ;
            }


            ~Calculator() {

                std::cout << "STOP\n";

            }


};


int main () {

    Calculator<int>c1(19 , 39 );
    
    std::cout<< c1.add() << std::endl;
    
    Calculator<double>c2(19.35 , 39.35 );

    return 0;

}