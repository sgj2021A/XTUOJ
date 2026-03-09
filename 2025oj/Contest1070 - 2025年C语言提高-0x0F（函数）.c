///问题 C: 回文串
//#include <stdio.h>
//#include <string.h>
//void reversal(char *base, char *aim){
//	int len = strlen(base);
//	int location = 0;
//	for(int i = len - 1;i >= 0; i--){
//		aim[i] = base[location];
//		location++;
//	}
//	aim[len] = '\0';
//}
//void  swapStr(char str1[],char str2[]){
//	char temp[101];
//	strcpy(temp,str1);
//	strcpy(str1,str2);
//	strcpy(str2,temp);
//}
//int main()
//{
//	int T;
//	scanf("%d",&T);
// 	for(int i=0;i<T;i++){
//		char str1[101] = {0},str2[101] = {0},str_reversal[101] = {0};
//		scanf("%s %s",str1,str2);
//		reversal(str1,str_reversal);
//		int len = strlen(str1),found = 0;
//		int len1 = strlen(str2);
//		if(len1 > len){
//			swapStr(str1,str2);
//		}
//		if(strstr(str1,str2) != NULL || strstr(str_reversal,str2) != NULL){
//			printf("Yes\n");
//			continue;
//		}
//		for(int j = 0;j < len;j++){
//			char temp = str1[0],temp_reversal = str_reversal[0];
//			for(int k = 1;k < len;k++){
//				str1[k - 1] = str1[k];
//				str_reversal[k - 1] = str_reversal[k];
//				
//			}
//			str1[len - 1] = temp;
//			str_reversal[len - 1] = temp_reversal;
//			//printf("%s %s\n",str1,str_reversal);
//			if(strstr(str1,str2) != NULL || strstr(str_reversal,str2) != NULL){
//				printf("Yes\n");
//				found = 1;
//				break;
//			}
//		}
//		if(found == 0){
//			printf("No\n");
//		}
//	 }
//	return 0;
//}
//修改 
//#include <stdio.h>
//#include <string.h>
//#include <stdbool.h>
//#include <stdlib.h>
//bool combine_left(char *str,char *base,int size,int location){
//	int len = strlen(str);
//	for(int i = 0;i < size;i++){
//		//printf("%c %c %d",str[(location - i + len) % len],base[i],(location - i + len) % len);
//		//printf("\n");
//		if(str[(location - i + len) % len] != base[i]){
//			return false;
//		}
//	}
//	return true;
//}
//
//bool combine_right(char *str,char *base,int size,int location){
//	int len = strlen(str);
//	for(int i = 0;i < size;i++){
//		//printf("%c %c %d",str[(location + i) % len],base[i],(location + i) % len);
//		//printf("\n");
//		if(str[(location + i) % len] != base[i]){
//			return false;
//		}
//	}
//	return true;
//}
//void Str_process(char *str1,char *str2){
//	int len1 = strlen(str1);
//	int len2 = strlen(str2);
//	for(int i = 0;i < len1;i++){
//		if(str1[i] == str2[0]){
//			if(combine_left(str1,str2,len2,i) || combine_right(str1,str2,len2,i)){
//				printf("Yes\n");
//				return;
//			}
//		}
//	}
//	printf("No\n");
//}
//
//int main(){
//	int k = 0;
//	scanf("%d",&k);
//	while(k--){
//		char str1[1000] = {0},str2[1000] = {0};
//		scanf("%s %s",str1,str2);
//		if(strlen(str2) == 0){
//			printf("Yes\n");
//		}else{
//			Str_process(str1,str2);			
//		}
//	}
//	return 0;
//}
//不知道错哪里了 
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        char A[101], B[101];
//        scanf("%s%s", A, B);
//        int lenA = strlen(A);
//        int lenB = strlen(B);
//        
//        int totalLen = lenA * lenB;
//        char *extendedA = (char*)malloc(totalLen + 1);
//        char *extendedRevA = (char*)malloc(totalLen + 1);
//        
//        for (int i = 0; i < lenB; i++) {
//            memcpy(extendedA + i * lenA, A, lenA);
//        }
//        extendedA[totalLen] = '\0';
//        
//        char revA[101];
//        for (int i = 0; i < lenA; i++) {
//            revA[i] = A[lenA - 1 - i];
//        }
//        revA[lenA] = '\0';
//        
//        for (int i = 0; i < lenB; i++) {
//            memcpy(extendedRevA + i * lenA, revA, lenA);
//        }
//        extendedRevA[totalLen] = '\0';
//        
//        if (strstr(extendedA, B) != NULL || strstr(extendedRevA, B) != NULL) {
//            printf("Yes\n");
//        } else {
//            printf("No\n");
//        }
//        
//        free(extendedA);
//        free(extendedRevA);
//    }
//    return 0;
//}

//问题 B: 彩球
//#include <stdio.h>
//
//int main(){
//	int T;
//	scanf("%d",&T);
//	while(T--){
//		int n,m,k;
//		scanf("%d %d %d",&n,&m,&k);
//		int a[10001],bucket[10001],count = 0,found = 0;
//		for(int i = 0;i < n;i++){
//			scanf("%d",&a[i]);
//		} 
//		for(int i = 0;i <= n - m;i++){ 
//			for(int j = 1;j < n;j++){
//				bucket[j] = 0;
//			}
//			count = 0;
//			for(int j = 0;j < m;j++){
//				//printf("%d ",a[(j + i)%n]);
//				if(bucket[a[(j + i)%n]] == 0){
//					count++;
//				}
//				bucket[a[(j + i)%n]]++;
//			}
//			//printf("\n");
//			if(count != k){
//				printf("No\n");
//				found = 1;
//				break;
//			}
//		}
//		if(found == 0){
//			printf("Yes\n");
//		}
//	}
//	return 0;
//} 
////方案二 滑动窗口检查（前一种超时） 
//#include <stdio.h>
//#include <string.h>
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        int n, m, k;
//        scanf("%d %d %d", &n, &m, &k);
//        int a[10001];
//        
//        for (int i = 0; i < n; i++) {
//            scanf("%d", &a[i]);
//        }
//        
//        // 使用滑动窗口技术优化
//        int cnt[10001] = {0};  // 记录每种颜色的出现次数
//        int distinct = 0;      // 当前窗口中的不同颜色数量
//        int valid = 1;         // 标记是否所有窗口都满足条件
//        
//        // 初始化第一个窗口
//        for (int i = 0; i < m; i++) {
//            if (cnt[a[i]] == 0) {
//                distinct++;
//            }
//            cnt[a[i]]++;
//        }
//        
//        // 检查第一个窗口
//        if (distinct != k) {
//            valid = 0;
//        }
//        
//        // 滑动窗口检查其余窗口
//        for (int i = 1; i <= n - m && valid; i++) {
//            // 移除窗口最左边的元素
//            int left_color = a[i - 1];
//            cnt[left_color]--;
//            if (cnt[left_color] == 0) {
//                distinct--;
//            }
//            
//            // 添加窗口最右边的元素
//            int right_color = a[i + m - 1];
//            if (cnt[right_color] == 0) {
//                distinct++;
//            }
//            cnt[right_color]++;
//            
//            // 检查当前窗口
//            if (distinct != k) {
//                valid = 0;
//            }
//        }
//        
//        printf(valid ? "Yes\n" : "No\n");
//    }
//    return 0;
//}

//问题 C: 回文串
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//bool is_palindrome(const char *str,int size) {
//    int left = 0;
//    int right = size;  // 字符串最后一个字符的索引
// 
//    while (left < right) {
//        if (str[left] != str[right]) {
//            return false;  // 不匹配，不是回文
//        }
//        left++;
//        right--;
//    }
//    return true;  // 所有字符匹配，是回文
//}
//
//int main(){
//	char str[1001] = {0};
//	while(scanf("%s",str) != EOF){
//		//获取字符串长度
//		int len = strlen(str);
//		//动态添加位置
//		int total = 0; 
//		char *str_pd = (char*)malloc(sizeof(char) * len + 1);
//		int combine = 0;
//		for(int i = 0;i < len + 1;i++){
//			combine = 0;
//			for(int j = 0;j < len;j++){
//				if(j == i){
//					combine++; 
//				}
//				str_pd[combine + j] = str[j];
//			}
//			str_pd[i] = str_pd[len - i];
//			//判断会问字符串 
//			if(is_palindrome(str_pd,len)){
//				total++;
//			}	 
//		}
//		free(str_pd);
//		printf("%d\n",total);
//	}
//	return 0;
//} 

//问题 D: 完全区间


//问题 E: 分割_1
#include <stdio.h>
#include <string.h>

int main(){
	
	return 0;
}


//问题 J: 区间
//#include <stdio.h>
//#include <string.h>
//#include <stdbool.h>
//
//bool total(int *c, int k) {
//    for(int i = 0; i < 26; i++) {
//        if(c[i] > k) return false;
//    }
//    return true;
//} 
//
//int main() {
//    int T; // 测试用例个数
//    scanf("%d", &T);
//    
//    while(T--) {
//        int k = 0;
//        scanf("%d", &k);
//        
//        char str[1001] = {0};
//        scanf("%s", str);
//        int len = strlen(str); 
//        
//        int c[26] = {0};
//        for(int i = 0; i < len; i++) {
//            c[str[i] - 'a']++;
//        }
//        
//        // 初始统计个数 
//        if(total(c, k)) {
//            printf("0\n");
//            continue;
//        }
//        
//        int min = 10000;
//        
//        // 枚举所有可能的删除区间
//        for(int i = 0; i < len; i++) {
//            for(int j = i; j < len; j++) {
//                // 复制原始频率数组
//                int c_c[26] = {0};
//                for(int x = 0; x < 26; x++) {
//                    c_c[x] = c[x];
//                }
//                
//                // 减去删除区间中的字符频率
//                for(int x = i; x <= j; x++) {
//                    c_c[str[x] - 'a']--;
//                }
//                
//                // 检查是否满足条件
//                if(total(c_c, k)) {
//                    int delete_length = j - i + 1;
//                    if(delete_length < min) {
//                        min = delete_length;
//                    }
//                }
//            }
//        }
//        
//        printf("%d\n", min);
//    }
//    
//    return 0;
//}
//上面的超时(二分查找 + 二维前缀和)
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//#define MAX_N 1000
//#define ALPHABET 26
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    
//    while (T--) {
//        int k;
//        scanf("%d", &k);
//        char s[MAX_N + 1];
//        scanf("%s", s);
//        int n = strlen(s);
//        
//        // 计算总频率
//        int total_freq[ALPHABET] = {0};
//        for (int i = 0; i < n; i++) {
//            total_freq[s[i] - 'a']++;
//        }
//        
//        // 检查整个字符串是否已经满足条件
//        int all_valid = 1;
//        for (int c = 0; c < ALPHABET; c++) {
//            if (total_freq[c] > k) {
//                all_valid = 0;
//                break;
//            }
//        }
//        
//        if (all_valid) {
//            printf("0\n");
//            continue;
//        }
//        
//        // 前缀频率数组
//        int **pref = (int **)malloc((n + 1) * sizeof(int *));
//        for (int i = 0; i <= n; i++) {
//            pref[i] = (int *)malloc(ALPHABET * sizeof(int));
//            memset(pref[i], 0, ALPHABET * sizeof(int));
//        }
//        
//        // 计算前缀频率
//        for (int i = 1; i <= n; i++) {
//            memcpy(pref[i], pref[i - 1], ALPHABET * sizeof(int));
//            int idx = s[i - 1] - 'a';
//            pref[i][idx]++;
//        }
//        
//        int ans_d = n;
//        
//        // 枚举所有可能的前缀
//        for (int i = 0; i <= n; i++) {
//            // 检查前缀是否满足条件
//            int prefix_valid = 1;
//            for (int c = 0; c < ALPHABET; c++) {
//                if (pref[i][c] > k) {
//                    prefix_valid = 0;
//                    break;
//                }
//            }
//            if (!prefix_valid) {
//                continue;
//            }
//            
//            // 二分查找最小的后缀起始位置
//            int low = i, high = n;
//            int candidate = -1;
//            
//            while (low <= high) {
//                int mid = (low + high) / 2;
//                int valid = 1;
//                
//                for (int c = 0; c < ALPHABET; c++) {
//                    int mid_freq = pref[mid][c] - pref[i][c];
//                    int merged_freq = total_freq[c] - mid_freq;
//                    
//                    if (merged_freq > k) {
//                        valid = 0;
//                        break;
//                    }
//                }
//                
//                if (valid) {
//                    candidate = mid;
//                    high = mid - 1;
//                } else {
//                    low = mid + 1;
//                }
//            }
//            
//            if (candidate != -1) {
//                int d = candidate - i;
//                if (d < ans_d) {
//                    ans_d = d;
//                }
//            }
//        }
//        
//        printf("%d\n", ans_d);
//        
//        // 释放内存
//        for (int i = 0; i <= n; i++) {
//            free(pref[i]);
//        }
//        free(pref);
//    }
//    
//    return 0;
//}

//问题 F: 数字
//#include <stdio.h>
//#include <string.h>
//#include <stdbool.h>
//#include <stdlib.h>
//
//int compare(char *a,char *b){
//	int len_a = strlen(a), len_b = strlen(b);
//	if(len_a != len_b)return len_a > len_b;
//	for(int i = 0;i < len_a; i++){
//		if(a[i] != b[i]) return a[i] > b[i];
//	}
//	return 1;
//}//a >= b 为 true 
//
//int subtraction(char *a,char *b,char *c){
//	int len_a = strlen(a), len_b = strlen(b);
//	int maxlen = len_a > len_b ? len_a : len_b;
//	int s = 0;
//	
//	int num_a[1000] = {0}, num_b[1000] = {0},result[1000] = {0};
//	for(int i = 0;i < len_a; i++) num_a[i] = a[len_a - 1 - i] - '0';
//	for(int i = 0;i < len_b; i++) num_b[i] = b[len_b - 1 - i] - '0';
//	for(int i = 0;i < maxlen;i++){
//		int temp = num_a[i] - num_b[i] - s;
//		if(temp < 0){
//			temp += 10;
//			s = 1; 
//		}else{
//			s = 0;
//		}
//		result[i] = temp;
//	}
//	// 去除前导零
//	int k = maxlen - 1;
//	while(k > 0 && result[k] == 0)k--;
//	for(int i = 0;i <= k;i++){
//		c[i] = result[k - i] + '0';
//	}
//	c[k + 1] = '\0';
//} 
//
//int main(){
//	
//	int k = 0;
//	char number_a[100],number_b[100],number_c[100];
//	scanf("%d",&k);
//	while(k--){
//		int count = 0;
//		scanf("%s %s",number_a,number_b);
//		while(compare(number_a,number_b)){
//			subtraction(number_a,number_b,number_c);
//			count++;
//			strcpy(number_a,number_c);
//			int len_a = strlen(number_a);
//			for(int i = len_a - 1;i >= 0;i--){
//				if(number_a[i] == '0'){
//					continue;
//				}else{
//					number_a[i + 1] = '\0';
//					break;
//				}
//			}
//		} 
//		printf("%d %s\n",count,number_c);
//	}	
//	return 0;
//}
//感觉超时，不改了，重写一个 
//#include <stdio.h>
//#include <string.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#include <time.h>
//int main(){
////cs
//    clock_t start, end;
//    double cpu_time_used;
////cs
//	int k = 0;
//	long long a,b;
//	scanf("%d",&k);
//	while(k--){
//		int count = 0;
//		scanf("%lld %lld",&a,&b);
//		int found = 0;
//		while(a > b){
//			if(a % 10 == 0){
//				count++;
//			}
//			while(a != 0){
//				if(a % 10 == 0){
//					a /= 10;
//				}else{
//					found = 1;
//					break;
//				}
//			}
//			if(found == 1){
//				if(a <= b){
//					found = 0;
//					break;
//				}
//			}
//			count++;
//			a -= b;
//		} 
//		printf("%d %lld\n",count,a);
//	}	
////cs
//    end = clock(); // 记录结束时间
//    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // 计算耗时（秒）
// 
//    printf("代码运行时间: %f 秒\n", cpu_time_used);
////cs
//	return 0;
//}

//时间超限

//#include <stdio.h>
//#include <string.h>
//#include <stdbool.h>
//#include <stdlib.h>
//
//int main(){
//	char a[100];
//	long long b;
//	int k;
//	scanf("%d",&k);
//	
//	while(k--){
//		scanf("%s",a);
//		scanf("%lld",&b);
//		int len = strlen(a);
//		int count = 0;
//		
//		//首先先去掉尾部为0的字符
//		if(a[len - 1] == '0')count++;
//		int new_len = len; 
//		for(int i = len -1;i >= 0;i--){
//			if(a[i] == '0'){
//				new_len--;
//			}else{
//				break;
//			}
//		}
//		a[new_len] = '\0';
//		long long a_atoi = atoll(a);
//		if(a_atoi <= b){
//			printf("%d %lld\n",count,a_atoi);
//			continue;
//		}
//		
//		//寻找可以被整除的数 
//		char temp_str[100];
//		
//		while(1){
//			len = strlen(a); 
//			a_atoi = atoll(a);
//			if(a_atoi < b || len == 0){
//				break;
//			}
//			for(int i = len - 1;i >= 0;i--){
//				int index = 0;
//				for(int j = i;j <= len - 1;j++,index++){
//					temp_str[index] = a[j];
//				}
//				temp_str[index] = '\0';
//				a_atoi = atoll(temp_str);
//				//printf("%s\n",temp_str);
//				if(a_atoi % b == 0 && a_atoi != 0){
//					count += a_atoi / b;
//					if(atoll(a) - a_atoi >= b){
//						count++;
//					}
//					a[i] = '\0';
//					//处理0 
//					len = strlen(a); 
//					new_len = len; 
//					for(int i = len -1;i >= 0;i--){
//						if(a[i] == '0'){
//							new_len--;
//						}else{
//							break;
//						}
//					}
//					a[new_len] = '\0';
//					break;
//				}			 
//				if(i == 0){
//					count += a_atoi / b;
//					sprintf(a,"%lld",atoll(a) - count * b); 
//				}	
//			}
//		}
//		//输出 
//		a_atoi = atoll(a);
//		if(strlen(a) == 0){
//			printf("%d %lld\n",count,0);	
//		}else{
//			printf("%d %lld\n",count,a_atoi);
//		}
//	}
//	
//	return 0;
//}
//修正（重要结论）（原来的代码错误在于可以不用连续的字符串，比如324的话2最后答案为162 0，而上面的代码给出的结果为5 1,答案错误，我们只需要处理可以被最后一位整除的数就好，而不是连续数位）-----------------------------------------------------------------
//#include <stdio.h>
//#include <string.h>
//#include <stdbool.h>
//#include <stdlib.h>
//
//// 计算最大公约数
//int gcd(int a, int b) {
//    return b == 0 ? a : gcd(b, a % b);
//}
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    
//    while (T--) {
//        long long n, k;
//        scanf("%lld %lld", &n, &k);
//        long long steps = 0;
//        
//        while (n >= k) {
//            if (n % 10 == 0) {
//                // 去掉尾部所有0
//                while (n % 10 == 0 && n != 0) {
//                    n /= 10;
//                }
//                steps++;
//            } else {
//                int d = n % 10;
//                int g = gcd(k, 10);
//                
//                if (d % g != 0) {
//                    // 无解，只能一直减k直到n<k
//                    long long t = n / k;//如果d不能被g整除，说明无法通过减k使尾部出现0
//                    steps += t;
//                    n -= t * k;
//                    break;
//                } else {
//                    // 找到最小的x使得x*k的个位数等于d的个位数
//                    int x;
//                    for (x = 1; x <= 10; x++) {
//                        if ((x * k) % 10 == d % 10) {
//                            break;
//                        }
//                    }
//                    
//                    if (n >= x * k) {
//                        steps += x;
//                        n -= x * k;
//                    } else {
//                        long long t = n / k;
//                        steps += t;
//                        n -= t * k;
//                        break;
//                    }
//                }
//            }
//        }
//        
//        printf("%lld %lld\n", steps, n);
//    }
//    
//    return 0;
//} 

//--------------------------------------------------

//问题 H: 刷油漆
//#include <stdio.h>
//#include <stdlib.h>
//int main(){
//	int m,n;
//	scanf("%d %d",&n,&m);
//	//初始化n * m 大小的MAP
//	short **map = (short**)malloc(sizeof(short*) * (n + 1));
//	for(int j = 0;j <= m;j++){
//		map[j] = (short*)malloc(sizeof(short) * (m + 1));
//	}
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            map[i][j] = 0;
//        }
//    }
//	//改变颜色
//	int c,t,f,list,k;
//	scanf("%d %d",&c,&t);
//	int total[1001] = {0};
//	while(t--){
//		scanf("%d",&f);
//		if(f == 0){//行改变 
//			scanf("%d %d",&list,&k);
//			for(int j = 1;j <= m;j++){
//				map[list][j] = k;
//			}
//		}else{//列改变 
//			scanf("%d %d",&list,&k);
//			for(int j = 1;j <= n;j++){
//				map[j][list] = k;
//			}				
//		}
//	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= m;j++){
//			total[map[i][j]]++;
//		}
//	}
//	for(int j = 1;j <= c;j++){
//		if(total[j] != 0){
//			printf("%d %d\n",j,total[j]);
//		}
//	}
//	for(int j = 0;j <= m;j++){
//		free(map[j]);
//	}
//	// 在 free 之前计算总分配内存
//	size_t total_allocated = 0;
//	total_allocated += (n + 1) * sizeof(short *);  // map 指针数组
//	for (int i = 0; i <= n; i++) {
//	    total_allocated += (m + 1) * sizeof(short);  // 每行的 short 数组
//	}
//	printf("Total allocated memory: %zu bytes\n", total_allocated);
//	free(map);				 
//	return 0;
//} 
//内存超限 190MB
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(){
//	int n,m,c,t,f,list,k;
//	scanf("%d %d %d %d",&n,&m,&c,&t);
//	int *total = (int*)malloc(sizeof(int) * (c + 1));
//	int *line = (int*)malloc(sizeof(int) * (m + 1));
//	int *row = (int*)malloc(sizeof(int) * (n + 1));
//	//初始化 
//	for(int i = 0;i <= n;i++){
//		row[i] = 0;
//	}
//	for(int i = 0;i <= m;i++){
//		line[i] = 0;
//	}
//	//更改 
//	while(t--){
//		scanf("%d %d %d",&f,&list,&k);
//		if(f == 0){//处理行
//			for(int i = 1;i <= n;i++){
//				if(line[i] != 0){
//					if(total[line[i]] != 0)total[line[i]]--;
//				}
//			} 
//			row[list] = k; 
//			total[k] = m;
//		}else{//处理列 
//			for(int i = 1;i <= m;i++){
//				if(row[i] != 0){
//					if(total[row[i]] != 0)total[row[i]]--;
//				}
//			} 
//			line[list] = k; 
//			total[k] = n;
//		}
//	}
//    for (int k = 1; k <= c; k++) {
//        if (total[k] > 0) {
//            printf("%d %d\n", k, total[k]);
//        }
//    }	 
//    free(line);
//    free(row);
//	free(total); 
//	return 0;
//} 
//时间超限 
//#include <stdio.h>
//
//typedef struct{
//	int f,i,k;
//}operation;
//
//int main(){
//	operation ope[100001];
//	int row[10001] = {0},line[10001] = {0},color[1001];
//	int n,m,c,t;
//	scanf("%d %d %d %d",&n,&m,&c,&t);
//	for(int i = 0;i < t;i++){
//		scanf("%d %d %d",&ope[i].f,&ope[i].i,&ope[i].k);
//	}
//	int brush_row = 0, brush_col = 0;
//	for(int i = t - 1;i >= 0;i--){
//		if(!ope[i].f){
//			if(!row[ope[i].i]){
//				row[ope[i].i] = 1;
//				brush_row++;
//				color[ope[i].k] += (m - brush_col);
//			}
//		}else{
//			if(!line[ope[i].i]){
//				line[ope[i].i] = 1;
//				brush_col++;
//				color[ope[i].k] += (n - brush_row);
//			}
//		}
//	}
//	for (int i = 1; i <= c; i++) {
//		if (color[i]) {
//			printf("%d %d\n", i, color[i]);
//		}
//	}
//	return 0;
//} 
//问题 I: 四位数
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h> 
//#include <stdbool.h>
////升序排序 
//int compare_left(const void *a,const void *b){
//	char str1 = *(const char *)a;
//	char str2 = *(const char *)b;
//	return (str1 > str2) ? 1 : (str1 < str2) ? -1 : 0; 
//}
////降序排序 
//int compare_right(const void *a,const void *b){
//	char str1 = *(const char *)a;
//	char str2 = *(const char *)b;
//	return (str1 < str2) ? 1 : (str1 > str2) ? -1 : 0; 
//} 
//bool verify(char *str){
//	int len = strlen(str);
//	for(int i = 1;i < len;i++){
//		if(str[i - 1] != str[i]){
//			return false;
//		}
//	}
//	return true;
//}
////反转 
//void reverseString(char* str) {
//    int len = strlen(str);
//    for (int i = 0; i < len / 2; i++) {
//        char temp = str[i];
//        str[i] = str[len - 1 - i];
//        str[len - 1 - i] = temp;
//    }
//}
////相加 
//void add(char *a,char *b){
//	int len_b = strlen(b);
//	int len_a = strlen(a);
//	int len = len_b > len_a ? len_a : len_b;
//	int s = 0,add;
//	for(int i = 0;i < 4;i++){
//		add = s + a[i] + b[i] - '0' * 2;
//		s = add / 10;
//		a[i] = add % 10 + '0';
//	}
//	reverseString(a); 
//}
//
//int main(){
//	int T = 0;
//	scanf("%d",&T);
//	while(T--){
//		char number_left[100],number_right[100];
//		scanf("%s",number_left);
//		//处理第一次满足情况 
//		if(verify(number_left)){
//			printf("0\n");
//			continue;
//		}
//		int len = 4;
//		int num,count = 0;
//		while(1){
//			count++;
//			strcpy(number_right,number_left);
//			qsort(number_left,len,sizeof(char),compare_left);
//			qsort(number_right,len,sizeof(char),compare_right);
//			add(number_left,number_right);
//			if(verify(number_left)){
//				printf("%d\n",count);
//				break;
//			}
//		}
//	}
//} 

//问题 K: 冰墩墩和冰壶
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <math.h>
//
//
//int compare(const void *a,const void *b){
//    double num1 = *(const double *)a;
//    double num2 = *(const double *)b;
//    return (num1 > num2) ? 1:(num1 < num2) ? -1 : 0;
//}
//
//int main(){
//    int T = 0;
//    scanf("%d",&T);
//    while(T--){
//            int t = 0;
//            double distance_R[30] = {0},distance_Y[30] = {0};
//            int R_index = 0,Y_index = 0;
//            char part;
//            scanf("%d",&t);
//                    
//            while(t--){
//                    double x,y;
//                    scanf(" %c %lf %lf",&part,&x,&y);
//                    if(part == 'Y'){
//                            distance_Y[Y_index++] = sqrt(x * x + y * y);
//                    }else{
//                            distance_R[R_index++] = sqrt(x * x + y * y);
//                    }                               
//            }
//            
//            qsort(distance_R,R_index,sizeof(double),compare);
//            qsort(distance_Y,Y_index,sizeof(double),compare);
//            
//            int count = 0;
//            
//            if(distance_R[0] <= distance_Y[0]){
//                    printf("Win ");
//        for(int i = 0; i < R_index; i++){
//            if(distance_R[i] < distance_Y[0]) count++;
//            else break; 
//        }
//                    printf("%d\n",count);
//            }else{
//                    printf("Lose ");
//        for(int i = 0; i < Y_index; i++){
//            if(distance_Y[i] < distance_R[0]) count++;
//            else break;
//        }
//                    printf("%d\n",count);
//            }       
//    }
//    return 0;
//}
