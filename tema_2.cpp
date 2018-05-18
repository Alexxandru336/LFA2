#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int dublura (char*v,int n,int a)
{
    for (int i=0;i<n;i++)
        if(v[i]==a)
        return 1;
    return 0;
}

int search (char m,char *a,int n)
{
    for(int i=0; i<n; i++)
        if(m==a[i]) return 1;
    return 0;
}

class vec
{
    int n=0;
    char *a;
public:
    vec()
    {
        n=0;
    }
    void copiaza(int e,char *f)
    {
        a=new char[e];
        for(int i=0; i<e; i++)
            a[i]=f[i];
        n=e;
    }
    int compara(char *v,int n) /// comparra 2 vectori de aceeasi dimensiune daca au aceleasi elemente in orice ordine
    {
        int gasit=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                if(v[i]==a[j]) gasit=1;
            if(!gasit)  return 0;
            gasit=0;
        }
        return 1;
    }
    void afiseaza()
    {
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
    }
    int search (char m)
    {
        for(int i=0; i<n; i++)
            if(m==a[i]) return 1;
        return 0;
    }
    getn()
    {
        return n;
    }


};

int main()
{
    int nrmuchii,i,j,solutie=1,k,l,iaux=0,inou=1,y=0,w=1,h,gasit=0;
    char muchii[100][100],finale[100],alfabet[100],aux[100];
    ifstream fin("date.in");
    fin>>nrmuchii;  /// citeste cate muchii sunt
    fin.get();
    fin.get(alfabet,100); /// citeste alfabetul
    fin.get();

    for(i=0; i<nrmuchii; i++) /// citeste muchile ( stare,stare,litera alfabet(sau string) ) lambda este cuvant rezervat si semnifica lambda
    {
        for(j=0; j<3; j++)
            fin>>muchii[i][j];
    }
    fin.get();
    fin.get(finale,100);
    fin.get();

    ///partea grea

    vec AFD[100][100],nou[100];
    AFD[0][0].copiaza(1,muchii[0]);
    nou[0].copiaza(1,muchii[0]);
    while(AFD[y][0].getn())
    {

        for(int k=0; k<strlen(alfabet); k++)
        {
            ///AFD[0][k]
            for(i=0; i<nrmuchii; i++)
            {
                if(muchii[i][2]==alfabet[k])
                {
                    if(AFD[y][0].search(muchii[i][0]))
                    {
                        if(!dublura(aux,iaux,muchii[i][1]))
                        {
                            aux[iaux]=muchii[i][1];
                            iaux++;
                        }
                    }

                }
            }
            AFD[y][k+1].copiaza(iaux,aux);

            for (int z=0; z<inou; z++)
            {
                if(nou[z].getn() == iaux)
                {
                    if(nou[z].compara(aux,iaux))
                    {
                        gasit=1;
                        z=inou;
                    }
                }
            }
            if(!gasit)
            {
                nou[inou].copiaza(iaux,aux);
                inou++;
                AFD[w][0].copiaza(iaux,aux);
                w++;
            }
            gasit=0;
            iaux=0;
        }
        y++;

    }
    for(int i=0; i<=y-1; i++)
    {
        for(j=0; j<strlen(alfabet)+1; j++)
        {
            if(AFD[i][j].getn())
                AFD[i][j].afiseaza();
            if(AFD[i][j].getn() == 0)
                cout<<"nu";
            cout<<"/";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Noduri finale:"<<endl;
    for(int i=0;i<strlen(finale);i++)
    {
            for(j=0;j<y;j++)
                if(AFD[j][0].search(finale[i]))
                    AFD[j][0].afiseaza(),cout<<endl;
    }

}
