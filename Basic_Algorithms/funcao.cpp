#include <iostream>

using namespace std;

//func p calcular o maior
void maior(int x, int y, int *r){
    if(x > y)
        *r = x;
    else
        *r = y;
}

int main(){
    int a;//var de entrada
    int b;//var de entrada
    int result;//var p resultado

    //input
    cin >> a;
    cin >> b;

    //verificando maior num
    maior(a, b, &result);

    //output
    cout << "O numero " << result << " e o maior" << endl;

    return 0;
}