#include<iostream>

using namespace std;

int main()
{
  int num[5]={1,2,3,6,7};
  int max=num[0];


  for (int i = 0; i <=4; i++)
  {
    if (num[i]>max)
    {
      max = num[i];
    }
    
  }
  cout<<max;
}