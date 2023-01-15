vector<ll> n_adic(ll i, ll n, ll N){
    //iのn進法表記を，長さNの配列形式で表現する．
    ll x = 1;
    rep(j, N){
        x *= n;
    }
    vector<ll> vec(N);
    rep(j, N){
        x /= n;
        vec[j] = i / x;
        i -= x * vec[j];
    }
    return vec;
}