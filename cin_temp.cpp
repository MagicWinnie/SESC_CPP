#include <iostream>
#include <vector>

using namespace std;

int main()
{
    double temp;
    vector<double> nums;
    while (cin>>temp) nums.push_back(temp);
    for (double c: nums) cout << c << " ";
    cout << endl;
}