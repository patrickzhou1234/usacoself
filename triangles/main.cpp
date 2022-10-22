// http://usaco.org/index.php?page=viewproblem2&cpid=1011
#include <iostream>
#include <cmath>

using namespace std;

#define MAX_INT 2147483647

struct bestcoords {

};

struct coord {
    int x, y;
};

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n,i,j,m;
    double a,b,c,s, area, mxarea=-1;
    cin >> n;
    coord fencepost[n];
    for (i=0;i<n;i++) {
        cin >> fencepost[i].x >> fencepost[i].y;
    }
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            for (m=0;m<n;m++) {
                if (i!=j && j!=m) {
                    a = sqrt(pow(abs(fencepost[i].x-fencepost[j].x),2)+pow(abs(fencepost[i].y-fencepost[j].y),2));
                    b = sqrt(pow(abs(fencepost[j].x-fencepost[m].x),2)+pow(abs(fencepost[j].y-fencepost[m].y),2));
                    c = sqrt(pow(abs(fencepost[i].x-fencepost[m].x),2)+pow(abs(fencepost[i].y-fencepost[m].y),2));
                    s=(a+b+c)/2;
                    area = sqrt(s*(s-a)*(s-b)*(s-c));
                    mxarea = max(area, mxarea);
                }
            }
        }
    }
    cout << (int)(mxarea*2);
    system("pause");
    return 0;
}