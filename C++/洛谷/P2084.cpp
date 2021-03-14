#include <iostream>
#include<queue>
using namespace std;
int main(){
    int m,n;
    cin>>m;
    char a;
    queue <char> q,qq;
    while(cin>>a!=0) q.push(a);
    n=q.size;
    while(!q.empty())
	{
		n--;
		if(q.front()!='0') 
		{
			cout<<q.front()<<'*'<<m<<'^'<<n;
			if(n!=0) cout<<'+';
		}
		q.pop();
	}
    return 0;
}