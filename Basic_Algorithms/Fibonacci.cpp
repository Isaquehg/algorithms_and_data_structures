#include <iostream>

using namespace std;

int main(){
    int n1=0, n2=1, n3=1, i, num;

    cin >> num;    
    
    for (i=1; i<num; i++){
        if (i==1){
            cout << 0 << endl;
        }
        else if (i == 2){
            cout << 1 << "\n" << 1 << endl;
        }
        else{
            cout << n3 << endl;
        }
        n3 = n1+n2;
        n1=n2;
        n2=n3;
    }

    return 0;  
}