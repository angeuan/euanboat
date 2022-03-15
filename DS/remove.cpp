#include<vector.h>
template <typename T>
T Vector<T>::remove(Rank r){
    T e = _elem[r];
    remove(r,r+1);
    return e;
}
template <typename T>
int Vector<T>::remove(Rank lo,Rank hi){
    if(lo == hi) return 0;
    while(hi<_size) _elem[lo++] = elem[hi++];
    _size = lo; shrink();
    return hi-lo;
}//区间操作

