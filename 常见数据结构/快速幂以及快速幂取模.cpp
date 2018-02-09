
//快速幂取模算法，求x^y%k
int quick_mod(int x, int y,int k) {
	int res = 1;
	while (y) {
		if (y & 1) res = (res*x) % k;
		x = (x*x) % k;
		y = y >> 1;
	}
	return res;
}


//快速幂算法，求x^y
long quick(int x,int y){
	long res=1;
	while(y){
		if(y&1)
			res=res*x;
		x=x*x;
		y=y>>1;
	}
	return res;
}