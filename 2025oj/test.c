////Contest1076 - 2025ƒÍC”Ô—‘»Î∂”œ∞Ã‚-0x15£®ƒ£ƒ‚£©
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main() {
//	int s;
//	scanf("%d", &s);
//
//	while (s--) {
//		int size;
//		scanf("%d", &size);
//		
//		//¥¥Ω®µÿÕº map[y][x]
//		char** map = (char**)malloc(sizeof(char*) * size);
//		for (int i = 0; i < size + 1; i++) {
//			map[i] = (char*)malloc(sizeof(char*) * (size + 1));
//		}
//		
//		//¥¥Ω®¥¢¥Ê ˝◊È
//		int *low_B = (int*)calloc(size, sizeof(int));//––¥¢¥Êy ∫⁄∆Â
//		int *line_B = (int*)calloc(size, sizeof(int));//¡–¥¢¥Êx ∫⁄∆Â
//		int** memo_B = (int**)calloc(size, sizeof(int*));//¥¢¥Ê–±Ω« ∫⁄∆Â
//		for (int i = 0; i < size; i++) {
//			memo_B[i] = (int*)calloc(size, sizeof(int));
//		}
//		int* low_W = (int*)calloc(size, sizeof(int));//––¥¢¥Êy ∞◊∆Â
//		int* line_W = (int*)calloc(size, sizeof(int));//¡–¥¢¥Êx ∞◊∆Â
//		int** memo_W = (int**)calloc(size, sizeof(int*));//¥¢¥Ê–±Ω« ∞◊∆Â
//		for (int i = 0; i < size; i++) {
//			memo_W[i] = (int*)calloc(size, sizeof(int));
//		}
//
//		// ‰»ÎµÿÕº
//		for (int i = 0; i < size; i++) {
//			scanf("%s", map[i]);
//		}
//
//		int range = size - 3;
//		int total_B = 0;//∫⁄∆Â
//		int total_W = 0;//∞◊∆Â
//
//		for (int x = 0; x < size; x++) {
//			for (int y = 0; y < size; y++) {
//				if (x > range && y > range)break;
//
//				if (line[x] == 0) {
//					if (map[y][x] == 'B' && map[y][x + 1] == 'B' && map[y][x + 1] == 'B') {
//						line[x] = 1;
//						total_B++;
//						continue;
//					}
//				}
//
//				if (low[y] == 0) {
//					if (map[y][x] == 'B' && map[y + 1][x] == 'B' && map[y + 2][x] == 'B') {
//						low[y] = 1;
//						total_B++;
//						continue;
//					}
//				}
//
//			}
//		}
//		//«Â≥˝µÿÕº
//		for (int i = 0; i < size + 1; i++) {
//			free(map[i]);
//		}
//		free(map);
//		for (int i = 0; i < size; i++) {
//			free(memo_B[i]);
//			free(memo_W[i]);
//		}
//		free(memo_W);
//		free(memo_B);
//		free(line_B);
//		free(line_W);
//		free(low_B);
//		free(low_W);
//	}
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        int bucket[1001] = { 0 };
//        int n;
//        char control;
//        scanf("%d %c", &n, &control);
//        int temp;
//        for (int i = 0; i < n; i++) {
//            scanf("%d", &temp);
//            bucket[temp]++;
//        }
//        if (control == 'A') {
//            for (int i = 0; i <= 1000; i++) {
//                while (bucket[i]--) printf("%d ", i);
//            }
//            printf("\n");
//        }
//        else {
//            for (int i = 1000; i >= 0; i--) {
//                while (bucket[i]--) printf("%d ", i);
//            }
//            printf("\n");
//        }
//
//    }
//    return 0;
//}
// 
//#include <stdio.h>
//
//void Sort(int arr[], int n, char control) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (control == 'A') {
//                if (arr[j] > arr[j + 1]) {
//                    int temp = arr[j];
//                    arr[j] = arr[j + 1];
//                    arr[j + 1] = temp;
//                }
//            }
//            else {
//                if (arr[j] < arr[j + 1]) {
//                    int temp = arr[j];
//                    arr[j] = arr[j + 1];
//                    arr[j + 1] = temp;
//                }
//            }
//        }
//    }
//}
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        int n;
//        char control;
//        scanf("%d %c", &n, &control);
//
//        int arr[1000]; 
//        for (int i = 0; i < n; i++) {
//            scanf("%d", &arr[i]);
//        }
//        Sort(arr, n, control);
//        for (int i = 0; i < n; i++) {
//            printf("%d ", arr[i]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int gcd(int a, int b) {
//	if (b == 0)return a;
//	else return gcd(b, a % b);
//}
//int main() {
//    int K, N, M;
//    scanf("%d", &K);
//
//    while (K--) {
//        scanf("%d %d", &N, &M);
//        if (M <= 1) {
//            printf("1\n");
//        }
//        else if (M == N) {
//            printf("0\n");
//        }
//        else {
//            int a = N * (N - 1) - M * (M - 1);
//            int b = N * (N - 1);
//            int g = gcd(a, b);
//            a /= g;
//            b /= g;
// 
//            printf("%d/%d\n", a, b);
//        }
//    }
//
//    return 0;
//}

//#include <stdio.h>
//int main() {
//	int arr[3] = {1,2,3};
//	int* p = arr;
//	printf("%d %d %d", *p, *(p + 1),*(p + 2));
//	return 0;
//}