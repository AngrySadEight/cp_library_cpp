void dijkstra(vvpll &graph, ll v, vl &dist){
    //ダイクストラ法．
    //graphには，頂点番号に対して，「直接繋がっている辺の相手の頂点番号とその重み」を記録してある．
    //配列distを，vからの最短距離で更新する．
    priority_queue<pll, vpll, greater<pll>> pque;
    pque.push(pll(0, v));
    dist[v] = 0;
    while(pque.size()){
        pll p = pque.top();
        pque.pop();
        if (dist[p.second] != p.first){
            continue;
        }
        for (auto x: graph[p.second]){
            if (dist[x.first] > dist[p.second] + x.second){
                dist[x.first] = dist[p.second] + x.second;
                pque.push(pll(dist[x.first], x.first));
            }
        }
    }
}