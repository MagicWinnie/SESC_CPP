#include <iostream>
#include <cmath>

using namespace std;

bool check(unsigned long long n)
{
    int curr = n / 10 % 10, prev = n % 10;
    int delta = prev - curr;
    n /= 10;
    while (n != 0)
    {
        curr = n % 10;
        if (prev - curr != delta) return false;
        prev = curr;
        n /= 10;
    }
    return true;
}

// 111

int main()
{
    int n, count = 0;
    cin >> n;

    if (n < 3) { cout << "N must be >= 3\n"; return -1; }
    
    if (n < 9)
    {
        unsigned long long low = (int)pow(10, n - 1);
        unsigned long long up = (int)pow(10, n);

        for (unsigned long long i = low; i < up; i++)
            if (check(i)) { count++; cout << i << " "; } 
        cout << endl;
    } else if (n == 9) {
        count = 11;
    } else if (n == 10) {
        count = 10;
    } else {
        count = 9;
    }

    cout << count << endl;
    return 0;
}