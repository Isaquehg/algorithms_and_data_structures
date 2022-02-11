#include <iostream>

using namespace std;

int primo(int p){
    int primos = 0;//numero de divisores comums
    for(int i = p; i > 0; i --){
        if(p % i == 0)
            primos ++;
    }
    if(primos > 2)//se for primo
        return 0;
    else//não primo
        return 1;
}
int main(){
    int num;//numero a verificar
    int result;//resultado da func

    cin >> num;

    result = primo(num);
    if(result == 1 && num != 1)
        cout << "Primo" << endl;
    else
        cout << "Not" << endl;

    return 0;
}