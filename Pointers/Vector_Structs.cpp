#include <iostream>

using namespace std;

struct info
{
    int SKU;
    float price;
};


int main(){
    info *prod;//struct
    int size;//size of struct
    int i;//aux

    //dinamic memory allocation
    cin >> size;
    prod = new info[size];
    //input SKU & Price
    for(i = 0; i < size; i ++){
        cin >> prod[i].SKU;
        cin >> prod[i].price;
    }
    //output
    for(i = 0; i < size; i ++){
        cout << prod[i].SKU << " ";
        cout << prod[i].price << " ";
    }

    delete [] prod;

    return 0;
}