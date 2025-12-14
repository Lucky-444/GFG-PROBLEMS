/* The functions which
builds the segment tree */
vector<int>seg;
void Build(int idx , int l , int r , int arr[]){
    if(l == r){
        seg[idx]  =arr[l];
        return ;
    }
    
    int mid = (l + r) >> 1; 
    Build(2 * idx + 1 , l , mid , arr);
    Build(2 * idx + 2 , mid + 1 , r , arr);
    
    seg[idx] = min(seg[2 * idx + 1] , seg[2 * idx + 2]);
}


int *constructST(int arr[], int n) {
    // Your code here
    seg.assign(4 * n , 1e9);
    
    Build(0 , 0 , n - 1 , arr);
    
    //Return the pointer to the internal array of the vector:
    //this will return this 
    return seg.data() ; 
}

int query(int idx , int l , int r, int left , int right){
    if(r < left || l > right){
        return 1e9 ;
    }
    
    if(l >= left && r <= right){
        return seg[idx] ; 
    }
    
    int mid = (l + r) >> 1;
    
    return min(query(2 * idx + 1 , l , mid , left , right) , query(2 * idx + 2 , mid + 1 , r , left , right)) ;
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b) {
    
    // Your code here
    
    return query(0 , 0 , n - 1 , a , b);
}