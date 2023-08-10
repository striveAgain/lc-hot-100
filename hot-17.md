### 算法，时间复杂度 $O(3^m \times 4^n)$
**`m` 为对应的 3 个字母的数字个数，`n` 为对应 4 个字母的数字个数**

先将每个数字可能对应的字母存起来，然后枚举给出的字符串中的所有数字，递归处理它所对应的字母即可；

---

### C++ 代码

```c++
class Solution {
    int n;
    string a[10];
    vector<string> ans;
public:
    void dfs(string cur, string s, int cnt) {
        if (cnt == n) {
            ans.push_back(cur);
            return;
        }

        int tmp = s[cnt] - '0';
        string st = a[tmp];
        for (int i = 0; i < st.size(); ++i) {
            cur.push_back(st[i]);
            dfs(cur, s, cnt + 1);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        a[2] = "abc", a[3] = "def", a[4] = "ghi", a[5] = "jkl";
        a[6] = "mno", a[7] = "pqrs", a[8] = "tuv", a[9] = "wxyz";
        n = digits.size();
        if (!n) {
            return {};
        }

        dfs("", digits, 0);
        return ans;
    }
};
```
