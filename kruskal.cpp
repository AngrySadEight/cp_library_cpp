ll kruskal(vector<pair<ll, pair<int, int>>> &connect, union_find tree){
    //クラスカル法．1辺を結ぶ2頂点の番号とその辺の長さが与えられた場合の，最小全域木の辺の重みの総和を求める．
    // connect関数には，「1辺の長さ」「2頂点の番号」をあらかじめ入れておく．
    ll ans = 0;
    for (ll i = 0; i < connect.size(); i++){
        if (!tree.same(connect[i].second.first, connect[i].second.second)){
            ans += connect[i].first;
            tree.unite(connect[i].second.first, connect[i].second.second);
        }
    }
    return ans;
}
