struct BIT{
    //Binary Indexed Tree.
    int N;
    vector<ll> vec;
    BIT(int N_): N(N_), vec(N + 1){
        for (int i = 0; i < N + 1; i++){
            vec[i] = 0;
        }
    }
    
    void add(int p, ll x){
        for (int i = p; i <= N; i += (i & -i)){
            vec[i] += x;
        }
    }

    ll sum(int p){
        ll sum = 0;
        for (int i = p; i > 0; i -= (i & -i)){
            sum += vec[i];
        }
        return sum;
    }
};

