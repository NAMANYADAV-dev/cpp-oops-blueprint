#include "Manager.h"
#include<iostream>

    Manager::Manager( int employeeId,

        const std::string& name,

        int age,

        ll salary,

        const std::string& departmentName,

        int teamSize
    )

    :

    Employee(

        employeeId,

        name,

        age,

        salary

    ), departmentName(departmentName) , 

    teamSize(teamSize)
    {

    }


    const std::string&Manager::getDepartment() const {

            return departmentName;

    }

    int Manager::getTeamSize() const {

            return teamSize ;

    }


    void Manager::print() const {

          showDetails() ;

          std:: cout << "Department : " << getDepartment() << std:: endl;
          std:: cout << "TeamSize : " <<  getTeamSize() << std:: endl;

    }