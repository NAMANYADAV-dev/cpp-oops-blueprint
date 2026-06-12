#include<iostream>
#include<string>
#include<vector>
#include<memory>
using ll = long long ; 

class Employee{




        
        
        protected:
        
        int employeeId ; 
        
        std:: string name;
        
        int age ; 
        
        ll salary;
        
        
        
                                void showDetails() const {


                                std:: cout <<  "ID : " << getEmployeeId() << std :: endl;
                                std:: cout <<  "Name : " << getName() << std :: endl;
                                std:: cout <<  "Age : " << getAge() << std :: endl;
                                std:: cout <<  "Salary : " << getSalary() << std :: endl;



                                }
    

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


                void setAge (int age) {

                        if(age > 0) {

                                this->age = age;

                        }else {

                                std:: cout << "Invalid Age...\n";

                        }

                }

                virtual ~Employee ()  = default ; 


};



class Manager : public Employee {


     private : 


            std:: string departmentName ;

            int teamSize ;




     public :


            Manager( int employeeId , const std:: string& name , int age , ll salary ,const std:: string& departmentName , int teamsize ) :  Employee ( employeeId , name , age , salary ) , departmentName ( departmentName ) , teamSize( teamsize > 0 ? teamsize : 0 ) { } 
            
            

             const std:: string& getDepartementName() const {

                        return departmentName;

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


class EmployeeManager {


        private :

                std::vector<std::unique_ptr<Employee>>employees;

                static int totalEmployees;


        public :

               static int getTotalEmployee()  {

                        return totalEmployees;

                }
            


                void addEmployee(std::unique_ptr<Employee>emp) {

                        employees.push_back(std::move(emp));
                        totalEmployees++;

                }



                void searchEmployeeById( int id) const {

                        bool found = false;

                        for( const auto& emp : employees) {

                                if(emp->getEmployeeId() == id) {

                                emp->print();
                                found = true;

                                break;


                                }

                        }

                        if( !found) {
        
                            std:: cout << "Employee Not Found...\n" ; 
        
                        }
                        
                }



                void removeEmployee();

                
                void displayAllEmployee() const {

                        if(employees.empty()){

                                std:: cout << "No empolyee...\n";
                                return ;

                        }


                       
                        for(const auto& employee : employees) {

                                employee->print();


                        }

                }



           


};

int EmployeeManager::totalEmployees = 0 ; 

int main () {

       EmployeeManager e1;



       e1.addEmployee(
        std::make_unique<Manager>(101 ,"Naman" , 30 , 100000 , "HR" , 10 )
       );
       
       e1.addEmployee(
        std::make_unique<Manager>(102 ,"Shivam" , 30 , 100000 , "HR" , 10 )
       );


       
       
       
       e1.addEmployee(
               std::make_unique<Developer>(103 ,"Vivek" , 30 , 100000 , "HR" , 10 )
        );
        
        
        e1.addEmployee(
                std::make_unique<Developer>(104 ,"Rahul" , 30 , 100000 , "HR" , 10 )
        );


        e1.displayAllEmployee();
        
        
       std:: cout << " Total Employee : " << EmployeeManager::getTotalEmployee()<< std:: endl; 

       return 0 ; 

}