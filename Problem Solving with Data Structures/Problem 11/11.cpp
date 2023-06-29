#include <iostream>

using namespace std;
template<class t>
class bstnode {

public:
    int data;
    bstnode<t>* left;
    bstnode<t>* right;
    bstnode<t>(int value) {
        data = value;
        left = NULL;
        right = NULL;

    }

};
template<class t>
class bst {

public:
    bst<t>* left;
    bst<t>* right;
    int data;
    bstnode<t>* root;
    bst() {
        root = NULL;
    }

    bstnode<t>* insert(bstnode<t>* r, int item)
    {
        if (r == NULL)
        {
            bstnode<t>* newnode = new bstnode<t>(item);
            r = newnode;
        }
        else if (item < r->data)
        {

            r->left = insert(r->left, item);
        }
        else
            r->right = insert(r->right, item);

        return r;

    }
    void insert(int data) {
        root = insert(root, data);
    }



};
void preprder(bstnode<int>* r) {
    if (r == NULL)
        return;
    cout << r->data << "  ";
    preprder(r->left);
    preprder(r->right);
}

/// function of creating a node 
bst<int>* NewNode(int data) {
    bst<int>* node = new bst<int>();
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return (node);
}


// check the hight 
bool CheckTheHight(bst<int>* n, int* hight) {
    int lefthight = 0, righthight = 0;
    int l = 0, r = 0;
    if (n == NULL)
    {
        *hight = 0;
        return 1;
    }
    l = CheckTheHight(n->left, &lefthight);
    r = CheckTheHight(n->right, &righthight);
    *hight = (lefthight > righthight ? lefthight : righthight) + 1;

    if (std::abs(lefthight - righthight >= 2))
        return 0;

    else
        return l, r;

}

// function tests of balancing 
void IsBalanced()
{// test1
    int hight = 0;
    bst<int>* tree1 = NewNode(1);
    tree1->left = NewNode(2);
    tree1->right = NewNode(3);
    tree1->left->left = NewNode(4);      ///// balanced
    tree1->left->right = NewNode(5);
    if (CheckTheHight(tree1, &hight))
        cout << "the tree is balanced" << endl;
    else
        cout << "the tree is not balanced" << endl;

    //test2
    int hight1 = 0;
    bst<int>* tree2 = NewNode(1);
    tree2->left = NewNode(2);
    tree2->right = NewNode(3);
    tree2->left->left = NewNode(4);
    tree2->left->right = NewNode(5);////  balanced
    tree2->right->left = NewNode(6);

    if (CheckTheHight(tree2, &hight1))
        cout << "the tree is balanced" << endl;
    else
        cout << "the tree is not balanced" << endl;

    // test3
    int hight2 = 0;
    bst<int>* tree3 = NewNode(1);
    tree3->left = NewNode(2);
    tree3->right = NewNode(3);
    tree3->left->left = NewNode(4);

    tree3->left->left->left = NewNode(4); /// not balanced

    if (CheckTheHight(tree3, &hight2))
        cout << "the tree is balanced" << endl;
    else
        cout << "the tree is not balanced" << endl;

    //test4
    int hight3 = 0;
    bst<int>* tree4 = NewNode(1);
    tree4->left = NewNode(2);       ///  not balanced 
    tree4->right = NewNode(3);

    if (CheckTheHight(tree4, &hight3))
        cout << "the tree is balanced" << endl;
    else
        cout << "the tree is not balanced" << endl;

    //test5
    int hight4 = 0;
    bst<int>* tree5 = NewNode(1);
    tree5->left = NewNode(2);
    tree5->left->left = NewNode(4);   //// not balanced

    if (CheckTheHight(tree5, &hight4))
        cout << "the tree is balanced" << endl;
    else
        cout << "the tree is not balanced" << endl;



}
//Tree Comparison
bool sameroots(bst<int>* r1, bst<int>* r2)
{
    if (r1 == NULL && r2 == NULL) //means that the two roots are  equal
        return true;
    if (r1 == NULL || r2 == NULL)
        return false; //so one of them is null so they are not equal
    if (r1->data == r2->data && sameroots(r1->left, r2->left) && sameroots(r1->right, r2->right)) // Check the data of roots and data of left and right subtrees are the same or not
        return true;
    else
        return false;
}

bool subtree(bst<int>* tree, bst<int>* subt)
{
    if (tree == NULL)
        return false; //so they aren't equal
    if (sameroots(tree, subt)) //check they have the same roots or not
        return true;
    else //so it will check the left and right subtrees
        return subtree(tree->left, subt) || subtree(tree->right, subt);
}

void comparisontree()
{
    //test case 1
    bst<int>* t1 = NewNode(26);
    t1->right = NewNode(30);
    t1->right->right = NewNode(33);
    t1->left = NewNode(10);
    t1->left->left = NewNode(4);
    t1->left->left->right = NewNode(5);
    t1->left->right = NewNode(11);
    bst<int>* st1 = NewNode(10);
    st1->right = NewNode(11);
    st1->left = NewNode(4);
    st1->left->right = NewNode(5);
    if (subtree(t1, st1))
        cout << "Tree 2 is subtree of Tree 1";
    else
        cout << "Tree 2 is not a subtree of Tree 1";

    //test case 2
    bst<int>* t2 = NewNode(5);
    t2->right = NewNode(7);
    t2->right->right = NewNode(9);
    t2->right->right->right = NewNode(10);
    t2->right->right->left = NewNode(8);
    t2->left = NewNode(3);
    t2->left->right = NewNode(4);
    t2->left->left = NewNode(2);
    t2->left->left->left = NewNode(1);
    bst<int>* st2 = NewNode(9);
    st2->right = NewNode(10);
    st2->left = NewNode(8);
    if (subtree(t2, st2))
        cout << "\nTree 2 is subtree of Tree 1";
    else
        cout << "\nTree 2 is not a subtree of Tree 1";

    //test case 3
    bst<int>* t3 = NewNode(5);
    t3->right = NewNode(7);
    t3->right->right = NewNode(9);
    t3->right->right->right = NewNode(10);
    t2->right->right->left = NewNode(8);
    t3->left = NewNode(3);
    t3->left->right = NewNode(4);
    t3->left->left = NewNode(2);
    t3->left->left->left = NewNode(1);
    bst<int>* st3 = NewNode(3);
    st3->right = NewNode(4);
    st3->left = NewNode(2);
    st3->left->left = NewNode(1);
    if (subtree(t3, st3))
        cout << "\nTree 2 is subtree of Tree 1";
    else
        cout << "\nTree 2 is not a subtree of Tree 1";

    //test case 4
    bst<int>* t4 = NewNode(5);
    t4->right = NewNode(7);
    t4->right->right = NewNode(9);
    t4->right->right->right = NewNode(10);
    t4->left = NewNode(3);
    t4->left->right = NewNode(4);
    t4->left->left = NewNode(2);
    t4->left->left->left = NewNode(1);
    bst<int>* st4 = NewNode(6);
    st4->right = NewNode(9);
    st4->left = NewNode(3);
    if (subtree(t4, st4))
        cout << "\nTree 2 is subtree of Tree 1";
    else
        cout << "\nTree 2 is not a subtree of Tree 1";

    //test case 5
    bst<int>* t5 = NewNode(20);
    t5->right = NewNode(30);
    t5->right->right = NewNode(40);
    t5->right->right->right = NewNode(50);
    t5->left = NewNode(10);
    t5->left->right = NewNode(15);
    t5->left->left = NewNode(5);
    t5->left->left->left = NewNode(0);
    bst<int>* st5 = NewNode(30);
    st5->right = NewNode(56);
    st5->left = NewNode(10);
    if (subtree(st5, t5))
        cout << "\nTree 2 is subtree of Tree 1";
    else
        cout << "\nTree 2 is not a subtree of Tree 1";
}

void printRange(bst<int>* root, int n1, int n2)
{
    if (!root)
        return;

    bst<int>* current = root;

    while (current) {

        if (current->left == NULL)
        {

            if (current->data <= n2 &&
                current->data >= n1)
            {
                cout << current->data << " ";
            }

            current = current->right;
        }

        else {
            bst<int>* pre = current->left;

            while (pre->right != NULL &&
                pre->right != current)
                pre = pre->right;

            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }

            else {
                pre->right = NULL;


                if (current->data <= n2 &&
                    current->data >= n1)
                {
                    cout << current->data << " ";
                }

                current = current->right;
            }
        }
    }

}
int main() {
    bst<int> tree;
    tree.insert(7);
    tree.insert(10);
    tree.insert(5);


    /*preprder(tree.root);
    cout << endl;*/

    IsBalanced();
    cout << endl;
    comparisontree();
    cout << endl;

    //test case ex
    bst<int>* r1 = NewNode(5);
    r1->left = NewNode(3);
    r1->right = NewNode(7);
    r1->left->left = NewNode(2);
    r1->left->right = NewNode(4);
    r1->right->right = NewNode(9);
    r1->right->right->right = NewNode(10);
    r1->right->right->left = NewNode(8);
    cout << "records whose key values fall between 3,6" << endl;
    printRange(r1, 3, 6);
    cout << endl;
    cout << "records whose key values fall between 8,15" << endl;
    printRange(r1, 8, 15);
    cout << endl;
    cout << "records whose key values fall between 6,6" << endl;
    printRange(r1, 6, 6);
    //test case 1->5
    bst<int>* r2 = NewNode(4);
    r2->left = NewNode(2);
    r2->right = NewNode(7);
    r2->left->left = NewNode(1);
    r2->left->right = NewNode(3);
    r2->right->left = NewNode(6);
    r2->right->right = NewNode(10);
    cout << endl;
    cout << "records whose key values fall between 4,12" << endl;
    printRange(r2, 4, 12);
    cout << endl;
    cout << "records whose key values fall between 1,8" << endl;
    printRange(r2, 1, 8);
    cout << endl;
    cout << "records whose key values fall between 2,6" << endl;
    printRange(r2, 2, 6);
    cout << endl;
    cout << "records whose key values fall between 5,11" << endl;
    printRange(r2, 5, 11);
    cout << endl;
    cout << "records whose key values fall between 3,3" << endl;
    printRange(r2, 3, 3);
}