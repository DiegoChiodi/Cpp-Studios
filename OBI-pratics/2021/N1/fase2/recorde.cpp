#include <iostream>

using namespace std;

int main(void)
{
    int pro_res, mun_res, oli_res;

    cin >> pro_res >> mun_res >> oli_res;

    
    if (pro_res < mun_res)
    {
        cout << "RM" << endl;
    } else {
        cout << '*' << endl;
    }
    
    if (pro_res < oli_res)
    {
        cout << "RO" << endl;
    } else {
        cout << '*';
    }


    return 0;
}