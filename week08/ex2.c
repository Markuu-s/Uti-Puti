#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define szByte 10 * 1000 * 1000

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        void *leakMemory = malloc(szByte);
        memset(leakMemory, 0, szByte);
        sleep(1);
    }
    return 0;
}

/*

procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 2  0    872 293756 451024 3634508    0    0    16    51  283  220  8  3 89  0  0
 1  0    872 303364 451024 3632664    0    0     0   244  595 1679  2  1 97  0  0
 0  0    872 304112 451024 3632664    0    0     0     0  382  929  1  1 98  0  0
 0  0    872 321288 451024 3632532    0    0     0     0  432 1275  1  1 97  0  0
 0  0    872 320988 451032 3632548    0    0     0   180  406 1008  1  1 99  0  0
 1  0    872 316728 451032 3636780    0    0     0     0  611 1760  2  1 97  0  0
 0  0    872 312648 451032 3637112    0    0     0   732  591 1800  3  1 96  0  0
 0  0    872 315204 451032 3636976    0    0     0     0  313  891  1  0 99  0  0
 1  0    872 318280 451032 3633320    0    0     0   176 1003 2554  3  1 96  0  0
 1  0    872 319104 451032 3633380    0    0     0     0 1488 3021  4  2 95  0  0
 0  0    872 312420 451040 3641516    0    0     0   216 1699 3382  4  2 94  0  0
 0  0    872 312444 451048 3641284    0    0     0   232 1262 1890  2  1 97  0  0
 0  0    872 321012 451048 3632584    0    0     0     0  846  804  1  1 99  0  0
 0  0    872 318688 451048 3632600    0    0     0     0  326  834  1  1 98  0  0
 0  0    872 324436 451048 3632664    0    0     0   208  361  903  1  0 99  0  0
 0  0    872 294708 451056 3661600    0    0     0   332  583 1640  2  1 96  0  0


si == so == 0 => nothing was swapped

*/