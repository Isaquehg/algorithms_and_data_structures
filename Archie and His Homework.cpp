#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;//numerator
    int d;//denominator
    
    cin >> n;
    cin >> d;

    //__gcd(x, y) finds the greatest divisor by both integers
    cout << n / (__gcd(n, d)) << " " << d / (__gcd(n, d)) << endl;

    return 0;
}