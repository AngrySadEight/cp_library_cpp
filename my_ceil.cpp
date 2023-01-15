ll my_ceil(ll A, ll B){
    //AをBで割った値よりも小さくない最小の整数を返す。B>0
    ll ret;
    if (A >= 0){
        ret = (A + B - 1) / B;
    }
    else{
        ret = ((A * (-1)) / B) * (-1);
    }
    return ret;
}