struct PrimalDual {
    struct edge {
        int to;
        int cap;
        ll cost;
        int rev;
    };

    ll INF = 8000000000000000000;
    vector<vector<edge>> graph;
    int N;
    vector<ll> dist;
    vector<int> prevv;
    vector<int> preve;
    vector<ll> pot;

    PrimalDual(int n) : N(n) { graph.assign(N, vector<edge>()); }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pque;

    void add_edge(int from, int to, int cap, ll cost) {
        graph[from].push_back(edge{to, cap, cost, (int)graph[to].size()});
        graph[to].push_back(edge{from, 0, -cost, (int)graph[from].size() - 1});
    }

    ll min_cost_flow(int s, int t, int f) {
        ll ret = 0;
        pot.assign(N, 0);
        preve.assign(N, -1);
        prevv.assign(N, -1);

        while (f > 0) {
            dist.assign(N, INF);
            pque.push(pair<int, int>(0, s));
            dist[s] = 0;
            while (pque.size()) {
                pair<int, int> p = pque.top();
                pque.pop();
                if (dist[p.second] != p.first) {
                    continue;
                }
                for (int i = 0; i < graph[p.second].size(); i++) {
                    edge &e = graph[p.second][i];
                    if (e.cap > 0 && dist[e.to] > dist[p.second] + e.cost +
                                                      pot[p.second] -
                                                      pot[e.to]) {
                        dist[e.to] =
                            dist[p.second] + e.cost + pot[p.second] - pot[e.to];
                        prevv[e.to] = p.second;
                        preve[e.to] = i;
                        pque.push(pair<int, int>(dist[e.to], e.to));
                    }
                }
            }
            if (dist[t] == INF) {
                return -1;
            }
            for (int i = 0; i < N; i++) {
                pot[i] += dist[i];
            }
            int f_sub = f;
            int now_v = t;
            while (now_v != s) {
                f_sub = min(f_sub, graph[prevv[now_v]][preve[now_v]].cap);
                now_v = prevv[now_v];
            }
            f -= f_sub;
            ret += f_sub * pot[t];
            now_v = t;
            while (now_v != s) {
                edge &e = graph[prevv[now_v]][preve[now_v]];
                e.cap -= f_sub;
                graph[now_v][e.rev].cap += f_sub;
                now_v = prevv[now_v];
            }
        }
        return ret;
    }
};