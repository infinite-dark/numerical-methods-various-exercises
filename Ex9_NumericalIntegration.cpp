#include <iostream>
#include <iomanip>
#include <cmath>

#define PRECISION 13

using namespace std;

double f(double x) {
    return sin(x);
}

double d1f(double x) {
    return cos(x);
}

double d3f(double x) {
    return -cos(x);
}

double trapezoid(double x0, double xn, int n) {
    double h = (xn - x0)/n;

    double result = 0;
    result += f(x0)/2;
    result += f(xn)/2;
    for (int i = 1; i < n; i++) {
        result += f(x0 + i*h);
    }
    result *= h;

    return result;
}

double simpson(double x0, double xn, int n) {
    double h = (xn - x0)/n;

    double result = 0;
    result += f(x0);
    result += f(xn);
    for (int i = 1; i < n; i++)
        if (i%2 == 1)
            result += 4*f(x0 + i*h);
        else
            result += 2*f(x0 + i*h);
    result *= h/3;

    return result;
}

double boole(double x0, double xn, int n) {
    double h = (xn - x0)/n;

    double result = 0;
    result += 7*f(x0);
    result += 7*f(xn);
    for (int i = 1; i < n; i++)
        if (i%2 == 1)
            result += 32*f(x0 + i*h);
        else if (i%4 == 0)
            result += 14*f(x0 + i*h);
        else if (i%2 == 0)
            result += 12*f(x0 + i*h);
    result *= 2*h/45;

    return result;
}

double euler_maclaurin(double x0, double xn, int n) {
    double h = (xn - x0)/n;

    double result = trapezoid(x0, xn, n);
    result += (d1f(x0) - d1f(xn)) * pow(h, 2)/12;
    result -= (d3f(x0) - d3f(xn)) * pow(h, 4)/720;

    return result;
}

int main() {
    constexpr double x0 { 0 }, xn { M_PI };

    cout << setprecision(PRECISION);
    cout << setw(10) << "N" << setw(20) << "Trapezoid" << setw(20) << "Simpson" << setw(20) << "Boole" << setw(20) << "Euler-Maclaurin\n";
    for (int n = 4; n <= 1024; n *= 2) {
        cout << setw(10) << n;
        cout << setw(20) << trapezoid(x0, xn, n);
        cout << setw(20) << simpson(x0, xn, n);
        cout << setw(20) << boole(x0, xn, n);
        cout << setw(20) << euler_maclaurin(x0, xn, n);
        cout << endl;
    }

    return 0;
}