#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    int var = 7;
    double y = 0.47 * var;
    double z = -1.32 * var;

    
    double x = 0.48 * var;
    double b = 1 - (x + y) / pow(fabs(z), 0.34)
        + pow(y, 2) / 6.0
        + pow(z, 3) / 120.0
        + exp(x - y) / (z + y);

    double a = log(fabs((y - sqrt(fabs(x * x - b))) *
        pow(fabs((y - x * x) / (z + 4 * y * y)), 2.0 / 3.0)));

    
    cout << "1 завдання:\n";
    cout << "x = " << x << "\n";
    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n\n";

    
    double x_start = -1.0, x_end = 1.0, dx = 0.2;

    cout << "2 завдання:\n";
    for (x = x_start; x <= x_end; x += dx)
    {
        b = 1 - (x + y) / pow(fabs(z), 0.34)
            + pow(y, 2) / 6.0
            + pow(z, 3) / 120.0
            + exp(x - y) / (z + y);

        a = log(fabs((y - sqrt(fabs(x * x - b))) *
            pow(fabs((y - x * x) / (z + 4 * y * y)), 2.0 / 3.0)));

        cout << "x = " << x << "  a = " << a << "  b = " << b << endl;
    }

    return 0;
}



