#include<iostream>

using namespace std;

int main(){
    int a[100000];//array
    int n;//array size
    int lgap = 0;//largest gap between elements
    int aux;//counter

    cin >> n;
    //finding the greatest gap
    for(aux = 0; aux < n; aux ++){
        cin >> a[aux];
        if(a[aux] - a[aux - 1] > lgap){
            lgap = a[aux] - a[aux - 1];
        }
    }

    //output
    cout << lgap << endl;

    return 0;
}