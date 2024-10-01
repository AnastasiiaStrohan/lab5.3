#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double s(const double x);

int main()
{
    double t_start, t_end;
    int n;
    cout << "tp = "; cin >> t_start;
    cout << "tk = "; cin >> t_end;
    cout << "n = "; cin >> n;

    double dt = (t_end - t_start) / n;
    double t = t_start;


    cout << fixed << "-----------------------------------" << endl;
    cout << "|" << setw(10) << "t" << " |" << setw(20) << "s(t)" << " |" << endl;
    cout << "-----------------------------------" << endl;


    while (t <= t_end)
    {
        double result = s(t * t + 2 * s(1 - t) + s(1));
        cout << "|" << setw(10) << setprecision(5) << t << " |"
            << setw(20) << setprecision(10) << result << " |" << endl;
        t += dt;
    }

    cout << "-----------------------------------" << endl;
    return 0;
}

double s(const double x)
{
    if (abs(x) > 1)
    {
        return (cos(x) * cos(x) + 1);
    }
    else
    {
        double S = 0;
        int k = 0;
        double a = 1;
        S = a;

        do
        {
            k++;
            double R = (pow(x, 2 * k + 1)) / ((2 * k + 1) * tgamma(2 * k + 2));
            a *= R;
            S += a;
        } while (k < 4);

        return S;
    }
}
