
#include<iostream>
using namespace std;
template <class T>
class BSTNode {
public:
    T data;
    BSTNode* left, * right;
    BSTNode() {
        left = right = NULL;
    }
    BSTNode(T val) {
        data = val;
        left = right = NULL;
    }
};
template <class T>
class BSTFCI {
public:
    BSTNode<T>* root;
    BSTFCI() {
        root = NULL;
    }
    BSTNode<T>* insert(BSTNode<T>* r, T val) {
        if (r == NULL) {
            BSTNode<T>* newnode = new BSTNode<T>(val);
            r = newnode;

        }
        else if (val < r->data) {
            r->left = insert(r->left, val);
        }
        else
            r->right = insert(r->right, val);
        return r;
    }
    void insert(T val) {
        root = insert(root, val);
    }
    void preorder(BSTNode<T>* r) {
        if (r == NULL) {
            return;
        }
        else
        {
            cout << r->data << "  ";
            preorder(r->left);
            preorder(r->right);
        }

    }
    void inorder(BSTNode<T>* r) {
       
        if (r == NULL) {
            return;
        }
        else
        {
            inorder(r->left);
            cout << r->data << "  ";
            inorder(r->right);
            
        }
 
    }
    void anotherInorder(BSTNode<T>* r, T lower, T higher) {
      
        if (r == NULL) {
            return;
        }
        if (r->data > lower)
            anotherInorder(r->left, lower, higher);
        if (lower <= r->data && higher >= r->data)
            cout << r->data << " ";
        if (r->data < higher)
            anotherInorder(r->right, lower, higher);
       
    }
    void printRange(T lower, T higher)
    {
        BSTNode<T>* r = this->root;
        anotherInorder(r, lower, higher);
        cout << endl;

    }
    bool isBalance(BSTNode<T>* root, int* height) {
        int left_height = 0, right_height = 0, l = 0, r = 0;
        if (root == NULL) {
            *height = 0;
            return 1;
        }
        l = isBalance(root->left, &left_height);
        r = isBalance(root->right, &right_height);

        if (left_height > right_height)
            *height = left_height + 1;
        else
            *height = right_height + 1;

        if (abs(left_height - right_height) >= 2)
            return 0;
        else
            return (l && r);
    }
    bool identical(BSTNode<T>* r1, BSTNode<T>* r2)
    {
        if (r1 == NULL && r2 == NULL)
            return true;

        else if (r1 == NULL || r2 == NULL)
            return false;

        return (r1->data == r2->data && identical(r1->left, r2->left) && identical(r1->right, r2->right));
    }

    bool isSubTree(BSTNode<T>* tree, BSTNode<T>* sub)
    {
        if (sub == NULL)
            return true;
        if (tree == NULL)
            return false;

        if (identical(tree, sub))
            return true;

        return isSubTree(tree->left, sub) ||
            isSubTree(tree->right, sub);
    }

};
int main() {
    int h = 0;
    BSTFCI<string> t;
    BSTFCI<int>t2, t3, t4, t5, t6,t7,t8;
    t.insert("a");
    t.insert("b");
    t.insert("c");
    t.insert("d");
    t.insert("e");
    //////////////////////////
    t2.insert(8);
    t2.insert(2);
    t2.insert(3);
    t2.insert(9);
    t2.insert(10);
    ////////////////////////
    t3.insert(1);
    t3.insert(2);
    t3.insert(3);
    t3.insert(4);
    t3.insert(5);
    ///////////////////////
    t4.insert(4);
    t4.insert(5);
    //////////////////////
    t5.insert(2);
    t5.insert(4);
    t5.insert(10);
    t5.insert(12);
    t5.insert(8);
    t5.insert(1);
    t5.insert(6);
    t5.insert(23);
    //////////////////////
    t6.insert(5);
    t6.insert(3);
    t6.insert(7);
    t6.insert(2);
    t6.insert(4);
    t6.insert(9);
    t6.insert(1);
    t6.insert(8);
    t6.insert(10);
    ///////////////////////
    t7.insert(9);
    t7.insert(8);
    t7.insert(10);
    ///////////////////////
    t8.insert(3);
    t8.insert(2);
    t8.insert(4);
    //t8.insert(1);

    t.inorder(t.root);
    cout << endl;
    if (t.isBalance(t.root, &h))
        cout << "the binary tree1 is balanced\n";
    else
        cout << "the binary tree1 is not balanced\n";

   
    t2.inorder(t2.root);
    cout << endl;
    if (t2.isBalance(t2.root, &h))
        cout << "the binary tree2 is balanced\n";
    else
        cout << "the binary tree2 is not balanced\n";

    
    t3.inorder(t3.root);
    cout << endl;
    if (t3.isBalance(t3.root, &h))
        cout << "the binary tree3 is balanced\n";
    else
        cout << "the binary tree3 is not balanced\n";

   
    t4.inorder(t4.root);
    cout << endl;
    if (t4.isBalance(t4.root, &h))
        cout << "the binary tree4 is balanced\n";
    else
        cout << "the binary tree4 is not balanced\n";

   // cout << "2 4 10 12 8 1 6 23 \n";
    t5.inorder(t5.root);
    cout << endl;
    if (t5.isBalance(t5.root, &h))
        cout << "the binary tree5 is balanced\n";
    else
        cout << "the binary tree5 is not balanced\n";

    //////////////////////////////////////////////////
    cout << endl;

    if (t3.isSubTree(t3.root, t4.root)) {
        cout << "tree4 is subtree of tree3\n";
    }
    else
        cout << "tree4 is not subtree of tree3\n";
    cout << endl;
    if (t3.isSubTree(t4.root, t3.root)) {
        cout << "tree3 is subtree of tree4\n";
    }
    else
        cout << "tree3 is not subtree of tree4\n";
    cout << endl;
    if (t3.isSubTree(t5.root, t4.root)) {
        cout << "tree4 is subtree of tree5\n";
    }
    else
        cout << "tree4 is not subtree of tree5\n";
    cout << endl;

    if (t3.isSubTree(t6.root, t7.root)) {
        cout << "tree7 is subtree of tree6\n";
    }
    else
        cout << "tree7 is not subtree of tree6\n";
    cout << endl;

    if (t3.isSubTree(t6.root, t8.root)) {
        cout << "tree7 is subtree of tree8\n";
    }
    else
        cout << "tree7 is not subtree of tree8\n";
    cout << endl;

    cout << "t range = "; t.printRange("a", "c");
    cout << "t2 range = ";  t2.printRange(2, 3);
    cout << "t3 range = "; t3.printRange(2, 4);
    cout << "t4 range = "; t4.printRange(1, 4);
    cout << "t5 range = "; t5.printRange(3, 9);
    cout << "t6 range = "; t6.printRange(6, 6);

    return 0;
}