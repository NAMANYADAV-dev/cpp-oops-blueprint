#include "Developer.h"
#include <iostream>

        Developer::Developer(
            int employeeId,
            const std::string& name,
            int age,
            ll salary,
            const std::string& programmingLanguage,
            int experience
        )
        :
        Employee(
            employeeId,
            name,
            age,
            salary
        ),
        programmingLanguage(programmingLanguage),
        experience(experience)
        {
        }

        const std::string& Developer::getProgrammingLanguage() const {

                    return programmingLanguage;

        }


        int Developer::getExprience() const {

                return experience;

        }


        void Developer::print() const {

             showDetails();

             std::cout << "Programming Language : " << getProgrammingLanguage() << std::endl;
             std::cout << "Exprience : " << getExprience() << std::endl;

        }

