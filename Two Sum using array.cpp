#include<iostream>
using namespace std;
int main()
{
    int n,size=0;
    cout<<"Enter the sum"<<endl;
    cin>>n;
    cout<<"Enter the size of array"<<endl;
    cin>>size;
    int a[size];
    cout<<"ENter the elements"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(n==a[i]+a[j])
            {
                cout<<'['<<i<<','<<j<<']'<<endl;
              break;
            }
        }
    }
}
