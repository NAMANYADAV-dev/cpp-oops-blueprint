#include<iostream>

template<typename T = int>

class Box {

    private:

        T data;

    public:

        Box(T d) {

            this->data = d;

        }

        void display() {

            std:: cout << data << std::endl;

        }


};

int main () {

    Box<>b1(599);
    
    b1.display();
    
    Box<double>b2(5993.346);

    b2.display();
    
    return 0 ;

}