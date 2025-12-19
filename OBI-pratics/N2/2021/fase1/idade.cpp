#include <iostream>

using namespace std;

bool get_meio(const int ver, const int border_1, const int border_2)
{
    if ((ver < border_1 && ver > border_2) || (ver > border_1 && ver < border_2))
    {
        return true;
    }
    return false;
}
int main(void)
{
    int a, b, c;

    cin >> a >> b >> c;

    if (get_meio(a,b,c))
    {
        cout << a;
    } else if (get_meio(b,c,a)) {
        cout << b;
    } else {
        cout << c;
    }
    

    return 0;
}