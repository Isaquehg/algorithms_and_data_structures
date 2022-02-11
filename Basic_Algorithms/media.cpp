#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main() {
 
    double r;
    float n = 3.14159;
    float area;
    
    cin >> r;
    
    area = n*(r*r);
    
    cout << fixed << setprecision(4);
    cout << "A=" << area << endl;
    
    return 0;
}