#include<iostream>

class Book {

private:

    std::string title;

public:

    static int totalBooks;

    Book(const std::string& title) {

        this->title = title;

        totalBooks++;
    }

    static void showBooks() {

        std::cout << "Total Books = "
             << totalBooks << std::endl;
    }
};

int Book::totalBooks = 0;


int main () {

    Book b("C++");
    Book b1("C");
    Book b2("js");
    
    Book::showBooks();

    return 0 ;
}