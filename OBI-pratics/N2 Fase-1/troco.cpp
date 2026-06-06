#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int valor_f, quant_moedas;

    cin >> valor_f >> quant_moedas;

    vector<int> moedas(quant_moedas);

    for (int i = 0; i < quant_moedas; i++)
    {
        cin >> moedas[i];
    }

    vector<bool> dp(valor_f + 1, false);
    dp[0] = true;

    for (int moeda : moedas)
    {
        for (int v = valor_f; v >= moeda; v--)
        {
            dp[v] = dp[v] || dp[v - moeda];
        }
    }

    cout << (dp[valor_f] ? "S" : "N");
    return 0;
}