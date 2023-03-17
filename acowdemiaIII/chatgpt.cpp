#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> pasture(N);
    for (int i = 0; i < N; i++)
    {
        cin >> pasture[i];
    }

    int friends = 0;
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < M; col++)
        {
            if (pasture[row][col] == 'C')
            {
                vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
                for (const auto &dir : directions)
                {
                    int nr = row + dir.first;
                    int nc = col + dir.second;

                    if (nr >= 0 && nr < N && nc >= 0 && nc < M && pasture[nr][nc] == 'G')
                    {
                        int nnr = nr + dir.first;
                        int nnc = nc + dir.second;

                        if (nnr >= 0 && nnr < N && nnc >= 0 && nnc < M && pasture[nnr][nnc] == 'C')
                        {
                            friends++;
                            pasture[nr][nc] = '.';
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << friends << endl;
    return 0;
}
