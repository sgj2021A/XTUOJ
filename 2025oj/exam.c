#define _CRT_SECURE_NO_WARNINGS

//问题 G: 输出大写字母

//#include <string.h>
//#include <stdio.h>
//
//int main() {
//	int n = 0;
//	char temp;
//	scanf("%d", &n);
//
//	getchar();
//	while (n--) {
//		int bucket[26] = { 0 };
//		int found = 0;
//		while (1) {
//			temp = getchar();
//			if (temp == '\n') break;
//
//			if (temp <= 'Z' && temp >= 'A') {
//				if (!bucket[temp - 'A']) {
//					bucket[temp - 'A']++;
//					printf("%c", temp);
//					found = 1;
//				}
//			}
//
//		}
//		if (!found) {
//			printf("Not Found");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//问题 A: 平方差数

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int T;
//	scanf("%d", &T);
//
//	while (T--) {
//		unsigned long long k;
//		scanf("%llu", &k);
//
//		unsigned long long answer = 3;
//		
//		if (k == 1) {
//			printf("3\n");
//		}
//		else {
//			k -= 1;
//			if (k % 3 == 0) {
//				printf("%llu\n", 4 + k / 3 * 4);
//			}
//			else {
//				unsigned long long add;
//				if (k % 3 == 1) {
//					add = 1;
//				}
//				else if (k % 3 == 2) {
//					add = 3;
//				}
//				printf("%llu\n", 4 + k / 3 * 4 + add);
//			}
//		}
//	}
//
//	return 0;
//}

//问题 C: 小明的奇思妙想

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int k;
//	scanf("%d", &k);
//
//	//预处理2幂次数组
//	int* m2 = (int*)calloc(25,sizeof(int));
//	m2[0] = 2;
//	for (int i = 1; i < 21; i++) {
//		m2[i] = m2[i - 1] * 2;
//	}
//	
//	for (int i = 0; i < 21; i++) {
//		if (k == m2[i]) {
//			printf("None");
//			free(m2);
//			return 0;
//		}
//	}
//
//	int add = 0, index = 0,found = 0;
//	int* arr = (int*)malloc(sizeof(int) * k);
//	for (int i = 1; i <= k / 2; i++) {
//		index = 0;
//		add = 0;
//		for (int j = i; add <= k; j++) {
//			arr[index++] = j;
//			add += j;
//
//			if (add > k)break;
//			if (add == k) {
//				found = 1;
//				for (int z = 0; z < index - 1; z++) {
//					printf("%d ", arr[z]);
//				}
//				printf("%d\n",arr[index - 1]);
//			}
//		}
//	}
//
//	if (found == 0) {
//		printf("None");
//	}
//
//	free(arr);
//	free(m2);
//	return 0;
//}

//问题 B: 不动的大图书馆与普通的魔法使
 
//#include <stdio.h>
//#include <stdlib.h>
//
//int compare(const void* a, const void* b) {
//	return *(int*)a - *(int*)b;
//}
//
//int main() {
//	int T;
//	scanf("%d", &T);
//
//	while (T--) {
//		int n;
//		scanf("%d", &n);
//
//		int* arr = (int*)malloc(sizeof(int) * n);
//
//		for (int i = 0; i < n; i++) {
//			scanf("%d", arr + i);
//		}
//		int answer = 0;
//		
//		if (n == 1) {
//			answer = 0;
//		}
//		else {
//			int mex = 0,min = 0;
//			qsort(arr, n, sizeof(int), compare);
//			if (arr[0] == 0)mex = 1;
//			for (int i = 0; i < n - 1; i++) {
//				min = arr[i + 1];
//				if(arr[i] == mex)mex++;
//
//				if (mex == min)answer++;
//			}
//		}
//
//
//		printf("%d\n", answer);
//		free(arr);
//	}
//	return 0;
//}

//问题 D: 书籍搬运

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int T;
//	scanf("%d", &T);
//
//	while (T--) {
//		int n;
//		unsigned long long V, C;
//
//		scanf("%d %llu %llu", &n, &V, &C);
//
//		unsigned long long* arr = (unsigned long long*)malloc(sizeof(unsigned long long) * n);
//		for (int i = 0; i < n; i++) {
//			scanf("%llu", arr + i);
//		}
//
//		int total = 1;
//		int count = 0;
//		
//		for (int i = 0; i < n; i++) {
//			count += arr[i];
//			if (count > V) {
//				total++;
//				count = arr[i];
//			}
//		}
//		
//		printf("%lld\n", C * total);
//
//		free(arr);
//	}
//	return 0;
//}

//问题 E: 神探联盟招募大作战

//#include <stdio.h>
//#include <stdlib.h>
//
//int compare(const void* a, const void* b) {
//    return (*(int*)a - *(int*)b);
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    int *a = (int *) malloc (sizeof(int) * n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &a[i]);
//    }
//    qsort(a, n, sizeof(int), compare);
//    int range = 0;
//    int temp = a[n - 1];
//    int count = 0;
//    int current = 0;
//    for (int i = n - 1; i >= 0; i--) {
//        current++;
//        if (current >= temp) {
//            count++;
//            current = 0;
//            range = i;
//            break;
//        }
//    }
//
//    for (int i = 0; i < range; i++) {
//        current++;
//        if (current >= a[i]) {
//            count++;
//            current = 0;
//        }
//    }
//    printf("%d\n", count);
//    free(a);
//    return 0;
//}


//问题 H: 道路维修问题

//#include <stdio.h>
//#include <stdlib.h>
//int process(int *arr,int m, int s, int c, int index) {
//	printf("index : %d\n", index);
//	int* arr_py = (int*)calloc(s, sizeof(int));
//	for (int i = 0; i < s; i++) {
//		arr_py[i] = arr[i];
//	}
//
//	for (int i = 0; i < s; i++) {
//		if (m > 0) {
//			if (arr_py[i] == 1) {
//				for (int j = i; j < index + i && j < s; j++) {
//					arr_py[j] = 0;
//				}
//				//test
//				printf("change:");
//				for (int j = 0; j < s; j++) {
//					printf("%d", arr_py[j]);
//				}
//				printf("\n");
//				//test
//				i += index;
//				m--;
//			}
//		}
//	}
//
//	for (int i = 0; i < s; i++) {
//		if (arr_py[i] == 1) {
//			return 0;
//		}
//	}
//
//	free(arr_py);
//	return 1;
//}
//int process(int* arr, int left,int size,int range,int m) {
//	int num_1 = 0;
//	int num_2 = 0;
//	int start = 0;
//	int answer = 10000000;
//	for (int i = left; i < size; i++) {
//		if (arr[start] != 1) {
//			start++;
//			num_1++;
//		}
//		else {
//			break;
//		}
//	}
//	if (range > m) {
//		return 10000000;
//	}
//	if ((left >= size || start == size) && range == m) {
//		return 0;
//	}
//	if (left >= size || start == size) {
//		return 10000000;
//	}
//	int index = 1;
//	for (int i = start + 1; i < size; i++) {
//		int temp = index + process(arr, i, size, range + 1, m);
//		index++;
//		answer = temp < answer ? temp : answer;
//	}
//	return answer;
//}
//
//int main() {
//	int m, s, c;
//	
//	scanf("%d %d %d", &m, &s, &c);
//
//	int* arr = (int*)calloc(s,sizeof(int));
//	
//	int temp;
//	for (int i = 0; i < c; i++) {
//		scanf("%d", &temp);
//		arr[temp] = 1;
//	}
//	//test
//	//printf("original :");
//	//for (int j = 0; j < s; j++) {
//	//	printf("%d", arr[j]);
//	//}
//	//printf("\n");
//	//test
//	int answer = process(arr, 0, s, 0, m);
//
//	printf("%d", answer);
//	free(arr);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int process(int* arr, int size) {
//	int min = 1000000;
//	for (int i = 0; i < size; i++) {
//		int temp = arr[i] + arr[(i + 1) % size] + arr[(i + 2) % size];
//		if (min > temp)min = temp;
//	}
//	return min;
//}
//
//int main() {
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		int arr[19] = { 0 };
//		for (int i = 0; i < 19; i++) {
//			scanf("%d", &arr[i]);
//		}
//		int center = 0;
//		for (int i = 0; i < 7; i++) center += arr[i];
//		int min_a = 10000000;
//		int arr_c[6] = { 0 };
//		for (int i = 1; i < 7; i++)arr_c[i - 1] = arr[i];
//		int arr_w[12] = { 0 };
//		for (int i = 7; i < 19; i++)arr_w[i - 7] = arr[i];
//		int out = arr[0] + process(arr_c, 6) + process(arr_w, 12);
//		if (center > out)center = out;
//		printf("%d\n", center);
//	}
//	return 0;
//}