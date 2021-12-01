#include <iostream>

using namespace std;

void tabuada(int n){
    int result;//valor da multiplicação
    for(int i = 1; i <= 10; i ++){
        result = n * i;
        cout << n << " X " << i << " = " << result << endl;
    }
}
int main(){
    int num;//coluna da tabuada
    //input
    cin >> num;
    //chamada da func
    tabuada(num);

    return 0;
}