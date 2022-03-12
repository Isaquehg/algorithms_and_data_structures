#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double raiz(float x, float xo, double e){
    if(abs(pow(xo, 2) - x) <= e)
        return xo;
    else
        return raiz(x, (pow(xo, 2) + x)/(2 * xo), e);
}

int main(){
    float n, no;//numero a realizar raiz e estimativa
    double e;//lim superior
    double result;//resultado da raiz

    //input
    cin >> n >> no >> e;
    
    //calculo da raiz
    result = raiz(n, no, e);

    //output
    cout << fixed << setprecision(4);
    cout << result << endl;

    return 0;
}