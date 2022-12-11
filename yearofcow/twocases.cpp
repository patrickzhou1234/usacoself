// http://usaco.org/index.php?page=viewproblem2&cpid=1107
#include <iostream>
#include <vector>

using namespace std;

#define MAX_INT 2147483647

int main() {
    int n, i, j;
    cin >> n;
    string mat[n][8];
    string zod[] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    for (i=0;i<n;i++) {
        for (j=0;j<8;j++) {
            cin >> mat[i][j];
        }
    }
    bool next;
    int nextct=0, prevct=0, curyr=0;
    string curcow="Bessie", prevcow="";
    vector<string> blacklist;
    for (i=0;i<n;i++) {
        if (mat[i][3]=="previous") {
            next=false;
        } else {
            next=true;
        }
        if (curcow=="Elsie") {
            break;
        }
        if (mat[i][7]==curcow) {
            for (j=0;j<blacklist.size();j++) {
                if (blacklist[j]==mat[i][0]) {
                    i++;
                }
            }
            if (next) {
                for (j=curyr;j<12;j++) {
                    if (zod[j]!=mat[i][4]) {
                        nextct++;
                    } else {
                        curyr=j;
                        break;
                    }
                    if (j==11) {
                        j=-1;
                    }
                }
            } else {
                for (j=curyr;j>=0;j--) {
                    if (zod[j]!=mat[i][4]) {
                        prevct++;
                    } else {
                        curyr=j;
                        break;
                    }
                    if (j==0) {
                        j=12;
                    }
                }
            }
            prevcow=curcow;
            curcow=mat[i][0];
            i=-1;
        }
        if (i==n-1) {
            blacklist.push_back(curcow);
            curcow = prevcow;
            i=-1;
        }
    }
    cout << abs(prevct-nextct);
    system("pause");
    return 0;
}