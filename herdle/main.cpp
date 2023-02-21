// http://www.usaco.org/index.php?page=viewproblem2&cpid=1179
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    char a[3][3], b[3][3];
    int i, j, m, cor = 0, incor = 0;
    bool checked[3][3] = {false};
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin >> b[i][j];
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (a[j][i] == b[j][i] && checked[j][i] == false)
            {
                cor++;
                checked[j][i] = true;
            }
            else
            {
                for (m = 0; m < 3; m++)
                {
                    if (a[j][i] == b[m][j] && checked[m][j] == false)
                    {
                        incor++;
                        checked[m][j] = true;
                        break;
                    }
                }
            }
        }
    }
    cout << cor << "\n"
         << incor << endl;
    system("pause");
    return 0;
}