#include <iostream>
#include<cstring>

using namespace std;

int main(){
    char nome[20];
    int x;

    cin.getline(nome,20);

    cout <<"Prazer " << nome << endl;

    x = strlen(nome);
    cout << x << endl;

    char nome3[10];
    char nome4[10];

    strcpy(nome3, "Larry");
    strcpy(nome4, "Darry");

    cout << strcmp(nome3, nome4) << endl;
    cout << strcmp(nome4, nome3) << endl;

    return 0;
}
//strcpy(nome, "str") -- string copy
//x = strlen(nome) -- string lenght
//strcmp(var1, var2) -- binary string comparison / 
//strcmp > 0 - word one is longer than second
//strcmp < 0 - word one is shorter
//else, both are equal
//x = strtok(str,) -- string split
//x = strlwr(nome) -- string lower
//x = strupr(nome) -- string upper
//strlen(nome) -- returns the number of spaces used in this char
//strcat(nome, nome2) -- returns the concatuation of this strings