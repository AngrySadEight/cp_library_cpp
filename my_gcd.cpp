ll my_gcd(ll a, ll b){
    //ユークリッドの互除法を用いて，aとbの最大公約数を求める．
    ll ret = 0;
    if (a < b){
        swap(a, b);
    }
    if (b == 0){
        ret = a;
    }
    else{
        ret = my_gcd(b, a % b);
    }
    return ret;
}