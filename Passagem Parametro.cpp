#include <iostream>
#include <iomanip>

using namespace std;

//pode-se passar parâmetros por CÓPIA ou por REFERÊNCIA
//os vetores nas funções já são passados por referência
void media(double p1, double p2, double &m){
    m = (p1 + p2) / (2.0);
}

int main(){
    double n1, n2;//notas
    double result;//retorno da função

    cin >> n1 >> n2;

    media(n1, n2, result);

    cout << result << endl;

    return 0;
}