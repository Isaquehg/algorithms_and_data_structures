#include <iostream>

using namespace std;

int sinal(int n){
    int result;//resultado
    if(n > 0)
        result = 1;
    else if(n == 0)
        result = 0;
    else
        result = -1;
    return result;
}
int main(){
    int x;//parametro da func

    //input
    cin >> x;

    //output
    if(sinal(x) == 1)
        cout << "Positivo" << endl;
    else if(sinal(x) == 0)
        cout << "Zero" << endl;
    else
        cout << "Negativo" << endl;
}