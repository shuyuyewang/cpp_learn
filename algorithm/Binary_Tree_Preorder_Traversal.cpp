class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;//代表前序遍历的结果
        if (!root) return result;//空返回空

        stack<TreeNode*> st;//用栈代表处理进度
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top(); //取节点指针
            st.pop();//弹出，防止重复处理
            result.push_back(node->val);//读根
            if (node->right) st.push(node->right);//用这个node访问右子树，然后入栈，先入后出
            if (node->left) st.push(node->left);//用这个node访问左子树，然后入栈，后入先出
        }//至此一轮循环已经实现了root->left->right，下一轮就是在
        return result;
    }
};
