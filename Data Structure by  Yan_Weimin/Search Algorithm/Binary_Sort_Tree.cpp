#include <iostream>
using namespace std;
#define ENDFLAG '#'
typedef struct ElemType
{
    char key;
} ElemType;
typedef struct BSTNode
{
    ElemType data;
    BSTNode *lchild, *rchild;
} BSTNode, *BSTree;
BSTree SearchBST(BSTree T, char key)
{
    if ((!T) || key == T->data.key)
        return T;
    else if (key < T->data.key)
        return SearchBST(T->lchild, key);
    else
        return SearchBST(T->rchild, key);
}
void InsertBST(BSTree &T, ElemType e)
{
    if (!T)
    {
        BSTree S = new BSTNode;
        S->data = e;
        S->lchild = S->rchild = NULL;
        T = S;
    }
    else if (e.key < T->data.key)
        InsertBST(T->lchild, e);
    else if (e.key > T->data.key)
        InsertBST(T->rchild, e);
}
void CreateBST(BSTree &T)
{
    T = NULL;
    ElemType e;
    cin >> e.key;
    while (e.key != ENDFLAG)
    {
        InsertBST(T, e);
        cin >> e.key;
    }
}
void DeleteBST(BSTree &T, char key)
{
    BSTree p = T;
    BSTree f = NULL;
    BSTree q;
    BSTree s;
    while (p)
    {
        if (p->data.key == key)
            break;
        f = p;
        if (p->data.key > key)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if (!p)
        return;
    if ((p->lchild) && (p->rchild))
    {
        q = p;
        s = p->lchild;
        while (s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        p->data = s->data;
        if (q != p)
        {
            q->rchild = s->lchild;
        }
        else
            q->lchild = s->lchild;
        delete s;
    }
    else
    {
        if (!p->rchild)
        {
            q = p;
            p = p->lchild;
        }
        else if (!p->lchild)
        {
            q = p;
            p = p->lchild;
        }
        if (!f)
            T = p;
        else if (q == f->lchild)
            f->lchild = p;
        else
            f->rchild = p;
        delete q;
    }
}
void InOrderTraverse(BSTree &T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data.key << " ";
        InOrderTraverse(T->rchild);
    }
}
int main(void)
{
    BSTree T;
    cout << "Pleasr enter several character separated by Enter,end input with #" << endl;
    CreateBST(T);
    cout << "Current BST in-order traversal result:" << endl;
    InOrderTraverse(T);
    char key;
    cout << "Please enter charater to search for" << endl;
    cin >> key;
    BSTree result = SearchBST(T, key);
    if (result)
    {
        cout << "Found character " << key << endl;
    }
    else
    {
        cout << "Did not find character" << key << endl;
    }
    cout << "Please enter charater to delete" << endl;
    cin >> key;
    DeleteBST(T, key);
    cout << "Current BST in-order traversal result:" << endl;
    InOrderTraverse(T);
}