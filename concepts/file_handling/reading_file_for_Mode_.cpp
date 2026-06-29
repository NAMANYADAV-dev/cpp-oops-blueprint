#include<iostream>
#include<fstream>

int main () {

        std::ifstream file("village.txt" , std::ios::in);

        std::string name;

        std:: string age ; 

        getline(file , name);
        getline(file , age);

        file >> name;

        file >> age ;

        std:: cout << name <<  std:: endl << age << std::endl;

        return 0 ; 
}