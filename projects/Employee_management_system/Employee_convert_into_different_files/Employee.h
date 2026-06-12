#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<string>

using ll = long long ; 

class Employee{
        
        protected:
        
                    int employeeId ; 
                    
                    std:: string name;
                    
                    int age ; 
                    
                    ll salary;
        
        
        
                     void showDetails() const ; 

        public : 


                Employee( int employeeId , const std:: string& name , int age , ll salary );

                virtual void print () const = 0 ; 

                int getEmployeeId ()  const  ;

                const std:: string& getName ()  const ;
                
                int  getAge () const ;
                


                ll getSalary () const  ;


                void setName(const std::string& name) ;

                void setSalary( ll salary) ;


                void setAge (int age) ;

                virtual ~Employee ()  = default ; 


};


#endif