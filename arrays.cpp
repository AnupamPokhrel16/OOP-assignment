#include<iostream>

using namespace std;

int main()
{
  int num[5]={};
  int sum=0;

  for (int i = 0; i <=4; i++)
  {
    cout<<"Write the "<<i+1<<" element ";
    cin>>num[i];
    sum=num[i]+ sum;
    
  }
  cout<<sum;

}