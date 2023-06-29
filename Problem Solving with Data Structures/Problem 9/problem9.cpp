#include<iostream>
using namespace std;
struct TreeNode {
    int val;                                                                       //data stored in the the node
    TreeNode* left;                                                               //left pointer point to  left subtree
    TreeNode* right;                                                             // right pointer point to right subtree
    TreeNode() : val(0), left(NULL), right(NULL) {}                             //default constructor                                  
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}                       //parametrized constructor                                
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left),
        right(right) {}                                                          //parametrized constructor 
};
class Solution {
public:

    bool foldable(TreeNode* root1, TreeNode* root2)       // Function to Test foldability                   


    {

        if (root1 == NULL && root2 == NULL)
            return true;

        else  if (root1 != NULL && root2 != NULL)
            return foldable(root1->left, root2->right) && foldable(root1->right, root2->left);
        else return false;


    }

    bool isfold(TreeNode* root3, TreeNode* root4)
    {
        return foldable(root3, root4);
    }



};
int main()
{
    Solution s;

    // Frist test case

    TreeNode* root01 = new TreeNode(1);
    TreeNode* root02 = new TreeNode(1);
    root01->left = new TreeNode(4);
    root01->left->right = new TreeNode(5);
    root02->right = new TreeNode(2);
    root02->right->left = new TreeNode(3);


    if (s.foldable(root01, root02))
    {

        cout << "Tree is foldable" << endl;
    }
    else {
        cout << "Tree is not foldable" << endl;
    }


    //Second test case

    TreeNode* root03 = new TreeNode(1);
    TreeNode* root04 = new TreeNode(1);
    root03->left = new TreeNode(2);
    root03->left->left = new TreeNode(4);
    root04->right = new TreeNode(3);
    root04->right->right = new TreeNode(5);

    if (s.foldable(root03, root04))
    {

        cout << "Tree is foldable" << endl;
    }
    else {
        cout << "Tree is not foldable" << endl;
    }


    //Third test case
    TreeNode* root05 = new TreeNode(1);
    TreeNode* root06 = new TreeNode(1);
    root05->left = new TreeNode(2);
    root05->left->right = new TreeNode(6);
    root05->left->left = new TreeNode(4);
    root06->right = new TreeNode(3);
    root06->right->right = new TreeNode(5);

    if (s.foldable(root05, root06))
    {

        cout << "Tree is foldable" << endl;
    }
    else {
        cout << "Tree is not foldable" << endl;
    }



    // fourth test case
    TreeNode* root07 = new TreeNode(1);
    TreeNode* root08 = new TreeNode(1);
    root07->left = new TreeNode(2);
    root08->right = new TreeNode(3);
    //root08->right->left = new TreeNode(8);
    root08->right->right = new TreeNode(5);

    if (s.foldable(root07, root08))
    {

        cout << "Tree is foldable" << endl;
    }
    else {
        cout << "Tree is not foldable" << endl;
    }
    // Fifth test case
    TreeNode* root09 = new TreeNode(1);
    TreeNode* root10 = new TreeNode(1);
    root09->left = new TreeNode(2);
    root09->left->left = new TreeNode(4);
    root09->left->right = new TreeNode(5);
    root10->right = new TreeNode(3);
    root10->right->left = new TreeNode(6);
    root10->right->right = new TreeNode(5);

    if (s.foldable(root09, root10))
    {

        cout << "Tree is foldable" << endl;
    }
    else {
        cout << "Tree is not foldable" << endl;
    }

    return 0;

}


