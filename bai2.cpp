
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int t; // t là chỉ số của phần tử cuối mảng, tức là đỉnh stack
};
void Init(Stack &S)
{
    S.t=-1; //Khi stack chưa có phần tử nào thì top được khởi tạo là -1,
            // nếu khởi tạo t = 0 là SAI vì khi đó sẽ hiểu top tại a[0]
}
int IsEmpty(Stack& s) {
    if(s.t==-1)
		return 1;
	else
		return 0;
}


int IsFull(Stack& s) {
    if(s.t>= MAX)
		return 1;
	else
		return 0;

}

int Push(Stack& s, const int x) {
    if(IsFull(s)==0)
	{
		s.t++;
		s.arr[s.t]=x;
		return 1;
	}
	else
		return 0;

}
void Pop(Stack& s) {
    if(!IsEmpty(s)) {
        
		s.t--;
    }
}
int Top(Stack& s) {
    if(!IsEmpty(s)) {
        return s.arr[s.t];
    }
    else return -1;
}
void printStack(Stack& s) {
    if(!IsEmpty(s)) {
        for(int i = 0; i <= s.t; i++) {
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




