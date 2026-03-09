#define _CRT_SECURE_NO_WARNINGS
//-------------------------------------------------
//问题 A: 填数

//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
//int total_sup[1001];
//int num_sup;
//static int init(char *control,int* sup,int n) {
//	int len = strlen(control);
//	int add = 0;
//	for (int i = 0; i < len; i++) {
//		if (control[i] == '-')(*sup)++;
//		else add++;
//	}
//
//	if (sup == n - 1 || add == n - 1) {
//		return 0;
//	}
//
//	if (sup == 1 && control[0] == '-') {
//		return 0;
//	}
//
//	if (n % 4 == 2 || n % 4 == 1) {
//		return 0;
//	}
//	return 1;
//}
////int compare(const void* a, const void* b) {
////	return *(int*)a - *(int*)b;
////}
//
//static void output(char* control,int n) {
//	int len = strlen(control);
//	//qsort(total_sup, num_sup, sizeof(int), compare);
//	int* total_add = (int*)calloc(n + 1, sizeof(int));
//	for (int i = 0; i < num_sup; i++) {
//		total_add[total_sup[i]] = 1;
//	}
//	int temp = 1;
//	while (1) {
//		if (total_add[temp] == 0) {
//			printf("%d", temp);
//			temp++;
//			break;
//		}
//		temp++;
//	}
//	int index_add = 0, index_sup = 0;
//	for (int i = 0; i < len; i++) {
//		if (control[i] == '+') {
//			while (1) {
//				if (total_add[temp] == 0) {
//					printf(" %d", temp);
//					temp++;
//					break;
//				}
//				temp++;
//			}
//		}
//		else {
//			printf(" %d", total_sup[index_sup++]);
//		}
//	}
//	printf("\n");
//}
//
//static int process(int sup, int add, int index) {
//
//	if (add == 0 && sup == 0) {
//		return 1;
//	}
//	
//	if (sup <= 0) {
//		if (add != 0)return 0;
//	}
//	if (add < 0) return 0;
//	if (index == 0)return 0;
//
//	total_sup[num_sup++] = index;
//	if (process(sup - 1, add - index * 2, index - 1)) {
//		return 1;
//	}
//	else {
//		num_sup--;
//		return process(sup, add, index - 1);
//	}
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
//		char str[1001];
//
//		scanf("%s", str);
//		
//		int sup = 0;
//		int pd = init(str, &sup, n);
//
//		if (pd == 0) {
//			printf("impossible\n");
//			continue;
//		}
//		num_sup = 0;
//		int add = (n + 1) * n / 2;
//		
//		int result = process(sup, add, n);
//
//		if (result == 0) {
//			printf("impossible\n");
//		}
//		else {
//			output(str,n);
//		}
//
//		//test
//		//printf("TEST\n");
//		//printf("sup : %d\n", sup);
//		//printf("add : %d\n", add);
//		//printf("result : %d\n", result);
//		//printf("\n");
//		//test
//
//	}
//
//	return 0;
//}

//修改思路
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
//int total_add[1500];
//int num_add;
//
//static void output(char* control,int n) {
//	int len = strlen(control);
//	//qsort(total_sup, num_sup, sizeof(int), compare);
//	int total_sup[1500] = { 0 };
//	int temp_sup[1500] = { 0 };
//	int temp = 0;
//	for (int i = 0; i < num_add; i++) {
//		total_sup[total_add[i]] = 1;
//	} 
//	for (int i = 1; i <= n; i++) {
//		if (total_sup[i] == 0)temp_sup[temp++] = i;
//	}
//	printf("%d", total_add[0]);
//	int index_add = 1, index_sup = 0;
//	for (int i = 0; i < len; i++) {
//		if (control[i] == '-') {
//			printf(" %d", temp_sup[index_sup++]);
//		}
//		else {
//			printf(" %d", total_add[index_add++]);
//		}
//	}
//	printf("\n");
//}
//
//void init(int* sup,int *add,char* str) {
//	int len = strlen(str);
//	(*sup) = 0;
//	(*add) = 1;
//	for (int i = 0; i < len; i++) {
//		if (str[i] == '-')(*sup)++;
//		else (*add)++;
//	}
//}
//
//int main() {
//	int T;
//	scanf("%d", &T);
//
//	while (T--) {
//		num_add = 0;
//		char str[1001];
//		int n;
//		scanf("%d", &n);
//		scanf("%s", str);
//
//		int add, sup;
//		init(&sup, &add, str);
//
//		long long max = 0, min = 0;
//		max = min = (n + 1) * n / 2;
//
////		printf("init : max : %d min : %d\n", max, min);
//		if ((n * (n + 1) / 2) % 2 != 0) {
//			printf("impossible\n");
//			continue;
//		}
//		int temp = n;
//		for (int i = 1; i <= sup; i++) {
//			max -= i * 2;
//			min -= temp * 2;
//			temp--;
//		}
//
////		printf("change : max : %d min : %d\n", max, min);
//
//		if (min > 0 || min > max || min % 2 != 0) {
//			printf("impossible\n");
//			continue;
//		}
//
//		if (min == 0) {
//			for (int i = 1; i <= add; i++) {
//				total_add[num_add++] = i;
//			}
//			output(str, n);
//			continue;
//		}
//		if (max == 0) {
//			temp = n;
//			for (int i = 1; i <= add; i++) {
//				total_add[num_add++] = temp;
//				temp--;
//			}
//			output(str, n);
//			continue;
//		}
//
//		int a = abs(min / 2);
//		for (int i = 1; i <= add; i++) {
//			total_add[num_add++] = i;
//		}
//		int b = a / add;
//		int c = a % add;
//		for (int i = 0; i < num_add; i++) {
//			total_add[i] += b;
//		}
//		if (c != 0) {
//			total_add[num_add - 1] += c;
//		}
//		output(str, n);
//
//	}
//
//	return 0;
//}

//重写思路
//#include <stdlib.h>
//#include <stdio.h>
//int add[1001], sup[1001];
//int main() {
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		int n,sum,m;
//		char s[1001] = "+";
//		scanf("%d %s", &n, s + 1);
//		sum = n * (n + 1) / 2;
//		if (sum & 1)puts("impossible");//if(sum % 2 != 0)
//		else {
//			sum >>= 1;//sum /= 2;
//			for (int i = m = 0; i < n; i++)m += s[i] == '+';
//			int min = m * (m + 1) / 2;
//			int max = (2 * n - m + 1) * m / 2;
//			if (sum<min || sum > max)puts("impossible");
//			else {
//				sum -= min;
//				int k = sum / m;
//				for (int i = 0; i < m;i++)add[i] = i + 1 + k;
//				k = sum % m;
//				for (int i = m - 1; k; k--, i--)add[i]++;
//				int j, temp;
//				for (temp = 0, j = 0, k = 0; j < m && k <= n; k++)
//					if (add[j] != k)sup[temp++] = k;
//					else j++;
//				while (k <= n)sup[temp++] = k++;
//				for (int i = 0, j = 0, k = 0; k < n; k++) {
//					if (s[k] == '+')printf("%d ", add[i++]);
//					else printf("%d ", sup[j++]);
//				}
//				putchar("\n");
//			}
//		}
//	}
//	return 0;
//}

//按照老师思路重写代码
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
//int total_add[1500];
//int num_add;
//
//static void output(char* control, int n) {
//    int len = strlen(control);
//    int total_sup[1500] = { 0 };
//    int temp_sup[1500] = { 0 };
//    int temp = 0;
//    for (int i = 0; i < num_add; i++) {
//        total_sup[total_add[i]] = 1;
//    }
//    for (int i = 1; i <= n; i++) {
//        if (total_sup[i] == 0)temp_sup[temp++] = i;
//    }
//    printf("%d", total_add[0]);
//    int index_add = 1, index_sup = 0;
//    for (int i = 0; i < len; i++) {
//        if (control[i] == '-') {
//            printf(" %d", temp_sup[index_sup++]);
//        }
//        else {
//            printf(" %d", total_add[index_add++]);
//        }
//    }
//    printf("\n");
//}
//
//void init(int* sup, int* add, char* str) {
//    int len = strlen(str);
//    (*sup) = 0;
//    (*add) = 1;
//    for (int i = 0; i < len; i++) {
//        if (str[i] == '-')(*sup)++;
//        else (*add)++;
//    }
//}
//
//int main() {
//    int T;
//    scanf("%d", &T);
//
//    while (T--) {
//        num_add = 0;
//        char str[1001];
//        int n;
//        scanf("%d", &n);
//        scanf("%s", str);
//
//        int add, sup;
//        init(&sup, &add, str);
//
//        long long sum = (long long)n * (n + 1) / 2;
//        if (sum % 2 != 0) {
//            printf("impossible\n");
//            continue;
//        }
//
//        sum /= 2;
//        int m = add;
//        long long min = (long long)m * (m + 1) / 2;
//        long long max = (long long)(2 * n - m + 1) * m / 2;
//
//        if (sum < min || sum > max) {
//            printf("impossible\n");
//            continue;
//        }
//
//        sum -= min;
//        int k = sum / m;
//        for (int i = 0; i < m; i++) {
//            total_add[num_add++] = i + 1 + k;
//        }
//        k = sum % m;
//        for (int i = m - 1; k > 0; k--, i--) {
//            total_add[i]++;
//        }
//
//        output(str, n);
//    }
//
//    return 0;
//}

//-------------------------------------------------
//问题 B: 删除

//#include <stdio.h>
//#include <stdlib.h>
//
//int compare(const void* a, const void* b) {
//	return *(long long*)a - *(long long*)b;
//}
//
//int main() {
//	int n, k;
//	scanf("%d %d", &n, &k);
//	long long* arr = (long long *)calloc(n, sizeof(long long));
//	for (int i = 0; i < n; i++)scanf("%lld", arr + i);
//	qsort(arr, n, sizeof(long long), compare);
//	int min = *(arr), max = *(arr + n - 1), left = 1,right = n - 2,num = n;
//	
//	while (1) {
//		if (abs(max - min) <= k || num == 1) {
//			puts("Yes");
//			break;
//		}
//		if (left > right || num == 2) {
//			puts("No");
//			break;
//		}
//		int temp_L = abs(arr[left] - min);
//		int temp_R = abs(max - arr[right]);
//		if (temp_L > k && temp_R > k) {
//			puts("No");
//			break;
//		}
//		if ((temp_L <= k && temp_R > k) || (temp_L <= k && temp_R <= k && temp_L >= temp_R)) {
//			min = (min + arr[left]) / 2;
//			left++;
//			num--;
//		}else if ((temp_R <= k && temp_L > k) || ((temp_R <= k && temp_L <= k && temp_R >= temp_L))) {
//			max = (max + arr[right]) / 2;
//			right--;
//			num--;
//		}
//		else {
//			puts("No");
//			break;
//		}
//	}
//	free(arr);
//	return 0;
//}

//修改
//原先代码在处理left == k与right == k时优先选择左，会出现问题

//#include <stdlib.h>
//#include <stdio.h>
//
//int compare(const void* a, const void* b) {
//	return *(int*)a - *(int*)b;
//}
//
//int main() {
//	int n, k;
//	scanf("%d %d", &n, &k);
//	int* arr = (int*)calloc(n, sizeof(int));
//	int* left = (int*)calloc(n, sizeof(int));
//	int* right = (int*)calloc(n, sizeof(int));
//	int index_left = 0;
//	int index_right = 0;
//	for (int i = 0; i < n; i++) scanf("%d", arr + i);
//	if (n == 1) {
//		puts("Yes");
//		return 0;
//	}
//	qsort(arr, n, sizeof(int), compare);
//	int temp = arr[0];
//	left[index_left++] = temp;
//	for (int i = 1; i < n; i++) {
//		int a = arr[i] - temp;
//		if (a > k)break;
//		else {
//			left[index_left++] = (arr[i] + temp) / 2;
//			temp = (arr[i] + temp) / 2;
//		}
//	}
//	temp = arr[n - 1];
//	right[index_right++] = temp;
//	for (int i = n - 2; i >= 0; i--) {
//		int a = a = temp - arr[i];
//		if (a > k)break;
//		else {
//			right[index_right++] = (arr[i] + temp) / 2;
//			temp = (arr[i] + temp) / 2;
//		}
//	}
//
//	//test
//	//puts("left : ");
//	//for (int i = 0; i < index_left; i++)printf("%d ", left[i]);
//	//printf("\n");
//	//puts("right : ");
//	//for (int i = 0; i < index_right; i++)printf("%d ", right[i]);
//	//printf("\n");
//	//test
//
//	int found = 0;
//	qsort(right, index_right, sizeof(int), compare);
//	for (int i = 0; i < index_left && i < index_right; i++) {
//		int a = abs(right[i] - left[i]);
//		if (a <= k)found = 1;
//	}
//	if (found)puts("Yes");
//	else puts("No");
//	free(arr);
//	free(left);
//	free(right);
//	return 0;
//}


//-------------------------------------------------
//问题 E: 菱形 II

//#include <stdlib.h>
//#include <stdio.h>
//
//typedef struct {
//	int n, line, p;
//}node;
//int main() {
//	int T;
//	scanf("%d", &T);
//
//	while (T--) {
//		int n;
//		node start, end;
//		scanf("%d %d %d", &n, &(start.n), &(end.n));
//		int found_start = 0,found_end = 0,temp = 0;
//		for (int i = 1; i <= n; i++) {
//			temp += i;
//			if (start.n <= temp) {
//				start.line = i;
//				start.p = start.n - (temp - i);
//				found_start++;
//			}
//			if (found_start) break;
//		}
//		temp = 0;
//		for (int i = 1; i <= n; i++) {
//			temp += i;
//			if (end.n <= temp) {
//				end.line = i;
//				found_end++;
//				end.p = end.n - (temp - i);
//			}
//			if (found_end) break;
//		}
//		// 修改点4：修正后半部分查找逻辑
//		if (!found_start) {
//			temp = n * (n + 1) / 2;
//			// 修改点5：正确计算后半部分每条反对角线的元素数量
//			for (int i = n + 1; i <= 2 * n - 1; i++) {
//				int elements_in_diag = 2 * n - i;  // 第i条反对角线的元素数量
//				if (start.n <= temp + elements_in_diag) {
//					start.line = i;
//					start.p = start.n - temp;  // 在当前反对角线内的位置
//					found_start = 1;
//					break;
//				}
//				temp += elements_in_diag;
//			}
//		}
//
//		// 修改点6：同样的逻辑应用于终点
//		if (!found_end) {
//			temp = n * (n + 1) / 2;
//			for (int i = n + 1; i <= 2 * n - 1; i++) {
//				int elements_in_diag = 2 * n - i;
//				if (end.n <= temp + elements_in_diag) {
//					end.line = i;
//					end.p = end.n - temp;
//					found_end = 1;
//					break;
//				}
//				temp += elements_in_diag;
//			}
//		}
//		int answer = 0;
//		if (abs(start.line - end.line) >= abs(start.p - end.p))answer = abs(start.line - end.line);
//		else answer = abs(start.line - end.line) + 2 * (abs(start.p - end.p) - abs(start.line - end.line));
//		printf("%d\n", answer);
//	}
//	return 0;
//}

//思路问题（把菱形旋转成为正方形）

//AI矩阵变换版本
//#include <stdio.h>
//#include <math.h>
//typedef struct {
//    int x, y, n;
//}node;
//void calculateCoordinates(int a, int n, int* i, int* j) {
//    // 计算前a条反对角线的数字总数
//    int total_first_half = a * (a + 1) / 2;
//
//    if (n <= total_first_half) {
//        // n在前a条反对角线内
//        // 计算反对角线索引k
//        int k = (int)ceil((-1 + sqrt(1 + 8 * n)) / 2);
//        // 计算在当前反对角线中的位置a_pos
//        int a_pos = n - k * (k - 1) / 2;
//        // 计算坐标
//        *i = k - a_pos + 1;
//        *j = a_pos;
//    }
//    else {
//        // n在后a-1条反对角线内
//        int C = n - total_first_half;
//
//        // 找到最小的m满足条件
//        int m;
//        for (m = 1; m <= a - 1; m++) {
//            int threshold = m * a - m * (m + 1) / 2;
//            if (threshold >= C) {
//                break;
//            }
//        }
//
//        // 计算a_pos
//        int prev_threshold = (m - 1) * a - (m - 1) * m / 2;
//        int a_pos = C - prev_threshold;
//        // 计算坐标
//        *i = a - a_pos + 1;
//        *j = m + a_pos;
//    }
//}
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        	int n;
//        	node start, end;
//        	scanf("%d %d %d", &n, &(start.n), &(end.n));
//            calculateCoordinates(n,start.n, &start.x, &start.y);
//            calculateCoordinates(n,end.n, &end.x, &end.y);
//            int answer = 0;
//            answer = abs(start.x - end.x) + abs(start.y - end.y);
//            printf("%d\n", answer);
//    }
//    return 0;
//}

//修改前面代码
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct {
//	int n, line, p, x, y;
//}node;
//int change(int n,node *item) {
//	if (item->n <= n * (n + 1) / 2) {
//		item->x = (item->line - item->p) + 1;
//		item->y = item->p;
//	}
//	else {
//		int h = item->line - n;
//		item->y = h + item->p;
//		item->x = n - item->p + 1;
//	}
//}
//int main() {
//	int T;
//	scanf("%d", &T);
//
//	while (T--) {
//		int n;
//		node start, end;
//		scanf("%d %d %d", &n, &(start.n), &(end.n));
//		int found_start = 0,found_end = 0,temp = 0;
//		for (int i = 1; i <= n; i++) {
//			temp += i;
//			if (start.n <= temp) {
//				start.line = i;
//				start.p = start.n - (temp - i);
//				found_start++;
//			}
//			if (found_start) break;
//		}
//		temp = 0;
//		for (int i = 1; i <= n; i++) {
//			temp += i;
//			if (end.n <= temp) {
//				end.line = i;
//				found_end++;
//				end.p = end.n - (temp - i);
//			}
//			if (found_end) break;
//		}
//		if (!found_start) {
//			temp = n * (n + 1) / 2;
//			for (int i = n + 1; i <= 2 * n - 1; i++) {
//				int elements_in_diag = 2 * n - i; 
//				if (start.n <= temp + elements_in_diag) {
//					start.line = i;
//					start.p = start.n - temp;
//					found_start = 1;
//					break;
//				}
//				temp += elements_in_diag;
//			}
//		}
//		if (!found_end) {
//			temp = n * (n + 1) / 2;
//			for (int i = n + 1; i <= 2 * n - 1; i++) {
//				int elements_in_diag = 2 * n - i;
//				if (end.n <= temp + elements_in_diag) {
//					end.line = i;
//					end.p = end.n - temp;
//					found_end = 1;
//					break;
//				}
//				temp += elements_in_diag;
//			}
//		}
//		change(n, &start);
//		change(n, &end);
//        int answer = abs(start.x - end.x) + abs(start.y - end.y);
//        printf("%d\n", answer);
//	}
//	return 0;
//}

//-------------------------------------------------
//问题 H: Markdown表格

//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//
//#define MAX_ROWS 12  // 行数不超过10，加上一些缓冲
//#define MAX_COLS 12  // 列数不超过10，加上一些缓冲
//#define MAX_LEN 210  // 每行字符串长度不超过200，加上一些缓冲
//// 对齐方式枚举
//typedef enum {
//    ALIGN_LEFT,
//    ALIGN_CENTER,
//    ALIGN_RIGHT
//} Alignment;
//// 函数声明
//void trim_whitespace(char* str);
//int split_columns(char* line, char columns[][MAX_LEN], int max_cols);
//void parse_alignment(char* align_str, Alignment* align);
//void calculate_col_widths(char columns[][MAX_LEN], int col_count, int* widths);
//void print_border(int* col_widths, int col_count);
//void print_row(char columns[][MAX_LEN], int col_count, int* col_widths, Alignment* alignments, int is_header);
//
//int main() {
//    char lines[MAX_ROWS][MAX_LEN];
//    int line_count = 0;
//
//    // 读取所有输入行
//    while (fgets(lines[line_count], MAX_LEN, stdin) != NULL) {
//        // 去除换行符
//        lines[line_count][strcspn(lines[line_count], "\n")] = '\0';
//        line_count++;
//        if (line_count >= MAX_ROWS) break;
//    }
//
//    // 解析表头
//    char header_cols[MAX_COLS][MAX_LEN];
//    int col_count = split_columns(lines[0], header_cols, MAX_COLS);
//
//    // 解析对齐方式
//    char align_strs[MAX_COLS][MAX_LEN];
//    split_columns(lines[1], align_strs, MAX_COLS);
//
//    Alignment alignments[MAX_COLS];
//    for (int i = 0; i < col_count; i++) {
//        parse_alignment(align_strs[i], &alignments[i]);
//    }
//
//    // 解析数据行
//    char data_rows[MAX_ROWS][MAX_COLS][MAX_LEN];
//    int data_row_count = line_count - 2;
//    for (int i = 0; i < data_row_count; i++) {
//        split_columns(lines[i + 2], data_rows[i], MAX_COLS);
//    }
//
//    // 计算列宽
//    int col_widths[MAX_COLS] = { 0 };
//
//    // 考虑表头
//    calculate_col_widths(header_cols, col_count, col_widths);
//
//    // 考虑数据行
//    for (int i = 0; i < data_row_count; i++) {
//        calculate_col_widths(data_rows[i], col_count, col_widths);
//    }
//
//    // 输出表格
//
//    // 上边界
//    print_border(col_widths, col_count);
//
//    // 表头行
//    print_row(header_cols, col_count, col_widths, alignments, 1);
//
//    // 表头下边界
//    print_border(col_widths, col_count);
//
//    // 数据行
//    for (int i = 0; i < data_row_count; i++) {
//        print_row(data_rows[i], col_count, col_widths, alignments, 0);
//    }
//
//    // 下边界
//    print_border(col_widths, col_count);
//
//    return 0;
//}
//// 去除字符串首尾空白字符
//void trim_whitespace(char* str) {
//    int len = strlen(str);
//    int start = 0, end = len - 1;
//
//    // 找到第一个非空白字符
//    while (start < len && isspace(str[start])) {
//        start++;
//    }
//
//    // 找到最后一个非空白字符
//    while (end >= 0 && isspace(str[end])) {
//        end--;
//    }
//
//    if (start > end) {
//        str[0] = '\0';
//        return;
//    }
//
//    // 移动字符
//    int new_len = end - start + 1;
//    for (int i = 0; i < new_len; i++) {
//        str[i] = str[start + i];
//    }
//    str[new_len] = '\0';
//}
//// 分割列
//int split_columns(char* line, char columns[][MAX_LEN], int max_cols) {
//    int col_count = 0;
//    char* token = strtok(line, "|");
//
//    while (token != NULL && col_count < max_cols) {
//        strcpy(columns[col_count], token);
//        trim_whitespace(columns[col_count]);
//        col_count++;
//        token = strtok(NULL, "|");
//    }
//
//    return col_count;
//}
//// 解析对齐方式
//void parse_alignment(char* align_str, Alignment* align) {
//    trim_whitespace(align_str);
//    int len = strlen(align_str);
//
//    int has_colon_left = 0;
//    int has_colon_right = 0;
//
//    for (int i = 0; i < len; i++) {
//        if (align_str[i] == ':') {
//            if (i == 0) has_colon_left = 1;
//            if (i == len - 1) has_colon_right = 1;
//        }
//    }
//
//    if ((!has_colon_left && !has_colon_right) || (has_colon_left && has_colon_right)) {
//        *align = ALIGN_CENTER;
//    }
//    else if (has_colon_left && !has_colon_right) {
//        *align = ALIGN_LEFT;
//    }
//    else {
//        *align = ALIGN_RIGHT;
//    }
//}
//// 计算列宽
//void calculate_col_widths(char columns[][MAX_LEN], int col_count, int* widths) {
//    for (int i = 0; i < col_count; i++) {
//        int len = strlen(columns[i]);
//        if (len + 2 > widths[i]) {
//            widths[i] = len + 2;
//        }
//    }
//}
//// 打印边框
//void print_border(int* col_widths, int col_count) {
//    printf("+");
//    for (int i = 0; i < col_count; i++) {
//        for (int j = 0; j < col_widths[i]; j++) {
//            printf("-");
//        }
//        printf("+");
//    }
//    printf("\n");
//}
//// 打印行
//void print_row(char columns[][MAX_LEN], int col_count, int* col_widths, Alignment* alignments, int is_header) {
//    printf("|");
//
//    for (int i = 0; i < col_count; i++) {
//        char* content = columns[i];
//        int content_len = strlen(content);
//        int total_width = col_widths[i];
//        int padding = total_width - content_len;
//
//        Alignment align = is_header ? ALIGN_CENTER : alignments[i];
//
//        int left_padding, right_padding;
//
//        switch (align) {
//        case ALIGN_LEFT:
//            left_padding = 1;
//            right_padding = padding - left_padding;
//            break;
//
//        case ALIGN_RIGHT:
//            right_padding = 1;
//            left_padding = padding - right_padding;
//            break;
//
//        case ALIGN_CENTER:
//            left_padding = padding / 2;
//            right_padding = padding - left_padding;
//            // 确保左边空格数小于等于右边
//            if (left_padding > right_padding) {
//                int temp = left_padding;
//                left_padding = right_padding;
//                right_padding = temp;
//            }
//            break;
//        }
//
//        // 输出左边空格
//        for (int j = 0; j < left_padding; j++) {
//            printf(" ");
//        }
//
//        // 输出内容
//        printf("%s", content);
//
//        // 输出右边空格
//        for (int j = 0; j < right_padding; j++) {
//            printf(" ");
//        }
//
//        printf("|");
//    }
//
//    printf("\n");
//}

//-------------------------------------------------
//问题 G: 回文串

//#include <stdio.h>
//#include <string.h>
//#include <stdbool.h>
//bool Init(char* str) {
//    int len = strlen(str);
//    int bucket[26] = { 0 }, total = 0;
//    for (int i = 0; i < len; i++) bucket[str[i] - 'a']++;
//    for (int i = 0; i < 26; i++) if (bucket[i] & 1) total++;
//    return len & 1 ? total == 1 : total == 0;
//}
//bool Palindrome(char* str, int left, int right) {
//    for (int i = left, j = right; i < j; i++, j--)
//        if (str[i] != str[j]) return false;
//    return true;
//}
//bool Same(char* str, int left, int right, int len) {
//    for (int i = 0; i < len; i++)
//        if (str[left + i] != str[right + i]) return false;
//    return true;
//}
//bool Same_C(char* str, int left, int right, int len) {
//    for (int i = 0; i < len; i++)
//        if (str[left + i] != str[right - len + 1 + i]) return false;
//    return true;
//}
//void Reserve(char* str) {
//    int left = 0;
//    int right = strlen(str) - 1;
//    while (left < right) {
//        char temp = str[left];
//        str[left] = str[right];
//        str[right] = temp;
//        left++;
//        right--;
//    }
//}
//bool Process(char* str) {
//    int len = strlen(str);
//    for (int i = 1; i <= len / 2; i++) {
//        if (Same(str, 0, i, i)) {
//            if (Palindrome(str, i * 2, len - 1)) return true;
//        }
//    }
//    return false;
//}
//bool Process_C(char* str) {
//    int len = strlen(str);
//    for (int i = 1; i <= len / 2; i++) {
//        if (Same_C(str, 0, len - 1, i)) {
//            if (Palindrome(str, i, len - 1 - i)) return true;
//        }
//    }
//    return false;
//}
//bool Palindrome_Init(char* str) {
//    int len = strlen(str);
//    int ret = true,index = 0;
//    for (int i = 0, j = len - 1; i < j; i++, j--)
//    {
//        if (str[i] != str[j]) {
//            ret = false;
//            index = i;
//            break;
//        }
//    }
//    if (!ret) {
//        int temp = 0;
//        for (int i = index; i < len - index; i++) {
//            str[temp++] = str[i];
//        }
//        str[temp] = '\0';
//    }
//    return ret;
//}
//int main() {
//    char str[10001]; 
//    while (scanf("%s", str) != EOF) {
//        if (!Init(str)) {
//            puts("No");
//            continue;
//        }
//
//        if (Palindrome_Init(str)) {
//            puts("Yes");
//            continue;
//        }
//        if (Process_C(str)) {
//            puts("Yes");
//            continue;
//        }
//        if (Process(str)) {
//            puts("Yes");
//            continue;
//        }
//        Reserve(str);
//        if (Process(str)) {
//            puts("Yes");
//            continue;
//        }
//        puts("No");
//    }
//    return 0;
//}

//-------------------------------------------------
//问题 C : 大佬，带带我

//#include <stdlib.h>
//#include <stdio.h>
//
//typedef struct {
//	int id;
//	int value;
//}character;
//
//int compare_c(const void* a, const void* b) {
//	return ((character*)a)->value - ((character*)b)->value;
//}
//
//int read() {
//	int x = 0;
//	char c;
//	c = getchar();
//	while (c <= '9' && c >= '0') {
//		x = x * 10 + (c - '0');
//		c = getchar();
//	}
//	return x;
//}
//int main() {
//	int change[10001] = { 0 };
//	int total[10001] = { 0 };
//	int n, m;
//	n = read();
//	m = read();
//	character *arr = (character*)malloc(sizeof(character) * n);
//	for (int i = 0; i < n; i++) {
//		arr[i].id = i;
//		arr[i].value = read();
//	}
//	qsort(arr, n, sizeof(character), compare_c);
//	for (int i = 0; i < n; i++) change[arr[i].id] = i;
//	total[0] = 0;
//	for (int i = 1; i < n; i++) {
//		if (arr[i].value > arr[i - 1].value)total[i] = i;
//		else total[i] = total[i - 1];
//	}
//
//	printf("%d", total[change[0]]);
//	for (int i = 1; i < n; i++) {
//		printf(" %d", total[change[i]]);
//	}
//	printf("\n---------\n");
//	for (int i = 0; i < m; i++) {
//		int persion = read();
//		int num = read();
//		for (int j = 0; j < num; j++) {
//			int heat = read();
//			int heat_level = arr[change[heat - 1]].value;
//			int persion_level = arr[change[persion - 1]].value;
//			if (persion_level > heat_level) {
//				total[change[persion - 1]]--;
//			}else if (persion_level <heat_level) {
//				total[change[heat - 1]]--;
//			}
//		}
//	}
//
//	printf("%d", total[change[0]]);
//	for (int i = 1; i < n; i++) {
//		printf(" %d", total[change[i]]);
//	}
//	free(arr);
//	return 0;
//}	
//主要问题，在重复的选择过程中会重复减去，需要数组记录大小

//修改，使用二维数组，内存太大，用邻接表优化，题目给出大小不超过100000
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Node {
//    int person;
//    struct Node* next;
//} Node;
//
//int main() {
//    int n, m;
//    scanf("%d %d", &n, &m);
//
//    int* ability = (int*)malloc(n * sizeof(int));
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &ability[i]);
//    }
//    Node** dislike = (Node**)malloc(n * sizeof(Node*));
//    for (int i = 0; i < n; i++) {
//        dislike[i] = NULL;
//    }
//    for (int i = 0; i < m; i++) {
//        int person, k;
//        scanf("%d %d", &person, &k);
//        person--;
//        for (int j = 0; j < k; j++) {
//            int disliked_person;
//            scanf("%d", &disliked_person);
//            disliked_person--;
//            Node* new_node = (Node*)malloc(sizeof(Node));
//            new_node->person = disliked_person;
//            new_node->next = dislike[person];
//            dislike[person] = new_node;
//        }
//    }
//    int* result = (int*)calloc(n, sizeof(int));
//    int** dislike_lookup = (int**)malloc(n * sizeof(int*));
//    for (int i = 0; i < n; i++) {
//        dislike_lookup[i] = (int*)calloc(n, sizeof(int));
//        Node* current = dislike[i];
//        while (current != NULL) {
//            dislike_lookup[i][current->person] = 1;
//            current = current->next;
//        }
//    }
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            if (i == j) continue;
//            if (ability[i] > ability[j] &&         
//                dislike_lookup[i][j] == 0 &&         
//                dislike_lookup[j][i] == 0) {      
//                result[i]++;
//            }
//        }
//    }
//    for (int i = 0; i < n; i++) {
//        printf("%d", result[i]);
//        if (i < n - 1) {
//            printf(" ");
//        }
//    }
//    printf("\n");
//    free(ability);
//    free(result);
//    for (int i = 0; i < n; i++) {
//        Node* current = dislike[i];
//        while (current != NULL) {
//            Node* temp = current;
//            current = current->next;
//            free(temp);
//        }
//        free(dislike_lookup[i]);
//    }
//    free(dislike);
//    free(dislike_lookup);
//
//    return 0;
//}

//位图优化
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//// 快速读取函数
//int read_int() {
//    int x = 0;
//    char c = getchar();
//    while (c < '0' || c > '9') {
//        c = getchar();
//    }
//    while (c >= '0' && c <= '9') {
//        x = x * 10 + (c - '0');
//        c = getchar();
//    }
//    return x;
//}
//
//int main() {
//    int n, m;
//    n = read_int();
//    m = read_int();
//
//    int* ability = (int*)malloc(n * sizeof(int));
//    for (int i = 0; i < n; i++) {
//        ability[i] = read_int();
//    }
//
//    // 使用位图存储
//    int bitmap_size = (n + 31) / 32;
//    unsigned int** dislike = (unsigned int**)malloc(n * sizeof(unsigned int*));
//    for (int i = 0; i < n; i++) {
//        dislike[i] = (unsigned int*)calloc(bitmap_size, sizeof(unsigned int));
//    }
//
//    for (int i = 0; i < m; i++) {
//        int person, k;
//        person = read_int();
//        k = read_int();
//        person--;
//
//        for (int j = 0; j < k; j++) {
//            int disliked_person;
//            disliked_person = read_int();
//            disliked_person--;
//
//            // 设置位图中的对应位
//            int idx = disliked_person / 32;
//            int bit = disliked_person % 32;
//            dislike[person][idx] |= (1u << bit);
//        }
//    }
//
//    int* result = (int*)calloc(n, sizeof(int));
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            if (i == j) continue;
//
//            if (ability[i] > ability[j]) {
//                int idx_j = j / 32;
//                int bit_j = j % 32;
//                int idx_i = i / 32;
//                int bit_i = i % 32;
//                bool i_dislikes_j = (dislike[i][idx_j] & (1u << bit_j)) != 0;
//                bool j_dislikes_i = (dislike[j][idx_i] & (1u << bit_i)) != 0;
//
//                if (!i_dislikes_j && !j_dislikes_i) {
//                    result[i]++;
//                }
//            }
//        }
//    }
//
//    for (int i = 0; i < n; i++) {
//        printf("%d", result[i]);
//        if (i < n - 1) {
//            printf(" ");
//        }
//    }
//    printf("\n");
//
//    // 释放内存
//    free(ability);
//    free(result);
//    for (int i = 0; i < n; i++) {
//        free(dislike[i]);
//    }
//    free(dislike);
//
//    return 0;
//}


//#include <stdlib.h>
//#include <stdio.h>
//
//typedef struct {
//    int id;
//    int value;
//}character;
//
//typedef struct {
//    int persion;
//    int heat;
//}node;
//
//
//typedef  struct node{
//    int persion;
//    int heat;
//    node* next;
//}node;
//
//typedef struct{
//    node* bucket;
//}item;
//
//item* createlist() {
//    item* list = (item*)malloc(sizeof(item));
//    list->bucket = NULL;
//    return list;
//}
//
//void insertlist(item* list,int persion,int heat) {
//    node* a = (node*)malloc(sizeof(node));
//    a->next = list->bucket;
//    a->persion = persion;
//    a->heat = heat;
//}
//
//void uniquelist(item* list) {
//
//}
//
//
//node hm[2000010];
//int change[10001];
//int total[10001];
//int temp[10001];
//int compare_c(const void* a, const void* b) {
//    return ((character*)a)->value - ((character*)b)->value;
//}
//
//int compare_hm(const void* a, const void* b) {
//    const node* row1 = (const node*)a;
//    const node* row2 = (const node*)b;
//    return row1->persion - row2->persion;
//}
//
//int read() {
//    int x = 0;
//    char c;
//    c = getchar();
//    while (c <= '9' && c >= '0') {
//        x = x * 10 + (c - '0');
//        c = getchar();
//    }
//    return x;
//}
//
//int main() {
//    int n, m;
//    n = read();
//    m = read();
//    character* arr = (character*)malloc(sizeof(character) * n);
//    for (int i = 0; i < n; i++) {
//        arr[i].id = i;
//        arr[i].value = read();
//    }
//    qsort(arr, n, sizeof(character), compare_c);
//    for (int i = 0; i < n; i++) change[arr[i].id] = i;
//
//
//    for (int i = 1; i < n; i++) {
//        if (arr[i].value > arr[i - 1].value)total[i] = i;
//        else total[i] = total[i - 1];
//    }
//
//
//    int heatIndex = 0;
//
//    for (int i = 0; i < m; i++) {
//        int persion = read();
//        int num = read();
//        for (int j = 0; j < num; j++) {
//            int heat = read();
//            hm[heatIndex].persion = persion - 1;
//            hm[heatIndex].heat = heat - 1;
//            heatIndex++;
//            hm[heatIndex].heat = persion - 1;
//            hm[heatIndex].persion = heat - 1;
//            heatIndex++;
//        }
//    }
//
//    //去重
//    qsort(hm, heatIndex, sizeof(node), compare_hm);
//    int index = 0;
//    for (int j = 0; j < n; j++) {
//        for (int i = 0; i < 10001; i++)temp[i] = 0;
//        for (int i = index; i < heatIndex; i++) {
//            if (hm[i].persion != j) {
//                index = i;
//                break;
//            }
//            if (temp[hm[i].heat] == 0) {
//                temp[hm[i].heat] = 1;
//                if (arr[change[hm[i].heat]].value < arr[change[hm[i].persion]].value) {
//                    total[change[hm[i].persion]]--;
//                }
//            }
//        }
//    }
//    printf("%d", total[change[0]]);
//    for (int i = 1; i < n; i++) {
//        printf(" %d", total[change[i]]);
//    }
//    free(arr);
//    return 0;
//}

//-------------------------------------------------
//问题 D : 吃饱了才有力气减肥

//#include <stdlib.h>
//#include <stdio.h>
//void swap(int* a, int* b) {
//	int c = *b;
//	*b = *a;
//	*a = c;
//}
//int max_temp(int *arr,int size) {
//	int max_num = -100;
//	int postion = 0;
//	int range = 0;
//	int total = 0;
//	for (int i = size - 1; i >= 0; i--) {
//		total += arr[i];
//		if (total < 0) {
//			range = i;
//			break;
//		}
//	}
//	for (int i = range; i < size; i++) {
//		if (arr[i] > max_num) { 
//			max_num = arr[i];
//			postion = i;
//		}
//	}
//	if (max_num < 0)return 0;
//	swap(arr, arr + postion);
//	return 1;
//}
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	int* arr = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++)scanf("%d", arr + i);
//	if (n == 1) {
//		if (arr[0] < 0) {
//			puts("No");
//		}
//		else {
//			puts("Yes");
//		}
//		return 0;
//	}
//	int total = 0,index = 0;
//
//	for (int i = 0; i < n; i++) {
//		total += arr[i];
//		if (total < 0) {
//			index = i;
//			total -= arr[i];
//			if (!max_temp(arr + i, n - i)) {
//				puts("No\n");
//				return 0;
//			}
//			else break;
//		}
//	}
//	for (int i = index; i < n; i++) {
//		total += arr[i];
//		if (total < 0) {
//			index = i;
//			puts("No\n");
//			return 0;
//		}
//	}
//	puts("Yes\n");
//	free(arr);
//	return 0;
//}

//#include <stdio.h>
//void swap(int* a, int* b) {
//	int c = *b;
//	*b = *a;
//	*a = c;
//}
//int main() {
//	int t;
//	scanf("%d", &t);
//	if (t == 1) {
//		int temp;
//		scanf("%d", &temp);
//		if (temp >= 0)puts("Yes");
//		else puts("No");
//		return 0;
//	}
//	int arr[100001];
//	int p_f = -1, p_b = 0;
//	long long pre = 0;
//	for (int i = 0; i < t; i++)scanf("%d", arr + i);
//	for (int i = 0; i < t; i++) {
//		pre += arr[i];
//		if (pre < 0) {
//			p_f = i;
//			break;
//		}
//	}
//	if (p_f == -1) {
//		puts("Yes");
//		return 0;
//	}
//	pre = 0;
//	for (int i = t - 1; i >= 0; i--) {
//		pre += arr[i];
//		if (pre < 0 || i == 0) {
//			p_b = i;
//			break;
//		}
//	}
//	int c_f = 0, c_b = 0;
//	int temp = 100000000;
//	for (int i = p_f; i >= 0; i--) {
//		if (temp > arr[i]) {
//			temp = arr[i];
//			c_f = i;
//		}
//	}
//	temp = -100000000;
//	for (int i = t; i >= p_b && i > p_f; i--) {
//		if (temp < arr[i]) {
//			temp = arr[i];
//			c_b = i;
//		}
//	}
//	swap(&arr[c_f], &arr[c_b]);
//	pre = 0;
//	for (int i = 0; i < t; i++) {
//		pre += arr[i];
//		if (pre < 0) {
//			puts("No");
//			return 0;
//		}
//	}
//	puts("Yes");
//	return 0;
//}