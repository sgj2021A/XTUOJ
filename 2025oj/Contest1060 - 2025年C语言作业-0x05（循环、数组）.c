//问题 A: 前缀和
//#include <stdio.h>
//int main(){
//	long long arr[100001]={};
//	int a,b;
//	scanf("%d %d",&a,&b);
//	for(int i=0;i<a;i++){
//		scanf("%lld",&arr[i]);
//	}
//	int l,r,d;
//	for(int j=0;j<b;j++){
//		scanf("%d %d %d",&l,&r,&d);
//		for(int i=l-1;i<r;i++){
//			arr[i]+=d;
//		}
//	}
//	int add=0;
//	for(int j=0;j<a;j++){
//		add+=arr[j];
//		printf("%d ",add);
//	}
//	return 0;
//}
//时间超限(差分法)
//#include <stdio.h>
//int main(){
//	int arr[100001]={};
//	int arr1[100002]={};
//	int a,b;
//	scanf("%d %d",&a,&b);
//	for(int i=0;i<a;i++){
//		scanf("%d",&arr[i]);
//	}
//	arr1[0]=arr[0];
//	for(int i=1;i<a;i++){
//		arr1[i]=arr[i]-arr[i-1];
//	}
//	arr1[a] = 0;
//	int l,r,d;
//	for(int j=0;j<b;j++){
//		scanf("%d %d %d",&l,&r,&d);
//		arr1[l - 1] += d;
//        if (r < a) {
//            arr1[r] -= d;
//        } else {
//            arr1[a] -= d;
//        }
//	}
//	arr[0] = arr1[0];
//	for (int i = 1; i < a; i++) {
//	    arr[i] = arr[i-1] + arr1[i];
//	}
//	long long add=0;
//	for(int j=0;j<a;j++){
//		add+=arr[j];
//		printf("%lld ",add);
//	}
//	return 0;
//}

//问题 B: Colombian Number
//#include <stdio.h>
//#include <stdbool.h>
//int digitSum(int num) {
//	int sum = 0;
//	while (num>0) {
//		sum+=num%10;
//		num/=10;
//	}
//	return sum;
//}
//bool isSelfNumber(int n) {
//	for (int m = n - 100; m < n; m++) {
//		if (m <= 0) continue;
//		if (m + digitSum(m) == n) {
//			return false;
//		}
//	}
//	return true;
//}
//
//int main() {
//	int T, n;
//	scanf("%d", &T);
//	while (T--) {
//		scanf("%d", &n);
//		if (isSelfNumber(n)) {
//			printf("Yes\n");
//		} else {
//			printf("No\n");
//		}
//	}
//	return 0;
//}

//问题 C: 项链
//#include <stdio.h>
//#include <string.h>
//#include <stdbool.h>
//
//bool change(int n1[], int n2[], int size, int N) {
//    if (N < 0 || N >= size) {
//        return false;
//    }
//    int target = n2[N];
//    int position = -1;
//    for (int i = 0; i < size; i++) {
//        if (n1[i] == target) {
//            position = i;
//            break;
//        }
//    }
//    if (position == -1) {
//        return false;
//    }
//    while (n1[0] != target) {
//        int temp = n1[size - 1]; 
//        for (int i = size - 1; i > 0; i--) {
//            n1[i] = n1[i - 1]; 
//        }
//        n1[0] = temp; 
//    }
// 
//    return true;
//}
//bool 
//int main(){
//	int T;
//	int number1[1001],number2[1001];
//	scanf("%d",&T);
//	while(T--){
//		int size;
//		scanf("%d",&size);
//		for(int i=0;i<size;i++){
//			scanf("%d",number1[i]);
//		}
//		for(int i=0;i<size;i++){
//			scanf("%d",number2[i]);
//		}		
//	}
//}
//优化
//#include <stdio.h>
//#define MAXN 1000
//
//int main() {
//    int T, n, A[MAXN], B[MAXN], A_reversed[MAXN];
//    scanf("%d", &T);
//    
//    while (T--) {
//        scanf("%d", &n);
//        for (int i = 0; i < n; i++) scanf("%d", &A[i]);
//        for (int i = 0; i < n; i++) scanf("%d", &B[i]);
//        
//        int found = 0;
//        // 检查原始序列的旋转
//        for (int k = 0; k < n; k++) {
//            int match = 1;
//            for (int i = 0; i < n; i++) {
//                if (A[(i + k) % n] != B[i]) {
//                    match = 0;
//                    break;
//                }
//            }
//            if (match) {
//                found = 1;
//                break;
//            }
//        }
//        if (found) {
//            printf("Yes\n");
//            continue;
//        }
//        // 生成翻转序列并检查其旋转
//        for (int i = 0; i < n; i++) A_reversed[i] = A[n-1-i];
//        for (int k = 0; k < n; k++) {
//            int match = 1;
//            for (int i = 0; i < n; i++) {
//                if (A_reversed[(i + k) % n] != B[i]) {
//                    match = 0;
//                    break;
//                }
//            }
//            if (match) {
//                found = 1;
//                break;
//            }
//        }
//        printf(found ? "Yes\n" : "No\n");
//    }
//    return 0;
//} 

//问题 D: 7的倍数
//#include <stdio.h>
//#include <string.h>
//#include <stdbool.h> 
//
//// 高精度除法：大整数除以7，返回商
//char* divideBy7(const char* numStr) {
//    int len = strlen(numStr);
//    char* result = (char*)malloc((len + 1) * sizeof(char));
//    result[len] = '\0';
//    
//    int remainder = 0;
//    int resultIndex = 0;
//    
//    for (int i = 0; i < len; i++) {
//        int digit = numStr[i] - '0';
//        int current = remainder * 10 + digit;
//        int quotient = current / 7;
//        remainder = current % 7;
//        
//        // 跳过前导零
//        if (quotient != 0 || resultIndex > 0) {
//            result[resultIndex++] = quotient + '0';
//        }
//    }
//    
//    // 如果结果为空（即被除数为0），返回"0"
//    if (resultIndex == 0) {
//        result[0] = '0';
//        result[1] = '\0';
//    } else {
//        result[resultIndex] = '\0';
//    }
//    
//    return result;
//}
//
//int bigNumMod(const char *numStr, int divisor) {
//    int remainder = 0;
//    for (int i = 0; numStr[i] != '\0'; i++) {
//        int digit = numStr[i] - '0'; 
//        remainder = (remainder * 10 + digit) % divisor;
//    }
//    return remainder;
//}
//
//bool Mod_7(const char *numStr){
//	if(bigNumMod(numStr,7) == 0){
//		return true;
//	}
//	return false;
//}
//
//void bigNumAdd(char *numStr,int number){//在这道题目中只涉及7
//	int add = numStr[strlen(numStr) - 1] - '0' + number;
//	int up = add / 10;
//	numStr[strlen(numStr) - 1] = '0' + add % 10;
//	int cs = strlen(numStr) - 2;
//	while(up != 0 && cs >= 0){;
//		add = numStr[cs] - '0' + up;
//		numStr[cs] = '0' + add % 10;		
//		up = add / 10;
//		cs--;
//	}
//	if(up > 0){
//		memmove(numStr + 1,numStr,strlen(numStr) + 1);
//		numStr[0] = up + '0';
//	}
//}
//
//int main(){
//	char number[100000] = {0};
//	char number_zero[100000] = {0};
//	char number_base[100000] = {0};  
//	while(scanf("%s",number) != EOF){
//		int count = 0;
//		number_zero[0] = '0';
//		number_zero[1] = '\0';//对0初始
//		number_base[0] = number [strlen(number) - 1];
//		number_base[1] = '\0'; //基础为原来的数的最后一位 
//		if(bigNumMod(number,7) == 0){//被7整除 
//			printf("0\n%s\n",number);
//			continue;
//		}
//		
//		while(1){
//			printf("%s   %s\n",number_zero,number_base);
//			if(strstr(number_base,number) != NULL && Mod_7(number_base)){
//				printf("%d\n%s\n",strlen(number_base) - strlen(number),number_base);
//				break;
//			}else if(strstr(number_zero,number) != NULL && Mod_7(number_zero)){
//				printf("%d\n%s\n",strlen(number_zero) - strlen(number),number_zero);
//				break;
//			}
//			bigNumAdd(number_base,7);
//			bigNumAdd(number_zero,7);
//		}		
//	}
//	return 0;
//}
//时间超时(输入太大了) 
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//
//int bigNumMod(const char *numStr, int divisor) {
//    int remainder = 0;
//    for (int i = 0; numStr[i] != '\0'; i++) {
//        int digit = numStr[i] - '0';
//        remainder = (remainder * 10 + digit) % divisor;
//    }
//    return remainder;
//}
//
//int main() {
//    char s[10010];
//    while (scanf("%s", s) != EOF) {
//        int L = strlen(s);
//        int R_s = bigNumMod(s, 7);
//        
//        int T_b[7], U_b[7], inv_U_b[7];
//        T_b[0] = 1;
//        for (int b = 1; b <= 6; b++) {
//            T_b[b] = (T_b[b-1] * 10) % 7;
//        }
//        
//        int index = L % 6;
//        if (index == 0) {
//            U_b[0] = 1;
//        } else {
//            U_b[0] = 1;
//            for (int i = 1; i <= index; i++) {
//                U_b[0] = (U_b[0] * 10) % 7;
//            }
//        }
//        for (int b = 1; b <= 6; b++) {
//            U_b[b] = (U_b[b-1] * 10) % 7;
//        }
//        
//        for (int b = 0; b <= 6; b++) {
//            int base = U_b[b];
//            int inv = 1;
//            for (int i = 0; i < 5; i++) {
//                inv = (inv * base) % 7;
//            }
//            inv_U_b[b] = inv;
//        }
//        
//        int pow10[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
//        char best_sol[100000] = "";
//        int best_a = -1;
//        
//        for (int k = 0; k <= 6; k++) {
//            for (int a = 0; a <= k; a++) {
//                int b = k - a;
//                if (a == 0 && b == 0) {
//                    if (R_s == 0) {
//                        if (strlen(best_sol) == 0 || strcmp(s, best_sol) < 0) {
//                            strcpy(best_sol, s);
//                            best_a = 0;
//                        }
//                    }
//                } else if (a == 0 && b > 0) {
//                    int end_B = pow10[b] - 1;
//                    for (int B = 0; B <= end_B; B++) {
//                        if ((R_s * T_b[b] + B) % 7 == 0) {
//                            char B_str[10];
//                            sprintf(B_str, "%0*d", b, B);
//                            char candidate[100000];
//                            strcpy(candidate, s);
//                            strcat(candidate, B_str);
//                            if (strlen(best_sol) == 0 || strcmp(candidate, best_sol) < 0) {
//                                strcpy(best_sol, candidate);
//                                best_a = 0;
//                            }
//                        }
//                    }
//                } else if (b == 0 && a > 0) {
//                    int end_A = pow10[a] - 1;
//                    for (int A = 0; A <= end_A; A++) {
//                        if ((A * U_b[0] + R_s) % 7 == 0) {
//                            char A_str[10];
//                            sprintf(A_str, "%0*d", a, A);
//                            char candidate[100000];
//                            strcpy(candidate, A_str);
//                            strcat(candidate, s);
//                            if (strlen(best_sol) == 0 || strcmp(candidate, best_sol) < 0) {
//                                strcpy(best_sol, candidate);
//                                best_a = a;
//                            }
//                        }
//                    }
//                } else {
//                    int end_B = pow10[b] - 1;
//                    for (int B = 0; B <= end_B; B++) {
//                        int required_A = (- R_s * T_b[b] - B) % 7;
//                        if (required_A < 0) required_A += 7;
//                        required_A = (required_A * inv_U_b[b]) % 7;
//                        int A = required_A;
//                        char A_str[10];
//                        sprintf(A_str, "%0*d", a, A);
//                        char B_str[10];
//                        sprintf(B_str, "%0*d", b, B);
//                        char candidate[100000];
//                        strcpy(candidate, A_str);
//                        strcat(candidate, s);
//                        strcat(candidate, B_str);
//                        if (strlen(best_sol) == 0 || strcmp(candidate, best_sol) < 0) {
//                            strcpy(best_sol, candidate);
//                            best_a = a;
//                        }
//                    }
//                }
//            }
//            if (strlen(best_sol) > 0) {
//                printf("%d\n%s\n", best_a, best_sol);
//                break;
//            }
//        }
//    }
//    return 0;
//}//还要改 60 

//QAQ无语了 
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int big_mod(char *num, int mod) {
//    int remainder = 0;
//    int len = strlen(num);
//    
//    for (int i = 0; i < len; i++) {
//        // 逐位处理：remainder = (remainder * 10 + (num[i] - '0')) % mod
//        remainder = (remainder * 10 + (num[i] - '0')) % mod;
//    }
//    
//    return remainder;
//}
//
//int main(){
//	char num[10001] = {0};
//	while(scanf("%s",num) != EOF){
//		int mod = big_mod(num,7);
//		if(mod == 0){
//			printf("%d\n%s",0,num);
//			continue;
//		}	
//		
//		printf("1\n%s",num); 
//		switch(mod){
//			case 1:printf("4\n");break;
//			case 2:printf("1\n");break;
//			case 3:printf("5\n");break;
//			case 4:printf("2\n");break;
//			case 5:printf("6\n");break;
//			case 6:printf("3\n");break;
//		} 
//	}
//	return 0;
//} 
//问题 E: Rotate Again
//#include <stdio.h>
//#include <stdlib.h>
//void m_c(int **map){//外层逆时针
//	int temp = map[0][0];
//	map[0][0] = map[0][1];
//	map[0][1] = map[0][2];
//	map[0][2] = map[0][3];
//	map[0][3] = map[1][3];
//	map[1][3] = map[2][3];
//	map[2][3] = map[3][3];
//	map[3][3] = map[3][2];
//	map[3][2] = map[3][1];
//	map[3][1] = map[3][0];
//	map[3][0] = map[2][0];
//	map[2][0] = map[1][0];
//	map[1][0] = temp;
//}
//
//void i_c(int **map){//内侧逆时针
//	int temp = map[1][1];
//	map[1][1] = map[1][2];
//	map[1][2] = map[2][2];
//	map[2][2] = map[2][1];
//	map[2][1] = temp;
//}
//
//int max_add(int **map){
//	int max = -1;
//	for(int i = 0; i < 3;i++){
//		for(int j = 0;j < 3;j++){
//			int count = map[i][j] + map[i + 1][j] +  map[i][j + 1] + map[i + 1][j + 1];
//			if(max < count){
//				max = count;
//			}
//		}
//	}
//	
//	return max;
//}
//
//int main()
//{
//	int k = 0;
//	scanf("%d", &k);
//	while(k--){
//		//动态申请数组
//        int **map = malloc(4 * sizeof(int *));
//        for (int i = 0; i < 4; i++) {
//            map[i] = malloc(4 * sizeof(int));
//        }
//        //输入测试样例
//		for(int i = 0;i < 4;i++){
//			for(int j = 0;j < 4;j++){
//				scanf("%d", &map[i][j]);
//			}
//		}
//		int max = -1;
//		for(int i = 0;i < 16;i++){
//			for(int j = 0;j < 4;j++){
//				int count = max_add(map);
//				if(max < count){
//					max = count;
//				}
//				i_c(map);
//			}
//			m_c(map);
//		}
//		//输出测试样例	
//		printf("%d\n",max);	
//		//释放内存
//        for (int i = 0; i < 4; i++) {
//            free(map[i]);
//        }
//        free(map);		
//	} 
// 	return 0;
//}

//问题 J: Robot(题目意思未理解)

//#include <stdio.h>
//#include <string.h>
// 
//char command[210];
//int len,numL,numR,numU,numD;
// 
//int main()
//{
//    while ( scanf("%s",command) != EOF)
//    {
//        len = strlen(command);
//        numL = numR = numU = numD = 0;
//        for (int i = 0; i < len; i ++)                      // 统计各指令数量
//        {
//            if (command[i] == 'L')       numL ++;
//            else if (command[i] == 'R')  numR ++;
//            else if (command[i] == 'U')  numU ++;
//            else                         numD ++;
//        }         //D指令改为L     此时U肯定要为0 (!U 与 U == 0 等效)
//        if      (numL+numD == numR && !numU)  puts("Yes");   // D指令替换成L指令
//        else if (numL+numU == numR && !numD)  puts("Yes");   // U指令替换成L指令
//        else if (numR+numD == numL && !numU)  puts("Yes");   // D指令替换成R指令
//        else if (numR+numU == numL && !numD)  puts("Yes");   // U指令替换成R指令
// 
//        else if (numU+numL == numD && !numR)  puts("Yes");   // L指令替换成U指令
//        else if (numU+numR == numD && !numL)  puts("Yes");   // R指令替换成U指令
//        else if (numD+numL == numU && !numR)  puts("Yes");   // L指令替换成D指令
//        else if (numD+numR == numU && !numL)  puts("Yes");   // R指令替换成D指令
//        else    puts("No");
//    }
//    return 0;
//}



//问题 F: 方程组
//#include <stdio.h>
//#include <math.h>
//int main(){
//	int k=0;
//	scanf("%d",&k);
//	while(k--){
//		long long n,m;
//		scanf("%lld %lld",&n,&m);
//		int found = 0;
//		int cs_i = (int)sqrt(m/2);
//		int cs_j = m/2;
//		for(long long i=0;i < cs_i + 2;i++){
//			for(long long j=i;j < cs_j + 2; j++){
//				if(i*i*i + j*j*j == n && i*i + j*j ==m){
//					printf("%lld %lld\n",i,j);
//					found = 1;
//					break;
//				}
//			}
//			if(found == 1){
//				break;
//			}
//		}
//		
//		if(found == 0){
//			printf("0\n");
//		}
//	}
//	return 0;
//}
//暴力时间超限（优化）+ 负数没有考虑 
//#include <stdio.h>
//#include <math.h>
//int main(){
//	long long n,m,k;
//	int found = 0;
//	scanf("%lld",&k);
//	while(k--){
//		scanf("%lld %lld",&n,&m);
//		found =0;
//		long long range_x = (long long)sqrt(m) + 1;
//		if(m == 0){
//			if(n == 0){
//				printf("0 0\n");
//			}else{
//				printf("0\n");	
//			} 
//			continue;
//		}
//		for(long long i = -range_x;i <= range_x;i++){
//			long long j2 = m - i * i;
//			if(j2 < 0)continue;
//			long long j = (long long)sqrt(j2);//这里开方只能开到正数 
//			if(j * j == j2){
//				if(i * i * i + j * j * j == n){
//					printf("%lld %lld\n",i,j);
//					found = 1;
//					break;
//				}
//            	if (i * i * i + (-j) * (-j) * (-j) == n) {
//                	printf("%lld %lld\n", i, -j);
//                	found = 1;
//            		break;
//        		}
//			}			
//		}
//		if(found == 0){
//			printf("0\n");
//		}
//	}
//	return 0;
//}

//问题 H: 数字
//#include <stdio.h>
//int sum(long long number){
//	long long cs = number;
//	int s = 0;
//	while(cs != 0){//计算数码和 
//		s += cs % 10;
//		cs /= 10;
//	}
//	return s;	
//}
//int main(){
//	int k=0;
//	scanf("%d",&k);
//	while(k--){
//		long long number,count = 0;
//		scanf("%lld",&number);
//		count = number;
//		while(count > 0){
//			int sum_count = sum (count);
//			if(sum_count > 0 && count % sum_count == 0){
//                printf("%lld\n", count);
//                break;				
//			}
//			count--;
//		}
//	}
//	return 0;
//} 
//错误点：题目要求的是给定一个整数n，在不小于n 即 1<= x <= n的数中是否有数为合理数
//	    不是有一个数x可以被n的合理数所整除 

//问题 I: 子序列
//#include <stdio.h>
//#include <string.h>
//int main(){
//	int k=0;
//	scanf("%d",&k);
//	while(k--){
//		char str1[201],str2[201],newstr[201]={0};
//		int c[26]={0};
//		scanf("%s %s",str1,str2);
//		int len1 = strlen(str1);
//		int len2 = strlen(str2);
//		for(int i = 0;i < len2;i++){
//			c[str2[i]-'A']++;
//		}
//		int cs = 0;
//		for(int i = 0;i < len1;i++){
//			if(c[str1[i]-'A'] != 0){
//				newstr[cs] = str1[i];
//				cs++;
//			}
//		}
//		if(strcmp(newstr,str2) == 0){
//			printf("Yes\n");
//		}else{
//			printf("No\n");
//		}
//	}
//	return 0;
//}
//双指针修改（错误点，会不知道提取多少次，如UULA 和UL U出现两次但是全部保留） 
//#include <stdio.h>
//#include <string.h>
//
//int main() {
//    int k;
//    scanf("%d", &k);
//    while (k--) {
//        char str1[201], str2[201];
//        scanf("%s %s", str1, str2);
//        
//        int len1 = strlen(str1);
//        int len2 = strlen(str2);
//        
//        int i = 0, j = 0;
//        
//        // 双指针法检查str2是否是str1的子序列
//        while (i < len1 && j < len2) {
//            if (str1[i] == str2[j]) {
//                j++;  // 匹配到str2的一个字符
//            }
//            i++;  // 继续遍历str1
//        }
//        
//        if (j == len2) {
//            printf("Yes\n");
//        } else {
//            printf("No\n");
//        }
//    }
//    return 0;
//} 

//问题 G: 欧拉函数
//#include <stdio.h>
//#include <stdbool.h>
//#include <math.h>
//bool isPrime(unsigned long long n) {
//    if (n < 2) return false;
//    if (n == 2) return true;
//    if (n % 2 == 0) return false; 
//    unsigned long long limit = (unsigned long long)sqrt(n);
//    for (int i = 3; i <= limit; i += 2) {
//        if (n % i == 0) {
//            return false; 
//        }
//    }
//    return true;
//}
//long long euler_phi(long long n) {
//    if (n == 1) return 0;
//    long long result = n;
//    for (long long i = 2; i * i <= n; i++) {
//        if (n % i == 0) {
//            result = result / i * (i - 1);
//            while (n % i == 0) {
//                n /= i;
//            }
//        }
//    }
//    if (n > 1) {
//        result = result / n * (n - 1);
//    }
//    return result;
//}
//
//int main() {
//    long long n;
//    while (scanf("%lld", &n) != EOF) {
//        if (n == 0) break;
//        printf("%lld\n", euler_phi(n));
//    }
//    return 0;
//}

//问题 K: 重量
//#include<stdio.h> 
//
//int compare(const void *a,const void *b){
//	return (*(int *)a - *(int *)b)
//}
//int main(){
//	int t=0;
//	scanf("%d",&t);
//	whlie(t--){
//		int size=0,arr[10001]={};
//		scanf("%d",&size);
//		for(int i=0;i<size;i++){
//			scanf("%d",&arr[i]);
//		}
//		qsort(arr,size,sizeof(int),compart);
//		int item=1,item_com=0;
//		while(item_com==0){
//			for(int i=0;i<=item;i++){
//				
//			}
//			item++;
//		}
//	}
//	return 0;
//}
//修正

//#include<stdio.h>
//#include <stdlib.h>
//#define TABLE_SIZE 10000
//typedef struct HashNode{
//	int value;
//	struct HashNode *next;
//}HashNode; 
//typedef struct HashTable{
//	HashNode *bucket[TABLE_SIZE];
//}HashTable;
//HashTable *createTable(){
//	HashTable *Table=(HashTable *)malloc(sizeof(HashTable));
//	for(int i=0;i<TABLE_SIZE;i++){
//		Table->bucket[i]=NULL;
//	}	
//	return Table;
//}
//unsigned int hash(const int value){
//	return value%TABLE_SIZE;
//}
//void insert_HT(HashTable *HT,int value){
//	unsigned int index = hash(value);
//	HashNode *newnode = (HashNode *)malloc(sizeof(HashNode));
//	newnode->value = value;
//	newnode->next = HT->bucket[index];
//	HT->bucket[index] = newnode;
//}
//int find(HashTable *HT,int value){
//	unsigned int index = hash(value);
//	HashNode *current = HT->bucket[index];
//	while(current){
//		if(current->value==value){
//			return 1;
//		}
//		current = current->next;
//	}
//	return -1;
//}
//void freeHashTable(HashTable *HT){
//	for(int i=0;i<TABLE_SIZE;i++){
//		HashNode *current = HT->bucket[i];
//		while(current){
//			HashNode *temp = current;
//			current=current->next;
//			free(temp);
//		}
//	}
//	free(HT);
//}
//int main(){
//	int k=0,arr[10001];
//	scanf("%d",&k);
//	while(k--){
//		int n;
//		scanf("%d",&n);
//		for(int i=0;i<n;i++){
//			scanf("%d",&arr[i]);
//		}
//		HashTable *HT=createTable();
//		int cs=0;
//		for(int i=0;i<n;i++){
//			for(int j=n-1;j>=0;j--){
//				cs=0;
//				for(int k=i;k<=j;k++){
//					cs+=arr[k];
//				}
//				insert_HT(HT,cs);
//			}
//		} 
//		int cs1=0;
//		while(1){
//			if(find(HT,cs1)==-1){
//				printf("%d",cs1);
//				break;
//			}
//			cs1++;
//		}
//		freeHashTable(HT);
//	}
//	return 0;
//}
//逻辑错误 逻辑错误：问题要求的是砝码放在天平同一边，即可以使用任何砝码的子集（不一定是连续的子数组）来称重。您的代码只计算了连续子数组的和，但砝码的子集和可能不是连续的。
//正确解法：贪心算法
//#include <stdio.h>
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//	    int n;
//	    scanf("%d", &n);
//	    long long S = 0;
//	    int found = 0;
//		for(int i=0;i<n;i++){
//			int a;
//			scanf("%d",&a);
//			if(found==1)continue;
//			if(a<=S+1){
//				S+=a;
//			}else{
//				printf("%lld\n",S+1);
//				found=1;
//			}
//		}
//		if(found==0){
//			printf("%lld\n",S+1);
//		}		
//    }
//    return 0;
//}


