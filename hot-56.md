### 算法

经典区间合并问题，背模板即可；

### C++ 代码
```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
	
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > ans;
        
        int st = -1, ed = -1;
        for (int i = 0; i < n; ++i) {
            if (ed < intervals[i][0]) {
                if (st != -1) {
                    ans.push_back({st, ed});
                }
                
                st = intervals[i][0];
                ed = intervals[i][1];
            } else {
                ed = max(ed, intervals[i][1]);
            }
        }
        
        if (st != -1) {
            ans.push_back({st, ed});
        }
        
        return ans;
    }
};
```
