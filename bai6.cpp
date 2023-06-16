/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;
bool isValid(string s) {
    char stack[MAX];
    int top = -1;
    char c, t;
    for (int i = 0; i < s.length(); i++) {
        c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else {
            if (top < 0) {
                return false;
            } else {
                t = stack[top--];
                if (c == ')' && t != '(') {
                    return false;
                }
                if (c == ']' && t != '[') {
                    return false;
                }
                if (c == '}' && t != '{') {
                    return false;
                }
            }
        }
    }
    return top == -1;
}
if(n == 1) return 1;
else return 0;
//insert code here
//###INSERT CODE HERE -

int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}



