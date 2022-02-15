//T(n) = n²
#include <iostream>

using namespace std;

int main(){
    int i, j;//counters
    int x;//aux
    int cont;
    int n;//problem size

    cin >> n;

    cont = 0;
    for(j = 0; j < n; j ++){//T(n) = n
        i = n;
        for(i = 0; i < n; i ++){//T(n) = n
            x = i * 2;
            cont ++;
        }
    }
    cout << cont << endl;

    return 0;
}