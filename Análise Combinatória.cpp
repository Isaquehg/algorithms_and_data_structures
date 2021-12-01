#include <iostream>
#include <iomanip>

using namespace std;

//fatorial
void fat(double &n){
    double mult = 1;
    for(int i = n; i > 1; i --){
        mult *= i;
    }
    n = mult;
}
//potênciação
double pow(double x, double y){
    double elev = 1.0;
    for(int i = 0; i < y; i ++){
        elev *= x;
    }
    return elev;
}
//combinação
double comb(double n1, double p1){
    double result1;//resultado
    double x = (n1 - p1);//auxiliar
    fat(n1);
    fat(p1);
    fat(x);
    result1 = n1 / (p1 * x);
    return result1;
}
//arranjo
void arr(double n2, double p2, double &result2){
    double x = n2 - p2;//auxiliar
    fat(n2);
    fat(x);
    result2 = n2 / x;
}
//terceira fórmula
void func3(double n3, double p3){
    double result3;
    double z = p3 + 2;
    result3 = pow(n3, z);
    cout << result3 << endl;
}
//quarta fórmula
double func4(){
    double n4, p4;
    cin >> n4 >> p4;
    double result4;
    double x4 = n4 - 1.0;
    fat(p4);
    double y4 = p4;
    result4 = pow(x4, y4);
    cout << result4 << endl;
}

int main(){
    double n, p;//variaveis de entrada
    double combinacao;//resultado da func
    double arranjo = 0.0;

    //input
    cin >> n >> p;

    //atribuindo valores às funções
    combinacao = comb(n, p);
    arr(n, p, arranjo);
    
    //output
    cout << fixed << setprecision(4);
    cout << "Combinacao = " << combinacao << endl;
    cout << "Arranjo = " << arranjo << endl;
    cout << "Funcao 3 = ";
    func3(n, p);
    cout << "Funcao 4 =  ";
    func4();
    cout << endl;

    return 0;
}