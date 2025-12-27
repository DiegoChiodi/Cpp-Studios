#include <iostream>

using namespace std;

int main(void)
{
    int  pos, disc, avi;

    cin >> pos >> disc >> avi;

    int result;
    if (disc >= avi)
    {
        result = disc - avi;
    } else {
        result = pos - avi + disc;
    }

    cout << result;
};