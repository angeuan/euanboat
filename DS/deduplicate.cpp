#include<vector.h>

template <typename T>
int Vector<T>::deduplicate(){
    int oldSize = _size;
    Rank i = 1;
    while (i<_size){
        (find(_elem[i],0,i)?i++:remove(i));
    }
    return oldSize - _size;
}
//不变性，单调性
//可标记重复元素，再统一删除