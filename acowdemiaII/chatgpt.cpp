#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int K, N;
    cin >> K >> N;

    vector<string> names(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> names[i];
    }

    vector<vector<string>> publications(K, vector<string>(N));
    for (int i = 0; i < K; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> publications[i][j];
        }
    }

    vector<vector<char>> seniority(N, vector<char>(N, '?'));
    for (int i = 0; i < N; ++i)
    {
        seniority[i][i] = 'B';
    }

    for (const auto &publication : publications)
    {
        unordered_map<string, int> effort;
        int current_effort = N;
        for (int i = 0; i < N; ++i)
        {
            if (i > 0 && publication[i] > publication[i - 1])
            {
                current_effort--;
            }
            effort[publication[i]] = current_effort;
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (i != j)
                {
                    if (effort[names[i]] < effort[names[j]])
                    {
                        if (seniority[i][j] == '1' || seniority[j][i] == '0')
                        {
                            seniority[i][j] = seniority[j][i] = '?';
                        }
                        else
                        {
                            seniority[i][j] = '0';
                            seniority[j][i] = '1';
                        }
                    }
                    else if (effort[names[i]] == effort[names[j]])
                    {
                        seniority[i][j] = seniority[j][i] = '?';
                    }
                }
            }
        }
    }

    for (const auto &row : seniority)
    {
        for (char c : row)
        {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
