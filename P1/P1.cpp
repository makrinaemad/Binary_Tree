#include <iostream>

using namespace std;

struct node {
    string data;
    node* next;
    node(string value, node* _next) { data = value; next = _next; }
    node() { data = ""; next = nullptr; }
};

class myStack {
private:
    int counter = 0;
    node* head = nullptr;
    int dotCounter = 0;
public:
    void applyCual(string oldPath)
    {
        string temp;
        for (int i = 0; i < oldPath.size(); i++)//loop to loop on the string
        {
            if (oldPath[i] != '/')//collect all char that are between the two '/'
            {
                temp += oldPath[i];
            }
            if (oldPath[i] == '.' && oldPath[i - 1] == '/' && oldPath[i + 1] == '.' && (oldPath[i + 2] == '/' || (i + 2) == oldPath.size()))//this to get rid of the "/.." and go tto the upper directory
            {
                temp.pop_back();
                pop();
                i++;
            }
            if (oldPath[i] == '.' && oldPath[i - 1] == '/' && (oldPath[i + 1] == '/' || (i + 1) == oldPath.size()))//this to get rid of the "/."
            {
                temp.pop_back();
            }
            if (oldPath[i] == '/' || (i + 1) == oldPath.size())//this to handle the repetition of '/'
            {
                push(temp);
                temp.clear();
                for (i; oldPath[i + 1] == '/';)
                    i++;
            }
        }
    }

    void push(string val)
    {
        if (val == "")//to prevent the increment of counter with the fake push of null
            return;
        head = new node(val, head);
        counter++;
    }
    bool isEmpty()
    {
        return (counter == 0);
    }
    int Size()
    {
        return counter;
    }
    string top()
    {
        if (counter == 0)
        {
            return "";
        }
        return head->data;
    }
    string pop()
    {
        string tempData;
        if (counter == 0)
        {
            return "/";
        }
        node* temp = head;
        head = head->next;
        tempData = temp->data;
        delete temp;
        counter--;
        return tempData;
    }
    void displayNewPath()
    {
        string newPath;
        int count = counter;
        if (counter == 0)
        {
            newPath = "/";
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                newPath = '/' + pop() + newPath;
            }
        }
        cout << newPath << endl;

    }

};

int main()
{
    myStack test1, test2, test3, test4;
    string path;

    test1.applyCual("/home/");
    test1.displayNewPath();

    test2.applyCual("/../");
    test2.displayNewPath();

    test3.applyCual("/home//foo/");
    test3.displayNewPath();

    cout << "enter your file path:";
    cin >> path;
    //cin.ignore();

    test4.applyCual(path);
    test4.displayNewPath();

    return 0;
}
