//Contest1067 - 2025年C语言提高-0x0C（贪心）

//问题 A: 聚会
//#include <stdio.h>
//#include <stdlib.h>
//
//int compare(const void *a, const void *b) {
//    return (*(int *)a - *(int *)b);
//}
//
//int main(){
//	int k = 0;
//	scanf("%d",&k);
//	
//	while(k--){
//		int n;
//		scanf("%d",&n);
//		
//		int *a =(int*)malloc(sizeof(int) * n);
//		
//		for(int i = 0;i < n;i++){
//			scanf("%d",&a[i]);
//		}
//		
//		qsort(a,n,sizeof(int),compare);
//		
//		int max = 1;
//		for(int i = 0;i < n;i++){
//			if(max >= a[i]){
//				max++;
//			}
//		}
//		
//		printf("%d\n",max - 1);
//		
//		free(a);	
//		
//	}
//	return 0;
//}

//-------------------------------------------
//问题 D: 数字（加强版）
//#include <string.h>
//#include <stdio.h>
//int main(){
//	int k = 0;
//	scanf("%d",&k);
//	while(k--){
//		char str[100001];
//		scanf("%s",str);
//		int len = strlen(str);
//		int total = 0;
//		for(int i = len - 1;i > 0;i--){
//			if(str[i] != '0'){
//				total += (str[i] - '0' + 1);
//			}else if(str[i] == '0' && i == len - 1){
//				total++;
//			}
//		}
//		total += str[0] - '0';
//		printf("%d\n",total);
//	} 
//} 
//--------------------------------------------
//问题 C: 扁担
//差的平方最小:在排序或优化问题中，最小化相邻元素之间差值的平方和。
//平滑排序：使排序后的序列尽可能“平滑”，避免相邻元素差异过大。
//#include <stdio.h>
//#include <stdlib.h>
//int compare(const void *a, const void *b) {
//    return (*(int *)a - *(int *)b);
//}
////升序排序 
//int main(){
//	int k = 0;
//	scanf("%d",&k);
//	while(k--){
//		int w;
//		//输入数据 
//		scanf("%d",&w);
//		w *= 2;
//		int *weight = (int*)malloc(sizeof(int) * w);
//		for(int i = 0;i < w;i++){
//			scanf("%d",&weight[i]);
//		}
//		//寻找当前最小
//		qsort(weight,w,sizeof(int),compare);
//		long long total = 0;
//		for(int i = 0;i < w ;i+=2){
//			long long temp = weight[i + 1] - weight[i];
//			total +=(temp * temp);
//		} 
//		printf("%lld\n",total);
//		free(weight);
//	}
//	return 0;
//}
//-----------------------------------------
//问题 B: 最小化
//#include <stdio.h>
//#include <string.h>
//int main(){
//	int w = 0;
//	scanf("%d",&w);
//	while(w--){
//		int n,k;
//		char a[1001];
//		scanf("%d %d",&n,&k);
//		scanf("%s",a);
//		if(n == 1 && k >= 1){
//			printf("0\n");
//			continue;
//		}
//		if(a[0] != '1'){
//			k--;
//		}
//		for(int i = 1;i < n && k > 0;i++){
//			if(a[i] > '0' && a[i] != a[0]){
//				for(int j = i + 1;j < n;j++){
//					if(a[j] == a[i]){
//						a[j] = '0';
//					}
//				}
//				a[i] = '0';
//				k--;
//			}
//		}
//		for(int i = 1;i < n;i++){
//			if(a[i] == a[0]){
//				a[i] = '1';
//			}
//		}
//		a[0] = '1';
//		printf("%s\n",a);
//	}
//}
//--------------------------------------
//问题 E: RGB
//#include <string.h>
//#include <stdio.h>
//void swap(char *a,char *b){
//	char temp = 0;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int main(){
//	int k;
//	scanf("%d",&k);
//	while(k--){
//		char a[10001],b[10001];
//		int total = 0;
//		scanf("%s %s",a,b);
//		int len = strlen(a);
//		for(int i = 1;i < len;i++){
//			if(a[i - 1] == b[i] || a[i - 1] != b[i - 1]){
//				swap(&a[i],&a[i - 1]);
//				total++;
//			}else if(a[i - 1] != b[i - 1]){
//				total++;
//			} 
//		}
//		if(a[len - 1] != b[len - 1]){
//			total++;
//		}
//		printf("%d\n",total);
//	}
//}
//问题：任意交换不是相邻交换
//直接交换对：当两个位置 i 和 j 满足 a[i] = b[j] 且 a[j] = b[i] 时，一次交换可以同时修正这两个位置。
//三元组循环：三个位置形成循环时（如 a[i] = b[j], a[j] = b[k], a[k] = b[i]），两次交换可以修正这三个位置。
//#include <stdio.h>
//#include <string.h>
//
//int min(int a, int b) {
//    return a < b ? a : b;
//}
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        char a[10001], b[10001];
//        scanf("%s %s", a, b);
//        int n = strlen(a);
//        int rg = 0, rb = 0, gr = 0, gb = 0, br = 0, bg = 0;
//        int diff = 0;
//        //统计所有不匹配位置中字符对的数量
//        for (int i = 0; i < n; i++) {
//            if (a[i] != b[i]) {
//                diff++;
//                if (a[i] == 'R' && b[i] == 'G') rg++;
//                else if (a[i] == 'R' && b[i] == 'B') rb++;
//                else if (a[i] == 'G' && b[i] == 'R') gr++;
//                else if (a[i] == 'G' && b[i] == 'B') gb++;
//                else if (a[i] == 'B' && b[i] == 'R') br++;
//                else if (a[i] == 'B' && b[i] == 'G') bg++;
//            }
//        }
//        // 计算可以直接交换的对数（一次交换修正两个位置）
//        int k1 = min(rg, gr) + min(rb, br) + min(gb, bg);
//        // 更新剩余的数量
//        int rg1 = rg - min(rg, gr);
//        int gr1 = gr - min(rg, gr);
//        int rb1 = rb - min(rb, br);
//        int br1 = br - min(rb, br);
//        int gb1 = gb - min(gb, bg);
//        int bg1 = bg - min(gb, bg);
//        // 计算三元组循环（两次交换修正三个位置）
//        int s = min(rb1, min(bg1, gr1)) + min(rg1, min(gb1, br1));
//        // 总操作次数 = 不匹配位置数 - 直接交换对 - 三元组循环
//		int result = diff - k1 - s;
//        printf("%d\n", result);
//    }
//    return 0;
//} 
//--------------------------------------------------
//问题 F: 组队_1
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
////升序排序 
//int compare(const void *a,const void *b){
//	return (*(int *)a - *(int *)b);
//}
//int main(){
//	int n;
//	scanf("%d",&n);
//	int *grade = (int *)malloc(sizeof(int) * (3 * n));
//	n *= 3;
//	for(int i = 0;i < n;i++){
//		scanf("%d",grade + i);
//	}
//	long long total = 0;
//	qsort(grade,n,sizeof(int),compare);
//	for(int i = 0;i < n;i += 3){
//		long long temp1 = grade[i] - grade[i + 1];
//		long long temp2 = grade[i + 1] - grade[i + 2];
//		total += (temp1 * temp1 + temp2 * temp2);
//	}
//	printf("%lld\n",total);
//	free(grade);
//	return 0;
//}
//-----------------------------------------------------
//问题 G: 游戏
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//int compare(const void *a,const void *b){
//    return (*(int *)a - *(int *)b);
//}
//
//bool repeat(int *a,int size_a,int *b,int size_b){
//    int min = size_a > size_b ? size_b : size_a;
//    for(int i = 0,j = 0;i < size_a && j <size_b;){
//        if(a[i] == b[j])return true;
//        if(a[i] < b[j]){
//            i++;
//        }else{
//            j++;
//        }
//    }
//    return false;
//}
//
//int bucket(int *a,int size,int n){
//    int total = 0;
//    bool *a_bucket = (bool *)malloc(sizeof(bool) * (n + 1));
//    for(int i = 0;i <= n ;i++){
//        a_bucket[i] = false;
//    }
//    for(int i = 0;i < size;i++){
//        a_bucket[a[i]] = true;
//    }
//    for(int i = 0;i <= n ;i++){
//        if(a_bucket[i]){
//            total++;
//        }
//    }
//    free(a_bucket);
//    return total;
//}
//
//int main(){
//    int s,n,m,k;
//    scanf("%d",&s);
//    while(s--){
//        scanf("%d %d %d",&n,&m,&k);
//        bool *block = (bool*)malloc(sizeof(bool) * (n + 1));
//        for(int i = 0;i <= n;i++)block[i] = false;
//        
//        int *arr_M = (int *)malloc(sizeof(int) * m);
//        int *arr_H = (int *)malloc(sizeof(int) * k);
//        for(int i = 0;i < m;i++){
//            scanf("%d",arr_M + i);
//        }
//        for(int i = 0;i < k;i++){
//            scanf("%d",arr_H + i);
//        }
//        
//        qsort(arr_M,m,sizeof(int),compare);
//        qsort(arr_H,k,sizeof(int),compare);
//        
//        // 统计公共数字和独占数字
//        int common = 0;
//        int only_M = 0;
//        int only_H = 0;
//        
//        // 创建桶来统计
//        bool *bucket_M = (bool *)malloc(sizeof(bool) * (n + 1));
//        bool *bucket_H = (bool *)malloc(sizeof(bool) * (n + 1));
//        for(int i = 0;i <= n;i++){
//            bucket_M[i] = false;
//            bucket_H[i] = false;
//        }
//        
//        for(int i = 0;i < m;i++){
//            bucket_M[arr_M[i]] = true;
//        }
//        for(int i = 0;i < k;i++){
//            bucket_H[arr_H[i]] = true;
//        }
//        
//        for(int i = 1;i <= n;i++){
//            if(bucket_M[i] && bucket_H[i]){
//                common++;
//            }else if(bucket_M[i] && !bucket_H[i]){
//                only_M++;
//            }else if(!bucket_M[i] && bucket_H[i]){
//                only_H++;
//            }
//        }
//        
//        // 计算双方能获得的公共数字
//        int M_common = (common + 1) / 2;  // 小明先手，能获得至少一半的公共数字
//        int H_common = common - M_common;
//        
//        // 计算双方总可用数字
//        int M_total = only_M + M_common;
//        int H_total = only_H + H_common;
//        
//        if(M_total > H_total){
//            printf("Ming\n");
//        }else{
//            printf("Hua\n");
//        }
//        //首先，双方都会先抢公共数字，因为公共数字是双方都能用的，如果不抢就会被对方用掉。所以公共数字的争夺是必然的。
//		//然后，当公共数字用完之后，双方只能使用自己独占的数字。
//        //游戏结束的条件是当前玩家无法操作（即没有空格子可以放他手中的牌）。注意，空格子是指编号1~n中还没有被放置的格子。而每个数字对应一个格子，所以一个数字能被放置的条件是：这个数字在1~n范围内，且这个格子还没有被放牌。
//		free(bucket_M);
//        free(bucket_H);
//        free(arr_M);
//        free(arr_H);
//        free(block);
//    }
//    return 0;
//}
//-------------------------------------
//问题 J: 加一
//#include <stdio.h>
//#include <stdlib.h>
//int main(){
//	int k;
//	scanf("%d",&k);
//	while(k--){
//		int n = 0;
//		long long aim = 0;
//		scanf("%d",&n);
//		long long *arr = (long long *)malloc(sizeof(long long) * n);
//		
//		for(int i = 0;i < n;i++){
//			scanf("%lld",arr + i);
//			if(i == 0){
//				aim = arr[i];
//			}else if(aim < arr[i]){
//				aim = arr[i];
//			}
//		}
//		
//		for(int i = 0;i < n;i++){
//			arr[i] = aim - arr[i];
//		}
//		
//		long long total = 0;
//		long long now = 0;
//		
//		for(int i = 0;i < n;i++){
//			if(arr[i] > now){
//				total += (arr[i] - now);
//				now = arr[i];
//			}else if(arr[i] < now){
//				now = arr[i];
//			}
//		}
//		
//		printf("%lld\n",total);
//		
//		free(arr);
//	}
//	return 0;
//}
//-------------------------------------------------------
//问题 I: 游戏
//#include <stdio.h>
//#include <stdlib.h>
//
//int compare(const void* a,const void* b){
//	return (*(long long *)b - *(long long *)a);
//}
//
//int main(){
//	int n,k;
//	scanf("%d %d",&n,&k);
//	long long *arr = (long long*)malloc(sizeof(long long) * n);
//	
//	long long Max = 0,hua = 0,total = 0,answer = 0;
//	
//	for(int i = 0;i <n;i++){
//		scanf("%lld",arr + i);
//		total += arr[i];
//	}
//	
//	qsort(arr,n,sizeof(long long),compare);
//	
//	for(int i = 0;i < k;i++){
//		Max += arr[i];
//	}
//	
//	hua = total - Max;
//	
//	if(hua > Max){
//		printf("0\n");
//		free(arr);
//		return 0;
//	}
//	
//	for(int i = k;i < n - k;i++){
//		Max = Max - arr[i - k] + arr[i];
//		total -= arr[i - k];
//		hua = total - Max;
//		answer++;
//		if(hua > Max){
//			printf("%lld",answer);
//			free(arr);
//			return 0;
//		}
//	}
//	
//	printf("-1\n");
//	free(arr);
//	return 0;
//}
//---------------------------------------------------
//问题 H: 取数游戏
//经过分析，无论 k 的值如何，Alice 都可以通过重排序列将最大的 [n/2]个数放在自己的回合
//#include <stdio.h>
//#include <stdlib.h>
//
//int compare(const void* a,const void* b){
//	return (*(long long *)b - *(long long *)a);
//}
//
//int main(){
//	int n,k;
//	scanf("%d %d",&n,&k);
//	long long* arr = (long long*)malloc(sizeof(long long) * n);
//	for(int i = 0;i < n;i++){
//		scanf("%lld",arr + i);
//	} 
//	
//	qsort(arr,n,sizeof(long long),compare);
//	
//	int m = (n + 1) / 2;//计算Alice的回合数 
//	long long max = 0;
//	for(int i = 0;i < m;i++){
//		max += arr[i];
//	} 
//	printf("%lld\n",max);
//	
//	free(arr);
//	return 0;
//}
//--------------------------------------------------------------
//问题 K: 重量II
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//int compare(const void* a,const void* b){
//	return (*(long long *)b - *(long long *)a);
//}
//
//int main(){
//	int k;
//	scanf("%d",&k);
//	while(k--){
//		int n;
//		long long m;
//		scanf("%d %lld",&n,&m);
//		
//		int *weight = (int*)malloc(sizeof(int)*n);
//		
//		for(int i = 0;i < n;i++){
//			scanf("%d",weight + i);
//		}
//		
//		qsort(weight,n,sizeof(int),compare);
//		
//		if(weight[n - 1] != 1){
//			printf("-1\n");
//			free(weight);
//			continue;
//		}		
//		
//		int *total = (int*)malloc(sizeof(int) * (weight[0] + 1));
//		
//		for(int i = 0;i <= weight[0];i++){
//			total[i] = 0;
//		}
//		
//		long long answer = 0;
//		int unfound = 0;
//		for(int i = m;i >= 1;i--){
//			long long temp = i;
//			
//			for(int j = 0;j < n;j++){
//				int w = temp / weight[j];
//				if(w != 0){
//					if(w > total[weight[j]]){
//						total[weight[j]] = w;
//					}
//					temp %= weight[j];
//				}
//				if(temp == 0){
//					break;
//				}else if(j == n - 1){
//					unfound = 1;
//					break;
//				}
//			}
//			
//			if(unfound == 1){
//				break;
//			}				
//		}
//		
//		if(unfound == 1){
//			printf("-1\n");
//		}else{
//			for(int i = 0;i <= weight[0];i++){
//				answer += total[i];
//			}
//			printf("%lld\n",answer);			
//		}
//		free(weight);
//		free(total);
//	}
//	return 0;
//}
//时间超限
//#include <stdio.h>
//#include <stdlib.h>
//如果我们已经能称出1到x的所有重量
//那么加入一个重量为w的砝码后，我们就能称出1到x+w的所有重量（前提是w ≤ x+1）
//int compare(const void* a,const void* b){
//	return (*(int*)a - *(int*)b);
//}
//
//int main(){
//	int T;
//	scanf("%d",&T);
//	
//	while(T--){
//		
//		int n;
//		long long m;
//		scanf("%d %lld",&n,&m);
//		
//		int* weight = (int*)malloc(sizeof(int) * n);
//		
//		for(int i = 0;i < n;i++){
//			scanf("%d",weight + i);
//		}
//		
//		qsort(weight,n,sizeof(int),compare);
//		
//		if(weight[0] != 1){
//			printf("-1\n");
//			free(weight);
//			continue;
//		}
//		
//		long long max_weight = 0;
//		int total = 0;
//		
//		while(max_weight < m){
//			long long next_weight = 0;
//			
//			//寻找最大的砝码
//			for(int i = 0;i < n;i++){
//				if(weight[i] <= max_weight + 1){
//					next_weight = weight[i];
//				}else{
//					break;
//				}
//			}
//			
//            // 如果没有找到合适的砝码
//            if (next_weight == 0) {
//                total = -1;
//                break;
//            }		
//			
//			//寻找到了合适的砝码	
//			total++;
//			max_weight += next_weight;
//		}
//		printf("%d\n",total);
//		free(weight); 
//	}
//	return 0;
//}
//--------------------------------------------------
//问题 L: Cow
//#include <stdio.h>
//#include <stdlib.h>
//int compare(const void* a,const void* b){
//	return(*(int *)b - *(int *)a);
//}
//int main(){
//	int s = 0;
//	scanf("%d",&s);
//	
//	while(s--){
//		int n , m , p , k ;
//		scanf("%d %d %d %d",&n,&m,&p,&k);
//		int x1,y1,x2,y2;
//		int x[110] = {0},y[110] = {0};
//		
//		for(int i = 1;i <= p; i++){
//			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
//			if(x1 == x2){
//				x[y1 > y2 ? y2 : y1]++;
//			}else{
//				y[x1 > x2 ? x2 : x1]++;
//			}
//		}
//		
//		qsort(x,n,sizeof(int),compare);
//		qsort(y,m,sizeof(int),compare);
//		
//		int total = 0,re_k = 0;
////		int total_k = 0;
//		
////		for(int i = 0;i <= n;i++){
////			if(x[i] != 0){
////				total_k++;
////			}
////		}
////		for(int i = 0;i <= m;i++){
////			if(y[i] != 0){
////				total_k++;
////			}
////		}
//		int temp = k;
//		//cs
////		for(int i = 0;i <= n;i++){
////			printf("%d ",x[i]);
////		}
////		printf("\n");
////		for(int i = 0;i <= m;i++){
////			printf("%d ",y[i]);
////		}		
////		printf("\n");
//		//cs
//		for(int i = 0,j = 0;x[i] != 0 || y[j] != 0;){
//			if(x[i] > y[j]){
//				if(k > 0){
//					//printf("csK\n");//cs
//					k--;
//				}else{
//					re_k++;
//					total += x[i];
//				}
//				i++;
//			}else{
//				if(k > 0){
//					//printf("csK\n");//cs
//					k--;
//				}else{
//					re_k++;
//					total += y[j];
//				}
//				j++;				
//			}
//		}
//		
//		if(re_k == 0){
//			printf("%d %d\n",total,temp - k);
//		}else{
//			printf("%d\n",total);
//		}
//		
//	}
//	
//	return 0;
//}
