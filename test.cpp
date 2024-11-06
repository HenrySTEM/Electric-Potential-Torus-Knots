#include <bits/stdc++.h>
#include "complex.h"

int main(){
    ld k = -10;
    while(k <= 10){
        com a(-4,k);
        com xp = sqrtp(a*a-4);
        com xn = sqrtn(a*a-4);
        cout << k << ' ' << mag(a + xp)/2 << ' ' << mag(a + xn)/2 << endl;
        k += 0.01;
    }
}