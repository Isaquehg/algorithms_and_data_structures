#include <iostream>

using namespace std;

int main(){
    char op;//operacao
    int num1;//numero um
    int num2;//numero 2

    //input
    cin >> num1 >> num2;
    cin.ignore();
    cin >> op;

    //casos de operação
    switch(op){
        case '+':
            cout << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 - num2 << endl;
            break;
        case '/':
            if(num2 == 0)
                cout << "Impossivel" << endl;
            else   
                cout << num1 / num2 << endl;
            break;
        case '*':
            cout << num1 * num2 << endl;
    }

    return 0;
}