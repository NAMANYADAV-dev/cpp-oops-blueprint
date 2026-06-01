#include<iostream>
using namespace std;
class Calculator{

    private :
      int interValue  = 0 ;
      double decimalValue = 0;
      long long bigValue = 0;
    public :
        Calculator(int a , int b){
            this->interValue = a+b;
            add(interValue);
        }


        Calculator(double a ,double b){
             this->decimalValue = a+b;
             add(decimalValue);
        }

        Calculator(int a , int b , int c){
           this->bigValue = a+b+c;
             add(bigValue); 
        }

      void  add(int interValues){
           cout<<interValues<<endl;
       }
      void  add(double decimalvalues){
           cout<<decimalvalues<<endl;
       }
      void  add(long long bigvalues){
           cout<<bigvalues<<endl;
       }

};
int main(){
 Calculator c1(12,234);
 Calculator c2(12.352,23.3254);
 Calculator c3(12,234,235);
    return 0;
}
