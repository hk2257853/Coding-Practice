#include "iostream"
using namespace std;
#define MAX 100
#include "queue"
#include "stack"

int adj[MAX][MAX];
int Tvertices;
int isvisited[MAX];
queue<int> que;
stack<int> stk;

void dfsiter(int ver)
{
    for (int i = 0; i < Tvertices; i++)
    {
        isvisited[i] = 0;
    }

    stk.push(ver);

    while(!stk.empty())
    {
        int top = stk.top();
        stk.pop();

        if (!isvisited[top])
        {
            cout << top << " ";
            isvisited[top] = 1;
        }
        
        // push all the unvisited adj vertices
        for (int i = 0; i < Tvertices; i++)
        {
            if(!isvisited[i] && adj[top][i]) 
                stk.push(i);
        }
        
    }
    cout << endl;

}

// print all vertices in dfs manner
// ie if they r not connected or if there's no cycle:
void dfsalliter()
{
    for (int i = 0; i < Tvertices; i++)
        if(!isvisited[i]) dfsiter(i);   
}

void dfsrec(int ver)
{
    cout << ver << " ";
    isvisited[ver] = 1;

    for (int i = 0; i < Tvertices; i++)
    {
      if (adj[ver][i] && !isvisited[i])
            dfsrec(i);
    }
}

void bfs(int ver)
{   // Do I need initial waiting visited ?
    for (int i = 0; i < Tvertices; i++)
    {
        isvisited[i] = 0;
    }

    que.push(ver);
    isvisited[ver] = 1;

    while(!que.empty())
    {
        int front = que.front();
        que.pop();
        cout << front << " ";

        // push all the adj vertices
        for (int i = 0; i < Tvertices; i++)
        {
            if(adj[front][i] && !isvisited[i]) 
            {
                que.push(i);
                isvisited[i] = 1;
            }
        }
        
    }
    cout << endl;
}

void insertvertex()
{
    Tvertices++;
}

void deletevertex(int x)
{
    for (int j = x; j < Tvertices; j++)
    {
        for (int i = 0; i < Tvertices; i++)
        {
            adj[j][i] = adj[j + 1][i];
            adj[i][j] = adj[i][j + 1];
        }
    }
    
    Tvertices--;
}

void addedge()
{
    int origin, des;
    cout << "Enter origin n des" << endl;
    cin >> origin >> des;

    adj[origin][des] = 1;
}

void deleteedge()
{
    int origin, des;
    cout << "Enter origin n des" << endl;
    cin >> origin >> des;

    adj[origin][des] = 0;
}


void display()
{
    for (int i = 0; i < Tvertices; i++)
    {
        for (int j = 0; j < Tvertices; j++)
        {
            cout << adj[i][j];
        }
        cout << endl;
    }
    
}

int main()
{   
    cout << "Enter total vertices" << endl;
    cin >> Tvertices;

    while (1)
    {
        // cout << "1 Insert vertex" << endl;
        // cout << "2 Delete vertex" << endl;
        // cout << "3 Insert edge" << endl;
        // cout << "4 Delete vertex" << endl;
        // cout << "5 display" << endl;
        // cout << "6 bfs" << endl;
        // cout << "7 exit" << endl;
        // cout << "8 enter mult edges" << endl;

        int option;
        cin >> option;
        
        switch (option)
        {
        case 1:
            insertvertex();
            break;
        case 2:
            int ver;
            cin >> ver;
            deletevertex(ver);
            break;
        case 3:
            addedge();
            break;
        case 4:
            deleteedge();
            break;
        case 5:
            display();
            break;
        case 6:
            int verr;
            cin >> verr;
            bfs(verr);
            break;
        case 7:
            exit(0);
            break;
        case 8:
            int n;
            cin >> n;
            while(n)
            {
                n--;
                addedge();
            }
            break;
        case 9:
            int verrr;
            cin >> verrr;
            for (int i = 0; i < Tvertices; i++)
                isvisited[i] = 0;
            dfsrec(verrr);
            cout << endl;
            break;
        case 10:
            int y;
            cin >> y;
            dfsiter(y);
            break;
        }
    }
    
    return 0;
}