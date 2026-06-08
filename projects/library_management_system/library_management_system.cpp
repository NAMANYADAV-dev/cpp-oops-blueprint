#include<iostream>
#include<vector>
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

        virtual void displayBookDetail() const  = 0 ;


        const std::string& getBookId () const{

            return bookId;

        }

       const  std::string& getBookName() const {

            return bookName;

        }

        ll getAvailableCopies() const {

                return availableCopies ;

        }


        void setAvailablesCopies(ll copies) {

                if(copies >= 0) {

                        availableCopies = copies;

                }else{

                        availableCopies = 0 ;

                }

        }

        virtual ~LibraryItem () {}


};

class Book : public LibraryItem {

        public :

           Book(std:: string bookId , std::string bookName , std::string authorName , std:: string category , ll availableCopies) : LibraryItem(bookId , bookName , authorName , category , availableCopies ) {

                  std:: cout << "Book details is loaded successfully ...\n";

           }


         void displayBookDetail() const  override {

        std::cout << "\n===== BOOK DETAILS =====\n";

                printBookDetail();

         }

};


class Member {


        private:

                ll memberId;
                std::string memberName;
                std::string emailMember;

        public :

                Member(ll memberId , std::string memberName , std::string emailMember ) : memberId(memberId > 0 ? memberId : 0 )  , memberName(memberName) , emailMember (emailMember)  {

                        std:: cout << "Member created successfully ...\n";

                }



                void displayMemberDetail()  const {


                        std:: cout << "Member ID : " << memberId << std::endl;
                        std:: cout << "Member Name : " << memberName << std::endl;
                        std:: cout << "Member Email: " << emailMember << std::endl;


                }

                ll getMemberId() const {

                        return memberId;

                }



                std::string getMemberName() const {

                        return memberName;

                }

};


class IssuedBook {


        private :

                std:: string bookId;

                ll memberId;


        
        public:
        
        
                IssuedBook(const std:: string& bookId , ll memberId) : bookId(bookId) , memberId(memberId) {} 

              const   std:: string&  getBookId() const {

                        return bookId;

                }

                ll getMemberId () const {


                        return memberId ;
                  
                }        

};


class Library{


        private :

              std::vector<Book> books;
              std::vector<Member>members;
              std::vector<IssuedBook>issuedBooks;


        public:


                void addBook(const Book& book){

                        books.push_back(book);

                        std:: cout << "Book added successfully...\n";

                }



                void addMember(const Member& memeber){

                        members.push_back(memeber);

                        std:: cout << "Member added successfully...\n";

                }


                void displayAllBooks()  const {

                        if(books.empty()) {

                                std:: cout << "No book available ...\n";

                                return ;


                        }

                        for( const auto& book : books) {

                                book.displayBookDetail();
                                std:: cout << '\n';

                        }


                }


                void displayAllMembers()  const {

                        if(members.empty()) {

                                std:: cout << "No Member available...\n";

                        }

                        for( const auto&member : members) {

                                member.displayMemberDetail();

                                std:: cout << '\n';

                        }


                }


                void searchBookById(const std::string& id) const  {

                        for(const auto& book : books) {

                              if(book.getBookId() == id) {

                                 std:: cout << "Book Found \n";
                                 book.displayBookDetail();
                                 return;
                              }  

                        }

                        std:: cout << "Book Not Found...\n";

                }



                void searchMemberById (const ll& id) const  {

                        for( const auto& member : members) {

                             if(member.getMemberId() == id ) {

                                 std:: cout << "Member Found ...\n";
                                 member.displayMemberDetail();
                                return ;        
                                 

                             }

                        }

                        std:: cout << "Member Not Found...\n";

                }


                void addIssueBook(const IssuedBook& issueBook) {

                        issuedBooks.push_back(issueBook);

                        std:: cout << "IssueBook successfully Added ...\n";

                }


                void displayIssueBook() const {

                        if(issuedBooks.empty()){

                                std:: cout << "No Issued Books Found...\n";
                                return ;

                        }

                        for(const auto& issueBook : issuedBooks) {

                                std:: cout << issueBook.getBookId() << " :  " << issueBook.getMemberId() << std::endl;


                        }
                

                }


};







int main () {


}