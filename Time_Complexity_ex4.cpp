//Analising a algorithms complexity
#include <iostream>

using namespace std;

int main(){
    int n;//problem size
    int x, i, j, k;//aux
    int cont = 0;//counter

    cout << "Type a n value: " << endl;
    cin >> n;

    //f(n) = n³
    //nT = n1 * n2 * nn(The final complexity is the number ^ loops_number)
    for(i = 0; i < n; i ++){
        for(j = 0; j < n; j ++){
            for(k = 0; k < n; k ++){
                x = 2 * i;
                cont ++;
            }
        }

    }
    cout << cont << " Iterations" << endl;

    return 0;
}