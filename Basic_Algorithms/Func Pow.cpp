#include <iostream>

using namespace std;

int pow(int x, int y){
    int elev = 1;
    for(int i = 0; i < y; i ++){
        elev *= x;
    }
    return elev;
}
int main(){
    int a, b;//base e expoente
    int result;//resultado da func
    //input
    cin >> a >> b;
    //atribuição
    result = pow(a, b);
    //output
    cout << result << endl;

    return 0;
}