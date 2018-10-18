// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Corrida de Regularidade
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2503

#include<bits/stdc++.h>

using namespace std;

struct corrida{
    int pts, id;
};

bool ordena(corrida x, corrida y){
    if(x.pts != y.pts) return x.pts < y.pts;
    return x.id < y.id;
}
int main(){
    int vel, pontos, times;
    while(cin >> vel >> pontos >> times){
        if(vel==0 && pontos==0 && times==0) break;
        struct corrida x[times];
        double aux = (double)vel/3.6;
        int vet_pontos[pontos], tempo_pontos[pontos];
        for(int i=0;i<pontos;i++) cin >> vet_pontos[i];
        int ans=0;
        for(int i=0;i<times;i++){
            for(int j=0;j<pontos;j++){
                int ideal, ans1;
                ideal=(float(vet_pontos[j]/aux));
                cin >> tempo_pontos[j];
                if(ideal > tempo_pontos[j]){
                    ans1=ideal-tempo_pontos[j];
                    ans1=ans1*2;
                }else{
                    ans1=tempo_pontos[j]-ideal;
                }
                ans1 = min(ans1, 1200);
                ans+=ans1;
            }
            x[i].pts=ans;
            //printf("Time %d = %d\n",i+1,x[i].pts);
            ans=0;
            x[i].id=i+1;
        }
        sort(x,x+times,ordena);
        for(int i=0;i<times;i++){
            if(i != times-1) printf("%d ",x[i].id);
            else printf("%d\n",x[i].id);
        }
    }
    return 0;
}

