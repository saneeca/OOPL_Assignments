#include <iostream>
#include <cstring>
using namespace std;

class Book {
    char* author;
    char* title;
    char* publisher;
    float price;
    int stock;

public:
    // Constructor with dynamic memory allocation
    Book(const char* a, const char* t, const char* p, float pr, int s) {
        author = new char[strlen(a) + 1];
        strcpy(author, a);

        title = new char[strlen(t) + 1];
        strcpy(title, t);

        publisher = new char[strlen(p) + 1];
        strcpy(publisher, p);

        price = pr;
        stock = s;
    }

    // Destructor to free memory
    ~Book() {
        delete[] author;
        delete[] title;
        delete[] publisher;
    }

    // Function to display book details
    void display() {
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nPublisher: " << publisher;
        cout << "\nPrice: " << price;
        cout << "\nStock: " << stock << endl;
    }

    // Function to check availability and process sale
    void searchAndBuy(const char* t, const char* a, int copies) {
        if (strcmp(title, t) == 0 && strcmp(author, a) == 0) {
            cout << "\nBook found!";
            display();

            if (copies <= stock) {
                float total = price * copies;
                cout << "Total cost for " << copies << " copies: " << total << endl;
                stock -= copies;
            } else {
                cout << "Required copies not in stock!" << endl;
            }
        }
    }

    // Function to check if title and author match
    bool matches(const char* t, const char* a) {
        return (strcmp(title, t) == 0 && strcmp(author, a) == 0);
    }
};
int main() {
    // Creating some books
    Book b1("George Orwell", "1984", "Penguin", 300.0, 10);
    Book b2("J.K. Rowling", "Harry Potter", "Bloomsbury", 500.0, 5);

    // Book list
    Book* books[] = { &b1, &b2 };
    int numBooks = 2;

    // Customer input
    char searchTitle[100], searchAuthor[100];
    int copies;

    cout << "Enter title of the book: ";
    cin.getline(searchTitle, 100);
    cout << "Enter author of the book: ";
    cin.getline(searchAuthor, 100);
    cout << "Enter number of copies: ";
    cin >> copies;

    bool found = false;

    for (int i = 0; i < numBooks; i++) {
        if (books[i]->matches(searchTitle, searchAuthor)) {
            books[i]->searchAndBuy(searchTitle, searchAuthor, copies);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not available in the inventory!" << endl;
    }

    return 0;
}
