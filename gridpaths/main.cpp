// https://cses.fi/problemset/task/1625 unfinished

#include <iostream>

using namespace std;

int main() {
    int xpos=0,ypos=0,i;
    string line, secondline;
    cin >> line;
    secondline = line;
    for (i=0;i<secondline.length();i++) {
        if (line[i] == '?') {
            secondline[i] = 'a';
        }
    }
    system("pause");
    return 0;
}