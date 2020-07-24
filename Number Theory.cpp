#include <bits/stdc++.h>
using namespace std;
// Modular Exponentiation
long long modularExponentiation(long long x , long long n , long long M)
{
	long long result = 0;
	
	while(n>0)
	{
		if(n%2 == 1)
			result = (result*x)%M;
			
		x = (x*x);
		n = n>>1;
	}
	return result;
}

// GCD(a,b)
long long GCD(long long a , long long b){
	if(b==0)
		return a;
	else 
		return Gcd(b , a%b);
}

//Inverse Modulo
long long modInverse( long long A , long long M)
{
	return modularExponentiation(A , M-2 ,M);
}

// Sieve Implementation
void sieve(long long N){
	
	bool isPrime[N+1];
	long long i,j;
	for(i = 0  ; i <= N ; i++)
		isPrime[i]  = true;
	
	isPrime[0] = isPrime[1] = false;
	
	for(i = 2 ; i*i <= N ; i++)
	{
		if(isPrime[i]){
		
		for(j = i*i ; j <= N ; j+=i)
			isPrime[j] = false;
		}
	}
	
}






