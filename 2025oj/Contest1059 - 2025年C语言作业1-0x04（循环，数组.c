//#include <stdio.h>
//#include <math.h>
//#include <string.h>
//#include <stdbool.h> 
//问题 A: Rectangle
//int min(int a,int b){
//	return a < b ? a : b;
//}
//int max(int a,int b){
//	return a > b ? a : b;
//}
//int main(){
//	int k;
//	scanf("%d",&k);
//	while(k--){
//		int x1,x2,y1,y2,x3,x4,y3,y4;
//		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
//		scanf("%d %d %d %d",&x3,&y3,&x4,&y4);
//		int left1=min(x1,x2);
//		int right1=max(y1,y2);
//		int top1=max(x1,x2);
//		int bottom1=min(y1,y2);
//		int left2=min(x3,x4);
//		int right2=max(y3,y4);
//		int top2=max(x3,x4);
//		int bottom2=min(y3,y4);
//		if(right1>left2&&right2>left1&&top1>bottom2&&top2>bottom1){
//			printf("Yes\n");
//		}else{
//			printf("No\n");
//		}
//	}
//	return 0;
//}

//问题 B: Sandglass
//int main(){
//	int k=0;
//	scanf("%d",&k);
//	while(k--){
//		int n=0;
//		scanf("%d",&n);
//		for(int i=0;i<n-1;i++){
//			printf("-");
//		}
//		printf("\n\\");
//		for(int i=0;i<n-3;i++){
//			printf(" ");
//		}
//		printf("/\n");
//		int cs=1;
//		for(int i=0;i<n/2-2;i++){
//			for(int j=0;j<=i;j++){
//				printf(" ");
//			}
//			printf("\\");
//			for(int j=0;j<n-i-cs-4;j++){
//				printf("*");
//			}
//			cs++;
//			printf("/\n");
//		}
//		cs=0;
//		for(int i=0;i<n/2-1;i++){
//			for(int j=0;j<n/2-2-i;j++){
//				printf(" ");
//			}
//			printf("/");
//			for(int j=0;j<cs;j++){
//				printf(" ");
//			}
//			printf("*");
//			for(int j=0;j<cs;j++){
//				printf(" ");
//			}
//			printf("\\\n");
//			cs++;
//		}
//		for(int i=0;i<n-1;i++){
//			printf("-");
//		}
//		printf("\n\n");
//	}
//}
////问题 D: Tri-Triangle
//int main() {
//    char c;
//    int cs=0;
//    while (scanf("%c", &c) != EOF) {
//        for (char i = 'A'; i <= c; i++) {
//            for (int j = 'A'; j <= c; j++) {
//                printf(" ");
//            }
//            for (int j = 0; j < c - i; j++) {
//                printf(" ");
//            }
//            for (char j = 'A'; j <= i; j++) {
//                printf("%c", j);
//            }
//            for (char j = i - 1; j >= 'A'; j--) {
//                printf("%c", j);
//            }
//            printf("\n");
//        }
//        cs=2*(c-'A'+1);
//        for (char i = 'A'; i <= c; i++) {
//            for (int j = 0; j < c - i; j++) {
//                printf(" ");
//            }
//            for (char j = 'A'; j <= i; j++) {
//                printf("%c", j);
//            }
//            for (char j = i - 1; j >= 'A'; j--) {
//                printf("%c", j);
//            }
//            for (int j = 1; j < cs; j++) {
//                printf(" ");
//            }
//            cs-=2;
//            for (char j = 'A'; j <= i; j++) {
//                printf("%c", j);
//            }
//            for (char j = i - 1; j >= 'A'; j--) {
//                printf("%c", j);
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}
//问题 C: A+B II
//int main(){
//	int a;
//	while(1){
//		scanf("%d",&a);
//		if(a==0){
//			break;
//		}
//		for(int i=0;i<a;i++){
//			for(int j=a-i-1;j>0;j--){
//				printf(" ");
//			}
//			if(i==0){
//				printf("1");
//			}else{
//				for(int j=1;j<=i;j++){
//					printf("%d",j);
//				}
//				printf("+");
//				for(int j=i;j>=1;j--){
//					printf("%d",j);
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//问题 E: 十字
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define Max_Map 125
//int main(){
//	char a;
//	while(scanf("%c",&a) != EOF){
//		char map[Max_Map][Max_Map]={};
//    	for (int i = 0; i < Max_Map; i++) {
//        	memset(map[i], ' ', Max_Map);
//    	}		
//		int point=(a-'A'+1)*2; 
//		for(int i=a-'A'+1;i<=point*2-1-(a-'A');i++){
//			map[i][point]='A';
//		} 
//		for(int i=a-'A'+1;i<=point*2-1-(a-'A');i++){
//			map[point][i]='A';
//		}
//		for(char k = 'B'; k <= a; k++) {
//		    for(int i = 1; i <= point*2-1; i++) {
//		        for(int j = 1; j <= point*2-1; j++) {
//		            // 跳过已填充区域
//		            if(map[i][j] != ' ') continue;
//		            
//		            // 检查四个方向是否有前一个字符
//		            if(map[i-1][j] == k-1 || map[i+1][j] == k-1 || map[i][j-1] == k-1 || map[i][j+1] == k-1) {
//		            	map[i][j] = k;
//		            }else if(map[i - 1][j - 1] == k - 1 ||map[i + 1][j - 1] == k - 1 ||map[i - 1][j + 1] == k - 1 ||map[i + 1][j + 1] == k - 1){
//		            	map[i][j] = k;
//					}
//		        }
//		    }
////		    for(int i = 1; i <= point*2-1; i++) {
////		        for(int j = 1; j <= point*2-1; j++) {
////		            // 跳过已填充区域
////		            if(map[i][j] != ' ') continue;
////		            // 检查是否在角上的区域
////					if(map[i][j+1] == k && map[i+1][j] == k && map[i+1][j+1] == k - 1 || map[i][j+1] == k && map[i-1][j] == k && map[i-1][j+1] == k - 1 || map[i][j-1] == k && map[i-1][j] == k && map[i-1][j-1] == k - 1 || map[i][j-1] == k && map[i+1][j] == k && map[i+1][j-1] == k - 1 ) {
////		            	map[i][j] = k;
////		            } 
////		        }
////		    }
//		}
//		for(int i=1;i<=point*2-1;i++){
//			for(int j=1;j<=point*2-1;j++){
//				printf("%c",map[i][j]);
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}


//问题 F: 矩阵乘法
//int main() {
//    int t;
//    scanf("%d", &t);
//    while (t--) {
//        int n, k1;
//        scanf("%d %d", &n, &k1);
//        int A[10][10];
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < k1; j++) {
//                scanf("%d", &A[i][j]);
//            }
//        }
//        int k2, m;
//        scanf("%d %d", &k2, &m);
//        int B[10][10];
//        for (int i = 0; i < k2; i++) {
//            for (int j = 0; j < m; j++) {
//                scanf("%d", &B[i][j]);
//            }
//        }
//        int C[10][10] = {0};
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                for (int p = 0; p < k1; p++) {
//                    C[i][j] += A[i][p] * B[p][j];
//                }
//            }
//        }
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                if (j > 0) printf(" ");
//                printf("%d", C[i][j]);
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//问题 G: 身份证验证
//int main() {
//    int t;
//    scanf("%d", &t);
//    while (t--) {
//    	long long sum=0;
//        char str[20];
//        scanf("%s",str);
//        for (int i = 0; i < 18; i++) {
//            char c = str[17 - i];
//            if (c == 'X') {
//                sum += 10;
//            } else if (c >= '0' && c <= '9') {
//                sum += (c - '0') * (1LL << i);
//            } else {
//                sum = -1;
//                break;
//            }
//        }
//		if(sum%11==1){
//			printf("Yes\n");
//		}else{
//			printf("No\n");
//		}
//
//    }
//    return 0;
//}
//问题 H: 勾股数
//int process(int x,int y){
//	int f=x*x+y*y;
//	int z=fabs(x*x-y*y);
//	for(int i=1;i<=sqrt(f)+1;i++){
//		if(z==i*i||f==i*i){
//			return i;
//		}
//	}
//	return -1;
//}
//int main(){
//	int t,x,y,z;
//	scanf("%d",&t);
//	while(t--){
//		scanf("%d %d",&x,&y);
//		z=process(x,y);
//		if(z==-1){
//			printf("None\n");
//		}else{
//			printf("%d\n",z);
//		}
//	}
//	return 0;
//}

//问题 I: 字符矩阵
//int main() {
//	char a='A';
//	while(1) {
//		char map[55][55]= {};
//		scanf("%c",&a);
//		int w=(a-'A')*2+1;
//		if(a=='#') {
//			break;
//		}
//		int cs=1;
//		for(int j=a; j>='A'; j--) {
//			map[1][cs]=j;
//			cs++;
//		}
//		for(int j='B'; j<=a; j++) {
//			map[1][cs]=j;
//			cs++;
//		}
//		for(int i=2; i<=(w+1)/2; i++) {
//			cs=2;
//			map[i][1]=map[1][i];
//			for(int j=2; j<=(w+1)/2; j++) {
//				map[i][j]=map[i-1][j-1];
//			}
//			for(int j=(w+1)/2+1; j<=w; j++) {
//				map[i][j]=map[i][j-cs];
//				cs+=2;
//			}
//		}
//		
//		for(int i=1; i<=(w+1)/2; i++) {
//			for(int j=1; j<=w; j++) {
//				printf("%c",map[i][j]);
//			}
//			printf("\n");
//		}
//		cs=1;
//		for(int i=1; i<=(w+1)/2-1; i++){
//			for(int j=1; j<=w; j++) {
//				printf("%c",map[(w+1)/2-i][j]);
//				cs++;
//			}
//			printf("\n");
//		}
//	}
//}

//问题 J: Set(?)
//bool find(long long *a,int size,long long f_n){
//	for(int i=0;i<size;i++){
//		if(*(a+i)==f_n){
//			return true;
//		}
//	}
//	return false;
//}
//bool add(long long *a,int size,long long a_n){
//	for(int i=0;i<size;i++){
//		if(*(a+i)==-1){
//			*(a+i)=a_n;
//			return true;
//		}
//	}
//	return false;
//}
//bool find_one(long long *a,int size){
//	int cs=0;
//	for(int i=0;i<size;i++){
//		if(*(a+i)==-1){
//			cs++;
//		}
//	}
//	if(cs==0){
//		return false; 
//	}	
//	return true;
//}
//int main(){
//	long long e;
//	long long k=0;
//	scanf("%d",&k);
//	while(k--){
//		long long d,a[4]={-1,-1,-1,-1},cs=0;
//		scanf("%lld",&d); 
//		if(d>=1&&d<=4){
//			for(int i=0;i<d;i++){
//				scanf("%lld",&e);
//			}
//			printf("Yes\n");
//		}else{
//			for(int i=0;i<d;i++){
//				scanf("%lld",&e);
//				if(find_one(a,4)&&find(a,4,e)==false){
//					add(a,4,e);
//					if(i==d-1){
//						printf("Yes\n");
//					}
//				}else{
//					if(!find(a,4,e)){
//						printf("No\n");
//						break;
//					}else if(i==d-1){
//						printf("Yes\n");
//					}
//				}
//			}
//		}
//	}
//} 
//#include <stdio.h>
//#include <stdlib.h>
//
//int compare(const void *a, const void *b) {
//    return (*(long long *)a - *(long long *)b);
//}
//
//int main() {
//    int K;
//    scanf("%d", &K);
//    while (K--) {
//        int n;
//        scanf("%d", &n);
//        long long *A = (long long *)malloc(n * sizeof(long long));
//        for (int i = 0; i < n; i++) {
//            scanf("%lld", &A[i]);
//        }
//        
//        qsort(A, n, sizeof(long long), compare);
//        
//        int distinct_count = 1;
//        for (int i = 1; i < n; i++) {
//            if (A[i] != A[i-1]) {
//                distinct_count++;
//            }
//        }
//        
//        if (distinct_count > 4) {
//            printf("No\n");
//            free(A);
//            continue;
//        }
//        
//        long long *V = (long long *)malloc(distinct_count * sizeof(long long));
//        int idx = 0;
//        V[idx++] = A[0];
//        for (int i = 1; i < n; i++) {
//            if (A[i] != A[i-1]) {
//                V[idx++] = A[i];
//            }
//        }
//        
//        if (distinct_count <= 3) {
//            printf("Yes\n");
//        } else {
//            int found = 0;
//            for (int i = 0; i < 4; i++) {
//                long long T = V[i];
//                long long diffs[3];
//                int diff_idx = 0;
//                for (int j = 0; j < 4; j++) {
//                    if (j == i) continue;
//                    diffs[diff_idx++] = T - V[j];
//                }
//                int valid = 0;
//                for (int a = 0; a < 3; a++) {
//                    for (int b = a + 1; b < 3; b++) {
//                        for (int c = 0; c < 3; c++) {
//                            if (c == a || c == b) continue;
//                            if (diffs[a] == diffs[b] + diffs[c] ||
//                                diffs[b] == diffs[a] + diffs[c] ||
//                                diffs[c] == diffs[a] + diffs[b]) {
//                                valid = 1;
//                                break;
//                            }
//                        }
//                        if (valid) break;
//                    }
//                    if (valid) break;
//                }
//                if (valid) {
//                    found = 1;
//                    break;
//                }
//            }
//            if (found) {
//                printf("Yes\n");
//            } else {
//                printf("No\n");
//            }
//        }
//        free(V);
//        free(A);
//    }
//    return 0;
//}
//问题 K: Magic
//void qsort(
//    void *base,      // 数组首地址
//    size_t nmemb,    // 数组元素个数
//    size_t size,     // 每个元素的大小（字节）
//    int (*compar)(const void *, const void *) // 比较函数
//);
//int compare(const void *a, const void *b) {
//    // 返回值的含义：
//    // < 0：a 应排在 b 前面
//    // > 0：b 应排在 a 前面
//    // = 0：顺序不变
//}
//*(char*)b - *(char*)a 计算的是 b 的值减去 a 的值：
//如果 b > a，结果为正数 → b 排在 a 前面（降序）。
//如果 b < a，结果为负数 → a 排在 b 前面（降序）。
//如果 b == a，结果为 0 → 顺序不变。
//在比较函数内部，必须将它们强制转换为实际的指针类型（如 char*、int* 等），才能解引用取值。
//a 和 b 的来源：由 qsort 自动传入，指向待比较的两个数组元素。
//指针类型：必须是 const void*，需强制转换后才能解引用。
//int cmp_asc(const void *a, const void *b) {
//    return *(char*)a - *(char*)b;
//}
//
//int cmp_desc(const void *a, const void *b) {
//    return *(char*)b - *(char*)a;
//}
//
//int main() {
//    int n;
//    while (scanf("%d", &n) && n != 0) {
//        if (n == 6174) {
//            printf("0\n");
//            continue;
//        }
//        int count = 0;
//        while (n != 6174) {
//            char s[5];
//            sprintf(s, "%04d", n);
//            char asc[5], desc[5];
//            strcpy(asc, s);
//            strcpy(desc, s);
//            qsort(asc, 4, sizeof(char), cmp_asc);
//            qsort(desc, 4, sizeof(char), cmp_desc);
//            int a = atoi(asc);
//            int b = atoi(desc);
//            n = b - a;
//            count++;
//        }
//        printf("%d\n", count);
//    }
//    return 0;
//}
