#include<iostream>
#include<fstream>

int main () {

        std:: fstream file;

        file.open("students.txt" , std::ios::in | std::ios::out);

        file << "WHAT IS YOUR NAME ..."; 

        std::string text;

        getline(file , text) ;

        std:: cout<< text << std::endl;

        return 0 ; 

}