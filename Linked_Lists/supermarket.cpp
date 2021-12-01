#include <iostream>
#include <list>

using namespace std;


int main(){
    int n;//numero de operacoes
    int op;//operacao a ser realizada
    int cod;//codigo do produto
    int x = 0;;//aux
    list<int> estoque;//lista p produtos em estoque(fila)
    list<int> vendas;//lista p produtos em vendas(pilha)
    list<int>::iterator p;//iterator
    //input de operacoes
    cin >> n;
    while(x != n){
        cin >> op;
        if(op == 1){//insere prod no estoque
            cin >> cod;
            estoque.push_back(cod);
        }
        else if(op == 2){//move do estoque p vendas
            estoque.pop_front();
            vendas.push_front(*estoque.begin());
        }
        x ++;
    }
    //mostrando valores de estoque e venda
    cout << "Estoque: ";
    for(p = estoque.begin(); p != estoque.end(); p ++){
        cout << *p << " ";
    }
    cout << endl;
    cout << "Vendas: ";
    for(p = vendas.begin(); p != vendas.end(); p ++){
        cout << *p << " ";
    }
    cout << endl;
    //desaloc memoria
    while(!estoque.empty()){
        estoque.pop_front();
    }
    while(!vendas.empty()){
        vendas.pop_front();
    }

    return 0;
}