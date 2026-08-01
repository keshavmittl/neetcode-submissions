class DisjointSet {
   public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node) return node;

        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
   public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DisjointSet ds(n);

        unordered_map<string, int> mailNode;  // mail , owner(0,1,2)
        // this clubs two iterations if there is a match found or assign the owner to the email
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if (mailNode.find(mail) == mailNode.end()) {
                    mailNode[mail] = i;
                } else {
                    ds.unionBySize(i, mailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        // this pushes emails with the same parent to the parent index
        for (auto it : mailNode) {
            string mail = it.first;
            int node = it.second;

            int parent = ds.find(node);

            mergedMail[parent].push_back(mail);
        }
        // till this ,common emails are all clubed together  ans now we will print them to the
        // answer
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) continue;  // if the size of the owner is zero

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);  // pushes the name of the person first

            for (auto& mail : mergedMail[i])
                temp.push_back(mail);  // pushes all the emails of the owner

            ans.push_back(temp);
        }

        return ans;
    }
};