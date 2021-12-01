#include <iostream>

using namespace std;

int fatorial(int n){
    int fat = 1;
    for(int i = n; i > 0; i ++){
        fat *= i;
    }
    return fat;
}
int main(){
    int x;
    int result;

    cin >> x;

    result = fatorial(x);

    return 0;
}