#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
// tail recursion is faster than anyother..


// this is not tail recursion because of multipication
int factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1);
}

// factorial using tail recursion
int factorialTailRecursion(int n,int fac=1){
    
    if(n==0) return fac;
    return factorialTailRecursion(n-1,n*fac);
}

bool stringPalindrome(string sr,int s,int e){
    if(s==e) return true;
    if(s>e)  return true;
    if(sr[s]!=sr[e])
        return false;
    return stringPalindrome(sr,s+1,e-1);
}

long long int findJosephus(long long int n, long long int k) 
{ 
    long long int sum = 0, i; 
  
    // For finding out the removed  
    // chairs in each iteration 
    //equation::  J(n,k)=(J(n-1,k)+k)%n
    for (i = 2; i <= n; i++) 
        sum = (sum + k) % i; 
  
    return sum + 1; 
} 

// sum of digits using recursion

int sumOfDigit(int n){
    if(n==0){
        return 0;
    }
    return sumOfDigit(n/10)+(n%10);
}
int main(){
    // string s = "aabcaa";
    // cout << stringPalindrome(s,0,s.size()-1) << endl;
    // cout << findJosephus(6,2);
    
    cout << sumOfDigit(253) << endl;

    return 0;
}