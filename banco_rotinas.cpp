
#include<iostream>
#include<cstdlib>
#include<vector>
#include<time.h>
using namespace std;

struct Produto
{
    string descricao;
    float estoqute;
    float preco;
};

struct Registro 
{
    int k;     //Chave
    Produto r; //Registro
};

vector<Registro>rotina_gera_registros(vector<int> vetor_chaves,int tam)
{
    
    Registro r;
    Produto p;
    vector<Registro> vetor_registro;
    int num_rand;

    for(int i=0; i<tam; ++i){
        num_rand = rand() % 100;
        p.descricao = "produto cadastrado!";

        int num_rand_e = rand() % 100;
        p.estoqute = num_rand_e;

        int num_rand_p = rand() % 100;
        p.preco = num_rand_p;

        r.r = p;
        r.k = vetor_chaves[i];
        vetor_registro.push_back(r);
    }
    
    return vetor_registro;
}

bool chave_existe(vector<int> vetor_chaves, int chave, int tam)
{
    
    for(int i=0; i<tam; ++i)
    {
        if(vetor_chaves[i] == chave)
        {
            return true;
        } 
    }
    return false;
}

vector<int>rotina_gera_chaves(int n_key, int key_range)
{
    srand(time(NULL));
    int num_rand;
    vector<int> vetor_chaves;
    
    for(int i=0; i<=n_key; ++i)
    {
        num_rand = rand() % key_range;

        if(!chave_existe(vetor_chaves,num_rand, i))     
        {
            vetor_chaves.push_back(num_rand);                         
        } 
        if(chave_existe(vetor_chaves,num_rand, i))
            --i;
    }

    return vetor_chaves;
}

void ordenacao_bubble(vector<Registro>& x)
{
    Registro k;    

    int i, j, aux;
    bool troca = true;
    int N = x.size();
    for (i = 0; i < N - 1 && troca; ++i)
    {
        troca = false;
        for (j = 0; j < N - i - 1; ++j)
        {
            if (x[j].k > x[j + 1].k)
            {
                troca = true;
                aux = x[j].k;
                x[j].k = x[j + 1].k;
                x[j + 1].k = aux; 
            }
        }
    }
    for (int i = 0; i < x.size(); i++)
        cout << x[i].k << " ";

    cout << endl;
}

int buscaSequencial(int c, vector<Registro>& x)
{
    int N = x.size();
    int i = 0, res = -1;

    while (i < N && x[i].k <= c)  
    {
        if (c == x[i].k)
        {
            res = i;
            break;
        }
        i++;
    }
    cout << endl << "Fiz " << i + 1 << " comparacoes!" << endl;
    return res;
}


int main()
{
    int user_n_Key;
    int user_Key_range;
    int user_busca;
    
    while(true)
    {
        cout << "Digite o valor de n_Key: ";
        cin  >> user_n_Key;
        cout << "Digite o valor de Key_range: ";
        cin  >> user_Key_range;
        cout << "Digite o valor de busca: ";
        cin  >> user_busca;

        if(user_n_Key < user_Key_range)
            break; 

        else{
            cout << "----------digite novamente----------" << endl;
        }
        
    }

    vector<int> vetor_chaves;
    vector<Registro> vetor_registro;

    vetor_chaves = rotina_gera_chaves(user_n_Key, user_Key_range);
    vetor_registro = rotina_gera_registros(vetor_chaves,user_n_Key);
    
    ordenacao_bubble(vetor_registro);
    
    int resp_busca;
    resp_busca = buscaSequencial(user_busca , vetor_registro);

    float precoA  = vetor_registro[resp_busca].r.preco;
    float estoqueA = vetor_registro[resp_busca].r.estoqute;
    string descricaoA = vetor_registro[resp_busca].r.descricao;

    if(user_busca == vetor_registro[resp_busca].k )
    {
        cout << "O preço do produto: " << precoA << endl;
        cout << "Quantidade em estoque: " << estoqueA << endl;
        cout << "Status: " << descricaoA << endl;
    }

    else{     
        cout << "O preço do produto: 0   " << endl;
        cout << "Quantidade em estoque: 0" << endl;
        cout << "Status: Não cadastrado! " << endl;
    }
    return 0;
}