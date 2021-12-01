#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct dados{
    double lat;//latitude
    double longi;//longitude
    double elev;//altitude/elevação
    double disdis;//distancia ponto a ponto p achar vmax
    int hr;//horas
    int min;//minutos
    int seg;//segundo
};
static double haversine(double lat1, double lon1, double lat2, double lon2){
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    //converter em radianos
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;
    //aplicação da formula
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}
int main(){
    dados info[100];//dados do atleta
    int x = 0;//contador
    int n;//total de entradas completas
    double dis[100];//distancia percorrida ponto a ponto(km)
    double tdis = 0.0;//distancia total(km/h)
    int thr, tmin, tseg;//tempo total(h,min,s)
    double vmax = 0.0;//vel maxima (km/h)
    double vmedia;//velocidade media (km/h)
    double gelev = 0.0;//ganho de elevação (m)
    double pelev = 0.0;//perda de elevação (m)
    double maalt = 0.0;//maior elevação (m)
    double mealt = 100000.0;//menor elevação (m)
    double thoras;//tempo total em horas

    //input inicial
    cin >> info[x].lat >> info[x].longi >> info[x].elev >> info[x].hr >> info[x].min >> info[x].seg;
    //entrada de todos valores
    while((info[x].lat != -1) && (info[x].longi != -1) && (info[x].elev != -1) && (info[x].hr != -1) && (info[x].min != -1) && (info[x].seg != -1)){
        x ++;
        cin >> info[x].lat >> info[x].longi >> info[x].elev >> info[x].hr >> info[x].min >> info[x].seg;
    }
    n = x - 1;//numero de entradas
    //calculando distanca percorrida
    for(x = 1; x <= n; x ++){
        dis[x] = haversine(info[n].lat, info[n].longi, info[n - 1].lat, info[n - 1].longi);
        tdis += dis[x];
    }
    //calculando tempo decorrido
    thr = info[n].hr - info[0].hr;
    tmin = info[n].min - info[0].min;
    tseg = info[n].seg - info[0].seg;
    //convertendo tudo p segundos
    while(thr > 0){
        tseg += 3600;
        thr --;
    }
    while(tmin > 0){
        tseg += 60;
        tmin --;
    }
    thoras = tseg / 3600.0;//tempo total em horas
    //calculando velocidades maxima e media
    vmedia = tdis / thoras;
    for(x = 0; x < n; x ++){
        if(x > 0){//desconsiderando primeira entrada
            info[x].disdis = haversine(info[x].lat, info[x].longi, info[x - 1].lat, info[x - 1].longi);
            if(info[x].disdis / ((info[x].seg / 3600.0) - (info[x - 1].seg / 3600.0)) > vmax)
                vmax = info[x].disdis / ((info[x].seg / 3600.0) - (info[x - 1].seg / 3600.0));
        }
    }
    //calculando ganho e perda de elevação
    for(x = 0; x < n; x ++){
        if(x > 0){    
            if(info[x].elev - info[x - 1].elev >= 0)
                gelev += (info[x].elev - info[x - 1].elev);
            else
                pelev += (info[x].elev - info[x - 1].elev);
        }
    }
    //calculando maior e menor altitude
    for(x = 0; x < n; x ++){
        if(info[x].elev > maalt)
            maalt = info[x].elev;
        else if(info[x].elev < mealt)
            mealt = info[x].elev;
    }
    //output
    cout << fixed << setprecision(2);
    cout << "Distancia total***: " << tdis << " km" << endl;
    cout << "Tempo total decorrido: " << thr << ":" << tmin << ":" << tseg << endl;
    cout << "Velocidade maxima: " << vmax << " km/h" << endl;
    cout << "Velocidade media***: " << vmedia << " km/h" << endl;
    cout << "Ganho de elevacao***: " << gelev << " m" << endl;
    cout << "Perda de elevacao: " << pelev << " m" << endl;
    cout << "Maior altitude: " << maalt << " m" << endl;
    cout << "Menor altitude: " << mealt << " m" << endl;

    return 0;
}