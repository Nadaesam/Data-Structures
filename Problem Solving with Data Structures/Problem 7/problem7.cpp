#include<iostream>
using namespace std;
struct node {
	int data;
	node* left;
	node* right;
};
struct node* newnode(int data) {
	struct node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void mirror(node* root) {
	if (root) {
		mirror(root->left);
		mirror(root->right);
		node* temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}
void display_inorder(struct node* n) {
	if (n == NULL)
		return;
	display_inorder(n->left);
	cout << n->data << " ";
	display_inorder(n->right);


}
int main() {
	struct node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	display_inorder(root);
	cout << "***************";

	mirror(root);
	display_inorder(root);



	//*************  2 ****************//
	struct node* root2 = newnode(2);
	root2->left = newnode(5);
	root2->right = newnode(8);
	root2->right->left = newnode(3);
	root2->left->left = newnode(7);
	root2->left->right = newnode(9);
	cout << endl << "---------------" << endl;
	display_inorder(root2);
	mirror(root2);
	cout << "****************";
	display_inorder(root2);

	cout << endl << "---------------------" << endl;

	//**********3****************//
	struct node* root3 = newnode(2);
	root3->left = newnode(4);
	root3->right = newnode(5);
	root3->left->right = newnode(6);
	root3->left->left = newnode(7);
	root3->right->left = newnode(8);
	root3->left->left->left = newnode(9);
	display_inorder(root3);
	mirror(root3);
	cout << "****************";
	display_inorder(root3);
	cout << endl << "---------------" << endl;
	//***********4*************//

	struct node* r4 = newnode(1);
	r4->left = newnode(4);
	r4->right = newnode(15);
	r4->left->right = newnode(3);
	r4->left->left = newnode(2);
	r4->right->right = newnode(5);
	r4->right->left = newnode(6);
	r4->left->right->left = newnode(7);

	display_inorder(r4);
	mirror(r4);
	cout << "****************";
	display_inorder(r4);
	cout << endl << "---------------" << endl;
	//**************5**************//
	struct node* r5 = newnode(1);

	r5->left = newnode(1);
	r5->right = newnode(2);
	r5->right->right = newnode(3);
	r5->right->left = newnode(4);
	r5->right->right->right = newnode(5);
	r5->right->right->left = newnode(6);
	r5->left->right = newnode(7);
	r5->left = newnode(48);
	r5->left = newnode(8);
	display_inorder(r5);

	mirror(r5);
	cout << "****************";
	display_inorder(r5);
	cout << endl << "---------------";
}
