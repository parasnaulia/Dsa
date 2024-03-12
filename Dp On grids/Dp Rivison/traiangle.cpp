#include<iostream>
#include<bits/stdc++.h>
using namespace std;

float largestTraingle(int base1,int height1,int base2,int height2)
{
      float ans=0;
      float area1=float(base1*height1)/2;
      float area2=float(base2*height2)/2;
      if(area1>area2)
      {
            ans=area1;
      }
      else 
      {
            ans=area2;
      }
      return ans*1.00;


}
int countPerfectSquares(const std::vector<int>& arr) {
    int count = 0;

    for (int num : arr) {
        double sqrt_result = sqrt(num);
        if (sqrt_result == static_cast<int>(sqrt_result)) {
            count++;
        }
    }

    return count;
}
int main()
{
     vector<int> arr={25,77,54,81,48,34};
     cout<<countPerfectSquares(arr);

      return 0;
}
