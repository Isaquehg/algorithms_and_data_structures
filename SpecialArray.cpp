#include<iostream>

using namespace std;

int main(){
    int a[100];//given array
    int n;//array size
    int aux;//counter
    int nonnat = 0;//non natural numbers

    cin >> n;
    for(aux = 0; aux < n; aux ++){//array input
        cin >> a[aux];
        if(a[aux] <= 0){//if there are non natural numbers
            nonnat ++;
        }
    }
    //output
    if(nonnat > 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    return 0;
}