### 算法，时间复杂度 $O(n)$

经典的简化的括号匹配问题

### C++ 代码
```c++
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        unordered_map<char, char> ump {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        stack<char> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty() || st.top() != ump[s[i]]) {
                    return false;
                }
                st.pop();
            }
        }

        if (!st.empty()) {
            return false;
        }

        return true;
    }
};
```
