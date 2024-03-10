#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double f (const double x) {
    return 1/(1 + x*x);
}

double l (const vector<double>& arguments, const double x, const int j) {
    double quotient = 1;
    for (int i = 0; i < arguments.size(); i++)
        if (i != j)
            quotient *= (x - arguments[i])/(arguments[j] - arguments[i]);
    return quotient;
}

double lagrange (const vector<double>& arguments, const vector<double>& values, const double x) {
    double sum = 0;
    for (int j = 0; j < values.size(); j++)
        sum += l(arguments, x, j) * values[j];
    return sum;
}


int main() {
    constexpr char terminator{';'};
    vector<double> arguments, values;

    cout << "Enter interpolation range: ";
    double begin, end;
    cin >> begin; cin >> end;

    cout << "Input function arguments: ";
    for (char c; cin >> c && c != terminator;) {
        cin.putback(c);
        double x; cin >> x;
        arguments.push_back(x);
    }

    for (const double& x : arguments)
        values.push_back(f(x));

    cout << "Enter step width: ";
    double step{1};
    cin >> step;
    double steps = (end - begin)/step;

    for (int i = 0; i <= steps; i++) {
        double x = begin + i*step;
        cout << setw(5) << x << setw(15) << lagrange(arguments, values, x) << "\n";
    }

    return 0;
}
