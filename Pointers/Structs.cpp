#include <iostream>

using namespace std;

struct info
{
    int SKU;
    float price;
};

int main(){
    info *prod;

    prod = new info;

    prod->SKU = 0001;
    prod->price = 251.7;

    cout << "SKU: " << prod->SKU << endl;
    cout << "Price: " << prod->price << endl;

    delete prod;

    return 0;
}