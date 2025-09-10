#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ukrainian");

    int var = 7;
    double x = 0.48 * var;
    double y = 0.47 * var;   
    double z = -1.32 * var;
    double a, b;

    b = 1 - (x + y) / pow(fabs(z), 0.34)+ pow(y,2) / 6.0 + pow(z, 3) / 120.0+ exp(x - y) / (z + y);
    a = log(fabs((y - sqrt(fabs(x * x - b))) * pow(fabs((y - x * x) / (z + 4 * y * y)), 2.0 / 3.0)));

    cout << "\na = " << a << endl;
    cout << "\nb = " << b << endl;

    return 0;
}