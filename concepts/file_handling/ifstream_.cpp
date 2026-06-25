#include<iostream>
#include<fstream>

int main () {

        std::ifstream file("Student.txt");

        std::string text;

        getline(file,text);

        std::cout << text << std::endl;

        file.close();
        

        return 0 ; 

}