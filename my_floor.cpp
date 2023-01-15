ll my_floor(ll A, ll B){
    //AをBで割った値を超えない最大の整数を返す。B>0
    ll ret;
    if (A >= 0){
        ret = A / B;
    }
    else{
        ret = ((A * (-1) + B - 1) / B) * -1;
    }
    return ret;
}