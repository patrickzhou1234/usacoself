// link to problem
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int x, n, i, tmpl, mxRun = -1, prevL;
    cin >> x >> n;
    set<int> lights;
    vector<int> origLights, runs;
    lights.insert(0);
    for (i = 0; i < n; i++)
    {
        cin >> tmpl;
        origLights.push_back(tmpl);
        lights.insert(tmpl);
    }
    lights.insert(x);
    prevL = 0;
    for (int s : lights)
    {
        mxRun = max(mxRun, s - prevL);
        prevL = s;
    }
    auto it = lights.begin(), it2 = lights.begin();
    for (i = n - 1; i >= 0; i--)
    {
        runs.push_back(mxRun);
        it = lights.find(origLights[i]);
        if (it != lights.end())
        {
            it++;
            it2 = it;
            it--;
            it--;
            lights.erase(origLights[i]);
        }
        mxRun = max(mxRun, *it2 - *it);
    }
    for (i = n - 1; i >= 0; i--)
    {
        cout << runs[i] << " ";
    }
    return 0;
}