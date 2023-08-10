### 算法，时间复杂度 $O(\frac{4^n}{\sqrt{n})$（卡特兰数）

**时间复杂度参考 leetcode hot100-22 方法二。。。**

采用递归的思路，跟踪过程中 `(` 和 `)` 的数量，记为 `count[0]` 和 `count[1]`，需要满足 `count[0] <= n` 以及 `count[1] <= count[0] (包含了 count[1] <= n)`；

### C++ 代码
```c++
class Solution {
    vector<int> count;
public:
    void dfs(string cur, int cnt, int n, vector<string>& ans) {
        if (cnt == 2 * n) {
            ans.push_back("(" + cur + ")");
            return;
        }

        if (count[0] < n) {
            ++count[0];
            dfs(cur + "(", cnt + 1, n, ans);
            --count[0];
        }

        if (count[1] <= count[0]) {
            ++count[1];
            dfs(cur + ")", cnt + 1, n, ans);
            --count[1];
        }
    }

    vector<string> generateParenthesis(int n) {
        count.resize(2, 0);
        vector<string> ans;

        dfs("", 0, n - 1, ans);

        return ans;
    }
};
```
