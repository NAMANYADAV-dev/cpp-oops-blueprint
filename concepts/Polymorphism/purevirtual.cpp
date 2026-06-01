#include<iostream> 
#include<vector>
using namespace std;
class Payment{
    public:
      virtual void pay() = 0 ;
};

class UPI : public Payment{
    public:
        void pay() override {
             cout<<"Pay using UPI \n";
        }
};

class Card : public Payment{
     public :
        void pay() override{
            cout<<"Pay using Card \n";
        }
};


class Crypto : public Payment {
    public :
        void pay() override {
            cout<<"Pay using Crypto\n";
        }
};
int main(){
   Payment *p;
   UPI u;
   p = &u;
   p->pay();
   Card c;
   p = &c;
   p->pay();
   Crypto cr;
   p = &cr;
   p->pay();
   return 0;
} 