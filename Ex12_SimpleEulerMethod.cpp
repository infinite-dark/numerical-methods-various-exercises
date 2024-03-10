#include <iostream>
#include <iomanip>
#include <cmath>

#define PRECISION 6
using namespace std;

double f(double y, int i) {
    if (i)
        return pow(y, 2) + 1;
    else
        return 0;
}

double euler(double y, double h, int i) {
    return y + h*f(y, i);
}

int main() {
    constexpr double h0 { 0.2 }, x0 { 0 }, xn { 1 }, y0 { 0 };

    cout << setprecision(PRECISION);
    for (int i = 0; i <= 2; i++) {
        double h = h0/pow(2, i);
        int steps = (xn - x0)/h;

        cout << "Solution for h = " << setw(5) << h << "\n";
        cout << setw(10) << "x" << setw(14) << "y\n";
        double y = y0;
        for (int j = 0; j <= steps; j++) {
            double x = x0 + j*h;
            y = euler(y, h, j);
            cout << setw(10) << x;
            cout << setw(14) << y;
            cout << "\n";
        }
        cout << "\n";
    }
}