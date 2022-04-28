#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i < 36; i++)
    {
        if (100 - 2 * i - (36 - i) * 4 == 0)
        {
            cout << "so ga la : " << i << endl;
            cout << "so cho la : " << 36 - i << endl;
        }
    }
    return 0;
}