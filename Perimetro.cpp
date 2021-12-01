#include <iostream>
#include <math.h>

using namespace std;

float dist(int XA, int YA, int XB, int YB){
	float distancia;
	
	distancia = sqrt((XB-XA)^2 + (YB-YA)^2);
    distancia *= 4.0;
	
	return distancia;
}

int main()
{
	int xa, ya, xb, yb;
    int xa0, ya0;
	
	float result, perimetro = 0;
	
	cin >> xa >> ya;
    xa0 = xa;
    ya0 = ya;
	cin >> xb >> yb;
	
	while(xa != 0 && ya != 0){
		result = dist(xa, ya, xb, yb);
		
		cout << result << endl;
		
		cin >> xa >> ya;
		cin >> xb >> yb;
		
		perimetro = perimetro + result;
				
	}
	
	cout << perimetro << endl;
    
    return 0;
}