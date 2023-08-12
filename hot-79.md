### 算法，时间复杂度 $O(MN \times 3^L)$

**M, N 为网格的长和宽，L 为 `word` 长度，每次最多进入 3 个分支！**

经典的 DFS 匹配问题；

### C++ 代码
```c++
class Solution {
    int n, m;
    vector<vector<bool> > vis;
    vector<int> dx, dy;
public:
    bool dfs(vector<vector<char> >& board, string word, int x, int y, int cnt) {
        if (board[x][y] != word[cnt]) {
            return false;
        }

        if (cnt == word.size() - 1) {
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            int px = x + dx[i], py = y + dy[i];
            if (px >= 0 && px < n && py >= 0 && py < m && !vis[px][py]) {
                vis[px][py] = true;
                if (dfs(board, word, px, py, cnt + 1)) {
                    return true;
                }
                vis[px][py] = false;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();

        vis.resize(n, vector<bool>(m, false));
        dx.resize(4, 0), dy.resize(4, 0);
        dx[0] = -1, dx[1] = 1, dx[2] = 0, dx[3] = 0;
        dy[0] = 0, dy[1] = 0, dy[2] = -1, dy[3] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                vis[i][j] = true;
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
                vis[i][j] = false;
            }
        }

        return false;
    }
};
```
