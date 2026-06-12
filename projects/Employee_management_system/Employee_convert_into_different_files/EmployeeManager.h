#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include<vector>
#include<iostream>
#include<memory>
#include "Employee.h"

class EmployeeManager{

    private:

    std::vector<std::unique_ptr<Employee>> employees;

    static int totalEmployees ; 

public:

    void addEmployee(
        std::unique_ptr<Employee> emp
    );


    void searchEmployeeByName (const std::string& name) const ; 



    void displayAllEmployee() const;
};

#endif