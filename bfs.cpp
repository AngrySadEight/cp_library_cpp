vector<int> bfs(vector<vector<int>> &graph, int v, int N){
    //隣接リスト形式で表された辺の重みが全て1のグラフに対して，vからの最短距離を求める．
    vector<int> dis(N, INF);
    queue<int> que;
    vector<int> isvisited(N, false);
    dis[v] = 0;
    isvisited[v] = true;
    que.push(v);
    while(que.size()){
        int p = que.front();
        que.pop();
        for (int x: graph[p]){
            if (isvisited[x]){
                continue;
            }
            isvisited[x] = true;
            dis[x] = dis[p] + 1;
            que.push(x);
        }
    }
    return dis;
}
