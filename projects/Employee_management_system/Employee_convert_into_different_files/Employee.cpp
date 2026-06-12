#include "Employee.h"
#include<iostream>

Employee::Employee(int employeeId, const std::string& name ,int 
            age , ll salary ) 
            
            :
            
            employeeId(employeeId) , name(name) , age(age) , salary(salary){}

        
void Employee::showDetails() const {

         std:: cout << "ID : " << employeeId << std:: endl;
         std:: cout << "Name : " << name << std:: endl;
         std:: cout << "Age : " << age << std:: endl;
         std:: cout << "Salary : " << salary << std:: endl;

}            


            int Employee::getEmployeeId() const {

                return employeeId;

            }



            const std::string& Employee::getName() const {

                    return name;

                }


                int Employee::getAge() const {
                        
                    return age;

                }


                ll Employee::getSalary() const {

                        return salary;

                }


                void Employee::setAge(int age) {

                    if(age > 0) {

                        this->age = age;

                    }

                }


                void Employee::setName( const std::string& name) {

                            this->name = name;

                }


                void Employee::setSalary(ll salary) {

                        if(salary > 0) {

                            this->salary = salary;

                        }

                }
            