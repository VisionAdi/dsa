#include<iostream>
#define size 20
using namespace std;

class BST
{
private:
    typedef struct treeNode
    {
        int data;
        struct treeNode *right, *left;
    }node;
    node *root,*New,*temp,*parent;

public:
    node *que[20];
    int front, rear;
    BST()
    {
        root=NULL;
        front=rear=-1;
    }
    void create();
    void display();
    void find();
    void insert(node *,node *);
    void inorder(node *);
    void search(node **, int, node **);
    void LongestPathNodes();
    int Depth(node *);
    void FindMinValue();
    void minValue(node *,int *);
    void mirrorImg();
    void mirror(node *);
    void LevelWiseDisplay(node *root);
    void enque(node *temp);
    node *deque();

};

void BST::create()
{
    New=new node;
    New->left=NULL;
    New->right=NULL;
    cout<<"\nEnter Element to insert: ";
    cin>>New->data;
    if(root==NULL)
    {
        root=New;
    }
    else
        insert(root,New);
}

void BST::insert(node *root,node *New)
{
    if(New->data<root->data)
    {
        if(root->left==NULL)
        {
            root->left=New;
        }
        else
            insert(root->left,New);
    }
    if(New->data>root->data)
    {
        if(root->right==NULL)
        {
            root->right=New;
        }
        else
            insert(root->right,New);
    }

}

void BST::display()
{
    if(root==NULL)
    {
        cout<<"\nTree Not Created!";
    }
    else
    {
        cout<<"\nThe Tree in Inorder traversal is: ";
        inorder(root);
    }
}

void BST::inorder(node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<" "<<temp->data;
        inorder(temp->right);
    }
}

void BST::FindMinValue()
{
    int min=root->data;
    minValue(root,&min);
    cout<<"\nMinimum value node in given tree is: "<<min;
}

void BST::minValue(node *temp,int *min)
{
    if(temp!=NULL)
    {
        minValue(temp->left,min);
        if(temp->data<*min)
        {
            *min=temp->data;
        }
        minValue(temp->right,min);
    }
}

void BST::find()
{
    int key;
    cout<<"\nEnter Element you wish to search: ";
    cin>>key;
    temp=root;
    search(&temp,key,&parent);
    if(temp==NULL)
    {
        cout<<"\nElement is not found.";
    }
    else
    {
        cout<<"\nParent of node "<<temp->data<<"is "<<parent->data;
    }
}

void BST::search(node **temp,int key, node **parent)
{
    if(*temp==NULL)
    {
        cout<<endl<<"Tree not created.\n";
    }
    else
    {
        while(*temp!=NULL)
        {
            if((*temp)->data==key)
            {
                cout<<"\nElement "<<(*temp)->data<<" is present.";
                break;
            }
            *parent=*temp;
            if((*temp)->data>key)
            {
                *temp=(*temp)->left;
            }
            else
                *temp=(*temp)->right;
        }
    }
    return;
}

void BST::LongestPathNodes()
{
    if(root==NULL)
    {
        cout<<"\nTree is empthy.";
    }
    else
    {
        int lDepth=Depth(root->left);
        int rDepth=Depth(root->right);
        if(lDepth>rDepth)
        {
            cout<<"\nThe number of nodes in Longest Path = "<<lDepth+1;
        }
        else
        {
            cout<<"\nThe number of nodes in Longest Path = "<<rDepth+1;
        }
    }
}

int BST::Depth(node *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int lDepth=Depth(root->left);
        int rDepth=Depth(root->right);
        if(lDepth>rDepth)
            return (lDepth+1);
        else
            return (rDepth+1);
    }
}

/*void BST::enque(node *temp)
{
    if(rear==size-1)
    {
        cout<<"\nQueue is empty.";
        return;
    }
    rear=rear+1;
    que[rear]=temp;
}

BST::node *BST::deque()
{
    node *temp;
    if(front==rear)
    {
        cout<<"\nQueue is empty.";
        return NULL;
    }
    front ++;
    temp=que[front];
    return temp;
}

void BST::LevelWiseDisplay(node *root)
{
    node *temp, *dummy;
    dummy=new node;
    front=rear=-1;
    if(dummy==NULL)
    {
        cout<<"\nInsufficient Memory.\n";
    }
    dummy->left=root;
    dummy->right=NULL;
    dummy->data=-999;
    temp=dummy->left;
    enque(temp);
    enque(dummy);
    temp=deque();
    cout<<"\n";
    while(front!=rear)
    {
        cout<<"\n";
        if(temp!=dummy)
        {
            cout<<" "<<temp->data;
            if(temp->left!=NULL)
            {
                enque(temp->left);
            }
            if(temp->right!=NULL)
            {
                enque(temp->right);
            }
            else
            {
                enque(temp);
                cout<<"\n";
            }
        }
        temp=deque();
    }
}*/

void BST::mirrorImg()
{
    cout<<"\nOriginal tree: ";
    inorder(root);
    //LevelWiseDisplay(root);
    mirror(root);
    cout<<"\nMirror/Swapped Nodes image of tree is: ";
    //LevelWiseDisplay(root);
    inorder(root);
    mirror(root);
}

void BST::mirror(node *root)
{
    node *tempNode;
    if(root!=NULL)
    {
        mirror(root->left);
        mirror(root->right);
        tempNode=root->left;
        root->left=root->right;
        root->right=tempNode;
    }
}

int main()
{
    BST obj;
    int ch;
    char ans='y';
    cout<<"\n---------PROGRAM FOR BST---------";
    do
    {
        cout<<"\n\n1.Create\n2.Display\n3.Longest Path Nodes\n4.Find Minimum Value\n5.Mirror given tree/Swap left and right subtree\n6.Search\n7.Exit";
        cout<<"\nEnter you choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            do
            {
                obj.create();
                cout<<"\nDo you want to enter more elements?(y/n) ";
                cin>>ans;
            }while(ans=='y');
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.LongestPathNodes();
            break;
        case 4:
            obj.FindMinValue();
            break;
        case 5:
            obj.mirrorImg();
            break;
        case 6:
            obj.find();
            break;
        }

    }while(ch!=7);

    return 0;
}
