#include <iostream>

using namespace std;

int main (void) 
{
    int n;
    cin >> n;
    
    int freq[100001] = {0};

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }
    int freq_num = 0;
    int best_num = 0;
    for (int i = 0; i < 100001; i++)
    {
        if (freq[i] > freq_num || (i < best_num && freq[i] == freq_num))
        {
            freq_num = freq[i];
            best_num = i;
        }
    }

    cout << freq_num << ' ' << best_num;


    return 0;
}