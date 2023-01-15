vector<vector<ll>> matrix_pow(vector<vector<ll>> &M, vector<ll> &bin, ll N, ll K, ll mod){
    //行列累乗を計算する．M^x % modを計算する．ただし，xは陽には引数をとらない．
    //M: 行列M．bin: p_adic(x, 2, K)（xの2進数表現）．N: 行列Mの大きさ．K: 配列binの長さ．mod: （取る場合は）modの値．
    vector<vector<ll>> matrix(N, vector<ll>(N));
    for (ll i = 0; i < N; i++){
        for (ll j = 0; j < N; j++){
            matrix[i][j] = M[i][j];
        }
    }
    vector<vector<ll>> ans_old_matrix(N, vector<ll>(N));
    for (ll i = 0; i < N; i++){
        for (ll j = 0; j < N; j++){
            if (i == j)
                ans_old_matrix[i][j] = 1;
            else
                ans_old_matrix[i][j] = 0;
        }
    }

    vector<vector<ll>> ans_new_matrix(N, vector<ll>(N));
    for (ll i = 0; i < N; i++){
        for (ll j = 0; j < N; j++){
            ans_new_matrix[i][j] = 0;
        }
    }

    vector<vector<ll>> new_matrix(N, vector<ll>(N));
    for (ll i = 0; i < N; i++){
        for (ll j = 0; j < N; j++){
            new_matrix[i][j] = 0;
        }
    }

    for (ll x = 0; x < K; x++){
        if (bin[K - 1 - x] == 1){
            for (ll i = 0; i < N; i++){
                for (ll j = 0; j < N; j++){
                    for (ll k = 0; k < N; k++){
                        ans_new_matrix[i][j] = (ans_new_matrix[i][j] + (ans_old_matrix[i][k] * matrix[k][j])) % mod;
                    }
                }
            }
            for (ll i = 0; i < N; i++){
                for (ll j = 0; j < N; j++){
                    ans_old_matrix[i][j] = ans_new_matrix[i][j];
                    ans_new_matrix[i][j] = 0;
                }
            }
        }
        for (ll i = 0; i < N; i++){
            for (ll j = 0; j < N; j++){
                for (ll k = 0; k < N; k++){
                    new_matrix[i][j] = (new_matrix[i][j] + (matrix[i][k] * matrix[k][j])) % mod;
                }
            }
        }
        for (ll i = 0; i < N; i++){
            for (ll j = 0; j < N; j++){
                matrix[i][j] = new_matrix[i][j];
                new_matrix[i][j] = 0;
            }
        }
    }

    return ans_old_matrix;
}