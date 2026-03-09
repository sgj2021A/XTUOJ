//Contest1073 - 2025年C语言提前作业-0x12（二分、双指针）

//问题 A: 游戏套装

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main(){
//	int **total = (int**)malloc(sizeof(int*) * 10001);
//	
//	for(int i = 0;i <= 10000;i++){
//		total[i] = (int*)malloc(sizeof(int) * 5);
//		for(int j = 0;j <= 4;j++){
//			total[i][j] = 0;
//		}
//	}
//	
//	int n,m,start = 1000000,end = -1,min = 1000000;
//	char str[10];
//	scanf("%d %d",&n,&m);
//	for(int i = 0;i < n;i++){
//		scanf("%s",str);
////		printf("当前str : %s ; ",str);
//		//getchar(); 
//		char to = str[0];
//		int len = strlen(str);
//		
//        char num_str[10];
//        for(int j = 0; j < len - 1; j++){
//            num_str[j] = str[j + 1];
//        }
//        num_str[len - 1] = '\0'; 
//		int to_num = atoi(num_str);
////		printf("当前位置 : %c %d\n",to,to_num);
//		if(str[0] == 'A'){
//			total[to_num][0] = i + 1;
//		}else if(str[0] == 'B'){
//			total[to_num][1] = i + 1;
//		}else if(str[0] == 'C'){
//			total[to_num][2] = i + 1;
//		}else if(str[0] == 'D'){
//			total[to_num][3] = i + 1;
//		}else if(str[0] == 'E'){
//			total[to_num][4] = i + 1;
//		}
//		//test
////		printf("\n"); 
////		for(int j = 1;j <= m;j++){
////			for(int z = 0;z < 5;z++){
////				printf("%d ",total[j][z]);
////			}
////			printf("\n");
////		}
////		printf("\n");
//		//test
//		for(int j = 0;j < 5;j++){
//			if(total[to_num][j] == 0){
//				break;
//			}else if(j == 4){
//				int start_cs = 1000000,end_cs = -1;
//				for(int z = 0;z < 5;z++){
//					if(total[to_num][z] < start_cs)start_cs = total[to_num][z];
//					if(total[to_num][z] > end_cs)end_cs = total[to_num][z];
//				}				
//				int min_cs = end_cs - start_cs;
//				if(min > min_cs){
//				//	printf("change min : %d\n",min_cs); 
//					start = start_cs;
//					end = end_cs;
//					min = min_cs;
//				}
//			}
//		}
//	}
//	 
//	printf("%d %d",start,end);
//	
//	for(int i = 0;i <= 10000;i++){
//		free(total[i]);
//	}	
//	free(total);
//	return 0;
//}

//---------------------------------------------
//问题 B: 性价比 
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#define E 1e-8 
//int compare(const void *a,const void *b){
//    double diff = *((double*)b) - *((double*)a);
//    if (fabs(diff) < E) return 0; // 视为相等
//    return (diff < 0) ? 1 : -1;
//} 
// 
//int main(){
//     
//    int n;
//    scanf("%d",&n);
//     
//    double *rate = (double*)malloc(sizeof(double) * n);
//    for(int i = 0;i < n;i++){
//        scanf("%lf",rate + i);
//    }
//     
//    for(int i = 0;i < n;i++){
//        double temp;
//        scanf("%lf",&temp);
//        rate[i] /= temp;
//    }
//     
//    qsort(rate,n,sizeof(double),compare);
//     
//    if(n == 1){
//        printf("0\n");
//        free(rate);
//        return 0;
//    }
//     
//    long long res = 0;
////  for(int left = n - 2,right = n - 1;rate[right] > 1 && right >= 1;){
////      if(rate[left] * rate[right] <= 1 || left == 0){
////          right--;
////          left = right - 1;
////          continue;
////      }
////      //printf("left:%d right:%d\n",left,right);
////      if(rate[left] * rate[right] > 1)res++;   
////      left--;     
////  } 
//    int left = 0, right = n - 1;
//    while (left <= right && rate[right] > 1) {
//        if (rate[left] * rate[right] > 1 + E) {
//            res += (right - left); 
//            right--;
//        } else {
//            left++;
//        }
//    }
//    printf("%lld\n",res);
//    //test
////  for(int i = 0;i < n;i++){
////      printf("%lf ",rate[i]);
////  }   
//    //test
//    free(rate);
//    return 0;
//}

//---------------------------------------------
//问题 C: 分类
//#include <stdio.h>
//#include <stdlib.h>
// 
//// 比较函数用于排序
//int compare(const void *a, const void *b) {
//    return (*(int*)a - *(int*)b);
//}
// 
//// 检查是否可以在最大差值为max_diff的情况下分成至少m个团队
//int canSplit(int arr[], int n, int m, int max_diff) {
//    int count = 1; // 当前团队数量
//    int last = arr[0]; // 当前团队的起始值
//     
//    for (int i = 1; i < n; i++) {
//        // 如果当前元素与last的差值大于max_diff，需要开始新团队
//        if (arr[i] - last > max_diff) {
//            count++;
//            last = arr[i];
//             
//            // 如果团队数量已经达到m，但还有元素未处理，返回0
//            if (count > m) {
//                return 0;
//            }
//        }
//    }
//    return 1;
//}
// 
//int main() {
//    int T;
//    scanf("%d", &T);
//     
//    while (T--) {
//        int n, m;
//        scanf("%d %d", &n, &m);
//         
//        int *a = (int*)malloc(sizeof(int) * n);
//        for (int i = 0; i < n; i++) {
//            scanf("%d", &a[i]);
//        }
//         
//        // 对能力值进行排序
//        qsort(a, n, sizeof(int), compare);
//         
//        // 二分查找寻找最小的最大差值
//        int left = 0;
//        int right = a[n-1] - a[0]; // 最大可能的差值
//        int answer = right;
//         
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//             
//            if (canSplit(a, n, m, mid)) {
//                answer = mid;
//                right = mid - 1;
//            } else {
//                left = mid + 1;
//            }
//        }
//         
//        printf("%d\n", answer);
//        free(a);
//    }
//     
//    return 0;
//}
//---------------------------------------------
//问题 D: 众数 
//#include <stdio.h>
//#include <stdlib.h> 
//
//int compare(const void *a,const void *b){
//	return *((long long*)a) > *((long long*)b) ? 1 : 0;
//}
//
//int main(){
//	
//	int s;
//	scanf("%d",&s);
//	
//	while(s--){
//		int n,k;
//		scanf("%d %d",&n,&k);
//		
//		long long *num = (long long*)malloc(sizeof(long long) * n);
//		
//		for(int i = 0;i < n;i++){
//			scanf("%lld",num + i);
//		}
//		
//		qsort(num,n,sizeof(long long),compare);
//		
//		long long max = 1;
//		for(int i = n - 1;i > 0;i--){
//			long long max_cs = 1;
//			if(i + 1 <= max)break;
//			
//			long long temp = k;
//			for(int j = i - 1;j >= -1;j--){
////				printf("%d %d %lld | ",i + 1,j + 1,max_cs); 
//				if(temp < num[i] - num[j] || j == -1){ 
////					printf("change : %lld| ",max_cs);
//					max = (max < max_cs ? max_cs : max);
//					break;
//				}else{
//					temp -= (num[i] - num[j]);
//					max_cs++;
////					printf("produce : %lld temp : %lld | ",max_cs,temp);
//				}
//			}
//		} 
////		printf("\n");
//		printf("%lld\n",max);
//		//test
////		printf("排序数列 : ");
////		for(int i = 0;i < n;i++){
////			printf("%lld ",*(num + i));
////		}	
////		printf("\n");	
//		//test
//		free(num);
//	}
//	
//	return 0;
//}

//---------------------------------------------
//问题 E: Estrella's Chocolate
//#include <stdio.h>
//#include <stdlib.h>
//
////int compare(const void *a,const void *b){
////	return *((long long*)a) > *((long long*)b) ? 1 : 0;
////}
//
//int process(long long *num,long long size,long long index,int cut_num){
//	int cut = 1,count = 0;
//	for(int i = 0;i < size;i++){
//        if(num[i] > index) {
//            return 0;
//        }
//		if(count + num[i] > index){
//			cut++;
//			count = num[i];
//			if(cut > cut_num) return 0;
//		}else{
//			count += num[i];
//		}
//	//	printf("count : %d cut : %d\n",count,cut); 
//	}
//	return cut <= cut_num;
//}
//
//int main(){
//	int s = 0;
//	
//	scanf("%d",&s);
//	
//	while(s--){
//		int n,m;
//		scanf("%d %d",&n,&m);
//		long long *num = (long long*)malloc(sizeof(long long) * n);		
//		long long left = 0,right = 0;
//		
//		for(int i = 0;i < n;i++){
//			scanf("%lld",num + i);
//			right += num[i];
//			if(num[i] > left) left = num[i];
//		}
//		//qsort(num,n,sizeof(long long),compare);
//		//test
////		for(int i = 0;i < n;i++){
////			printf("%lld ",num[i]);
////		}
//		//printf("\n%lld %lld\n",left,right);
//		//test	
//		long long result = right;
//		long long index = 0;	
//		while(left <= right){
//			index = left + (right - left) / 2;
//		//	printf("index : %d\n",index);
//			if(process(num,n,index,m)){
//				result = index;
//				right = index - 1;
//			}else{
//				left = index + 1;
//			}
//		}
//		printf("%d\n",result);
//		free(num); 
//	}
//
//	
//	return 0;
//} 
//

//---------------------------------------------
//问题 F: Craftman
//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct{
//	long long need;
//	long long have;
//}node;
//
//int process(node *game,int size,long long index,long long k){
//	for(int i = 0;i < size;i++){
//		if(game[i].need * index > game[i].have){
//			k -= (game[i].need * index - game[i].have);
//			if(k < 0)return 0;
//		}
//	}
//	return 1;
//} 
//
//int main(){
//	int s;
//	scanf("%d",&s);
//	
//	while(s--){
//		int n;
//		long long k,right,left = 0;
//		scanf("%d %lld",&n,&k);
//		
//		node *game = (node*)malloc(sizeof(node) * n);
//		
//		for(int i = 0;i < n;i++){
//			scanf("%lld",&(game[i].need));
//		}
//		for(int i = 0;i < n;i++){
//			scanf("%lld",&(game[i].have));
//		//	if(left < game[i].have / game[i].need)left = game[i].have / game[i].need;
//		} 
//		right = 2000000000;
//		long long result = left;
//		while(left <= right){
//			long long min = left + (right - left) / 2;
//			if(process(game,n,min,k)){
//				left = min + 1;
//				result = min;
//			}else{
//				right = min - 1;
//			}
//		}
//		//test
////		for(int i = 0;i < n;i++){
////			printf("%lld %lld | ",game[i].need,game[i].have);
////		} 		
////		printf("\n");
//		//test
//		printf("%lld\n",result);
//		free(game);
//	}
//	
//	return 0;
//}
//---------------------------------------------
//问题 H: 制药
//#include <stdio.h> 
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct{
//	int a, b;
//}node;
// 
//int process(node* item,int index,int n,int m){
//	for(int i = 0;i < n;i++){
//		long long need = index * item[i].a;
//		if(need % item[i].b != 0){
//			m -= (need / item[i].b + 1);
//		}else{
//			m -=(need / item[i].b);
//		}
//		if(m < 0)return 0;
//	}
//	return 1;
//} 
// 
//int main(){
//	int s;
//	scanf("%d",&s);
//	
//	while(s--){
//		int n,m;
//		int left = 0,right = 1000000;
//		scanf("%d %d",&n,&m);
//		
//		node *item = (node*)malloc(sizeof(node) * n);
//		
//		for(int i = 0;i < n;i++){
//			scanf("%d",&item[i].a);
//			//if(m / item[i].a > right)right = m / item[i].a;
//		}
//		
//		for(int i = 0;i < n;i++){
//			scanf("%d",&item[i].b);
//		}
//		
//		int result = left;
//		
//		while(left <= right){
//			//printf("left : %d right : %d result : %d\n",left,right,result);
//			int min = left + (right - left) / 2;
//			if(process(item,min,n,m)){
//				result = min;
//				left = min + 1;
//			}else{
//				right = min - 1;
//			}
//		}
//		
//		printf("%d\n",result);
//		free(item);
//	}
//	return 0;
//} 

//---------------------------------------------
//问题 I: 三角形

//#include <stdio.h>
//#include <stdlib.h>
//
//int compare(const void *a,const void *b){
//	if(*(long long*)a - *(long long*)b > 0)return 1;
//	else return 0;
//}
//int isTriangle(long long a, long long b, long long c) {
//    // 检查三角形不等式
//    if (a + b > c && a + c > b && b + c > a) {
//        return 1; // 可以构成三角形
//    }
//    return 0; // 不能构成三角形
//}
//int main(){
//	int s;
//	scanf("%d",&s);
//	
//	while(s--){
//		int n;
//		scanf("%d",&n);
//		
//		long long *arr = (long long*)malloc(sizeof(long long) * n);
//		
//		for(int i = 0;i < n;i++){
//			scanf("%lld",arr + i);
//		}
//		
//		qsort(arr,n,sizeof(long long),compare);
//		
////		for(int i = 0;i < n;i++){
////			printf("%lld ",arr[i]);
////		}
////		printf("\n");		
//		
//		int total = 0;
//		//int left = 0,min = 0,right = n - 1;
//		for(int k = 2;k < n;k++){
//			int i = 0;
//			for(int j = k - 1;j > 0;j--){
//				while(i < j && arr[i] + arr[j] <= arr[k]){
//					i++;
//				}
//				if(i < j){
//					total += (j - i);
//				}
//			}
//		} 
//		printf("%d\n",total);
//		free(arr);
//	}
//
//	return 0;
//}

//---------------------------------------------
//问题 L: 最大的数

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//void swap(char *a,char *b){
//	char c = *a;
//	*a = *b;
//	*b = c;
//}
//
//int main(){
//	char str[10001];	
//	
//	while(scanf("%s",str) != EOF){
//		int len = strlen(str);
//		
//		int change = 1;
//		int left = 0,right = len - 1;
//		while(change != 0){
////			change = 0;
////			left = 0;
////			right = len - 1; 
////			while(left < right){
//////				printf("left : %d right : %d\n",left,right); 
////				if(abs((str[left] - '0') - (str[left + 1] - '0')) % 2 == 1 && str[left] < str[left + 1]){
////					change++;
////					swap(&str[left],&str[left + 1]); 
////				}
////				if(abs((str[right] - '0') - (str[right - 1] - '0')) % 2 == 1 && str[right - 1] < str[right]){
////					change++; 
////					swap(&str[right],&str[right - 1]);
////				}
////				right--; 
////				left++;
////			}	
////			printf("change %d\n",change);	
//			change = 0;
//			while(left < len - 1){
//				if(abs((str[left] - '0') - (str[left + 1] - '0')) % 2 == 1 && str[left] < str[left + 1]){
//					change++;
//					swap(&str[left],&str[left + 1]); 
//					left = left - 1;
//				}else{
//				left++;						
//				}	
//			}
//		}
//		
//		printf("%s\n",str);
//
//	}
//	return 0;
//} 

//在任意交换过程中，所有奇数数字之间的相对顺序保持不变，所有偶数数字之间的相对顺序也保持不变。因此，问题转化为将奇数序列和偶数序列合并成一个字典序最大的序列。

//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(){
//	char str[10001];
//	
//	while(scanf("%s",str) != EOF){
//		char str_1[10001],str_2[10001];
//		int index_1 = 0,index_2 = 0,index = 0;
//		
//		int len = strlen(str);
//		
//		for(int i = 0;i < len;i++){
//			if(abs(str[i] - '0') % 2 == 1){
//				str_1[index_1++] = str[i]; 
//			}else{
//				str_2[index_2++] = str[i];
//			}
//		}
//		
//		char result[10001];
//		
//	for(int j = 0,i = 0;index < len;){
//	    if(i < index_1 && j < index_2){
//	        // 两个序列都还有元素时，比较当前字符
//	        if(str_1[i] > str_2[j]){
//	            result[index++] = str_1[i++];
//	        }else{
//	            result[index++] = str_2[j++];
//	        }
//	    }else if(i < index_1){
//	        // 只有奇数序列还有元素
//	        result[index++] = str_1[i++];
//	    }else{
//	        // 只有偶数序列还有元素
//	        result[index++] = str_2[j++];	
//	    }
//	} 
//		result[len] = '\0';
//		
//		printf("%s\n",result);
//	}
//}

//-----------------------------------------------------
// 问题 J: 前缀和

//#include <stdio.h>
//#include <stdlib.h>
//
//int compare(const void *a,const void *b){
//	return *((int*)a) - *((int*)b);
//}
//
//int main(){
//	int s;
//	scanf("%d",&s);
//	
//	while(s--){
//		int num_A,num_B;
//		scanf("%d %d",&num_A,&num_B);
//		
//		int *A = (int*)malloc(sizeof(int) * num_A);
//		//int *B = (int*)malloc(sizeof(int) * num_B);
//		int B;
//		long long k = 0;
//				
//		for(int i = 0;i < num_A;i++){
//			scanf("%d",A + i);
//		} 	
//		
//		int *great_0 = (int*)malloc(sizeof(int) * num_B);
//		long long little_0 = 0;
//		int index = 0;
//		for(int i = 0;i < num_B;i++){
//			scanf("%d",&B);
//			if(B <= 0){
//				k++;
//				little_0 += B;
//			}else{
//				great_0[index++] = B;
//			}
//		}
//		
//		qsort(great_0,index,sizeof(int),compare);
//		
//		//test
//	//	printf("index : %d little_0 : %lld\n",index,little_0);
//	//	for(int i = 0; i < index;i++){
//	//		printf("%d ",great_0[i]);
//	//	}
//	//	printf("\n");
//		//test 
//		long long result = 0;
//		int location_A = 0,location_B = 0;
//		if(little_0 < 0){
//			result = k;
//		}
//		for(int i = 0;i < index + num_A;i++){
//			if(location_B < index){
//				if(A[location_A] > great_0[location_B]){
//	//				printf("add great_0[%d] : %d little_0 : %lld \n",location_B,great_0[location_B],little_0);
//					little_0 += great_0[location_B++]; 
//				}else{
//	//				printf("add A[%d] : %d little_0 : %lld \n",location_A,A[location_A],little_0);
//					little_0 += A[location_A++];
//				}
//				k++;
//			}else{
//	//			printf("add A[%d] : %d little_0 : %lld \n",location_A,A[location_A],little_0);
//				little_0 += A[location_A++];
//				k++;
//			}
//			if(little_0 < 0){
//				result = k;
//			}
//		}
//		free(A);
//		free(great_0);
//		printf("%lld\n",result);
//	//	printf("\n"); 
//	}
//	
//	return 0;
//} 
//修正 
//#include<stdio.h>
//#include<stdlib.h>
//int a[1005] = {}, b[1005] = {};
////从小到大排序
//int cmp(const void *a, const void *b) {
//    return *(int*)a - *(int*)b;
//}
//int n, m;
////二分查找数组b最接近x的数
//int find(int x) {
//    int mid, res = 0, left = 1, right = m;
//    while (left <= right) {
//        mid = (left + right) / 2;
//        if (b[mid] <= x) {
//            res = mid;
//            left = mid + 1;
//        } else {
//            right = mid - 1;
//        }
//    }
//    return res;
//}
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        int i;
//        scanf("%d%d", &n, &m);
//        for (i = 1; i <= n; i++) {
//            scanf("%d", &a[i]);
//        }
//        for (i = 1; i <= m; i++) {
//            scanf("%d", &b[i]);
//        }
//        //数组b从小到大排序
//        qsort(b + 1, m, sizeof(int), cmp);
//        //求前缀和
//        for (i = 2; i <= n; i++)a[i] += a[i - 1];
//        for (i = 2; i <= m; i++)b[i] += b[i - 1];
//        int k = 0, t;
//        for (i = 0; i <= n; i++) {
//            //x+a[i]=-1,所以查找-a[i]-1
//            t = find(-a[i] - 1);
//            if (a[i] + b[t] < 0 && i + t > k)k = i + t;
//        }
//        printf("%d\n", k);
//    }
//}

//-------------------------------------------
//问题 G: 马里奥（问题） 
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(){
//	
//	long long w,n,d;
//	
//	scanf("%lld %lld %lld",&w,&n,&d);
//	
//	long long *arr = (long long*)malloc(sizeof(long long) * (n + 2));
//	
//	arr[0] = 1;
//	arr[n + 1] = w;
//	for(int i = 1;i <= n;i++){
//		scanf("%lld",arr + i);
//	}
//	
//	//judge -1
//	if(w - 1 <= d){
//		printf("-1");
//		free(arr);
//		return 0;
//	}
//	
//	long long *sub = (long long*)malloc(sizeof(long long) * (n + 2));	
//	sub[0] = arr[0];
//	for(int i = 1;i <= n + 1;i++){
//		sub[i] = arr[i] - arr[i - 1];
//	}
//	n += 2;
//	
//	//test
////	printf("w : %lld n : %lld d: %lld\n",w,n,d);
////	printf("arr : ");
////	for(int i = 0;i < n;i++){
////		printf("%lld ",arr[i]);
////	}
////	printf("\nsub : ");
////	for(int i = 0;i < n;i++){
////		printf("%lld ",sub[i]);
////	}	
//	//test
//	
//	int left = 1,right = 1;
//	//frist set
//	int total = 0;
//	while(1){
//		total += sub[right++];
//		if(total >= d)break;
//	}
//	right--; 
//	
//	//test
////	printf("\nfrist total : %d right : %d\n",total,right);
//	//test	
//	
//	if(right == n - 1){
//		printf("%d",total);
//		free(sub);
//		free(arr);
//		return 0;
//	} 
//	
//	//next
//	int result = right - left + 1;
//	
//	while(right < n - 1){
//		total -= sub[left++];
//		if(total >= d || right >= n - 1)continue; 
//		while(1){
//			right++;
//			total += sub[right];
//			if(total >= d || right >= n - 1)break;
//		}
//		result = (right - left) < result ? (right - left) : result;
//		//printf(" left : %d right : %d total : %d result %d right - left : %d\n",left,right,total,result,right - left);
//	}
//	
//	printf("%d",result);
//	free(arr);
//	free(sub);
//	
// 	return 0;
//} 

//修正 
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(){
//	long long w,n,d;
//	scanf("%lld %lld %lld",&w,&n,&d);
//	
//	long long *arr = (long long*)malloc(sizeof(long long)*(n + 2));
//	
//	for(int i = 1;i <= n;i++){
//		scanf("%lld",arr + i);
//	}
//	arr[0] = 1;
//	arr[n + 1] = w;
//	
//	int result = 100000;
//	
//	if(1 + d >= w){
//		printf("-1");
//		free(arr);
//		return 0;
//	}
//	for(int i = 0;i < n;i++){
//		long long range = arr[i] + d;
//		int total = 0;
//		if(arr[i] + d >= w)break; 
//		for(int j = i + 1;j <= n;j++){
//			if(arr[j] <= range){
//				total++;
//			}else{
//				//printf("i : %d total : %d result : %d\n",i,total,result); 
//				result = total < result ? total : result;
//				break;				
//			}
//			if(j == n){
//				//printf("i : %d total : %d result : %d\n",i,total,result); 
//				result = total < result ? total : result;
//			}
//		} 
//	}
//	//test
////	printf("arr : ");
////	for(int i = 0;i <= n + 1;i++){
////		printf("%lld ",arr[i]);
////	}
////	printf("\n"); 
//	//test 
//	printf("%d",result);
//	free(arr);
//	return 0;
//}
//--------------------------------------------------------
//问题 K: 数组

//#include <stdio.h>
//#include <stdlib.h>
//int compare(const void *a,const void *b){
//	return *((long long*)a) - *((long long*)b);
//}
//int main(){
//	int s;
//	scanf("%d",&s);
//	
//	while(s--){
//		int n;
//		long long a1,a2,m;
//		scanf("%d %lld %lld %lld",&n,&a1,&a2,&m);
//		
//		long long *arr = (long long*)malloc(sizeof(long long) * n);
//		arr[0] = a1;
//		arr[1] = a2;
//		
//		for(int i = 2;i < n;i++){
//			arr[i] = (arr[i - 1] + arr[i - 2]) % m;
//		}
//		
////		qsort(arr,n,sizeof(long long),compare);
//		
//		//test
////		printf("arr : "); 
////		for(int i = 0;i < n;i++){
////			printf("%lld ",arr[i]);	
////		}
////		printf("\n"); 
//		//test
//		
//		long long L,R;
//		scanf("%lld %lld",&L,&R);
//		
//		long long result = 0;
//		
//		int left = 0,right = 0;
//		
////		while(arr[left] < L){
////			left++;
////		}
//		for(;arr[left] <= R && left < n;left++){
//			if(arr[left] >= L &&arr[left] <= R)result++;
//		//	printf("left : %d\n",left); 
//			for(right = left + 1;right < n;right++){
//				long long temp = arr[right] + arr[left]; 
//				if(temp >= L &&temp <= R){
//					//printf("left : %d right : %d %d %d\n",left,right,arr[left],arr[right]);
//					result++;
//				}
//			}
//		}
//		printf("%lld\n",result);
//		free(arr); 
//	} 
//	return 0;
//} 
//时间超限

//#include <stdio.h>
//#include <stdlib.h>
//
//int compare(const void *a,const void *b){
//	return (*(long long*)a > *(long long*)b) ? 1 : -1;
//} 
//
//int main(){
//	int s;
//	scanf("%d",&s);
//	
//	while(s--){
//		int n; 
//		long long m,a1,a2,L,R;
//		
//		scanf("%d %lld %lld %lld",&n,&a1,&a2,&m);
//		scanf("%lld %lld",&L,&R); 
//		long long *a = (long long*)malloc(sizeof(long long) * n);
//		
//		a[0] = a1;
//		a[1] = a2;
//		
//		for(int i = 2;i < n;i++){
//			a[i] = (a[i - 1] + a[i - 2]) % m;
//		}
//		
//		long long total_1 = 0;
//		for(int i = 0;i < n;i++){
//			if(2*a[i] <= R && 2*a[i] >= L){
//				total_1++;
//			}
//		}
//		
//		qsort(a,n,sizeof(long long),compare);
//		
//		int j = n - 1;
//		long long total_2 = 0;
//		for(int i = 0;i < n;i++){
//			while(j >= 0 && a[i] + a[j] > R){
//				j--;
//			}
//			if(j >= 0){
//				total_2 += (j + 1);
//			}
//		}
//		
//		long long total_3 = 0;
//		j = n - 1;
//		for(int i = 0;i < n;i++){
//			while(j >= 0 && a[i] + a[j] > L - 1){
//				j--;
//			}
//			if(j >= 0){
//				total_3 += (j + 1);
//			}
//		}
//				
//		long long total = total_2 - total_3;
//		long long result = (total + total_1) / 2;
//		printf("%lld\n",result);
//		free(a); 		
//	}
//	 
//	return 0;
//}
// 
