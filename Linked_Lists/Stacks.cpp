#include <iostream>
#include <list>

using namespace std;
//STACKS: Insertion is done in front!(like a stack of books)
int main(){
    list<int> pilha;//pointers
    int x;//element to insert
    //input e inserindo na pilha
    for(int i = 0; i < 4; i ++){
        cin >> x;
        pilha.push_front(x);//inserting x on front
    }
    //output e delete
    while(!pilha.empty()){//enquanto pilha nao estiver vazia
        cout << *pilha.begin() << " ";//showing beginning
        pilha.pop_front();//remove first item
    }

    return 0;
}