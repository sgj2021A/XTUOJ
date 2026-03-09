//问题 A: Fibonacci
//#include <stdio.h>
//long long fib[50];
//int count;
//int bin_search(long long x) {
//    int left = 0, right = count - 1;
//    while (left <= right) {
//        int mid = (left + right) / 2;
//        if (fib[mid] == x) {
//            return 1;
//        } else if (fib[mid] < x) {
//            left = mid + 1;
//        } else {
//            right = mid - 1;
//        }
//    }
//    return 0;
//}
//
//int main() {
//    fib[0] = 1;
//    fib[1] = 2;
//    count = 2;
//    while (fib[count - 1] <= 1000000000) {
//        fib[count] = fib[count - 1] + fib[count - 2];
//        count++;
//    }
//
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        long long n;
//        scanf("%lld", &n);
//        int ans = 0;
//        for (int i = 0; i < count; i++) {
//            if (fib[i] > n) break;
//            for (int j = i; j < count; j++) {
//                if (fib[i] + fib[j] > n) break;
//                long long rest = n - fib[i] - fib[j];
//                if (rest < fib[j]) break;
//                if (bin_search(rest)) {
//                    ans++;
//                }
//            }
//        }
//        printf("%d\n", ans);
//    }
//    return 0;
//}

////问题 B: 身份证
//#include <stdio.h>
//#include <string.h>
//
//int main() {
//	int T;
//	scanf("%d",&T);
//	while(T--) {
//		char id[19];
//		scanf("%s",id);
//		int len = 18;
//		unsigned long long count = 0;
//		for(int i = 0; i < len - 1; i++) { //遍历前1-17个数
//			for(int j = 0; j <= 9; j++) { //遍历1-9
//				count = 0;
//				for(int k = 0; k < len - 1; k++) { //计算校验值
//					if(i == k) {
//						count += (j - '0')*(1ULL << 17-k);
//						continue;
//					}
//					count += (id[k] - '0')*(1ULL << 17-k);
//					if(id[17]=='X') {
//						count += 10*(1ULL << 17);
//					} else {
//						count += (id[17] - '0')*(1ULL << 0);
//					}
//					//计算完毕，输出
//					if(count % 11 == 1){
//	                    if (id[i] - '0' == j) {
//	                        printf("-");
//	                    } else {
//	                        printf("%d ", j);
//	                    }
//					}
//					break;
//				}
//			}
//		}
//		//遍历18位
//		for(int i = 0; i <= 10; i++) { //遍历最后一位 10表示X
//			count = 0;
//			for(int j = 0; j < 17; j++) {
//				count += (id[i] - '0')*(1ULL << 17 - j);
//			}
//			count += (i - '0')*(1ULL << 0);
//			if(count % 11 == 1) {
//				if(i == 10 && id[17] == 'X' || id[i] - '0' == i) {
//					printf("-");
//				} else {
//					if(i == 10) {
//						printf("X");
//					} else {
//						printf("%d",i);
//					}
//				}
//				break;
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
//修正
//#include <stdio.h>
//
//int main() {
//    // 预计算权重数组 w: w[i] = 2^i mod 11, for i in [0, 17]
//    //在身份证校验公式中，权重指的是每个数字位在计算校验和时所乘的系数。
//    int w[18];
//    w[0] = 1;
//    for (int i = 1; i < 18; i++) {
//        w[i] = (w[i-1] * 2) % 11;
//    }
//    // 预计算逆元数组 inv_w: inv_w[i] 是 w[i] 在模 11 下的乘法逆元
//    int inv_w[18];
//    for (int i = 0; i < 18; i++) {
//        int a = w[i];
//        // 使用费马小定理计算逆元: a^{-1} = a^9 mod 11, 因为 11 是质数
//        int inv = 1;
//        for (int j = 0; j < 9; j++) {
//            inv = (inv * a) % 11;
//        }
//        inv_w[i] = inv;
//    }
//
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        char id[19];
//        scanf("%s", id);
//        int S = 0;
//        // 计算当前身份证的校验和 S
//        for (int j = 0; j < 18; j++) {
//            int digit;
//            if (id[j] == 'X' || id[j] == 'x') {
//                digit = 10;
//            } else {
//                digit = id[j] - '0';
//            }
//            // 字符串索引 j 对应的指数为 17 - j
//            int exponent = 17 - j;
//            S = (S + digit * w[exponent]) % 11;
//        }
//        // 确保 S 在 [0, 10] 范围内
//        S %= 11;
//        if (S < 0) S += 11;
//
//        if (S == 1) {
//            // 校验通过，输出18个 '-'
//            for (int j = 0; j < 18; j++) {
//                putchar('-');
//            }
//            putchar('\n');
//        } else {
//            // 计算差值 delta = (1 - S) mod 11
//            int delta = (1 - S) % 11;
//            if (delta < 0) delta += 11;
//            // 遍历每个位置 j，计算正确值
//            for (int j = 0; j < 18; j++) {
//                int exponent = 17 - j; // 该位置对应的指数
//                int current_digit;
//                if (id[j] == 'X' || id[j] == 'x') {
//                    current_digit = 10;
//                } else {
//                    current_digit = id[j] - '0';
//                }
//                // 计算正确值 b = current_digit + delta * inv_w[exponent] mod 11
//                int b = (current_digit + delta * inv_w[exponent]) % 11;
//                if (b < 0) b += 11;
//                // 检查正确值 b 是否合法
//                if (j < 17) {
//                    // 前17位，b 必须在 0 到 9 之间
//                    if (b >= 0 && b <= 9) {
//                        putchar('0' + b);
//                    } else {
//                        putchar('-');
//                    }
//                } else {
//                    // 最后一位，b 可以在 0 到 10 之间
//                    if (b == 10) {
//                        putchar('X');
//                    } else if (b >= 0 && b <= 9) {
//                        putchar('0' + b);
//                    } else {
//                        putchar('-');
//                    }
//                }
//            }
//            putchar('\n');
//        }
//    }
//    return 0;
//}

//问题 C: 环
//方法贪心算法
//#include <stdio.h>
//#include <stdlib.h>
//int main(){
//	int T;
//	scanf("%d",&T);//输入测试样例个数
//	while(T--){
//		int size = 0;
//		scanf("%d",&size);
//		int *arr = (int *)malloc(sizeof(int) * size);
//		int *location = (int *)malloc(sizeof(int) * size);
//		for(int i = 0;i < size;i++){
//			*(location + i) = 0;//位置初始化
//		}
//		location[0] = 1;//第一位已经遍历
//		for(int i = 0;i < size;i++){
//			scanf("%d",arr + i);//测试样例输入
//		}
//		int forword = 0,back = 0, count = 0,now_location = 0,r_location = 0,l_location = 0;
//		for(int i = 0;i < size - 1;i++){
//			forword = 0;
//			back = 0;
//			for(int m = 1; ;m++){//扫描后面的值
//				forword += arr[(now_location + m - 1) % size];
//				if(location[(now_location + m) % size] == 0){
//					l_location = (now_location + m) % size;
//					break;
//				}
//			}
//			for(int m = 1; ;m++){//扫描前面的值
//				back += arr[((now_location - m) % size + size) % size];
//				if(location[((now_location - m) % size + size) % size] == 0){
//					r_location = ((now_location - m) % size + size) % size;
//					break;
//				}
//			}
//			now_location = forword <= back ? l_location : r_location;
//			location[now_location] = 1;
//			count += forword <= back ? forword : back;
//			//printf("location:%d left:%d right:%d\n",now_location,back,forword);
//		}
//		printf("%d\n",count);
//		free(arr);
//		free(location);
//	}
//}
//时间超限
//更改思路，把已经遍历过的地方直接删掉
//#include <stdio.h>
//#include <stdlib.h>
//int main(){
//	int T;
//	scanf("%d",&T);//输入测试样例个数
//	while(T--){
//		int size = 0;
//		scanf("%d",&size);
//		int *arr = (int *)malloc(sizeof(int) * size);
//		for(int i = 0;i < size;i++){
//			scanf("%d",arr + i);//测试样例输入
//		}
//		int leftLocation = 0;
//		int rightLocation = 0;
//		int count = 0;
//		long long right,left,total = 0;
//		int direction = -1;//0表示右边，1表示左边
//		for(int i = 0;i < size - 1;i++){
//			if(direction == 0){//上一步向右边移动
//				right = arr[rightLocation];
//				left = total + 	arr[size - leftLocation - 1];
//			}else{//上一步向左边移动
//				left = arr[size - leftLocation - 1];
//				right = total + arr[rightLocation];
//			}
//			if(left >= right){
//				rightLocation++;
//				total +=right;
//				count += right;
//				direction = 0;
//				printf(" -> ");
//			}else{
//				leftLocation++;
//				count += left;
//				total += left;
//				direction = 1;
//				printf(" <- ");
//			}
//			printf("left:%d right:%d locat_l:%d locat_r:%d\n",left,right,leftLocation,rightLocation);
//		}
//		printf("%d\n",count);
//		free(arr);
//	}
//	return 0;
//}
//优化(看不明白)
//#include <stdio.h>
//
//int main() {
//    int T;
//    scanf("%d", &T);  // 读取测试用例数量
//    while (T--) {
//        int n;
//        scanf("%d", &n);  // 读取数组大小
//        int a[n];
//        int S = 0;  // 数组元素总和
//        for (int i = 0; i < n; i++) {
//            scanf("%d", &a[i]);
//            S += a[i];  // 累加计算总和
//        }
//
//        // 特殊情况处理：当数组大小为3时
//        if (n == 3) {
//            // 计算四种可能的移除方案代价：
//            // option1: 移除a[2]，剩余a[0]和a[1]直接相连
//            // option2: 移除a[0]，剩余a[1]和a[2]直接相连
//            // option3/4: 移除a[1]，剩余a[0]和a[2]需要额外连接（环形结构导致）
//            int option1 = a[0] + a[1];
//            int option2 = a[1] + a[2];
//            int option3 = 2 * a[0] + a[2];
//            int option4 = 2 * a[2] + a[0];
//            int min = option1;
//            if (option2 < min) min = option2;
//            if (option3 < min) min = option3;
//            if (option4 < min) min = option4;
//            printf("%d\n", min);
//        } else {
//            // 通用情况处理（n>3）
//            long long pre[n + 1];  // 前缀和数组
//            pre[0] = 0;
//            // 构建前缀和数组：pre[i] = a[0]+a[1]+...+a[i-1]
//            for (int i = 1; i <= n; i++) {
//                pre[i] = pre[i - 1] + a[i - 1];
//            }
//
//            long long ans = S;  // 初始化最小代价为总和（最大可能值）
//            // 遍历每个可能的移除节点
//            for (int i = 0; i < n; i++) {
//                int u, v;  // 定义当前节点的左右邻居索引
//                // 环形结构处理：最后一个节点的邻居是首尾元素
//                if (i < n - 1) {
//                    u = i + 1;    // 右邻居
//                    v = i + 2;    // 右邻居的右邻居（用于某种计算）
//                } else {
//                    u = n;        // 特殊标记？需要结合后续逻辑分析
//                    v = 1;         // 环形结构的首元素索引
//                }
//
//                long long d1, d2;  // 定义两个距离变量
//                // 计算d1：与左邻居相关的某种距离
//                if (u == 1) {
//                    d1 = 0;  // 边界条件处理
//                } else {
//                    // 根据当前索引与u-1的关系计算d1
//                    // 可能是在计算左半部分的和或补集
//                    if (i < u - 1) {
//                        d1 = S - pre[u - 1];  // 右半部分和
//                    } else {
//                        d1 = pre[u - 1];      // 左半部分和
//                    }
//                }
//
//                // 计算d2：与右邻居相关的某种距离
//                if (v == 1) {
//                    d2 = 0;  // 边界条件处理
//                } else {
//                    // 根据当前索引与v-1的关系计算d2
//                    if (i < v - 1) {
//                        d2 = S - pre[v - 1];  // 右半部分和
//                    } else {
//                        d2 = pre[v - 1];      // 左半部分和
//                    }
//                }
//
//                long long max_d = d1 > d2 ? d1 : d2;  // 取两者较大值
//                // 关键代价计算：
//                // 2*(S - a[i]) 可能表示移除后剩余元素的两倍和
//                // 减去max_d可能是为了修正重复计算的边权
//                long long cost = 2 * (S - a[i]) - max_d;
//
//                // 更新最小代价
//                if (cost < ans) {
//                    ans = cost;
//                }
//            }
//            printf("%lld\n", ans);
//        }
//    }
//    return 0;
//}

//问题 D: 数码积性
//#include <stdio.h>
//#include <math.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#define MAX 10000000
//
//int NumAdd(int num){
//	int count = 0; 
//	while(num != 0){
//		count += num % 10;
//		num /= 10;
//	}
//	return count;
//}
//
//int main(){
//	int *num_add = (int *)malloc(sizeof(int) * (MAX + 1));//数码和数组
//	bool *num_can = (bool *)malloc(sizeof(bool) * (MAX + 1));//数字是否满足数码积性 
//	int  *prefix = (int *)malloc(sizeof(int) * (MAX + 1));//前缀和 
//	//处理数码和
//	for(int i = 1;i <= MAX;i++){
//		num_add[i] = NumAdd(i);
//	} 
//	//处理满足数码积的数字
//	for(int i = 1;i <= MAX;i++){
//		num_can[i] = false;//初始化所有都不满足 
//	}
//	for(int x = 2;x <= sqrt(MAX);x++){//枚举所有可能的数字
//		for(int y = x; y <= MAX / x;y++){
//			int n = x * y;
//			if(n > MAX)break;
//			if(num_add[n] == num_add[x] * num_add[y]){
//				num_can[n] = true;
//			}
//		} 
//	}
//	//构建前缀和数组
//	prefix[0] = 0;
//	for(int i = 1;i <= MAX;i++){
//		prefix[i] = prefix[i - 1];
//		if(num_can[i]){
//			prefix[i]++;
//		}
//	}
//	free(num_add);
//	free(num_can);
//	//主程序
//	int t = 0;
//	scanf("%d",&t);
//	while(t--){
//		int L,R;
//		scanf("%d %d",&L,&R);
//		printf("%d\n",prefix[R] - prefix[L - 1]);
//	}
//	free(prefix);	 
//}

//问题 E: 公共的数
//#include <stdio.h>
//long long gcd(long long a,long long b){
//	if(b==0){
//		return a;
//	}
//	return gcd(b,a%b);
//}
//int main(){
//	int T=0;
//	scanf("%d",&T);
//	while(T--){
//		int a,b,c,d;
//		scanf("%d %d %d %d",&a,&b,&c,&d);
//		if(a == 1 && c == 1){
//			long long g = gcd(b,d);
//			long long lcm = (long long)b * d / g;
//			if(lcm > 1000000000){
//				printf("0\n");
//			}else{
//				long long count = 1000000000 /lcm;
//				printf("%lld\n",count);
//			}
//		}else if(a == 1 && c > 1){
//			int count = 0;
//			long long y = 0;
//			for(int m=1; ; m++){
//				y = y * c + d;
//				if(y > 1000000000)break;
//				if(y % b == 0){
//					count++;
//				}
//			}
//			printf("%d\n",count);
//		}else if(c == 1 && a > 1){
//			int count = 0;
//			long long x = 0;
//			for(int m=1; ; m++){
//				x = x * a + b;
//				if(x > 1000000000)break;
//				if(x % d == 0){
//					count++;
//				}
//			}
//			printf("%d\n",count);
//		}else{
//			long long x_vals[100] = {0};
//			long long y_vals[100] = {0};
//			int x_count = 0;
//			int y_count = 0;
//			long long x = 0;
//			long long y = 0;
//			for(int m=0; ; m++){
//				x = x * a + b;
//				if(x > 1000000000)break;
//				x_vals[m] = x;
//				x_count++;
//			}
//			for(int m=0; ; m++){
//				y = y * c + d;
//				if(y > 1000000000)break;
//				y_vals[m] = y;
//				y_count++;
//			}
//			int count = 0;
//			for(int i = 0;i < x_count;i++){
//				for(int j = 0;j < y_count;j++){
//					if(x_vals[i]==y_vals[j]){
//						count++;
//						break;
//					}
//				}
//			}
//			printf("%d\n",count);
//		}
//	}
//	return 0;
//}

//问题 H: Repeat One
//number可以表示为：number = (10^m - 1)/9
//需要：(10^N - 1)/9 ≡ 0 (mod M)
//即：10^N ≡ 1 (mod 9M)
//无解情况：如果M能被2或5整除，那么无解
//有解情况：当gcd(9M,10)=1时，解存在(因为10=2*5，如果又最大公因数的话m可以被2或5整除)
//模拟除法
//(a + b) mod M = (a mod M + b mod M) mod M
//(a × b) mod M = (a mod M × b mod M) mod M

//#include<stdio.h>
//int main()
//{
//	int k,n,m,p,c;
//    scanf("%d",&k);
//    while(k--)
//    {
//        scanf("%d",&m);
//		if(m%2==0&&m%5==0)//由数码1组成的数一定不能被2和5整除。
//		{
//			printf("0\n");
//		}
//		else
//		{
//			n=1,p=m,c=0;
//			while(p--)
//		    {
//		        n=n%m;
//		        c++;
//		        if(n==0)
//		        break;
//		        else
//		        n=n*10+1;
//		    }
//		    if(n==0) printf("%d\n",c);
//		    else printf("0\n");
//		}
//	}
//	return 0;
//}

//问题 F: 两个数
#include <stdio.h>
#include <stdlib.h>
int main(){
	int n = 0;
	while(scanf("%d", &n) == 1){
		long long count = 0;
		long long *number = (long long*)malloc(sizeof(long long) * n);
		for(int i = 0;i < n;i++){
			scanf("%lld",&number[i]);
			count += number[i];
		}
		long long S =  count / (n - 2);
		if(S * (n-2) != count){
			printf("0\n");
			free(number);
			continue;
		}
		int total_up = 0;
		for(int i = 0;i < n;i++){
			if(number[i] > S){
				total_up++;
			}
		}
		free(number);
		if(total_up > 2){
			printf("0\n");
			continue;
		}
		if(total_up == 2){
			printf("1\n");
			continue;
		}		
		if(total_up == 1){
			printf("%d\n",n - 1);
			continue;
		}
		printf("%lld\n",n*(n-1)/2);
	}
}

//问题 G: Candy
//#include <stdio.h>
//#define P 1000000007
//
//int main(){
//      int N = 1;
//      while(N != 0){
//              long long ans = 0;
//              scanf("%d",&N);
//              if(N == 3){
//                      printf("1\n");
//                      continue;
//              }
//              for(int i = 1;i <= N;i++){
//                      for(int j = 1;j <= N;j++){
//                              if(i == j) continue;
//                              int sum_ij = i + j;
//                              if(sum_ij > N)continue;
//                              int sum_k = sum_ij % 3;
//                              for(int l = sum_k + sum_ij; l <= N; l+=3){
//                                      ans++;
//                              }
//                      }
//                      ans %= P;
//              }
//              printf("%lld\n",ans);
//      }
//}
//时间超限......(优化)
//1：三份 模3余数均为1 的 糖果；
//2：三份 模3余数均为2 的 糖果；
//3：三份 模3余数均为0 的 糖果；
//4：一份 模3余数为1 的 糖果 + 一份 模3余数为2 的 糖果 + 一份 模3余数为0 的 糖果。
//#include <stdio.h>
//#define Mod 1000000007
//long long compute(long long s){                         // 组合数公式 C(n,3)
//    return (s*(s-1)*(s-2)/6) % Mod;
//}
//
//int main()
//{
//    long long n,N = 1;
//    long long x,y,z;
//    long long ans1,ans2,ans3,ans;
//    while (1){
//        scanf("%lld",&N);
//        if(N == 0){
//            break;
//        }
//        x = N/3;                                // x:3的倍数的 个数
//        y = z = x;
//        n = N%3;
//        if (n == 1)y += 1;             // y:模3余1的数 的个数
//        else if (n == 2)y += 1, z += 1;     // z:模3余2的数 的个数
//        ans1 = compute(x);
//        ans2 = compute(y);
//        ans3 = compute(z);
//        ans = (ans1+ans2+ans3+x*y*z) % Mod;
//        printf("%lld\n",ans);
//    }
//    return 0;
//}

//问题 J: 奇怪的开关(DP算法) 
//E(m) = 1 + (n-m)/n * E(m+1) + m/n * E(m)
//变形得：E(m) = n/(n-m) + E(m+1)
//将问题建模为马尔可夫过程，其中状态表示当前亮灯的数量。每次按键随机选择一盏灯，如果灯是灭的则亮起（状态增加），否则状态不变。
//n / (n - m) 用几何分布求和 
//#include <stdio.h>
////最大公因数 
//long long gcd(long long a,long long b){
//	if(b == 0)return a;
//	return gcd(b,a%b);
//}
////最小公倍数 
//long long lcm(long long a,long long b){
//	return a / gcd(a,b) * b;
//}
////主程序
//int main(){
//	int T = 0;
//	scanf("%d",&T);
//	while(T--){//输入次数 
//		int n,m,k;
//		scanf("%d %d %d",&n, &m, &k);
//		//如果k == m是已经达到标准
//		if(k == m){
//			printf("0\n");
//			continue;
//		} 
//		//循环范围 
//		int L = n - k + 1;//几何分布求和最大值
//		int U = n - m;
//		//从初始状态 m 到目标状态 k,需要经过 k-m次状态增加
//		long long num = 0;
//		long long den = 1;
//		
//		for(int j = L;j <= U;j++){
//			long long new_den = lcm(den,j);
//			long long new_num = num * (new_den / den) + 1 * (new_den / j);
//			
//			long long g = gcd(new_num,new_den);
//			num = new_num / g;
//			den = new_den / g;
//		}
//		
//		num *= n;
//		long long g = gcd(num,den);
//		num /= g;
//		den /= g;
//		if(den == 1){
//			printf("%lld\n",num);
//		}else{
//			printf("%lld/%lld\n",num,den);
//		}
//	}
//	return 0;
//} 
