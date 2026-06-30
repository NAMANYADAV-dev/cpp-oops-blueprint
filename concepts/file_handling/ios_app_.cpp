#include<iostream>
#include<fstream>

int main () {

        std::ofstream file ("record.txt" , std::ios::app);

        file << "SHIVAM\n" ;

        file.close();

        return 0 ; 
}