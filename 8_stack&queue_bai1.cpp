
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};



void Init(Stack& S) {
    S.n = 0;
}
int IsEmpty(Stack& s) {
    return s.n == 0;
}
int IsFull(Stack& s) {
    return s.n >= MAX;
}
void Push(Stack& s,const int x) {
    if(!IsFull(s)) {
        s.arr[s.n++] = x;
    }
    
}
void Pop(Stack& s) {
    if(!IsEmpty(s)) {
        s.n--;
    }
}
int Top(Stack& s) {
    if(!IsEmpty(s)) {
        return s.arr[s.n-1];
    }
    else return -1;
}
void printStack(Stack& s) {
    if(!IsEmpty(s)) {
        for(int i = 0; i <= s.n-1; i++) {
            cout << s.arr[i] << " ";
        }
    }
    else {
        cout << "Stack is empty" ;
    }
}
int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    for (int i= 1; i<=n; i++)
    {
        cin>>x;
        Push(S,x);

    }
    cout<<"Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    Pop(S);
    cout<<"\nUpdated Stack:";
    printStack(S);
    cout<<"\nTop:"<<Top(S);
    return 0;
}




