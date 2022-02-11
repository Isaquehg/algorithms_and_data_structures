#include <iostream>

using namespace std;

int main(){
    int i, j, ciclo = 0, max = 0, z;

    cin >> i >> j;

    for(int x=i; x<=j; x++){ //operar os ciclos de i a j
        z = x;
        while(z != 1){
            if (z % 2 == 0){ //se for par
                z = z/2;
                ciclo ++;
                if (ciclo > max){ //adicionando o maior ciclo ao max
                    max = ciclo;
                }
                continue;
            }
            else{
                z = (3*z) + 1; //se for ímpar
                ciclo ++;
                if (ciclo > max){ //add o maior ciclo ao max
                    max = ciclo;
                }
                continue;
            }
        }
    }
    cout << i << " " << j << " " << max << endl;

    return 0;
}