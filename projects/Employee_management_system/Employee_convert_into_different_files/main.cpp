#include"Manager.h"
#include"developer.h"
#include"EmployeeManager.h"

int main () {


    EmployeeManager manager;

    manager.addEmployee(std::make_unique<Manager>(
           101,
            "Naman",
            25,
            100000,
            "HR",
            10
    ));

    manager.displayAllEmployee();


    return 0 ; 


}