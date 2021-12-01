#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> list1;//lista  unir
    list<int> list2;//lista a unir
    list<int> list3;//uniao
    list<int>::iterator p;//iterator 1
    list<int>::iterator q;//iterator 2
    int x;//aux
    int num;//numero a inserir

    cin >> x;
    while(x != 0){
        num = x;
        list1.push_back(num);
        cin >> x;
    }
    cin >> x;
    while(x != 0){
        num = x;
        list2.push_back(num);
        cin >> x;
    }
    for(p = list1.begin(); p != list1.end(); p ++){
        
    }


    //desalocando mem
    while(!list1.empty()){//while queue has elements
        cout << *list1.begin() << " ";//showing beginning
        list1.pop_front();//remove first item
    }
    while(!list2.empty()){//while queue has elements
        cout << *list2.begin() << " ";//showing beginning
        list2.pop_front();//remove first item
    }
    while(!list3.empty()){//while queue has elements
        cout << *list3.begin() << " ";//showing beginning
        list3.pop_front();//remove first item
    }

    return 0;
}