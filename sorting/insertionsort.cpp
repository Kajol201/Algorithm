#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   for(int i=0;i<n;i++)
   {
       bool flag=false;
       int idx=-1;

       for(int j=i-1;j>=0;j--)
       {
           if(a[i]<a[j])
           {
               flag=true;
               idx=j;

           }

       }
          if(flag)
           {
               for(int j=i;j>idx;j--)
              {
                  swap(a[j],a[j-1]);

              }

           }

   }
   for(auto u:a)
   {
       cout<<u<<" ";
   }
    return 0;
}

