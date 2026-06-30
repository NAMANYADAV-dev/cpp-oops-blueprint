#include<iostream>
#include<fstream>

int main () {

        std::ofstream file("record.txt", std::ios::trunc);

        file << "RAHUL";

        file.close();

        return 0 ;

}