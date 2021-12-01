#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream arq;//declarando var (inputfile)
    int x;

    arq.open("texto.txt",ifstream::in);
    arq >> x;

    cout << "X = " << x << endl;

    arq.close();

    return 0;
}