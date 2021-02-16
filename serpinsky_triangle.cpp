#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

double pi = atan(1.0) * 4;

void triangle(double x1, double y1, double x2, double y2, double x3, double y3, int n)
{
    if (n == 1)
    {
        cout << x1 << " " << y1 << "\n" << x2 << " " << y2 << "\n\n";
        cout << x2 << " " << y2 << "\n" << x3 << " " << y3 << "\n\n";
        cout << x3 << " " << y3 << "\n" << x1 << " " << y1 << "\n\n";
        return;
    }
    triangle(x1, y1, (x1 + x2)/2.0, y2, ((x1 + x2)/2.0 + x1)/2.0, (y1 + y3)/2.0, n - 1);
    triangle((x1 + x2)/2.0, y1, x2, y2, ((x1 + x2)/2.0 + x2)/2.0, (y1 + y3)/2.0, n - 1); 
    triangle((x1 + (x1 + x2)/2.0)/2.0, (y1 + y3)/2.0, ((x1 + x2)/2.0 + x2)/2.0, (y1 + y3)/2.0, x3, y3, n - 1);
}

int main()
{
    int n;
    double size;
    cin >> n >> size;
    triangle(0.0, 0.0, size, 0.0, size*cos(pi/3.0), size*sin(pi/3.0), n);
}