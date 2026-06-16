#include<iostream>

class Students{

    private:

            int marks ;

    public:

          explicit  Students(int n) : marks(n){}

          friend void show(Students& s);

};

        void show(Students& s) {

            std:: cout << s.marks << std::endl;

        }

int main () {

        Students s(299);
        show(s); 

        return 0 ;

}