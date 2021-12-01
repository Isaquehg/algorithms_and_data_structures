#include <iostream>

using namespace std;

int main(){
    float v[3];//vector is a pointer
    float *p;//pointer

    v[0] = 1.5;
    v[1] = 3.0;
    v[2] = 5.57;
    p = v;
    cout << "p = " << p << endl;//vector adress
    cout << v << endl;//vector adress
    
    cout << *v << endl;//shows the vector's beginning
    cout << "*p = " << *p << endl;//first vector element v[0]
    p += 2;
    cout << "*p = " << *p << endl;//third element v[2]

    return 0;
}