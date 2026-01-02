//leetcode - 20
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValidParanthesis(string s)
{
    stack<char> stk;

    for (char c : s) {
        switch (c) {

            case '(': 
            case '{': 
            case '[': 
                stk.push(c); 
                break;

            case ')': 
                if (stk.empty() || stk.top() != '(') return false; 
                stk.pop(); 
                break;
            case '}': 
                if (stk.empty() || stk.top() != '{') return false; 
                stk.pop(); 
                break;
            case ']': 
                if (stk.empty() || stk.top() != '[') return false; 
                stk.pop(); 
                break;
        }
    }
    return stk.empty();
}

int main()
{
    string s = "{}()[]";

    cout<<isValidParanthesis(s)<<endl;
}