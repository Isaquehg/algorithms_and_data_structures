#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int vet[100];
    int n;//qtidade a inserir
    int maiores;//valores maiores q a media
    double media = 0.0;//media aritimetica
    int x;//contador

    cin >> n;

    //input e media
    for(x = 0; x < n; x ++){
        cin >> vet[x];
        media += vet[x];
    }
    media = media / (double)(n);
    cout << fixed << setprecision(2) << "Media: " << media << endl;
    //verificar quais valores sao acima da media
    cout << "Maiores que a media: ";
    for(x = 0; x < n; x ++){
        if(vet[x] > media)
            cout << vet[x] << " ";
    }

    return 0;
}