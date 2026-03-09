#define _CRT_SECURE_NO_WARNINGS

//问题 A: 地板砖

//#include <stdio.h>
//#include <string.h>
//#define S 3
//#define MOD 1000000007
//void sup_3(long long arr1[S][S],long long arr2[S][S], long long result[S][S]) {
//	long long temp[S][S];
//	memset(temp, 0, sizeof(temp));
//	for (int i = 0; i < S; i++) {
//		for (int j = 0; j < S; j++) {
//			for (int k = 0; k < S; k++) {
//				temp[i][j] = (temp[i][j] + (arr1[i][k] % MOD * arr2[k][j] % MOD) % MOD) % MOD;
//			}
//		}
//	}
//	memcpy(result, temp, sizeof(temp));
//}
//void sup(long long arr[S][S], long long result[S][S],int n) {
//	long long temp[S][S];
//	long long pow_arr[S][S];
//	memset(temp, 0, sizeof(temp));
//	memcpy(pow_arr, arr, sizeof(temp));
//	for (int i = 0; i < S; i++) result[i][i] = 1;
//	memcpy(temp, result, sizeof(temp));
//	while (n > 0) {
//		if (n & 1) {
//			sup_3(temp, pow_arr, temp);
//		}
//		sup_3(pow_arr, pow_arr, pow_arr);
//		n >>= 1;
//	}
//	memcpy(result, temp, sizeof(temp));
//}
//void sup_1(long long arr[S][S], long long base[S], long long result[S]) {
//	memset(result, 0, sizeof(long long) * S);
//	for (int i = 0; i < S; i++) {
//		for (int k = 0; k < S; k++) {
//			result[i] = (result[i] + (base[k] % MOD * arr[i][k] % MOD) % MOD) % MOD;
//		}
//	}
//}
//int main() {
//	long long M[S][S] = {
//		{2,0,1},
//		{1,0,0},
//		{0,1,0}
//	};
//	long long base[S] = { 2,1,1 };
//	
//	int t = 0;;
//	scanf("%d", &t);
//	while (t--) {
//		int n;
//		long long m[S][S];
//		memset(m, 0, sizeof(m));
//		scanf("%d", &n);
//		if (n == 1) {
//			puts("1");
//			continue;
//		}
//		else if (n == 2) {
//			puts("2");
//			continue;
//		}
//		sup(M, m, n - 2);
//		long long result[S];
//		sup_1(m, base, result);
//		printf("%lld\n", result[0]);
//	}
//	return 0;
//}

//问题 H: 逆序数（大数据）

//#include <stdio.h>
//int main() {
//	while (1) {
//		int n;
//		int arr[10001];
//		scanf("%d", &n);
//		if (n == 0)return 0;
//		for (int i = 0; i < n; i++)scanf("%d", arr + i);
//		long long result = 0;
//		for (int i = n - 1; i > 0; i--) {
//			for (int j = i - 1; j >= 0; j--) {
//				if (arr[j] > arr[i])result++;
//			}
//		}
//		printf("%lld\n", result);
//	}
//	return 0;
//}

//时间超限
//#include <stdio.h>
//#include <stdlib.h>
//
//long long sort(int arr[], int temp[], int left,int mid, int right) {
//	int k1 = left, k2 = mid + 1, index = left;
//	long long count = 0;
//	while (k1 <= mid && k2 <= right) {//使用双指针排序数组
//		if (arr[k1] < arr[k2]) temp[index++] = arr[k1++];
//		else {
//			temp[index++] = arr[k2++];
//			count += (mid - k1 + 1);//核心代码
//			//当处理左右两侧的数组时，左右两侧数组已经是有序的了
//			//并且是从小到大排序，mid是左半部分最后一个数据的索引
//			//k1是当前左半部分最后一个位置的索引，min - k1 + 1是
//			//从k1 到 mid 的元素个数,左右数组不用管内部是否有逆序数
//			//在之前的递归中已经计算过了
//			//如果 arr[i] > arr[j]，那么 arr[k1+1], arr[k1+2], ..., arr[mid] 也都大于 arr[k2]
//		}
//	}
//	//填充后续数组
//	while (k1 <= mid)temp[index++] = arr[k1++];
//	while (k2 <= right)temp[index++] = arr[k2++];
//	//填充回原数组
//	for (int i = left; i <= right; i++)arr[i] = temp[i];
//	return count;
//}
//
//long long process(int arr[], int temp[], int left, int right) {
//	long long count = 0;
//	if (left < right) {
//		int mid = left + (right - left) / 2;
//		count += process(arr, temp, left, mid);
//		count += process(arr, temp, mid + 1, right);
//		count += sort(arr, temp, left, mid, right);
//	}
//	return count;
//}
//
//int main() {
//	int n;
//	int arr[10001], temp[10001];
//	while (1) {
//		scanf("%d", &n);
//		if (n == 0)return 0;
//		for (int i = 0; i < n; i++) scanf("%d", arr + i);
//		long long result = 0;
//		result = process(arr, temp, 0, n - 1);
//		printf("%lld\n", result);
//	}
//	return 0;
//}

//问题 G: 分苹果

//#include <stdio.h>
//#define MOD 1000000007
//#define MAX 1000
//long long C[MAX + 1][MAX + 1];
//void init_C() {
//	for (int i = 0; i <= MAX; i++) {
//		C[i][0] = 1;
//		for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
//	}
//}
//long long process(int n, int m, int k) {
//	if (n < m)return 0;
//	if (m * k < n)return 0;
//	long long result = 0;
//	int range = (n - m) / k;
//	for (int i = 0; i <= range; i++) {
//		long long j = n - i * k - 1;
//		if (j < m - 1) continue;
//		long long term = C[m][i] * C[j][m - 1] % MOD;
//		if (i & 1)  result = (result - term + MOD) % MOD;
//		else  result = (result + term) % MOD;
//	}
//	return result;
//}
//int main() {
//	int T;
//	scanf("%d", &T);
//	init_C();
//	while (T--) {
//		int n, m, k;
//		scanf("%d %d %d", &n, &m, &k);
//		long long result = process(n, m, k);
//		printf("%lld\n", result);
//	}
//	return 0;
//}

//问题 F: 积

//#include <stdlib.h>
//#include <stdio.h>
//#include <stdbool.h>
//#define MOD 1000000007
//int read() {
//	long long x = 0, f = 1;
//	char c = getchar();
//	while (c < '0' || c > '9') {
//		if (c == '-')f = -1;
//		c = getchar();
//	}
//	while (c >= '0' && c <= '9') {
//		x = x * 10 + c - '0';
//		c = getchar();
//	}
//	return x * f;
//}
//int compare(const void* a, const void* b) {
//	int result = *(long long*)a > *(long long*)b ? 1 : *(long long*)a == *(long long*)b ? 0 : -1;
//	return result;
//}
//int find(int* arr,int size) {
//	int result = 0;
//	int temp = llabs(arr[0]);
//	for (int i = 1; i < size; i++) {
//		if (llabs(arr[i]) < temp) {
//			temp = llabs(arr[i]);
//			result = i;
//		}
//	}
//	return result;
//}
//int main() {
//	long long T = read();
//	while (T--) {
//		long long n, m;
//		long long arr[10001] = { 0 };
//		bool choose[10001] = { 0 };
//		n = read();
//		m = read();
//		for (int i = 0; i < n; i++) arr[i] = read();
//		qsort(arr, n, sizeof(long long), compare);
//		long long result = 1,f = 1;
//		int total = 0;
//		int i = 0, j = n - 1;
//		for (; i < j;) {
//			if (total >= m)break;
//			if (llabs(arr[i]) < llabs(arr[j])) {
//				choose[j] = true;
//				if (arr[j] < 0)f *= -1;
//				j--;
//			}
//			else {
//				choose[i] = true;
//				if (arr[i] < 0)f *= -1;
//				i++;
//			}
//		}
//		if (f < 0 && arr[j] > 0) {
//			int index = i - 1;
//			while (index > 0 && arr[index] > 0) {
//				index--;
//			}
//			choose[index] = false;
//			choose[j] = true;
//		}
//		else if(f < 0){
//			for (int z = 0; z < n; z++) choose[z] = false;
//			i = j = find(arr, n);
//			total = 0;
//			for (;i >= 0 && j < n;) {
//				if (total >= m)break;
//				if (llabs(arr[i]) > llabs(arr[j])) {
//					choose[j] = true;
//					j++;
//				}
//				else {
//					choose[i] = true;
//					i--;
//				}
//			}
//			if (total != m) {
//				if (i <= 0) {
//					for (int z = 0, p = j; z < m - total; z++) choose[p++] = true;
//				}
//				else {
//					for (int z = 0, p = i; z < m - total; z++) choose[p--] = true;
//				}
//			}
//		}
//		for (int z = 0; z < n; z++) if (choose[z])result = (result * arr[z]) % MOD;
//		printf("%lld\n", result);
//	}
//	return 0;
//}

//修改，思路问题
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#define MOD 1000000007
//int compare(const void* a, const void* b) {
//	return *((long long*)a) >= *((long long*)b) ? 1 : -1;
//}
//int compare_P(const void* a, const void* b) {
//	return *((long long*)a) < *((long long*)b) ? 1 : -1;
//}
//int read() {
//	long long x = 0, f = 1;
//	char c = getchar();
//	while (c < '0' || c > '9') {
//		if (c == '-')f = -1;
//		c = getchar();
//	}
//	while (c >= '0' && c <= '9') {
//		x = x * 10 + c - '0';
//		c = getchar();
//	}
//	return x * f;
//}
//int main() {
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		long long Z = 0, P[10001] = { 0 }, N[10001] = { 0 };
//		bool P_B[10001] = { false }, N_B[10001] = { false };
//		int indexP = 0, indexN = 0,f = 1;
//		int n, k;
//		long long result = 1;
//		scanf("%d %d", &n, &k);
//		//特殊情况n = k时
//		if (n == k) {
//			for (int i = 0; i < n; i++) result = (result * read()) % MOD;
//			printf("%lld\n", result);
//			continue;
//		}
//		//处理一般情况
//		for (int i = 0; i < n; i++) {
//			long long temp = read();
//			if (temp < 0)N[indexN++] = temp;
//			else if (temp > 0)P[indexP++] = temp;
//			else Z = 1;//分离零
//		}
//		qsort(P, indexP, sizeof(long long), compare_P);
//		qsort(N, indexN, sizeof(long long), compare);
//		int kP = 0, kN = 0;
//		//使用双指针
//		for (kP = 0, kN = 0; kN < indexN && kP < indexP && kP + kN < k;) {
//			if (llabs(P[kP]) <= llabs(N[kN])) {
//				//printf("choose : %lld\n", N[kN]);
//				N_B[kN++] = true;
//				f *= -1;
//			}
//			else {
//				//printf("choose : %lld\n", P[kP]);
//				P_B[kP++] = true;
//			}
//		}
//		//处理双指针没有弄完的部分
//		if (kP + kN < k) {
//			while (kN < indexN && kP + kN < k) {
//				N_B[kN++] = true;
//				f *= -1;
//			}
//			while (kP < indexP && kP + kN < k) P_B[kP++] = true;
//		}
//		//处理特殊情况
//		//1.如果当前 result 为负数
//		if (f < 0) {
//			//如果除了0外所有乘积是负数
//			if (indexP + indexN == k && Z) {
//				printf("0\n");
//				continue;
//			}else if (indexP == 0) {//如果说没有正数
//				if (Z) {//如果有0
//					printf("0\n");
//					continue;
//				}
//				else {//如果没有0
//					for (int i = 0; i < indexN; i++)N_B[i] = false;
//					for (int i = 0,v = indexN - 1;i < k; i++)N_B[v--] = true;
//				}
//			}
//			else {//如果有正数
//				if (kP == indexP) {//正数全部用完了
//					P_B[kP - 1] = false;
//					N_B[kN] = true;
//				}
//				else if(kN == indexN){//负数用完了
//					N_B[kN - 1] = false;
//					P_B[kP] = true;
//				}
//				else {//都没有用完
//					if (llabs(N[kN]) > llabs(P[kP])) {
//						P_B[kP - 1] = false;
//						N_B[kN] = true;
//					}
//					else {
//						N_B[kN - 1] = false;
//						P_B[kP] = true;
//					}
//				}
//			}
//		}
//
//		//计算结果
//		//printf("result : %lld\n", result);
//		for (int i = 0; i < indexN; i++) if (N_B[i]) {
//			result = (result * N[i]) % MOD;
//			//printf("result : %lld\n", result);
//		}
//		for (int i = 0; i < indexP; i++) if (P_B[i]) {
//			result = (result * P[i]) % MOD;
//			//printf("result : %lld\n", result);
//		}
//		printf("%lld\n", result);
//	}
//	return 0;
//}

//问题 E: 斐波拉契+1

//#include <stdio.h>
//#include <string.h>
//
//#define MOD 1000000007LL
//#define N 3
//
//typedef long long ll;
//
//// 矩阵乘法
//void mul(ll a[N][N], ll b[N][N], ll c[N][N]) {
//    ll temp[N][N] = { 0 };
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            for (int k = 0; k < N; k++) {
//                temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % MOD;
//            }
//        }
//    }
//    memcpy(c, temp, sizeof(temp));
//}
////矩阵快速平方
//void pow(ll a[N][N], ll k, ll res[N][N]) {
//    ll temp[N][N];
//    memcpy(temp, a, sizeof(temp));
//    memset(res, 0, sizeof(ll) * N * N);
//    for (int i = 0; i < N; i++) {
//        res[i][i] = 1;
//    }
//    while (k > 0) {
//        if (k & 1) {
//            mul(res, temp, res);
//        }
//        mul(temp, temp, temp);
//        k >>= 1;
//    }
//}
//void m(ll mat[N][N], ll vec[N], ll res[N]) {
//    ll temp[N] = { 0 };
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            temp[i] = (temp[i] + mat[i][j] * vec[j]) % MOD;
//        }
//    }
//    memcpy(res, temp, sizeof(temp));
//}
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    // 递推矩阵 M
//    ll M[N][N] = {
//        {1, 1, 1},
//        {1, 0, 0},
//        {0, 0, 1}
//    };
//    ll init[N] = { 1, 1, 1 };
//
//    while (T--) {
//        ll n;
//        scanf("%lld", &n);
//        if (n == 0) {
//            printf("1\n");
//            continue;
//        }
//        ll Mp[N][N];
//        pow(M, n - 1, Mp);
//        ll res_vec[N];
//        m(Mp, init, res_vec);
//        printf("%lld\n", res_vec[0]);
//    }
//
//    return 0;
//}

//问题 D: 斐波拉契数的平方和

//#include<stdio.h>
//#include<stdlib.h>
//#include <string.h>
//#define N 2
//#define MOD 1000000007LL
//void mul(long long first[N][N], long long last[N][N], long long result[N][N]) {
//	long long temp[N][N] = { 0 };
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			for (int z = 0; z < N; z++) {
//				temp[i][j] = (temp[i][j] + first[i][z] * last[z][j]) % MOD;
//			}
//		}
//	}
//	memcpy(result, temp, sizeof(temp));
//}
//void pow(long long mat[N][N], long long k, long long result[N][N]) {
//	long long temp[N][N];
//	memcpy(temp, mat, sizeof(temp));
//	memset(result, 0, sizeof(long long) * N * N);
//	for (int i = 0; i < N; i++)result[i][i] = 1;
//	while (k > 0) {
//		if (k & 1)mul(result, temp, result);
//		mul(temp, temp, temp);
//		k >>= 1;
//	}
//}
//void m(long long mat[N][N], long long v[N], long long result[N]) {
//	long long temp[N] = { 0 };
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			temp[i] = (temp[i] + mat[i][j] * v[j]) % MOD;
//		}
//	}
//	memcpy(result, temp, sizeof(temp));
//}
//int main() {
//	long long M[N][N] = {
//		{1,1},
//		{1,0}
//	};
//	long long init[N] = { 1,1 };
//	
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		long long a = 0 , b = 0;
//		scanf("%lld %lld", &a, &b);
//		//f0²+f1²+f2²+....+fn² = fn*f(n+1);
//		long long result_1 = 0;
//		long long result_2 = 0;
//		if (a == 0) {
//			result_1 = 0;
//		}
//		else {
//			long long MatFirst[N][N];
//			long long I[N];
//			memcpy(MatFirst, M, sizeof(MatFirst));
//			memcpy(I, init, sizeof(I));
//			pow(MatFirst, a - 1, MatFirst);
//			m(MatFirst, I, I);
//			long long temp1 = I[0];
//			long long temp2 = I[1];
//			result_1 = (temp1 * temp2) % MOD;
//		}
//		long long MatFirst[N][N];
//		long long I[N];
//		memcpy(MatFirst, M, sizeof(MatFirst));
//		memcpy(I, init, sizeof(I));
//		pow(MatFirst, b, MatFirst);
//		m(MatFirst, I, I);
//		long long temp1 = I[0];
//		long long temp2 = I[1];
//		result_2 = (temp1 * temp2) % MOD;
//		long long result = (result_2 - result_1 + MOD) % MOD;
//		printf("%lld\n", result);
//	}
//	return 0;
//}