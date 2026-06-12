#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"


class Manager : public Employee {

private:

    std::string departmentName;
    int teamSize;

public:

    Manager(
        int employeeId,
        const std::string& name,
        int age,
        ll salary,
        const std::string& departmentName,
        int teamSize
    );

    const std::string& getDepartment() const ;

    int getTeamSize() const ;

    void print() const override;
};



#endif