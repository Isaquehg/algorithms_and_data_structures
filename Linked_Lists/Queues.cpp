#include <iostream>
#include <list>

using namespace std;
//QUEUES: Insertion is done behind
int main(){
    list<int> fila;//pointers
    int x;//element to insert
    //input and inserting
    for(int i = 0; i < 4; i ++){
        cin >> x;
        fila.push_back(x);//inserting x on back
    }
    //output e delete
    while(!fila.empty()){//while queue has elements
        cout << *fila.begin() << " ";//showing beginning
        fila.pop_front();//remove first item
    }

    return 0;
}