// link to problem
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, i, j, tmp;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    int lList[k];
    vector<vector<int>> mList;
    for (i = 0; i < k; i++)
    {
        cin >> lList[i];
        for (j = 0; j < lList[i]; j++)
        {
            cin >> tmp;
            mList[i].push_back(tmp);
        }
    }
    system("pause");
    return 0;
}