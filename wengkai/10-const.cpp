#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x; 
    cin >> x;
    const int size = x;
    double a[size];
    cout << sizeof(a) / sizeof(*a) << endl;
    return 0;
}
