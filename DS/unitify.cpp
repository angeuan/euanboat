#include<vector.h>
template <typename T> int Vector<T>::uniquify(){
    int oldSize = _size; int i=0;
    while(i<_size - 1)
        (_elem[i]==_elem[i+1])?remove(i+1):i++;
    return oldSize - _size;
}//效率低

template<typename T>int Vector<T>::uniquify(){
    int i = 0,j = 0;
    while(++j < _size)
        if(_elem[i] != _elem[j]) _elem[++i] = _elem[j];
    _size = ++i; shrink();
    return j - i;       
}//有序向量的高效唯一化