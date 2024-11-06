#include <bits/stdc++.h>
#include "complex.h"

ld n = 0;
ld p = 0;
ld q = 1;
ld res; 

// com func(com c){
//     com z(n,0);
//     com dist = (z - ((c - 1/c)/com(0,2)));
//     com speed = (q*q+2*p*p+p*p*(c+1/c)/2);
//     com den = (z*z+z*(com(0,1)/c - c*com(0,1)) + 5 + 2*c + 2/c);
//     return dist*sqrti(speed)/(sqrti(den)*den)/c/com(0,1);
// }

//electric field

com func(com c){
    com z(n,0);
    com dist = (z + ((c - 1/c)/com(0,2)));
    com mid = p*(2+(c+1/c)/2);
    com speed = (q*q+mid*mid);
    com den = (z*z+z*(com(0,1)/c - c*com(0,1)) + 5 + 2*c + 2/c);
    return dist*sqrti(speed)/(sqrti(den)*den*c);
}

//length function

com lenfunc(com c){
    com mid = p*(2+(c+1/c)/2);
    com speed = (q*q+mid*mid);
    return sqrti(speed)/c;
}

//electric field (alternative formulation)

com func2(com c){
    com z(n,0);
    com num = (c*c - 2*I*c*z - 1)*sqrtp((p*p*c*c/2) + (c*(q*q+2*p*p)) + (p*p/2));
    //com den = (c*c*(2-z*I)) + (c*(5+z*z)) + (2+z*I);
    com den = (2-z*I)*(c+2+z*I)*(c+(z*I+2)/(z*z+4));
    //cout << den << ' ' << den1 << endl;
    den = den*sqrtp(den)*2*c;
    return num/den;
}

//Finds integral over unit circle, starting from 1 and going counterclockwise
com findint(){
    ld k = PI*2/res;
    com ans = 0;
    for(int j = 0; j < res; ++j){
        com c(cos(k*j),sin(k*j));
        com vec(-sin(k*j),cos(k*j));
        com part = func(c)*vec;
        part = part*k;
        ans = ans + part;
    }
    return ans;
}

int main(){
    com a(1,0);
    com b(1,0);
    cin >> res;
    // while(n < 10){
    //     cout << n << ' ' << findint() << endl;
    //     ++n;
    // }
    // while(n <= 3){
    //     cout << findint().x << endl;
    //     n += 0.01;
    // }
    //vector<vector<ld>> things(10,vector<ld>(9,0));
/*
    while(q < 13){
        for(n = -2; n <= 2; n += 0.5){
            things[q - 3][n*2+4] = findint().x;
        }
        ++q;
    }
    for(int i = 0; i < 10; ++i){
        cout << i + 3 << endl;
        for(ld x : things[i]){
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cout << things[i + 1][j] - things[i][j] << ' ';
        }
        cout << endl;
    }
*/

//TO FIND A MAXIMUM

    while(p <= 1.001){
        //cout << p << ' ' << q << endl;
        ld mx = 0;
        ld val = 0;
        ld step = 1;
        while(step > 0.000000001){        
            while(true){
                bool done = true;
                n = mx - step;
                ld cur = findint().y;
                if(cur > val){
                    mx = n;
                    val = cur;
                    done = false;
                }
                n = mx + step;
                cur = findint().y;
                if(cur > val){
                    mx = n;
                    val = cur;
                    done = false;
                }
                if(done) break;
            }
            step /= 2;
        }
        cout << mx << endl;
        p += 0.005;
        q -= 0.005;
    //     //q += 17;
    }

}