#include<vector.h>
template <typename T> //0 <= lo <= hi <= _size
static Rank fibSearch( T * S, T const & e, Rank lo, Rank hi ) {
for ( Fib fib(hi - lo); lo < hi; ) { //Fib数列制表备查
while ( hi - lo < fib.get() ) fib.prev(); //自后向前顺序查找轴点（分摊O(1)）
Rank mi = lo + fib.get() - 1; //确定形如Fib(k) - 1的轴点
if ( e < S[mi] ) hi = mi; //深入前半段[lo, mi)
else if ( S[mi] < e ) lo = mi + 1; //深入后半段(mi, hi)
else return mi; //命中
}
return -1; //查找失败
}