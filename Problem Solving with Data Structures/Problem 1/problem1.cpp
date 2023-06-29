//problem 1

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class stack
{
private:
    char s[20]; //to store the path
    int top;    //to know what is the last element is the stack

public:
    stack()
    {
        top = -1;  //it's -1 bec when I push a char it will increament to 0 (first char)
    }

    int isfull() //function to check that there is a space in the stack or not
    {
        if (top == 19)
            return 1;
        else
            return 0;
    }

    int isempty() ////function to check that the stack is empty or not
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }

    void push(char val)
    {
        if (!isfull()) //check that there is a space in the stack
        {
            top++;
            s[top] = val;
        }
        else
            cout << "stack is full" << endl;
    }

    void pop(char val) //to delete a char in the stack
    {
        if (!isempty())  //check that the stack is empty or not
        {
            val = s[top];
            top--; //to know the char that below the deleted char
        }
    }

    char peek() //to show the last element
    {
        if (!isempty())
            return s[top];
        return ' ';
    }

    void simplifypath(char inputpath[20]) //function to simplify the path
    {
        int i, counter = 0;
        char temp[20];
        for (i = 0; inputpath[i] != '\0'; i++)
        {
            push(inputpath[i]);

            if (inputpath[i] == '.')
            {
                pop(inputpath[i]);
                counter++;
                if (counter = 2)
                {
                    pop(inputpath[i]); //delete the dir that before the two dots
                    counter = 0;
                }
            }
            else if (inputpath[i] == '/')
            {
                counter++;
                if (counter >= 2)
                {
                    pop(inputpath[i]);
                    counter = 0;
                }
            }
        }
        stack st; //another stack to store in it the path
        int len = strlen(inputpath);
        if (inputpath[len] == '/')
            pop(inputpath[len]);
        for (i = 0; inputpath[i] != '\0'; i++) //to store the letters of the path correctly
        {
            temp[i] = peek();
            st.push(temp[i]);
            pop(temp[i]);
        }

        for (i = 0; inputpath[i] != '\0'; i++) //to print the simplified path
        {
            cout << st.peek();
            st.pop(temp[i]);
        }
    }

};

int main()
{
    stack n;
    char test1[] = "/home/";
    char test2[] = "/../";
    char test3[] = "/home//foo/";
    char test4[] = "/a/../";
    char test5[] = "/a//b/../c/";
    cout << "The simplified path of /home/ is\t";
    n.simplifypath(test1);
    cout << "\n\nThe simplified path of /../ is\t\t";
    n.simplifypath(test2);
    cout << "\n\nThe simplified path of /home//foo/ is\t";
    n.simplifypath(test3);
    cout << "\n\nThe simplified path of /a/../ is\t";
    n.simplifypath(test4);
    cout << "\n\nThe simplified path of /a//b/../c/ is";
    n.simplifypath(test5);
    return 0;
}