

#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;


// Hàm kiểm tra tính hợp lệ của chuỗi ngoặc đơn

bool isValid(string expr) {
    int n = expr.length();
    char stack[MAX];
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (expr[i] == '(') {
            if (top == MAX - 1) {
                return false;
            }
            stack[++top] = '(';
        }
        else if (expr[i] == ')') {
            if (top == -1 || stack[top] != '(') {
                return false;
            }
            top--;
        }
    }
    return (top == -1);
}
int main()
{
	string expr; cin>>expr;
	cout<< isValid(expr);

	return 0;
}



