int atoi(string str) {
    int ans = 0;
    int n = str.size();
    int i=0, sign=1;
    if(str[0] == '-'){
        sign = -1;
        i++;
    }
    for(; i<n; i++){
        if(str[i]-'0'>= 0 && str[i]-'0'<=9){
            ans= ans*10+(str[i]-'0');
        }
    }
    return ans*sign;
}