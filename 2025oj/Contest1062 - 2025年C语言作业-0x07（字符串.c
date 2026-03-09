//问题 A: 密码
//#include <stdio.h>
//#include <string.h>
//int process(char *str1,char *str2,int *c,int size){
//      for(int i=0;i<size;i++){
//              if(str1[i]>='A'&&str1[i]<='Z'){
//                      if(c[str1[i]-'A']!=str2[i] && c[str1[i]-'A']!=0){
//                              printf("No\n");
//                              return 0;
//                      }else{
//                              c[str1[i]-'A']=str2[i];
//                      }
//              }else{
//                      if(c[str1[i]-'a'+26]!=str2[i] && c[str1[i]-'a'+26]!=0){
//                              printf("No\n");
//                              return 0;
//                      }else{
//                              c[str1[i]-'a'+26]=str2[i];
//                      }
//              }
//      }
//      for(int i=0;i<52;i++){
//              for(int j=i+1;j<52;j++){
//                      if(c[i]==c[j]&&c[i]!=0){
//                              printf("No\n");
//                              return 0;
//                      }
//              }
//      }
//      printf("Yes\n");
//      return 0;
//}
//int main(){
//    int T=0;
//    char str1[1001],str2[1001];
//    int c[55];
//    scanf("%d",&T);
//    while(T--){
//              for(int i=0;i<52;i++){
//                      c[i]=0;
//              }
//        scanf("%s",str1);
//        scanf("%s",str2);
//          int size = strlen(str1);
//        process(str1,str2,c,size);
//    }
//}


//问题 B: 删除字符串
//#include<string.h>
//#include<stdio.h>
//#include<stdbool.h>
//#include<stdlib.h>
//struct str_new {
//	struct str_new *up;
//	char str[160];
//	struct str_new *down;
//};
//bool find(struct str_new *str1,const char *str2) {
//	struct str_new *head=str1;
//	while(head != NULL) {
//		if(strcmp(head->str,str2)==0) {
//			return true;
//		}
//		head = head->down;
//	}
//	return false;
//}
//void add_list(struct str_new **str1, const char *str2) {
//	struct str_new *new_node = malloc(sizeof(struct str_new));
//	strcpy(new_node->str, str2);
//	new_node->up = NULL;
//	new_node->down = NULL;
//	if (*str1 == NULL) {
//		*str1 = new_node;
//	} else {
//		struct str_new *head = *str1;
//		while (head->down != NULL) {
//			head = head->down;
//		}
//		head->down = new_node;
//		new_node->up = head;
//	}
//}
//
//void del_list(struct str_new **str1) {
//	struct str_new *head=*str1;
//	while(head != NULL) {
//		struct str_new *temp = head;
//		head = head->down;
//		free(temp);
//	}
//	*str1=NULL;
//}
//int number(struct str_new *str1) {
//	int i=0;
//	struct str_new *head = str1;
//	while(head != NULL) {
//		head=head->down;
//		i++;
//	}
//	return i;
//}
//void process(const char *str, const int *size) {
//    struct str_new *str_list = NULL;  // 初始化为NULL，避免内存泄漏
//    int n = *size;
//
//    // 遍历所有可能的删除区间
//    for (int i = 0; i < n; i++) {
//        for (int j = i; j < n; j++) {
//            // 构建删除区间[i,j]后剩下的字符串
//            char new_str[160] = {0};
//            int index = 0;
//            
//            // 添加删除区间前的部分
//            for (int k = 0; k < i; k++) {
//                new_str[index++] = str[k];
//            }
//            
//            // 添加删除区间后的部分
//            for (int k = j + 1; k < n; k++) {
//                new_str[index++] = str[k];
//            }
//            
//            // 跳过空字符串
//            if (index == 0) {
//                continue;
//            }
//            
//            // 检查是否已存在
//            if (!find(str_list, new_str)) {
//                add_list(&str_list, new_str);
//            }
//        }
//    }
//    
//    printf("%d\n", number(str_list));
//    del_list(&str_list);
//}
//int main() {
//	char str[160];
//	for(int k=1; k<=100; k++) {
//		scanf("%s",str);
//		int len = strlen(str);
//		process(str,&len);
//	}
//}
//优化
//#include <string.h>
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//struct str_new {
//	struct str_new *up;
//	char str[160];
//	struct str_new *down;
//};
//bool find(struct str_new *str1, const char *str2) {
//	struct str_new *head = str1;
//	while (head != NULL) {
//		if (strcmp(head->str, str2) == 0) {
//			return true;
//		}
//		head = head->down;
//	}
//	return false;
//}
//void add_list(struct str_new **str1, const char *str2) {
//	struct str_new *new_node = malloc(sizeof(struct str_new));
//	if (!new_node) {
//		perror("Memory allocation failed");
//		exit(EXIT_FAILURE);
//	}
//	strcpy(new_node->str, str2);
//	new_node->up = NULL;
//	new_node->down = NULL;
//	if (*str1 == NULL) {
//		*str1 = new_node;
//	} else {
//		struct str_new *head = *str1;
//		while (head->down != NULL) {
//			head = head->down;
//		}
//		head->down = new_node;
//		new_node->up = head;
//	}
//}
//void del_list(struct str_new **str1) {
//	if (*str1 == NULL) return;
//	struct str_new *head = *str1;
//	while (head != NULL) {
//		struct str_new *temp = head;
//		head = head->down;
//		free(temp);
//	}
//	*str1 = NULL;
//}
//int number(struct str_new *str1) {
//	int i = 0;
//	struct str_new *head = str1;
//	while (head != NULL) {
//		head = head->down;
//		i++;
//	}
//	return i-1;
//}
//void process(const char *str, const int *size) {
//	struct str_new *str_list = NULL;
//	for (int i = 0; i < *size; i++) {
//		for (int j = i; j <= *size; j++) {
//			if (j > i) {
//				char s[160] = {0};
//				int cs = 0;
//				for (int k = i; k < j; k++) {
//					s[cs] = str[k];
//					cs++;
//					if (cs >= 159) break;
//				}
//				s[cs] = '\0';
//				if (cs > 0 && !find(str_list, s)) {
//					add_list(&str_list, s);
//				}
//			}
//		}
//	}
//	printf("%d\n", number(str_list));
//	del_list(&str_list);
//}
//int main() {
//	char str[160];
//	for (int k = 1; k <= 100; k++) {
//		if (scanf("%159s", str) != 1) {
//			fprintf(stderr, "Input error\n");
//			continue;
//		}
//		int len = strlen(str);
//		process(str, &len);
//	}
//	return 0;
//}
//优化
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MOD1 1000000007
//#define MOD2 1000000009
//#define BASE1 131
//#define BASE2 13331
//
//typedef struct {
//    unsigned long long h1;
//    unsigned long long h2;
//} Node;
//
//unsigned long long pow1[151];
//unsigned long long pow2[151];
//
//int cmp(const void *a, const void *b) {
//    Node *pa = (Node*)a;
//    Node *pb = (Node*)b;
//    if (pa->h1 != pb->h1) {
//        return pa->h1 < pb->h1 ? -1 : 1;
//    }
//    if (pa->h2 != pb->h2) {
//        return pa->h2 < pb->h2 ? -1 : 1;
//    }
//    return 0;
//}
//
//int main() {
//    pow1[0] = 1;
//    pow2[0] = 1;
//    for (int i = 1; i <= 150; i++) {
//        pow1[i] = (pow1[i-1] * BASE1) % MOD1;
//        pow2[i] = (pow2[i-1] * BASE2) % MOD2;
//    }
//
//    char s[151];
//    while (scanf("%s", s) != EOF) {
//        int n = strlen(s);
//        unsigned long long H1a[151] = {0};
//        unsigned long long H1b[151] = {0};
//        for (int i = 0; i < n; i++) {
//            H1a[i+1] = (H1a[i] * BASE1 + s[i]) % MOD1;
//            H1b[i+1] = (H1b[i] * BASE2 + s[i]) % MOD2;
//        }
//
//        Node arr[11250];
//        int count = 0;
//        for (int i = 0; i <= n; i++) {
//            for (int j = i+1; j <= n; j++) {
//                if (i + n - j < 1) continue;
//                unsigned long long suffix1 = (H1a[n] - H1a[j] * pow1[n-j] % MOD1 + MOD1) % MOD1;
//                unsigned long long h1 = (H1a[i] * pow1[n-j] % MOD1 + suffix1) % MOD1;
//
//                unsigned long long suffix2 = (H1b[n] - H1b[j] * pow2[n-j] % MOD2 + MOD2) % MOD2;
//                unsigned long long h2 = (H1b[i] * pow2[n-j] % MOD2 + suffix2) % MOD2;
//
//                arr[count].h1 = h1;
//                arr[count].h2 = h2;
//                count++;
//            }
//        }
//
//        if (count == 0) {
//            printf("0\n");
//            continue;
//        }
//
//        qsort(arr, count, sizeof(Node), cmp);
//        int ans = 1;
//        for (int i = 1; i < count; i++) {
//            if (arr[i].h1 != arr[i-1].h1 || arr[i].h2 != arr[i-1].h2) {
//                ans++;
//            }
//        }
//        printf("%d\n", ans);
//    }
//    return 0;
//} 
//有问题（不知道问题在哪）AI思路 （哈希算法） 
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MOD1 1000000007
//#define MOD2 1000000009
//#define BASE 131
//
//typedef struct {
//    long long h1;
//    long long h2;
//} HashPair;
//
//int compare(const void *a, const void *b) {
//    HashPair *pa = (HashPair *)a;
//    HashPair *pb = (HashPair *)b;
//    if (pa->h1 != pb->h1) {
//        return pa->h1 < pb->h1 ? -1 : 1;
//    } else {
//        return pa->h2 < pb->h2 ? -1 : 1;
//    }
//}
//
//int main() {
//    char s[160];
//    while (scanf("%s", s) != EOF) {
//        int n = strlen(s);
//        long long p1[160], p2[160];
//        long long h1[160], h2[160];
//        p1[0] = 1;
//        p2[0] = 1;
//        h1[0] = 0;
//        h2[0] = 0;
//        for (int i = 1; i <= n; i++) {
//            p1[i] = (p1[i-1] * BASE) % MOD1;
//            p2[i] = (p2[i-1] * BASE) % MOD2;
//            h1[i] = (h1[i-1] * BASE + s[i-1]) % MOD1;
//            h2[i] = (h2[i-1] * BASE + s[i-1]) % MOD2;
//        }
//
//        int total_pairs = (n+1) * (n+2) / 2;
//        HashPair *pairs = (HashPair *)malloc(total_pairs * sizeof(HashPair));
//        int index = 0;
//        for (int i = 0; i <= n; i++) {
//            for (int j = i; j <= n; j++) {
//                int len_back = n - j;
//                long long back1 = (h1[n] - h1[j] * p1[len_back] % MOD1 + MOD1) % MOD1;
//                long long back2 = (h2[n] - h2[j] * p2[len_back] % MOD2 + MOD2) % MOD2;
//                long long total1 = (h1[i] * p1[len_back] % MOD1 + back1) % MOD1;
//                long long total2 = (h2[i] * p2[len_back] % MOD2 + back2) % MOD2;
//                pairs[index].h1 = total1;
//                pairs[index].h2 = total2;
//                index++;
//            }
//        }
//
//        qsort(pairs, index, sizeof(HashPair), compare);
//        int ans = 1;
//        for (int i = 1; i < index; i++) {
//            if (pairs[i].h1 != pairs[i-1].h1 || pairs[i].h2 != pairs[i-1].h2) {
//                ans++;
//            }
//        }
//        printf("%d\n", ans-2);
//        free(pairs);
//    }
//    return 0;
//}

//问题 C: 字符串的幂次
//#include <stdio.h>
//#include <string.h>
//
//int main(){
//	char str[10001];
//	for(int k=0;k<100;k++){
//		scanf("%s",str);
//		char str1[5001]={};
//		int len=strlen(str),min=1000001,number=0;
//		for(int i=1;i<=len/2;i++){
//			if(len%i==0){
//				for(int j=0;j<i;j++){
//					str1[j]=str[j];
//				}
//				number=0;
//				int cs=0;
//				for(int l=0;l<len/i;l++){
//					cs=0;
//					for(int j=(l+1)*i;j<(l+2)*i;j++){
//						if(str[j]!=str1[cs]){
//							number++;
//						}
//						cs++;
//					} 
//				}
//				if(min>number){
//					min=number;
//				}
//			}
//		}
//		printf("%d\n",min);
//	}
//	return 0;
//} 
//优化 
//#include <stdio.h>
//#include <string.h>
//#include <limits.h>
//
//int main() {
//    char str[10001];
//    for (int k = 0; k < 100; k++) {
//        scanf("%s", str);
//        int len = strlen(str);
//        int min_changes = len-1;
//        if(len==1){
//        	printf("0\n");
//        	continue;
//		}
//        for (int i = 1; i <= len / 2; i++) {
//            if (len % i != 0) continue; 
//            int changes = 0;
//            for (int j = i; j < len; j++) {
//                if (str[j] != str[j % i]) {
//                    changes++;
//                }
//            }
//            if (changes < min_changes) {
//                min_changes = changes;
//            }
//        }
//        if (min_changes == INT_MAX) {
//            min_changes = len - 1;
//   		}
//        printf("%d\n", min_changes);
//    }
//    return 0;
//}
////优化本方案
//#include <stdio.h>
//#include <string.h>
//#include <limits.h>
//
//int main() {
//    char str[10001];
//    while (scanf("%s", str) != EOF) {
//        int n = strlen(str);
//        int min_changes = INT_MAX;
//
//        for (int i = 1; i <= n / 2; i++) {
//            if (n % i != 0) continue;
//            int k = n / i;
//            int changes = 0;
//            for (int j = 0; j < i; j++) {
//                int freq[26] = {0};
//                for (int seg = 0; seg < k; seg++) {
//                    int idx = seg * i + j;
//                    char c = str[idx];
//                    freq[c - 'a']++;
//                }
//                int max_freq = 0;
//                for (int letter = 0; letter < 26; letter++) {
//                    if (freq[letter] > max_freq) {
//                        max_freq = freq[letter];
//                    }
//                }
//                changes += (k - max_freq);
//            }
//            if (changes < min_changes) {
//                min_changes = changes;
//            }
//        }
//
//        if (min_changes == INT_MAX) {
//            min_changes = n - 1; 
//        }
//        printf("%d\n", min_changes);
//    }
//    return 0;
//} 
//优化 ----
//#include <stdio.h>
//#include <string.h>
//
//#define MAX_LEN 10010
//#define ALPHABET 26
//
//char s[MAX_LEN];
//int count[5000][ALPHABET];
//
//int main() {
//    while (scanf("%s", s) != EOF) {
//        int n = strlen(s);
//        int min_change = n;
//
//        for (int l = 1; l <= n / 2; l++) {
//            if (n % l != 0) continue;
//            int k = n / l;
//            for (int i = 0; i < l; i++) {
//                for (int j = 0; j < ALPHABET; j++) {
//                    count[i][j] = 0;
//                }
//            }
//            for (int j = 0; j < k; j++) {
//                for (int i = 0; i < l; i++) {
//                    int idx = j * l + i;
//                    char c = s[idx];
//                    count[i][c - 'a']++;
//                }
//            }
//            int total_change = 0;
//            for (int i = 0; i < l; i++) {
//                int max_count = 0;
//                for (int j = 0; j < ALPHABET; j++) {
//                    if (count[i][j] > max_count) {
//                        max_count = count[i][j];
//                    }
//                }
//                total_change += (k - max_count);
//            }
//            if (total_change < min_change) {
//                min_change = total_change;
//            }
//        }
//        printf("%d\n", min_change);
//    }
//    return 0;
//} 

//问题 D: 字符串_1
//#include <stdio.h>
//#include <string.h>
//#include <limits.h>
//#include <stdlib.h> 
//int char_distance(char a, char b) {
//    int diff = abs(a - b);
//    return (diff <= 13) ? diff : 26 - diff;
//}
//int main(){
//	int t=0;
//	scanf("%d",&t);
//	while(t--){
//		char str1[1001],str2[1001];
//		int min=0;
//		scanf("%s",str1);
//		scanf("%s",str2);
//		int cs=0,cs1=0;
//		int len=strlen(str1);
//		for(int j=0;j<len;j++){
//			min=min+char_distance(str1[j],str2[j]);
//		}			
//		for(int i=0;i<len-1;i++){
//			cs1++;
//			char temp=str1[len-1]; 
//			for(int j=len-1;j>0;j--){
//				str1[j]=str1[j-1];			
//			}
//			int cost = (cs1 < len - cs1) ? cs1 : len - cs1;
//			str1[0]=temp;
//			cs=cost;
//			for(int j=0;j<len;j++){
//				cs=cs+char_distance(str1[j],str2[j]);					
//			}	
//			if(cs<min)min=cs;	
//		}
//		printf("%d\n",min);
//	}
//} 

//问题 E: 共同的子串
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<stdbool.h>
//#define Table_Size 100
//typedef struct HashNode{
//	char *value;
//	struct HashNode *next;
//}HashNode;
//typedef struct HashTable{
//	HashNode *bucket[Table_Size];
//}HashTable;
//HashTable *CreateHashTable(){
//	HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
//	for(int i=0;i<Table_Size;i++){
//		ht->bucket[i]=NULL;
//	}
//	return ht;
//}
//unsigned int hash(int key){
//	return key%Table_Size;
//}
//void insert(HashTable *ht,int key,char *str){
//	HashNode *newnode = (HashNode *)malloc(sizeof(HashNode));
//	unsigned index = hash(key); 
//	newnode->next = ht->bucket[index];
//	newnode->value = (char *)malloc(strlen(str)+1);
//	strcpy(newnode->value,str);
//	ht->bucket[index] = newnode; 
//}
//void freeTable(HashTable *ht){
//	for(int i=0;i<Table_Size;i++){
//		HashNode *current = ht->bucket[i];
//		while(current){
//			HashNode *temp = current;
//			current = current->next;
//			free(temp->value);
//			free(temp);
//		} 
//	}
//	free(ht);
//}
//bool find(HashTable *ht,int key,char *str){
//	unsigned int index = hash(key);
//	HashNode *current = ht->bucket[index];
//	while(current){
//		if(strcmp(str,current->value)==0){
//			return true;
//		}
//		current = current->next;
//	}
//	return false;
//}
//bool found(char *str1,char *str2,HashTable *ht,int start,int end){
//	char str[101];
//	int len=end-start+1;
//	int len2=strlen(str2);
//	int find_pd=0;
//	int cs=0;
//	for(int i=0;i<len2-len;i++){
//		for(int j=0;i<len;i++){
//			if(str1[start+j]!=str2[j+i]){
//				find_pd=1;
//			}
//		}
//		if(find_pd!=1){
//			for(int j = 0;j < len; i++){
//				str[j]=str1[i+start];
//			}
//			if(find(ht,len,str)){
//				return false;
//			}else{
//				insert(ht,len,str);
//				return true;
//			}
//			break;
//		}		
//	}
//	return false;
//}
//int main(){
//	char str1[101],str2[101];
//	int T=0,answer;
//	scanf("%d",&T);
//	while(T--){
//		answer=0;
//		scanf("%s %s",str1,str2);
//		int len1=strlen(str1);
//		int len2=strlen(str2);
//		HashTable *ht = CreateHashTable(); 
//		if(len1<=len2){
//			//str1大小小于str2
//			for(int i=0;i<len1;i++){
//				for(int j=len1;j>=i;j++){
//					if(found(str1,str2,ht,i,j)){
//						answer++;
//					}
//				}
//			}
//		}else{
//			for(int i=0;i<len1;i++){
//				for(int j=len1;j>=i;j++){
//					if(found(str2,str1,ht,i,j)){
//						answer++;
//					}
//				}
//			}		
//		}
//		printf("%d\n",answer);
//		freeTable(ht);
//	}
//}
//修正 ---------------------------
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<stdbool.h>
//#define Table_Size 100
//typedef struct HashNode {
//    char *value;
//    struct HashNode *next;
//} HashNode;
//typedef struct HashTable {
//    HashNode *bucket[Table_Size];
//} HashTable;
//HashTable *CreateHashTable() {
//    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
//    for(int i = 0; i < Table_Size; i++) {
//        ht->bucket[i] = NULL;
//    }
//    return ht;
//}
//// 修改哈希函数：使用字符串内容而不是长度作为键
//unsigned int hash(char *str) {
//    unsigned int value = 0;
//    while (*str) {
//        value = (value * 31) + *str;
//        str++;
//    }
//    return value % Table_Size;
//}
//// 修改插入函数：使用字符串内容作为键
//void insert(HashTable *ht, char *str) {
//    unsigned int index = hash(str);
//    // 检查是否已存在相同的字符串
//    HashNode *current = ht->bucket[index];
//    while (current != NULL) {
//        if (strcmp(current->value, str) == 0) {
//            return; // 已存在，不插入
//        }
//        current = current->next;
//    }
//    // 插入新节点
//    HashNode *newnode = (HashNode *)malloc(sizeof(HashNode));
//    newnode->value = (char *)malloc(strlen(str) + 1);
//    strcpy(newnode->value, str);
//    newnode->next = ht->bucket[index];
//    ht->bucket[index] = newnode;
//}
//// 修改查找函数：使用字符串内容作为键
//bool find(HashTable *ht, char *str) {
//    unsigned int index = hash(str);
//    HashNode *current = ht->bucket[index];
//    while (current != NULL) {
//        if (strcmp(current->value, str) == 0) {
//            return true;
//        }
//        current = current->next;
//    }
//    return false;
//}
//void freeTable(HashTable *ht) {
//    for(int i = 0; i < Table_Size; i++) {
//        HashNode *current = ht->bucket[i];
//        while (current != NULL) {
//            HashNode *temp = current;
//            current = current->next;
//            free(temp->value);
//            free(temp);
//        }
//    }
//    free(ht);
//}
//// 修改found函数：检查子串是否在两个字符串中都存在
//bool found(char *str1, char *str2, HashTable *ht, int start, int end) {
//    int len = end - start + 1;
//    // 提取子串
//    char *substr = (char *)malloc(len + 1);
//    strncpy(substr, str1 + start, len);
//    substr[len] = '\0';
//    // 检查子串是否在str2中存在
//    bool exists_in_str2 = (strstr(str2, substr) != NULL);
//    // 检查子串是否已经在哈希表中
//    bool already_counted = find(ht, substr);
//    // 如果子串在两个字符串中都存在且尚未计数，则插入哈希表
//    if (exists_in_str2 && !already_counted) {
//        insert(ht, substr);
//        free(substr);
//        return true;
//    }
//    free(substr);
//    return false;
//}
//int main() {
//    char str1[101], str2[101];
//    int T = 0, answer;
//    scanf("%d", &T);
//    while (T--) {
//        answer = 0;
//        scanf("%s %s", str1, str2);
//        int len1 = strlen(str1);
//        int len2 = strlen(str2);
//        HashTable *ht = CreateHashTable();
//        // 遍历所有可能的子串
//        for (int i = 0; i < len1; i++) {
//            for (int j = i; j < len1; j++) { // 修正循环条件
//                if (found(str1, str2, ht, i, j)) {
//                    answer++;
//                }
//            }
//        }
//        printf("%d\n", answer);
//        freeTable(ht);
//    }
//    return 0;
//}

//问题 F: 字符频度
//#include <stdio.h>
//#include <string.h>
//int main(){
//	char str[1001];
//	while(scanf("%s", str) != EOF){
//		int statistics[26] = {0}, total[1001] = {0};
//		char min_char[1001] = {0};
//		int len = strlen(str);
//		for(int i = 0;i < len; i++){
//			statistics[str[i]-'a']++;
//		}
//		for(int i = 0;i < 26; i++){
//			if(statistics[i] == 0)continue;
//			total[statistics[i]]++;
//			if(min_char[statistics[i]] == 0 || (i + 'a') < min_char[statistics[i]]){
//				min_char[statistics[i]] = i + 'a';
//			}
//		}
//		int max = -1,answer=-1;
//		for(int i = 1;i <= len; i++){
//			if(total[i] == 0)continue;
//			if(max < total[i]){
//				max = total[i];
//				answer = i;
//			}else if(total[i] == max){
//				if(min_char[i] < min_char[answer]){
//					answer = i;
//				}
//			}
//		}
//		printf("%d",answer);
//		for(int i = 0;i < 26; i++){
//			if(statistics[i] == answer){
//				printf(" %c",i+'a');
//			}
//		}
//		printf("\n");		
//	}
//	return 0;
//} 

//问题 G: Cute String
//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//int main(){
//	char str[201];
//	while(fgets(str,sizeof(str),stdin)!=NULL){
//		str[strcspn(str, "\n")] = '\0';
//		int total_space=0;
//		int total_character[26]={0};
//		int len = strlen(str);
//		for(int i = 0;i < len;i++){
//			str[i] = toupper(str[i]);
//		}
//		for(int i = 0;i < len;i++){
//			if(str[i] == ' '){
//				total_space++;
//				continue;
//			}
//			total_character[str[i]-'A']++;
//		}
//		if(total_space >= 10){
//			printf("No\n");
//			continue;
//		}
//		int total = 0;
//		for(int i= 0;i < 26;i++){
//			if(total_character[i] != 0){
//				total++;
//			}
//		}
//		if(total > 10){
//			printf("No\n");
//			continue;
//		}
//		printf("Yes\n");
//	}
//	return 0;
//}

//问题 H: 最多的可变换字符串
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct {
//    char key[11];
//    int indices[100];
//    int count;
//} Group;
//
//int compare_char(const void *a, const void *b) {
//    return *(char*)a - *(char*)b;
//}
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        int n;
//        scanf("%d", &n);
//        char strs[100][11];
//        Group groups[100];
//        int group_count = 0;
//
//        for (int i = 0; i < n; i++) {
//            scanf("%s", strs[i]);
//        }
//
//        for (int i = 0; i < n; i++) {
//            char temp[11];
//            strcpy(temp, strs[i]);
//            qsort(temp, strlen(temp), sizeof(char), compare_char);
//
//            int found = 0;
//            for (int j = 0; j < group_count; j++) {
//                if (strcmp(groups[j].key, temp) == 0) {
//                    groups[j].indices[groups[j].count++] = i;
//                    found = 1;
//                    break;
//                }
//            }
//            if (!found) {
//                strcpy(groups[group_count].key, temp);
//                groups[group_count].indices[0] = i;
//                groups[group_count].count = 1;
//                group_count++;
//            }
//        }
//
//        int max_size = 0;
//        int min_first_index = 1000;
//        int best_group_index = -1;
//        for (int i = 0; i < group_count; i++) {
//            int first_index = groups[i].indices[0];
//            if (groups[i].count > max_size) {
//                max_size = groups[i].count;
//                min_first_index = first_index;
//                best_group_index = i;
//            } else if (groups[i].count == max_size) {
//                if (first_index < min_first_index) {
//                    min_first_index = first_index;
//                    best_group_index = i;
//                }
//            }
//        }
//
//        printf("%d\n", groups[best_group_index].count);
//        for (int i = 0; i < groups[best_group_index].count; i++) {
//            int idx = groups[best_group_index].indices[i];
//            printf("%s\n", strs[idx]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//问题 I: 翻转的字符串

//#include <stdio.h>
//#include <string.h>
//char change(char c){
//	switch(c){
//		case 'b':
//			return 'q';
//		case 'd':
//			return 'p';
//		case 'f':
//			return 'f';
//		case 'h':
//			return 'y';
//		case 'l':
//			return 'l';
//		case 'm':
//			return 'w';
//		case 'n':
//			return 'u';
//		case 'o':
//			return 'o';       
//		case 's':
//			return 's';  
//		case 'x':
//			return 'x'; 
//		case 'z':
//			return 'z';      
//		case '1':
//			return '1';  
//		case '2':
//			return '2';
//		case '6':
//			return '9';  
//		case '8':
//			return '8';
//		case 'q':
//			return 'b';
//		case 'p':
//			return 'd';	
//		case 'y':
//			return 'h';
//		case 'w':
//			return 'm';
//		case 'u':
//			return 'n';
//		case '9':
//			return '6';
//	}
//}
//int main(){
//	char str[21];
//	while(scanf("%s",str) != EOF){
//		for(int i=0;i<strlen(str);i++){
//			str[i] = change(str[i]);
//		}
//		for(int i=strlen(str)-1;i>=0;i--){
//			printf("%c",str[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//问题 K: 连接字符串
//#include <stdio.h>
//#include <string.h>
//
//int get_overlap(char *s, char *t) {
//    int len_s = strlen(s);
//    int len_t = strlen(t);
//    int max_k = len_s < len_t ? len_s : len_t;
//    for (int k = max_k; k >= 0; k--) {
//        int flag = 1;
//        for (int i = 0; i < k; i++) {
//            if (s[len_s - k + i] != t[i]) {
//                flag = 0;
//                break;
//            }
//        }
//        if (flag) return k;
//    }
//    return 0;
//}
//
//int main() {
//    char s1[210], s2[210];
//    while (scanf("%s %s", s1, s2) == 2) {
//        int k1 = get_overlap(s1, s2);
//        int k2 = get_overlap(s2, s1);
//
//        char res1[410] = {0};
//        char res2[410] = {0};
//
//        strcpy(res1, s1);
//        strcat(res1, s2 + k1);
//
//        strcpy(res2, s2);
//        strcat(res2, s1 + k2);
//
//        int len1 = strlen(res1);
//        int len2 = strlen(res2);
//
//        if (len1 < len2) {
//            printf("%s\n", res1);
//        } else if (len1 > len2) {
//            printf("%s\n", res2);
//        } else {
//            if (strcmp(res1, res2) < 0) {
//                printf("%s\n", res1);
//            } else {
//                printf("%s\n", res2);
//            }
//        }
//    }
//    return 0;
//}

//问题 J: 最近联系人
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <stdbool.h> 
//typedef struct item{
//	char *str;
//	int count;
//	struct item *next;
//}item;
//typedef struct list{
//	item *list;
//}list; 
//list *createList(){
//	list *lt = (list *)malloc(sizeof(list));
//	lt->list = NULL;
//	return lt;
//}
//bool find(list *lt,char *str){
//	item *it = lt->list;
//	while(it){
//		if(strcmp(str,it->str)==0){
//			it->count++;
//			return true;
//		}
//		it = it->next;
//	}
//	return false;
//}
//void insert(list *lt,char *str){
//	if(!find(lt,str)){
//		item *newitem = (item *)malloc(sizeof(item));
//		newitem->next = lt->list;
//		newitem->str = (char *)malloc(sizeof(strlen(str)+1));
//		strcpy(newitem->str,str);
//		newitem->count = 1;
//		lt->list = newitem;
//	}
//}
//void freeList(list *lt){
//	item *it = lt->list;
//	while(it){
//		item *temp = it;
//		it = it->next;
//		free(temp->str);
//		free(temp);
//	}
//	free(lt);
//}
//char *process(list *lt){
//	char *name;
//	item *temp = lt->list;
//	int max=-1;
//	while(temp){
//		if(temp->count>max){
//			max = temp->count;
//		}
//		temp = temp->next;
//	}
//	temp = lt->list;
//	while(temp){
//		if(temp->count==max){
//			name = temp->str;
//			temp = temp->next;
//			break;
//		}
//		temp = temp->next;		
//	}
//	while(temp){
//		if(temp->count==max){
//			if(strcmp(temp->str,name) <= 0){
//				name = temp->str;
//			}
//		}
//		temp = temp->next;
//	}
//	return name;
//}
//int main(){
//	int T;
//	scanf("%d",&T);
//	while(T--){
//		list *lt = createList();
//		char str[20];
//		bool judge = true;
//		scanf("%s",str);
//		if(strcmp(str,"START")==0)judge = true;
//		while(judge){
//			scanf("%s",str);
//			if(strcmp(str,"END")==0){
//				printf("%s\n",process(lt));
//				freeList(lt);
//				judge = false;
//				break;
//			}
//			insert(lt,str);
//		}
//	}
//}

//问题 E: 共同的子串
//#include<stdio.h>
//#include<string.h>
//int main(){
//	int T=0;
//	scanf("%d",&T);
//	while(T--){
//		char A[101]={},B[101]={};
//		scanf("%s %s",A,B);
//		int total=0;
//		int len=strlen(A);//字符串长度 
//		for(int i=0;i<len;i++){//遍历字符串 
//			int temp=0,cs=0;
//			for(int j=i;j<len;j++){
//				cs=0;
//				for(int k=len-1;k>=j;k--){
//					temp=k-j+1;
//					for(int l=0;l<temp;l++){
//						if(A[i+l]!=B[j+l]){
//							cs=1;
//						}
//					}
//					if(cs!=1){
//						total++;
//					}
//					cs=0;
//				}
//			}
//		}
//		printf("%d\n",total);
//	}
//	return 0;
//}
//-----------------------

