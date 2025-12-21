#include <iostream>

using namespace std;

struct var {
    string name;
    int valor;
};

using namespace std;
int main(void) {
    
    int lin, col ;

    cin >> lin >> col;

    var dif_var[lin * col];

    lin ++, col++;
    var matriz[lin][col];



    for (int i = 0; i < lin; i ++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == lin - 1 && j == col - 1)
            {
                break;
            } else if (i == lin - 1) {
                cin >> matriz[i][j].valor;
            } else if (j == col - 1)
            {
                cin >> matriz[i][j].valor;
            } else {
                cin >> matriz[i][j].name;
                bool is_dif = true;
                for (int k = 0; k < (i - 1) * (j - 1); k++)
                {
                    if (dif_var[k].name == matriz[i][j].name)
                    {
                        is_dif = false;
                        break
                    } else if (dif_var[k].name == '\0')
                    {
                        is_dif = false;
                        break;
                    }
                }
            }
        }
    }


       
    return 0;
}