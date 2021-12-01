//Testing programs complexity
#include <iostream>

using namespace std;

int main(){
    int n;//tamanho problema
    int x, i;//aux
    int cont = 0;//contador

    cout << "Digite o valor de n: " << endl;
    cin >> n;

    //i ++ --> f(n) = n

    /*for(i = 0; i < n; i ++){
        x = 2 * i;
        cont ++;
    }
    cout << cont << " Repeticoes" << endl;*/
    

    i = 0;

    //i ++ --> f(n) = n

    while(i < n){
        x = 2 * i;
        i ++;
        cont ++;
    }
    cout << cont << " Repeticoes" << endl;

    return 0;
}