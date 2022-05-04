#include<vector>
#include<iostream>
#include<strings.h>
#include<algorithm>
using namespace std;
int a[1005][1005];
int visited[1005][1005];//to check visited nodes
int x=0;//count of tiles in a room
//to convert the number into binary string
string int_to_binary(int b)
{
    string p="0000";
    int e=3;
    while(b!=0)
    {
        if(b%2!=0)
        {
            p[e]='1';
            b=b/2;
            e--;
        }
        else
        {
            b=b/2;
            e--;
        }
    }
    return p;
}
//implementing depth first search
void dfs(int i,int j,int n,int m)
{
    if(i>=n||j>=m||i<0||j<0||visited[i][j]==1)
    return;
    visited[i][j]=1;
    x++;
    string s=int_to_binary(a[i][j]);
    if(s[0]=='0')
    dfs(i-1,j,n,m);
    if(s[1]=='0')
    dfs(i,j+1,n,m);
    if(s[2]=='0')
    dfs(i+1,j,n,m);
    if(s[3]=='0')
    dfs(i,j-1,n,m);
}
int main()
{
    int n,m;
    vector<int> v;
    cout<<"enter rows and colums";
    cin>>n>>m;
    cout<<"enter row 1:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>a[i][j];
        if(i!=n-1)
        cout<<"enter row "<<i+2<<":"<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(!visited[i][j])
           {
           x=0;
           dfs(i,j,n,m);
           v.emplace_back(x);
           }
        }
    }
    cout<<"room size from largest to smallest are:"<<endl;
    //sorting the elements in the vector using sort function from algorithm header file
    sort(v.begin(),v.end(),greater<int>());
     for (int i=0;i<v.size();i++)
        cout <<v[i]<<" ";
    return 0;

}
