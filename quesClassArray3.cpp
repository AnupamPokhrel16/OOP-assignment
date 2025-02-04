#include<iostream>

using namespace std;

int main()
{
  int num[5]={1,2,3,6,7};
  int value;
  
  cout<<"Write the value to check "<<endl;
  cin>>value;

  for (int i = 0; i <=4; i++)
  {
    if (num[i]==value)
    {
      cout<<"Value exists";
    }
    
  }
}