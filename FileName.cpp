#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

class Circle {
protected:
    double radius;

public:
    double M_PI = 3.14;
    Circle(double r = 1.0) {
        radius = r;
    }

    double area() const {
        return M_PI * radius * radius;
    }

    double length() const {
        return 2 * M_PI * radius;
    }

    void showInfo() const {
        cout << "Коло: радіус = " << radius
            << ", площа = " << area()
            << ", довжина кола = " << length() << endl;
    }

    double getRadius() const {
        return radius;
    }
};

class Rectangle {
protected:
    double width, height;

public:
    Rectangle(double w = 1.0, double h = 1.0) {
        width = w;
        height = h;
    }

    double area() const {
        return width * height;
    }

    double perimeter() const {
        return 2 * (width + height);
    }

    void showInfo() const {
        cout << "Прямокутник: ширина = " << width
            << ", висота = " << height
            << ", площа = " << area()
            << ", периметр = " << perimeter() << endl;
    }
};

class RectInCircle : public Circle, public Rectangle {
public:
    RectInCircle(double r) : Circle(r) {
        double diag = 2 * r;
        width = height = diag / sqrt(2);
    }

    void showAll() {
        cout << "\n=== Інформація про вписаний прямокутник і коло ===\n";
        Circle::showInfo();
        Rectangle::showInfo();
    }

    void writeToFile(const string& filename) {
        ofstream fout(filename);
        if (!fout) {
            cout << "Помилка відкриття файлу для запису!\n";
            return;
        }
        fout << "Коло:\n";
        fout << "  Радіус = " << radius << endl;
        fout << "  Площа = " << Circle::area() << endl;
        fout << "  Довжина кола = " << length() << endl;
        fout << "Прямокутник:\n";
        fout << "  Ширина = " << width << endl;
        fout << "  Висота = " << height << endl;
        fout << "  Площа = " << Rectangle::area() << endl;
        fout << "  Периметр = " << perimeter() << endl;
        fout.close();
        cout << "\nДані записано у файл: " << filename << endl;
    }

    void readFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "Помилка відкриття файлу для читання!\n";
            return;
        }
        cout << "\n=== Зчитані дані з файлу ===\n";
        string line;
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
    }
};


int main() {
    setlocale(LC_ALL, "Ukrainian");

    double r;
    cout << "Введіть радіус кола: ";
    cin >> r;

    RectInCircle obj(r);
    obj.showAll();

    string filename = "result.txt";
    obj.writeToFile(filename);
    obj.readFromFile(filename);

    return 0;
}
