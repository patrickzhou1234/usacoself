// https://cses.fi/problemset/task/1091
#include <iostream>
#include <set>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    bool fd;
    int n, m, i, tick, cust;
    cin >> n >> m;
    int customers[m];
    multiset<int> ticketset;
    for (i = 0; i < n; i++)
    {
        cin >> tick;
        ticketset.insert(tick);
    }
    for (i = 0; i < m; i++)
    {

        cin >> customers[i];
    }
    auto it = ticketset.begin();
    for (i = 0; i < m; i++)
    {
        it = ticketset.lower_bound(customers[i]);
        if (it == ticketset.end())
        {
            cout << -1 << endl;
            continue;
        }
        fd = true;
        cust = customers[i];
        while (*it > customers[i])
        {
            it = lower_bound(ticketset.begin(), ticketset.end(), cust);
            cust--;
            if (it == ticketset.begin() && *it > customers[i])
            {
                fd = false;
                break;
            }
        }
        if (!fd)
        {
            cout << -1 << endl;
            continue;
        }
        cout << *it << endl;
        ticketset.erase(ticketset.find(*it));
    }
    return 0;
}