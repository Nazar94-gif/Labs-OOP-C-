#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Book {
    string author, title, publisher;
    int year, pages;
public:
    Book() : 
        author(""), 
        title(""), 
        publisher(""), 
        year(0), 
        pages(0) {}

    void setAuthor(const string a) { author = a; }
    void setTitle(const string t) { title = t; }
    void setPublisher(const string p) { publisher = p; }
    void setYear(int y) { year = y; }
    void setPages(int p) { pages = p; }

    string getAuthor() const { return author; }
    string getTitle() const { return title; }
    string getPublisher() const { return publisher; }
    int getYear() const { return year; }
    int getPages() const { return pages; }

    void input() {
        cin.ignore();
        cout << "Автор: "; getline(cin, author);
        cout << "Назва: "; getline(cin, title);
        cout << "Видавництво: "; getline(cin, publisher);
        cout << "Рік видання: "; cin >> year;
        cout << "Сторінок: "; cin >> pages;
    }

    void show() const {
        cout << "\nКнига:\nАвтор: " << author
            << "\nНазва: " << title
            << "\nВидавництво: " << publisher
            << "\nРік: " << year
            << "\nСторінок: " << pages << endl;
    }
};


class Library {
    int count;
    Book* books;
public:
    Library(int n) : count(n), books(new Book[n]) {}
    ~Library() { delete[] books; }

    void fill() {
        for (int i = 0; i < count; i++) {
            cout << "\n--- Книга №" << i + 1 << " ---\n";
            books[i].input();
        }
    }

    void showAll() {
        cout << "\n=== Усі книги ===\n";
        for (int i = 0; i < count; i++) books[i].show();
    }

    void searchByAuthor(const string& a) {
        cout << "\nКниги автора " << a << ":\n";
        for (int i = 0; i < count; i++)
            if (books[i].getAuthor() == a) books[i].show();
    }

    void searchByTitle(const string& t) {
        cout << "\nКниги з назвою " << t << ":\n";
        for (int i = 0; i < count; i++)
            if (books[i].getTitle() == t) books[i].show();
    }

    void searchByPublisher(const string& p) {
        cout << "\nКниги видавництва " << p << ":\n";
        for (int i = 0; i < count; i++)
            if (books[i].getPublisher() == p) books[i].show();
    }

    void searchByYear(int y) {
        cout << "\nКниги видані у " << y << " році:\n";
        for (int i = 0; i < count; i++)
            if (books[i].getYear() == y) books[i].show();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть кількість книг: ";
    cin >> n;
    Library lib(n);

    lib.fill();
    lib.showAll();

    string s;
    int y;
    cin.ignore();

    cout << "\nВведіть автора для пошуку: "; getline(cin, s); lib.searchByAuthor(s);
    cout << "\nВведіть назву для пошуку: "; getline(cin, s); lib.searchByTitle(s);
    cout << "\nВведіть видавництво для пошуку: "; getline(cin, s); lib.searchByPublisher(s);
    cout << "\nВведіть рік видання для пошуку: "; cin >> y; lib.searchByYear(y);

    return 0;
}
