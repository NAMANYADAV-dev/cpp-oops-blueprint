#include<iostream>

class Database {

        private:

                static Database* instance ;


                Database() {

                        std:: cout << "Database Connected\n";

                }


        public: 


                static Database* getInstance() {

                        if(instance == nullptr) {

                                instance = new Database();

                        }

                            return instance;
                }


};

Database* Database::instance = nullptr;


int main () {

        Database * bd1 = Database::getInstance();
        Database * bd2 = Database::getInstance();
        Database * bd3 = Database::getInstance();

        std:: cout << bd1 << std::endl;
        std:: cout << bd2 << std::endl;
        std:: cout << bd3 << std::endl;


        return 0 ; 
}