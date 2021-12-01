#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double i, m, o, n, a, ne, ti, tf;

    cin >> i >> m >> o >> n >> a >> ne;
    cin >> ti;

    tf = ti - (i + m + o + n + a + ne);

    cout << fixed << setprecision(2) << endl;

    if (tf >= 0){
        cout << "Sobrou: R$ " << tf << endl;
    }
    else{
        cout << "Deve: R$ " << tf*(-1) << endl;
    }

    return 0;
}