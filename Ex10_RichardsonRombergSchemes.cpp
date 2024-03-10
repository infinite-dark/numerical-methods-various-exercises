#include <iostream>
#include <iomanip>
#include <cmath>

#define PRECISION 13
using namespace std;

double f(double x) {
    return x*exp(x);
}

double f2(double x) {
    return sin(x);
}

double richardson(double x, int i, double h, int derivative) {
    if (i < 1) {
        cout << "invalid value" << endl;
        return i;
    }
    if (i == 1) {
        if (derivative == 1) {
            return (f(x + h) - f(x - h)) / 2 / h;
        }
        if (derivative == 2) {
            return (f(x + h) - 2*f(x) + f(x - h))/h/h;
        }
        else {
            cout << "invalid value" << endl;
            return derivative;
        }
    }
    return (pow(4, i - 1) * richardson(x, i - 1, h, derivative) - richardson(x, i - 1, 2*h, derivative))/(pow(4, i - 1) - 1);
}

double romberg(double x0, double xn, int m, int k) {
    if (k == 0) {
        int n = pow(2, m);
        double h = (xn - x0)/n;

        double trapezoid = 0;
        trapezoid += f2(x0)/2;
        trapezoid += f2(xn)/2;
        for (int i = 1; i < n; i++) {
            trapezoid += f2(x0 + i*h);
        }
        trapezoid *= h;

        return trapezoid;
    }
    else {
        return (pow(4, k) * romberg(x0, xn, m, k - 1) - romberg(x0, xn, m - 1, k - 1))/(pow(4, k) - 1);
    }
}

int main() {
    cout << setprecision(PRECISION);
    cout << setw(50) << "First Derivative\n";
    cout << setw(10) << "h" << setw(20) << "D1" << setw(20) << "D2" << setw(20) << "D3" << setw(20) << "D4\n";
    for (int j = 0; j <= 3; j++) {
        double h = 0.4/pow(2, j);
        cout << setw(10) << h;
        for (int i = 1; i <= j + 1; i++) {
            cout << setw(20) << richardson(2, i, h, 1);
        }
        cout << "\n";
    }
    cout << "\n";

    cout << setw(50) << "Second Derivative\n";
    cout << setw(10) << "h" << setw(20) << "D1" << setw(20) << "D2" << setw(20) << "D3" << setw(20) << "D4\n";
    for (int j = 0; j <= 3; j++) {
        double h = 0.4/pow(2, j);
        cout << setw(10) << h;
        for (int i = 1; i <= j + 1; i++) {
            cout << setw(20) << richardson(2, i, h, 2);
        }
        cout << "\n";
    }
    cout << "\n";

    cout << setw(50) << "Integral\n";
    cout << setw(10) << "m" << setw(20) << "I(m,0)" << setw(20) << "I(m,1)" << setw(20) << "I(m,2)" << setw(20) << "I(m,3)\n";
    for (int m = 2; m <= 5; m++) {
        cout << setw(10) << m;
        for (int k = 0; k <= m - 2; k++) {
            cout << setw(20) << romberg(0, M_PI, m, k);
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}