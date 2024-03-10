#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f (const double x) {
    return cos(x) - x;
}

double root (const double xL, const double xR) {
    return (xL*f(xR) - xR*f(xL))/(f(xR) - f(xL));
}

int main() {
    double xL{0}, xR{0}, xM{0}, x0{0}, precision{0};
    int iterations = 0;

    cout << "Enter xL: ";
    cin >> xL;

    cout << "Enter xR: ";
    cin >> xR;

    cout << "Enter precision: ";
    cin >> precision;

    do {
        x0 = xM;
        xM = root(xL, xR);

        if (f(xL) * f(xM) > 0)
            xL = xM;
        else if (f(xR) * f(xM) > 0)
            xR = xM;

        iterations++;
    } while (fabs((x0 - xM)/x0) > precision);

    cout << setw(15) << setprecision(8) << xM << setw(5) << iterations << endl;
    return 0;
}
