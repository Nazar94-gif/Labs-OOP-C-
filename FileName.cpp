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
        cout << "����: ����� = " << radius
            << ", ����� = " << area()
            << ", ������� ���� = " << length() << endl;
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
        cout << "�����������: ������ = " << width
            << ", ������ = " << height
            << ", ����� = " << area()
            << ", �������� = " << perimeter() << endl;
    }
};

class RectInCircle : public Circle, public Rectangle {
public:
    RectInCircle(double r) : Circle(r) {
        double diag = 2 * r;
        width = height = diag / sqrt(2);
    }

    void showAll() {
        cout << "\n=== ���������� ��� �������� ����������� � ���� ===\n";
        Circle::showInfo();
        Rectangle::showInfo();
    }

    void writeToFile(const string& filename) {
        ofstream fout(filename);
        if (!fout) {
            cout << "������� �������� ����� ��� ������!\n";
            return;
        }
        fout << "����:\n";
        fout << "  ����� = " << radius << endl;
        fout << "  ����� = " << Circle::area() << endl;
        fout << "  ������� ���� = " << length() << endl;
        fout << "�����������:\n";
        fout << "  ������ = " << width << endl;
        fout << "  ������ = " << height << endl;
        fout << "  ����� = " << Rectangle::area() << endl;
        fout << "  �������� = " << perimeter() << endl;
        fout.close();
        cout << "\n��� �������� � ����: " << filename << endl;
    }

    void readFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "������� �������� ����� ��� �������!\n";
            return;
        }
        cout << "\n=== ������ ��� � ����� ===\n";
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
    cout << "������ ����� ����: ";
    cin >> r;

    RectInCircle obj(r);
    obj.showAll();

    string filename = "result.txt";
    obj.writeToFile(filename);
    obj.readFromFile(filename);

    return 0;
}
