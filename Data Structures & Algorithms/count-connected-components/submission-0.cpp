class dsu{
    public:
    vector<int>size;
    vector<int>parent;
    int cap ; 
    dsu(int cap){
        this->cap = cap;
        parent.resize(cap);
        for(int i = 0 ; i<cap ; i++)parent[i]= i;
        size.resize(cap , 1);
    }

    int find(int node){
        if(node ==parent[node])return node; 

        return node = find(parent[node]);
    }

    void unite(int u , int v){
        u =find(u);
        v= find(v);

        if(u == v){
            return ;
        }

        if(size[u] > size[v]){
            parent[v] = u;
            size[u] +=size[v];
        }
        else{
            parent[u] = v; 
            size[v] +=size[u];
        }
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        dsu ds(n); 
        for(auto edge: edges){
            ds.unite(edge[0] ,edge[1]);
        }

        int cnt =0 ; 
        for(int i = 0 ; i<n ;i++){
            if(ds.parent[i]  == i)cnt++;
        }
        return cnt ;
    }
};
