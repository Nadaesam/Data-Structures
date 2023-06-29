//problem 6
#include <string>
#include <iostream>
using namespace std;
class node
{
public:
    string value;
    node* left;
    node* right;
    node(string v) //empty node
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class tree
{
public:
    bool leaf(node* node) //check if the node is leaf or not
    {
        if (node->left == nullptr && node->right == nullptr)
            return true;
        else
            return false;
    }

    int evaluation(node* root)
    {
        if (leaf(root)) //if it is leaf so it is a number
        {
            return stoi(root->value); //return the number
        }
        else //so it is an operator and has children
        {
            int num1;
            int num2;
            int result;
            string x = root->value;
            num1 = evaluation(root->left);
            num2 = evaluation(root->right);
            if (x == "+")
            {
                result = num1 + num2;
                return result;
            }
            else if (x == "-")
            {
                result = num1 - num2;
                return result;
            }
            else if (x == "*")
            {
                result = num1 * num2;
                return result;
            }
            else if (x == "/")
            {
                result = num1 / num2;
                return result;
            }
            else
                return 0;
        }
    }

    void displaytestcases()
    {
        //test case number 1
        node* root1 = new node("+");
        root1->left = new node("3");
        root1->right = new node("*");
        root1->right->left = new node("4");
        root1->right->right = new node("/");
        root1->right->right->left = new node("8");
        root1->right->right->right = new node("2");
        cout << "The expression is +3-4/82 \n";
        cout << "Evaluaion = " << evaluation(root1) << endl << endl;

        //test case number 2
        node* root2 = new node("+");
        root2->left = new node("7");
        root2->right = new node("*");
        root2->right->left = new node("4");
        root2->right->right = new node("-");
        root2->right->right->left = new node("8");
        root2->right->right->right = new node("1");
        cout << "The expression is -7*4+20 \n";
        cout << "Evaluaion = " << evaluation(root2) << endl << endl;

        //test case number 3
        node* root3 = new node("+");
        root3->left = new node("9");
        root3->right = new node("*");
        root3->right->left = new node("2");
        root3->right->right = new node("6");
        cout << "The expression is +9*26 \n";
        cout << "Evaluaion = " << evaluation(root3) << endl << endl;

        //test case number 4
        node* root4 = new node("+");
        root4->left = new node("9");
        root4->right = new node("*");
        root4->right->left = new node("12");
        root4->right->right = new node("6");
        cout << "The expression is +9*12 6 \n";
        cout << "Evaluaion = " << evaluation(root4) << endl << endl;

        //test case number 5
        node* root5 = new node("+");
        root5->left = new node("9");
        root5->right = new node("*");
        root5->right->left = new node("3");
        root5->right->right = new node("/");
        root5->right->right->left = new node("1");
        root5->right->right->right = new node("2");
        cout << "The expression is +9*3/12 \n";
        cout << "Evaluaion = " << evaluation(root5) << endl << endl;
    }
};
int main()
{
    tree t;
    t.displaytestcases();
    return 0;
}

/*
BY USING STACK
#include <iostream>
#include <string>
using namespace std;

class stack
{
private:
    char s[50]; //to store the characters in the stack
    int top;    //to know what is the last char is the stack

public:
    stack()
    {
        top=-1;  //it's -1 bec when I push a char it will increament to 0 (first char)
    }

    int isfull() //function to check that there is a space in the stack or not
    {
        if(top==49)
        return 1;
        else
        return 0;
    }

    int isempty() //function to check that the stack is empty or not
    {
        if(top==-1)
        return 1;
        else
        return 0;
    }

    void push(char value)
    {
        if(!isfull()) //check that there is a space in the stack or not
        {
            top++;
            s[top]=value;
        }
        else
        cout<<"stack is full"<<endl;
    }

    char pop() //to delete a char in the stack
    {
        char value;
        if(!isempty())  //check that the stack is empty or not
        {
           value=s[top];
           top--; //to know the char that below the deleted char
        }
        return value;
    }

    void display()
    {
        for(int i=0; i<=top ; i++)
         cout<<s[i]<<" ";
         cout<<endl;
    }

    int evaluation (string exp)
    {
        stack s;
        int num1,num2,result;
        for(int i=exp.length();i>0;i--) //to begin from the end
        {
            if(exp[i]>=48 && exp[i]<=57) //ASCII code of 0 (48) & 9 (57)
            s.push(exp[i]-48);//Number-0 (to know what is the num)
            else
            {
                num1=s.pop();
                num2=s.pop();
                if(exp[i]=='+')
                {
                    result=num1+num2;
                    s.push(result);
                }
                else if(exp[i]=='-')
                {
                    result=num1-num2;
                    s.push(result);
                }
                else if(exp[i]=='*')
                {
                    result=num1*num2;
                    s.push(result);
                }
                else if(exp[i]=='/')
                {
                    result=num1/num2;
                    s.push(result);
                }

            }

        }
        return s.pop(); //return the evaluation number
    }
};
int main()
{
    stack n;
    cout<<"The expression is +3*4/82 "<<"\nEvaluation = "<<n.evaluation(" +3*4/82 ")<<endl<<endl;
    cout<<"The expression is -+7*45+20 "<<"\nEvaluation = "<<n.evaluation(" -+7*45+20 ")<<endl<<endl;
   cout<<"The expression is +9*3/12 "<<"\nEvaluation = "<<n.evaluation(" +9*3/12 ")<<endl<<endl;
   cout<<"The expression is -/*2*5+3652 "<<"\nEvaluation = "<<n.evaluation(" -/*2*5+3652 ")<<endl<<endl;
    cout<<"The expression is +9*26 "<<"\nEvaluation = "<<n.evaluation(" +9*26 ")<<endl<<endl;
    return 0;
}
*/