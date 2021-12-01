#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    string nome;//nome cliente
    string city;//cidade cliente
    int cod;//codigo do produto
    int idade;//idade cliente   
    double preco;//preço produto
    double pag;//pagamento cliente
    double troco;//troco compra

    //definir o produto
    cin >> cod;
    switch(cod){
        case 1:
            cout << "Queijo" << endl;
            break;
        case 2:
            cout << "Geleia" << endl;
            break;
        case 3:
            cout << "Doce" << endl;
            break;
        case 4:
            cout << "Refrigerante" << endl;
            break;
        case 5:
            cout << "Sorvete" << endl;
            break;
        case 6:
            cout << "Presunto cru" << endl;
            break;
        case 7:
            cout << "Vinho" << endl;
    }

    //receber preco, nome, cidade, idade e pagamento e calcular total e troco
    cin >> preco;
    cin.ignore();
    getline(cin, nome);
    getline(cin, city);
    cin >> idade >> pag;

    //output total
    cout << fixed << setprecision(2);
    cout << "Valor total = " << preco << endl;
    
    //output troco
    troco = pag - preco;
    cout << "Troco = " << troco*1.00 << endl;

    return 0;
}