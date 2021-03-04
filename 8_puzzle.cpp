#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 3

class Node
{
public:
    Node *parent;
    int x, y;
    int mat[N][N];
    ll hcost;
    Node()
    {
        parent = NULL;

        x = 0;
        y = 0;
        hcost = 1e9;
        memset(mat, 0, sizeof(mat));
    }
    Node(int x_blank, int y_blank, int mat_new[N][N])
    {
        parent = NULL;
        x = x_blank;
        y = y_blank;
        memcpy(mat, mat_new, sizeof mat);
    }

    void setMatrix(int mat_new[N][N])
    {
        memcpy(mat, mat_new, sizeof mat);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (mat_new[i][j] == 0)
                {
                    this->x = i;
                    this->y = j;
                }
            }
        }
    }
    void setParent(Node *parent)
    {
        this->parent = parent;
    }
    Node *getParent()
    {
        return this->parent;
    }
    void print()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << this->mat[i][j] << " ";
            cout << endl;
        }
        cout << "Blank : x = " << this->x << ", y = " << this->y << endl;
        cout << "Cost : " << this->hcost << endl;
    }
};
vector<Node *> moveGen(Node *node)
{
    int mat[N][N];
    memcpy(mat, node->mat, sizeof mat);
    int x = node->x, y = node->y;
    vector<Node *> moved;
    //blank space moved up
    if (x != 0)
    {
        int change_mat[N][N];
        memcpy(change_mat, mat, sizeof mat);
        change_mat[x][y] = mat[x - 1][y];
        change_mat[x - 1][y] = 0;
        Node *upNode = new Node(x - 1, y, change_mat);
        upNode->setParent(node);
        moved.push_back(upNode);
    }
    //blank space moved down
    if (x != N - 1)
    {
        int change_mat[N][N];

        memcpy(change_mat, mat, sizeof mat);
        change_mat[x][y] = mat[x + 1][y];
        change_mat[x + 1][y] = 0;
        Node *downNode = new Node(x + 1, y, change_mat);
        downNode->setParent(node);
        moved.push_back(downNode);
    }
    //blank space moved left
    if (y != 0)
    {
        int change_mat[N][N];
        memcpy(change_mat, mat, sizeof mat);
        change_mat[x][y] = mat[x][y - 1];
        change_mat[x][y - 1] = 0;
        Node *leftNode = new Node(x, y - 1, change_mat);
        leftNode->setParent(node);
        moved.push_back(leftNode);
    }
    //blank space moved right
    if (y != N - 1)
    {
        int change_mat[N][N];
        memcpy(change_mat, mat, sizeof mat);
        change_mat[x][y] = mat[x][y + 1];
        change_mat[x][y + 1] = 0;
        Node *rightNode = new Node(x, y + 1, change_mat);
        rightNode->setParent(node);
        moved.push_back(rightNode);
    }
    return moved;
}
bool goalTest(int mat_check[N][N], int final[N][N])
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mat_check[i][j] != final[i][j])
                return false;
        }
    }
    return true;
}
int heuristicDisplacedNode(Node *node, Node *final)
{
    int mat[N][N];
    int mat_final[N][N];
    memcpy(mat, node->mat, sizeof mat);
    memcpy(mat_final, final->mat, sizeof mat);
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j] != mat_final[i][j])
                count++;
        }
    }
    return count;
}
int heuristicManhattanDistance(Node *node, Node *final)
{
    int mat[N][N];
    int mat_final[N][N];
    memcpy(mat, node->mat, sizeof mat);
    memcpy(mat_final, final->mat, sizeof mat);
    int count = 0;
    pair<int, int> position[9];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            position[mat_final[i][j]] = make_pair(i, j);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            count += abs(position[mat[i][j]].first - i);
            count += abs(position[mat[i][j]].second - j);
        }
    }
    return count;
}
void printPath(Node *root)
{
    if (root == NULL)
        return;
    printPath(root->parent);
    root->print();
    cout << endl;
}
struct comp
{
    bool operator()(const Node *lhs, const Node *rhs) const
    {
        return (lhs->hcost) > (rhs->hcost);
    }
};
void solveh1(Node *start, Node *final)
{
    start->hcost = heuristicDisplacedNode(start, final);
    priority_queue<Node *, std::vector<Node *>, comp> pq;
    pq.push(start);
    int count = 0;
    int prevCost;
    while (!pq.empty())
    {
        Node *min = pq.top();
        pq.pop();
        prevCost = min->hcost;
        if (goalTest(min->mat, final->mat))
        {
            printPath(min);
            return;
        }
        vector<Node *> moved = moveGen(min);
        for (int i = 0; i < moved.size(); i++)
        {
            Node *node = moved[i];
            node->hcost = heuristicDisplacedNode(node, final);
            if (node->hcost < prevCost)
                pq.push(node);
        }
        count++;
    }
    start->print();
    final->print();
    cout << "NOT POSSIBLE" << endl;
}
void solveh2(Node *start, Node *final)
{
    start->hcost = heuristicManhattanDistance(start, final);
    priority_queue<Node *, std::vector<Node *>, comp> pq;
    pq.push(start);
    int count = 0;
    int prevCost;
    while (!pq.empty())
    {
        Node *min = pq.top();
        pq.pop();
        prevCost = min->hcost;
        if (goalTest(min->mat, final->mat))
        {
            printPath(min);

            return;
        }
        vector<Node *> moved = moveGen(min);
        for (int i = 0; i < moved.size(); i++)
        {
            Node *node = moved[i];
            node->hcost = heuristicManhattanDistance(node, final);
            if (node->hcost < prevCost)
                pq.push(node);
        }
        count++;
    }
    start->print();
    final->print();
    cout << "NOT POSSIBLE" << endl;
}
int main()
{
    Node *start = new Node();
    int mat[N][N];
    srand(unsigned(time(0)));
    vector<int> arr;
    for (int j = 0; j < 9; ++j)
        arr.push_back(j);
    random_shuffle(arr.begin(), arr.end());
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mat[i][j] = arr[count];
            count++;
        }
    }
    start->setMatrix(mat);
    Node *final = new Node();

    random_shuffle(arr.begin(), arr.end());
    count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mat[i][j] = arr[count];
            count++;
        }
    }
    final->setMatrix(mat);
    final->hcost = 0;
    cout << "By heuristic function which calculates the number of displaced nodes : " << endl;
    solveh1(start, final);
    cout << endl;
    cout << "By heuristic function which calculates the Manhattan distance:" << endl;
    solveh2(start, final);
    return 0;
}