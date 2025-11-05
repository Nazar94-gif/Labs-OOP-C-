#include <iostream>
#include <string>
using namespace std;

class Mammal {
protected:
    string name;
    int age;
public:
    Mammal(string n, int a) : name(n), age(a) {}
    virtual ~Mammal() {}
    virtual void describe() const = 0;
};

class Animal : public Mammal {
protected:
    string species;
public:
    Animal(string n, int a, string s) : Mammal(n, a), species(s) {}
    virtual ~Animal() {}
};

class Horse : public Animal {
    string breed;
public:
    Horse(string n, int a, string b)
        : Animal(n, a, "кінь"), breed(b) {}

    void describe() const override {
        cout << "Тварина: " << species << endl;
        cout << "Кличка: " << name << ", Вік: " << age << " років" << endl;
        cout << "Порода: " << breed << endl;
    }
};

class Cow : public Animal {
    double milkYield; 
public:
    Cow(string n, int a, double yield)
        : Animal(n, a, "корова"), milkYield(yield) {}

    void describe() const override {
        cout << "Тварина: " << species << endl;
        cout << "Ім'я: " << name << ", Вік: " << age << " років" << endl;
        cout << "Дає молока: " << milkYield << " л/день" << endl;
    }
};

class Human : public Mammal {
    string profession;
public:
    Human(string n, int a, string p)
        : Mammal(n, a), profession(p) {}

    void describe() const override {
        cout << "Ім'я: " << name << ", Вік: " << age << " років" << endl;
        cout << "Професія: " << profession << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ukrainian");

    Mammal* mammals[3];

    mammals[0] = new Human("Назар", 30, "програміст");
    mammals[1] = new Horse("Андрій", 3, "кінь свійський");
    mammals[2] = new Cow("Мілка", 4, 10);

    cout << "=== ОПИС ССАВЦІВ ===\n\n";
    for (int i = 0; i < 3; i++) {
        mammals[i]->describe();
        cout << "------------------------------\n";
    }

    for (int i = 0; i < 3; i++)
        delete mammals[i];

    return 0;
}
