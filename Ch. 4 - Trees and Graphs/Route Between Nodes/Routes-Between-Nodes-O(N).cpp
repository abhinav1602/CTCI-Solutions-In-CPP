#include<bits/stdc++.h>
using namespace std;
int vis[100000] = {0};

checkIfReachable(vector<int> v[], int source, int destination){
    queue<int> q;
    q.push(source);

    int top, children_len;

    while(!q.empty()){
        top = q.front();
        q.pop();

        if(top == destination)
            return true;

        if(vis[top] != 1){
            children_len = v[top].size();

            for(int i=0; i<children_len; i++){
                q.push(v[top][i]);
            }
            vis[top] = 1;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;

    // store graph in the form of adjacency list
    vector<int> v[n+1];

    // number of entries for edges = q
    int q, x, y;
    cin>>q;
    memset(vis, 0, sizeof(vis));

    for(int i=0; i<q; i++) {
        cin>>x>>y;
        // there is an edge from x to y
        v[x].push_back(y);
        //v[y].push_back(x);
    }

    int vis[n+1] = {0};

    // enter source and destination node
    int source, destination;
    cin>>source>>destination;

    bool Reachable = checkIfReachable(v, source, destination);
    if(Reachable)
        cout<<"Reachable";
    else
        cout<<"Not Reachable";
    return 0;
}

