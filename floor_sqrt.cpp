ll floor_sqrt(ll X){
    //平方根の整数切り捨て．
    ll left = 1;
    ll right = 3000000003;
    while(true){
        if (right - left <= 1){
            break;
        }
        ll center = (left + right) / 2;
        if (center * center > X){
            right = center;
        }
        else{
            left = center;
        }
    }
    return left;
}