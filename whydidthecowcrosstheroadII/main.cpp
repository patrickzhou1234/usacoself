// http://www.usaco.org/index.php?page=viewproblem2&cpid=712
#include <iostream>
#include <unordered_set>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    int i, j, ct = 0;
    unordered_set<int> st;
    unordered_set<char> passed;
    string s;
    cin >> s;
    for (i = 0; i < s.length() - 1; i++)
    {
        if (passed.find(s[i]) != passed.end())
        {
            continue;
        }
        passed.insert(s[i]);
        for (j = i + 1; j < s.length(); j++)
        {
            if (s[j] == s[i])
            {
                break;
            }
            else if (st.find(s[j]) == st.end())
            {
                st.insert(s[j]);
            }
            else
            {
                st.erase(st.find(s[j]));
            }
        }
        ct += st.size();
        st.clear();
    }
    cout << ct / 2 << endl;
    system("pause");
    return 0;
}