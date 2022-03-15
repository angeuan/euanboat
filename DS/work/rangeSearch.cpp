#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int room[500010];

int mybinSearch(int v[],int const& e,int lo,int hi){
    while(lo<hi){
        int mi = (lo + hi)>>1;
        (e < v[mi]) ? hi = mi : lo = mi + 1;
    }
    return --lo;
}

