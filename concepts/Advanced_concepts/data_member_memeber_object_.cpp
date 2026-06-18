#include<iostream>
using namespace std;

class Engine {
public:
    void start() {
        cout << "Engine Started\n";
    }
};

class Car {
public:
    Engine eng; // Member Object
};

int main() {

    Car c;

    c.eng.start();

    return 0 ;

}