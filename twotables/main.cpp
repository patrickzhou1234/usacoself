// https://codeforces.com/contest/1555/submission/223747359
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int t, i, W, H, x1, x2, y1, y2, w, h, mxW, mxH, mnW, mnH, ct, mnChange = MAX_INT;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        cin >> W >> H >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;
        ct = 0;
        mxW = max(W - x2, x1);
        mxH = max(H - y2, y1);
        mnW = min(x1, W - x2);
        mnH = min(y1, H - y2);
        if (mxH >= h || mxW >= w)
        {
            ct = 0;
        }
        else if (w - mxW <= mnW && (w - mxW <= h - mxH || h - mxH > mnH))
        {
            ct = w - mxW;
        }
        else if (h - mxH <= mnH && (h - mxH <= w - mxW || w - mxW > mnW))
        {
            ct = h - mxH;
        }
        else
        {
            ct = -1;
        }
        cout << ct << "\n";
    }
    system("pause");
    return 0;
}