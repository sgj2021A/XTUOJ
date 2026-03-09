#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h> 
#include <string.h>
//Cycle
//int main(){
//	int T = 0,r = 0,answer;
//	scanf("%d",&T);
//	for(int i=0;i<T;i++){
//		answer=0;
//		scanf("%d",&r);
//		for(int i=1;i<r;i++){
//			for(int j=1;j<r;j++){
//				if(i*i+j*j==r*r)
//					answer++;
//				else if(i*j>r*r)
//					break;
//			}
//		}
//		answer=answer*4+4;
//		printf("%d\n",answer);
//	}
//}

//问题 B: Perfect Palindrome Number
//#define MAX_N 100000
//#define COIN_COUNT 3
//
//int coins[COIN_COUNT] = {11, 1001, 1111};
//int dp[MAX_N + 1];
//
//void precompute() {
//    for (int i = 1; i <= MAX_N; i++) {
//        dp[i] = INT_MAX / 2;
//    }
//    dp[0] = 0;
//    for (int i = 0; i < COIN_COUNT; i++) {
//        int c = coins[i];
//        for (int j = c; j <= MAX_N; j++) {
//            if (dp[j - c] + 1 < dp[j]) {
//                dp[j] = dp[j - c] + 1;
//            }
//        }
//    }
//}
//
//int main() {
//    precompute();
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        int n;
//        scanf("%d", &n);
//        if (dp[n] >= INT_MAX / 2) {
//            printf("0\n");
//        } else {
//            printf("%d\n", dp[n]);
//        }
//    }
//    return 0;
//}

//问题 C: 等式
//int main(){
//	const int Max=1000000;
//	bool isSquare[Max+1];
//    for (int i = 0; i <= Max; i++) {
//        isSquare[i] = false;
//    }
//    for (int i = 1; i * i <= Max; i++) {
//        isSquare[i * i] = true;
//    }
//	int T=0;
//	int n=0,answer=0,d=0,c=0;
//	scanf("%d",&T);
//	for(int i=0;i<T;i++){
//		scanf("%d",&n);
//		answer=0;
//		d=sqrt(n);
//		for(int a=0;a<=d;a++){
//			for(int b=a;b<=d;b++){
//				c=n-a*a-b*b;
//				if(a>b){
//					break;
//				}else if(isSquare[c]){
//					if(sqrt(c)>=b&&sqrt(c)>=a&&a>0&&b>0&&c>0)
//						answer++;
//				}
//			}
//		}
//		printf("%d\n",answer); 
//	} 
//}

//问题 D: 逆序数（小数据）
//#define Max 10001
//int process(int a[],int size){
//	int answer=0;
//	for(int i=0;i<size;i++){
//		for(int j=i+1;j<size;j++){
//			if(a[i]>a[j])
//				answer++;
//		}
//	}
//	return answer;
//}
//int main(){
//	int number[Max]={};
//	int n=1;
//	while(1){
//		scanf("%d",&n);
//		if(n==0){
//			break;
//		}
//		for(int i=0;i<n;i++){
//			scanf("%d",number+i);
//		}
//		printf("%d\n",process(number,n));
//	}
//}

//问题 E: 六边形
//#define Max 8
//#define Number 19
//int minNumber(int arr[],int size){
//	int min = 10000;
//	for(int i=0;i<size;i++){
//		if(arr[i]<=min){
//			min=arr[i];
//		}
//	}
//	return min;
//}
//int addNumber(int arr[],int factor){
//	switch(factor){
//		case 0:
//			return arr[0]+arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6];
//		case 1:
//			return arr[0]+arr[1]+arr[2]+arr[8]+arr[7]+arr[18]+arr[6];
//		case 2:
//			return arr[0]+arr[1]+arr[2]+arr[3]+arr[10]+arr[9]+arr[8];
//		case 3:
//			return arr[3]+arr[0]+arr[2]+arr[10]+arr[11]+arr[12]+arr[4];
//		case 4:
//			return arr[4]+arr[5]+arr[0]+arr[3]+arr[12]+arr[13]+arr[14];
//		case 5:
//			return arr[5]+arr[0]+arr[4]+arr[14]+arr[15]+arr[16]+arr[6];
//		case 6:
//			return arr[0]+arr[6]+arr[5]+arr[16]+arr[17]+arr[18]+arr[1];		
//	}
//}
//int main(){
//	int add[Max],number[Number];
//	int T=0;
//	scanf("%d",&T);
//	while(T--){
//		for(int i=0;i<Number;i++){
//			scanf("%d",&number[i]);
//		}
//		for(int i=0;i<Max;i++){
//			add[i]=addNumber(number,i);
//		}
//		printf("%d\n",minNumber(add,Max));
//	}
//}
//优化(错误修改)---------------
//int Swap(int a,int b){
//	int c;
//	c=a;
//	a=b;
//	b=c;
//}
//int sort(int arr[],int size){
//	for(int i=0;i<size;i++){
//		for(int j=i+1;j<size;j++){
//			if(arr[i]>arr[j]){
//				Swap(&arr[i],&arr[j]);
//			}
//		}
//	}
//}
//int main(){
//	int arr_in,arr_medium[6],arr_out[12],add_in=0,add_up=0;
//	int T=0;
//	scanf("%d",&T);
//	while(T--){
//		scanf("%d",&arr_in);
//		for(int i=0;i<6;i++){
//			scanf("%d",&arr_medium[i]);
//		}
//		for(int i=0;i<12;i++){
//			scanf("%d",&arr_out[i]);
//		}
//		sort(arr_medium,6);
//		sort(arr_out,12);
//		add_in=arr_in;
//		for(int i=0;i<6;i++){
//			add_in+=arr_medium[i];
//		}	
//		add_up=arr_in+arr_medium[0]+arr_medium[1]+arr_medium[2]+arr_out[0]+arr_out[1]+arr_out[2];
//		if(add_in>=add_up){
//			printf("%d\n",add_up);
//		}else{
//			printf("%d\n",add_in);			
//		}
//	}
//	return 0;
//} 
//优化(修改错误旋转不是排序)------------------- 
//int Min(int arr[], int size) {
//    int min = INT_MAX;
//    for (int i = 0; i < size; i++) {
//        int sum = arr[i];
//        // 由于是六边形，需要考虑循环的情况
//        sum += arr[(i + 1) % size];
//        sum += arr[(i + 2) % size];
//        if (sum < min) {
//            min = sum;
//        }
//    }
//    return min;
//}
//int main(){
//	int arr_in,arr_medium[6],arr_out[12],add_in=0,add_up=0;
//	int T=0;
//	scanf("%d",&T);
//	while(T--){
//		add_in=0,add_up=0;	
//		scanf("%d",&arr_in);
//		for(int i=0;i<6;i++){
//			scanf("%d",&arr_medium[i]);
//		}
//		for(int i=0;i<12;i++){
//			scanf("%d",&arr_out[i]);
//		}
//		add_in=arr_in;
//		for(int i=0;i<6;i++){
//			add_in+=arr_medium[i];
//		}	
//		add_up=arr_in+Min(arr_medium,6)+Min(arr_out,12);
//		if(add_in>=add_up){
//			printf("%d\n",add_up);
//		}else{
//			printf("%d\n",add_in);			
//		}
//	}
//	return 0;
//} 

//问题 F: 最大子段和(第一段错误，问题不知道)
//#define MAX 100001
//int Max(int arr[], int size, int m) {//滑动窗口解决 
//    int max = 0,cs = 0;
//    for(int i = 0 ; i < m; i++){
//    	max += arr[i];
//	}
//	cs = max;
//    for (int i = 1; i <= size - m; i++) { // 确保不越界
//    	cs = cs - arr[i-1] + arr[i+m-1];
//        if (cs > max) {
//            max = cs;
//        }
//    }
//    return max;
//}
//int main(){
//	int arr[MAX]={};
//	int n=0,m=0;
//	while(1){
//		scanf("%d %d",&n,&m);
//		if(n==0&&m==0){
//			break;
//		}
//		for(int i=0;i<n;i++){
//			scanf("%d",&arr[i]);
//		}
//		printf("%d\n",Max(arr,n,m));
//	}
//}

//问题 G: A+B IV
//int proess(int a,int b,int c){
//	if((c-b)%a==0){
//		return (c-b)/a;
//	}else{
//		return -(c-a)/b; 
//	}
//}
//int Zero(int a) {
//    if (a == 0) {
//        return 0;
//    }
//    a = abs(a); 
//    int count = 0;
//    while (a > 0) {
//        a /= 10;
//        count++;
//    }
//    return count-1;
//}
//int main(){
//	int T,a,b,c,cs;
//	scanf("%d",&T);
//	while(T--){
//		scanf("%d+%d=%d",&a,&b,&c);
//		cs=proess(a,b,c);
//		if(cs<0){
//			printf("-%d\n",Zero(cs));		
//		}else{
//			printf("%d\n",Zero(cs));			
//		}		
//	}
//	return 0;
//}
//优化--------------------------(暴力拆除) 
//int main() {
//    int k;
//    scanf("%d", &k);
//    while (k--) {
//        int a, b, c;
//        scanf("%d+%d=%d", &a, &b, &c);
//        long long base = 1;
//        int found = 0;
//        for (int n = 0; n <= 10; n++) {
//            long long value = a * base + b;
//            if (value == c) {
//                printf("%d\n", n);
//                found = 1;
//                break;
//            }
//            base *= 10;
//        }
//        if (found) continue;
//        base = 10;
//        for (int m = 1; m <= 10; m++) {
//            long long value = a + b * base;
//            if (value == c) {
//                printf("%d\n", -m);
//                break;
//            }
//            base *= 10;
//        }
//    }
//    return 0;
//}

//问题 H: 锐角三角形
//bool isAcuteTriangle(int a, int b, int c) {
//    if (a > b) { int temp = a; a = b; b = temp; }
//    if (a > c) { int temp = a; a = c; c = temp; }
//    if (b > c) { int temp = b; b = c; c = temp; }
//    if (a + b <= c) {
//        return false;
//    }
//    return (c * c < a * a + b * b);
//}
//int process(int arr[],int size){
//	int answer=0;
//	for(int i=0;i<size;i++){
//		for(int j=i+1;j<size;j++){
//			for(int k=j+1;k<size;k++){
//				if(isAcuteTriangle(arr[i],arr[j],arr[k]))
//				answer++;	
//			}
//		}
//	}
//	return answer;
//}
//int main() {
//	int a[101]={},size;
//    int k;
//    scanf("%d", &k);
//    while (k--) {
//		scanf("%d",&size);
//		for(int i=0;i<size;i++){
//			scanf("%d",&a[i]);
//		}
//		printf("%d\n",process(a,size));
//    }
//    return 0;
//}

//问题 I: 随机数()
//线性同余发生器（LCG）是一种伪随机序列生成器算法，能产生具有不连续计算的伪随机序列的分段线性方程。生成器由循环关系定义
//（1） 是伪随机序列；
//（2） 表示模量；
//（3） 表示乘数；
//（4） 表示增量；
//（5） 表示初始值。
//。如果 ，该发生器通常称为乘法同余发生器（MCG）。如果 ，该发生器称为混合同余发生器。
//线性同余发生器的好处是，通过适当选择参数，区间长度可知且很长。虽然不是唯一标准，但是一般情况下太短的区间长度在伪随机数发生器中是一个致命的缺陷。
//它对参数 和 的选择极为敏感
//1.周期性 : 经过一定步数后会重复之前的序列
//最大周期：如果参数选择得当，LCG 可以达到满周期（即周期长度为 m），生成 0 到 m-1 的所有整数。(题目要求)
//影响周期的因素：
//a和m必须互质
//如果 c=0(即 LCG 变为乘法同余生成器），需要额外条件（如 a-1 是 m的所有素数因子的倍数）。
///如果 c!=0，只要 a和 m互质，LCG 就能达到满周期。
//2. 均匀性
//理想情况：如果 LCG 达到满周期，生成的数会均匀覆盖 0 到 m-1。
//如果参数选择不当（如 a和 m不互质），生成的数可能集中在某些子区间，导致分布不均匀。
//即使达到满周期，生成的数在低维空间（如 1D）可能均匀，但在高维空间（如 2D、3D）可能呈现规律性（如超平面结构）。
//3. 覆盖范围
//需要满周期条件 生成 0 到 m-1 的所有整数
//int gcd(int a, int b) {
//    if (b == 0) return a;
//    return gcd(b, a % b);
//}
//
//int main() {
//    int a, c, m;
//    while (scanf("%d %d %d", &a, &c, &m) == 3) {
//        if (m == 1) {
//            printf("Yes\n");
//            continue;
//        }
//        if (gcd(c, m) != 1) {
//            printf("No\n");
//            continue;
//        }
//        
//        int temp = m;
//        int factors[100];
//        int count = 0;
//        for (int i = 2; i * i <= temp; i++) {
//            if (temp % i == 0) {
//                factors[count++] = i;
//                while (temp % i == 0) temp /= i;
//            }
//        }
//        if (temp > 1) factors[count++] = temp;
//        
//        int valid = 1;
//        for (int i = 0; i < count; i++) {
//            int p = factors[i];
//            if (p == 2 && m % 4 == 0) {
//                continue;
//            }
//            if ((a - 1) % p != 0) {
//                valid = 0;
//                break;
//            }
//        }
//        if (!valid) {
//            printf("No\n");
//            continue;
//        }
//        if (m % 4 == 0) {
//            if ((a - 1) % 4 != 0) {
//                printf("No\n");
//                continue;
//            }
//        }
//        printf("Yes\n");
//    }
//    return 0;
//}

//问题 K: Color
//方案一(正确) 
//int main(){
//	short map[101][101]={0};
//	int m,n,k,t,x,y,answer,safe=0;
//	scanf("%d",&t);
//	while(t--){//0 空 1 黑 2 红
//		answer = 0; 
//		safe = 0;
//		scanf("%d %d %d",&m,&n,&k);
//		for(int i=0;i<101;i++){
//			for(int j=0;j<101;j++){
//				map[i][j]=0;
//			}
//		}
//		while(k--){
//			scanf("%d %d",&x,&y);
//			map[x][y]=1;
//		}
//		for(int i=1;i<=m;i++){
//			for(int j=1;j<=n;j++){
//				if(map[i][j]==1){
//					break;
//				}else if(j==n){
//					answer=answer+n;
//					safe++;
//				}
//			}
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				if(map[j][i]==1){
//					break;
//				}else if(j==m){
//					answer=answer-safe+m;
//				}
//			}
//		}
//		printf("%d\n",answer);
//	}
//	return 0;
//}
//-----------------方案二(正确)
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        int m, n, k;
//        scanf("%d %d %d", &m, &n, &k);
//        int row_black[101] = {0}; // 标记行是否有黑色格子
//        int col_black[101] = {0}; // 标记列是否有黑色格子
//        
//        // 读取黑色格子并标记
//        for (int i = 0; i < k; i++) {
//            int x, y;
//            scanf("%d %d", &x, &y);
//            row_black[x] = 1;
//            col_black[y] = 1;
//        }
//        
//        // 统计没有黑色格子的行数
//        int R0 = 0;
//        for (int i = 1; i <= m; i++) {
//            if (!row_black[i]) {
//                R0++;
//            }
//        }
//        
//        // 统计没有黑色格子的列数
//        int C0 = 0;
//        for (int j = 1; j <= n; j++) {
//            if (!col_black[j]) {
//                C0++;
//            }
//        }
//        
//        // 计算最多能染色的格子数
//        int ans = R0 * n + C0 * m - R0 * C0;//重要 
//        printf("%d\n", ans);
//    }
//    return 0;
//}

//问题 J: 原根
//对于 p-1的所有素因子 q（即 q是 p-1的质因数），均满足：2的(p-1)/q次方 %p != 1 
//-----
//快速幂算法。多次平方和乘法 
//快速幂算法通过将指数分解为二进制形式，利用平方和乘法的组合来高效计算大数的幂次模运算。
//将指数表示为二进制形式。
//根据二进制位的值（0 或 1），决定是否将当前的底数乘到结果中
//每次迭代时，底数自乘（平方），指数右移一位（相当于除以 2）。
//long long fast_pow(long long base, long long exp, long long mod) {
//    long long result = 1;
//    base %= mod;
//    while (exp) {
//        if (exp&1) {
//            result=(result*base) % mod;
//        }
//        base = (base * base)%mod;
//        exp>>= 1;
//    }
//    return result;
//}
////分解质因数
//int get_prime_factors(long long n, long long *factors) {
//    int count = 0;
//    if (n % 2 == 0) {
//        factors[count++] = 2;
//        while (n % 2 == 0) {
//            n /= 2;
//        }
//    }
//    for (long long i=3; i*i<=n; i+=2) {
//        if (n%i == 0) {
//            factors[count++] = i;
//            while (n%i == 0) {
//                n/=i;
//            }
//        }
//    }
//    if (n>1) {
//        factors[count++] = n;
//    }
//    return count;
//}
//
//int main() {
//    long long p;
//    while (scanf("%lld",&p) != EOF) {
//        if (p==2) {
//            printf("Yes\n");
//            continue;
//        }
//        long long n = p - 1;
//        long long factors[100];
//        int count = get_prime_factors(n, factors);
//        int is_primitive = 1;
//        for (int i = 0; i < count; i++) {
//            long long q = factors[i];
//            long long r = n / q;
//            long long power = fast_pow(2, r, p);
//            if (power == 1) {
//                is_primitive = 0;
//                break;
//            }
//        }
//        if (is_primitive) {
//            printf("Yes\n");
//        } else {
//            printf("No\n");
//        }
//    }
//    return 0;
//}
//问题 L: 连分式(过不去即使思路一致，测试数据正常)
//void Swap(long long *a,long long *b){
//	long long c;
//	c=*a;
//	*a=*b;
//	*b=c;
//}
//typedef struct {
//    long long up;   // 分子
//    long long down; // 分母
//} fraction;
//long long gcd(long long a,long long b){
//	if(a<b){
//		Swap(&a,&b);
//	}
//	if(b==0){
//		return a;
//	}
//	return gcd(b,a%b);
//}
//void process(fraction *f,long long b,long long a){
//	f->up=f->up+b*f->down;
//	Swap(&f->down,&f->up);
//	f->up*=a;
//	long long g=gcd(f->down,f->up);
//	f->down/=g;
//	f->up/=g;
//}
//int main() {
//    long long k,a,b,n;
//    fraction f;
//    scanf("%lld", &k);
//    while (k--) {
//		scanf("%lld %lld %lld",&a,&b,&n);
//		f.down=b;
//		f.up=a;
//		for(int i=1;i<n;i++){
//			process(&f,b,a);
//		}
//		printf("%lld/%lld\n",f.up,f.down);
//    }
//    return 0;
//}
//优化-------------
//long long gcd(long long a, long long b) {
//    if (b == 0) return a;
//    return gcd(b, a % b);
//}
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        long long a, b, n;
//        scanf("%lld %lld %lld", &a, &b, &n);
//        if (n == 1) {
//            long long g = gcd(a, b);
//            printf("%lld/%lld\n", a / g, b / g);
//        } else {
//            long long num = a;
//            long long den = b;
//            for (long long i = 2; i <= n; i++) {
//                long long new_num = a * den;
//                long long new_den = b * den + num;
//                long long g = gcd(new_num, new_den);
//                num = new_num / g;
//                den = new_den / g;
//            }
//            printf("%lld/%lld\n", num, den);
//        }
//    }
//    return 0;
//}


