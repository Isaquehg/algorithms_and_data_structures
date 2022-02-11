#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    double ang_pos_men = 0.0, ang_pos_mai = 0.0, ang, expression, n1, n2; 
    //angulo positivo menor, angulo positivo maior, anguloθ e expressão sin*cos

    cin >> n1 >> n2;

    ang = n1;
    while(sin(ang)*cos(ang) <= 0.0){
        ang += 0.1;
    }
    ang_pos_men = ang;
    while(sin(ang)*cos(ang) > 0.0){
        ang += 0.1;
    }
    ang_pos_mai = ang - 0.1;

    cout << fixed << setprecision(1) << endl;
    cout << ang_pos_men << " a " << ang_pos_mai << endl;

    return 0;
}