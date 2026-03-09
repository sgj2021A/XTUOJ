//Contest1074 - 2025年C语言提前作业-0x13（二分、双指针）
//问题 A: Range
//#include <stdio.h>
//#include <stdlib.h>
//
//int compare(const void *a,const void *b){
//	return *((long long*)a) - *((long long*)b);
//}
//
//int main(){
//	int s;
//	scanf("%d",&s);
//	
//	while(s--){
//		int n,c;
//		scanf("%d %d",&n,&c);
//		
//		long long *arr = (long long*)malloc(sizeof(long long) * n);
//		
//		for(int i = 0;i < n;i++){
//			scanf("%lld",arr + i);
//		}
//		
//		qsort(arr,n,sizeof(long long),compare);
//		
//		int result = 1000000;
//		
//		for(int left = 0;left < n - 1;left++){
//			int count = left;
//			long long temp = c * arr[left];
//			for(int right = n - 1;right > left;right--){
//				if(arr[right] > temp){
//					count++;
//				}else{
//					break;
//				}
//			}
//			result = result < count ? result : count;
//		}
//		
//		printf("%d\n",result);
//		free(arr);
//	}
//	
//	return 0;
//} 

//---------------------------------------------
//问题 B: Distance
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//int compare(const void *a,const void *b){
//	return (*(long long*)a - *(long long*)b);
//}
//
//int main(){
//	int s;
//	scanf("%d",&s);
//	
//	while(s--){
//		int n,m;
//		scanf("%d %d",&n,&m);
//		long long *arr_a = (long long*)malloc((sizeof(long long) * n));
//		long long *arr_b = (long long*)malloc((sizeof(long long) * m));
//		
//		
//		for(int i = 0;i < n;i++){
//			scanf("%lld",arr_a + i);
//		}
//		
//		for(int i = 0;i < m;i++){
//			scanf("%lld",arr_b + i);
//		}
//		
//		qsort(arr_a,n,sizeof(long long),compare);
//		qsort(arr_b,m,sizeof(long long),compare);
//		
//		
//		long long result = 10000000000;
//		
//		int left = 0,right = 0;
//		
//		while(left < n && right < m){
//			long long temp = llabs(arr_a[left] - arr_b[right]);
//			if(temp < result)result = temp;
//			
//			if(arr_a[left] < arr_b[right]){
//				left++;
//			}else{
//				right++;
//			}
//		}
//		printf("%lld\n",result);
//		free(arr_a);
//		free(arr_b);
//		
//	}
//	return 0;
//}

//--------------------------------------------------------
//问题 C: Buying Gifts
//#include <stdio.h>
//#include <stdlib.h>
//
//int compare(const void *a,const void *b){
//	return (*(long long*)a - *(long long*)b);
//}
//
//int main(){
//	int s;
//	scanf("%d",&s);
//	
//	while(s--){
//		int index = 0,min = 10000000;
//		int n,m;
//		scanf("%d %d",&n,&m);
//		
//		int *arr = (int*)malloc(sizeof(int) * n);
//		int *sub = (int*)malloc(sizeof(int) * (n + 1 - m));
//		
//		for(int i = 0;i < n;i++){
//			scanf("%d",arr + i);
//		}
//		qsort(arr,n,sizeof(int),compare);  
//		for(int i = 0;i <= n - m;i++){
//			sub[i] = arr[i + m - 1] - arr[i];
//			if(sub[i] < min){
//				min = sub[i];
//				index = i;
//			}
//		}
//		//test
////		printf("arr : ");
////		for(int i = 0;i < n;i++){
////			printf("%d ",arr[i]);
////		}
////		printf("\nsub : ");
////		for(int i = 0;i <= n - m;i++){
////			printf("%d ",sub[i]);
////		}
////		printf("\nindex : %d\n",index);
//		//test
//		int total = 0;
//		for(int i = index;i < index + m;i++){
//			total += arr[i];
//		}
//		
//		printf("%d %d\n",min,total);
//		free(arr);
//		free(sub);
//	}
//	return 0;
//} 
//---------------------------------------------------
//问题 D: 田忌赛马 II
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//int compare(const void *a,const void *b){
//	return (*(int*)a - *(int*)b);
//}
//long long gcd(long long a,long long b){
//	return b == 0 ? a : gcd(b,a % b);
//}
//int main(){
//	int s;
//	scanf("%d",&s);
//	
//	while(s--){
//		int n;
//		scanf("%d",&n);
//		int *A = (int*)malloc(sizeof(int) * n); 
//		int *B = (int*)malloc(sizeof(int) * n); 	
//		
//		for(int i = 0;i < n;i++){
//			scanf("%d",A + i);
//		}
//		for(int i = 0;i < n;i++){
//			scanf("%d",B + i);
//		}
//		
//		qsort(A,n,sizeof(int),compare);
//		qsort(B,n,sizeof(int),compare);
//		
//		long long win = 0,fail = 0;
//		
//		int index = 0;
//		for(int i = 0;i < n;i++){
//			int found = 0;
//			for(int j = index;j < n;j++){
//				if(A[i] < B[j]){
//					win += j;
//					fail += n - j;
//					index = j;
//					found = 1;
//					break;
//				}else if(A[i] == B[j]){
//					win += j;
//					fail += n - j - 1;
//					index = j;
//					found = 1; 
//					break;
//				}
//			}
//		    if(!found){
//		        win += n;  // 赢所有n场
//		        fail += 0; // 输0场
//		        index = n; // 后续都跳过
//		    } 
//		} 
//        long long total = win - fail;
////        for (int i = 0; i < n; i++) {
////            for (int j = 0; j < n; j++) {
////                if (A[i] > B[j]) {
////                    total += 1;      // 齐王赢
////                } else if (A[i] < B[j]) {
////                    total -= 1;      // 齐王输
////                }
////                // 平局不加不减
////            }
////        }		
//			
//        long long result = 200 * total;
//        if (result % n == 0) {
//            printf("%lld\n", result / n);
//        } else {
//            // 处理负号
//            int sign = (result < 0) ? -1 : 1;
//            long long abs_result = llabs(result);
//            long long g = gcd(abs_result, n);
//            
//            printf("%lld/%lld\n", sign * abs_result / g, n / g);
//        }
//		free(A);
//		free(B); 
//	}
//	
//	return 0;
//}
//---------------------------------------------------
//问题 E: 最长连续子串
//#include <stdio.h>
//#include <string.h>
//
//int main(){
//	char str[1001];
//	
//	while(scanf("%s",str) != EOF){
//		int len = strlen(str);
//		if(len == 1){
//			printf("1\n");
//			continue;
//		}
//		int max = 1;
//		for(int i = 0;i < len - 1;i++){
//			if(str[i] + 1 == str[i + 1]){
//				int temp = 2;
//				for(int j = i + 2;j < len;j++){
//					if(str[j] - 1 == str[j - 1]){
//						temp++;
//					}else{ 
//						i = j - 1; 
//						break;						
//					}
//				}
//				max = max > temp ? max : temp;
//			}
//		}
//		printf("%d\n",max);
//	}
//	return 0;
//}
//---------------------------------------------------
//问题 F: 字符不重复子串
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX 27
//typedef struct node{
//	char *str;
//	struct node *next;
//}node;
//
//typedef struct{
//	node *bucket[MAX];
//}hash;
//
//int compare(const void *a, const void *b) {
//    return strcmp(*(const char **)a, *(const char **)b);
//}
//
//hash* hashCreate(){
//	hash *list = (hash*)malloc(sizeof(hash));
//	for(int i = 0;i < MAX;i++){
//		list->bucket[i] = NULL;
//	}
//	return list;
//}
//
//int hashFound(hash *list,char *str){
//	int index = strlen(str);
//	node *item = list->bucket[index];
//	while(item != NULL){
//		if(strcmp(str,item->str) == 0){
//			return 0; 
//		}else{
//			item = item->next;
//		}	
//	} 
//	return index;
//}
//
//int hashInsert(hash *list,char *str){
//	int index = hashFound(list,str);
//	if(!index){
//		return 0;
//	}
//	node *item = (node*)malloc(sizeof(node));
//	item->str = strdup(str);
//	item->next = list->bucket[index];
//	list->bucket[index] = item;
//	return 1; 
//}
//
//void hashClear(hash *list){
//	node *item;
//	for(int i = 0;i < MAX;i++){
//		item = list->bucket[i];
//		while(item != NULL){
//			node *temp = item;
//			item = item->next;
//			free(temp->str);
//			free(temp);
//		}
//	}
//	free(list);
//}
//
//int main(){
//	char str[10001]; 
//	while(scanf("%s",str) != EOF){
//		int len = strlen(str);
//		hash *list = hashCreate();
//		
//		for(int i = 0;i < len;i++){
//			if(str[i] != str[i + 1]){
//				int bucket[26] = {0},index = 0;
//				char str_py[10001] = {0};
//				for(int j = i;j <= len;j++){
//					if(str[j] == '\0'){
//						str_py[index] = '\0';
//						hashInsert(list,str_py);
//						break;
//					}else if(!bucket[str[j] - 'a']){
//						bucket[str[j] - 'a'] = 1;
//						str_py[index++] = str[j];
//					}else{
//						i = j - 1;
//						str_py[index] = '\0';
//						hashInsert(list,str_py);
//						break;
//					}
//				}
//				
//			}
//			
//		}
//		
//		int max_len = 0;
//		
//		for(int i = 1;i <= MAX;i++){
//			if(list->bucket[i] != NULL){
//				max_len = i;
//			}
//		}
//		
//		int count = 0;
//		node *temp = list->bucket[max_len];
//		while(temp != NULL){
//			count++;
//			temp = temp->next;
//		}
//		
//		if(count == 0){
//			printf("0\n");
//			hashClear(list);
//			continue;
//		}		
//		
//		char** result = (char**)malloc(sizeof(char*) * count);
//		temp = list->bucket[max_len];
//		int location = 0;
//		
//		while(temp != NULL){
//			result[location++] = strdup(temp->str);
//			temp = temp->next;
//		}
//		
//		qsort(result,count,sizeof(char *),compare);	
//		printf("%d\n",max_len);
//        for (int i = 0; i < count; i++) {
//            printf("%s\n", result[i]);
//            free(result[i]);  // 释放深拷贝的字符串
//        }	
//        free(result);
//		hashClear(list);
//	}
//	
//	return 0;
//} 
//哈希表问题但是不知道问题出现在哪里 
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX 27
//typedef struct node{
//	char *str;
//	struct node *next;
//}node;
//
//typedef struct{
//	node *bucket[MAX];
//}hash;
//
//int compare(const void *a, const void *b) {
//    return strcmp(*(const char **)a, *(const char **)b);
//}
//
//hash* hashCreate(){
//	hash *list = (hash*)malloc(sizeof(hash));
//	for(int i = 0;i < MAX;i++){
//		list->bucket[i] = NULL;
//	}
//	return list;
//}
//
//int hashFound(hash *list,char *str){
//	int index = strlen(str);
//	node *item = list->bucket[index];
//	while(item != NULL){
//		if(strcmp(str,item->str) == 0){
//			return 0; 
//		}else{
//			item = item->next;
//		}	
//	} 
//	return index;
//}
//
//int hashInsert(hash *list,char *str){
//	int index = hashFound(list,str);
//	if(!index){
//		return 0;
//	}
//	node *item = (node*)malloc(sizeof(node));
//	item->str = strdup(str);
//	item->next = list->bucket[index];
//	list->bucket[index] = item;
//	return 1; 
//}
//
//void hashClear(hash *list){
//	node *item;
//	for(int i = 0;i < MAX;i++){
//		item = list->bucket[i];
//		while(item != NULL){
//			node *temp = item;
//			item = item->next;
//			free(temp->str);
//			free(temp);
//		}
//	}
//	free(list);
//}
//
//int main(){
//	char str[10001]; 
//	while(scanf("%s",str) != EOF){
//		int len = strlen(str);
//		hash *list = hashCreate();
//		
//		for(int i = 0;i < len;i++){
//			// 为每个起始位置生成不重复字符的子串
//			int bucket[26] = {0};
//			char str_py[10001] = {0};
//			int index = 0;
//			
//			for(int j = i;j < len;j++){
//				if(!bucket[str[j] - 'a']){
//					bucket[str[j] - 'a'] = 1;
//					str_py[index++] = str[j];
//					str_py[index] = '\0'; // 确保字符串正确终止
//					hashInsert(list, str_py);
//				}else{
//					break;
//				}
//			}
//		}
//		
//		int max_len = 0;
//		
//		for(int i = 1;i < MAX;i++){
//			if(list->bucket[i] != NULL){
//				max_len = i;
//			}
//		}
//		
//		// 计算最大长度子串的数量
//		int count = 0;
//		node *temp = list->bucket[max_len];
//		while(temp != NULL){
//			count++;
//			temp = temp->next;
//		}
//		
//		if(count == 0){
//			printf("0\n");
//			hashClear(list);
//			continue;
//		}
//		
//		char** result = (char**)malloc(sizeof(char*) * count);
//		temp = list->bucket[max_len];
//		int location = 0;
//		while(temp != NULL){
//			result[location++] = strdup(temp->str);
//			temp = temp->next;
//		}
//		
//		qsort(result,count,sizeof(char *),compare);	
//		printf("%d\n",max_len);
//		for(int i = 0;i < count;i++){
//			printf("%s\n",result[i]);
//			free(result[i]);  // 释放深拷贝的字符串
//		}	
//		free(result);
//		hashClear(list);
//	}
//	
//	return 0;
//}
//时间超限 
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int compare(const void *a, const void *b) {
//    return strcmp(*(const char **)a, *(const char **)b);
//}
//int main(){
//	char str[10001];
//	while(scanf("%s",str) != EOF){
//		int len = strlen(str);
//		char **result = (char**)malloc(sizeof(char*) * len);
//		for(int i = 0;i < len;i++){
//			result[i] = (char*)malloc(sizeof(char) * (len + 1));
//		}		
//		
//		int index = 0;
//		int max_len = 0;
//		for(int i = 0;i < len;i++){
//			int bucket[26] = {0},location = 0;
//			char str_py[10001] = {0};
//			
//			for(int j = i;j < len;j++){
//				if(bucket[str[j] - 'a'] == 0){
//					bucket[str[j] - 'a'] = 1;
//					str_py[location++] = str[j]; 
//				}else{
//					str_py[location] = '\0';
//					if(location == max_len){
//						strcpy(result[index++],str_py); 
//					}else if(location > max_len){
//						max_len = location; 
//						index = 0;
//						strcpy(result[index++],str_py); 
//					}
//					break;
//				}
//			}	
//		}
//		
//		if(max_len == 0){
//			printf("0\n");
//			for(int i = 0;i < len;i++){
//				free(result[i]);
//			}
//			free(result);
//			continue;
//		}
//		
//		qsort(result,index,sizeof(char *),compare);
//		
//		printf("%d\n",max_len);
//		
//		printf("%s\n",result[0]);
//		for(int i = 1;i < index;i++){
//			if(strcmp(result[i],result[i-1]) != 0){
//				printf("%s\n",result[i]);
//			}
//		}
//		
//		for(int i = 0;i < len;i++){
//			free(result[i]);
//		}
//		free(result);
//	}
//	return 0; 
//}
//判题时时间超限，不知道为啥 
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int compare(const void *a, const void *b) {
//    return strcmp(*(const char **)a, *(const char **)b);
//}
//
//int main(){
//	char str[10001];
//	while(scanf("%s",str) != EOF){
//		int len = strlen(str);
//		
//		// 找到最长不重复子串的长度
//		int max_len = 0;
//		for(int i = 0;i < len;i++){
//			int bucket[256] = {0};
//			int current_len = 0;
//			
//			for(int j = i;j < len;j++){
//				if(bucket[(unsigned char)str[j]]){
//					break;
//				}
//				bucket[(unsigned char)str[j]] = 1;
//				current_len++;
//				
//				if(current_len > max_len){
//					max_len = current_len;
//				}
//			}
//		}
//		
//		// 收集所有最长不重复子串
//		char **result = (char**)malloc(sizeof(char*) * len);
//		for(int i = 0;i < len;i++){
//			result[i] = (char*)malloc(sizeof(char) * (max_len + 1));
//		}
//		int index = 0;
//		
//		for(int i = 0;i <= len - max_len;i++){
//			int bucket[256] = {0};
//			int valid = 1;
//			
//			// 检查当前子串是否有重复字符
//			for(int j = i;j < i + max_len;j++){
//				if(bucket[(unsigned char)str[j]]){
//					valid = 0;
//					break;
//				}
//				bucket[(unsigned char)str[j]] = 1;
//			}
//			
//			if(valid){
//				strncpy(result[index], str + i, max_len);
//				result[index][max_len] = '\0';
//				index++;
//			}
//		}
//		
//		if(max_len == 0){
//			printf("0\n");
//			for(int i = 0;i < len;i++){
//				free(result[i]);
//			}
//			free(result);
//			continue;
//		}
//		
//		qsort(result,index,sizeof(char *),compare);
//		
//		printf("%d\n",max_len);
//		printf("%s\n",result[0]);
//		for(int i = 1;i < index;i++){
//			if(strcmp(result[i],result[i-1]) != 0){
//				printf("%s\n",result[i]);
//			}
//		}
//		
//		for(int i = 0;i < len;i++){
//			free(result[i]);
//		}
//		free(result);
//	}
//	return 0; 
//}

//-----------------------------------------
//问题 G: 相同的数
//#include<stdio.h>
//#include<stdlib.h>
//
//int compare(const void *a,const void *b){
//      return *(int*)a - *(int*)b;
//}
//
//int main(){
//      int s;
//      scanf("%d",&s);
//      
//      while(s--){
//              int a,c,m,n;
//              scanf("%d %d %d %d",&a,&c,&m,&n);
//              
//              int *X = (int*)malloc(sizeof(int) * m);
//              
//              X[0] = 0;
//              
//              for(int i = 1;i < m;i++){
//                      X[i] = (a * X[i - 1] % m + c) % m;
//              }                       
//              
//              qsort(X,m,sizeof(int),compare);
//              
//              int max = 0;
//              int index = 0;
//              for(int i = X[0] + 1;i <= X[m - 1] + 1;i++){
//                      int temp = 0;
//                      for(int j = index;j < m;j++){
//                              if(X[j] >= i)break;
//                              if(X[j] < i){
//                                      if(i - X[j] <= n){
//                                              temp++; 
//                                      }else{
//                                              index = j;
//                                              //printf("Change\n");
//                                      }
//                              }
//                      }
//                      //printf("i : %d temp : %d index : %d\n",i,temp,index);
//                      if(temp > max){
//                              max = temp;     
//                      }
//              }
//              printf("%d\n",max);
//              //test
////            printf("Arr : ");
////            for(int i = 0;i < m;i++){
////                    printf("%d ",X[i]);
////            }
////            printf("\n");
//              //test
//              
//              free(X);
//      }
//      
//      return 0;
//}

//Time OUT
//#include<stdio.h>
//#include<stdlib.h>
//int compare(const void *a,const void *b){
//      return *(int*)a - *(int*)b;
//}
//
//int main(){
//      int s;
//      scanf("%d",&s);
//      
//      while(s--){
//              int a,c,m,n;
//              scanf("%d %d %d %d",&a,&c,&m,&n);
//              
//              int *X = (int*)malloc(sizeof(int) * m);
//              
//              X[0] = 0;
//              
//              for(int i = 1;i < m;i++){
//                      X[i] = (a * X[i - 1] % m + c) % m;
//              }                       
//              
//              qsort(X,m,sizeof(int),compare);
//              
//              int result = 0;
//              for(int i = m - 1;i >= 0;i--){
//                      int temp = X[i] + 1;
//                      int total = 0;
//                      for(int j = i;j >= 0;j--){
//                              if(temp - X[j] <= n){
////                                    printf("X : %d ",X[j]);
//                                      total++;
//                              }else{
//                                      break;
//                              }
//                      }
//                      if(result < total)result = total;
//                      //printf("i : %d total : %d\n",i,total);
//              }
//              
//              printf("%d\n",result);
//              
//              //test
////            printf("Arr : ");
////            for(int i = 0;i < m;i++){
////                    printf("%d ",X[i]);
////            }
////            printf("\n");
//              //test
//              
//              free(X);
//      }
//      
//      return 0;
//}

//Time OUT
//#include<stdio.h>
//#include<stdlib.h>
//
//int main(){
//    int T;
//    scanf("%d",&T);
//    
//    while(T--){
//        int a,c,m,n;
//        scanf("%d %d %d %d",&a,&c,&m,&n);
//        
//        // 生成序列并统计频率
//        int *freq = (int*)calloc(m, sizeof(int));
//        long long x = 0;
//        freq[0]++;
//        
//        for(int i = 1;i < m;i++){
//            x = (a * x + c) % m;
//            freq[x]++;
//        }
//        
//        // 差分数组
//        int max_size = m + n;
//        int *diff = (int*)calloc(max_size, sizeof(int));
//        
//        // 标记区间
//        for(int v = 0;v < m;v++){
//            if(freq[v] > 0){
//                int left = v + 1;
//                int right = v + n;
//                diff[left] += freq[v];
//                if(right + 1 < max_size){
//                    diff[right + 1] -= freq[v];
//                }
//            }
//        }
//        
//        // 计算前缀和找最大值
//        int current = 0;
//        int max_count = 0;
//        for(int i = 1;i <= m + n;i++){
//            current += diff[i];
//            if(current > max_count){
//                max_count = current;
//            }
//        }
//        
//        printf("%d\n",max_count);
//        
//        free(freq);
//        free(diff);
//    }
//    
//    return 0;
//}
//---------------------------------------------------
//问题 H: 括号

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main(){
//      char str[20001];
//      
//      while(scanf("%s",str) != EOF){
//              int len = strlen(str);
//              int *pre_L = (int*)calloc(len,sizeof(int));
//              int *pre_R = (int*)calloc(len,sizeof(int));
//              pre_L[0] = 0;
//              pre_R[0] = 0;
//      
//              for(int i = 0;i < len;i++){
//                      if(i > 0){
//                              pre_R[i] = pre_R[i - 1];
//                      }
//                      if(str[i] == '('){
//                              pre_L[i]++;
//                      }else if(str[i] == ')'){
//                              pre_R[i]++;
//                      }
//              }
//              
//              int total_L = pre_L[len - 1];
//              
//              //test
////            printf("pre_L : ");
////            for(int i = 0;i < len;i++){
////                    printf("%d ",pre_L[i]);
////            }
////            printf("\npre_R : ");
////            for(int i = 0;i < len;i++){
////                    printf("%d ",pre_R[i]);
////            }               
////            printf("\n");
//              //test
//              
//              long long result = 0;
//              for(int i = 0;i < len;i++){
//                      if(pre_L[i] != 0){
//                              result += (pre_R[len - 1] - pre_R[i]);
//                      }
//              }       
//              printf("%lld\n",result);
//              free(pre_L);
//              free(pre_R);
//      }
//      
//      return 0;
//}

//-----------------------------------------------
//问题 I: substring
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main(){
//      char str[2001];
//      while(scanf("%s",str) != EOF){
//              int len = strlen(str);
//              //printf("total : %d\n",len);
//              if(len < 26){
//                      printf("0\n");
//                      continue;
//              }
//              int result = 100000;
//              for(int i = 0;i < len - 25;i++){
//                      int bucket[26] = {0};
//                      int total = 0;
//                      //printf("i : %d\n",i);
//                      for(int j = i;j < len;j++){
//                              if(bucket[str[j] - 'a'] == 0){
//                                      bucket[str[j] - 'a']++;
//                                      total++;        
//                              }
//                              //printf("total : %d |",total);
//                              if(total == 26){
//                                      result = j - i + 1 < result ? j - i + 1 : result;
//                                      break;
//                              }
//                      }
//                      //printf("\n");
//              }
//              if(result == 100000){
//                      printf("0\n");
//              }else{
//                      printf("%d\n",result);                  
//              }
//      }
//      return 0;
//}

//-----------------------------------------------
//问题 J: 矩形
//#include <stdlib.h>
//#include <stdio.h>
//
//int compare(const void *a, const void *b) {
//    long long x = *(const long long*)a;
//    long long y = *(const long long*)b;
//    return (x > y) - (x < y); 
//}
//
//int main(){
//        int n;
//        unsigned long long L,R;
//        scanf("%d %llu %llu",&n,&L,&R);
//        long long *arr = (long long*)malloc(sizeof(long long) * n);
//        
//        for(int i = 0;i < n;i++){
//                scanf("%lld",arr + i);
//        }
//        int result = 0;
//        qsort(arr,n,sizeof(long long),compare);
//        
//        //test
//        printf("arr : ");
//        for(int i = 0;i < n;i++){
//                printf("%lld ",arr[i]);
//        }
//        printf("\n");
//        //test
//        
////      long long *pre = (long long*)malloc(sizeof(long long) * n);
////      int index = 0;
////      unsigned long long S_temp = 0;
////      
////      pre[index++] = arr[0];
////      if(arr[0] == arr[1]){
////              S_temp = arr[1] * arr[0];
////              pre[index++] = arr[0];
////              if(S_temp <= R && S_temp >= L)result++;
////      }
////      for(int i = 1;i < n;i++){
////              if(arr[i] == arr[i - 1]){
////                      if(arr[i] * arr[i - 1] != S_temp){
////                              S_temp = arr[i] * arr[i - 1];
////                              pre[index++] = arr[i];
////                              if(S_temp <= R && S_temp >= L)result++;
////                      }
////              }else{
////                      pre[index++] = arr[i];
////              }
////      }       
//        
//        //test
////      printf("pre : ");
////      for(int i = 0;i < index;i++){
////              printf("%lld ",pre[i]);
////      }
////      printf("\n");
//        //test
//                
////      for(int i = 0;i < n - 1;i++){
////              if(i != 0){
////                      if(arr[i] == arr[i - 1]){
////                              //printf("change i : %d\n",i);
////                              continue;
////                      }                       
////              }
////              for(int j = i + 1;j < n;j++){
////                      if(j != i + 1){
////                              if(arr[j] == arr[j - 1]){
////                                      //printf("change j : %d\n",j);
////                                      continue;
////                              }
////                      }
////                      //printf("arr[i] : %d arr[j] : %d\n",arr[i],arr[j]);
////                      
////                      unsigned long long temp = (unsigned long long)arr[i] * arr[j];
////                      
////                      if(temp >= L && temp <= R)result++;
////                      if(temp > R)break;
////              }
////      }
//                
//        
//        
//        printf("%d",result);    
//        free(arr);
//        //free(pre);
//        return 0;
//}
//修改
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct{
//	long long num;
//	long long size;
//}node;
//
//int compare(const void *a, const void *b) {
//    long long diff = *(long long*)a - *(long long*)b;
//    return diff > 0 ? 1 : (diff < 0 ? -1 : 0);
//}
//
//int main(){
//	int n;
//	long long L,R;
//	
//	scanf("%d %lld %lld",&n,&L,&R);
//	
//	long long *arr = calloc(n,sizeof(long long));
//	
//	for(int i = 0;i < n;i++){
//		scanf("%lld",arr + i);
//	}
//	
//	qsort(arr,n,sizeof(long long),compare);
//	
//	node *total = (node*)malloc(sizeof(node) * n);
//	
//	int index = 0;
//	total[0].num = arr[0];
//	total[0].size = 1;
//	for(int i = 1;i < n;i++){
//		if(arr[i] == arr[i - 1]){
//			total[index].size++;
//		}else{
//			index++;
//			total[index].num = arr[i];
//			total[index].size = 1;
//		}
//	}
//	index++;
//	 
//	//寻找可以形成正方形 
//	long long total_square = 0;
//	for(int i = 0;i < index;i++){
//		if(total[i].size >= 2){
//			long long temp = total[i].num * total[i].num;
//			if(temp <= R && temp >= L){
//				total_square++;
//			}
//		}
//	} 
//	//寻找所有可以成为的正方形
//	long long total_num_square = 0;
//	for(int i = 0;i < index;i++){
//		long long temp = total[i].num * total[i].num;
//		if(temp <= R && temp >= L){
//			total_num_square++;
//		}
//	} 	 
//	//寻找最右边的边界
//	long long total_R = 0;
//	int j = index - 1;
//	for(int i = 0;i < index;i++){
//		while(total[i].num * total[j].num > R && j >= 0){
//			j--;
//		}
//		if(j >= 0){
//			total_R += j + 1;	
//		}
//	} 
//	//寻找最左边的边界
//	long long total_L = 0;
//	j = index - 1;
//	for(int i = 0;i < index;i++){
//		while(total[i].num * total[j].num >= L && j >= 0){
//			j--;
//		}
//		if(j >= 0){
//			total_L += j + 1;	
//		}
//	} 	 
//	//统计
//	long long _total_ = total_R - total_L - total_num_square;
//	long long result = _total_ / 2 + total_square;
//	
//	printf("%lld",result);
//	 
//	//test
////	printf("\ntotal_square : %lld total_num_square : %lld total_R : %lld total_L : %lld\n",total_square,total_num_square,total_R,total_L);
////	printf("arr : ");
////	for(int i = 0;i < n;i++){
////		printf("%lld ",arr[i]);
////	}
////	printf("\n");
////	printf("index : %d \ntotal :\n",index); 
////	for(int i = 0;i < index;i++){
////		printf("num : %lld size : %d\n",total[i].num,total[i].size);
////	}
//	//test
//	
//	free(total);
//	free(arr);
//	return 0; 
//} 
//-----------------------------------------------------
//问题 K: 结巴
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main(){
//	int s;
//	scanf("%d",&s);
//	
//	while(s--){
//		char a[100001];
//		char b[100001];
//		
//		scanf("%s",a);
//		scanf("%s",b);
//		
//		int len_a = strlen(a);
//		int len_b = strlen(b);
//		
//		int index_a = 0;
//		int index_b = 0;
//		int found = 0;
//		int deference = 0;
//		//printf("len_a : %d len_b : %d\n",len_a,len_b);
//		while(index_a < len_a || index_b < len_b){
//			if(index_b == len_b - 1){
//				//printf("#2 : exam %d %d\n",index_a + 1,index_b + 1);
//				index_a++;
//				if(a[index_a] != b[index_b]){
//					deference++;
//					if(deference > 1){
//						//printf("change\n"); 
//						found = 1;
//						break;
//					}
//					if(index_a == len_a){
//						break;
//					}					
//				}
//			}else{
//				//printf("#1 : exam %d %d\n",index_a + 1,index_b + 1); 
//				if(a[index_a] == b[index_b]){
//					deference = 0;
//					index_a++;
//					index_b++;
//				}else{
//					index_b++;
//					deference++;
//					if(deference > 1){
//						//printf("change\n"); 
//						found = 1;
//						break;
//					}
//				}	
//			}
//		}
//		
//		if(found){
//			printf("Yes\n");
//		}else{
//			printf("No\n");
//		}
//		 
//		
//	}
//	return 0;
//} 
//修改 
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
// 
//typedef struct{
//    char str[100001];
//    int num[100001];
//    int size;
//}node;
// 
//void process(node *item,char *str){
//    int len = strlen(str);
//    int index = 0;
//     
//    item->num[0] = 1;
//    item->str[0] = str[0];
//    index++;
//    for(int i = 1;i < len;i++){
//        if(str[i] != str[i - 1]){
//            item->str[index] = str[i];
//            item->num[index] = 1;
//            index++;
//        }else{
//            item->num[index - 1]++;
//        }
//    }
//    item->str[index] = '\0';
//    item->size = index;
//}
//int judge(int a,int b){
//	if(a == b)return 0;
//	if(2*b >= a)return 0;
//	return 1;
//}
//int main(){
//    int s;
//    scanf("%d",&s);
//     
//    while(s--){
//        char s1[100001],s2[100001];
//         
//        scanf("%s",s1);
//        scanf("%s",s2);
//         
//        node a,b;
//        //init
//        for(int i = 0;i < 100001;i++){
//            a.num[i] = 0;
//            b.num[i] = 0;
//        } 
//        process(&a,s1);
//        process(&b,s2); 
//        //init
//         
//        if(strcmp(a.str,b.str) != 0){
//            printf("Yes\n");
//            continue;
//        }
//        int found = 0;
//        for(int i = 0;i < a.size;i++){
//        	int max_num = a.num[i] > b.num[i] ? a.num[i] : b.num[i];
//			int min_num = a.num[i] < b.num[i] ? a.num[i] : b.num[i];  
//            if(judge(max_num,min_num)){
//                found = 1;
//                break;
//            }
//        }
//        if(found){
//            printf("Yes\n");
//        }else{
//            printf("No\n");
//        }
//        //test
////      printf("a : \n");
////      printf("%s\n",a.str);
////      for(int i = 0;i < a.size;i++){
////          printf("%d ",a.num[i]);
////      }
////      printf("\n");
////      printf("b : \n");
////      printf("%s\n",b.str);
////      for(int i = 0;i < b.size;i++){
////          printf("%d ",b.num[i]);
////      }
////      printf("\n");
//        //test
//             
//    }
//     
//    return 0;
//}

//--------------------------------------------------------
//问题 L: 子串
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define max(a,b) ((a) > (b) ? (a) : (b))
//
//int find(int **bucket,int L,int R,char c){
//	if(L == 0)
//		return bucket[c - 'a'][R];
//	else return bucket[c - 'a'][R] - bucket[c - 'a'][L - 1];
//}
//
//int check(int **bucket,int L,int R,int m){
//	for(int i = 0;i < 26;i++){
//		int count;
//		if(L == 0){
//			count = bucket[i][R];
//		}else{
//			count = bucket[i][R] - bucket[i][L - 1];
//		}
//		if(count > m){
//			return 0;
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
//		int n,m;
//		scanf("%d %d",&n,&m);
//		
//		char *str = (char*)malloc(sizeof(char) * (n + 1));
//		
//		scanf("%s",str);
//		
//		int **bucket = (int**)calloc(26,sizeof(int*));
//		for(int i = 0;i < 26;i++){
//			bucket[i] = (int*)calloc(n,sizeof(int));
//		}
//		//bucket[26][n]
//		//预处理字串 
//		bucket[str[0] - 'a'][0]++;
//		for(int i = 1;i < n;i++){
//			for(int j = 0;j < 26;j++){
//				bucket[j][i] = bucket[j][i - 1];
//			}
//			bucket[str[i] - 'a'][i]++;
//		}
//		
////		int result = 1;
////		for(int i = 0;i < n - result;i++){
////			//寻找第一个字串
////			int total_1 = 0;
////			int left;
////			for(int left = i;left < n - 1;left++){
////				if(find(bucket,i,left,str[left]) <= m)total_1++;
////				else break;
////			}
////			//寻找第二个字串(需要最大)
////			int total_2 = -1;
////			int left_R = left + 1,right_R = left + 1;
////			while(left_R < n && right_R < n){
////				if(find(bucket,left_R,right_R,str[right_R]) <= m){
////					right_R++;
//////					printf("right_R++ ： %d\n",right_R); 
////				}else if(right_R == n - 1){
////					left_R++;
//////					printf("left_R++ ： %d\n",left_R); 
////					total_2 = total_2 >  right_R - left_R + 1 ? total_2 : right_R - left_R;
////				}else{
////					total_2 = total_2 >  right_R - left_R + 1 ? total_2 : right_R - left_R;
////					left_R++;
//////					printf("left_R++\n"); 
////				}
////			}
////			total_2 = total_2 >  right_R - left_R + 1 ? total_2 : right_R - left_R + 1;
//////			printf("left_R : %d right_R: %d total_2: %d\n",left_R,right_R,total_2);
////			result = total_1 + total_2 > result ? total_1 + total_2 : result;
//////			printf("total_1 : %d total_2: %d\n",total_1,total_2); 
////		}
//		int result = 0;
//		for(int min = 1;min < n;min++){
//			//查询左侧字符串
//			int left = 0,right = 0;
//			int max_L = 0;
//			
//			while(right < min){
//				if(find(bucket,left,right,str[right]) <= m){
//					right++;
//				}else{
//					max_L = max_L > right - left + 1 ? max_L : right - left + 1;
//					left++;
//				}
//			}
//			//查询右侧字符串 
//			left = n - 1,right = n - 1;
//			int max_R = 0;
//			
//			while(left >= min){
//				if(find(bucket,left,right,str[right]) <= m){
//					left--;
//				}else{
//					max_R = max_R > right - left + 1 ? max_L : right - left + 1;
//					right++;
//				}
//			}			
//			
//			result = result > max_R + max_L ? result : max_R + max_L;
//		}
//		
//		printf("%d\n",result); 
//			
//		//test
////		printf("bucket :\n");
////		for(int i = 0;i < n;i++){
////			for(int j = 0;j < 26;j++){
////				printf("%d ",bucket[j][i]);
////			}
////			printf("\n");
////		}
//		//test
//		
//		free(str);
//		for(int i = 0;i < 26;i++){
//			free(bucket[i]);
//		}
//		free(bucket);
//	}
//	
//	return 0;
//} 
//修改 
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define max(a,b) ((a) > (b) ? (a) : (b))
//
//int main(){
//	int s;
//	scanf("%d",&s);
//	
//	while(s--){
//		int n,m;
//		scanf("%d %d",&n,&m);
//		
//		char *str = (char*)malloc(sizeof(char) * (n + 1));
//		
//		scanf("%s",str);
//		
//		int* total_L = (int*)calloc(n + 1,sizeof(int));
//		int* total_R = (int*)calloc(n + 1,sizeof(int));
//		
//		int bucket[26] = {0};
//		
//		int left_L = 0;
//		int total = 0;
//		for(int right_L = 0;right_L < n;right_L++){
//			bucket[str[right_L] - 'a']++;
//			while(bucket[str[right_L] - 'a'] > m){
//				bucket[str[left_L] - 'a']--;
//				left_L++;
//			}
//			total = max(total,right_L - left_L + 1);
//			total_L[right_L + 1] = total;
//		}
//		
//		int right_R = n - 1;
//		total = 0;
//		for(int i = 0;i < 26;i++){
//			bucket[i] = 0;
//		}
//		for(int left_R = n - 1;left_R >= 0;left_R--){
//			bucket[str[left_R] - 'a']++;
//			while(bucket[str[left_R] - 'a'] > m){
//				bucket[str[right_R] - 'a']--;
//				right_R--;
//			}
//			total = max(total,right_R - left_R + 1);
//			total_R[left_R] = total;			
//		}
//		
//		int result = 0;
//		for(int i = 1;i < n;i++){
//			result = max(result,total_L[i] + total_R[i]);
//		}
//		
//		printf("%d\n",result);
//		free(total_L);
//		free(total_R);
//		free(str);
//	}
//	return 0;
//}
