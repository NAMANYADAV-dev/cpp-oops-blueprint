#include<iostream>

class Buffer{
    private:
        int *data;

    public:
            Buffer(int size) {

                 data = new int[size];

            }

            ~Buffer() {

                delete[] data;
            }

            Buffer& operator=(Buffer&& other) {

                    if(this != &other) {

                        delete[] data;

                        data = other.data;

                        other.data = nullptr;
                    }
                        return *this;
            }
};


int main () {

        Buffer b1(1000);

        Buffer b2(199);


        b2 = std::move(b1);


        return 0 ; 

        

}