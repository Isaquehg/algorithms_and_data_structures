#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double raiz(int x, int xo, double e){
    if(abs(pow(xo, 2) - x) <= e)
        return sqrt(x);
    else
        return raiz(x, (pow(xo, 2) + x)/(2 * xo), e);
}

int main(){
    int n, no;//numero a realizar raiz e sua estimativa
    double e;//lim superior
    //input
    cin >> n >> no >> e;
    //output
    cout << fixed << setprecision(2);
    cout << raiz(n, no, e) << endl;

    return 0;
}