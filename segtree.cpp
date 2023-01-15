struct segtree{
    vector<ll> vec;

    segtree(ll N) : vec(N){
        rep(i, N){
            vec[i] = 0;
        }
    }
    //初期化．segtree seg(N); のように宣言する．
    //サイズNは（用意したいセグ木の長さ）*2よりも大きい2べきの数で宣言する必要がある．

    void sum_update(ll k, ll a, ll N){ 
        // 0_indexed
        k += (N / 2);
        vec[k] = a;
        while (k > 1){
            k = k / 2;
            vec[k] = vec[k * 2] + vec[k * 2 + 1];
        }
    }
    //セグメントツリー上で和の計算を行う上での前処理．k番目の要素をaに変更して，なおかつ和の計算の前処理を行う．

    void max_update(ll k, ll a, ll N)
    { // 0_indexed
        k += (N / 2);
        vec[k] = a;
        while (k > 1)
        {
            k = k / 2;
            vec[k] = max(vec[k * 2], vec[k * 2 + 1]);
        }
    }
    //セグメントツリー上で最大値を求める上での前処理．k番目の要素をaに変更して，なおかつ最大値を求める前処理を行う．

    void min_update(ll k, ll a, ll N)
    { // 0_indexed
        k += (N / 2);
        vec[k] = a;
        while (k > 1)
        {
            k = k / 2;
            vec[k] = min(vec[k * 2], vec[k * 2 + 1]);
        }
    }
    //セグメントツリー上で最小値を求める上での前処理．k番目の要素をaに変更して，なおかつ最小値を求める前処理を行う．

    ll min_query(ll a, ll b, ll k, ll l, ll r)
    { // min_query(a,b,1,0,N / 2) a,b,l,r=0_indexed
        if (r <= a || b <= l)
            return 10000000000000000;
        if (a <= l && r <= b)
            return vec[k];
        ll vl = min_query(a, b, k * 2, l, (l + r) / 2);
        ll vr = min_query(a, b, k * 2 + 1, (l + r) / 2, r);
        return min(vl, vr);
    }
    //セグメントツリー上で，半開区間[a,b)(a,bは0_indexed)における最小値を求める．
    // k,l,rは固定で，k=1,l=0,r=N/2として良い．

    ll check(ll i, ll N)
    {
        return vec[i + N / 2];
    }
    // i番目の要素を確認する．

    ll max_query(ll a, ll b, ll k, ll l, ll r)
    { // max_query(a,b,1,0,N / 2) a,b,l,r=0_indexed
        if (r <= a || b <= l)
            return -100000000000000000;
        if (a <= l && r <= b)
            return vec[k];
        ll vl = max_query(a, b, k * 2, l, (l + r) / 2);
        ll vr = max_query(a, b, k * 2 + 1, (l + r) / 2, r);
        return max(vl, vr);
    }
    //セグメントツリー上で，半開区間[a,b)(a,bは0_indexed)における最大値を求める．
    // k,l,rは固定で，k=1,l=0,r=N/2として良い．

    ll sum_query(ll a, ll b, ll k, ll l, ll r)
    { // sum_query(a,b,1,0,N / 2) a,b,l,r=0_indexed
        if (r <= a || b <= l)
            return 0;
        if (a <= l && r <= b)
            return vec[k];
        ll vl = sum_query(a, b, k * 2, l, (l + r) / 2);
        ll vr = sum_query(a, b, k * 2 + 1, (l + r) / 2, r);
        return vl + vr;
    }
    //セグメントツリー上で，半開区間[a,b)(a,bは0_indexed)における和を求める。
    // k,l,rは固定で，k=1,l=0,r=N/2として良い．
};