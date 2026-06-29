#include<iostream>
#include<fstream>

int main () {

        std::ifstream file;
        file.open("village.txt");

        std::string name;
        std::string age;

        char ch ;
        file.get(ch);
        
        getline(file , name);
        getline(file , age);
        
        file >> name >> age ;
        
        std::cout << name << std::endl << age << std::endl;
        std:: cout << ch << std::endl;
        return 0 ; 

}