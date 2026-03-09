//问题 A: 水仙花数
//#include <stdio.h>
//#include <math.h>
//int main(){
//	int number=1,found=0;
//	while(number != 0){
//		found = 0;
//		scanf("%d",&number);
//		int count = 0,w=0;
//		int cs = number;
//		while(cs!=0){
//			w++;
//			cs/=10;
//		}	
//		cs = number;	
//		while(cs != 0){
//			count += pow(cs%10,w);
//			cs/=10;
//			if(count == number){
//				printf("Yes\n");
//				found = 1;
//				break;
//			}else if(count > number){
//				break;
//			}
//		}
//		if(found != 1 && number != 0){
//			printf("No\n");
//		}
//	}
//	return 0;
//}

//问题 B: 平衡三进制2
//#include <stdio.h>
//#include <string.h>
//
//void reverse(char *s, int len) {
//    int i = 0, j = len - 1;
//    while (i < j) {
//        char temp = s[i];
//        s[i] = s[j];
//        s[j] = temp;
//        i++;
//        j--;
//    }
//}
//
//void decimalToBalancedTernary(int n, char *result) {
//    if (n == 0) {
//    	strcpy(result, "0");
//        return;
//    }
//    int index = 0;
//    while (n > 0) {
//        int rem = n % 3;
//        n = n / 3;
//        if (rem == 2) {
//            result[index++] = '-';
//            n++;
//        } else if (rem == 1) {
//            result[index++] = '1';
//        } else {
//            result[index++] = '0';
//        }
//    }
//    result[index] = '\0';
//    reverse(result, index);
//}
//
//int main() {
//    int N;
//    scanf("%d", &N);
//    while (N--) {
//        int x;
//        scanf("%d", &x);
//        char result[100];
//        decimalToBalancedTernary(x, result);
//        printf("%s\n", result);
//    }
//    return 0;
//}

//问题 C: A+B V
//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//long long count(char *a, char *b) {
//    int len_a = strlen(a);
//    int len_b = strlen(b);
//    int max_len = len_a > len_b ? len_a : len_b;
//    long long result = 0;
//    long long power = 1; 
//    for (int i = 0; i < max_len; i++) {
//        int digit_a = (i < len_a) ? (a[len_a - 1 - i] - '0') : 0;
//        int digit_b = (i < len_b) ? (b[len_b - 1 - i] - '0') : 0;
//        long long sum = digit_a + digit_b;
//        result += (sum % 10) * power;
//        power *= 10;
//    }
//    return result;
//}
//int main(){
//	int k = 0;
//	char a[100]={0},b[100]={0};
//	scanf("%d",&k);
//	while(k--){
//		scanf("%s %s",a,b);
//		char c[100]={};
//		printf("%lld\n",count(a,b));
//	}
//	return 0;
//}

//问题 D: Digit String
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main(){
//	char str[40];
//	long long n;
//	long long result;
//	int k,found=0;
//	while(scanf("%s %lld",str,&n) != EOF){
//		found = 0;
//		char *end;
//		if(strcmp(str,"0") == 0 && n == 0){
//			printf("2\n");
//			continue;
//		}
//		for(int i=2;i<=16;i++){
//			result = strtol(str,&end,i);//进制转化函数 
//			if(result == n && *end == '\0'){
//				found = 1;
//				printf("%d\n",i);
//				break;
//			}	
//		}
//		if(found == 0){
//			printf("Impossible\n");
//		}
//	}
//	return 0;
//}

//问题 E: 单调
//#include <stdio.h>
//
//// 判断整数n在b进制下是否是单调的
//int is_monotonic(int n, int b) {
//    int prev_digit = -1; // 前一位数字，初始为-1以保证第一个数字一定比它大
//    while (n > 0) {
//        int current_digit = n % b;
//        if (current_digit <= prev_digit) {
//            return 0; // 当前位不大于前一位，不满足单调
//        }
//        prev_digit = current_digit;
//        n /= b;
//    }
//    return 1; // 所有位都满足条件
//}
//
//// 寻找最小的满足条件的进制b
//int find_min_base(int n) {
//    int low = 2, high = n;
//    int ans = n; // 初始设为一个极大值
//    while (low <= high) {
//        int mid = (low + high) / 2;
//        if (is_monotonic(n, mid)) {
//            ans = mid;
//            high = mid - 1; // 尝试寻找更小的b
//        } else {
//            low = mid + 1; // 需要更大的b
//        }
//    }
//    return ans;
//}
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    for (int i = 0; i < T; i++) {
//        int n;
//        scanf("%d", &n);
//        printf("%d\n", find_min_base(n));
//    }
//    return 0;
//}
//问题 F: 相同的数码
//#include <stdio.h>
//#include <stdlib.h>
//int process(long long number,int base){
//	long long temp = number;
//	int cs = temp % base;
//	while(temp /= base){
//		if(cs != temp % base){
//			return -1;
//		}
//	}
//	return 0;
//}
//int main(){
//	long long number;
//	int k,found = 0;
//	scanf("%d",&k);
//	while(k--){
//		found = 0;
//		scanf("%lld",&number);
//		if(number == 0 || number == 1){
//			printf("2\n");
//			continue;
//		}
//		for(int i = 2;i <= 100;i++){
//			if(process(number,i) == 0){
//				printf("%d\n",i);
//				found = 1;
//				break;
//			}
//		}
//		if(found == 0){
//			printf("0\n");
//		}
//	}
//}

//问题 G: 2021
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//
//int main() {
//    char s[105];
//    while (scanf("%s", s) != EOF) {
//        int len = strlen(s);
//        int max_digit = 0;
//        for (int i = 0; i < len; i++) {//找出最大数字 
//            int digit = s[i] - '0';
//            if (digit > max_digit) {
//                max_digit = digit;
//            }
//        }
//        int b_min = (max_digit + 1) > 2 ? (max_digit + 1) : 2;//找出最小进制 
//        int found = 0;
//        int ans = 0;
//        if (len == 1 && s[0] == '0') {//如果数字串为 0 就退出 
//            printf("0\n");
//            continue;
//        }
//        for (int b = b_min; b <= 2022; b++) {//最大进制为2022（遍历寻找） 
//            long long value = 0;
//            for (int i = 0; i < len; i++) {
//                int digit = s[i] - '0';
//                value = value * b + digit;//使用霍纳法则
//                if (value > 2021) {//如果大于2021就提前退出 
//                    break;
//                }
//            }
//            if (value == 2021) {
//                ans = b;
//                found = 1;
//                break;
//            }
//        }
//        if (found) {
//            printf("%d\n", ans);
//        } else {
//            printf("0\n");
//        }
//    }
//    return 0;
//}

//问题 H: String Hash
// 霍纳法则（Horner's Method）
//#include <stdio.h>
//#include <string.h>
//#define MOD 1000000007
//#define BASE 26
//int main() {
//    char s[1005];
//    while (scanf("%s", s) != EOF) {
//        int len = strlen(s);
//        long long hash = 0;
//		hash = (hash * BASE + 1) % MOD;
//		for(int i = 0;i < len;i++){
//			int digit = s[i] - 'a';
//			hash = (hash * BASE + digit) % MOD;// 霍纳法则（Horner's Method）
//		}
//        printf("%lld\n", hash);
//    }
//    return 0;
//}

//问题 I: 回文数
//#include <stdio.h>
//#include <stdbool.h>
//bool choose(int number,int base){
//	int change[100]={0};
//	int l = 0;
//	while(number != 0){
//		change[l] = number % base;
//		number /= base;
//		l++;
//	}
//    for (int i = 0, j = l - 1; i < j; i++, j--) {
//        if (change[i] != change[j]) {
//            return false;
//        }
//    }
//	return true;
//}
//int main(){
//	int T,number;
//	scanf("%d",&T);
//	while(T--){
//		scanf("%d",&number);
//		if (number == 0 || number == 1) {
//            printf("2\n");
//            continue;
//        }
//		for(int m = 2; ;m++){
//			if(choose(number,m)){
//				printf("%d\n",m);
//				break;
//			}
//		}	
//	}
//	return 0;
//}

//问题 J: Min Base II
//#include <stdio.h>
//#include <stdlib.h>
//int process(long long number,int base){
//	int *total = (int *)calloc(base + 1,sizeof(int)); 
//	long long temp = number;
//	while(temp != 0){
//		total[temp % base]++;
//		temp /= base;
//	}
//	int cs = 0;
//	for(int i = 0; ;i++){
//		if(total[i] != 0){
//			cs = i;
//			temp = total[i];
//			break;
//		}
//	}
//	for(int i = cs + 1;i <= base ; i++){
//		if(total[i] == 0)continue;
//		if(total[i] != temp){
//			free(total);
//			return -1;	
//		}
//	}
//	free(total);
//	return base;
//}
//int main(){
//	long long number;
//	int k;
//	scanf("%d",&k);
//	while(k--){
//		scanf("%lld",&number);
//		if(number == 0 || number == 1){
//			printf("2\n");
//			continue;
//		}
//		for(int i = 2; ;i++){
//			if(process(number,i) != -1){
//				printf("%d\n",i);
//				break;
//			}
//		}
//	}
//} 

//问题 K: 数码和
//#include <stdio.h>
//#include <string.h>
//
//int calculate_sum(long long num, int base) {
//    if (num == 0) {
//        return 0;
//    }
//    int sum = 0;
//    while (num > 0) {
//        sum += num % base;
//        num /= base;
//    }
//    return sum;
//}
//
//int main() {
//    int k;
//    scanf("%d", &k);
//    while (k--) {
//        int sum_base[17] = {0};
//        int count_sum[1000] = {0};
//        long long num;
//        scanf("%lld", &num);
//        for (int base = 2; base <= 16; base++) {
//            int s = calculate_sum(num, base);
//            sum_base[base] = s;
//            if (s < 1000) {
//                count_sum[s]++;
//            }
//        }
//        int max_count = -1;
//        for (int i = 0; i < 1000; i++) {
//            if (count_sum[i] > max_count) {
//                max_count = count_sum[i];
//            }
//        }
//        int target_sum = -1;
//        printf("%d\n",max_count);
//        for (int i = 0; i <= 999; i++) {
//            if (count_sum[i] == max_count) {
//                target_sum = i;
//				printf("%d", target_sum);
//        		for (int base = 2; base <= 16; base++) {
//            		if (sum_base[base] == target_sum) {
//                		printf(" %d", base);
//            		}
//        		}
//        		printf("\n");
//            }
//        }
//    }
//    return 0;
//}

//问题 L: Binary
//#include <stdio.h>
//#include <string.h>
//
//int choose(long long number){
//	int max = 0;
//	int count = 0;
//	while(number != 0){
//		if(number % 2 == 1){
//			count ++;
//		}else{
//			count = 0;
//		}
//		if(count > max){
//			max = count;
//		}
//		number /= 2;
//	}
//	return max;
//}
//
//int main(){
//	int k = 0;
//	long long number = 0;
//	scanf("%d",&k);
//	while(k--){
//		scanf("%lld",&number);
//		printf("%d\n",choose(number));
//	}
//	return 0;
//} 
