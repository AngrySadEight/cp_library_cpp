void bellman_ford(vector<ll> &from, vector<ll> &to, vector<ll> &cost, vector<ll> &dis, ll v, ll N, ll M, bool &negative){
    //ベルマンフォード法。
    //頂点fromから頂点toまでの長さcostの辺が，M本張られている。頂点数はN。
    //このもとで，始点vからの最短距離disを求めることにする。
    //負の閉路がある場合はnegativeがtrueになる。
    vector<bool> hasroute(N, false);
    hasroute[v] = true;
    vector<bool> nega(N, false);
    for (ll i = 0; i < N; i++){
        bool update = false;
        for (ll j = 0; j < M; j++){
            if (dis[to[j]] > dis[from[j]] + cost[j]){
                dis[to[j]] = dis[from[j]] + cost[j];
                if (hasroute[from[j]]) hasroute[to[j]] = true;
                update = true;
                if (i == N - 1){
                    nega[to[j]] = true;
                }
            }
        }
        if (!update){
            break;
        }
    }

    for (ll i = 0; i < N; i++){
        for (ll j = 0; j < M; j++){
            if (hasroute[from[j]] && nega[from[j]])
                nega[to[j]] = true;
        }
    }
    if (hasroute[N - 1] && nega[N - 1]) negative = true;
}