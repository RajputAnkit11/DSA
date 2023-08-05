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
    vector<TreeNode*> generateTrees(int n) {    // check notes gfg article link
        vector<TreeNode*> ans = constructBSTs(1,n);
        return ans;              
    }
    
    vector<TreeNode*> constructBSTs(int start, int end){
        
        vector<TreeNode*> list; 
        
        if(start>end){
            list.push_back(NULL);
            return list;
        }
        
        for(int i = start; i<=end ; i++){
            
            vector<TreeNode*> leftSubTree = constructBSTs(start,i-1);
            vector<TreeNode*> rightSubTree = constructBSTs(i+1,end);
            
            for(int j=0;j<leftSubTree.size();j++){
                
                TreeNode* left = leftSubTree[j];
                
                for(int k=0;k<rightSubTree.size();k++){
                    
                    TreeNode* right = rightSubTree[k];
                    
                    TreeNode* node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    
                    list.push_back(node);
                }       
            }
        }
        
        return list;
    }
};