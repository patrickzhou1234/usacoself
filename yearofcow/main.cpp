// http://usaco.org/index.php?page=viewproblem2&cpid=1107
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

/*
string cow_name[N];
int cow_age[N];
int cow_year[N];

cow_name[0] = "Bessie";
cow_age[0] = 0;
cow_year[0] = 0;

for each line:
	find cow_from (the one at the end) 
    distance : this cow and from
    if (before) cow_name[cntr]=new_cow, cow_age[]=
    if (next)

      
======

search for cow_name == Elsie;

*/

int main() {
    int n, i, j;
    cin >> n;
    string zod[] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    string cow_name[n+1];
    int cow_age[n+1];
    int cow_year[n+1];

    cow_name[0] = "Bessie";
    cow_age[0] = 0;
    cow_year[0] = 0;
    for (i=1;i<=n;i++) {
        string tmp;
        string cow_to, cow_from, year_sign, next;
        cin >> cow_to >> tmp >> tmp >> next >> year_sign >> tmp >> tmp >> cow_from;
        cow_name[i]=cow_to;
        for (j=0;j<12;j++) {
            if (zod[j]==year_sign) {
                cow_year[i]=j;
                break;
            }
        }
        int cow_from_ind;
        for (j=0;j<i;j++) {
            if (cow_name[j]==cow_from) {
                cow_from_ind=j;
                break;
            }
        }
        int diff;
        if (next=="next") {
            diff = cow_year[i]-cow_year[cow_from_ind];
            if (diff<=0) {
                diff+=12;
            }
            cow_age[i]=cow_age[cow_from_ind]+diff;
        } else {
            diff = cow_year[cow_from_ind]-cow_year[i];
            if (diff<=0) {
                diff+=12;
            }
            cow_age[i]=cow_age[cow_from_ind]-diff;
        }

    }
    for (i=0;i<n+1;i++) {
        if (cow_name[i]=="Elsie") {
            cout << abs(cow_age[i]);
        }
    }
    system("pause");
    return 0;
}