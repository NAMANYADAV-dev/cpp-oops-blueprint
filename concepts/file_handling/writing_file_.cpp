#include<iostream>
#include<fstream>

int main () {

        std::ofstream file("Village.txt");

        file << "Naman = 18\n";
        file << "Shivam = 19 ";

        file.close();

        return 0 ; 

}