#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//问题 A: 分数
//int GCD(long long a,long long b){
//	if(a<0||b<0){
//		return -1;
//	}
//	if(b == 0){
//		return a;
//	}
//	return GCD(b,a%b);
//}
//int main(){
//	int T=0;
//	long long a,b,c; 
//	long long d=0,e=0,f=0;
//	scanf("%d",&T); 
//	for(int k=0;k<T;k++){
//		scanf("%lld %lld %lld",&a,&b,&c);
//		d = a*a*c - b*b*a +c*c*b;
//		e = a*b*c;
//		if(e<0){
//			d=-d;
//			e=-e;
//		}
//		if(d==0){
//			printf("0\n");
//		}else if(d%e==0){
//			printf("%lld\n",d/e);
//		}else{			
//			f=GCD(fabs(d),e);
//			printf("%lld/%lld\n",d/f,e/f);
//		}
//	}
//	
//} 

//问题 B: 求最小公倍数
//int GCD(int a,int b){
//	if(a<0||b<0){
//		return 1;
//	}
//	if(b == 0){
//		return a;
//	}
//	return GCD(b,a%b);
//}
//int gcd(int a,int b){
//	return a*b/GCD(a,b);
//}
//int main(){
//	int x,y; 
//	while(1){
//		scanf("%d %d",&x,&y);
//		if(x == 0&&y == 0){
//			break;
//		}
//		printf("%d\n",gcd(x,y));
//	}	
//} 

//问题 C: sum & times
//int main(){
//	bool answer=false;
//	long long n=0,c,d,a=0,b=0;
//	scanf("%lld",&n); 
//	for(int k=0;k<n;k++){
//		scanf("%lld %lld",&c,&d);
//		answer = false;
//		for(b=c;b>=a;b--){
//			a=c-b;
//			if(a*b==d){
//				answer=true;
//				break;
//			}
//		}
//		if(answer==true){
//			printf("%lld %lld\n",a,b);
//		}else{
//			printf("None\n");
//		}
//	}
//}
//-------------优化
//正确的方法应该是通过数学方程来求解。我们知道 a 和 b 是方程 x^2 - c*x + d = 0(维达定理) 的两个根。判断这个二次方程是否有整数解，且满足 a ≤ b。
//long long isqrt(long long n) {
//    if (n < 0) return -1;
//    if (n == 0) return 0;
//    long long x = n;
//    long long y = (x + 1) / 2;
//    while (y < x) {
//        x = y;
//        y = (x + n / x) / 2;
//    }
//    return x;
//}
//
//int main() {
//    int K;
//    scanf("%d", &K);
//    while (K--) {
//        long long c, d;
//        scanf("%lld %lld", &c, &d);
//        long long delta = c * c - 4 * d;
//        if (delta < 0) {
//            printf("None\n");
//            continue;
//        }
//        long long root = isqrt(delta);
//        if (root * root != delta) {
//            printf("None\n");
//            continue;
//        }
//        if ((c - root) % 2 != 0) {
//            printf("None\n");
//            continue;
//        }
//        long long a = (c - root) / 2;
//        long long b = (c + root) / 2;
//        printf("%lld %lld\n", a, b);
//    }
//    return 0;
//}

//问题 D: A+B III
//long long GCD(long long a,long long b){
//	if(a<0||b<0){
//		return 1;
//	}
//	if(b == 0){
//		return a;
//	}
//	return GCD(b,a%b);
//}
//long long cs(long long b,long long a){
//	//C 2 5
//	long long c=1,d=1;
//	for(int i=0;i<b;i++){
//		c=c*a;
//		a--;
//	}
//	for(int i=1;i<=b;i++){
//		d=d*i;
//	}
//	return c/d;
//}
//int main(){
//	int t,n,m;
//	long long a,b,c;
//	scanf("%d",&t);
//	for(int k=0;k<t;k++){
//		scanf("%d %d",&n,&m);
//		if(m<3){
//			printf("0\n");
//		}else if(n==m){
//			printf("1\n");
//		}else{
//			a=cs(3,n);
//			b=cs(3,m);
//			if(b%a==0){
//				printf("1/%lld\n",b/a);
//			}else{
//				c=GCD(a,b);
//				printf("%lld/%lld\n",b/c,a/c);
//			}
//		}
//	}	
//	return 0;
//}

//问题 E: 青蛙（步长为m+1，为n与m+1互质）问题是要判断青蛙是否能访问所有位置。这等价于问：步长d是否与n互质？ 
//青蛙每次跳跃可以移动到当前位置顺时针或逆时针方向第(k+1)个位置？因为如果相隔k个位置，那么目标位置与当前位置之间有k个位置，所以从当前位置到目标位置需要跳k+1步？但题目中的k是给定的参数。
//int gcd(int a,int b){
//	if(b==0){
//		return a; 
//	}
//	return gcd(b,a%b); 
//}
//
//
//int main(){
//	int T=0,n,m;
//	scanf("%d",&T);
//	for(int k=0;k<T;k++){
//		scanf("%d %d",&n,&m);
//		if(n==1){
//			printf("Yes\n");
//		}else if(gcd(n,m+1)==1){
//			printf("Yes\n");
//		}else{
//			printf("No\n");
//		}
//	}	
//}

//问题 F: 面积 
//int GCD(int a,int b){
//	if(a<0||b<0){
//		return -1;
//	}
//	if(b == 0){
//		return a;
//	}
//	return GCD(b,a%b);
//}
//int main(){
//	int T=0;
//	int a=0,b=0,s=0,c=0,d=1;
//	scanf("%d",&T);
//	for(int i=0;i<T;i++){
//		scanf("%d %d",&a,&b);
//		c=2*(a+b);
//		s=(a*a+b*b)*c-a*a*b-b*b*b;
//		if(s%(2*(a+b)) == 0){
//			printf("%d\n",s/c);
//		}else{
//			d=GCD(s,c);
//			printf("%d/%d\n",s/d,c/d);
//		}	
//	}
//}

//问题 G: 三角数 
//int main(){
//	int T=0;
//	long long n=0;
//	scanf("%d",&T);
//	for(int i=0;i<T;i++){
//		scanf("%lld",&n);
//        if (n % 4 == 0 || n % 4 == 1) {
//            printf("%lld\n", n / 2);
//        } else {
//            printf("%lld\n", (n + 1) / 2);
//        }
//	}
//}
//三角形数表的第n行有n个连续数字，起始数字是前n-1行数字总数加1，即S = n(n-1)/2 + 1。
//关键点是S的奇偶性决定了该行偶数的个数：
//如果S是奇数，那么该行偶数的个数是n/2（整数除法）。
//如果S是偶数，那么该行偶数的个数是(n+1)/2（整数除法）。
//S的奇偶性取决于T = n(n-1)/2的奇偶性。因为S = T + 1，所以如果T是偶数，S是奇数；如果T是奇数，S是偶数。
//现在，我需要判断T的奇偶性。T = n(n-1)/2。注意，n(n-1)总是偶数，因为连续两个整数必有一个偶数，所以T是整数。
//T的奇偶性可以通过n modulo 4来分析：
//如果n ≡ 0 mod 4，那么n是4的倍数，n-1是奇数。n(n-1)/2 = (4k * (4k-1))/2 = 2k*(4k-1)。由于4k-1是奇数，所以T的奇偶性取决于2k的奇偶性，即k的奇偶性。但k是整数，所以如果k是偶数，T是偶数；如果k是奇数，T是奇数。但k = n/4，所以n/4的奇偶性决定T的奇偶性。这有点复杂。
//实际上，有一个更简单的方法：考虑n和n-1的奇偶性。
//由于n(n-1)是两个连续整数，它们的乘积是偶数。除以2后，T的奇偶性取决于n和n-1中能被2整除的次数。
//更直的是，考虑n modulo 4：
//当n ≡ 0 mod 4时，n是4的倍数，n-1是奇数。设n=4k，则T=4k*(4k-1)/2=2k*(4k-1)。T是偶数， 
//当n ≡ 1 mod 4时，n=4k+1，则n-1=4k。T=(4k+1)*4k/2=2k*(4k+1)。T是偶数
//当n ≡ 2 mod 4时，n=4k+2，则n-1=4k+1。T=(4k+2)*(4k+1)/2=(2(2k+1))*(4k+1)/2=(2k+1)*(4k+1)。由于4k+1是奇数，2k+1是奇数，奇数乘奇数是奇数，所以T是奇数。
//当n ≡ 3 mod 4时，n=4k+3，则n-1=4k+2。T=(4k+3)*(4k+2)/2=(4k+3)*2(2k+1)/2=(4k+3)*(2k+1)。4k+3是奇数，2k+1是奇数，奇数乘奇数是奇数，所以T是奇数。
//从以上分析：
//如果n ≡ 0 mod 4，T的奇偶性取决于k=n/4的奇偶性。
//如果n ≡ 1 mod 4，T的奇偶性取决于k=(n-1)/4的奇偶性。
//如果n ≡ 2 mod 4，T是奇数。
//如果n ≡ 3 mod 4，T是奇数。

//问题 H: Harmonic Porgression
//long long gcd(long long a, long long b) {
//    if (b == 0) return a;
//    return gcd(b, a % b);
//}
//
//long long lcm(long long a, long long b) {
//    return a / gcd(a, b) * b;
//}
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        int a, b;
//        scanf("%d %d", &a, &b);
//        long long L = 1;
//        for (int i = a; i <= b; i++) {
//            L = lcm(L, i);
//        }
//        long long sum = 0;
//        for (int i = a; i <= b; i++) {
//            sum += L / i;
//        }
//        long long g = gcd(sum, L);
//        long long numerator = sum / g;
//        long long denominator = L / g;
//        if (denominator == 1) {
//            printf("%lld\n", numerator);
//        } else {
//            printf("%lld/%lld\n", numerator, denominator);
//        }
//    }
//    return 0;
//}

//问题 I: 世界杯
//设下注在胜的比例为a，平的比例为b，负的比例为c，那么a + b + c = 1。
//A * max_w > S 并且 B * max_d > S 并且 C * max_l > S
//将S设为1，则A、B、C是比例，满足A + B + C = 1。
//则A * max_w > 1 并且 B * max_d > 1  并且 C * max_l > 1
//A > 1/max_w, B>1/max_d, C>1/max_l 加上 A+B+C=1 
//1 / max_w + 1 / max_d + 1 / max_l >= 1
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        int n;
//        scanf("%d", &n);
//        double max_w = 0.0, max_d = 0.0, max_l = 0.0;
//        for (int i = 0; i < n; i++) {
//            double w, d, l;
//            scanf("%lf %lf %lf", &w, &d, &l);
//            if (w > max_w) max_w = w;
//            if (d > max_d) max_d = d;
//            if (l > max_l) max_l = l;
//        }
//        double total = 1.0 / max_w + 1.0 / max_d + 1.0 / max_l;
//        if (total < 1.0) {
//            printf("Yes\n");
//        } else {
//            printf("No\n");
//        }
//    }
//    return 0;
//}

//问题 J: 格子
//long long gcd(long long a, long long b) {
//    if (b == 0) return a;
//    return gcd(b, a % b);
//}
//long long C(int n,int m){
//	long long up=1,down=1;
//	for(int i=1;i<=m;i++){
//		down=down*i;
//		up=up*(n-i+1);
//	}
//	return up/down;
//}
//long long Down(int n,int m,int k){
//	return C(m*n,k);
//}
//long long Up(int n,int m,int k){
//	long long a=C(n,k);
//	long long b=m;
//	for(int i=1;i<=(k-1);i++){
//		b=b*(m-i);
//	}
//	return b*a;
//}
//int main(){
//	int T=0,n,m,k;
//	long long up=0,down=0,Gcd=0;
//	scanf("%d",&T);
//	while(T--){
//		scanf("%d %d %d",&n,&m,&k);
//		if(k>m||k>n){
//			printf("0\n");
//		}else if(k==1){
//			printf("1\n");
//		}else{
//			up=Up(n,m,k);
//			down=Down(n,m,k);
//			if(down%up==0){
//				printf("1/%lld\n",down/up);
//			}else{
//				Gcd=gcd(down,up);
//				printf("%lld/%lld\n",up/Gcd,down/Gcd);
//			}
//		}
//	}
//}

//问题 K: Circle
//#define EPSILON 1e-9
// 
//int isZero(double x) {
//    return fabs(x) < EPSILON;
//}
//double Distance(double x1,double y1,double x2,double y2){
//	return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
//}
//int location(int r1,int r2,double distance){
//    if (distance > r1 + r2) {
//        return 5;
//    } else if (isZero(distance - r1 - r2)) {
//        return 4;
//    } else if (isZero(fabs(r1 - r2) - distance)) {
//        return 2;
//    } else if (distance < fabs(r1 - r2)) {
//        return 1;
//    } else {
//        return 3;
//	}
//}
//int main(){
//	int T=0;
//	int x1,y1,r1,x2,y2,r2,answer;
//	double dis=0;
//	scanf("%d",&T);
//	while(T--){
//		scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
//		dis=Distance(x1,y1,x2,y2);
//		answer=location(r1,r2,dis);
//		printf("%d\n",answer);
//	}
//	return 0;
//}
