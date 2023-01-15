vector<int> topological_sort(vector<vector<int>> &connection, vector<int> &count, int N){
    // vectorをトポロジカルソートして返す．
    // connectionには，その頂点から直接（有向辺で）行くことのできる頂点の番号を入れておく．
    // countには，その頂点に（有向辺で）入ってくる辺の数を入れておく．
    vector<int> ans(0);
    queue<int> que;

    for (int i = 0; i < N; i++){
        if (count[i] == 0){
            que.push(i);
        }
    }

    while (que.size() != 0){
        int v = que.front();
        que.pop();

        for (int i = 0; i < connection[v].size(); i++){
            count[connection[v][i]] -= 1;
            if (count[connection[v][i]] == 0){
                que.push(connection[v][i]);
            }
        }
        ans.push_back(v);
    }

    return ans;
}