#include<vector.h>
template <typename T>
int Vector<T>::disordered() const{
    int n=0;
    for(int i = 1;i< _size; i++){
        n+=(_elem[i-1]>_elm=[i]);
        //判断逆序对
    }
    return n;
}//n>0就是存在无序