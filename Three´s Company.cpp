#include <iostream>

using namespace std;

int main(){
    char word[20];//word to be inserted
    int n;//number of letters
    int x;//counter

    cin >> n;
    cin.ignore();
    cin.getline(word, 20);

    for(x = 0; x < n; x ++){
        cout << word[x] << word[x] << word[x];
    }

    return 0;
}