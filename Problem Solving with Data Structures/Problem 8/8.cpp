#include <iostream>
#include <string>
#include <utility>
using namespace std;
/*
 nada shaben 20210611
 sabreen othmen 20210613
 nada essam
 mariam elsbagh
 */
class binary_tree {
public:
    char val = 0;
    binary_tree* left = nullptr;
    binary_tree* right = nullptr;
};


int index;

void search(binary_tree* t, string preorder, const string& inorder) {
    if (t == nullptr)return;

    t->val = preorder[index];
    index++;
    if (inorder.find(preorder[index - 1]) % 2 == 1) {
        t->left = new binary_tree;
        t->right = new binary_tree;
    }
    search(t->left, preorder, inorder);
    search(t->right, preorder, inorder);
}

void print(binary_tree* t) {
    if (t == nullptr)
        return;
    print(t->left);
    print(t->right);
    cout << t->val << " ";
}

void printPostOrder(string preorder, const string& inorder) {
    auto* t = new binary_tree;
    search(t, move(preorder), inorder);
    print(t);
}


int main() {
    //test case 1
    string pre1 = "ABFGC";
    string in1 = "FBGAC";
    printPostOrder(pre1, in1);
    cout << endl;
    index = 0;
    //test case 2
    string pre2 = "HIKLJ";
    string in2 = "KILHJ";
    printPostOrder(pre2, in2);
    cout << endl;
    index = 0;
    //test case 3
    string pre3 = "ABDHIEJKCFLMGNO";
    string in3 = "HDIBJEKALFMCNGO";
    printPostOrder(pre3, in3);
    cout << endl;
    index = 0;
    //test case 4
    string pre4 = "HIKLJMN";
    string in4 = "KILHMJN";
    printPostOrder(pre4, in4);
    cout << endl;
    index = 0;
    //test case 5
    string pre6 = "TUWYZXV";
    string in6 = "YWZUXTV";
    printPostOrder(pre6, in6);
    



    return 0;
}