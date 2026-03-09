//Contest1075 - 2025年C语言入队习题-0x14（递归）
#define _CRT_SECURE_NO_WARNINGS
//问题 A: 中位数
//#include <stdlib.h>
//#include <stdio.h>
//
//int compare(const void* a, const void* b) {
//	return *(int*)a - *(int*)b;
//}
//int process(int n, int *arr, int left,int right) {
//	int num = right - left + 1;
//	if (num == 1) {
//		return n * arr[left];
//	}else if (num < 1) {
//		return 0;
//	}
//
//	int* py = (int*)calloc(num, sizeof(int));
//	
//	for (int i = left; i < left + num; i++) {
//		py[i - left] = arr[i];
//	}
//
//	qsort(py, num, sizeof(int), compare);
//
//	int min;
//	min = num / 2;
//	int m = py[min];
//	int location;
//	free(py);
//
//	for (location = left; location < left + num; location++) {
//		if (arr[location] == m)break;
//	}
//	
//	int result = n * m + process(n + 1, arr, left, location - 1) + process(n + 1, arr, location + 1, right);
//	
//	return result;
//}
//int main() {
//	int T;
//	if (scanf("%d", &T) != 1)return 0;
//	while (T--) {
//		int n;
//		if (scanf("%d", &n) != 1)return 0;
//
//		int* arr = (int*)calloc(n, sizeof(int));
//
//		for (int i = 0; i < n; i++) {
//			if (scanf("%d", arr + i) != 1)return 0;
//		}
//		
//		int result = process(1, arr, 0, n - 1);
//
//		printf("%d\n", result);
//		free(arr);
//	}
//	return 0;
//}

//-------------------------------------------------------------
//问题 B: 图像
//1  2  5  6
//3  4  7  8
//9 10 13 14
//11 12 15 16
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//typedef struct {
//	unsigned long long x, y;
//}vector;
//void process(vector *location, unsigned long long *pre, unsigned long long k) {
//	int index;
//	if (k == 1) {
//		location->x += 1;
//		location->y += 1;
//		return;
//	}
//	for (index = 0; index < 31; index++) {
//		if (pre[index] >= k) break;
//	}
//	int block;
//	unsigned long long quarter = pre[index - 1];
//	unsigned long long square = (unsigned long long)sqrt(pre[index - 1]);
//	if (k <= quarter) {
//		block = 1;
//	}else if (k <= 2 * quarter) {
//		location->x += square;
//		block = 2;
//	}
//	else if (k <= 3 * quarter) {
//		location->y += square;
//		block = 3;
//	}
//	else {
//		location->x += square;
//		location->y += square;
//		block = 4;
//	}
//	k = k - (block - 1) * pre[index - 1];
//	process(location, pre, k);
//}
//int main() {
//	unsigned long long pre[31] = { 0 };
//	pre[0] = 1;
//	for (int i = 1; i < 31; i++) {
//		pre[i] = 4 * pre[i - 1];
//	}
//
//	int T;
//	scanf("%d", &T);
//
//	while (T--) {
//		unsigned long long k;
//		scanf("%llu", &k);
//		if (k == 1) {
//			printf("1 1\n");
//			continue;
//		}
//		vector location;
//		location.x = 0;
//		location.y = 0;
//		process(&location, pre, k);
//		printf("%llu %llu\n", location.y, location.x);
//	}
//
//	return 0;
//}

//--------------------------------------------------------
//问题 C: 同构字符串
//#include <stdio.h>
//#include <string.h>
//
//int process(char* str1, char* str2) {
//	int len1 = strlen(str1);
//	char str1L[1025], str1R[1025], str2L[1025], str2R[1025];
//	if (strcmp(str1, str2) == 0) {
//		return 1;
//	}
//	if (len1 % 2 != 0) {
//		return 0;
//	}
//	int min = len1 / 2;
//	for (int i = 0; i < min; i++) {
//		str1L[i] = str1[i];
//		str2L[i] = str2[i];
//	}
//	str1L[min] = '\0';
//	str2L[min] = '\0';
//
//	for (int i = 0; i < min; i++) {
//		str1R[i] = str1[i + min];
//		str2R[i] = str2[i + min];
//	}
//	str1R[min] = '\0';
//	str2R[min] = '\0';
//
//	if ((process(str1L, str2L) && process(str1R, str2R)) || (process(str1L, str2R) && process(str1R, str2L))) {
//		return 1;
//	}
//}
//
//int main() {
//	char str1[1050], str2[1050];
//
//	while (scanf("%s %s", str1, str2) != EOF) {
//		if (strcmp(str1, str2) == 0) {
//			printf("Yes\n");
//			continue;
//		}
//
//		int len1 = strlen(str1);
//		int len2 = strlen(str2);
//
//		if (len1 != len2) {
//			printf("No\n");
//			continue;
//		}
//		if (len1 % 2 != 0) {
//			printf("No\n");
//			continue;
//		}
//		if (process(str1, str2)) {
//			printf("Yes\n");
//		}
//		else {
//			printf("No\n");
//		}
//	}
//	return 0;
//}

//--------------------------------------------------
//问题 D: 分割
//#include <stdio.h>
//#include <stdlib.h>
//#define MOD 1000000007
//long long process(int* arr, int left, int right) {
//	long long result;
//	int num = right - left + 1;
//	if (num == 1) {
//		result = arr[left] % MOD;
//		return arr[left] % MOD;
//	}
//	if (num % 2 == 0) {
//		int min = left + num / 2;
//		long long L = process(arr, left, min - 1) % MOD;
//		long long R = process(arr, min, right) % MOD;
//		result = (L * R) % MOD;
//		return result;
//	}
//	else {
//		int min = left + (num - 1) / 2;
//		long long L = process(arr, left, min - 1) % MOD;
//		long long R = process(arr, min + 1, right) % MOD;
//		result = ((llabs(L + R) * llabs(L - R)) % MOD * arr[min] % MOD) % MOD;
//		return result;
//	}
//}
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	
//	int *arr = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", arr + i);
//	}
//	long long result = process(arr, 0, n - 1);
//	printf("%lld", result);
//
//	free(arr);
//	return 0;
//}

//----------------------------------------------------------
//问题 E: 通配符
//#include <stdio.h>
//#include <string.h>
//
//int memo[100][100];
//int process(char *base,char *str,int index_base,int index_str) {
//	int len_base = strlen(base);
//	int len_str = strlen(str);
//
//	if (memo[index_base][index_str] != -1) {
//		return memo[index_base][index_str];
//	}
//	if (index_str == len_str && index_base == len_base) {
//		return memo[index_base][index_str] = 1;
//	}
//	if (index_str == len_str) {
//		for (int i = index_base; i < len_base; i++) {
//			if (base[i] != '*') return memo[index_base][index_str] = 0;
//		}
//		return memo[index_base][index_str] = 1;
//	}
//	if (index_base == len_base) {
//		return memo[index_base][index_str] = 0;
//	}
//
//	if (base[index_base] == '_') {
//		return memo[index_base][index_str] = process(base, str, index_base + 1, index_str + 1);
//	}
//	if (base[index_base] == '*') {
//		return memo[index_base][index_str] = process(base, str, index_base + 1, index_str) || process(base, str, index_base, index_str + 1);
//	}
//	if (base[index_base] == str[index_str]) {
//		return memo[index_base][index_str] = process(base, str, index_base + 1, index_str + 1);
//	}
//	else {
//		return memo[index_base][index_str] = 0;
//	}
//	return memo[index_base][index_str] = 0;
//}
//
//int main() {
//	int s;
//	scanf("%d", &s);
//	
//	while (s--) {
//		char base[100];
//		scanf("%s", base);
//		int n;
//		scanf("%d", &n);
//		int total = 0;
//		while (n--) {
//			char str[100];
//			scanf("%s", str);
//			for (int i = 0; i < 100; i++) {
//				for (int j = 0; j < 100; j++) {
//					memo[i][j] = -1;
//				}
//			}
//			if (process(base, str, 0, 0)) {
//				total++;
//				printf("%s\n", str);
//			}
//		}
//		printf("%d\n", total);
//	}
//
//	return 0;
//}

//-----------------------------------------------
//问题 F: 汉诺塔 II
//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int s;
//	scanf("%d", &s);
//
//	while (s--) {
//		int n;
//		scanf("%s", &n);
//
//		int arr
//	}
//	return 0;
//}

//-----------------------------------------------
//问题 G: 幂
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//unsigned long long process(char str[101]) {
//	int len = strlen(str);
//	
//	if (len == 6) { // "(x)(y)\0"
//		if (str[0] == '(' && str[2] == ')' && str[3] == '(' && str[5] == ')') {
//			unsigned long long n = str[1] - '0' + str[4] - '0';
//			return n * n;
//		}
//	}
//	if (len == 3) { // "(x)\0"
//		if (str[0] == '(' && str[2] == ')') {
//			unsigned long long n = str[1] - '0';
//			return n * n;
//		}
//	}
//
//	char str_new[101];
//	int totalL = 0, totalR = 0,total = 0;
//	for (int i = 0; i < len; i++) {
//		if (str[i] == '(')totalL++;
//		if (str[i] == ')')totalR++;
//		if (totalL == totalR && totalL != 0) {
//			total++;
//		}
//	}
//	totalL = 0;
//	totalR = 0;
//	int index = 0;
//	int total_num = 0;
//	unsigned long long answer = 1;
//	for (int i = 0; i < len; i++) {
//		if (str[i] <= '9' && str[i] >= '0') {
//			total_num++;
//		}
//	}
//	if (total_num == 1) {
//		for (int i = 1; i < len - 1; i++) {
//			str_new[index++] = str[i];
//		}
//		str_new[index] = '\0';
//		answer = process(str_new);
//		return answer * answer;
//	}
//
//	for (int i = 0; i < len; i++) {
//		if (str[i] == '(')totalL++;
//		if (str[i] == ')')totalR++;
//		str_new[index++] = str[i];
//		if (totalL == totalR && totalL != 0) {
//			str_new[index] = '\0';
//			unsigned long long temp = process(str_new);
//			answer *= (temp * temp);
//		}
//		index = 0;
//	}
//	return answer;
//}
//
//int main() {
//	char str[101];
//	while (scanf("%s", str) != EOF) {
//		unsigned long long result = process(str);
//		printf("%llu\n", result);
//	}
//	printf("TEST");
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//
//long long parse_expression(const char* s, int* index);
//
//// 解析一个因子（括号内的表达式）
//long long parse_factor(const char* s, int* index) {
//    if (s[*index] == '(') {
//        (*index)++; // 跳过 '('
//        long long value = parse_expression(s, index);
//        if (s[*index] == ')') {
//            (*index)++; // 跳过 ')'
//        }
//        return value * value; // 规则2：对表达式值平方
//    }
//    return 0;
//}
//
//// 解析整个表达式（可能由多个因子组成）
//long long parse_expression(const char* s, int* index) {
//    long long sum = 0;
//
//    while (s[*index] && s[*index] != ')') {
//        if (s[*index] == '(') {
//            // 解析因子并累加
//            long long factor_value = parse_factor(s, index);
//            sum += factor_value;
//        }
//        else if (isdigit(s[*index])) {
//            // 数字字符，直接计算其平方值
//            int digit = s[*index] - '0';
//            (*index)++;
//            sum += digit * digit; // 规则1：数字的平方
//        }
//        else {
//            // 跳过其他字符（理论上不会出现）
//            (*index)++;
//        }
//    }
//
//    return sum * sum; // 规则3：对累加和平方
//}
//
//int main() {
//    char line[105];
//
//    while (fgets(line, sizeof(line), stdin)) {
//        // 移除换行符
//        line[strcspn(line, "\n")] = 0;
//
//        if (strlen(line) == 0) continue;
//
//        int index = 0;
//        long long result = parse_expression(line, &index);
//        printf("%lld\n", result);
//    }
//
//    return 0;
//}

//修正

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//#define R 101
//
////int countLen(char* str,int len) {
////	int left = 0;
////	int right = 0;
////	int count = 0;
////	for (int i = 0; i < len; i++) {
////		if (str[i] == '(') {
////			left++;
////		}
////		else if (str[i] == ')') {
////			right++;
////		}
////		if (right == left) {
////			count++;
////		}
////	}
////	return count;
////}
//
//void deleteStr(char* str) {
//	int len = strlen(str);
//	int index = 0;
//	for (int i = 1; i < len - 1; i++) {
//		str[index++] = str[i];
//	}
//	str[index] = '\0';
//}
//
//unsigned long long process(char* str) {
//	int len = strlen(str);
//	
//	if (len == 1) {
//		return str[0] - '0';
//	}
//
////	int count = countLen(str, len);
//	char str_new[R];
//	int index = 0;
//	int left = 0, right = 0;
//	unsigned long long result = 0;
////	if (count == 2) {
////		for (int i = 0; i < len; i++) {
////			str_new[index++] = str[i];
////			if (str[i] == '(')left++;
////			else if (str[i] == ')')right++;
////			
////			if (left == right)break;
////		}
////		str_new[index] = '\0';
////		deleteStr(str_new);
////		unsigned long long result1 = process(str_new);
//////		printf("%s\n", str_new);
////
////		int location = strlen(str_new) + 2;
////		index = 0;
////		for (; location <= len; location++) {
////			str_new[index++] = str[location];
////		}
////		deleteStr(str_new);
//////		printf("%s\n", str_new);
////		unsigned long long result2 = process(str_new);
////		result = (result1 + result2) * (result1 + result2);
////	}
////	else {
//		for (int i = 0; i < len; i++) {
//			str_new[index++] = str[i];
//			if (str[i] == '(')left++;
//			else if (str[i] == ')')right++;
//
//			if (left == right) {
//				str_new[index] = '\0';
//				deleteStr(str_new);
//				unsigned long long result1 = process(str_new);
//				result += result1;
//				index = 0;
//			}
//		}
//		//printf("result : %lld\n", result);
//		result *= result;
////	}
//
////	printf("count : %d\n", count);//test
//	return result;
//}

//int main() {
//	char str[R];
//	while (scanf("%s", str) != EOF) {
//		printf("%llu\n", process(str));
//	}
//	return 0;
//}

//------------------------------------------------
// 问题 H: Black White Chess
//#include <stdio.h>
//#include <stdbool.h>
//#define Range 66540
//short memo[Range];
//#include <string.h>
//
//short end;
//int find(short find_num,int index){
//      if(memo[find_num] == 1){
//              return 1;
//      }
//      return 0;
//}
//
//short change_low(short num,int n){//-
//      switch (n) {
//              case 1:
//                      num ^= (1 << 0);
//                      num ^= (1 << 1);
//                      num ^= (1 << 2);
//                      num ^= (1 << 3);
//                      break;
//              case 2:
//                      num ^= (1 << 4);
//                      num ^= (1 << 5);
//                      num ^= (1 << 6);
//                      num ^= (1 << 7);
//                      break;
//              case 3:
//                      num ^= (1 << 8);
//                      num ^= (1 << 9);
//                      num ^= (1 << 10);
//                      num ^= (1 << 11);                       
//                      break;
//              case 4:
//                      num ^= (1 << 12);
//                      num ^= (1 << 13);
//                      num ^= (1 << 14);
//                      num ^= (1 << 15);
//                      break;
//      }
//      return num;
//}
//
//short change_line(short num,int n){//|
//      switch (n) {
//              case 1:
//                      num ^= (1 << 0);
//                      num ^= (1 << 4);
//                      num ^= (1 << 8);
//                      num ^= (1 << 12);
//                      break;
//              case 2:
//                      num ^= (1 << 1);
//                      num ^= (1 << 5);
//                      num ^= (1 << 9);
//                      num ^= (1 << 13);
//                      break;
//              case 3:
//                      num ^= (1 << 2);
//                      num ^= (1 << 6);
//                      num ^= (1 << 10);
//                      num ^= (1 << 14);                       
//                      break;
//              case 4:
//                      num ^= (1 << 3);
//                      num ^= (1 << 7);
//                      num ^= (1 << 11);
//                      num ^= (1 << 15);
//                      break;
//      }       
//      return num;
//}
//
//short change_c(short num,int n){//田
//      switch (n) {
//              case 1:
//                      num ^= (1 << 0);
//                      num ^= (1 << 1);
//                      num ^= (1 << 4);
//                      num ^= (1 << 5);
//                      break;
//              case 2:
//                      num ^= (1 << 2);
//                      num ^= (1 << 3);
//                      num ^= (1 << 6);
//                      num ^= (1 << 7);
//                      break;
//              case 3:
//                      num ^= (1 << 8);
//                      num ^= (1 << 9);
//                      num ^= (1 << 12);
//                      num ^= (1 << 13);
//                      break;
//              case 4:
//                      num ^= (1 << 10);
//                      num ^= (1 << 11);
//                      num ^= (1 << 14);
//                      num ^= (1 << 15);
//                      break;
//              case 5:
//                      num ^= (1 << 1);
//                      num ^= (1 << 2);
//                      num ^= (1 << 5);
//                      num ^= (1 << 6);
//                      break;
//              case 6:
//                      num ^= (1 << 6);
//                      num ^= (1 << 7);
//                      num ^= (1 << 10);
//                      num ^= (1 << 11);
//                      break;  
//              case 7:
//                      num ^= (1 << 9);
//                      num ^= (1 << 10);
//                      num ^= (1 << 13);
//                      num ^= (1 << 14);
//                      break;
//              case 8:
//                      num ^= (1 << 4);
//                      num ^= (1 << 5);
//                      num ^= (1 << 8);
//                      num ^= (1 << 9);
//                      break;
//              case 9:
//                      num ^= (1 << 5);
//                      num ^= (1 << 6);
//                      num ^= (1 << 9);
//                      num ^= (1 << 10);
//                      break;                  
//      }
//      return num;
//}
//
//int process(short start,int index){
//      if(find(start,index))return 0;
//      
//      if(start == end)return 1;
//      
//      memo[start] = 1;
//      
//      int result_line = process(change_line(start,1),index) || process(change_line(start,2),index) || process(change_line(start,3),index) || process(change_line(start,4),index);
//      int result_low = process(change_low(start,1),index) || process(change_low(start,2),index) || process(change_low(start,3),index) || process(change_low(start,4),index);    
//      int result_c = process(change_c(start,1),index) || process(change_c(start,2),index) || process(change_c(start,3),index) || process(change_c(start,4),index) || process(change_c(start,5),index) || process(change_c(start,6),index) || process(change_c(start,7),index) || process(change_c(start,8),index) || process(change_c(start,9),index);    
//      return result_line || result_low || result_c;
//}
////int main()
////{
////    int s;
////    scanf("%d",&s);
////    
////    while(s--){
////            for(int i = 0;i < Range;i++){
////                    memo[i] = 0;
////            }       
////            char str1[17],str2[17];
////            short start,end;
////            scanf("%s",str1);
////            scanf("%s",str2);
////            
////            change(&start,&end,str1,str2);
////            
////            //printf("%hu %hu\n",start,end);
////            
////            if(process(start,0)){
////                    printf("Yes\n");
////            }else{
////                    printf("No\n");
////            }
////    }
////    
////    return 0;
////}
//void init_state(short *state, const char *str) {
//    *state = 0;
//    for (int i = 0; i < 16; i++) {
//        if (str[i] == '1') {
//            *state |= (1 << i);
//        }
//    }
//}
//int main() {
//    int s;
//    scanf("%d", &s);
//    
//    while (s--) {
//        char str1[17], str2[17];
//        short start, end;
//        
//        scanf("%s", str1);
//        scanf("%s", str2);
//        
//        init_state(&start, str1);
//        init_state(&end, str2);
//        
//        if (process(start,0)) {
//            printf("Yes\n");
//        } else {
//            printf("No\n");
//        }
//    }
//    
//    return 0;
//}
//深度优先超时，改用广度优先
//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//
//#define RANGE 65536
//
//bool visited[RANGE];
//short queue[RANGE];
//int front, rear;
//
//short change_low(short num, int n) {//-
//    switch (n) {
//        case 1:
//            num ^= (1 << 0);
//            num ^= (1 << 1);
//            num ^= (1 << 2);
//            num ^= (1 << 3);
//            break;
//        case 2:
//            num ^= (1 << 4);
//            num ^= (1 << 5);
//            num ^= (1 << 6);
//            num ^= (1 << 7);
//            break;
//        case 3:
//            num ^= (1 << 8);
//            num ^= (1 << 9);
//            num ^= (1 << 10);
//            num ^= (1 << 11);            
//            break;
//        case 4:
//            num ^= (1 << 12);
//            num ^= (1 << 13);
//            num ^= (1 << 14);
//            num ^= (1 << 15);
//            break;
//    }
//    return num;
//}
//
//short change_line(short num, int n) {//|
//    switch (n) {
//        case 1:
//            num ^= (1 << 0);
//            num ^= (1 << 4);
//            num ^= (1 << 8);
//            num ^= (1 << 12);
//            break;
//        case 2:
//            num ^= (1 << 1);
//            num ^= (1 << 5);
//            num ^= (1 << 9);
//            num ^= (1 << 13);
//            break;
//        case 3:
//            num ^= (1 << 2);
//            num ^= (1 << 6);
//            num ^= (1 << 10);
//            num ^= (1 << 14);            
//            break;
//        case 4:
//            num ^= (1 << 3);
//            num ^= (1 << 7);
//            num ^= (1 << 11);
//            num ^= (1 << 15);
//            break;
//    }    
//    return num;
//}
//
//short change_c(short num, int n) {//田
//    switch (n) {
//        case 1:
//            num ^= (1 << 0);
//            num ^= (1 << 1);
//            num ^= (1 << 4);
//            num ^= (1 << 5);
//            break;
//        case 2:
//            num ^= (1 << 2);
//            num ^= (1 << 3);
//            num ^= (1 << 6);
//            num ^= (1 << 7);
//            break;
//        case 3:
//            num ^= (1 << 8);
//            num ^= (1 << 9);
//            num ^= (1 << 12);
//            num ^= (1 << 13);
//            break;
//        case 4:
//            num ^= (1 << 10);
//            num ^= (1 << 11);
//            num ^= (1 << 14);
//            num ^= (1 << 15);
//            break;
//        case 5:
//            num ^= (1 << 1);
//            num ^= (1 << 2);
//            num ^= (1 << 5);
//            num ^= (1 << 6);
//            break;
//        case 6:
//            num ^= (1 << 6);
//            num ^= (1 << 7);
//            num ^= (1 << 10);
//            num ^= (1 << 11);
//            break;    
//        case 7:
//            num ^= (1 << 9);
//            num ^= (1 << 10);
//            num ^= (1 << 13);
//            num ^= (1 << 14);
//            break;
//        case 8:
//            num ^= (1 << 4);
//            num ^= (1 << 5);
//            num ^= (1 << 8);
//            num ^= (1 << 9);
//            break;
//        case 9:
//            num ^= (1 << 5);
//            num ^= (1 << 6);
//            num ^= (1 << 9);
//            num ^= (1 << 10);
//            break;            
//    }
//    return num;
//}
//
//void init_state(short *state, const char *str) {
//    *state = 0;
//    for (int i = 0; i < 16; i++) {
//        if (str[i] == '1') {
//            *state |= (1 << i);
//        }
//    }
//}
//
//bool bfs(short start, short target) {
//    if (start == target) return true;
//    
//    // 初始化队列和访问数组
//    front = 0;
//    rear = 0;
//    memset(visited, 0, sizeof(visited));
//    
//    queue[rear++] = start;
//    visited[start] = true;
//    
//    while (front < rear) {
//        short current = queue[front++];
//        
//        // 尝试所有行变换
//        for (int i = 1; i <= 4; i++) {
//            short next = change_line(current, i);
//            if (!visited[next]) {
//                if (next == target) return true;
//                visited[next] = true;
//                queue[rear++] = next;
//            }
//        }
//        
//        // 尝试所有列变换
//        for (int i = 1; i <= 4; i++) {
//            short next = change_low(current, i);
//            if (!visited[next]) {
//                if (next == target) return true;
//                visited[next] = true;
//                queue[rear++] = next;
//            }
//        }
//        
//        // 尝试所有田字变换
//        for (int i = 1; i <= 9; i++) {
//            short next = change_c(current, i);
//            if (!visited[next]) {
//                if (next == target) return true;
//                visited[next] = true;
//                queue[rear++] = next;
//            }
//        }
//    }
//    
//    return false;
//}
//
//int main() {
//    int s;
//    scanf("%d", &s);
//    
//    while (s--) {
//        char str1[17], str2[17];
//        short start, end;
//        
//        scanf("%s", str1);
//        scanf("%s", str2);
//        
//        init_state(&start, str1);
//        init_state(&end, str2);
//        
//        if (bfs(start, end)) {
//            printf("Yes\n");
//        } else {
//            printf("No\n");
//        }
//    }
//    
//    return 0;
//}
//修改思路，储存可以变换后的数字
//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//
//#define RANGE 65536
//
//bool reachable[RANGE] = { false };
//short queue[RANGE];
//int front, rear;
//
//// 您的操作函数保持不变...
//short change_low(short num, int n) {//-
//    switch (n) {
//    case 1:
//        num ^= (1 << 0);
//        num ^= (1 << 1);
//        num ^= (1 << 2);
//        num ^= (1 << 3);
//        break;
//    case 2:
//        num ^= (1 << 4);
//        num ^= (1 << 5);
//        num ^= (1 << 6);
//        num ^= (1 << 7);
//        break;
//    case 3:
//        num ^= (1 << 8);
//        num ^= (1 << 9);
//        num ^= (1 << 10);
//        num ^= (1 << 11);
//        break;
//    case 4:
//        num ^= (1 << 12);
//        num ^= (1 << 13);
//        num ^= (1 << 14);
//        num ^= (1 << 15);
//        break;
//    }
//    return num;
//}
//
//short change_line(short num, int n) {//|
//    switch (n) {
//    case 1:
//        num ^= (1 << 0);
//        num ^= (1 << 4);
//        num ^= (1 << 8);
//        num ^= (1 << 12);
//        break;
//    case 2:
//        num ^= (1 << 1);
//        num ^= (1 << 5);
//        num ^= (1 << 9);
//        num ^= (1 << 13);
//        break;
//    case 3:
//        num ^= (1 << 2);
//        num ^= (1 << 6);
//        num ^= (1 << 10);
//        num ^= (1 << 14);
//        break;
//    case 4:
//        num ^= (1 << 3);
//        num ^= (1 << 7);
//        num ^= (1 << 11);
//        num ^= (1 << 15);
//        break;
//    }
//    return num;
//}
//
//short change_c(short num, int n) {//田
//    switch (n) {
//    case 1:
//        num ^= (1 << 0);
//        num ^= (1 << 1);
//        num ^= (1 << 4);
//        num ^= (1 << 5);
//        break;
//    case 2:
//        num ^= (1 << 2);
//        num ^= (1 << 3);
//        num ^= (1 << 6);
//        num ^= (1 << 7);
//        break;
//    case 3:
//        num ^= (1 << 8);
//        num ^= (1 << 9);
//        num ^= (1 << 12);
//        num ^= (1 << 13);
//        break;
//    case 4:
//        num ^= (1 << 10);
//        num ^= (1 << 11);
//        num ^= (1 << 14);
//        num ^= (1 << 15);
//        break;
//    case 5:
//        num ^= (1 << 1);
//        num ^= (1 << 2);
//        num ^= (1 << 5);
//        num ^= (1 << 6);
//        break;
//    case 6:
//        num ^= (1 << 6);
//        num ^= (1 << 7);
//        num ^= (1 << 10);
//        num ^= (1 << 11);
//        break;
//    case 7:
//        num ^= (1 << 9);
//        num ^= (1 << 10);
//        num ^= (1 << 13);
//        num ^= (1 << 14);
//        break;
//    case 8:
//        num ^= (1 << 4);
//        num ^= (1 << 5);
//        num ^= (1 << 8);
//        num ^= (1 << 9);
//        break;
//    case 9:
//        num ^= (1 << 5);
//        num ^= (1 << 6);
//        num ^= (1 << 9);
//        num ^= (1 << 10);
//        break;
//    }
//    return num;
//}
//void init_state(short* state, const char* str) {
//    *state = 0;
//    for (int i = 0; i < 16; i++) {
//        if (str[i] == '1') {
//            *state |= (1 << i);
//        }
//    }
//}
//void precompute() {
//    memset(reachable, 0, sizeof(reachable));
//    front = rear = 0;
//
//    queue[rear++] = 0;  // 从全0状态开始
//    reachable[0] = true;
//
//    while (front < rear) {
//        short current = queue[front++];
//
//        for (int i = 1; i <= 4; i++) {
//            short next = change_line(current, i);
//            if (!reachable[next]) {
//                reachable[next] = true;
//                queue[rear++] = next;
//            }
//        }
//
//        for (int i = 1; i <= 4; i++) {
//            short next = change_low(current, i);
//            if (!reachable[next]) {
//                reachable[next] = true;
//                queue[rear++] = next;
//            }
//        }
//
//        for (int i = 1; i <= 9; i++) {
//            short next = change_c(current, i);
//            if (!reachable[next]) {
//                reachable[next] = true;
//                queue[rear++] = next;
//            }
//        }
//    }
//}
//
//int main() {
//    precompute();  // 预处理所有可达状态
//
//    int T;
//    scanf("%d", &T);
//
//    while (T--) {
//        char str1[17], str2[17];
//        short start, end;
//
//        scanf("%s%s", str1, str2);
//
//        // 使用一致的位顺序初始化
//        start = end = 0;
//        for (int i = 0; i < 16; i++) {
//            if (str1[i] == '1') start |= (1 << i);
//            if (str2[i] == '1') end |= (1 << i);
//        }
//
//        // 关键：A->B可达 当且仅当 A^B 可达
//        if (reachable[start ^ end]) {
//            printf("Yes\n");
//        }
//        else {
//            printf("No\n");
//        }
//    }
//
//    return 0;
//}