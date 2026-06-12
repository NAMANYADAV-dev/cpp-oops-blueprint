#include "EmployeeManager.h"

int EmployeeManager::totalEmployees = 0 ;

void EmployeeManager::addEmployee(std::unique_ptr<Employee>emp) {

        employees.push_back(std::move(emp));

        totalEmployees++;


}

void EmployeeManager::searchEmployeeByName(const std::string& name) const {

                if(employees.empty()){

                    std::cout << "No employee...\n";

                    return;

                }

                bool found = false;

                for(const auto& emp : employees) {

                    if(emp!= nullptr && emp->getName() == name) {

                          emp->print();

                          found = true;

                          break;

                    }

                }

                if(!found) {

                    std:: cout << "No employee Found\n";

                }

            }
        
    void EmployeeManager::displayAllEmployee() const {

               if(employees.empty()) {

                    std::cout << "No employee...\n";

               }


               for(const auto& employee : employees) {

                            employee->print(); 

               }

    }



