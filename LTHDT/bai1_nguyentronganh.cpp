#include <iostream>

using namespace std;

int DEMCHUSO(int n)
{
    if (n < 10)
    {
        return 1;
    }
    else
        return DEMCHUSO(n / 10) + 1;
}
int main()
{
    int n;
    cout << "nhpa so nguyen duong n: ";
    cin >> n;
    cout << "so nguyen duong " << n << " co " << DEMCHUSO(n) << " chu so. " << endl;
}