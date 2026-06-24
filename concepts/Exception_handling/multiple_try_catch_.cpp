#include<iostream>

int main () {

        try {

                throw 3.34;


        } 

        catch(int x) {

                std::cout << "Integer Exception" << std::endl;

        }

        catch (char ch) {

                std::cout << "Character Exception " << std::endl;

        }

        catch (double d) {

                std::cout << "Double Exception " << std::endl;

        }


        return 0  ; 

}