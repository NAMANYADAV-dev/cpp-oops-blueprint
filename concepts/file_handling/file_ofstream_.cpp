#include<iostream>
#include<fstream>

int main () {

        std::ofstream file("student.txt");

        file << "Hello Naman , you are boy bro ? ";

        file.close();

        return 0; 

}