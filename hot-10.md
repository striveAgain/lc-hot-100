### 算法：字符串匹配问题，时间复杂度 $O(mn)$，空间复杂度 $O(mn)$

经典的 `DP` 问题，非常重要！！！

#### 状态表示

`f[i][j]` -- 表示 `s` 的前 `i` 个字符和 `p` 的前 `j` 个字符的匹配情况；

#### 状态计算

根据当前字符是否是 `*` 进行分类：
+ 若当前字符不是 `*`
  + 若 `s[i - 1]` 和 `p[j - 1]` 匹配，则 `f[i][j] |= f[i - 1][j - 1]`；
  + 若 `s[i - 1]` 和 `p[j - 1]` 不匹配，则 `f[i][j] = false`；
+ 若当前字符是 `*`
  + 若 `s[i - 1]` 和 `p[j - 2]` 匹配，则可以继续用 `*` 匹配或者丢掉这个组合 `f[i][j] |= f[i - 1][j] | f[i][j - 2]`；
  + 若 `s[i - 1]` 和 `p[j - 2]` 不匹配，则 `f[i][j] |= f[i][j - 2]`；

### C++ 代码
```c++
class Solution {
public:
    bool match(string s, string p, int i, int j) {
        if (!i) {
            return false;
        }

        if (p[j - 1] == '.') {
            return true;
        }

        return s[i - 1] == p[j - 1];
    }

    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();

        vector<vector<int> > f(m + 1, vector<int>(n + 1));
        f[0][0] = true;

        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (match(s, p, i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                } else {
                    if (match(s, p, i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }

        return f[m][n];
    }
};
```
