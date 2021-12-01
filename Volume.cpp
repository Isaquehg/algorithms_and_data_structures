#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double volume(int r){
    double v;
    v = (4.0 / 3.0) * 3.14 * pow(r, 3);
    return v;
}
int main(){
    int raio;//raio da esfera
    double vol;//volume da esfera

    //input
    cin >> raio;
    //atribuição da fun p um var
    vol = volume(raio);
    //output
    cout << fixed << setprecision(2);
    cout << vol << endl;

    return 0;
}