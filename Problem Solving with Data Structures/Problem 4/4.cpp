
#include<iostream>
using namespace std;
struct TreeNode {
    int val;                                                                     // data stored in the the node
    TreeNode* left;                                                             //left pointer point on left subtree
    TreeNode* right;                                                           // right pointer point on right subtree
    TreeNode() : val(0), left(nullptr), right(nullptr) {}                     // intial values for 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}               // parametrized constutors
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left),
        right(right) {}
};
class Solution
{
public:
    //symmetric function
    bool Symmetric(TreeNode* root1, TreeNode* root2)          //root1 pointer point to the subtree
                                                             //root2 pointer point  to the subtree
    {
        if (root1 == NULL && root2 == NULL)
            return true;
        if (root1 && root2 && root1->val == root2->val)
            return Symmetric(root1->left, root2->right) && Symmetric(root1->right, root2->left);
        return false;
    }
    bool SSymmetriccc(TreeNode* root)
    {
        return Symmetric(root, root);
    }                                         //recursion function
};
int main()
{
    Solution obj;
    //first test case
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);

    if (obj.SSymmetriccc(root1)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    //second test case
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(NULL);
    root->right->left = new TreeNode(3);
    root->left->right = new TreeNode(NULL);
    root->right->left = new TreeNode(3);

    if (obj.SSymmetriccc(root))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;

}