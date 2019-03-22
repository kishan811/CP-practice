1. Postorder -->

        vector<int> v;
        //create stack
        stack<TreeNode*> s;
        //push root in stack
        s.push(root);
        //while stack not empty
        while (!s.empty()) 
        {
        	//pop stack in root
            root = s.top(); 
            s.pop();
            
            //if root not empty push in vector
            if(root)
               v.push_back(root->val);
            else
                continue;
            
            //push root->left in stack
            s.push(root->left);
            
            //push root->right in stack
            s.push(root->right);
        }
        
        //print vector in reverse
        return vector<int>(rbegin(v), rend(v));


--------------------------------------------------------------------
2. Preorder -->

		//create stack
        stack<TreeNode*> s;
        vector<int> v;

        //while true
        while(1)
        {
        	//while root
            while(root)
            {
            	//push root->data in vector or print it
                v.push_back(root->val);
                //push root in stack
                s.push(root);
                //assign root=root->left
                root=root->left;
                
            }
            
            //if stack is empty break loop
            if(s.empty())
              break;
            
            //pop stack top in root  
            root=s.top();
            s.pop(); 
            
            //assign root=root->right
            root=root->right;
        }
        
        return v;



-----------------------------------------------------------------------

3. Inorder -->

 vector<int> inorderTraversal(TreeNode* root) 
 {
		//create stack
        stack<TreeNode*> s;
        vector<int>v;
       
        //while true
        while(1)
        {
        	//while root
            while(root)
            {
                //push root in stack
                s.push(root);
                //assign root=root->left
                root=root->left;
            }
            
            //if stack is empty break loop
            if(s.empty())
                break;
            
            //pop stack top in root  
            root=s.top();
            s.pop();
            //....only change from inorder 
            v.push_back(root->val);
            //....
            
            //assign root=root->right
            root=root->right;
        }
        return v;
    }


-----------------------------------------------------
4. LevelOrder Traversal level by level top down


        queue<TreeNode*> q;
        vector<vector<int>> v;
        
        if(root)
            q.push(root);
        
        while(!q.empty())
        {
            int count = q.size();
            vector<int>vi;
            
            while(count>0)
            {
                TreeNode* temp= q.front();
                q.pop();
                vi.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
               
                count--;
            }
          
           v.push_back(vi); 


---------------------------------------------------------------------------------
5. LevelOrder level by level bottom up

    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
       //create queue  
       queue<TreeNode*> q;
       
        vector<vector<int>> v;
        
        //push root in queue
        if(root)
            q.push(root);
        
        //while queue not empty
        while(!q.empty())
        {
            //count =queue size
            int count = q.size();
            
            vector<int>vi;
            
            //while count >0
            while(count>0)
            {
                //pop queue front in temp
                TreeNode* temp= q.front();
                //push temp value in vi
                vi.push_back(temp->val);
                q.pop();
                
                //push temp left and right in queue
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
               
                //decrement count
                count--;
            }
          
           //pushback vi in v ->level order till now  
           v.push_back(vi); 
      }
        
        //taken another vector(vectror)) vn
        //insert vv in vn in reverese
        vector<vector<int>> vn;
        
        for(int i=v.size()-1;i>=0;i--)
        {
            vector<int> vv;
            for(int j=0;j<v[i].size();j++)
            {
                vv.push_back(v[i][j]);
            }
            vn.push_back(vv);
        }
        
        return vn;
    }


    ---------------------------------------------------------------

6. 110. Balanced Binary Tree
         
    Given a binary tree, determine if it is height-balanced.

a)Top-Down Approach->O(n^2)

 public boolean isBalanced(TreeNode root) 
    {
        if(root == null)
            return true;
        
        int left_height = getHeight(root.left);
        int right_height = getHeight(root.right);
        
        return Math.abs(left_height - right_height) <= 1 && isBalanced(root.left) && isBalanced(root.right);
    }
    
    private int getHeight(TreeNode root)
    {
        if(root == null)
            return 0;
        else
            return 1 + Math.max(getHeight(root.left), getHeight(root.right));
    }



 b)bottom-up-->o(n)

        bool isBalanced(TreeNode* root) {
        
        //call new function getheight
        int res=getheight(root);
        //if return -1(means at some node , abs(l_height - r_height)>=2) ,return false 
        if(res==-1)
            return false;
        else  //else return true
            return true;
    }
    
   int getheight(TreeNode* root)
   {
       //if root==NULL, return 0   	
       if(root==NULL)
           return 0;
       //call getheight root->left
       int l_height=getheight(root->left);
       //call getheight root->right
       if(l_height ==-1) //if left child abs(l_height - r_height)>=2, it is obiously equal to value -1;
           return -1; 
       
       int r_height=getheight(root->right);
       if(r_height ==-1) //if right child abs(l_height - r_height)>=2, it is obiously equal to value -1;
           return -1;
       
       if(abs(l_height - r_height)>=2) //if none of child is -1, than calculate if abs(l_height - r_height)>=2 than return -1;
           return -1;
       else
           return 1+max(l_height,r_height); // else return height
           
   }


------------------------------------------------------------------------------    

7. 112. Path Sum-->
Given a binary tree and a sum, 
determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.


  bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }

-------------------------------------------------------------------------

8. 226.Invert Binary Tree-->
Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1


a) Recursive

TreeNode* invertTree(TreeNode* root) {
    if (root) {
        invertTree(root->left);
        invertTree(root->right);
        std::swap(root->left, root->right);
    }
    return root;
}

b) Non-Recursive

TreeNode* invertTree(TreeNode* root) {
    std::stack<TreeNode*> stk;
    stk.push(root);
    
    while (!stk.empty()) {
        TreeNode* p = stk.top();
        stk.pop();
        if (p) {
            stk.push(p->left);
            stk.push(p->right);
            std::swap(p->left, p->right);
        }
    }
    return root;
}


------------------------------------------------------------------------------------

9. 101. Symmetric Tree (Mirror Tree)
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3


a)recursive-->

 bool isSymmetric(TreeNode* root) 
 {
        return ismirror(root,root);
  }
    
 int ismirror(TreeNode* r1,TreeNode* r2)
    {
        if(!r1 && !r2)
            return 1;
        
        if(r1 && r2 && r1->val==r2->val )
            return (ismirror(r1->left,r2->right) && ismirror(r1->right,r2->left));
                    
        return 0;            
    }


b)iterative-->

    bool isSymmetric(TreeNode* root) {
     queue<TreeNode*> q;
     q.push(root);   
     q.push(root);
     
     while(!q.empty())
     {
         TreeNode *temp1=q.front();
         q.pop();
         TreeNode *temp2=q.front();
         q.pop();
         if(!temp1 && !temp2)
             continue;
         
         if(!temp1 || !temp2 || temp1->val!=temp2->val)
             return false;
         
         q.push(temp1->left);
         q.push(temp2->right);
         q.push(temp1->right);
         q.push(temp2->left);
     }
        return true;
    }

------------------------------------------------------------------------------

10. 257. Binary Tree Paths
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]    

a) recursive -->
    
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> res;
 		
 		//if root cALL rtlpath function        
        if(root)
          rtlpath(root,res,"");
        
        return res; 
    }
    
    void rtlpath(TreeNode* root,vector<string> &res, string s )
    {
    	// if leaf node push string s in res vector
        if (!root->left && !root->right)
         {
            res.push_back(s + to_string(root->val));
         }
        else
        {
        	//if root->left present add to string s;
            if(root->left)
              rtlpath( root->left, res, s + to_string(root->val) + "->" );
          	//if root->right present add to string s;
            if(root->right)
              rtlpath( root->right, res, s + to_string(root->val) + "->" );
        }
    }

b) iterative

//DFS - Stack
public List<String> binaryTreePaths(TreeNode root) {
    //list of string
    List<String> list=new ArrayList<String>();
    //stack of TreeNode
    Stack<TreeNode> stk=new Stack<TreeNode>();
    //stack of string
    Stack<String> s=new Stack<String>();
    
    if(root==null) return list;
    
    stk.push(root);
    s.push("");
    
    while(!stk.isEmpty()) {
        TreeNode temp=stk.pop();
        String curStr=s.pop();
        
        if(temp.left==null && temp.right==null) list.add(curStr+temp.val);
        if(temp.left!=null) {
            stk.push(temp.left);
            s.push(curStr+temp.val+"->");
        }
        if(temp.right!=null) {
            stk.push(temp.right);
            s.push(curStr+temp.val+"->");
        }
    }
    return list;
} 

-------------------------------------------------------------------------------------

11. 235. Lowest Common Ancestor of a Binary Search Tree
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]

Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

a)recursive-->

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root)
            return NULL;
        if(p->val<root->val && q->val<root->val)
            return lowestCommonAncestor(root->left,p,q);
        else if(p->val>root->val && q->val>root->val)
            return lowestCommonAncestor(root->right,p,q);
        else
            return root;
    }

b)iterative-->

 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode *temp=root;
        
        while(temp!=NULL)
        {
            if(p->val > temp->val && q->val > temp->val )
            {
                temp=temp->right;
            }
            else if(p->val < temp->val && q->val < temp->val )
            {
                temp=temp->left;
            }
            else
                return temp;
        }
        return NULL;
    }

---------------------------------------------------------------------------------
12. 543. Diameter of Binary Tree
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the 
longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

 
 a) int res=0;
    int diameterOfBinaryTree(TreeNode* root) 
    {
        diameter(root);
        return res;
    }
    
    int diameter(TreeNode* root)
    {
       if(root==NULL)
           return 0;
        
        int left_height=diameter(root->left);
        int right_height=diameter(root->right);
        
        if(left_height + right_height > res)
            res=left_height + right_height;
        
        return 1 + max( left_height , right_height );
         
    }

 ------------------------------------------------------------------   