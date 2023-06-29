#include <iostream>
using namespace std;



// c++ program to find Sum Of All Elements smaller 
// than or equal to Kth Smallest Element In BST 


/* Binary tree Node */
struct tree
{
	int value;
	tree* left, * right;
};




// utility function new Node of BST 
struct tree* createNode(int data)
{
	tree* new_Node = new tree;
	new_Node->left = NULL;
	new_Node->right = NULL;
	new_Node->value = data;
	return new_Node;
}




// function to insert a node 
struct tree* insert(tree* root, int value)
{
	// If the tree is empty, return a new Node 
	if (root == NULL)
		return createNode(value);

	// Otherwise, recur down the tree 
	if (root->value > value)
		root->left = insert(root->left, value);

	else if (root->value < value)
		root->right = insert(root->right, value);

	// return the (unchanged) Node pointer 
	return root;
}




// recursion function of the sum
int recursion_of_sum(tree* root, int k, int& count)
{
	// Base cases 
	if (root == NULL)
		return 0;
	if (count > k)
		return 0;

	// Compute sum of elements in left subtree 
	int res = recursion_of_sum(root->left, k, count);
	if (count >= k)
		return res;

	// Add root's data 
	res += root->value;

	// Add current Node 
	count++;
	if (count == k)
		return res;

	// If count is less than k, return right subtree Nodes 
	return res + recursion_of_sum(root->right, k, count);
}



// Wrapper over ksmallestElementSumRec() 
int sum_of_tree(struct tree* root, int k)
{
	int count = 0;
	 return recursion_of_sum(root, k, count);
	
}




// test function
void Tests()
{
	// test 1 
	tree* root = NULL;
	root = insert(root, 54);
	root = insert(root, 51);
	root = insert(root, 49);
	root = insert(root, 52);
	root = insert(root, 75);
	root = insert(root, 74);
	root = insert(root, 85);

	int k = 3;
	cout << "Sum of k smallest elements is " << sum_of_tree(root, k) << endl;

	////////////////////////////////////////////////////

	// test 2
	tree* root1 = NULL;
	root1 = insert(root1, 54);
	root1 = insert(root1, 51);
	root1 = insert(root1, 49);
	root1 = insert(root1, 52);
	root1 = insert(root1, 75);
	root1 = insert(root1, 74);
	root1 = insert(root1, 85);
	root1 = insert(root1, 33);


	int y = 4;
	cout << "Sum of k smallest elements is " << sum_of_tree(root1, y) << endl;


	//////////////////////////////////////////////////////////////////


	// test 3
	tree* root2 = NULL;
	root2 = insert(root2, 54);
	root2 = insert(root2, 51);
	root2 = insert(root2, 49);
	root2 = insert(root2, 52);
	root2 = insert(root2, 75);
	root2 = insert(root2, 74);
	root2 = insert(root2, 85);
	root2 = insert(root2, 33);
	root2 = insert(root2, 50);

	int u = 5;
	cout << "Sum of k smallest elements is " << sum_of_tree(root2, u) << endl;

	///////////////////////////////////////////////////////

	//test 4

	tree* root3 = NULL;
	root3 = insert(root3, 54);
	root3 = insert(root3, 51);
	root3 = insert(root3, 49);
	root3 = insert(root3, 52);
	root3 = insert(root3, 75);
	root3 = insert(root3, 74);
	root3 = insert(root3, 85);
	root3 = insert(root3, 33);
	root3 = insert(root3, 50);
	root3 = insert(root3, 22);

	int t = 6;
	cout << "Sum of k smallest elements is " << sum_of_tree(root3, t) << endl;


	/////////////////////////////////////////////////////////////


		//test 5 

	tree* root4 = NULL;
	root4 = insert(root4, 54);
	root4 = insert(root4, 51);
	root4 = insert(root4, 49);
	root4 = insert(root4, 52);
	root4 = insert(root4, 75);
	root4 = insert(root4, 74);
	root4 = insert(root4, 85);
	root4 = insert(root4, 33);
	root4 = insert(root4, 50);
	root4 = insert(root4, 22);
	root4 = insert(root4, 40);


	int i = 7;
	cout << "Sum of k smallest elements is " << sum_of_tree(root4, i) << endl;
}


int main()
{
	Tests();
	return 0;
}
