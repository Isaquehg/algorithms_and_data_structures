#include <iostream>

using namespace std;

int main(){
    int a;
    int *b;

    a = 2;

    b = &a;

    cout << &a << endl;
    cout << b << endl;
    cout << *b << endl;

    *b = 3;
    cout << a << endl;

    return 0;
}