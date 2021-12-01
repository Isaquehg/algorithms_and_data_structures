#include <iostream>
using namespace std;

void soma(int a, int b, int &s){
    s = a + b;
}
int main(){
    int x = 2, y = 3;
    int res = 0;

    soma(x, y, res);

    cout << res << endl;

    return 0;
}
//
//& antes de um parametro copia a variavel para a main