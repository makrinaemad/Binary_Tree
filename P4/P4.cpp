#include <iostream>
using namespace std;
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

        TreeNode(int x, TreeNode *left, TreeNode *right)
        {

        TreeNode* Node=new TreeNode();
        Node->val=x;
        Node->left=left;
        Node->right=right;}
void Inorder(TreeNode* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
	cout << root->val << " ";
	Inorder(root->right);
}
};

class Solution {
public:
        bool isSameTree(TreeNode* p, TreeNode* q) {

            if(p && !q || !p && q)
            {
                return false;
            }
            else if(p && q)
            {
                if(p->val !=q->val)
            {
                return false;
            }
             return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
            }
             else
                return true;
    }
    void ans (TreeNode*p, TreeNode* q)   //prints true or false
    {
        if(isSameTree(p,q))
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }

};

int main()
{
    Solution* s;
    ///example 1
    cout<<"p = [1,2,3], q = [1,2,3] : ";
   TreeNode *p=new TreeNode(1);
    p->left=new TreeNode(2);
    p->right= new TreeNode(3);

    TreeNode *q=new TreeNode(1);
    q->left=new TreeNode(2);
    q->right= new TreeNode(3);
    s->ans(p,q);

    ///example 2
    cout<<"p = [1,2], q = [1,null,2] : ";
    p=new TreeNode();
    p->val=1;
    p->left=new TreeNode(2);
    p->right=new TreeNode();

    q=new TreeNode();
    q->val=1;
    q->left=new TreeNode();
    q->right=new TreeNode(2);
    s->ans(p,q);

    ///example 3
    cout<<"p = [1,2,1], q = [1,1,2] : ";
    p=new TreeNode(1);
    p->left=new TreeNode(2);
    p->right=new TreeNode(1);

    q=new TreeNode(1);
    q->left=new TreeNode(1);
    q->right= new TreeNode(2);
    s->ans(p,q);

   ///example 4
   cout<<"p=[1,2,1,7], q=[1,1,2] : ";
    p=new TreeNode(1);
    p->left=new TreeNode(2);
    p->right=new TreeNode(1);
    p->right->right=new TreeNode(7);

    q=new TreeNode(1);
    q->left=new TreeNode(1);
    q->right= new TreeNode(2);
    s->ans(p,q);
    return 0;
}
