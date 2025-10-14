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
        cout << "Ęîëî: đŕäłóń = " << radius
            << ", ďëîůŕ = " << area()
            << ", äîâćčíŕ ęîëŕ = " << length() << endl;
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
        cout << "Ďđ˙ěîęóňíčę: řčđčíŕ = " << width
            << ", âčńîňŕ = " << height
            << ", ďëîůŕ = " << area()
            << ", ďĺđčěĺňđ = " << perimeter() << endl;
    }
};

class RectInCircle : public Circle, public Rectangle {
public:
    RectInCircle(double r) : Circle(r) {
        double diag = 2 * r;
        width = height = diag / sqrt(2);
    }

    void showAll() {
        cout << "\n=== ˛íôîđěŕöł˙ ďđî âďčńŕíčé ďđ˙ěîęóňíčę ł ęîëî ===\n";
        Circle::showInfo();
        Rectangle::showInfo();
    }

    void writeToFile(const string& filename) {
        ofstream fout(filename);
        if (!fout) {
            cout << "Ďîěčëęŕ âłäęđčňň˙ ôŕéëó äë˙ çŕďčńó!\n";
            return;
        }
        fout << "Ęîëî:\n";
        fout << "  Đŕäłóń = " << radius << endl;
        fout << "  Ďëîůŕ = " << Circle::area() << endl;
        fout << "  Äîâćčíŕ ęîëŕ = " << length() << endl;
        fout << "Ďđ˙ěîęóňíčę:\n";
        fout << "  Řčđčíŕ = " << width << endl;
        fout << "  Âčńîňŕ = " << height << endl;
        fout << "  Ďëîůŕ = " << Rectangle::area() << endl;
        fout << "  Ďĺđčěĺňđ = " << perimeter() << endl;
        fout.close();
        cout << "\nÄŕíł çŕďčńŕíî ó ôŕéë: " << filename << endl;
    }

    void readFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "Ďîěčëęŕ âłäęđčňň˙ ôŕéëó äë˙ ÷čňŕíí˙!\n";
            return;
        }
        cout << "\n=== Ç÷čňŕíł äŕíł ç ôŕéëó ===\n";
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
    cout << "Ââĺäłňü đŕäłóń ęîëŕ: ";
    cin >> r;

    RectInCircle obj(r);
    obj.showAll();

    string filename = "result.txt";
    obj.writeToFile(filename);
    obj.readFromFile(filename);

    return 0;
}
