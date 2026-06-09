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

                        std::string bookName = "";
                        std::string memberName = "";

                        for( auto& issueBook : issuedBooks) {

                               for( auto& book : books) {

                                        if(book.getBookId() == issueBook.getBookId()) {


                                                bookName = book.getBookName();


                                        }

                               }


                               for(const auto& member : members) {

                                        if(member.getMemberId() == issueBook.getMemberId()) {


                                                memberName = member.getMemberName();


                                        }

                               }

                               std::cout << "\n=====================\n";
       
                                       std::cout << "Book ID     : " << issueBook.getBookId() << '\n';
       
                                       std::cout << "Book Name   : "  << bookName  << '\n';
       
                                       std::cout << "Member ID   : " << issueBook.getMemberId()  << '\n';
       
                                       std::cout << "Member Name : " << memberName << '\n';
       
                                       std::cout << "=====================\n";
                       
                               
                        }



                }


                void issueBook(const std::string& bookId , ll memberId); 


                void returnBook(const std::string& bookId , ll memberId); 


};


void Library::issueBook(const std:: string& bookId , ll memberId) {

       Book *foundBook  = nullptr ;

        for ( auto& book : books) {

              if( book.getBookId() == bookId) {

                 foundBook  = &book;

                 break;

              }

        }

        if(foundBook == nullptr) {

                std:: cout << "Book Not exits...\n";
                return ; 

        }


        std::cout << "Available Copies... : " << foundBook->getAvailableCopies() << std:: endl;


         if(foundBook->getAvailableCopies() <= 0) {

                        std::cout << "No Copies Available...\n";
                        return;
        }


        Member *foundMember = nullptr;

        for( auto&member : members) {

                if(member.getMemberId() == memberId) {


                        foundMember = &member;
                        break;

                }

        }

        if(foundMember == nullptr) {

                std:: cout << "Member Not exits ...\n";
                return;

        }

        
        for(const auto& issue : issuedBooks) {

        if(  issue.getBookId() == bookId && issue.getMemberId() == memberId ) {

                std::cout << "Book already issued to this member...\n";
                return;
        }
}

        IssuedBook issue(bookId , memberId) ;

        issuedBooks.emplace_back(issue);

        foundBook->setAvailablesCopies(

                foundBook->getAvailableCopies() - 1 
        );


        std::cout << "Book Issued Successfully...\n";


        std::cout << "Book " << bookId  << " issued to Member " << memberId << " successfully.\n";

        std::cout << "Remaining Copies : "  << foundBook->getAvailableCopies() << std::endl;
} 



void Library::returnBook(const std::string& bookId , ll memberId) {

        size_t issueIndex = issuedBooks.size();

        for(size_t i = 0 ; i < issuedBooks.size() ; i ++)  {

             if(issuedBooks[i].getBookId() == bookId && issuedBooks[i].getMemberId() == memberId) {


                        issueIndex = i ;

                        break;


             }

        }


        if(issueIndex == issuedBooks.size()) {

                std:: cout << "Issued Record Not Found\n";
                return;

        } 


        Book *foundBook = nullptr ;


        for(auto& book : books) {

                if(book.getBookId() == bookId) {

                        foundBook = &book;

                        break;

                }

        }

        if(foundBook == nullptr) {

                std:: cout << "Book Not Found...\n";

                return ;
        }


       foundBook->setAvailablesCopies( foundBook->getAvailableCopies() + 1) ;

       issuedBooks.erase(

                issuedBooks.begin() + issueIndex 

       );

       std::cout << "Book Returned Successfully...\n";

}



int main () {

        Library l1;
        

        Book b1( "101" , "CPP" , "Bjarne" , "Programming" ,  5) ; 
        Book b2( "102" , "DSA" , "Abdul" , "Programming" ,  3) ; 

        l1.addBook(b1);
        l1.addBook(b2);


        // Member 

        Member m1(1 , "Naman" , "naman@300yadgmail.com");
        Member m2(2 , "shivam" , "shivam@3001yadgmail.com");


        l1.addMember(m1);
        l1.addMember(m2);

        std:: cout << "\n ===== ALL BOOKS =====\n";

        l1.displayAllBooks() ; 

        std:: cout << "\n ===== ALL MEMBERS =====\n";

        l1.displayAllMembers() ; 
        
        std::cout << "\n===== SEARCH BOOK =====\n";
        l1.searchBookById("101");

        std::cout << "\n===== SEARCH MEMBER =====\n";
        l1.searchMemberById(1);

        std::cout << "\n===== ISSUE BOOK =====\n";
        l1.issueBook("101", 1);

        std::cout << "\n===== ISSUED BOOKS =====\n";
        l1.displayIssueBook();

        std::cout << "\n===== RETURN BOOK =====\n";
        l1.returnBook("101", 1);

        std::cout << "\n===== ISSUED BOOKS AFTER RETURN =====\n";
        l1.displayIssueBook();





        return 0 ; 



}