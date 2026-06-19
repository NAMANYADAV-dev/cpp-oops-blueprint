#include<iostream>


class Buffer{

    private:

        int *data;

    public:

            Buffer(int size) {

                 data = new int[size];

            }

            Buffer(Buffer&& other) {

                    data = other.data;

                    other.data = nullptr;

            }

};


int main () {

        Buffer b1(1000);

        Buffer b2 = std::move(b1);

        

}