1. Answer
```cpp
#include <bits/stdc++.h>
using namespace std;

class NQueens {
    int n;
    vector<vector<string>> solutions;
    vector<int> col, diag1, diag2;

public:
    NQueens(int n) {
        this->n = n;
        col.resize(n, 0);
        diag1.resize(2*n - 1, 0);
        diag2.resize(2*n - 1, 0);
    }

    void solve(int row, vector<string>& board) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row + c] || diag2[row - c + n - 1])
                continue;

            // place queen
            board[row][c] = 'Q';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 1;

            solve(row + 1, board);

            // backtrack
            board[row][c] = '.';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 0;
        }
    }

    void run() {
        vector<string> board(n, string(n, '.'));
        solve(0, board);

        cout << "Total solutions: " << solutions.size() << "\n\n";

        for (auto &sol : solutions) {
            for (auto &row : sol)
                cout << row << endl;
            cout << "------\n";
        }
    }
};

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    NQueens obj(n);
    obj.run();

    return 0;
}
 ```

2. Answer:
```cpp
#include <bits/stdc++.h>
using namespace std;

class HamiltonianCycle {
    int V;
    vector<vector<int>> graph;
    vector<int> path;

public:
    HamiltonianCycle(vector<vector<int>> g) {
        graph = g;
        V = g.size();
        path.resize(V, -1);
    }

    bool isSafe(int v, int pos) {
        // Check if adjacent
        if (graph[path[pos - 1]][v] == 0)
            return false;

        // Check if already in path
        for (int i = 0; i < pos; i++)
            if (path[i] == v)
                return false;

        return true;
    }

    bool solve(int pos) {
        if (pos == V) {
            // Check if last connects to first
            return graph[path[pos - 1]][path[0]] == 1;
        }

        for (int v = 1; v < V; v++) {
            if (isSafe(v, pos)) {
                path[pos] = v;

                if (solve(pos + 1))
                    return true;

                path[pos] = -1; // backtrack
            }
        }
        return false;
    }

    void run() {
        path[0] = 0;

        if (!solve(1)) {
            cout << "No Hamiltonian Cycle exists\n";
            return;
        }

        cout << "Hamiltonian Cycle:\n";
        for (int i = 0; i < V; i++)
            cout << path[i] << " ";

        cout << path[0] << endl; // complete cycle
    }
};

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    HamiltonianCycle hc(graph);
    hc.run();

    return 0;
}
```
