#include <iostream>

using namespace std;




int main (void)
{
    int soma_digits;
    cin >> soma_digits;
    int init;
    cin >> init;
    int end;
    cin >> end;
    //Termina a entrada

    int results = 0;
    for (int i = init; i <= end; i++)
    {
        string ver = to_string(i);
        int poss_result = 0;
        for (int j = 0; j < ver.size(); j ++)
        {
            poss_result += ver[j] - '0';
        }

        if (poss_result == soma_digits)
        {
            results ++;
        }
    }

    cout << results;

    return 0;
}