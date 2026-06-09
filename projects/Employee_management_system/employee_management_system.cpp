#include<iostream>
#include<string>
using ll = long long ; 

class Employee{


        protected:

                int employeeId ; 

                std:: string name;

                int age ; 

                ll salary;

    
    

        public : 


                Employee( int employeeId , const std:: string& name , int age , ll salary ) : employeeId(employeeId > 0  ? employeeId : 0 ) , name(name) , age ( age > 0 ? age : 0) , salary (salary > 0 ? salary  : 0 ) { } 


                virtual void print () const = 0 ; 


                int getEmployeeId () const {
                    
                        return employeeId;

                }

                const std:: string& getName () const {
                    
                        return name;

                }

                
                int  getAge () const {

                      return age ;

                }


                ll getSalary () const {

                        return salary; 

                }


                void setName(const std::string& name) {

                    if(!name.empty()) {

                        this->name = name;

                    }


                }

                void setSalary( ll salary) {

                     if(salary > 0 ) {

                            this->salary = salary ;

                     }else {

                        std:: cout << "Invalid salary ...\n";

                     }

                }


                void showDetails() const {


                    std:: cout <<  "ID : " << getEmployeeId() << std :: endl;
                    std:: cout <<  "Name : " << getName() << std :: endl;
                    std:: cout <<  "Age : " << getAge() << std :: endl;
                    std:: cout <<  "Salary : " << getSalary() << std :: endl;



                }



                virtual ~Employee ()  = default ; 


};



class Manager : public Employee {


     private : 


            std:: string departementName ;

            int teamSize ;




     public :


            Manager( int employeeId , const std:: string& name , int age , ll salary ,const std:: string& departementName , int teamsize ) :  Employee ( employeeId , name , age , salary ) , departementName ( departementName ) , teamSize( teamsize > 0 ? teamsize : 0 ) { } 
            
            

             const std:: string& getDepartementName() const {

                        return departementName;

             }


             int getTeamSize() const {


                return teamSize ; 

             }

            void print() const override  {

                 std:: cout << "======== MANAGER =======\n" ; 

                 showDetails(); 


                 std:: cout << "Departement :  " << getDepartementName() << std:: endl;
                 std:: cout << "TeamSize :  " << getTeamSize() << std:: endl;

            }
};


class Developer : public Employee {


    private :


            std :: string programmingLanguage;

            int experience;


    
    public : 


            Developer(int employeeId , const std:: string& name , int age , ll salary ,  const std:: string& programmingLanguage , int experience) : Employee (employeeId , name ,age , salary ) , programmingLanguage(programmingLanguage) , experience(experience > 0 ? experience : 0 ) {}
            
            
            const std:: string& getProgrammingLanguage() const  {

                return programmingLanguage;

            }

            int getExperience() const {

                return experience;

            }


            void print() const override  {

                 std:: cout << "======== DEVELOPER =======\n" ; 

                 showDetails(); 


                 std:: cout << "Programming Language :  " << getProgrammingLanguage() << std:: endl;
                 std:: cout << "Experience :  " << getExperience() << std:: endl;

            }


};


int main () {



}