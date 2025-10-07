#include <iostream>
#include <string>
#include <stdexcept> 
#include <windows.h>

using namespace std;

class Person {
private:
    string lastName;
    string firstName;
    string middleName;
    string gender;
    int birthYear;

public:
   
    Person() : lastName(""), firstName(""), middleName(""), gender(""), birthYear(0) {}
    Person(string ln, string fn, string mn, string g, int by) {
        if (by < 1900 || by > 2025) throw invalid_argument("Некоректний рік народження!");
        lastName = ln;
        firstName = fn;
        middleName = mn;
        gender = g;
        birthYear = by;
    }

   
    friend istream& operator>>(istream& in, Person& p) {
        cout << "Введіть прізвище: ";
        in >> p.lastName;
        cout << "Введіть ім'я: ";
        in >> p.firstName;
        cout << "Введіть по батькові: ";
        in >> p.middleName;
        cout << "Введіть стать: ";
        in >> p.gender;
        cout << "Введіть рік народження: ";
        in >> p.birthYear;

        if (p.birthYear < 1925 || p.birthYear > 2025)
            throw invalid_argument("Помилка! Рік народження некоректний.");

        return in;
    }

    
    friend ostream& operator<<(ostream& out, const Person& p) {
        out << p.lastName << " " << p.firstName << " " << p.middleName
            << ", стать: " << p.gender
            << ", рік народження: " << p.birthYear;
        return out;
    }

   
    bool search(string ln) 
        const { return lastName == ln; }
    bool search(string ln, string fn) 
        const { return lastName == ln && firstName == fn; }
    bool search(int year) 
        const { return birthYear == year; }
};

int main() {
    SetConsoleOutputCP(1251); 
    SetConsoleCP(1251);
    try {
        Person p1;
        cin >> p1;

        cout << "\nВведена особа:\n" << p1 << endl;

        cout << "\nПошук за прізвищем 'Підставський': ";
        cout << (p1.search("Підставський") ? "знайдено" : "не знайдено") << endl;

        cout << "Пошук за прізвищем та ім'ям 'Підставський Назар': ";
        cout << (p1.search("Підставський", "Назарій") ? "знайдено" : "не знайдено") << endl;

        cout << "Пошук за роком народження 2006: ";
        cout << (p1.search(2006) ? "знайдено" : "не знайдено") << endl;
    }
    catch (invalid_argument& e) {
        cout << "Виняток: " << e.what() << endl;
    }
    catch (...) {
        cout << "Невідома помилка!" << endl;
    }

    return 0;
}