#include <iostream>

using namespace std;

void sum(int x, int y, int *s){
    *s = x + y;
}

int main(){
    int a, b, c;
    a = 5;
    b = 10;
    c = 0;

    sum(a, b, &c);//passing the C adress to the pointer

    cout << "C = " << c << endl;

    return 0;
}