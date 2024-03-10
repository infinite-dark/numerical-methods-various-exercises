#include <iostream>
#include <iomanip>
#include <cmath>

#define PRECISION 10

using namespace std;

double f(double x) {
    return x*exp(x);
}

double d1f(double x) {
    return exp(x) + f(x);
}

double d2f(double x) {
    return exp(x) + d1f(x);
}

int main() {
    constexpr double x0 { 2 };

    cout << setprecision(PRECISION);
    cout << "Forward Difference Approximation\n";
    for (int i = 0; i < 10; i++) {
        double h = 0.05 + i*0.05;
        double first_derivative = (f(x0 + h) - f(x0))/h;
        double second_derivative = (f(x0) - 2*f(x0 + h) + f(x0 + 2*h))/(h*h);
        cout << setw(5) << "h =" << setw(5) << h;
        cout << "\t\tf' =" << setw(15) << first_derivative;
        cout << "\t\tf'' =" << setw(15) << second_derivative << "\n";
    }
    cout << "\n";

    cout << "Central Difference Approximation\n";
    for (int i = 0; i < 10; i++) {
        double h = 0.05 + i*0.05;
        double first_derivative = (f(x0 + h) - f(x0 - h))/(2*h);
        double second_derivative = (f(x0 + h) - 2*f(x0) + f(x0 - h))/(h*h);
        cout << setw(5) << "h =" << setw(5) << h;
        cout << "\t\tf' =" << setw(15)  << first_derivative;
        cout << "\t\tf'' =" << setw(15) << second_derivative << "\n";
    }
    cout << "\n";

    cout << "Exact Solution\n";
    cout << "f'  =" << setw(15) << d1f(x0) << "\n";
    cout << "f'' =" << setw(15) << d2f(x0) << "\n";

    return 0;
}