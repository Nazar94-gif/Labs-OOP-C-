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
        cout << "�����: "; getline(cin, author);
        cout << "�����: "; getline(cin, title);
        cout << "�����������: "; getline(cin, publisher);
        cout << "г� �������: "; cin >> year;
        cout << "�������: "; cin >> pages;
    }

    void show() const {
        cout << "\n�����:\n�����: " << author
            << "\n�����: " << title
            << "\n�����������: " << publisher
            << "\nг�: " << year
            << "\n�������: " << pages << endl;
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
            cout << "\n--- ����� �" << i + 1 << " ---\n";
            books[i].input();
        }
    }

    void showAll() {
        cout << "\n=== �� ����� ===\n";
        for (int i = 0; i < count; i++) books[i].show();
    }

    void searchByAuthor(const string& a) {
        cout << "\n����� ������ " << a << ":\n";
        for (int i = 0; i < count; i++)
            if (books[i].getAuthor() == a) books[i].show();
    }

    void searchByTitle(const string& t) {
        cout << "\n����� � ������ " << t << ":\n";
        for (int i = 0; i < count; i++)
            if (books[i].getTitle() == t) books[i].show();
    }

    void searchByPublisher(const string& p) {
        cout << "\n����� ����������� " << p << ":\n";
        for (int i = 0; i < count; i++)
            if (books[i].getPublisher() == p) books[i].show();
    }

    void searchByYear(int y) {
        cout << "\n����� ����� � " << y << " ����:\n";
        for (int i = 0; i < count; i++)
            if (books[i].getYear() == y) books[i].show();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "������ ������� ����: ";
    cin >> n;
    Library lib(n);

    lib.fill();
    lib.showAll();

    string s;
    int y;
    cin.ignore();

    cout << "\n������ ������ ��� ������: "; getline(cin, s); lib.searchByAuthor(s);
    cout << "\n������ ����� ��� ������: "; getline(cin, s); lib.searchByTitle(s);
    cout << "\n������ ����������� ��� ������: "; getline(cin, s); lib.searchByPublisher(s);
    cout << "\n������ �� ������� ��� ������: "; cin >> y; lib.searchByYear(y);

    return 0;
}
