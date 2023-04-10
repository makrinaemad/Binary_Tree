#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left),
        right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // write you code here
        return (root == NULL || isTheEnd(root->left, root->right));
    }

    bool isTheEnd(TreeNode* leftSub, TreeNode* rightSub)
    {
        if (leftSub == NULL && rightSub == NULL)
        {
            return true;
        }
        else if (leftSub != NULL && rightSub != NULL)
        {
            return  ((leftSub->val == rightSub->val) && (isTheEnd(leftSub->left, rightSub->right)) && (isTheEnd(leftSub->right, rightSub->left)));
        }
        return false;
    }
};
// add main method and test cases to test your code


int main()
{
    TreeNode* first = new TreeNode(1);
    first->left = new TreeNode(2);
    first->left->left = new TreeNode(3);
    first->left->right = new TreeNode(4);
    first->right = new TreeNode(2);
    first->right->left = new TreeNode(4);
    first->right->right = new TreeNode(3);
    Solution s1;

    TreeNode* second = new TreeNode(1);
    second->left = new TreeNode(2);
    second->left->right = new TreeNode(3);
    second->right = new TreeNode(2);
    second->right->right = new TreeNode(3);
    Solution s2;

    cout << "root = [1,2,2,3,4,4,3]\n";
    if (s1.isSymmetric(first))
    {
        cout << "true\n";
    }
    else { cout << "false\n"; }

    cout << "root = [1,2,2,null,3,null,3]\n";
    if (s2.isSymmetric(second))
    {
        cout << "true\n";
    }
    else { cout << "false\n"; }

    return 0;
}
