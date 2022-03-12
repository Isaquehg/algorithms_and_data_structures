#include <iostream>

using namespace std;

int fatorial(int n){
    if(n == 0)
        return 1;
    else
        return n * fatorial(n - 1);
}

int main(){
    int num;//entrada
    int result;//resultado

    //input
    cin >> num;

    //calculo fatorial
    result = fatorial(num);

    //output
    cout << result << endl;

    return 0;
}