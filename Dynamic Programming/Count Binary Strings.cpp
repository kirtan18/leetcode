
//////////////////////////////// Using Space /////////////////////////////////

int main(){
    
    int n;
    cin >> n;
    vector<int>a(n+1,0);
    vector<int>b(n+1,0);
    a[1] = 1;
    b[1] = 1;
    for(int i = 2 ; i <= n ; i++){
        b[i] = b[i-1] + a[i-1];
        a[i] = b[i-1];
    }
    cout << a[n] + b[n] << "\n"; 
    return 0;
}

/////////////////////////////////// Without Space //////////////////////////////////////

int main(){
    
    int n;
    cin >> n;
    int first_a = 1;
    int first_b = 1;
    int sec_a ,sec_b;
    
    for(int i = 2 ; i <= n ; i++){
        sec_b = first_a + first_b;
        sec_a = first_b;
        first_a = sec_a;
        first_b = sec_b;
    }
    cout << sec_a + sec_b << "\n";
    return 0;
}
