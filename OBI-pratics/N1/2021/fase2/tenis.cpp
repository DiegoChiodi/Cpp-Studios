#include <iostream>

using namespace std;

int main(void)
{
    int a;
    int b;
    int c;
    int d;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;

    int time1 = a + d;
    int time2= b + c;

    int result = time2 - time1;

    if (result < 0)
    {
        result *= -1;
    }

    cout << result;

    return 0;
}