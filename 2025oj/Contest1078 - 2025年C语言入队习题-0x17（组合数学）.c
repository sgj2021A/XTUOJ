#define _CRT_SECURE_NO_WARNINGS

//问题 G: 积木III

//#include <stdio.h>
//#include <stdlib.h>
//long long total;
//
//int mul(int n) {
//	int result = 1;
//	for (int i = 2; i <= n; i++) result *= i;
//	return result;
//}
//
//void process(int n,int m,int start) {
//	if (m == 0) {
//		if (n == 0) total++;
//		return;
//	}
//	if (n < start)return;
//	for (int i = start; i <= n; i++) {
//		process(n - i, m - 1, i + 1);
//	}
//}
//
//int main() {
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		int n, m;
//		scanf("%d %d", &n, &m);
//		int min_total = m * (m + 1) / 2;
//		if (n < min_total) {
//			puts("0");
//			continue;
//		}
//		total = 0;
//		int mut = mul(m);
//		if (n == min_total) {
//			printf("%d\n", mut);
//			continue;
//		}
//		else {
//			process(n, m, 1);
//			printf("%lld\n", total);
//		}
//	}
//	return 0;
//}

//修改，递归时间超限,使用DP
//#include <stdio.h>
//
//#define MAX_N 100
//#define MAX_M 10
//
//long long dp[MAX_N + 1][MAX_M + 1];
//long long fact[MAX_M + 1];
////dp[i][j] = dp[i-j][j-1] + dp[i-j][j]
//void init() {
//    fact[0] = 1;
//    for (int i = 1; i <= MAX_M; i++) {
//        fact[i] = fact[i - 1] * i;
//    }
//    dp[0][0] = 1;
//    for (int i = 1; i <= MAX_N; i++) {
//        for (int j = 1; j <= MAX_M; j++) {
//            if (i >= j) {
//                dp[i][j] = dp[i - j][j - 1] + dp[i - j][j];
//            }
//        }
//    }
//}
//
//int main() {
//    init();
//
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        int n, m;
//        scanf("%d %d", &n, &m);
//        if (m * (m + 1) / 2 > n) {
//            printf("0\n");
//        }
//        else {
//            printf("%lld\n", dp[n][m] * fact[m]);
//        }
//    }
//    return 0;
//}

//----------------------------------------------
//问题 H: Blocks

//#include <stdio.h>
//  
//int total;
//
//void process(int n, int l, int m) {
//    if (m == 1) {
//        if (n < l && n >= 1) {
//            total++;
//        }
//        return;
//    }
//    for (int i = (l - 1 < n - m + 1 ? l - 1 : n - m + 1); i >= n / m; i--) {
//        if (i >= 1) {
//            process(n - i, i, m - 1);
//        }
//    }
//}
//
//int main() {
//
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        int n, m;
//        scanf("%d %d", &n, &m);
//        total = 0;
//
//        if (m == 1) {
//            printf("1\n");
//            continue;
//        }
//        if (n < m) {
//            printf("0\n");
//            continue;
//        }
//        for (int i = n - 1; i >= n / m; i--) {
//            if (i >= 1) {
//                process(n - i, i, m - 1);
//            }
//        }
//        printf("%d\n", total);
//    }
//    return 0;
//}

//----------------------------------------------
//问题 F: 积木II

//#include <stdio.h>
//#include <stdlib.h>
//int total;
//void process(int max, int n) {
//	if (n == 0 && max >= 0) {
//		total++;
//		return;
//	}
//	if (max < 0 || n <= 0) return;
//	for (int i = max; i >= n; i--) {
//		process(i - 1, n - 1);
//	}
//}
//
//int main() {
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		int n, m;
//		scanf("%d %d", &n, &m);
//		int result = 0;
//		int num_left = 1, num_right = m - 2;
//		//遍历所有位置
//		for (int i = 0; i < m - 2; i++) {
//			//确定所有数值
//			for (int j = n; j >= 0; j--) {
//				int left_total = n - j - 1;
//				for (int z = left_total; z >= (num_left + 1) * num_left / 2; z--) {
//					int right_total = n - j - left_total;
//					total = 0;
//					process(z, i);
//					int left = total;
//					total = 0;
//					process(right_total, right_total);
//					int right = total;
//					result += (left * right);
//				}
//			}
//			num_left++;
//			num_right--;
//		}
//		printf("%d\n", result);
//	}
//	return 0;
//}

//重写
//#include <stdio.h>
//#include <string.h>
//
//#define MAXN 100
//#define MAXM 10
//long long process(int n, int m, int min) {
//    if (m == 0) {
//        return (n == 0) ? 1 : 0;
//    }
//    if (n < min* m + m * (m - 1) / 2) {
//        return 0; 
//    }
//    if (n > max_sum(m, n)) {
//        return 0; 
//    }
//
//    long long count = 0;
//    if (n >= min) count += process(n - min, m - 1, min + 1);
//
//    count += process(n, m, min + 1);
//
//    return count;
//}
//int max_sum(int m, int n) {
//    int sum = 0;
//    for (int i = 0; i < m; i++) {
//        sum += (n - i);
//    }
//    return sum;
//}
//long long power(int base, int exp) {
//    long long result = 1;
//    for (int i = 0; i < exp; i++) {
//        result *= base;
//    }
//    return result;
//}
//
//int main() {
//    int T;
//    scanf("%d", &T);
//
//    while (T--) {
//        int n, m;
//        scanf("%d %d", &n, &m);
//
//        long long c = process(n, m, 1);
//        long long r= power(2, m - 1) - 2;
//
//        printf("%lld\n", c * r);
//    }
//    return 0;
//}

//----------------------------------------------
//问题 E: 红球与蓝球

//#include <stdio.h>
//#define MOD 1000000007
//#define MAX 1000
//
//long long C[MAX + 1][MAX + 1];
//
//void precompute() {
//    for (int i = 0; i <= MAX; i++) {
//        C[i][0] = 1;
//        for (int j = 1; j <= i; j++) {
//            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
//        }
//    }
//}
//
//int main() {
//    precompute();
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        int n, r, b;
//        scanf("%d %d %d", &n, &r, &b);
//        long long result = 0;
//        int min_i = n < r ? n : r;
//        for (int i = 0; i <= min_i; i++) {
//            if (i == 0 && r > 0) continue;
//            if (i > 0 && r == 0) continue;
//            int min_j = (n - i) < b ? (n - i) : b;
//            for (int j = 0; j <= min_j; j++) {
//                if (j == 0 && b > 0) continue;
//                if (j > 0 && b == 0) continue;
//                long long ways_choose = C[n][i] * C[n - i][j] % MOD;
//                long long ways_red = (i == 0) ? 1 : C[r - 1][i - 1];
//                long long ways_blue = (j == 0) ? 1 : C[b - 1][j - 1];
//                result = (result + ways_choose * ways_red % MOD * ways_blue) % MOD;
//            }
//        }
//        printf("%lld\n", result);
//    }
//    return 0;
//}

//----------------------------------------------
//问题 D: 红玫瑰与白玫瑰

//#include <stdio.h>
//#define MAX 410
//#define MOD 1000000007
//long long C[MAX + 1][MAX + 1];
////预处理组合数
//void init_C() {
//	for (int i = 0; i <= MAX; i++) {
//		C[i][0] = 1;
//		for (int j = 1; j <= i; j++) {
//			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
//		}
//	}
//}
//
//long long choose(int r, int i) {
//	if (i == 0) {
//		if (r == 0)return 1;
//		else return 0;
//	}
//	if (r < i) return 0;
//	return C[r - 1][i - 1];
//}
//
//int main() {
//	init_C();
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		int n, m, k;
//		long long result = 0;
//		scanf("%d %d %d", &n, &m, &k);
//		for (int i = 1; i <= n && i < k; i++) {
//			int j = k - i;
//			if (j < 1 || j > m) continue;
//			long long term1 = C[k][i];
//			long long term2 = choose(n, i);
//			long long term3 = choose(m, j);
//			result = (result + term1 % MOD * term2 % MOD * term3 % MOD) % MOD;
//		}
//		printf("%lld\n", result);
//	}
//	return 0;
//}

//----------------------------------------------
//问题 C: 彩球

//#include <stdio.h>
//int compare(const void* a, const void* b) {
//	return *(int*)a - *(int*)b;
//}
//long long C(int n, int m) {
//	long long result = 1;
//	if (n > m)return 0;
//	if (n == 0 || m == 0)return 1;
//	n = n > m - n ? m - n : n;
//	for (int i = 1; i <= n; i++) result = result * (m - n + i) / i;
//	return result;
//}
//int main() {
//	int arr[10001];
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		int s[10001] = { 0 };
//		int n;
//		scanf("%d", &n);
//		for (int i = 0; i < n; i++) scanf("%d", arr + i);
//		qsort(arr, n, sizeof(int), compare);
//		int total = 1;
//		int temp = arr[0];
//		s[total] = 1;
//		for (int i = 1; i < n; i++) {
//			if (arr[i] != temp) {
//				total++;
//				temp = arr[i];
//			}
//			s[total]++;
//		}
//		if (total < 3) {
//			printf("0\n");
//			continue;
//		}
//		long long result = 0;
//		for (int i = 1; i < n; i++) {
//			for (int j = i + 1; j < n; j++) {
//				for (int z = j + 1; z < n; z++) {
//					result += s[i] * s[j] * s[z];
//				}
//			}
//		}
//		printf("%lld\n", result);
//	}
//	return 0;
//}

// Total = Σ [i=1 to k-2] Σ [j=i+1 to k-1] Σ [k=j+1 to k] (f_i × f_j × f_k)
// Total = Σ [j=2 to k-1] [ Σ [i=1 to j-1] Σ [k=j+1 to k] (f_i × f_j × f_k) ]
// Total = Σ [j=2 to k-1] [ f_j × ( Σ [i=1 to j-1] Σ [k=j+1 to k] (f_i × f_k) ) ]
// 因为Σ [i=1 to j-1] Σ [k=j+1 to k] (f_i × f_k) = (Σ[i = 1 to j - 1] f_i) ×(Σ[k = j + 1 to k] f_k)
// Total = Σ [j=2 to k-1] [ f_j × (Σ [i=1 to j-1] f_i) × (Σ [k=j+1 to k] f_k) ]
//时间超限
//#include <stdio.h>
//#include <stdlib.h>
//
//int compare(const void* a, const void* b) {
//    return *(int*)a - *(int*)b;
//}
//
//int main() {
//    int arr[10001];
//    int T;
//    scanf("%d", &T);
//
//    while (T--) {
//        int frequency[10001] = { 0 };
//        int n, unique_count = 0;
//
//        scanf("%d", &n);
//        for (int i = 0; i < n; i++) {
//            scanf("%d", &arr[i]);
//        }
//
//        qsort(arr, n, sizeof(int), compare);
//
//        // 统计频率
//        int current = arr[0], count = 1;
//        for (int i = 1; i < n; i++) {
//            if (arr[i] == current) {
//                count++;
//            }
//            else {
//                frequency[unique_count++] = count;
//                current = arr[i];
//                count = 1;
//            }
//        }
//        frequency[unique_count++] = count;
//
//        if (unique_count < 3) {
//            printf("0\n");
//            continue;
//        }
//
//        // 计算后缀和
//        long long suffix_sum[10001] = { 0 };
//        suffix_sum[unique_count - 1] = 0;
//        for (int i = unique_count - 2; i >= 0; i--) {
//            suffix_sum[i] = suffix_sum[i + 1] + frequency[i + 1];
//        }
//
//        // 使用前缀和和后缀和计算三元组
//        long long result = 0;
//        long long prefix_sum = frequency[0];
//
//        for (int i = 1; i < unique_count - 1; i++) {
//            result += prefix_sum * frequency[i] * suffix_sum[i];
//            prefix_sum += frequency[i];
//        }
//
//        printf("%lld\n", result);
//    }
//    return 0;
//}

//----------------------------------------------
//问题 A: 狼与羊

//#include <stdio.h>
//#include <string.h>
//
//#define MOD 1000000007
//#define MAX 1000
//
//long long S[MAX + 5][MAX + 5];
////S(n,k) = k × S(n-1,k) + S(n-1,k-1)
////第二类斯特林数 S(n,k) 
//void init_stirling() {
//    S[0][0] = 1;
//    for (int i = 1; i <= MAX; i++) {
//        for (int j = 1; j <= i; j++) {
//            S[i][j] = (j * S[i - 1][j] + S[i - 1][j - 1]) % MOD;
//        }
//    }
//}
//
//int main() {
//    init_stirling();
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        int n, m, k;
//        scanf("%d %d %d", &n, &m, &k);
//
//        long long result = 0;
//        int start = (1 > k - m) ? 1 : k - m;
//        int end = (n < k - 1) ? n : k - 1;
//        for (int i = start; i <= end; i++) {
//            if (i >= 1 && i <= n && (k - i) >= 1 && (k - i) <= m) {
//                result = (result + S[n][i] * S[m][k - i]) % MOD;
//            }
//        }
//        printf("%lld\n", result);
//    }
//
//    return 0;
//}
