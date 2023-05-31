#include<iostream>
using namespace std;
#define MAX 20
#define TRUE 1
#define FALSE 0

class Graph
{
private:
    int g[MAX][MAX], v[MAX];
    int v1,v2;
public:
    int n;
    static int node_count;
    Graph();
    void create();
    void display();
    void DFS(int);
    ~Graph();
};

Graph::Graph()
{
    for(v1=0;v1<MAX;v1++)
    {
        v[v1]=FALSE;

    }
    for(v1=0;v1<MAX;v1++)
        for(v2=0;v2<MAX;v2++)
            g[v1][v2]=FALSE;
}

Graph::~Graph()
{
    for(v1=0;v1<n;v1++)
        for(v2=0;v2<n;v2++)
            g[v1][v2]=FALSE;

    for(v1=0;v1<n;v1++)
    {
        v[v1]=FALSE;
    }
}

void Graph::display()
{
    for(v1=0;v1<n;v1++)
    {
        for(v2=0;v2<n;v2++)
        {
            cout<<" "<<g[v1][v2];
        }
        cout<<"\n";
    }
}

void Graph::create()
{
    n=0;
    do
    {
        cout<<"\nEnter Edge of Graph by two vertices: \nFirst Vertex: ";
        cin>>v1;
        cout<<"\nSecond Vertex: ";
        cin>>v2;
        if(v1==-99)
            break;
        if(v1>=MAX||v2>=MAX)
            cout<<"\nInvalid vertex value";
        else
            g[v1][v2]=TRUE;
            g[v2][v1]=TRUE;
        n++;
    }while(1);
}

void Graph::DFS(int v1)
{
    cout<<"\n"<<v1;
    node_count++;
    v[v1]=TRUE;
    for(v2=0;v2<n;v2++)
    {
        if(g[v1][v2]==TRUE && v[v2]==FALSE)
            DFS(v2);
    }
}


int Graph::node_count=0;

int main()
{
    Graph obj;
    int v1;
    obj.create();
    cout<<"\nAdjacency Matrix for given graph is: "<<endl;
    obj.display();
    cout<<"\nEnter the starting vertex for traversal: ";
    cin>>v1;
    if(v1>=MAX)
        cout<<"\nInvalid vertex.";
    cout<<"\nThe Depth First Search of graph is: ";
    obj.DFS(v1);
    cout<<"\nTotal nodes: "<<Graph::node_count;
    return 0;

}
/*
01
02
03
14
24
34
-99
-99
*/

