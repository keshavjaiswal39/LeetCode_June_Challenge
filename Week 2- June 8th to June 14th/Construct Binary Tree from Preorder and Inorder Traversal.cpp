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
    
    unordered_map<int,int> m;
    int idx;
    
    TreeNode * solve(vector<int> preorder,vector<int> inorder,int l,int h)
    {
        // base case
        if(l>h)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[idx++]);

        if(l==h)
        {
            return root;
        }

        int index=m[root->val];

        root->left=solve(preorder,inorder,l,index-1);
        root->right=solve(preorder,inorder,index+1,h);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        idx = 0;
        m.clear();
        int n = preorder.size();

        for(int i=0;i<n;i++)
        {
            m[inorder[i]]=i;
        } 
        
        TreeNode *root=solve(preorder,inorder,0,n-1);
	
	    return root;
    }
};
