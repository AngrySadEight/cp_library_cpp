ll my_pow(ll x, ll n, ll mod){
    //　繰り返し二乗法で，x^nをmodで割った余りを求める．
    ll ret;
    if (n == 0){
        ret = 1;
    }
    else if (n % 2 == 1){
        ret = (x * my_pow((x * x) % mod, n / 2, mod)) % mod;
    }
    else{
        ret = my_pow((x * x) % mod, n / 2, mod);
    }
    return ret;
}