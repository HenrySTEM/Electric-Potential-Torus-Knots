#include <iostream>
#include <cmath>
using ld = long double;
using namespace std;
ld PI = 3.14159265358979323846;

struct com{
    ld x;
    ld y;
    com(ld a = 0, ld b = 0){
        x = a;
        y = b;
    }
};

ostream& operator<<(ostream& os, com c){
    os << c.x << '+' << c.y << 'i';
    return os;
}

ld size(com c){
    return sqrt(c.x*c.x + c.y*c.y);
}

ld mag(com c){
    return sqrt(c.x*c.x + c.y*c.y);
}

ld arg(com c){
    if(c.x == 0){
        if(c.y > 0) return PI/2;
        return 3*PI/2;
    }
    ld k = atan(c.y/c.x) + (c.x < 0 ? PI : 0);
    if(k < 0) k += 2*PI;
    //assert(0<=k && k<=2*PI);
    return k;
}

com cpol(ld mag, ld arg){
    return com(mag*cos(arg),mag*sin(arg));
}

com I(0,1);

/******************com and ld operators*********************/

com operator/(com a, ld k){
    return com(a.x/k, a.y/k);
}

com operator*(com a, ld k){
    return com(a.x*k, a.y*k);
}

com operator+(com a, ld k){
    return com(a.x + k, a.y);
}

com operator-(com a, ld k){
    return com(a.x - k, a.y);
}

/******************com and com operations*******************/

com operator+(com lhs, com rhs){
    return com(lhs.x + rhs.x, lhs.y + rhs.y);
}

com operator*(com lhs, com rhs){
    return com(lhs.x*rhs.x - lhs.y*rhs.y, lhs.x*rhs.y + lhs.y*rhs.x);
}

com operator-(com lhs, com rhs){
    return com(lhs.x - rhs.x, lhs.y - rhs.y);
}

com operator/(com lhs, com rhs){
    return (com(rhs.x,-rhs.y)*lhs)/(rhs.x*rhs.x + rhs.y*rhs.y);
}

/*****************ld on left, com on right****************/

com operator*(ld k, com a){
    return com(a.x*k, a.y*k);
}

com operator+(ld k, com a){
    return com(a.x + k, a.y);
}

com operator-(ld k, com a){
    return com(k - a.x , -a.y);
}

com operator/(ld k, com a){
    return com(k,0)/a;
}

com operator-(com c){
    return 0-c;
}

/*****************Extra com functions***************/

com exp(com c){
    return com(exp(c.x)*cos(c.y), exp(c.x)*sin(c.y));
}

com cos(com c){
    return (exp(I*c)+exp(-I*c))/2;
}

com cosh(com c){
    return (exp(c)+exp(-c))/2;
}

com sin(com c){
    return -I*(exp(I*c) - exp(-I*c))/2;
}

com sinh(com c){
    return -I*(exp(c) - exp(-c))/2;
}

com tan(com c){
    return -I*(exp(I*c) - exp(-I*c))/(exp(I*c) + exp(-I*c));
}

com tanh(com c){
    return -I*(exp(c) - exp(-c))/(exp(c) + exp(-c));
}

com sqrtp(com c){
    ld th = arg(c);
    ld r = mag(c);
    return cpol(sqrt(r),th/2);
}

com sqrtn(com c){
    ld th = arg(c);
    ld r = mag(c);
    return -cpol(sqrt(r),th/2);
}

// For complex numbers expected to be close to the real line
com sqrti(com c){
    ld th = arg(c);
    ld r = mag(c);
    com ans = cpol(sqrt(r),th/2);
    if(th < PI){
        return ans;
    }
    return -1*ans;
}