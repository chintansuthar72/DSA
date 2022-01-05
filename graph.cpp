#include <bits/stdc++.h>
using namespace std;

class graph
{
    // Adjcency List vretices are only integers
    int v;
    vector<int> *adjList;

public:
    graph(int sizeOfVertices)
    {
        v = sizeOfVertices;
        adjList = new vector<int>[v];
    }

    void addEdge(int x, int y)
    {
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    void printGraph()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "VERTEX " << i << "-> ";
            for (int x : adjList[i])
            {
                cout << x << ":";
            }
            cout << endl;
        }
    }

    void bfs(int src)
    {
        unordered_map<int, bool> visit;
        queue<int> q;
        q.push(src);
        visit[src] = true;
        while (!q.empty())
        {
            int tmp = q.front();
            q.pop();
            cout << tmp << " ";
            for (auto x : adjList[tmp])
            {
                if (visit[x] != true)
                {
                    visit[x] = true;
                    q.push(x);
                }
            }
        }
    }

    void dfs(int src)
    {
        unordered_map<int, bool> visit;
        visit[src] = 1;
        cout << src << " ";
        for (auto i : adjList[src])
        {
            if (visit[i] == false)
            {
                dfs(i);
            }
        }
    }

    // general graph
    //    unordered_map<string,list<pair<string,int>>> adjList;
    //
    //    public:
    //
    //    void addEdge(string value1,string value2,bool biDire,int weight){
    //        adjList[value1].push_back(make_pair(value2,weight));
    //        if(biDire)
    //            adjList[value2].push_back(make_pair(value1,weight));
    //    }
    //
    //    void printGraph(){
    //        for(auto p : adjList){
    //            cout << p.first << " -> ";
    //            for(auto x : (p.second)){
    //                cout << "(" <<x.first <<","<<x.second<<")"<<" : ";
    //            }
    //            cout << endl;
    //        }
    //    }
    //
    //    void bfs(string src){
    //
    //        unordered_map<string , bool> visited;
    //        queue<string> tmp;
    //
    //        tmp.push(src);
    //        visited[src] = true;
    //
    //        while(tmp.empty() == false) {
    //
    //            string node = tmp.front();
    //            tmp.pop();
    //            cout << node << " ";
    //
    //            for(auto x : adjList[node]) {
    //
    //                if(visited[x.first]==false) {
    //                    visited[x.first] = true;
    //                    tmp.push(x.first);
    //                }
    //            }
    //        }
    //    }
};

signed int main()
{
    // vretices are only integers
    graph g(6);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 0);
    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    //     g.printGraph();
    g.bfs(0);
    cout << endl;
    g.dfs(0);
    //general graph
    //    Graph g;
    //    g.addEdge("a","b", true,30);
    //    g.addEdge("b","c", true,20);
    //    g.addEdge("a","c", true,40);
    //    g.addEdge("d","c", true,50);
    //    g.printGraph();
    // g.bfs("c");
    return 0;
}
