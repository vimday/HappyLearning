/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :BBB.cpp
 * @Created Time:2020-10-21 19:18:23
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param p TreeNode类 
     * @param q TreeNode类 
     * @return TreeNode类
     */
    TreeNode* nearestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root->val == p->val || root->val == q->val)
            return root;
        TreeNode* l = nearestCommonAncestor(root->left, p, q);
        TreeNode* r = nearestCommonAncestor(root->right, p, q);
        return !l ? r : !r ? l : root;
        // if (!l)
        //     return r;
        // if (!r)
        //     return l;
        // return root;
        // write code here
    }
};