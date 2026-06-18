#include<iostream>

class Students{

    public:
            std::string name = "naman";

};

int main  () {
//     Students s ;
//     Students *ptr = &s;
//    std:: cout <<  ptr->name << std::endl;
        Students *s = new Students() ;

        std:: cout << s->name << std::endl;

        delete s ;

        return 0 ;

}