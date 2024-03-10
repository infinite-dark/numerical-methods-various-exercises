#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f (const double x) {
    return cos(x) - x;
}

int main() {
    double xL{0}, xR{0}, xM{0}, precision{0};
    int iterations{0};

    cout << "Enter xL: ";
    cin >> xL;

    cout << "Enter xR: ";
    cin >> xR;

    cout << "Enter precision: ";
    cin >> precision;

    do {
        xM = (xL + xR)/2;
        if (f(xL) * f(xM) > 0)
            xL = xM;
        else if (f(xL) * f(xM) < 0)
            xR = xM;
        iterations++;
    }   while (fabs((xL - xR)/xM) > precision);

    cout << setw(15) << setprecision(8) << xM << setw(5) << iterations << endl;
    return 0;
}
