#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.h"


class Developer : public Employee {

private:

    std::string programmingLanguage;
    int experience;

public:

    Developer(
        int employeeId,
        const std::string& name,
        int age,
        ll salary,
        const std::string& programmingLanguage,
        int experience
    );

    const std:: string& getProgrammingLanguage() const ;

    int getExprience() const ;

    void print() const override;
    
};




#endif