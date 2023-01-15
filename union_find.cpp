struct union_find{
    vector<int> par;
    vector<int> rank;
    vector<int> siz;
    vector<int> siz2;

    union_find(int N) : par(N), rank(N), siz(N), siz2(N){
        for (int i = 0; i < N; i++){
            par[i] = i;
            rank[i] = 0;
            siz[i] = 1;
            siz2[i] = 0;
        }
    }
    //宣言パート．例えばunion_find tree(N); のように宣言する．

    int root(int x){
        if (par[x] == x){
            return x;
        }
        return par[x] = root(par[x]);
    }
    //頂点に対して，その代表元となる頂点の番号を返す．

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if (rx == ry){
            siz2[rx]++;
            return;
        }
        if (siz[rx] < siz[ry]){
            par[rx] = ry;
            siz[ry] += siz[rx];
            siz2[ry] += siz2[rx];
            siz2[ry]++;
        }
        else{
            par[ry] = rx;
            siz[rx] += siz[ry];
            siz2[rx] += siz2[ry];
            siz2[rx]++;
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
    }
    //頂点xを含む連結成分と，頂点yを含む連結成分をマージする．
    //計算量削減のため，それぞれの木のサイズをあらかじめカウントしておく．
    //木のサイズの大きいほうに小さいほうをマージするようにする．

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    //頂点xと頂点yが同じ連結成分に属するかを判定する．

    int size(int x){
        return siz[root(x)];
    }
    //頂点xが含まれる連結成分における頂点の数．

    int size2(int x){
        return siz2[root(x)];
    }
    //頂点xが含まれる連結成分における辺の数．
};