#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Student {
    string surname;
    int id;
    double rating;
};

void printStudent(const Student& s) {
    cout << "Прізвище: " << s.surname
        << ", ID: " << s.id
        << ", Рейтинг: " << s.rating << endl;
}

bool findStudent(stack<Student> st, const string& target) {
    while (!st.empty()) {
        if (st.top().surname == target) {
            cout << "\nСтудента знайдено:\n";
            printStudent(st.top());
            return true;
        }
        st.pop();
    }
    cout << "\nСтудента з прізвищем '" << target << "' не знайдено.\n";
    return false;
}

void clearToSurname(stack<Student>& st, const string& target) {
    cout << "\nОчищення стеку до прізвища '" << target << "'...\n";
    while (!st.empty()) {
        if (st.top().surname == target) {
            cout << "Знайдено прізвище. Очищення завершено.\n";
            return;
        }
        st.pop();
    }
    cout << "Прізвище не знайдено. Стек повністю очищено.\n";
}

int main() {
    stack<Student> st;
    setlocale(LC_ALL, "Ukrainian");

    st.push({ "Бойко", 101, 85.5 });
    st.push({ "Петров", 102, 90.2 });
    st.push({ "Сидоренко", 103, 76.8 });
    st.push({ "Коваленко", 104, 88.1 });
    st.push({ "Мельник", 105, 92.4 });

    cout << "У стек занесено 5 студентів.\n";

    string target = "Коваленко";
    findStudent(st, target);

    clearToSurname(st, "Петров");

    cout << "\nСтек після очищення:\n";
    while (!st.empty()) {
        printStudent(st.top());
        st.pop();
    }

    return 0;
}
