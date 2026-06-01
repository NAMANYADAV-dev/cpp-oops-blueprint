#include<iostream>
using namespace std;
using ll = long long ;
class ATM{
     public :
          virtual void pay() = 0;
          virtual void addMoney(ll amt) = 0;
          virtual ~ATM() {};
};


class Account : public ATM  {
  
    protected :
       ll balance  = 0 ; 
     

    

};
class deposit : public Account {
   public :
         
      deposit (ll amount ){
         if(amount > 0){
            balance+=amount;
            
         }
      }

      void addMoney(ll amt) override {
            if(amt > 0 ){
               balance +=amt;
            }
      }


      void pay() override {
         cout<<"Current Balance...\n"<<balance<<endl;
      }

};
int main(){
   ATM *a;
   a = new deposit(5000);
   a->pay();
  

   a->addMoney(10000);
   a->pay();
    delete a;
    a= nullptr;
   return 0;
}