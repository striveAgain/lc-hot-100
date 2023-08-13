### 算法一：递归进行判断，时间复杂度 $O(n)$，空间复杂度 $O(n)$

`check(Treenode *node, int l, int r)` -- 检查节点的值是否在 `(l, r)` 中；

检查左子树时：`check(node, l, node->val)`；

检查右子树时：`check(node, node->val, r)`；

### C++ 代码
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode *node, long long l, long long r) {
        if (!node) {
            return true;
        }

        if (node->val <= l || node->val >= r) {
            return false;
        }

        return check(node->left, l, node->val) && check(node->right, node->val, r);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
};
```

---

### 算法二：栈模拟的中序遍历，时间复杂度 $O(n)$，空间复杂度 $O(n)$

记录中序序列中当前数的前一个数，进行怕那段即可；

### C++ 代码
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long bdy = LONG_MIN;

        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            if (root->val <= bdy) {
                return false;
            }

            bdy = root->val;
            root = root->right;
        }

        return true;
    }
};
```
