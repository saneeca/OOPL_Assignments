#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book 
{
private:
    int classMark;
    string title;
    string status;  // "On loan", "Reserved", "On shelf"

public:
    Book(int mark, string bookTitle)
        : classMark(mark), title(bookTitle), status("On shelf") {}

    int getClassMark() const 
{
        return classMark;
    }

    string getTitle() const 
{
        return title;
    }

    string getStatus() const 
{
        return status;
    }

    void checkOut() 
{
        if (status == "On shelf") 
        {
            status = "On loan";
            cout << title << " has been checked out successfully.\n";
        } else if (status == "On loan") 
        {
            cout << title << " is already on loan.\n";
        } 
        else 
        {
            cout << title << " is reserved, cannot be checked out.\n";
        }
    }

    void reserve() {
        if (status == "On loan") 
        {
            status = "Reserved";
            cout << title << " has been reserved.\n";
        } 
        else if (status == "On shelf") 
        {
            cout << title << " is available, no need to reserve.\n";
        } 
        else 
        {
            cout << title << " is already reserved.\n";
        }
    }

    void inquire() const 
{
        cout << "Book: " << title << "\nClass Mark: " << classMark << "\nStatus: " << status << endl;
    }

    void returnBook() 
{
        if (status == "On loan") 
        {
            status = "On shelf";
            cout << title << " has been returned.\n";
        } 
        else 
        {
            cout << title << " was not on loan.\n";
        }
    }
};

class Library 
{
private:
    vector<Book> books;

public:
    void addBook(int classMark, string title) 
{
        books.push_back(Book(classMark, title));
    }

    Book* findBook(int classMark) 
{
        for (auto& book : books) 
        {
            if (book.getClassMark() == classMark) 
            {
                return &book;
            }
        }
        return nullptr;
    }

    void checkOutBook(int classMark) 
{
        Book* book = findBook(classMark);
        if (book != nullptr) 
        {
            book->checkOut();
        } 
        else 
        {
            cout << "Book with class mark " << classMark << " not found.\n";
        }
    }

    void reserveBook(int classMark) 
{
        Book* book = findBook(classMark);
        if (book != nullptr) 
        {
            book->reserve();
        } 
        else 
        {
            cout << "Book with class mark " << classMark << " not found.\n";
        }
    }

    void inquireBook(int classMark) 
{
        Book* book = findBook(classMark);
        if (book != nullptr) 
        {
            book->inquire();
        } 
        else 
        {
            cout << "Book with class mark " << classMark << " not found.\n";
        }
    }

    void returnBook(int classMark) 
{
        Book* book = findBook(classMark);
        if (book != nullptr) 
        {
            book->returnBook();
        } 
        else 
        {
            cout << "Book with class mark " << classMark << " not found.\n";
        }
    }

    void summary() const 
{
        int onLoan = 0, reserved = 0, onShelf = 0;

        for (const auto& book : books) 
        {
            if (book.getStatus() == "On loan") 
            {
                onLoan++;
            } 
            else if (book.getStatus() == "Reserved") 
            {
                reserved++;
            } 
            else 
            {
                onShelf++;
            }
        }

        cout << "\nLibrary Summary:\n";
        cout << "Total books: " << books.size() << "\n";
        cout << "Books on loan: " << onLoan << "\n";
        cout << "Books reserved: " << reserved << "\n";
        cout << "Books on shelf: " << onShelf << "\n";
    }
};

int main() 
{
    Library library;

    // Adding some books to the library
    library.addBook(101, "The Great Gatsby");
    library.addBook(102, "To Kill a Mockingbird");
    library.addBook(103, "1984");
    library.addBook(104, "Pride and Prejudice");
    library.addBook(105, "The Catcher in the Rye");

    int choice, classMark;

    while (true) 
    {
        cout << "\n--- Library System ---\n";
        cout << "1. Check out a book\n";
        cout << "2. Reserve a book\n";
        cout << "3. Inquire about a book\n";
        cout << "4. Return a book\n";
        cout << "5. View library summary\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: 
              {
                cout << "Enter class mark of the book to check out: ";
                cin >> classMark;
                library.checkOutBook(classMark);
                break;
            }
            case 2: 
              {
                cout << "Enter class mark of the book to reserve: ";
                cin >> classMark;
                library.reserveBook(classMark);
                break;
            }
            case 3: 
              {
                cout << "Enter class mark of the book to inquire: ";
                cin >> classMark;
                library.inquireBook(classMark);
                break;
            }
            case 4: 
              {
                cout << "Enter class mark of the book to return: ";
                cin >> classMark;
                library.returnBook(classMark);
                break;
            }
            case 5:
                library.summary();
                break;
            case 6:
                cout << "Exiting the system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
