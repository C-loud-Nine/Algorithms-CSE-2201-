#include<bits/stdc++.h>
#define N 505

using namespace std;

char arr[N];
vector<char>result;
bool taken[N];
int n,m;


void print()
{
    for(int i=0;i<m;i++)    cout<<result[i];
    cout<<endl;
}

void call()
{
    if(result.size()==m)    print();
    else
        for(int i=0;i<n;i++)
        {
            if(!result.empty()&&result[result.size()-1]>arr[i])  continue;
            if(taken[i]==0)
            {
                taken[i]=1; result.push_back(arr[i]);
                call();
                taken[i]=0; result.pop_back();
                while(arr[i]==arr[i+1]) i++;
            }
        }
}

int main()
{
    
        cin>>arr>>m;
        n=strlen(arr);
        sort(arr,arr+n);

        call();
        cout<<endl<<endl;
    
}