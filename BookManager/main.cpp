#include <iostream>
#include <string>

using namespace std;

class Author {
private:
    string name;
    string nationality;
    int yearOfBirth;
public:
    Author(const string& name, const string& nationality, int yearOfBirth)
        : name(name), nationality(nationality), yearOfBirth(yearOfBirth) {}

    void display() const {
        cout << "Author Name: " << name << "\n"
             << "Nationality: " << nationality << "\n"
             << "Year of Birth: " << yearOfBirth << "\n";
    }
};

class Book {
private:
    string title;
    string isbn;
    double price;
    Author* author;     
public:
    Book(const string& title, const string& isbn, double price, Author* author)
        : title(title), isbn(isbn), price(price), author(author) {}

    void display() const {
        cout << "Title: " << title << "\n"
             << "ISBN: " << isbn << "\n"
             << "Price: PKR" << price << "\n";
        author -> display();
    }
};

int main() {

    Author author1("Jawad", "Pakistan", 2006);
    Author author2("Ahmed", "Qatar", 1997);

    Book* books[3];
    books[0] = new Book("C++ Programming", "ISBN001", 500, &author1);
    books[1] = new Book("Advanced OOP", "ISBN002", 300, &author2);
    books[2] = new Book("Data Structures", "ISBN003", 250, &author1); 

    cout << "All Books:\n";
    for (int i = 0; i < 3; ++i) {
        books[i] -> display();
        cout << "\n";
    }

    delete books[1];
    books[1] = nullptr;

    cout << "\nAfter deleting second book:\n";
    for (int i = 0; i < 3; ++i) {
        if (books[i]) books[i] -> display();        // <-- 
		cout << "\n";
    }

    cout << "\nAuthors still exist:\n";
    author1.display();
    author2.display();

    for (int i = 0; i < 3; ++i) {
        if (books[i]) delete books[i];
    }

	system("pause>0");    
    return 0;
}


