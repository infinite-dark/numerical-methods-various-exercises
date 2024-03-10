#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f (const double x) {
    return cos(x) - x;
}

double root (const double x1, const double x0) {
    return (x1*f(x0) - x0*f(x1))/(f(x0) - f(x1));
}

int main() {
    double x0{0}, x1{0}, precision{0};
    int iterations{0};

    cout << "Enter first initial argument: ";
    cin >> x0;

    cout << "Enter second initial argument: ";
    cin >> x1;

    cout << "Enter precision: ";
    cin >> precision;

    do {
        double xi = root(x0, x1);
        x0 = x1;
        x1 = xi;
        iterations++;
    } while (fabs((x1 - x0)/x1) > precision);

    cout << setw(15) << setprecision(8) << x1 << setw(5) << iterations << endl;
    return 0;
}
