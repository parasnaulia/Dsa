#include<iostream> 
#include<math.h>
using namespace std;
int main()
{
    //123
  //  Now this is a case when we want to reverse the no 
    //ans=10*digit+ans;
 //1*10^i+0 ans=1;(i==0)
 //10*2+1 //21(i==1)
 //10*3+21 //(i==2)
 //321
 //To print  a normal number 123
 // ans=(digit*10)+ans;
 //10 let ans=0;
 //ans=ans*10+digit.
 //1
 //12
 //123
 //decimal to binary
 float ans=0;
 int n=34;
 int i=0;
 while(n!=0)
 {
    int bit=n&1;
     ans=(bit*pow(10,i))+ans;
     n=n>>1;
    i++;
 }
 cout<<ans;

} 
