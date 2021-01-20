#include<iostream> 
#define ll long long int
using namespace std; 

void multiply(ll a[2][2], ll b[2][2]) 
{ 
	ll aux[2][2]; 
	for (ll i = 0; i < 2; i++) 
	{ 
		for (ll j = 0; j < 2; j++) 
		{ 
			aux[i][j] = 0; 
			for (ll k = 0; k < 2; k++) 
				aux[i][j] += a[i][k]*b[k][j]; 
		} 
	} 

	for (ll i=0; i<2; i++) 
		for (ll j=0; j<2; j++) 
			a[i][j] = aux[i][j];  
} 

ll mat_exp(ll Fib[2][2], ll n) 
{ 
 
    ll M[2][2] = {{0, 1}, {1, 1}};
	if (n==1) 
		return Fib[0][0] + Fib[0][1]; 

	mat_exp(Fib, n/2); 

	multiply(Fib, Fib); 

	if (n%2 != 0) 
		multiply(Fib, M); 

	return Fib[0][0] + Fib[0][1] ; 
} 

 
ll nth_fib_term(ll n) 
{ 

	ll Fib[2][2] = {{0, 1}, {1, 1}}; 
	

	if(n == 0) 
		return 0; 
	if(n == 1 || n == 2) 
		return 1; 

	return mat_exp(Fib, n-2); 
} 

int main() 
{ 
    cout << "Printing all the F(n) upto 64 : \n";
	for(int i=0; i<=64; i++)
		cout <<  "F (" << i << ") ==> " << nth_fib_term(i) << "\n";
    return 0; 
} 
