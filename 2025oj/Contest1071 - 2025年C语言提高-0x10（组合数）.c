//问题 A: Binary String
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX 1000000007
////long long Pow_2(int n){
////	long long result = 1;
////	for(int i = 0;i < n;i++){
////		result *= 2;
////		result %= MAX;
////	}
////	return result;
////}
//long long Pow_2(int n) {
//    long long result = 1;
//    long long base = 2;  // 底数
//    while (n > 0) {
//        if (n % 2 == 1) {       // 如果当前指数是奇数
//            result = (result * base) % MAX;
//        }
//        base = (base * base) % MAX;  // 底数平方
//        n /= 2;                // 指数减半
//    }
//    return result;
//}
//int main(){
//	long long *pre = (long long *)malloc(sizeof(long long) * 1000003);
//	pre[1] = 2;
//	pre[2] = 3; 
//	for(int i = 3;i < 1000002;i++){
//		pre[i] = (pre[i - 1] + pre[i - 2]) % MAX;
//	}
//	int k = 0;
//	scanf("%d",&k);
//	while(k--){
//		int n;
//		scanf("%d",&n);
//		printf("%lld\n",(Pow_2(n) - pre[n] + MAX) % MAX);
//	}
//	free(pre);
//	return 0;
//} 

//----------------------------------------------
//问题 B: Alice's Prime
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#define INTMAX 2147483648
//#define MAXRANGE 73939134
//#define MAX 1000000
//bool Prime(int n){
//	if(n < 2)return false;
//	if(n == 2 || n == 3)return true;
//	if(n % 2 == 0 || n % 3 == 0)return false;
//	for(long long i = 5;i * i <= num;i += 6){
//		if(n % i == 0)return false;
//		if(n % (i + 1) == 0)return false;
//	}
//	return true;
//} 
//int main(){
//	//基础素数 
//	bool *isPrime = (bool*)malloc(sizeof(bool) * MAX);
//	int index = 0;
//	int *prime = (int*)malloc(sizeof(int) * MAX);
//	int count = 1;
//	
//	for(int i = 0;i < MAX;i++){
//		isPrime[i] = true;
//	}
//	isPrime[1] = false;
//	isPrime[0] = false;
//	
//	for(int i = 2;i < MAX;i++){
//		if(isPrime[i]){
//			prime[index++] = i;
//			bool found = true;
//			int temp = i;
//			while(temp / 10 != 0){
//				if(!isPrime[temp / 10]){
//					found = false;
//					break;
//				}
//				temp /= 10;
//			}
//			if(isPrime[temp]){
//				if(found)printf("%d %d\n",count++,i);
////				if(found)printf("%d\n",i);
//			}
//		}
//		for(int j = 0;j < index && i * prime[j] < MAX;j++){
//			isPrime[i * prime[j]] = false;
//			if(i % prime[j] == 0){
//				break;
//			}
//		}
//	}
//	
//	
//	free(isPrime);
//	free(prime);
//	return 0;
//} 
//简单 
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//int main(){
//	printf("1 2\n2 3\n3 5\n4 7\n5 23\n6 29\n7 31\n8 37\n9 53\n10 59\n11 71\n12 73\n13 79\n14 233\n15 239\n16 293\n17 311\n18 313\n19 317\n20 373\n21 379\n22 593\n23 599\n24 719\n25 733\n26 739\n27 797\n28 2333\n29 2339\n30 2393\n31 2399\n32 2939\n33 3119\n34 3137\n35 3733\n36 3739\n37 3793\n38 3797\n39 5939\n40 7193\n41 7331\n42 7333\n43 7393\n44 23333\n45 23339\n46 23399\n47 23993\n48 29399\n49 31193\n50 31379\n51 37337\n52 37339\n53 37397\n54 59393\n55 59399\n56 71933\n57 73331\n58 73939\n59 233993\n60 239933\n61 293999\n62 373379\n63 373393\n64 593933\n65 593993\n66 719333\n67 739391\n68 739393\n69 739397\n70 739399\n71 2339933\n72 2399333\n73 2939999\n74 3733799\n75 5939333\n76 7393913\n77 7393931\n78 7393933\n79 23399339\n80 29399999\n81 37337999\n82 59393339\n83 73939133\n");
//	return 0;
//} 
//----------------------------------------------
//问题 C: 密码
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(){
//	long long num[45][4];
//	num[0][0] = 1;
//	num[0][1] = 1;
//	num[0][2] = 1;
//	num[0][3] = 1;
//	for(int i = 1;i < 45;i++){
//		num[i][0] = 0;	
//		num[i][1] = 0;
//		num[i][2] = 0;
//		num[i][3] = 0;
//	}
//	for(int i = 1;i < 45;i++){
//		for(int j = 0;j <= 3;j++){
//			if(j == 0){//1
//				num[i][1] += num[i - 1][j];
//				num[i][2] += num[i - 1][j];				 
//			} 
//			if(j == 1){//2
//				num[i][0] += num[i - 1][j];
//				num[i][2] += num[i - 1][j];		
//				num[i][3] += num[i - 1][j];			 
//			} 
//			if(j == 2){//3
//				num[i][0] += num[i - 1][j];
//				num[i][1] += num[i - 1][j];		
//				num[i][3] += num[i - 1][j];				 
//			} 
//			if(j == 3){//4
//				num[i][1] += num[i - 1][j];
//				num[i][2] += num[i - 1][j];				 
//			} 
//		}
//	}
////	for(int i = 0;i < 45;i++){
////		for(int j = 0;j < 4;j++){
////			printf("%d ",num[i][j]);
////		}
////		printf("\n");
////	}	
//	int k;
//	scanf("%d",&k);
//	
//	while(k--){
//		int n;
//		scanf("%d",&n);
//		printf("%lld\n",(long long)num[n - 1][0] + num[n - 1][1] + num[n - 1][2] + num[n - 1][3]);
//	}
//	
//	return 0;
//}
//----------------------------------------------
//dp[i+1] = 
//  0,                   如果 last == -1 (即前面没有'1')
//  sumdp[last],         否则
//
//其中：
//- sumdp[k] = dp[0] + dp[1] + ... + dp[k]
//- last 是当前位置之前最后一个'1'的位置
//问题 D: 分割01串
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h> 
//
//#define MAX 1000000007
//int main(){
//	char str[1001];
//	int k;
//	
//	scanf("%d",&k);
//	
//	while(k--){
//		scanf("%s",str);
//		int last = -1;
//		int len = strlen(str);
//		long long *dp = (long long*)malloc(sizeof(long long) * (len + 1));
//		long long *sumdp = (long long*)malloc(sizeof(long long) * (len + 1));
//		dp[0] = 1;
//		sumdp[0] = 1;
//		for(int i = 0;i < len;i++){
//			if(str[i] == '1'){
//				last = i;
//			}
//			if(last == -1){
//				dp[i + 1] = 0;
//			}else{
//				dp[i + 1] = sumdp[last];
//			}
//			sumdp[i + 1] = (sumdp[i] + dp[i + 1]) % MAX;
//		}
//		printf("%lld\n",dp[len]);	
//		free(dp);
//		free(sumdp); 
//	}
//	
//	return 0;
//} 
//----------------------------------------------
//问题 E: Recipient
//#include <stdio.h>
//#include <stdlib.h>
//#define MOD 1000000007
//long long mod_inverse(long long a, long long mod) {
//    long long res = 1, base = a, exp = mod - 2;
//    while (exp) {
//        if (exp & 1) res = res * base % mod;
//        base = base * base % mod;
//        exp >>= 1;
//    }
//    return res;
//}
//
//long long C(int n, int m) {
//    if (n > m) return 0;
//    if (n == 0 || n == m) return 1;
//    n = (n > m - n) ? m - n : n;
//    long long res = 1;
//    for (int i = 1; i <= n; i++) {
//        res = res * (m - n + i) % MOD;
//        res = res * mod_inverse(i, MOD) % MOD;
//    }
//    return res;
//}
//int main(){
//	long long *D = (long long*)malloc(sizeof(long long) * 1001);
//	D[0] = 1;
//	D[1] = 0;
//	D[2] = 1;
//	for(int i = 3;i <= 1000;i++){
//		D[i] = ((i - 1) * (D[i - 1] + D[i - 2]) % MOD) % MOD;
//	}
//	while(1){
//		long long n,m;
//		scanf("%lld %lld",&m,&n);
//		if(m == 0 && n == 0)break;
//		long long result = (C(n,m) % MOD * D[n]) % MOD;
//		printf("%lld\n",result);
//	}
//	free(D);
//	return 0;
//} 
//----------------------------------------------
//问题 G: 冰墩墩与颜色
//#include <stdio.h>
//#define MOD 1000000007
////long long Pow_2(int n){
////	long long ret = 1;
////	while(n--){
////		ret <<= 1;
////		ret %= MOD;
////	}
////	return ret / 2;
////}
//long long Pow_2(int n) {
//    long long res = 1, base = 2;
//    while (n) {
//        if (n & 1) res = res * base % MOD;
//        base = base * base % MOD;
//        n >>= 1;
//    }
//    return res;
//}
//int main(){
//	int s;
//	scanf("%d",&s);
//	
//	while(s--){
//		int k;
//		scanf("%d",&k);
//		
//		int n = k - 1;
//		//printf("%lld %d\n",Pow_2(n),n);
//		long long ret = (Pow_2(n - 1) * 3) % MOD * n % MOD;
//		
//		printf("%lld\n",ret);
//	} 
//	
//	return 0;
//}
//----------------------------------------------
//问题 H: 红球与白球
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MOD 1000000007
//int main(){
//	long long *pre = (long long*)malloc(sizeof(long long) * 100000);
//	pre[0] = 1;
//	pre[1] = 1;
//	for(int i = 2;i < 100000;i++){
//		pre[i] = (pre[i - 1] + pre[i - 2]) % MOD;
//	}
//	
//	int k;
//	scanf("%d",&k);
//	
//	while(k--){
//		int n;
//		scanf("%d",&n);
//		long long result = 0;
//		long long temp = 1;
//		for(int i = 0;i <= n - 2;i++){
//			temp = 1;
//			temp = (temp * pre[i]) % MOD;
//			temp = (temp * pre[n - 2 - i]) % MOD;
//			result = (result + temp) % MOD; 
//		}
//		
//		printf("%lld\n",result);
//	}
//	
//	return 0;
//}
//----------------------------------------------
//问题 I: 瓷片
//#include <stdio.h>
//
//long long dp[35][4]; // dp[i][state]
//
//long long countTiling(int n) {
//    // 状态定义：
//    // 0: 当前列两格都空
//    // 1: 当前列只有上格被覆盖
//    // 2: 当前列只有下格被覆盖  
//    // 3: 当前列两格都被覆盖
//    for(int i = 0;i < 35;i++){
//    	for(int j = 0;j < 4;j++){
//    		dp[i][j];
//		}
//	}
//    dp[0][3] = 1; // 初始状态：第0列被认为是满的
//    dp[0][0] = dp[0][1] = dp[0][2] = 0;
//    
//    for (int i = 1; i <= n; i++) {   	
//        // 从状态3（前一列满）转移到当前列
//        dp[i][0] += dp[i-1][3] * 2; // 放两个1x1或一个竖放的1x2
//        dp[i][1] += dp[i-1][3] * 1; // 上格横放1x2
//        dp[i][2] += dp[i-1][3] * 1; // 下格横放1x2
//        dp[i][3] += dp[i-1][3] * 1; // 两个横放1x2
//        
//        // 从状态1（前一列上格被覆盖）转移到当前列
//        dp[i][3] += dp[i-1][1] * 1; // 下格放1x1
//        dp[i][2] += dp[i-1][1] * 1; // 下格横放1x2
//        
//        // 从状态2（前一列下格被覆盖）转移到当前列
//        dp[i][3] += dp[i-1][2] * 1; // 上格放1x1
//        dp[i][1] += dp[i-1][2] * 1; // 上格横放1x2
//        
//        // 从状态0（前一列两格都空）转移到当前列
//        dp[i][3] += dp[i-1][0] * 1; // 放两个1x1或一个竖放的1x2
//    }
//    
//    return dp[n][3]; // 第n列满的状态
//}
//
//int main() {
//    int t, n;
//    scanf("%d", &t);
//    
//    while (t--) {
//        scanf("%d", &n);
//        printf("%lld\n", countTiling(n));
//    }
//    
//    return 0;
//}
//修改思路 
//#include <stdio.h>
//long long total[40];
//int main(){
//	//init
//	total[0]= 1,total[1] = 2,total[2] = 7;
//	for(int i = 3;i < 35;i++) total[i] = 3 * total[i - 1] + total[i - 2] - total[i - 3];
//	int T;
//	scanf("%d",&T);
//	while(T--){
//		int n;
//		scanf("%d",&n);
//		printf("%lld\n",total[n]);
//	}
//	return 0;
//} 

//----------------------------------------------
//问题 J: 组合数
//#include <stdio.h>
//
//long long C(int n,int m){
//	long long result = 1;
//	if(n > m)return 0;
//	if(n == 0|| m == 0 || m - n == 0)return 1;
//	
//	n = n > m - n ? m - n : n;
//	for(int i = 1;i <= n;i++){
//		result = result * (m - n + i) / i;
//	}
//	return result;
//}
//
//int main(){
//	int k = 0;
//	while(1){
//		int n;
//		scanf("%d",&n);
//		
//		if(n < 0){
//			return 0;
//		}
//		
//		printf("2^%d=",n);
//		for(int i = 0;i <= n;i++){
//			if(i != 0)printf("+");
//			printf("%lld",C(i,n));
//		}
//		printf("\n");
//	}
//	return 0;
//}
//----------------------------------------------
//问题 K: Coins 
//#include <stdio.h> 
//
//int main(){
//	long long dp[50] = {0};
//	dp[0] = 1;
//	dp[1] = 2; 
//	for(int i = 2;i <= 41;i++){
//		dp[i] = dp[i - 1] + dp[i - 2];
//	}
//	
//	int n;
//	while(1){
//		scanf("%d",&n);
//		if(n == 0)return 0;
//		printf("%lld\n",dp[n]);
//	}
//}

//----------------------------------------------
//问题 L: Wave
//#include <stdio.h>
//
//long long combination(int n, int k) {
//    if (k < 0 || k > n) return 0;
//    if (k == 0 || k == n) return 1;
//    
//    // 使用较小的k值计算
//    if (k > n - k) k = n - k;
//    
//    long long result = 1;
//    for (int i = 1; i <= k; i++) {
//        result = result * (n - k + i) / i;
//    }
//    return result;
//}
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    
//    while (T--) {
//        int n;
//        scanf("%d", &n);
//        
//        long long result = 0;
//        int max_k = n / 2;
//        
//        for (int k = 0; k <= max_k; k++) {
//            long long term = combination(n, k) * combination(n - k, k);
//            result += term;
//        }
//        
//        printf("%lld\n", result);
//    }
//    return 0;
//}
//思路2 动态规划 
//#include <stdio.h>
//
//int main(){
//	long long dp[43][101] = {0};
//	long long result[43] = {0};
//	
//	dp[0][50] = 1;//这里的 0 50 代表 i = 0 j = 0
//	result[0] = 1; 
//	
//	for(int i = 1; i <= 42;i++){
//		for(int j = -i;j <= i;j++){
//			int j_index = j + 50;
//			dp[i][j_index] = dp[i - 1][j_index] + dp[i - 1][j_index - 1] + dp[i - 1][j_index + 1];
//		}
//		result[i] = dp[i][50];
//	}
//	 
//	//输入 
//	int T;
//	scanf("%d",&T);
//	
//	while(T--){
//        int n;
//        scanf("%d", &n);
//        printf("%lld\n", result[n]);
//	}
//	return 0;
//}

//问题 F: 按位或
//#include <stdio.h>
//#include <stdlib.h>
//#define MOD 998244353
//long long fact[200010];
//void init() {
//    fact[0] = 1;
//    for (int i = 1; i < 200010; i++) {
//        fact[i] = fact[i-1] * i % MOD;
//    }
//}
//int main(){
//	init();
//	int T;
//	scanf("%d",&T);
//	while(T--){
//		int n;
//		scanf("%d",&n);
//		unsigned int *arr = (unsigned int*)calloc(n,sizeof(unsigned int));
//		for(int i = 0;i < n;i++)scanf("%u",arr + i);
//		unsigned int total = arr[0];
//		for(int i = 1;i < n;i++)total = total|arr[i];
//		unsigned long long diff = 0;
//		for(int i = 0;i < n;i++)if(arr[i] == total)diff++;
//		if(diff < 2){
//			puts("0");
//			continue;
//		}
//		unsigned long long result = 1;
//		result = ((diff % MOD * (diff - 1) % MOD) % MOD * fact[n - 2] ) % MOD;
//		printf("%llu\n",result);
//		free(arr);
//	}
//} 
