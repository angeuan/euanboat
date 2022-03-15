#include<vector.h>
template <typename T>
static Rank binSearch(T* A,T const& e,Rank lo,Rank hi){
    while(lo < hi){
        Rank mi = (lo + hi)>>1;
        if(e < A[mi]) hi = mi;
        else if(A[mi] < e) lo = mi + 1;
        else return mi;
    }
    return -1;
}
template <typename T>
static Rank binSearch(T* A,T const& e,Rank lo,Rank hi){
    while(1<hi - lo){
        Rank mi = (lo + hi)>>1;
        (e < A[mi]) ? hi = mi:lo = mi + 1;
        
    }
    return (e==A[lo])?lo:-1;
}
template <typename T> static Rank binSearch( T * S, T const & e, Rank lo, Rank hi ) {
while ( lo < hi ) { //不变性：A[0, lo) <= e < A[hi, n)
Rank mi = (lo + hi) >> 1;
e < S[mi] ? hi = mi : lo = mi + 1; //[lo, mi)或(mi, hi)
} //出口时，必有S[lo = hi] = M
return lo - 1; //故，S[lo-1] = m
} //版本C
