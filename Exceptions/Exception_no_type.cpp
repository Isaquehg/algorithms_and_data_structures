#include <iostream>

using namespace std;

int main(){
    try
    {
        int age = 5;
        if(age >= 18)
            cout << "Access granted" << endl;
        else
            throw 500;//some error number
    }
    catch(...){//when you don't know the data type to receive
        cout << "Error" << endl;
    }

    return 0;
}