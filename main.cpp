/*
🧩 Problem: Rat in a Maze (GeeksforGeeks)

A rat is placed at the top-left cell (0, 0) of a N x N maze represented by a binary matrix.
- 1 represents an open cell that the rat can move through.
- 0 represents a blocked cell.
The rat must reach the bottom-right cell (N-1, N-1).

The rat can move in **four directions**:
    D -> Down
    L -> Left
    R -> Right
    U -> Up

Find all possible paths from start to destination.
Return the paths as a list of strings in **lexicographical order**.

If no path exists, return an empty list.

Example:
Input:
maze = {{1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}}

Output:
["DDRRDR", "DDRURR", "DRDDRR"]  (depending on possible routes)

Constraints:
1 ≤ N ≤ 5
maze[i][j] is either 0 or 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& maze, int n, 
               string path, vector<string>& res) {
        // Boundary and block check
        if (i < 0 || j < 0 || i >= n || j >= n || maze[i][j] == 0 || maze[i][j] == -1)
            return;

        // Base case: reached destination
        if (i == n - 1 && j == n - 1) {
            res.push_back(path);
            return;
        }

        // Mark cell as visited
        maze[i][j] = -1;

        // Explore all four directions
        solve(i + 1, j, maze, n, path + "D", res); // Down
        solve(i, j - 1, maze, n, path + "L", res); // Left
        solve(i, j + 1, maze, n, path + "R", res); // Right
        solve(i - 1, j, maze, n, path + "U", res); // Up

        // Backtrack
        maze[i][j] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> res;

        if (maze[0][0] == 0) return res;

        solve(0, 0, maze, n, "", res);
        sort(res.begin(), res.end());
        return res;
    }
};

// ------------------ MAIN FUNCTION FOR TESTING ------------------

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    Solution obj;
    vector<string> paths = obj.ratInMaze(maze);

    cout << "Possible paths from start to destination:\n";
    if (paths.empty()) {
        cout << "No path exists.\n";
    } else {
        for (string path : paths)
            cout << path << " ";
        cout << endl;
    }

    return 0;
}
