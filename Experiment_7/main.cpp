class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto i : flights){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({w,v});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<>> q;
        vector<int> st(n,INT_MAX);
        st[src]  = 0;
        q.push({0,src,0}); // w , u , stop
        while(!q.empty()){
            int w = q.top()[0];
            int u = q.top()[1];
            int s = q.top()[2];
            q.pop();
            if(u == dst) return w;
            if(s > k || s > st[u]) continue;
            st[u] = s;
            for(auto i : adj[u]){
                int wd = i.first;
                int v = i.second;
                q.push({w+wd,v,s + 1});
            }
        }
        return -1;
    }
};
