struct Dinic {
    struct edge {
        int to;
        int cap;
        int rev;
    };

    vector<vector<edge>> graph;
    int N;
    vector<int> dist;
    vector<int> iter;

    Dinic(int n) : N(n) { graph.assign(N, vector<edge>()); }

    void add_edge(int from, int to, int cap) {
        graph[from].push_back(edge{to, cap, (int)graph[to].size()});
        graph[to].push_back(edge{from, 0, (int)graph[from].size() - 1});
    }

    void bfs(int s) {
        dist.assign(N, -1);
        queue<int> que;
        dist[s] = 0;
        que.push(s);
        while (que.size()) {
            int p = que.front();
            que.pop();
            for (int i = 0; i < graph[p].size(); i++) {
                edge &e = graph[p][i];
                if (e.cap > 0 && dist[e.to] < 0) {
                    dist[e.to] = dist[p] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int flow) {
        if (v == t) {
            return flow;
        }
        for (int &i = iter[v]; i < graph[v].size(); i++) {
            edge &e = graph[v][i];
            if (e.cap > 0 && dist[v] < dist[e.to]) {
                int min_f = dfs(e.to, t, min(flow, e.cap));
                if (min_f > 0) {
                    e.cap -= min_f;
                    graph[e.to][e.rev].cap += min_f;
                    return min_f;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (true) {
            bfs(s);
            if (dist[t] < 0) {
                return flow;
            }
            iter.assign(N, 0);
            int flow_sub;
            while (true) {
                flow_sub = dfs(s, t, 1000000009);
                if (flow_sub > 0) {
                    flow += flow_sub;
                } else {
                    break;
                }
            }
        }
    }
};
