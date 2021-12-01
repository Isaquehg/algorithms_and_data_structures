#include <iostream>
using namespace std;

int main()
{
    int n;//number of rows
    int x, y;//counters
    
    cin >> n;
    
    for(x = 1; x <= n; x ++){
        for(y = 1; y <= x; y ++){
            if(y == x)
                cout << y;
            else
                cout << y << " ";
        }
        cout << "\n";
    }

}