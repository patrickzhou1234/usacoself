// link to problem
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int i, j = 0;
    a = 'G' + a + 'G';
    b = 'G' + b + 'G';
    for (i = 0; i < a.length() - 1; i++)
    {
        if (a[i] != b[i] && a[i + 1] == b[i + 1])
        {
            j++;
        }
    }
    cout << j;
    system("pause");
    return 0;
}
/*
G
G
*/