#include <stdio.h>
#include <stdlib.h>
#include <String.h>

class Bitmap
{
private:
    int N;
    char *M;

public:
    Bitmap(int n = 8)
    {
        M = new char[N = (n + 7) / 8];
        memset(M, 0, N);
    }
    ~Bitmap()
    {
        delete[] M;
        M = NULL;
    }
    void set(int k);
    void clear(int k);
    bool test(int k);
};
class Bitmap
{
private:
    int N;
    char *M;

public:
    Bitmap(int n = 8)
    {
        M = new char[N = (n + 7) / 8];
    }
};