//Contest1072 - 2025年C语言提前作业-0x11（位运算）
//问题 A: 位运算
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdint.h>
//
//int main(){
//	int k;
//	scanf("%d",&k);
//	
//	while(k--){
//	
//		uint64_t a,b,c;
//		scanf("%llu %llu %llu",&a,&b,&c);
//		
//		uint64_t result = 0;
//		int unfound = 0;
//		for(int i = 0;i < 64;i++){
//			int ai = (a >> i) & 1;
//			int bi = (b >> i) & 1;
//			int ci = (c >> i) & 1;
//			
//			if(ai == ci){
//				result &= ~(1ULL << i);
//			}else if(!(bi == ci)){
//				result |= (1ULL << i);
//			}else{
//				unfound = 1;
//				break;
//			}	
//		}
//		
//		if(unfound){
//			printf("-1\n");
//		}else{
//			printf("%llu\n",result);
//		}	
//	}
//	return 0;
//}
 
//----------------------------------------------
//问题 B: 礼物

//----------------------------------------------
//问题 C: Dice
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//void process(bool *num,int a,int b,int c){
//	//使用三颗筛子 
//	int num1 = a * 100 + b * 10 + c;
//	int num2 = a * 100 + c * 10 + b;
//	int num3 = b * 100 + a * 10 + c;
//	int num4 = b * 100 + c * 10 + a;
//	int num5 = c * 100 + a * 10 + b;
//	int num6 = c * 100 + b * 10 + a;
//	//使用两颗筛子
//	int num7 = a * 10 + b; 
//	int num8 = a * 10 + c;
//	int num9 = b * 10 + a;
//	int num10 = b * 10 + c;
//	int num11 = c * 10 + a;
//	int num12 = c * 10 + b;
//	//使用一颗筛子
//	int num13 = a;
//	int num14 = b;
//	int num15 = c; 
//	num[num1] = true;
//	num[num2] = true;
//	num[num3] = true;
//	num[num4] = true;
//	num[num5] = true;
//	num[num6] = true;
//	num[num7] = true;
//	num[num8] = true;
//	num[num9] = true;
//	num[num10] = true;
//	num[num11] = true;
//	num[num12] = true;
//	num[num13] = true;
//	num[num14] = true;
//	num[num15] = true;
//}
//int main(){
//	bool *num = (bool*)malloc(sizeof(bool) * 1000);
//	int k;
//	int a[6],b[6],c[6];
//	scanf("%d",&k);
//	
//	while(k--){
//		//input
//		for(int i = 0;i < 6;i++){
//			scanf("%d",a + i);
//		}
//		for(int i = 0;i < 6;i++){
//			scanf("%d",b + i);
//		}
//		for(int i = 0;i < 6;i++){
//			scanf("%d",c + i);
//		}
//		//test
////		printf("test\n");
////		for(int i = 0;i < 6;i++){
////			printf("%d ",a[i]);
////		}
////		printf("\n");
////		for(int i = 0;i < 6;i++){
////			printf("%d ",b[i]);
////		}
////		printf("\n");
////		for(int i = 0;i < 6;i++){
////			printf("%d ",c[i]);
////		}
////		printf("\ntest\n");		
//		//initialize
//		for(int i = 0; i < 1000;i++){
//			num[i] = false;
//		}
//		//process
//		for(int i = 0;i < 6;i++){
//			for(int j = 0;j < 6;j++){
//				for(int z = 0;z < 6;z++){
//					process(num,a[i],b[j],c[z]);
//				}			
//			}			
//		}
//		//statistics
//		int total = 0;
//		for(int i = 0;i < 1000;i++){
//			if(num[i]){
//				//printf("%d ",i); 
//				total++;	
//			}
//		}
//		printf("%d\n",total);
//	}
//	free(num);
//	return 0; 
//} 

//----------------------------------------------
//问题 F: 异或
//#include <stdio.h>
//int main(){
//	
//	unsigned int a[100],b[100];
//	unsigned int x[100];
//	int k;
//	scanf("%d",&k);
//	
//	while(k--){
//		int n,index = 0;
//		scanf("%d",&n);
//		for(int i = 0;i < n;i++){
//			scanf("%u",a + i);	
//		}
//		for(int i = 0;i < n;i++){
//			scanf("%u",b + i);	
//		}
//		unsigned int temp = 0;
//		for(int i = 0;i < n;i++){
//			temp = a[i] ^ b[i];
//			for(int j = 0;j < n;j++){
//				if((a[j] ^ temp) != b[j]){
//					break;
//				}else if(j == n - 1){
//					x[index++] = temp;
//				}
//			}		
//		}
//		unsigned int min = 0xFFFFFFFF;
//		
//		for(int i = 0;i < index;i++){
//			if(min > x[i])min = x[i];
//		}
//		
//		printf("%u\n",min);		
//	} 
//	
//	return 0;
//}
//实际上 a[j] ^ temp 可能等于 b 中的任何一个元素，不一定是按顺序对应的 b[j]
//#include <stdio.h>
//int main(){
//	
//	unsigned int a[100],b[100];
//	unsigned int x[100];
//	int k;
//	scanf("%d",&k);
//	
//	while(k--){
//		int n,index = 0;
//		scanf("%d",&n);
//		for(int i = 0;i < n;i++){
//			scanf("%u",a + i);	
//		}
//		for(int i = 0;i < n;i++){
//			scanf("%u",b + i);	
//		}
//		unsigned int temp = 0;
//		for(int i = 0;i < n;i++){
//			temp = a[0] ^ b[i];  // 用a[0]作为基准，避免重复测试
//			int valid = 1;
//			for(int j = 0;j < n;j++){
//				unsigned int transformed = a[j] ^ temp;
//				int found = 0;
//				for(int k = 0;k < n;k++){
//					if(transformed == b[k]){
//						found = 1;
//						break;
//					}
//				}
//				if(!found){
//					valid = 0;
//					break;
//				}
//			}
//			if(valid){
//				x[index++] = temp;
//			}
//		}
//		unsigned int min = 0xFFFFFFFF;
//		
//		for(int i = 0;i < index;i++){
//			if(min > x[i])min = x[i];
//		}
//		
//		printf("%u\n",min);		
//	} 
//	
//	return 0;
//}
//----------------------------------------------
//问题 E: Bob's Password
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>
//#include <math.h>
//
//typedef struct{
//	int x,y;
//}vector2;
//
//void set(vector2 *location,char str){
//	if(str == '1'){
//		location->x = 1;
//		location->y = 1;
//	}else if(str == '2'){
//		location->x = 2;
//		location->y = 1;
//	}else if(str == '3'){
//		location->x = 3;
//		location->y = 1;
//	}else if(str == '4'){
//		location->x = 1;
//		location->y = 2;
//	}else if(str == '5'){
//		location->x = 2;
//		location->y = 2;
//	}else if(str == '6'){
//		location->x = 3;
//		location->y = 2;
//	}else if(str == '7'){
//		location->x = 1;
//		location->y = 3;
//	}else if(str == '8'){
//		location->x = 2;
//		location->y = 3;
//	}else if(str == '9'){
//		location->x = 3;
//		location->y = 3;
//	}	
//}
//
//int main(){
//	int k;
//	char str[10];
//	
//	scanf("%d",&k);
//	
//	while(k--){
//		bool password[4][4] = {false};
//		int index = 0;
//		scanf("%s",str);
//		int len = strlen(str);
//		//password [x][y]
//		vector2 *pw = (vector2*)malloc(sizeof(vector2) * len);
//		for(int i = 0;i < len;i++){
//			set(&pw[i],str[i]);
//		}
//		
//		password[pw[0].x][pw[0].y] = true;
//		bool unfound = false;
//		for(int i = 1;i < len;i++){
//			//同行或同列 
//			bool y_line = false;
//			bool x_line = false;
//			if(pw[i - 1].x == pw[i].x && abs(pw[i - 1].y - pw[i].y) == 2){
//				x_line = true;
//			}
//			if(pw[i - 1].y == pw[i].y && abs(pw[i - 1].x - pw[i].x) == 2){
//				y_line = true;
//			}
//			
//			if(abs(pw[i - 1].x - pw[i].x) == 2 && abs(pw[i - 1].y - pw[i].y) == 2){
//				y_line = true;
//				x_line = true;
//			}			
//			if(x_line && y_line){
//				if(!password[2][2]){
////					printf("x*y x:%d y:%d num:%c\n",pw[i].x,pw[i].y,str[i]); 
////					printf("x:%d y:%d num:%c\n",pw[i - 1].x,pw[i - 1].y,str[i - 1]); 
//					unfound = true;
//					break;
//				} 
//			}else if(x_line){
//				if(!password[pw[i].x][2]){
////					printf("x x:%d y:%d num:%c\n",pw[i].x,pw[i].y,str[i]); 
////					printf("x:%d y:%d num:%c\n",pw[i - 1].x,pw[i - 1].y,str[i - 1]);
//					unfound = true;
//					break;
//				} 
//			}else if(y_line){
//				if(!password[2][pw[i].y]){
////					printf("y x:%d y:%d num:%c\n",pw[i].x,pw[i].y,str[i]); 
////					printf("x:%d y:%d num:%c\n",pw[i - 1].x,pw[i - 1].y,str[i - 1]);
//					unfound = true;
//					break;
//				} 				
//			}
//			
//			password[pw[i].x][pw[i].y] = true;
//		}
//		
//		if(unfound){
//			printf("No\n");
//		}else{
//			printf("Yes\n");
//		}
//		free(pw);
//	}
//	
//	return 0;
//}
//----------------------------------------------
//问题 D: Unique Digit Number
//#include <stdlib.h>
//#include <stdio.h>
//#include <stdbool.h>
//int main(){
//	int statistics[10] = {10,9,9,9,9,9,9,9,9,9};
//	int pre[10] = {0}; 
//	for(int i = 1;i < 10;i++){
//		for(int j = 9;j >= 10 - i;j--){
//			statistics[i] *= j;
//		}
//	}
//	pre[0] = statistics[0];
//	for(int i = 1;i < 10;i++){
//		for(int j = 9;j >= 10 - i;j--){
//			pre[i] = statistics[i] + pre[i - 1];
//		}
//	}	
//	//test
//	for(int i = 0;i < 10;i++){
//		printf("%llu ",statistics[i]);
//	}	
//	printf("\n");
//	for(int i = 0;i < 10;i++){
//		printf("%llu ",pre[i]);
//	}	
//	printf("\n");
//	//test	
//	unsigned long long *num = (unsigned long long*)malloc(sizeof(unsigned long long) * (pre[9] + 2));  
//	int index = 1;
//	for(int i = 0;i <= 9;i++){
//		num[index++] = i;
//	}
//	unsigned long long pow_10 = 1;
//	for(int i = 1;i < 3;i++){
//		pow_10 *= 10;
//		int location;
//		if(i == 1){
//			location = 1;
//		}else{
//			location = pre[i - 2] + 1;
//		}
//		for(;location < pre[i - 1] + 1;location++){ 
//			bool total_num[10] = {false};
//			
//			unsigned long long temp = num[location];
//			 
//			while(temp / 10 != 0){
//				total_num[temp % 10] = true;
//				temp /= 10;
//			}
//			total_num[temp] = true;
//			
//			for(int z = 1;z < 10;z++){
//				if(!total_num[z]){
//					num[index++] = num[location] + z * pow_10;
//					printf("test num : %llu temp : %llu location : %d statistics : %d\n",num[location] + z * pow_10,num[location],location,statistics[i - 1]);	
//				}
//			}
//		}
//	}
//	//test 
//	for(int i = 1;i <= pre[2];i++){
//		printf("%llu ",num[i]);
//	}		
//	printf("\n");
//	//test
//	
//	int n;
//	while(scanf("%d",&n) != EOF){
//		printf("%llu\n",num[n]);
//	}
//	free(num);
//	return 0;	
//}
//算法修正 遗漏的3位数（包含0且0不在首位）
//#include <stdio.h>
//
//// 计算排列数 P(n, k)
//long long P(int n, int k) {
//    if (k > n) return 0;
//    long long r = 1;
//    for (int i = 0; i < k; i++) {
//        r *= (n - i);
//    }
//    return r;
//}
//
//// 找到第n个数位不同的数
//long long f(long long n) {
//    if (n <= 10) return n - 1;
//    
//    long long cnt = 10;  // 一位数的数量
//    int d = 2;           // 从两位数开始
//    
//    // 找到n所在的位数区间
//    while (d <= 10) {
//        long long now = 9 * P(9, d - 1);
//        if (n <= cnt + now) break;
//        cnt += now;
//        d++;
//    }
//    
//    // 在当前位数区间内的位置
//    long long pos = n - cnt - 1;
//    
//    // 构建数字
//    long long ans = 0;
//    int u[10] = {0};  // 标记已使用的数字
//    
//    for (int i = 0; i < d; i++) {
//        // 计算当前位的排列数
//        long long seg = P(9 - i, d - i - 1);
//        
//        // 尝试每个可能的数字
//        for (int num = (i == 0) ? 1 : 0; num <= 9; num++) {
//            if (u[num]) continue;
//            
//            if (pos < seg) {
//                ans = ans * 10 + num;
//                u[num] = 1;
//                break;
//            } else {
//                pos -= seg;
//            }
//        }
//    }
//    
//    return ans;
//}
//
//int main() {
//    long long n;
//    while (scanf("%lld", &n) != EOF) {
//        printf("%lld\n", f(n));
//    }
//    return 0;
//}
//这段代码的核心思路是基于组合数学的排列计数和分治定位的方法来高效求解第n个数位不同的数。
//整体思路：首先通过排列计算确定目标数字的位数，然后在该位数区间内逐位构建数字。对于每一位，计算选择每个可用数字后剩余位数的排列数，用位置索引来导航到正确的数字分支。
//位数确定：从1位数开始累加各区间数量（1位：10个，2位：81个，3位：648个...），找到包含第n个数的位数区间
//位置计算：计算目标数在该位数区间内的相对位置（从0开始）
//逐位构建：对于每一位：
//计算排列数 P(9-i, d-i-1)，表示选择当前数字后剩余位数的可能组合数
//遍历可用数字（第一位排除0），用位置索引选择正确的数字分支
//减去已跳过的排列数，更新位置索引
//标记已使用数字确保数位不同
//对于 n = 8000000，算法的推理过程如下：
//通过计算各区间累计数量发现，8000000 大于9位数的累计值5611771且小于等于10位数的累计值8877691，因此确定目标是一个10位数。
//在10位数区间内的位置为 8000000 - 5611771 - 1 = 2388228（从0开始计数）
//第一位：在1-9中选择，每个数字对应362880种后续排列。位置2388228落在数字7的范围内，确定第一位为7
//第二位：在剩余数字中选择，每个数字对应40320种排列。位置210948落在数字5的范围内，确定第二位为5
//依此类推，通过不断更新位置索引和排除已用数字，最终得到完整数字7518963024
//----------------------------------------------
//问题 H: Beautiful Number
//#include <stdio.h>
//#include <stdlib.h>
//
//int compare(const void *a, const void *b) {
//    // 降序排序：b - a
//    if (*(unsigned long long *)b > *(unsigned long long *)a) return 1;
//    else if (*(unsigned long long *)b < *(unsigned long long *)a) return -1;
//    else return 0;
//}
//
//int main(){
//	unsigned long long num[4000] = {0};
//	
//	unsigned long long n = 0;
//	
//	int index = 0;
//	
//	for(int i = 2;i <= 64;i++){
//		//初始化前 i 位置为 1
//		for(int j = 0;j < i;j++){
//			n |= (1ULL << j);
//		} 
//		
//		for(int j = 0;j < i - 1;j++){
//			n &= ~(1ULL << j);
//			num[index++] = n;
//			n |= (1ULL << j);
//		}
//	}
//	
//	qsort(num,index,sizeof(unsigned long long),compare);
//	int k;
//	scanf("%d",&k);
//	
//	while(k--){
//		unsigned long long start,end;
//		scanf("%llu %llu",&start,&end);
//		int total = 0;
//		for(int i = 0;i < index;i++){
//			if(num[i] >= start && num[i] <= end)total++;
//		}
//		printf("%d\n",total);
//	}
//	
//	return 0;
//}

//----------------------------------
//问题 G: 异或三元组

//#include <stdio.h>
//#include <stdbool.h>
//#define RANGE 10001
////long long res[RANGE];
////int main(){
////	//预处理
////	long long result = 0;
////	for(int i = 1;i < RANGE - 2;i++){
////		for(int j = i + 1;j < RANGE - 1;j++){
////			int num = i ^ j;
////			if(num > j && num < RANGE)res[num]++;
////		}
////	}
////	for(int i = 1;i < RANGE;i++)res[i] = res[i - 1] + res[i];
////	
////	int T;
////	scanf("%d",&T);
////	while(T--){
////		int n;
////		scanf("%d",&n);
////		printf("%lld\n",res[n]);
////	}
////	return 0;
////}
////int main(){
////	for(int n = 3;n <= 100;n++){
////		long long result = 0;
////		for(int i = 1;i <= n - 2;i++){
////			for(int j = i + 1;j <= n - 1;j++){
////				if(process(i,j,n))result++;
////			}
////		}
////		printf("n : %lld res : %lld\n",n,result);
////	}	
////	return 0;
////}
//#include <stdio.h>
//#include <math.h>
//
//long long process(int n) {
//    if (n < 3) return 0;
//    
//    // 计算 m = floor(log2(n))
//    int m = 0;
//    while ((1 << m) <= n) {
//        m++;
//    }
//    m--;  // 因为上面循环结束时，1<<m > n
//    
//    long long pow_2m = 1LL << m;  // 2^m
//    long long pow_2m_1 = 1LL << (m - 1);  // 2^(m-1)
//    long long pow_22m_1 = 1LL << (2 * m - 1);  // 2^(2m-1)
//    
//    // 计算 S(m) = (2^(2m-1) - 3*2^(m-1) + 1) / 3
//    long long S = (pow_22m_1 - 3 * pow_2m_1 + 1) / 3;
//    
//    // 如果 n 正好是 2^m
//    if (n == pow_2m) {
//        return S;
//    }
//    
//    // 否则计算 k = n - 2^m
//    long long k = n - pow_2m;
//    return S + k * (k + 1) / 2;
//}
//int main(){
//	int T;
//	scanf("%d",&T);
//	while(T--){
//		int n;
//		scanf("%d",&n);
//		long long res = process(n);
//		printf("%lld\n",res);
//	}
//	return 0;
//}
