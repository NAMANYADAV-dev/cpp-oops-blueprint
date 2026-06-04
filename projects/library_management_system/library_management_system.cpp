#include<iostream>
#include<string>
#include<cctype>
using ll = long long ;

class LibraryItem  {

    private:

            std:: string bookId ;


    protected:

            std::string bookName;
            std::string authorName;
            std::string category;
            ll availableCopies;

     public:


        LibraryItem( std::string bookId , std:: string bookN , std:: string authorname , std:: string category , ll availableCopies) {

                bool isBookId = true;

                for(int i = 0 ; i < bookId.size() ; i++ ) {

                        char check = bookId[i];

                        if(!std::isdigit(check)) {

                                isBookId =false;
                                break;

                        }


                }

                if(isBookId && !bookId.empty()) {

                        this->bookId = bookId;
                }else {


                     this->bookId = "";

                     std:: cout << "Write Only Number In Book Id ...\n";

                }


                if(!bookN.empty()) {

                        this->bookName = bookN;
                }else {


                     this->bookName = "";

                     std:: cout << "Write Only Alphabets In Book Name ...\n";

                }




                  bool isAuthorName = true;

                for(int i = 0 ; i < authorname.size() ; i++ ) {

                        char check = authorname[i];

                        if(!std::isalpha(check) && !isspace(check)) {

                                isAuthorName =false;
                                break;

                        }


                }

                if(isAuthorName && !authorname.empty()) {

                        this->authorName = authorname;
                }else {


                     this->authorName = "";

                     std:: cout << "Write Only Alphabets In Author Name ...\n";

                }




                  bool isCategory = true;

                for(int i = 0 ; i < category.size() ; i++ ) {

                        char check = category[i];

                        if(!std::isalpha(check) && !isspace(check)) {

                                isCategory =false;
                                break;

                        }


                }

                if(isCategory && !category.empty()) {

                        this->category = category;
                }else {


                     this->category = "";

                     std:: cout << "Write Only Alphabets In category Name ...\n";

                }


                if(availableCopies >= 0) {

                    this->availableCopies = availableCopies;    
                    
                }else {

                      this->availableCopies = 0 ;


                }

        }
     

        virtual void printBookDetail () const {


            std:: cout << "Book Name --> " << bookName << std::endl;
            std:: cout << "Athor Name --> " << authorName << std::endl;
            std:: cout << "Category Name --> " << category<< std::endl;
            std:: cout << "Copies  --> " << availableCopies << std::endl;

        }

        virtual void displayBookDetail() = 0 ;


        std::string getBookId () const{

            return bookId;

        }

        std::string getBookName() const {

            return bookName;

        }

        virtual ~LibraryItem () {}


};

int main () {


}