#include <iostream>
#include <iomanip>

using namespace std;

void fat(long &n){
    long mult = 1;
    for(int i = n; i > 1; i --){
        mult *= i;
    }
    n = mult;
}

int main(){
    long num;//numero de entrada
    
    //input
    cin >> num;
    //chamada da função
    fat(num);
    //output
    cout << num << endl;

    return 0;
}