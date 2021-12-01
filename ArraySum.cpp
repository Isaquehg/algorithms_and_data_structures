#include<iostream>

using namespace std;

int main(){
    int a[1000];//array to store the values
    int largest = -10000;//the largest array´s numbers
    int sum = 0;//the array´s sum of values
    int n;//numbers to enter
    int aux;//counter

    cin >> n;

    //entering n array values and adding to sum
    for(aux = 0; aux < n; aux ++){
        cin >> a[aux];
        sum += a[aux];
        //if the number is the largest
        if(a[aux] > largest){
            largest = a[aux];
        }
    }
    //output(division between sum and the largest)
    cout << sum % largest << endl;

    return 0;
}