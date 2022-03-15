#include<vector.h>
template <typename T>
void Vector<T>::expand(){
    if(_size < _capacity) return;
    _capacity = max(_capacity,DEFAUL_CAPACITY);
    T* oldElem = _elem; _elem = new T[_capacity <<= 1];
    for(int i = 0;i < _size; i++)
        _elem[i] = oldElem[i];
    delete [] oldElem;
}