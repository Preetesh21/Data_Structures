#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while (t-->0)
    {
        long long int n;
        cin>>n;
        int flag=0;
        long long int i=1;
        while(n>0)
        {
            if(n-2*i>0)
                n=n-2*i;
            else
            {
                flag=1;
                break;
            }
            if(flag==0&&n-2*i>0)
                n=n-2*i;
            else
            {
                flag=2;
                break;
            }
            i++;

        }
        if(flag==1)
            cout<<"IRON MAN"<<endl;
        else
            cout<<"CAPTAIN AMERICA"<<endl;
    }
}