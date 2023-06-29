#include <iostream>

using namespace std;

// struct that has nodw, right,left
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}//default constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}// paraametrized constructor has value
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}//parametrized constructor has node , right and left

};
class Solution {
public:
    TreeNode treeNode;
    Solution() :treeNode() {}//default constructor inherit form treenode constructor 
    Solution(int val) :treeNode(val) {}// paramerized has value inherit from treenode constroctor 
    Solution(int x, TreeNode* left, TreeNode* right) :treeNode(x, left, right) {}//parametrized constructor has value ,rirgt and left 
   /*X TreeNode* insert(int val) {
        TreeNode* sol = new TreeNode();
        sol->val = val;
        sol->right = NULL;
        sol->left = NULL;
        return sol;
    }
    */


};
bool isSameTree(Solution* p, Solution* q) {
    if (p == NULL && q == NULL)
        return 1;
    if (p != NULL && q != NULL)
    {
        return(p->treeNode.val == q->treeNode.val && p->treeNode.right == q->treeNode.right && p->treeNode.left == q->treeNode.left);
    }

}
void tests() {
    //first test tree
    TreeNode r(2);
    TreeNode l(3);
    Solution tree1(1, &r, &l);
    Solution tree2(1, &r, &l);
    if (isSameTree(&tree1, &tree2))
        cout << "the both trees are identical\n";
    else
        cout << "the both trees are not identical\n";


    //seconed test tree 
    TreeNode rs(0);
    TreeNode ls(2);
    TreeNode lss(2);

    Solution tree3(1, &rs, &ls);
    Solution tree4(1, NULL, &lss);

    if (isSameTree(&tree3, &tree4))
        cout << "the both trees are identical\n";
    else
        cout << "the both trees are not identical\n";


    //third test trees
    TreeNode rt(1);
    TreeNode lt(2);
    TreeNode rtt(2);
    TreeNode ltt(1);
    Solution tree5(1, &rt, &lt);
    Solution tree6(1, &rtt, &ltt);
    if (isSameTree(&tree5, &tree6))
        cout << "the both trees are identical\n";
    else
        cout << "the both trees are not identical\n";




}

int main()
{

    tests();

    return 0;
}