#include <bits/stdc++.h>

#define DIM 8

using namespace std;

const char rows[] = {'1', '2', '3', '4', '5', '6', '7', '8'};
const char cols[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

struct cell
{
    int row;
    int col;
    int dist;

    cell(int row, int col, int dist) : row(row), col(col), dist(dist) {}
};

inline bool inRange(int row, int col)
{
    return (row >= 0 && row < DIM) &&
           (col >= 0 && col < DIM);
}

int bfs(const cell& start, const cell& end)
{
    int dr[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dc[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    bool visited[DIM][DIM];
    queue<cell> q;

    for (int i = 0; i < DIM; ++i)
        for (int j = 0; j < DIM; ++j)
            visited[i][j] = false;

    visited[start.row][start.col] = true;
    q.push(start);

    while (!q.empty())
    {
        cell temp = q.front();
        q.pop();

        if (temp.row == end.row && temp.col == end.col)
            return temp.dist;

        for (int i = 0; i < 8; ++i)
        {
            int row = temp.row + dr[i];
            int col = temp.col + dc[i];

            if (inRange(row, col) && !visited[row][col])
            {
                visited[row][col] = true;
                q.push(cell(row, col, temp.dist + 1));
            }
        }
    }

    return -1;
}

cell parse(const string& coordinates)
{
    int row = distance(rows, find(rows, rows + DIM, coordinates[1]));
    int col = distance(cols, find(cols, cols + DIM, coordinates[0]));

    return cell(row, col, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    string startCoord;
    string endCoord;

    cin >> T;
    cin.ignore(1, '\n');

    while (T--)
    {
        cin >> startCoord >> endCoord;

        cell start = parse(startCoord);
        cell end = parse(endCoord);

        cout << bfs(start, end) << "\n" << flush;
    }

    return 0;
}