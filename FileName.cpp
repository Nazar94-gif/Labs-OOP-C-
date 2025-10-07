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
        if (by < 1900 || by > 2025) throw invalid_argument("����������� �� ����������!");
        lastName = ln;
        firstName = fn;
        middleName = mn;
        gender = g;
        birthYear = by;
    }

   
    friend istream& operator>>(istream& in, Person& p) {
        cout << "������ �������: ";
        in >> p.lastName;
        cout << "������ ��'�: ";
        in >> p.firstName;
        cout << "������ �� �������: ";
        in >> p.middleName;
        cout << "������ �����: ";
        in >> p.gender;
        cout << "������ �� ����������: ";
        in >> p.birthYear;

        if (p.birthYear < 1925 || p.birthYear > 2025)
            throw invalid_argument("�������! г� ���������� �����������.");

        return in;
    }

    
    friend ostream& operator<<(ostream& out, const Person& p) {
        out << p.lastName << " " << p.firstName << " " << p.middleName
            << ", �����: " << p.gender
            << ", �� ����������: " << p.birthYear;
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

        cout << "\n������� �����:\n" << p1 << endl;

        cout << "\n����� �� �������� 'ϳ����������': ";
        cout << (p1.search("ϳ����������") ? "��������" : "�� ��������") << endl;

        cout << "����� �� �������� �� ��'�� 'ϳ���������� �����': ";
        cout << (p1.search("ϳ����������", "������") ? "��������" : "�� ��������") << endl;

        cout << "����� �� ����� ���������� 2006: ";
        cout << (p1.search(2006) ? "��������" : "�� ��������") << endl;
    }
    catch (invalid_argument& e) {
        cout << "�������: " << e.what() << endl;
    }
    catch (...) {
        cout << "������� �������!" << endl;
    }

    return 0;
}