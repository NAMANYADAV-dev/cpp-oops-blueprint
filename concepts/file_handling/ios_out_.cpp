#include<iostream>
#include<fstream>

int main () {

        std::ofstream file ("village.txt" , std::ios::out);

        file << "Naman" ;

        file.close();

        return 0 ; 
}