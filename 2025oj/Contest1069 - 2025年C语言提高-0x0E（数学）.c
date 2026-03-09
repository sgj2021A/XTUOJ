//Contest1069 - 2025年C语言提高-0x0E（数学）

//问题 A: 分段

//#include <stdio.h>
//#include <stdlib.h>
//int main(){
//	int n;
//	scanf("%d",&n);
//	
//	long long *arr = (long long*)malloc(sizeof(long long) * n);
//	
//	for(int i = 0;i < n;i++){
//		scanf("%lld",&arr[i]);
//		if(i != 0){
//			arr[i] = arr[i - 1] + arr[i];
//		}
//	}	
//	long long num_max = arr[n - 1];
//	//test
////	for(int i = 0;i < n;i++){
////		printf("%d ",arr[i]);
////	}
////	printf("\n");	
//	//test
//	long long num = 0,unfound = 0;
//	for(int i = 0;i < n;i++){
//		num = arr[i];
//		if(num == 0)continue;
//		if(num_max % num != 0){
//			continue;
//		}
//		unfound = 0;
//		for(int j = i + 1,index = i;j < n;j++){
//			
//			if(arr[j] - arr[index] == num){
//				index = j;
//			}else if(arr[j] - arr[index] > num){
//				unfound = 1;
//				break;
//			}else if(j == n - 1){
//				unfound = 1;
//				break;
//			}
//				
//		}
//		
//		if(unfound == 0){
//			break;
//		}
//	}
//	printf("%lld\n",num);
//	free(arr);
//	return 0;
//}

//------------------------------------------------------
//问题 B: 等比数列的和

//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//typedef struct {
//	long long a,p,k;
//}item;
//
//int compare(const void *x, const void *y) {
//    item *t1 = (item *)x;
//    item *t2 = (item *)y;
//    if (t1->a != t2->a) return (t1->a > t2->a) ? 1 : -1;
//    if (t1->p != t2->p) return (t1->p > t2->p) ? 1 : -1;
//    return (t1->k > t2->k) ? 1 : -1;
//}
//
//int main(){
//	
//	int n;
//	scanf("%d",&n);
//	item* Set = (item*)malloc(sizeof(item) * 1000);
//	int caseNum = 0;
//	while(n--){
//		long long S;
//		int index = 0;
//		caseNum++;
//		scanf("%lld",&S); 
//		
//		int range_a = (int)sqrt(S); 
//		
//        //处理 k=2 的情况
//        for (long long d = 1; d * d <= S; d++) {
//            if (S % d == 0) {
//                // 检查 d = p+1
//                if (d >= 3) {
//                    Set[index].a = S / d;
//                    Set[index].p = d - 1;
//                    Set[index].k = 2;
//                    index++;
//                }
//                // 检查另一个因子
//                long long d2 = S / d;
//                if (d2 != d && d2 >= 3) {
//                    Set[index].a = S / d2;
//                    Set[index].p = d2 - 1;
//                    Set[index].k = 2;
//                    index++;
//                }
//            }
//        }
//        
//        //处理 k >= 3 的情况
//        const int max_k = 60;
//        for (int k = 3; k <= max_k; k++) {
//            for (long long p = 2; ; p++) {
//                
//                long long M = 1;
//                long long term = 1;
//                int overflow = 0;
//                
//                for (int i = 1; i < k; i++) {
//                    // 检查乘法是否溢出
//                    if (term > S / p) {
//                        overflow = 1;
//                        break;
//                    }
//                    term *= p;
//                    // 检查加法是否溢出
//                    if (M > S - term) {
//                        overflow = 1;
//                        break;
//                    }
//                    M += term;
//                }
//                
//                if (overflow) break;
//                
//                // 检查是否能整除
//                if (S % M == 0) {
//                    long long a = S / M;
//                    Set[index].a = a;
//                    Set[index].p = p;
//                    Set[index].k = k;
//                    index++;
//                }
//            }
//        }
//		
//		qsort(Set, index, sizeof(item), compare);
//        printf("Case %d:\n", caseNum);
//        printf("%d\n", index);
//        for (int i = 0; i < index; i++) {
//            printf("%lld %lld %lld\n", Set[i].a, Set[i].p, Set[i].k);
//        }		
//	}
//	free(Set);
//	return 0;
//} 

//------------------------------------------------------
//问题 I: 完全平方数I

//#include <stdio.h>
//#include <math.h>
//
//int main(){
//	int k;
//	scanf("%lld",&k);
//	
//	while(k--){
//		long long n,d = 1;
//		
//		scanf("%d",&n);
//		
//		//n = d*s*s 计算自由基d
//		long long temp = n;
//		long long d_2 = 0;
//		long long d_odd = 0;
//		//处理2 
//		while(temp % 2 == 0){
//			d_2++;
//			temp /= 2;
//		}
//		
//		if(d_2 % 2 == 1)d *= 2;
//		//处理奇数因子
//		for(long long i = 3;i * i <= temp;i += 2){
//			d_odd = 0;
//			while(temp % i == 0){
//				d_odd++;
//				temp /= i;
//			}
//			
//			if(d_odd % 2 == 1)d *= i;			 
//		} 
//		//处理剩余的质因数
//		if(temp > 1){
//			d *= temp;
//		} 
//		
//		//计算u (S = m * m) m = s*d*u
//		long long req = (n - 1) / 2;
//		long long u_min = sqrt((n - 1)/(2 * d));
//		long long u;
//		if(req == 0){
//			u = 0;
//		}else{
//			u = (long long)sqrt((double)req / d);
//			while(d * u * u < req){
//				u++;
//			}
//		}
//		printf("%lld\n",d * u * u - req);
//		
//	}
//	
//	return 0;
//}

//------------------------------------------------------
//问题 E: 平方数及其倍数

//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <stdbool.h>
//#define MAX 1000001
//
//int main(){
//	bool *isPow = (bool*) malloc (sizeof(bool) * MAX);
//	//初始化
//	for(int i = 0;i < MAX;i++){
//		isPow[i] = false; 
//	} 
//	//标记平方数
//	for(int i = 2;i * i < MAX;i++){
//		int pow = i * i;
//		for(int j = pow,index = 2;j < MAX;j =pow * index,index++){
//			isPow[j] = true;
//		}
//	}
//	//构建前缀和
//	int *pre = (int*) malloc (sizeof(int) * MAX);
//	pre[0] = 0;
//	for(int i = 1;i < MAX;i++){
//		pre[i] = pre[i - 1];
//		if(isPow[i])pre[i]++;
//	} 
//	
//	free(isPow);
//	//输出
//	int k;
//	scanf("%d",&k);
//	while(k--){
//		int start,end;
//		scanf("%d %d",&start,&end);
//		printf("%d\n",pre[end] - pre[start - 1]);
//	} 
//	
//	free(pre);
//	return 0;
//}

//------------------------------------------------------
//问题 F: 奇因数

//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//#define MAX 1000001 
//
//int main(){
//	//素数处理
//	bool *isOdd = (bool *)malloc(sizeof(bool) * MAX);
//	int *prime = (int*)malloc(sizeof(int) * MAX / 10);
//	int primeCount = 0; 
//	for(int i = 1;i < MAX;i++){
//		isOdd[i] = true;
//	}
//	isOdd[1] = false;
//	for(int i = 2;i < MAX;i++){
//		if(isOdd[i])prime[primeCount++] = i;
//		
//		for(int j = 0;j < primeCount && i * prime[j] < MAX;j++){
//			isOdd[i * prime[j]] = false;
//			if(i % prime[j] == 0)break;
//		}
//	}
//	free(prime);
//	
//	for(int i = 3;i < MAX;i++){
//		if(!isOdd[i]){
//			int temp = i;
//			int total = 0;
//			//处理2 
//			if(i % 2 == 0){
//				total = 1;
//				while(temp % 2 == 0){
//					temp /= 2;
//				}
//			}
//			//处理奇数因子
//			int t = 0;
//			for(t = 3;t * t <= temp;t += 2){
//				if(temp % t == 0){
//					total++;
//					while(temp % t == 0){
//						temp /= t; 
//					}
//				}
//			}
//			if(t <= temp){
//				total++;
//			}
//			//是否为奇因数
//			if(total % 2 == 1){
//				isOdd[i] = true;
//			} 
//			//printf("%d:%d ",i,total);
//		}
//	}
//	//test
////	printf("\n");
////	for(int i = 1;i < 20;i++){
////		printf("%d:%d ",i,isOdd[i]);
////	}
////	printf("\n");
//	//test 
//	int *pre = (int*)malloc(sizeof(int) * MAX);
//	pre[0] = 0;
//	for(int i = 1;i < MAX;i++){
//		pre[i] = pre[i - 1];
//		if(isOdd[i]){
//			pre[i]++;
//		}
//	}
//	free(isOdd);
//	//输入
//	int k = 0;
//	scanf("%d",&k);
//	while(k--){
//		int start,end;
//		scanf("%d %d",&start,&end);
//		printf("%d\n",pre[end] - pre[start - 1]);
//	}	 
//	free(pre);
//	return 0;
//}

//超时
// #include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//#define MAX 1000001 
//
//int main(){
//    //素数处理
//    bool *isOdd = (bool *)malloc(sizeof(bool) * MAX);
//    int *prime = (int*)malloc(sizeof(int) * MAX / 10);
//    int primeCount = 0; 
//    
//    // 初始化所有数为true，但1不是素数
//    for(int i = 1; i < MAX; i++){
//        isOdd[i] = true;
//    }
//    isOdd[1] = false;
//    
//    // 使用筛法计算不同质因数的个数
//    int *omega = (int *)calloc(MAX, sizeof(int));
//    
//    for(int i = 2; i < MAX; i++){
//        if(omega[i] == 0){ // i是素数
//            for(int j = i; j < MAX; j += i){
//                omega[j]++; // 增加不同质因数的计数
//            }
//        }
//    }
//    
//    // 标记奇因数（不同质因数个数为奇数）
//    for(int i = 1; i < MAX; i++){
//        isOdd[i] = (omega[i] % 2 == 1);
//    }
//    
//    free(omega);
//    free(prime);
//    
//    // 构建前缀和数组
//    int *pre = (int*)malloc(sizeof(int) * MAX);
//    pre[0] = 0;
//    for(int i = 1; i < MAX; i++){
//        pre[i] = pre[i - 1];
//        if(isOdd[i]){
//            pre[i]++;
//        }
//    }
//    
//    // 输入处理
//    int k = 0;
//    scanf("%d", &k);
//    while(k--){
//        int start, end;
//        scanf("%d %d", &start, &end);
//        // 边界检查
//        if(start == 0) start = 1;
//        printf("%d\n", pre[end] - pre[start - 1]);
//    }
//    
//    free(isOdd);
//    free(pre);
//    return 0;
//

//------------------------------------------------------
//问题 C: Dual Prime

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#define MaxPrimeRange 1000000
//int main(){
//	bool *isPrime = (bool*)malloc(sizeof(bool) * (MaxPrimeRange + 1));
//	int *Prime = (int *)malloc(sizeof(int) * (MaxPrimeRange / 10));
//	int index = 0;
//	for(int i = 2;i <= MaxPrimeRange;i++)isPrime[i] = true;
//	isPrime[0] = false;
//	isPrime[1] = false;
//	
//	for(int i = 2;i <= MaxPrimeRange;i++){
//		if(isPrime[i])Prime[index++] = i;
//		
//		for(int j = 0;j < index;j++){
//			long long p = (long long)i * Prime[j];
//			if(p > MaxPrimeRange)break;
//			isPrime[p] = false;
//			if(i % Prime[j] == 0)break;
//		}
//	}
//
//	for(int i = 0; i <= MaxPrimeRange;i++){
//		isPrime[i] = false;
//	}
//	for(int i = 0;i < index;i++){
//		for(int j = i + 1;j < index;j++){
//			long long p = (long long)Prime[i] * Prime[j]; 
//			if(p > MaxPrimeRange)break; 
//			isPrime[p] = true;
//		}
//	}
//	
//	int *pre = (int*)malloc(sizeof(int) * MaxPrimeRange);
//	pre[0] = 0;
//	for(int i = 1;i <= MaxPrimeRange;i++){
//		pre[i] = pre[i - 1];
//		if(isPrime[i])pre[i]++;		
//	}
//	
//	int k = 0;
//	scanf("%d",&k);
//	while(k--){
//		int start,end;
//		scanf("%d %d",&start,&end);
//		printf("%d\n",pre[end] - pre[start - 1]);
//	}
//	free(pre);
//	free(isPrime);
//	free(Prime);
//	return 0;	 
//} 

//----------------------------------------------
//问题 K: 因子和

//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#include <math.h>
//int main(){
//	long long num;
//	while(1){
//		
//		scanf("%lld",&num);
//		
//		if(num == 0)return 0;
//		
//		if(num == 1){
//			printf("1\n");
//			continue;
//		}
//		long long total = 1 + num;
//		long long max_range = sqrt(num);
//		for(long long i = 2; i <= max_range;i++){
//			long long a = num / i;
//			if(a * i == num){
//				if(a == i){
//					total += i;
//				}else{
//					total += (i + a);
//				}
//			}
//		}		
//		
//		printf("%lld\n",total);
//	} 
//	
//}

//----------------------------------------------
//问题 J: 完全平方数II

//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//int compare(const void *a, const void *b) {
//    return (*(long long *)a - *(long long *)b);
//}
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//		long long b,c;
//		scanf("%lld %lld",&b,&c);
//		
//		long long D =  b * b - 4 * c;
//		
//		int total = 0;
//		long long result[1000] = {0};
//		
//		if(D == 0){
//			if(b % 2 == 0)printf("-1\n");
//			else printf("0\n");
//			continue;
//		}  
//		
//		long long absD = llabs(D);
//		long long rangeN = (long long)sqrt(absD);
//		
//		for(long long i = 1;i <= rangeN;i++){
//			if(absD % i == 0){
//				
//				if(D > 0){
//					long long u = i;
//					long long v = D / i;
//					
//					if(v - u > 0 && (v - u) % 4 == 0){
//						long long x = u + v - 2 * b;
//						
//						if(x % 4 == 0 && x > 0)result[total++] = x / 4;
//						
//					}
//				}else{
//					long long u = -i;
//					long long v = -D / i;
//					
//					if(v - u >= 4 && (v - u) % 4 == 0){
//						long long x = u + v - 2 * b;
//						
//						if(x % 4 == 0 && x > 0)result[total++] = x / 4;
//						
//					}					
//				}
//			}
//		}
//		if(total == 0){
//			printf("0\n");
//		}else{
//			qsort(result,total,sizeof(long long),compare);
//			int unique = 0;//判断是否相同(去重)
//			for(int i = 0;i < total;i++){
//				if(i == 0 || result[i] != result[i - 1]){
//					result[unique++] = result[i];
//				}			
//			} 
//            for (int i = 0; i < unique; i++) {
//                if (i > 0) printf(" ");
//                printf("%lld", result[i]);
//            }	
//			printf("\n");			
//		}
//    }
//    return 0;
//}

//----------------------------------------------
//问题 H: Factorization
#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//#include <stdbool.h>
//#define MAX 1000001
//
//bool prime[MAX];
//long long pre[MAX];
//int total[MAX] = { 0 };
//static void init() {
//	for (int i = 0; i < MAX; i++) prime[i] = true;
//	for (int i = 2; i < MAX; i++) {
//		if (prime[i]) {
//			total[i] = 1;
//			int temp = i;
//			for (int j = 2; temp * j < MAX; j++) {
//				total[j * temp]++;
//				prime[j * temp] = false;
//			}
//		}
//	}
//	for (int i = 2; i < MAX; i++) {
//		pre[i] = pre[i - 1] + total[i];
//	}
//}
//int main() {
//	int T;
//	scanf("%d", &T);
//	init();
//	while (T--) {
//		int start, end;
//		scanf("%d %d", &start, &end);
//		printf("%lld\n", pre[end] - pre[start - 1]);
//	}
//	return 0;
//}

//----------------------------------------------
//问题 D: 函数

//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//#define MAX 1000001
//
//bool prime[MAX];
//long long pre[MAX];
//int total[MAX];
//static void init() {
//	int index = 0;
//	for (int i = 0; i < MAX; i++) prime[i] = true;
//	prime[0] = prime[1] = false;
//	for (int i = 2; i < MAX; i++) {
//		if (prime[i]) {
//			total[i] = 1;
//			for (int j = i + i; j < MAX; j += i) {
//				int temp = j;
//				prime[j] = false;
//				int count = 0;
//				while (temp % i == 0) {
//					count++;
//					temp /= i;
//				}
//				total[j] += count; 
//			}
//		}
//	}
//	pre[1] = 0;
//	for (int i = 2; i < MAX; i++) {
//		pre[i] = pre[i - 1] + total[i];
//	}
//}
//int main() {
//	int T;
//	init();
//	scanf("%d", &T);
//
//	while (T--) {
//		int start, end;
//		scanf("%d %d", &start, &end);
//		printf("%lld\n", pre[end] - pre[start - 1]);
//	}
//	return 0;
//}


//----------------------------------------------
//问题 G: Euler's Totient Function

//#include <stdio.h>
//#include <stdbool.h>
//#define MAX 3000100
//
//bool prime[MAX];
//long long pre[MAX];
//long long total[MAX] = { 0 };
//static void init() {
//	for (int i = 0; i < MAX; i++) {
//		prime[i] = true;
//		total[i] = i;
//	}
//	total[1] = 1;
//	for (int i = 2; i < MAX; i++) {
//		if (prime[i]) {
//			total[i] = i - 1;
//			int temp = i;
//			for (int j = 2; temp * j < MAX; j++) {
//				total[j * temp] = total[j * temp] / temp * (temp - 1);
//				prime[j * temp] = false;
//			}
//		}
//	}
//	for (int i = 1; i < MAX; i++) {
//		pre[i] = pre[i - 1] + total[i];
//	}
//}
//int main() {
//	int T;
//	scanf("%d", &T);
//	init();
//	while (T--) {
//		int start, end;
//		scanf("%d %d", &start, &end);
//		printf("%lld\n", pre[end] - pre[start - 1]);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//typedef struct {
//    int a, b, c;
//}V;
//V v[4000000];
//int compare(const void* a, const void* b) {
//    V temp1 = *(V*)a;
//    V temp2 = *(V*)b;
//    if (temp1.c > temp2.c) return 1;
//    if (temp1.c < temp2.c) return -1;
//    if (temp1.a > temp2.a) return 1;
//    if (temp1.a < temp2.a) return -1;
//    if (temp1.b > temp2.b) return 1;
//    if (temp1.b < temp2.b) return -1;
//    return 0;
//}
//int count = 0;
//int main() {
//    int T;
//    int C = 1;
//    scanf("%d", &T);
//    while (T--) {
//        char str[2010];
//        count = 0;
//        scanf("%s", str);
//        int len = strlen(str);
//        if (len < 3) {
//            printf("Case %d:\n", C++);
//            printf("0\n");
//            continue;
//        }
//        int pre[2021];
//        if (str[0] == '0')pre[0] = 0;
//        else pre[0] = 1;
//        for (int i = 1; i < len; i++) {
//            if (str[i] == '0') pre[i] = pre[i - 1];
//            else pre[i] = pre[i - 1] + 1;
//        }
//        for (int i = 1; i < len; i++) {
//            for (int j = i + 1; j < len; j++) {
//                int temp1 = abs(i - 2 * pre[i - 1]);
//                int temp2 = abs(j - i - 2 * (pre[j - 1] - pre[i - 1]));
//                int temp3 = abs(len - j - 2 * (pre[len - 1] - pre[j - 1]));
//
//                //printf("%d %d %d\n", temp1,temp2,temp3);
//                if (temp1 == temp2 && temp3 == temp2 && temp1 == temp3) {
//                    v[count].a = i;
//                    v[count].b = j;
//                    v[count].c = temp1;
//                    count++;
//                }
//            }
//        }
//        qsort(v, count, sizeof(V), compare);
//
//        printf("Case %d:\n", C++);
//        if (count == 0) {
//            printf("0\n");
//            continue;
//        }
//
//        int total_c = 0;
//        for (int i = 0; i < count; i++) {
//            if (i == 0) total_c = 1;
//            else if (v[i].c != v[i - 1].c) total_c++;
//        }
//        printf("%d\n", total_c);
//        printf("%d = (%d,%d)", v[0].c, v[0].a, v[0].b);
//        for (int i = 1; i < count; i++) {
//            if (v[i].c != v[i - 1].c) {
//                printf("\n%d = (%d,%d)", v[i].c, v[i].a, v[i].b);
//            }
//            else {
//                printf(" (%d,%d)", v[i].a, v[i].b);
//            }
//        }
//        printf("\n");
//    }
//
//    return 0;
//}