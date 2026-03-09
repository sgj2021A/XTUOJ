#define _CRT_SECURE_NO_WARNINGS
//问题 A: 游戏套装

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main() {
//    int** total = (int**)malloc(sizeof(int*) * 10001);
//
//    for (int i = 0; i <= 10000; i++) {
//        total[i] = (int*)malloc(sizeof(int) * 5);
//        for (int j = 0; j <= 4; j++) {
//            total[i][j] = 0;
//        }
//    }
//
//    int n, m, start = 1000000, end = -1, min = 1000000;
//    char str[10];
//    scanf("%d %d", &n, &m);
//    for (int i = 0; i < n; i++) {
//        scanf("%s", str);
//        //      printf("当前str : %s ; ",str);
//                //getchar(); 
//        char to = str[0];
//        int len = strlen(str);
//
//        char num_str[10];
//        for (int j = 0; j < len - 1; j++) {
//            num_str[j] = str[j + 1];
//        }
//        num_str[len - 1] = '\0';
//        int to_num = atoi(num_str);
//        //      printf("当前位置 : %c %d\n",to,to_num);
//        if (str[0] == 'A') {
//            total[to_num][0] = i + 1;
//        }
//        else if (str[0] == 'B') {
//            total[to_num][1] = i + 1;
//        }
//        else if (str[0] == 'C') {
//            total[to_num][2] = i + 1;
//        }
//        else if (str[0] == 'D') {
//            total[to_num][3] = i + 1;
//        }
//        else if (str[0] == 'E') {
//            total[to_num][4] = i + 1;
//        }
//        //test
////      printf("\n"); 
////      for(int j = 1;j <= m;j++){
////          for(int z = 0;z < 5;z++){
////              printf("%d ",total[j][z]);
////          }
////          printf("\n");
////      }
////      printf("\n");
//        //test
//        for (int j = 0; j < 5; j++) {
//            if (total[to_num][j] == 0) {
//                break;
//            }
//            else if (j == 4) {
//                int start_cs = 1000000, end_cs = -1;
//                for (int z = 0; z < 5; z++) {
//                    if (total[to_num][z] < start_cs)start_cs = total[to_num][z];
//                    if (total[to_num][z] > end_cs)end_cs = total[to_num][z];
//                }
//                int min_cs = end_cs - start_cs;
//                if (min > min_cs) {
//                    //  printf("change min : %d\n",min_cs); 
//                    start = start_cs;
//                    end = end_cs;
//                    min = min_cs;
//                }
//            }
//        }
//    }
//
//    printf("%d %d", start, end);
//
//    for (int i = 0; i <= 10000; i++) {
//        free(total[i]);
//    }
//    free(total);
//    return 0;
//}

//问题 B: 性价比

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#define forn(i,n) for(int i=0;i<(int)n;i++)
//
//typedef struct {
//    int a, b;
//}item;
//
//int compare(void const* a, void const* b) {
//    item t1 = *(item*)a;
//    item t2 = *(item*)b;
//    long long val1 = (long long)t1.a * t2.b;
//    long long val2 = (long long)t2.a * t1.b;
//    if (val1 > val2) return -1;
//    else if (val1 < val2) return 1;
//    else return 0;
//}
//
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    item arr[100100];
//
//    forn(i, n) scanf("%d", &(arr[i].a));
//    forn(i, n) scanf("%d", &(arr[i].b));
//
//    qsort(arr, n, sizeof(item), compare);
//
//    if (n == 1) {
//        printf("res:0\n");
//        return 0;
//    }
//
//    long long res = 0;
//    int left = 0, right = n - 1;
//
//
//    while (left < right) {
//
//        long long product_numerator = (long long)arr[left].a * arr[right].a;
//        long long product_denominator = (long long)arr[left].b * arr[right].b;
//
//        if (product_numerator > product_denominator) {
//            res += (right - left);
//            left++;
//        }
//        else {
//            right--;
//        }
//    }
//
//    printf("%lld\n", res);
//    return 0;
//}

//问题 C: 分类

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <limits.h>
//int arr[10010];
//int compare(const void* a, const void* b) {
//	return (*(int*)a - *(int*)b);
//}
//bool process(int base, int n, int m) {
//	int count = 1;
//	int last = arr[0];
//	for (int i = 1; i < n; i++) {
//		if (arr[i] - last > base) {
//			count++;
//			last = arr[i];
//			if (count > m)return false;
//		}
//	}
//	return true;
//}
//void solve() {
//	int n, m;
//	scanf("%d %d", &n,&m);
//	for (int i = 0; i < n; i++)scanf("%d", arr + i);
//	qsort(arr, n, sizeof(int), compare);
//	long long res = arr[n - 1] - arr[0];
//	int l = 0, r = arr[n - 1] - arr[0];
//	while (l < r) {
//		int min = l + (r - l) / 2;
//		if (process(min,n,m)) {
//			res = min;
//			r = min;
//		}
//		else {
//			l = min + 1;
//		}
//	}
//	printf("%lld\n", res);
//}
//int main() {
//	int T;
//	scanf("%d", &T);
//	while (T--)solve();
//	return 0;
//}

//问题 D: 众数

//#include <stdio.h>
//#include <stdlib.h>
//#define max(x,y) ((x) > (y) ? (x) : (y))
//int arr[100010];
//int compare(const void* a, const void* b) {
//	return (*((int*)a) - *((int*)b));
//}
//void solve() {
//	int n, k;
//	scanf("%d %d", &n, &k);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, n, sizeof(int), compare);
//	int res = 1;
//	for (int i = n - 1; i >= 0; i--) {
//		int temp = 1, t = k;
//		for (int j = i - 1; j >= 0; j--) {
//			if (t - (arr[i] - arr[j]) < 0)break;
//			else {
//				temp++;
//				t -= arr[i] - arr[j];
//			}
//		}
//		res = max(temp, res);
//	}
//	printf("%d\n", res);
//}
//int main() {
//	int T;
//	scanf("%d", &T);
//	while (T--)solve();
//}
//贪心思路时间超限
//#include <stdio.h>
//#include <stdlib.h>
//int arr[100010];
//long long pref[100010];
//int compare(const void* a, const void* b) {
//    return *(int*)a - *(int*)b;
//}
//int process(int m, int n, int k) {
//    for (int i = m - 1; i < n; ++i) {
//        long long sum = pref[i + 1] - pref[i - m + 1];
//        long long cost = (long long)arr[i] * m - sum;
//        if (cost <= k) return 1;
//    }
//    return 0;
//}
//void solve() {
//    int n, k;
//    scanf("%d %d", &n, &k);
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &arr[i]);
//    }
//    qsort(arr, n, sizeof(int), compare);
//
//    pref[0] = 0;
//    for (int i = 0; i < n; ++i) {
//        pref[i + 1] = pref[i] + arr[i];
//    }
//
//    int ans = 1;
//    int l = 1, r = n;
//    while (l <= r) {
//        int mid = l + (r - l) / 2;
//        if (process(mid, n, k)) {
//            ans = mid;
//            l = mid + 1; 
//        }
//        else {
//            r = mid - 1;
//        }
//    }
//    printf("%d\n", ans);
//}
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        solve();
//    }
//    return 0;
//}