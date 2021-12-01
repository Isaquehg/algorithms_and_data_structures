#include <iostream>

using namespace std;

int Comb(int n, int k){
    if(k == 1){//cond 1
        return n;
    }
    else if(n == k){//cond 2
        return 1;
    }
    else{//cond 3
        return Comb(n - 1, k - 1) + Comb(n - 1, k);
    }
}

int main(){
    int n, k;//numero de pessoas tomada k a k
    int result;//retorno da func
    //input
    cin >> n >> k;
    //combinacao
    result = Comb(n, k);
    //output
    cout << result << endl;

    return 0;
}