#include<iostream>
using namespace std;
#include<algorithm>
#include<bits/stdc++.h>
//Max heap 
class heaps
{
      public:
      int arr[100];
      int size;
      heaps()
      {
            size=0;
      }
      // void swap(int a,int b)
      // {
      //       int t=a;
      //       a=b;
      //       b=t;


      // }
      void insert(int val)
      {
            //Time complexity of insertion in heap is log(n)
            arr[size]=val;
            int index=size;
               size++;
            while(index>0)
            {
                  int parent=(index/2);
                  if(arr[parent]<arr[index])
                  {
                       
                        swap(arr[index],arr[parent]);
                         index=parent;
                  }
                  else
                  {
                        return;
                  }

            }
         
      }
      void deletion()
      {
            //Time Complexity of a Deletion in array is log(n).
            //Where n is number of nodes
            arr[0]=arr[size-1];
            size--;
            int index=0;
            while(index<size)
            {
                  int left=2*index+1;
                  int right=2*index+2;
                  if(left<size&&arr[left]>arr[index])
                  {
                        swap(arr[index],arr[left]);
                        index=left;
                  }
                  else if(right<size&&arr[right]>arr[index])
                  {
                        swap(arr[index],arr[right]);
                        index=right;
                  }
                  else
                  {
                        return;
                  }
            }

      }
      
      void print()
      {
            for(int i=0;i<size;i++)
            {
                  cout<<arr[i]<<" ";
            }cout<<endl;
      }

};
void Hepify(vector<int> &arr ,int n,int index)
{
      int largest=index;
      //In hepify We Dont Have To Take care Of LEaf Node Because They are already a heap
      int left=2*index+1;
      int right=2*index+2;
      if(left<n&&arr[largest]<arr[left])
      {
      
            largest=left;

      }
       if(right<n&&arr[right]>arr[largest])
      {
           
            largest=right;

      }
      
      if(largest!=index)
      {
            swap(arr[largest],arr[index]);
            Hepify(arr,n,largest);
      }
      
}

void Heap_Sort(vector<int> &arr,int n)
{
     
      while(n>0)
      {
            swap(arr[0],arr[n-1]);
            n--;
            Hepify(arr,n,0);

      }

      
}
// void Hepify(vector<int> &arr, int n, int i)
// {
//         int largest=i;
//       int left=2*i+1;
//       int right=2*i+2;
      
//       if(left<n && arr[largest]<arr[left])
//       largest=left;
      
//       if(right<n && arr[largest]<arr[right])
//       largest=right;
        
        
//       if(largest!=i)
//       {
//           swap(arr[largest],arr[i]);
//           Hepify(arr,n,largest);
//       }
      
//     }



int main()
{
      //heaps h;
      // h.insert(6);
      // h.insert(3);
      // h.insert(7);
      // h.insert(2);
      // h.insert(10);
      // h.deletion();
      // h.deletion();
      // h.insert(19);
      // h.print();
      vector<int> ans;
      ans.push_back(1);
      ans.push_back(4);
      ans.push_back(5);
      ans.push_back(6);
      int n=ans.size();
      for(int i=(n/2)-1;i>=0;i--)
      {
            Hepify(ans,n,i);
      }
      cout<<"After Hepify"<<endl;
      for(int i=0;i<ans.size();i++)
      {
            cout<<ans[i]<<" ";
      }
      cout<<"After Heap sort"<<endl;
      Heap_Sort(ans,n);
       for(int i=0;i<ans.size();i++)
      {
            cout<<ans[i]<<" ";
      }


      cout<<endl;
  return 0;

}