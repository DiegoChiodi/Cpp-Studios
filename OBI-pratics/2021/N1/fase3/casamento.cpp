#include <iostream>

using namespace std;

int get_potencia (int base, int expo)
{
    int result = 1;
    for (int i = 0; i < expo; i++)
    {
        result *= base;
    }
    return result;
}


int main (void)
{
    string homem, mulher;

    cin >> homem >> mulher;

    bool homem_maior = (homem.size() > mulher.size());
    string* maior = (homem_maior) ? &homem : &mulher;
    string* menor = (homem_maior) ? &mulher : &homem;
    
    int dif = maior->size() - menor->size();

    int maior_cas = 0;
    int menor_cas = 0;

    for (int i = 0; i < maior->size() - 1; i++)
    {
        int expoente = maior->size() - 1 - i;

        if (i >= dif)
        {
            if (maior->at(i) > menor->at(i - dif))
            {
                maior_cas += maior->at(i) * get_potencia(10, expoente);
            } else if (maior->at(i) > menor->at(i - dif))
            {
                menor_cas += menor->at(i - dif) * get_potencia(10, expoente - dif);
            } else
            {
                maior_cas += maior->at(i) * get_potencia(10, expoente);
                menor_cas += menor->at(i - dif) * get_potencia(10, expoente - dif);
            }
            
        } else 
        {
            maior_cas += maior->at(i) * get_potencia(10, expoente);
        }
        cout << i;
    }

    cout << maior_cas << menor_cas << endl;



    


    return 0;
}