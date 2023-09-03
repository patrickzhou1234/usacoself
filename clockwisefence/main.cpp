// http://www.usaco.org/index.php?page=viewproblem2&cpid=1109
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int countSubstring(const std::string &str, const std::string &sub)
{
    if (sub.length() == 0)
        return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
         offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}

int main()
{
    string cwpatterns[4] = {"NE", "WN", "SW", "ES"};
    string ccwpatterns[4] = {"NW", "EN", "WS", "SE"};
    int n, i, j;
    cin >> n;
    string a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    size_t pos = 0;
    int cwoccurrences, ccwoccurrences;
    for (i = 0; i < n; i++)
    {
        cwoccurrences = 0, ccwoccurrences = 0;
        for (j = 0; j < 4; j++)
        {
            cwoccurrences += countSubstring(a[i], cwpatterns[j]);
        }
        pos = 0;
        for (j = 0; j < 4; j++)
        {
            ccwoccurrences += countSubstring(a[i], ccwpatterns[j]);
        }
        if (cwoccurrences > ccwoccurrences)
            cout << "CW" << endl;
        else
            cout << "CCW" << endl;
    }
    system("pause");
    return 0;
}