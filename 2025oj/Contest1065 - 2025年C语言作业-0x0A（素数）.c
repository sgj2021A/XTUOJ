//Contest1065 - 2025年C语言作业-0x0A（素数）

//问题 A: Flawless Prime
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <math.h>
//bool Prime(long long num){
//	if(num < 2)return false;
//	if(num == 2 || num == 3)return true;
//	if(num % 2 == 0 || num % 3 == 0)return false;
//	for(long long i = 5;i * i <= num;i += 6){
//		if(num % i == 0 || num % (i + 2) == 0)return false;
//	}
//	return true;
//}
//
//int main(){
//	int k = 0;
//	scanf("%d",&k);
//	while(k--){
//		char num[15] = {0};
//		scanf("%s",num);
//		int num_size = strlen(num);
//		int found = 0;
//		long long number = atoll(num);
//		for(int i = num_size - 1;i >= 0;i--){
//			if(num[i]=='0'){
//				printf("No\n");
//				found = 1;
//				break;
//			}
//			//printf(" %lld ",number);
//			if(!Prime(number)){
//				printf("No\n");
//				found = 1;
//				break;
//			}
//			long long pow_10 = 1;
//			for(int j = 0;j < i;j++){
//				pow_10 *= 10;
//			}
//			//printf(" %lld ",pow_10);
//			number = number % pow_10;
//		}
//		if(found != 1){
//			printf("Yes\n");
//		}
//	}
//	return 0;
//}

//问题 B: 素数(虽然无前导零，但是算的时候算0)（使用6k±1优化法，适用于10^10以内的数）//这里的6 = 2 * 3
//6k：能被6整除，不是素数（除了2,3）
//6k + 2：能被2整除，不是素数
//6k + 3：能被3整除，不是素数
//6k + 4：能被2整除，不是素数
//所有素数（除了2,3）都是6k±1形式
//但不是所有6k±1形式的数都是素数
//6k±1只是素数的必要条件，不是充分条件
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#include <string.h>
//bool Prime(long long num){
//	if(num < 2)return false;
//	if(num == 2 || num == 3) return true;
//	if(num % 2 == 0 || num % 3 == 0) return false;
//	for(long long i = 5;i * i <= num;i += 6){
//		if(num % i == 0)return  false;
//		if(num % (i + 2) == 0)return false;
//	}
//	return true;
//}
//int main(){
//	int k = 0;
//	scanf("%d",&k);
//
//	while(k--){
//		int total = 0;
//		char number[50]={0};
//		scanf("%s",number);
//		for(int i = 0;i < strlen(number);i++){
//			//if(number[i] == '0')continue;
//			char number_choose[50] = {0};
//			int cs = 0;
//			for(int j = 0;j < strlen(number) - i;j++){
//				number_choose[j] = number[i + j];
//				cs = j;
//			}
//			number_choose[cs + 1] = '\0';
//			long long num = atoll(number_choose);
//			for(int j = 0;j < strlen(number) - i;j++){
//				if(j != 0){
//					num = num / 10;
//				}
//				if(Prime(num)){
//					total++;
//				}
//			}
//		}
//		printf("%d\n",total);
//	}
//
//	return 0;
//}

//问题 C: D_Prime
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//bool Prime(long long num){
//	if(num < 2)return false;
//	if(num == 2 || num == 3) return true;
//	if(num % 2 == 0 || num % 3 == 0) return false;
//	for(long long i = 5;i * i <= num;i += 6){
//		if(num % i == 0)return  false;
//		if(num % (i + 2) == 0)return false;
//	}
//	return true;
//}
//int main(){
//	int k = 0;
//	int found = 0;
//	scanf("%d",&k);
//	while(k--){
//		found = 0;
//		long long number = 0;
//		scanf("%lld",&number);
//        if (number < 4) {
//            printf("No\n");
//            continue;
//        }
//		int num_range = sqrt(number);
//		if (num_range * num_range == number && Prime(num_range)) {
//            printf("No\n");
//            continue;
//        }
//		for(long long i = 2;i <= num_range;i++){
//			if(number % i == 0){
//				if(Prime(i)){
//					long long x = number / i;
//					if(Prime(x)){
//						printf("Yes\n");
//						found = 1;
//						break;
//					}
//				}
//			}
//		}
//		if(found == 0){
//			printf("No\n");
//		}
//	}
//	return 0;
//}

//问题 D: 不定方程的正整数解
//#include<stdio.h>
//int main()
//{
//      int t = 0;
//      scanf("%d",&t);
//
//      while(t--){
//              long long a;
//              int count = 0;
//              scanf("%lld",&a);
//              long long i = a - 1,j = 1;
//              for(;i >= 1;i--){//x
//                      if(a*i % (a - i) == 0){
//                              count ++;
//                      }
//              }
//              printf("%d\n",count);
//      }
//      return 0;
//}

//问题 E: Interprime
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#define Max_Range 1000100
//int main(){
//	int count = 0;
//	bool *isPrime = (bool*)malloc(sizeof(bool) * Max_Range);
//	bool *isPrime_average = (bool*)malloc(sizeof(bool) * Max_Range);
//	for(int i = 0;i <  Max_Range;i++){//初始化数组
//		isPrime[i] = true;
//		isPrime_average[i] = false;
//	}
////	isPrime[0] = false;
////	isPrime[1] = false;
////	for(long long i = 2;i * i <= Max_Range;i++){
////		if(isPrime[i]){
////			for(long long j = i * i;j <= Max_Range;j += i){
////				isPrime[j] = false;
////			}
////		}
////	}（超时，改为线性筛选）
//
//	int *primes = (int*)malloc(sizeof(int) * Max_Range);
//	int primeCount = 0;
//	for(int i = 2; i < Max_Range; i++){
//		if(isPrime[i]){
//			primes[primeCount++] = i;
//		}
//		for(int j = 0; j < primeCount && i * primes[j] < Max_Range; j++){
//			isPrime[i * primes[j]] = false;
//			if(i % primes[j] == 0){
//				break;
//			}
//		}
//	}
//	free(primes);
//
//	int frist_prime = 3;
//	for(long long i = 5;i <= Max_Range;i++){
//			if(isPrime[i]){
//				int average = (frist_prime + i) / 2;
//				if(!isPrime[average]){
//					isPrime_average[average] = true;
//				}
//				frist_prime = i;
//			}
//	}
//	int k = 0,a,b;
//	scanf("%d",&k);
//	while(k--){
//		count = 0;
//		scanf("%d %d",&a,&b);
//		for(int i = a;i <= b;i++){
//			if(isPrime_average[i]){
//				count ++;
//			}
//		}
//		printf("%d\n",count);
//	}
//	free(isPrime);
//	free(isPrime_average);
//	return 0;
//}
//前缀和（优化isPrime_average）
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#define Max_Range 1000100
//
//int main(){
//    // 使用前缀和数组优化，prefix[i]表示[0,i]区间内interprime的个数
//    int *prefix = (int*)malloc(sizeof(int) * Max_Range);
//    bool *isPrime = (bool*)malloc(sizeof(bool) * Max_Range);
//
//    // 初始化数组
//    for(int i = 0; i < Max_Range; i++){
//        isPrime[i] = true;
//        prefix[i] = 0;
//    }
//    isPrime[0] = false;
//    isPrime[1] = false;
//
//    // 线性筛选素数
//    int *primes = (int*)malloc(sizeof(int) * Max_Range);
//    int primeCount = 0;
//    for(int i = 2; i < Max_Range; i++){
//        if(isPrime[i]){
//            primes[primeCount++] = i;
//        }
//        for(int j = 0; j < primeCount && i * primes[j] < Max_Range; j++){
//            isPrime[i * primes[j]] = false;
//            if(i % primes[j] == 0){
//                break;
//            }
//        }
//    }
//    free(primes);
//
//    // 计算interprime并构建前缀和数组
//    int first_prime = 3;
//    for(int i = 5; i < Max_Range; i++){
//        if(isPrime[i]){
//            int average = (first_prime + i) / 2;
//            if(average < Max_Range && !isPrime[average]){
//                // 标记这个位置有interprime，我们将在前缀和中处理
//                // 注意：这里不能直接设置prefix，因为可能有多个interprime对应同一个average
//                // 但根据定义，每个average是唯一的
//            }
//            first_prime = i;
//        }
//    }
//
//    // 构建前缀和数组：prefix[i] = 前i个数中interprime的个数
//    // 重新遍历计算interprime并构建前缀和
//    first_prime = 3;
//    for(int i = 5; i < Max_Range; i++){
//        if(isPrime[i]){
//            int average = (first_prime + i) / 2;
//            if(average < Max_Range && !isPrime[average]){
//                // 标记这个average为interprime
//                // 由于我们只需要前缀和，不需要单独存储每个interprime
//                // 我们可以在构建前缀和时直接处理
//            }
//            first_prime = i;
//        }
//    }
//
//    // 更高效的方法：直接构建前缀和数组
//    // 先重置prefix数组
//    for(int i = 0; i < Max_Range; i++){
//        prefix[i] = 0;
//    }
//
//    first_prime = 3;
//    for(int i = 5; i < Max_Range; i++){
//        if(isPrime[i]){
//            int average = (first_prime + i) / 2;
//            if(average < Max_Range && !isPrime[average]){
//                // 标记这个average位置
//                prefix[average] = 1; // 标记为1表示这个位置是interprime
//            }
//            first_prime = i;
//        }
//    }
//
//    // 构建真正的前缀和数组
//    for(int i = 1; i < Max_Range; i++){
//        prefix[i] += prefix[i-1];
//    }
//
//    int k, a, b;
//    scanf("%d", &k);
//    while(k--){
//        scanf("%d %d", &a, &b);
//        // 使用前缀和数组O(1)查询
//        int count = prefix[b] - (a > 0 ? prefix[a-1] : 0);
//        printf("%d\n", count);
//    }
//
//    free(isPrime);
//    free(prefix);
//    return 0;
//}

//问题 H: 哈希
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//
////int compare_arr(const void *a,const void *b){
////    return (*(const long long*)a > *(const long long*)b) - (*(const long long*)a < *(const long long*)b);
////}
//
//int main(){
//	int k = 0;
//	scanf("%d",&k);
//	//创建素数数组
//	bool Prime[10001];
//	for(int i = 0;i <= 10000;i++){
//		Prime[i] = true;
//	}
//	Prime[0] = false;
//	Prime[1] = false;
//	for(int i = 2;i * i <= 10000;i++){
//		if(Prime[i] == true){
//			for(int j = i * i;j <= 10000;j += i){
//				Prime[j] = false;
//			}
//		}
//	}
//
//	while(k--){
//		//创建哈希桶 + 数组
//		long long arr[1001] = {0};
//		int arr_size = 0;
//		scanf("%d",&arr_size);
//
//		//输入数据
//		for(int i = 0;i < arr_size;i++){
//			scanf("%lld",arr + i);
//		}
//		int found = 0;
//		//qsort(arr,arr_size,sizeof(long long),compare_arr);//对数组进行排序
//        for(int i = 2;i <= 10000;i++){
//            if(Prime[i]){
//                int *bucket = (int*)calloc(i, sizeof(int));
//                int valid = 1;
//
//                for(int j = 0;j < arr_size;j++){
//                    int remainder = arr[j] % i;
//                    if(bucket[remainder] >= 2){
//                        valid = 0;
//                        break;
//                    }else{
//                        bucket[remainder]++;
//                    }
//                }
//
//                free(bucket);
//
//                if(valid){
//                    printf("%d\n",i);
//                    break;
//                }
//            }
//        }
//	}
//
//	return 0;
//}


//问题 I: Prime Twins
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#define MaxRange 5000100
//int main(){
//	bool *isPrime = (bool*) malloc (sizeof(bool) * MaxRange);//初始化素数数组
//	for(int i = 0;i < MaxRange;i++){
//		*(isPrime + i) = true;
//	}
//	isPrime[0] = false;
//	isPrime[1] = false;
//
//	//初始化数组（线性）
//	int *primes = (int*)malloc(sizeof(int) * MaxRange);
//    int primeCount = 0;
//    for(long long i = 2; i < MaxRange; i++){
//        if(isPrime[i]){
//            primes[primeCount++] = i;
//        }
//        for(long long j = 0; j < primeCount && i * primes[j] < MaxRange; j++){
//            isPrime[i * primes[j]] = false;
//            if(i % primes[j] == 0){
//                break;
//            }
//        }
//    }
//    free(primes);
//
//    //前缀和优化
//	int *total = (int*)malloc(sizeof(int) * MaxRange);
//	int pre_total = 0;
//	int temp = 3;
//	for(int i = 0;i <= 1;i++){
//		total[i] = 0;
//	}
//	for(int i = 2;i < MaxRange - 2;i++){
//		total[i] = pre_total;
//		if(isPrime[i]){
//			if(isPrime[i + 2]){
//				pre_total += 1;
//				total[i] = pre_total;
//			}
//		}
//	}
//    for(int i = MaxRange-2; i < MaxRange; i++){
//        total[i] = total[i-1];
//    }
//	//主程序
//	int k = 0;
//	scanf("%d",&k);
//	while(k--){
//		int a,b;
//		scanf("%d %d",&a,&b);
//        if(b < a + 2) {
//            printf("0\n");
//        } else {
//            int count = total[b-2] - (a > 0 ? total[a-1] : 0);
//            printf("%d\n", count);
//        }
//	}
//    free(isPrime);
//    free(total);
//	return 0;
//}

///问题 F: 素数字符串
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <math.h>
//
//#define MaxRange 1000010
//int main() {
//    // 初始化素数数组
//    bool *primes = calloc(MaxRange, sizeof(bool));
//    for (int i = 2; i < MaxRange; i++) primes[i] = true;
//    primes[0] = primes[1] = false;
//
//    // 素数判断
//    for (long long i = 2; i <= sqrt(MaxRange); i++) {
//        if (primes[i]) {
//            for (long long j = i * i; j < MaxRange; j += i) {
//                primes[j] = false;
//            }
//        }
//    }
//
//      // 字符串编写
//      char *str = (char*)malloc(sizeof(char) * MaxRange);
//      int location = 0;
//      for(int i = 2; i < MaxRange; i++){
//              if(primes[i]){
//                      char str_num[20];
//                      sprintf(str_num,"%d",i);
//              for (int j = 0; str_num[j] != '\0'; j++) {
//                  if (location >= MaxRange - 1) break;
//                  str[location++] = str_num[j];
//              }
//              }
//              if(location >= MaxRange)break;
//      }
//      free(primes);
//      // 主函数
//      int k = 0;
//      scanf("%d",&k);
//      while(k--){
//              int a,b,c,count = 0;
//              scanf("%d %d %d",&a,&b,&c);
//              for(int i = a - 1;i < b;i++){
//                      if(str[i] - '0' == c){
//                              count++;
//                      }
//              }
//              printf("%d\n",count);
//      }
//    free(str);
//    return 0;
//}
//时间超限（前缀和(二位数组)优化）
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MaxRange 2500000
int main() {
	// 初始化素数数组
	bool *primes = calloc(MaxRange, sizeof(bool));
	for (int i = 2; i < MaxRange; i++) primes[i] = true;
	primes[0] = primes[1] = false;

	// 素数判断
	for (long long i = 2; i <= sqrt(MaxRange); i++) {
		if (primes[i]) {
			for (long long j = i * i; j < MaxRange; j += i) {
				primes[j] = false;
			}
		}
	}
	// 字符串编写
	char *str = (char*)malloc(sizeof(char) * MaxRange);
	int location = 0;
	for(int i = 2; i < MaxRange; i++) {
		if(primes[i]) {
			char str_num[20];
			sprintf(str_num,"%d",i);
			for (int j = 0; str_num[j] != '\0'; j++) {
				if (location >= MaxRange - 1) break;
				str[location++] = str_num[j];
			}
		}
		if(location >= MaxRange)break;
	}
	free(primes);
//	printf("%d\n",location);
	//前缀和优化
	int *total[10];
	for(int i = 0;i < 10;i++){
		total[i] = (int *)malloc(sizeof(int) * location + 1);
		total[i][0] = 0;
	} 	
	for(int i = 1;i <= location; i++){
		for(int j = 0;j < 10;j++){
			total[j][i] = total[j][i - 1];
		}
		total[str[i - 1] - '0'][i]++;
	}
	free(str);
//	for(int i = 999900;i <= 1000000;i++){
//		printf("%d : ",i);
//		for(int j = 0;j < 10;j++){
//			printf("%d ",total[j][i]);
//		}
//		printf("\n");
//	}
	// 主函数
	int k = 0;
	scanf("%d",&k);
	while(k--) {
		int a,b,c,count = 0;
		scanf("%d %d %d",&a,&b,&c);
		printf("%d\n",total[c][b] - total[c][a - 1]);
	}
    for(int j = 0; j < 10; j++) free(total[j]);
	return 0;
}
//问题 G: 素数个数
//#include <stdio.h>
//#include <stdbool.h>
//#include <math.h>
//bool Prime(long long number){
//      if(number == 0 || number == 1)return false;
//      if(number == 2 || number == 3)return true;
//      if(number % 2 == 0 || number % 3 == 0)return false;
//      long long number_range = (long long)sqrt(number);
//      for(int i = 5;i <= number_range;i += 6){
//              if(number % i == 0){
//                      return false;
//              }
//              if(number % (i + 2) == 0){
//                      return false;
//              }
//      }
//      return true;
//}
//
//int main(){
//      int T = 0;
//      scanf("%d",&T);
//      while(T--){
//              long long L,R;
//              int count = 0;
//              scanf("%lld %lld",&L,&R);
//              if(L <= 3){
//                      while(L < 3 && L <= R){
//                              if(L == 2 || L == 3){
//                                      count++;
//                              }
//                              L++;
//                      }
//              }else{
//                      if(L % 2 == 0){
//                              L++;
//                      }
//              }
//              for(;L <= R;L += 2){
//                      if(Prime(L)){
//                              count++;
//                      }
//              }
//              printf("%d",count);
//      }
//}

//欧拉筛法（线性筛法）分段筛法(6K+1超时)（需要看一下）
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#include <math.h>
//
//#define MAX_BASE 1000000  // 基础筛法上限（sqrt(R)）
//
//void baseSieve(int n, bool *isPrime, int *primes, int *primeCount) {
//    for (int i = 0; i <= n; i++) isPrime[i] = true;
//    isPrime[0] = isPrime[1] = false;
//    *primeCount = 0;
//
//    for (int i = 2; i <= n; i++) {
//        if (isPrime[i]) {
//            primes[(*primeCount)++] = i;
//        }
//        for (int j = 0; j < *primeCount && i * primes[j] <= n; j++) {
//            isPrime[i * primes[j]] = false;
//            if (i % primes[j] == 0) break;
//        }
//    }
//}
//
//int segmentedSieve(long long L, long long R, int *primes, int primeCount) {
//    int segmentSize = 1000000;  // 每段长度
//    bool *isSegmentPrime = (bool *)malloc((segmentSize + 1) * sizeof(bool));
//    int count = 0;
//
//    for (long long low = L; low <= R; low += segmentSize) {
//        long long high = (low + segmentSize - 1) < R ? (low + segmentSize - 1) : R;
//        for (long long i = 0; i <= high - low; i++) isSegmentPrime[i] = true;
//
//        for (int i = 0; i < primeCount; i++) {
//            long long p = primes[i];
//            long long start = (low + p - 1) / p * p;  // 找到 ≥low 的第一个 p 的倍数
//            if (start == p) start = p * 2;            // 避免标记 p 本身
//            for (long long j = start; j <= high; j += p) {
//                isSegmentPrime[j - low] = false;
//            }
//        }
//
//        for (long long num = low; num <= high; num++) {
//            if (num >= 2 && isSegmentPrime[num - low]) {
//                count++;
//            }
//        }
//    }
//
//    free(isSegmentPrime);
//    return count;
//}
//
//int main() {
//    int T;
//    scanf("%d", &T);
//
//    bool *isBasePrime = (bool *)malloc((MAX_BASE + 1) * sizeof(bool));
//    int *primes = (int *)malloc((MAX_BASE + 1) * sizeof(int));
//    int primeCount;
//
//    baseSieve(MAX_BASE, isBasePrime, primes, &primeCount);
//
//    while (T--) {
//        long long L, R;
//        scanf("%lld %lld", &L, &R);
//
//        if (R <= MAX_BASE) {
//            // 直接查询预处理结果
//            int count = 0;
//            for (long long num = L; num <= R; num++) {
//                if (isBasePrime[num]) count++;
//            }
//            printf("%d\n", count);
//        } else {
//            // 分段筛法
//            int count = segmentedSieve(L, R, primes, primeCount);
//            printf("%d\n", count);
//        }
//    }
//
//    free(isBasePrime);
//    free(primes);
//    return 0;
//}


//问题 J: 方程
//#include <stdio.h>
//#include <math.h>
//int main(){
//	int k = 0;
//	scanf("%d",&k);
//	while(k--){
//		long long a, b, c;
//		scanf("%lld %lld %lld",&a,&b,&c);
//		long long x = 0,y = 0;
//		long long arr[2][200000]={0},count = 0;//内存不够大
//		long long e = c + a * b;
//		if(e == 0){
//			printf("1\n");
//			printf("%lld %lld\n", -b, -a);
//			continue;
//		}
//		for(long long i = 1;i * i <= e;i++){
//			if(e % i == 0){
//				long long j = e / i;
//				x = i - b;
//				y = j - a;
//                if (x >= 0 && y >= 0) {
//                    arr[0][count] = x;
//                    arr[1][count] = y;
//                    count++;
//                }
//                if(i != j){
//					x = j - b;
//					y = i - a;
//	                if (x >= 0 && y >= 0) {
//	                    arr[0][count] = x;
//	                    arr[1][count] = y;
//	                    count++;
//	                }
//				}
//			}
//		}
//		if(count == 0){
//			printf("0\n");
//		}else{
//			printf("%lld\n",count);
//			for(int i = 0;i < count;i++){
//				printf("%lld %lld\n",arr[0][i],arr[1][i]);
//			}
//		}
//	}
//	return 0;
//}

//修正（内存不够大+必须得要排序）
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//typedef struct {
//    long long x;
//    long long y;
//} Solution;
//int compare(const void *a, const void *b) {
//    Solution *s1 = (Solution *)a;
//    Solution *s2 = (Solution *)b;
//    if (s1->x != s2->x) return (s1->x > s2->x) ? 1 : -1;
//    return (s1->y > s2->y) ? 1 : -1;
//}
////返回负数：a 应该排在 b 前面（a < b）。
////返回正数：a 应该排在 b 后面（a > b）。
////返回 0：a 和 b 相等（顺序不影响排序）。
////先按 x 升序排序
////如果 x 相同，再按 y 升序排序
//int main() {
//    int k = 0;
//    scanf("%d", &k);
//
//    while (k--) {
//        long long a, b, c;
//        scanf("%lld %lld %lld", &a, &b, &c);
//
//        long long e = c + a * b;
//        Solution *solutions = malloc(200000 * sizeof(Solution));
//        long long count = 0;
//
//        if (e == 0) {
//            printf("1\n");
//            printf("%lld %lld\n", -b, -a);
//            free(solutions);
//            continue;
//        }
//
//        for (long long i = 1; i * i <= e; i++) {
//            if (e % i == 0) {
//                long long j = e / i;
//
//                long long x1 = i - b;
//                long long y1 = j - a;
//                if (x1 >= 0 && y1 >= 0) {
//                    solutions[count].x = x1;
//                    solutions[count].y = y1;
//                    count++;
//                }
//
//                if (i != j) {
//                    long long x2 = j - b;
//                    long long y2 = i - a;
//                    if (x2 >= 0 && y2 >= 0) {
//                        solutions[count].x = x2;
//                        solutions[count].y = y2;
//                        count++;
//                    }
//                }
//            }
//        }
//        // 排序
//        qsort(solutions, count, sizeof(Solution), compare);
//        if (count == 0) {
//            printf("0\n");
//        } else {
//            printf("%lld\n", count);
//            for (int i = 0; i < count; i++) {
//                printf("%lld %lld\n", solutions[i].x, solutions[i].y);
//            }
//        }
//
//        free(solutions);
//    }
//
//    return 0;
//}
