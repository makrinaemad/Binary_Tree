#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
class Node {
public:
    int data;
    Node* left, * right;
    Node() {
        data = 0;
        left = right = NULL;
    }
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class BT {
public:
    Node* root;
    BT() {
        root = NULL;
    }
    Node* newNode(int val) {
        Node* n = new Node();
        n->data = val;
        n->left = NULL;
        n->right = NULL;
        return (n);
    }

    void flip(Node* r)
    {
        if (r == NULL)
            return;

        queue<Node*> q;
        q.push(r);

        while (!q.empty())
        {
            Node* curr = q.front();
            q.pop();

            swap(curr->left, curr->right);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    void flip()
    {
        if (root == NULL)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node* curr = q.front();
            q.pop();

            swap(curr->left, curr->right);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    void preorder(Node* r) {
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
    void inorder(Node* r) {
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
    void postorder(Node* r) {
        if (r == NULL) {
            return;
        }
        else
        {
            postorder(r->left);
            cout << r->data << "  ";
            postorder(r->right);
        }

    }
    void print_level_order(Node* root)
    {
        if (root == NULL) return;
        queue <Node*> q;
        q.push(root);
        for (;;)
        {
            int count = q.size();
            if (count == 0)
                break;
            for (int i = 0; i < count; i++)
            {
                Node* node = q.front();
                cout << node->data << " ";
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            cout << endl;
        }
    }
};
int main() {
    BT t, t2, t3, t4, t5;
    t.root = t.newNode(1);
    t.root->left = t.newNode(2);
    t.root->right = t.newNode(3);
    t.root->left->left = t.newNode(4);
    t.root->left->right = t.newNode(5);
    //-----------
    t2.root = t2.newNode(1);
    t2.root->left = t2.newNode(2);
    t2.root->left->left = t2.newNode(3);
    t2.root->left->left->left = t2.newNode(4);
    t2.root->left->right = t2.newNode(5);
    //-----------
    t3.root = t3.newNode(1);
    t3.root->left = t3.newNode(2);
    t3.root->right = t3.newNode(3);
    t3.root->left->left = t3.newNode(4);
    t3.root->right->right = t3.newNode(5);
    //-----------
    t4.root = t4.newNode(1);
    t4.root->left = t4.newNode(2);
    t4.root->left->left = t4.newNode(3);
    t4.root->left->left->left = t4.newNode(4);
    t4.root->left->left->left->left = t4.newNode(5);
    //-----------
    t5.root = t5.newNode(1);
    t5.root->right = t5.newNode(2);
    t5.root->left = t5.newNode(3);
    t5.root->left->left = t5.newNode(4);
    t5.root->left->left->right = t5.newNode(5);

    cout << "Level order traversal of given tree\n";
    t.print_level_order(t.root);
    //no parameter is sent
    t.flip();
    cout << "Level order traversal of the flipped tree\n";
    t.print_level_order(t.root);

    cout << "\nInorder traversal of the given tree \n";
    t.inorder(t.root);
    cout << "\nInorder traversal of the flipped tree\n";
    //parameter is sent
    t.flip(t.root);
    t.inorder(t.root);

    cout << "\n-------------------------\n";
    cout << "Level order traversal of given tree\n";
    t2.print_level_order(t2.root);
    t2.flip();
    cout << "Level order traversal of the flipped tree\n";
    t2.print_level_order(t2.root);

    cout << "\nInorder traversal of the given tree \n";
    t2.inorder(t2.root);
    cout << "\nInorder traversal of the flipped tree\n";
    t2.flip(t2.root);
    t2.inorder(t2.root);

    cout << "\n-------------------------\n";
    cout << "Level order traversal of given tree\n";
    t3.print_level_order(t3.root);
    t3.flip();
    cout << "Level order traversal of the flipped tree\n";
    t3.print_level_order(t3.root);
    cout << "\nInorder traversal of the given tree \n";
    t3.inorder(t3.root);
    cout << "\nInorder traversal of the flipped tree\n";
    t3.flip(t3.root);
    t3.inorder(t3.root);

    cout << "\n-------------------------\n";
    cout << "Level order traversal of given tree\n";
    t4.print_level_order(t4.root);
    t4.flip();
    cout << "Level order traversal of the flipped tree\n";
    t4.print_level_order(t4.root);
    cout << "\nInorder traversal of the given tree \n";
    t4.inorder(t4.root);
    cout << "\nInorder traversal of the flipped tree\n";
    t4.flip(t4.root);
    t4.inorder(t4.root);

    cout << "\n-------------------------\n";
    cout << "Level order traversal of given tree\n";
    t5.print_level_order(t5.root);
    t5.flip();
    cout << "Level order traversal of the flipped tree\n";
    t5.print_level_order(t5.root);
    cout << "\nInorder traversal of the given tree \n";
    t5.inorder(t5.root);
    cout << "\nInorder traversal of the flipped tree\n";
    t5.flip(t5.root);
    t5.inorder(t5.root);

    //    cout << "\npreorder traversal of the given tree \n";
    //    t.preorder(t.root);
    //    cout << "\npreorder traversal of the flipped tree\n";
    //    t.flip(t.root);
    //    t.preorder(t.root);

    //    cout << "\nPostorder traversal of the given tree \n";
    //    t.postorder(t.root);
    //    cout << "\nPostorder traversal of the flipped tree\n";
    //    t.flip(t.root);
    //    t.postorder(t.root);
    return 0;
}
