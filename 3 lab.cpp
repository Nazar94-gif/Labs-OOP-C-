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
        if (by < 1900 || by > 2025) throw invalid_argument("Íåêîðåêòíèé ð³ê íàðîäæåííÿ!");
        lastName = ln;
        firstName = fn;
        middleName = mn;
        gender = g;
        birthYear = by;
    }

   
    friend istream& operator>>(istream& in, Person& p) {
        cout << "Ââåä³òü ïð³çâèùå: ";
        in >> p.lastName;
        cout << "Ââåä³òü ³ì'ÿ: ";
        in >> p.firstName;
        cout << "Ââåä³òü ïî áàòüêîâ³: ";
        in >> p.middleName;
        cout << "Ââåä³òü ñòàòü: ";
        in >> p.gender;
        cout << "Ââåä³òü ð³ê íàðîäæåííÿ: ";
        in >> p.birthYear;

        if (p.birthYear < 1925 || p.birthYear > 2025)
            throw invalid_argument("Ïîìèëêà! Ð³ê íàðîäæåííÿ íåêîðåêòíèé.");

        return in;
    }

    
    friend ostream& operator<<(ostream& out, const Person& p) {
        out << p.lastName << " " << p.firstName << " " << p.middleName
            << ", ñòàòü: " << p.gender
            << ", ð³ê íàðîäæåííÿ: " << p.birthYear;
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

        cout << "\nÂâåäåíà îñîáà:\n" << p1 << endl;

        cout << "\nÏîøóê çà ïð³çâèùåì 'Ï³äñòàâñüêèé': ";
        cout << (p1.search("Ï³äñòàâñüêèé") ? "çíàéäåíî" : "íå çíàéäåíî") << endl;

        cout << "Ïîøóê çà ïð³çâèùåì òà ³ì'ÿì 'Ï³äñòàâñüêèé Íàçàð': ";
        cout << (p1.search("Ï³äñòàâñüêèé", "Íàçàð³é") ? "çíàéäåíî" : "íå çíàéäåíî") << endl;

        cout << "Ïîøóê çà ðîêîì íàðîäæåííÿ 2006: ";
        cout << (p1.search(2006) ? "çíàéäåíî" : "íå çíàéäåíî") << endl;
    }
    catch (invalid_argument& e) {
        cout << "Âèíÿòîê: " << e.what() << endl;
    }
    catch (...) {
        cout << "Íåâ³äîìà ïîìèëêà!" << endl;
    }

    return 0;
}
