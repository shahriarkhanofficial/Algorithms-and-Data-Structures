#include<bits/stdc++.h>
using namespace std ;

int gcd(int a , int b , int &x , int &y)
{
    if(!a)
    {
        x = 0 , y = 1 ;
        return b ;
    }
    int x1 , y1 ;
    int d = gcd(b%a,a,x1,y1) ;
    x = y1 - (b/a)*x1 ;
    y = x1 ;
    return d ;
}

int modinverse(int a , int m)
{
    int x , y ;
    int g = gcd(a,m,x,y) ;
    return (x%m + m)%m ;
}

int chinese(int num[] , int rem[] , int k)
{
    int prod = 1 ;
    for(int i = 0 ; i < k ; ++i) prod*=num[i] ;
    int result = 0 ;
    for(int i = 0 ; i < k ; ++i)
    {
        int pp = prod/num[i] ;
        result += rem[i]*inv(pp,num[i])*pp ;
    }
    return result%prod ;
}
