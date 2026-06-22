#include<iostream>


class Buffer{


    private:

        int *data;
        int size;

    
    public:

        Buffer(int size ) {

            data = new int [size];
            this->size = size;
            std::cout << "Constructor\n";
            
        }
        
        ~Buffer() {

            delete [] data;
            std::cout << "Destructor\n";

        }


        Buffer(const Buffer& other) {

                size = other.size;

                data = new int [size];

                for(int i = 0 ; i < size ; i++) {

                        data[i] = other.data[i] ;

                }

                std:: cout << "Copy Constructor\n";

        }


        Buffer& operator=(const Buffer& other) {

                if(this != &other) {

                    delete[] data;

                    size = other.size;

                    data = new int [size];

                    for(int i = 0 ; i < size ; i++) {

                           data[i] = other.data[i] ; 

                    }

                }

                    return *this;
        }



        Buffer(Buffer&& other) noexcept {

                data = other.data;

                size = other.size;

                other.data = nullptr;
                other.size = 0 ;

                std:: cout << "Move Constructor\n";
        }



        Buffer& operator=(Buffer&& other) noexcept {

                if(this != &other) {

                        delete[] data;

                        data = other.data;

                        size = other.size;

                        other.data = nullptr;

                        other.size = 0 ; 

                }

                return *this;

        }

};


int main () {

    Buffer b1(5);

    Buffer b2 = b1;

    Buffer b3(10);

    b3 = b1;

    Buffer b4 = std::move(b1);

    b2 = std::move(b3);

    return 0 ;


}