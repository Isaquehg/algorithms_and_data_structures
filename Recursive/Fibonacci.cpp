#include <iostream>

using namespace std;

int fibonacci(int n){
    if(n == 0 || n == 1)
        return 1;
    else
        return (fibonacci(n - 1)) + (fibonacci(n - 2));
}

int main(){
    int num;//entrada
    int result;//resultado

    //input
    cout << "Helloooo" << endl;
    cout << "B" << endl;
    cin >> num;

    //calculo fibonacci
    result = fibonacci(num);

    //output
    cout << result << endl;

    return 0;
}