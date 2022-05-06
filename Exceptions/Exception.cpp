#include <iostream>

using namespace std;

int main(){
    try
    {
        int age = 5;
        if(age >= 18)
            cout << "Access granted" << endl;
        else
            throw(age);//THROW function will throw the value to the CATCH function
    }
    catch(int age){
        cout << "Access denied. You're " << age << " years old" << endl;
    }
    

    return 0;
}