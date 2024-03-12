 #include<iostream>
 using namespace std;
#include<bits/stdc++.h>
//1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1

class TreeNode
{
      public:
      int data;
      TreeNode* left;
      TreeNode* right;
      TreeNode( int data)
      {
            this->data=data;
            this->right=NULL;
            this->left=NULL;
      }
      

};
void left1(TreeNode*root,vector<int> &ans)
    {
        vector<int> v;
        queue<TreeNode*> q;
        if(root==NULL)
        {
            return;
        }
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                   if(i==0)
                {
                    v.push_back(temp->data);
                }
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
             
            }
        }
        reverse(v.begin(),v.end());
        for(auto x:v)
        {
            ans.push_back(x);
        }
    }
    void right1(TreeNode*root,vector<int> &ans)
    {
        queue<TreeNode*> q;
        if(root==NULL)
        {
            return;
        }
         q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                 if(i==size-1)
                {
                    ans.push_back(temp->data);
                }
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
               
            }
        }
        
        
    }

void left(TreeNode*root,vector<int> &ans)
{
    if(root==NULL||(root->left==NULL&&root->right==NULL))
    {
        return;
    }
    ans.push_back(root->data);
    if(root->left)
    {
        left(root->left,ans);
    }
    else
    {
        left(root->right,ans);
    }
}
void leaf(TreeNode* root,vector<int> &ans)
 {
    queue<TreeNode*>q;
    if(root==NULL)
    {
        return;
    }
    q.push(root);
   while(!q.empty())
     {
        int size=q.size();
        for(int i=0;i<size;i++)
         {
             auto temp=q.front();
             q.pop();
           if(temp->left)
             {
                q.push(temp->left);
            }
             if(temp->right)
             {
                 q.push(temp->right);           
                 
                 
             }
             if((temp->left==NULL)&&(temp->right==NULL))
           {
         

    
    
    
                ans.push_back(temp->data);             
        }
   }
     }
    
 }
void right(TreeNode* root,vector<int> &ans)
{
     if(root==NULL||(root->left==NULL&&root->right==NULL))
    {
        return;
    }
    if(root->right)
    {
        right(root->right,ans);
    }
    else
    {
        right(root->left,ans);
    }
    ans.push_back(root->data);
    

    
}
TreeNode*createTree(TreeNode*&root)
{
      int data;
      cout<<"Enter The value"<<endl;
      cin>>data;
      root=new TreeNode(data);

      if(data==-1)
      {
            return NULL;
      }
      cout<<"enter The Left Value"<<root->data;
      root->left=createTree(root->left);
      cout<<"Enter The right value"<<root->data;
      root->right=createTree(root->right);
      return root;

}
void preorder(TreeNode*root)
{
      if(root!=NULL)
      {
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
      }
}
void inorder(TreeNode*root)
{
      if(root!=NULL)
      {
           
            inorder(root->left);
             cout<<root->data<<" ";
            inorder(root->right);
      }
}
void postorder(TreeNode*root)
{
      if(root!=NULL)
      {
           
            postorder(root->left);
            postorder(root->right);
             cout<<root->data<<" ";
      }
}

    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;
         q.push(root);
        if(root==NULL)
      {
            return ans;
      }
     
     
      while(!q.empty())
      {
            int size1=q.size();
            vector<int> v;
            for(int i=0;i<size1;i++)
            {
                  auto temp=q.front();
                  
                  q.pop();
                  v.push_back(temp->data);
                  if(temp->left)
                  {
                      q.push(temp->left);
                  }
                  if(temp->right)
                  {
                        q.push(temp->right);
                  }
            }
            ans.push_back(v);
      }
      return ans;
      
      
    }
vector<vector<int>>  Level(TreeNode* root)
{
      vector<vector<int>> ans;
      queue<TreeNode*> q;
      q.push(root);
      if(root==NULL)
      {
            return ans;
      }
      q.push(NULL);
      vector<int> v;
      
      while(!q.empty())
      {
            auto temp=q.front();
            q.pop();
            if(temp==NULL){
                 // cout<<endl;
                  ans.push_back(v);
                  v.clear();
                  if(!q.empty()){
                 q.push(NULL);
                  }
                
            }
            else{
                  v.push_back(temp->data);
                //  cout<<temp->data<<" ";
            if(temp->left)
            {
                  q.push(temp->left);

            }
            if(temp->right)
            {
                  q.push(temp->right);
            }
      }
      }
      return ans;
}
void Create_bfs(TreeNode* &root)
{
      int data;
      queue<TreeNode*> q;
      cout<<"Enter The  root Data"<<endl;
      cin>>data;
      root=new TreeNode(data);
      if(data==-1)
      {
            return;
      }
      q.push(root);
      while(!q.empty())
      {
            auto temp=q.front();
            q.pop();
            int leftdata;
            cout<<"Enter The left Data of"<<temp->data<<endl;
            cin>>leftdata;
            if(leftdata!=-1)
            {
                  temp->left=new TreeNode(leftdata);
                  q.push(temp->left);


            }
            int rightdata;
            cout<<"Enter The Right data of "<<temp->data<<endl;
            cin>>rightdata;
            if(rightdata!=-1)
            {
                  temp->right=new TreeNode(rightdata);
                  q.push(temp->right);
            }
      }

}

int main()
{
      TreeNode* root=NULL;
      // createTree(root);
      // preorder(root);
      // cout<<endl;
      // cout<<"inorder"<<endl;
      //  inorder(root);
      //  cout<<"postorder"<<endl;
      //  postorder(root);
      //  cout<<"Bfs"<<endl;
      //  vector<vector<int>> ans=Level(root);
      //  for(int i=0;i<ans.size();i++)
      //  {
      //       for(int j=0;j<ans[i].size();j++)
      //       {
      //             cout<<ans[i][j]<<" ";
      //       }
      //       cout<<endl;
      //  }
       //cout<<"0(n)"<<endl;
       //Level(root);
       Create_bfs(root);
// cout<<"Bfs "<<endl;
// vector<vector<int>> ans=Level(root);

//        for(int i=0;i<ans.size();i++)
//        {
//             for(int j=0;j<ans[i].size();j++)
//             {
//                   cout<<ans[i][j]<<" ";
//             }
//             cout<<endl;
//        }
vector<int> ans;
//ans.push_back(root->data);
left1(root->left,ans);
//leaf(root,ans);
right1(root->right,ans);

cout<<"Ans is "<<endl;
for(auto x:ans)
{
      cout<<x<<" ";
}

return 0;


}
