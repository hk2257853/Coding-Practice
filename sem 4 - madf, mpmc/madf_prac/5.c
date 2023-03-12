#include "stdio.h"

// better put a var o n t, n give them the req values...
// see stuff about 2d matrix with arrays (have worked with vec only recently...)

int main()
{
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};


    int p, q, r, s, t, u, v;
    p = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    q = B[0][0] * (A[1][0] + A[1][1]);
    r = A[0][0] * (B[1][2] - B[2][2]);
    s = A[1][1] * (B[2][1] - B[1][1]);
    t = B[1][1] * (A[1][1] + A[2][2]);
    u = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    v = (A[0][1] - A[1][1]) * (B[1][1] + B[1][0]);
    
    int a, b, c, d;
    a = p + s -t;
    b = r + t;
    c = q + s;
    d = p + r -q;

    printf("%d %d %d %d", a, b, c, d);

    return 0;
}