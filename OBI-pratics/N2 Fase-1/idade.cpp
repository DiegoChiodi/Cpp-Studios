#include <iostream>
using namespace std;

int val_1, val_2, val_3;

int main(void)
{
    cin >> val_1 >> val_2 >> val_3;
    if ((val_1 >= val_2 && val_1 <= val_3) or (val_1 <= val_2 && val_1 >= val_3))
    {
        cout << val_1;
    } else if ((val_2 > val_1 && val_2 < val_3) or (val_2 < val_1 && val_2 > val_3))
    {
        cout << val_2;
    } else {
        cout << val_3;
    }
    return 0;
}