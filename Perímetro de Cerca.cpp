#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double dist(int XA, int YA, int XB, int YB){
    double distancia;//distancia de arames
    distancia = sqrt(pow(XB - XA, 2) + pow(YB - YA, 2) * 1.0);
    distancia *= 4.0;//4 fileiras!!
    return distancia;
}
int main(){
    double rdist;//valor da funcao
    double total = 0.0;//total das distancias
    int xa, xb, ya, yb;//cooordenadas
    int ultxa, ultya, ultxb, ultyb;//auxiliares p calcular distancia do ultimo valor com o primeiro(ultimo ponto)
    int prixa, priya;//primeiro ponto

    //input
    cin >> xa >> ya;
    prixa = xa;
    priya = ya;
    //atribuicoes
    while(true){
        cin >> xb >> yb;
        if(xb == 0 && yb == 0){//Se a ultima entrada cair em xb, yb
            rdist = dist(ultxa, ultya, prixa, priya);//distancia entre o ultimo ponto entrado e o primeiro
            total += rdist;
            break;
        }
        else{
            ultxb = xb;
            ultyb = yb;
            rdist = dist(xa, ya, xb, yb);
            total += rdist;
        }
        cin >> xa >> ya;
        if(xa == 0 && ya == 0){ //Se a ultima entrada cair em xa, ya
            rdist = dist(ultxb, ultyb, prixa, priya);
            total += rdist;
            break;
        }
        else{
            ultxa = xa;
            ultya = ya;
            rdist = dist(xa, ya, xb, yb);
            total += rdist;
        }
    }
    //ouput
    cout << fixed << setprecision(2);
    cout << total << endl;

    return 0;
}