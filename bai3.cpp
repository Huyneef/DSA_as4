
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
void printStack(Stack& s) {
    if(!IsEmpty(s)) {
        for(int i = s.n-1; i >= 0; i--) {
            cout << s.arr[i] ;
        }
    }
    else {
        cout << "0";
    }
}

void DecimaltoBinary2(int x,Stack& s) {
    
        while(x) {
        int r = x%2;
        Push(s,r);
        x/=2;
        }
    
    
    
}



int main()
{
    Stack S;Init(S);
    int n,x;
    cin>>n;
    DecimaltoBinary2(n,S);
    printStack(S);
    return 0;
}




