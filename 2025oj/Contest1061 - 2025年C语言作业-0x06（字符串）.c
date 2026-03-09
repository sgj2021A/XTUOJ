//问题 A: 回文串
//#include <stdio.h>
//#include <string.h>
//int isPalindrome(char *s, int start, int end) {
//    while (start < end) {
//        if (s[start]!=s[end]) {
//            return 0;
//        }
//        start++;
//        end--;
//    }
//    return 1;
//}
//int main() {
//    int T;
//    scanf("%d",&T);
//    while (T--) {
//        char s[1001];
//        scanf("%s",s);
//        int n=strlen(s);
//        int ans=0;
//        for (int i=0;i<n;i++) {
//            if (isPalindrome(s,i,n-1)) {
//                ans=i;
//                break;
//            }
//        }
//        printf("%d\n",ans);
//    }
//    return 0;
//}

//问题 B: 整数分类
//#include <stdio.h>
//#include <string.h>
//int process(int n) {
//    if (n < 10) return n;
//    int sum = 0;
//    while (n > 0) {
//        sum += n % 10;
//        n /= 10;
//    }
//    return process(sum);
//}
//int main(){
//	char c[501];
//	while(1){
//		scanf("%s",c);
//		if(c[0]=='0'){
//			break;
//		}else{
//			int b=0;
//			int len=strlen(c);
//			for(int i=0;i<len;i++){
//				b+=(*(c+i)-'0');
//			}	
//			if(b>=10){
//				printf("%d\n",process(b));
//			}else{
//				printf("%d\n",b);
//			}		
//		}
//	}
//	return 0;
//}

//问题 C: Palindrome
//#include <stdio.h>
//#include <string.h>
//void process(char *str, int size) {
//    int bucket[26] = {}; 
//    for (int i = 0; i < size; i++) {
//        if (str[i] >= 'a' && str[i] <= 'z') {
//            bucket[str[i] - 'a']++;
//        }
//    }
//    int odd_count = 0;
//    for (int i = 0; i < 26; i++) {
//        if (bucket[i] % 2 == 1) {
//            odd_count++;
//        }
//    }
//    if (odd_count <= 1) {
//        printf("Yes\n");
//    } else {
//        printf("No\n");
//    }
//}
//int main(){
//	char str[1001];
//	for(int i=0;i<1000;i++){
//		scanf("%s",str);
//        if (str[0]=='0') {
//            break;
//        }
//		int size = strlen(str);
//		process(str,size);	
//	}
//}

//问题 D: 字符串
//#include <stdio.h>
//#include <string.h>
//void process(char *str, int size) {
//    int count[26] = {0};
//    int positions[26][1000];
//    char result[1001];
//
//    for (int i = 0; i < size; i++) {
//        char c = str[i];
//        int idx = c - 'a';
//        count[idx]++;
//        positions[idx][count[idx] - 1] = i;
//
//        int max_count = 0;
//        for (int j = 0; j < 26; j++) {
//            if (count[j] > max_count) {
//                max_count = count[j];
//            }
//        }
//
//        char candidates[26];
//        int num_candidates = 0;
//        for (int j = 0; j < 26; j++) {
//            if (count[j] == max_count) {
//                candidates[num_candidates++] = 'a' + j;
//            }
//        }
//
//        int min_pos = 100000;
//        char best_char;
//        for (int j = 0; j < num_candidates; j++) {
//            int char_idx = candidates[j] - 'a';
//            int pos = positions[char_idx][max_count - 1];
//            if (pos < min_pos) {
//                min_pos = pos;
//                best_char = candidates[j];
//            }
//        }
//        result[i] = best_char;
//    }
//    result[size] = '\0';
//    printf("%s\n", result);
//}
//int main() {
//    char str[1001];
//    while (scanf("%s", str) != EOF) {
//        int size = strlen(str);
//        process(str, size);
//    }
//    return 0;
//}

//问题 E: String I
//#include <stdio.h>
//#include <string.h>
//void process(char *str, int size) {
//	int bucket[30]={0}; 
//	for(int i=0;i<size;i++){
//		bucket[str[i]-'a']++;
//	} 
//	int max=0;
//	for(int i=0;i<26;i++){
//		if(max<bucket[i]){
//			max=bucket[i];
//		}
//	}
//	printf("%d\n",size-max);
//}
//int main() {
//    char str[2001];
//    while (scanf("%s", str) != EOF) {
//        int size = strlen(str);
//        process(str, size);
//    }
//    return 0;
//}

//问题 F: Completed String
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//int main(){
//	char str[1001];
//	while(scanf("%s", str) != EOF){
//		int len = strlen(str);
//    	for (int i = 0; i < len ; i++) {
//     	   str[i] = toupper(str[i]);//转化大写 
// 	    }
//  	    int bucket[30]={};
//  	    for (int i = 0; i < len ; i++){
//   	 	if(str[i]>='A'&&str[i]<='Z'){
//  	  		bucket[str[i]-'A'+1]++;
//			}
//		}
//		for(int i=1;i<=26;i++){
//			if(bucket[i]==0){
//				printf("No\n");
//				break;
//			}
//			if(i==26){
//				printf("Yes\n");
//			}
//		}	
//	}
//	return 0;
//}
//问题 G: Can you raed it croretcly?
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdbool.h>
//bool ArrayEqual(int a[],int b[],int size){
//	for(int i=0;i<size;i++){
//		if(a[i]!=b[i]){
//			return false;
//		}
//		if(i==size-1){
//			return true;
//		}
//	}
//}
//void process(char *str1,char *str2,int len){
//	int bucket1[26]={},bucket2[26]={};
//	for (int i = 0; i < len ; i++) {
//       str1[i] = toupper(str1[i]);//转化大写 
//       str2[i] = toupper(str2[i]);//转化大写 
//    }
//    if(strcmp(str1,str2)==0){
//    	printf("Equal\n");
//    	return;
//	}
//	if(str1[0]==str2[0]&&str1[len-1]==str2[len-1]){
//		for(int i=1;i<len-1;i++){
//			bucket1[str1[i]-'A']++;
//			bucket2[str2[i]-'A']++;		
//		}
//		if(ArrayEqual(bucket1,bucket2,26)){
//			printf("Yes\n");
//			return;
//		}else{
//			printf("No\n");
//			return;
//		}	
//	}else{
//		printf("No\n");
//		return;
//	}
//}
//int main(){
//	char str1[30],str2[30];
//	while(scanf("%s %s",str1,str2) != EOF){
//		int len = strlen(str1);	
//		process(str1,str2,len);		
//	}
//	return 0;
//}

//问题 H: String
//#include <stdio.h>
//#include <string.h>
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    while (T--) {
//        char str[10001];
//        char set_str[27];
//        scanf("%s", str);
//        scanf("%s", set_str);
//        
//        int allowed[26] = {0};
//        int set_len = strlen(set_str);
//        for (int i = 0; i < set_len; i++) {
//            allowed[set_str[i] - 'a'] = 1;
//        }
//        
//        int max_len = 0;
//        int current_len = 0;
//        int len = strlen(str);
//        for (int i = 0; i < len; i++) {
//            if (allowed[str[i] - 'a']) {
//                current_len++;
//                if (current_len > max_len) {
//                    max_len = current_len;
//                }
//            } else {
//                current_len = 0;
//            }
//        }
//        printf("%d\n", max_len);
//    }
//    return 0;
//}

//问题 I: 字母序列
//#include <stdio.h>
//int main() {
//    int T;
//    scanf("%d", &T);
//    for (int i = 0; i < T; i++) {
//        int n, m;
//        scanf("%d %d", &n, &m);
//        int c[m];
//        for (int j = 0; j < m; j++) {
//            scanf("%d", &c[j]);
//        }
//        char s[27];
//        for (int j = 0; j < n; j++) {
//            s[j] = 'A' + j;
//        }
//        int start = 0;
//        printf("#%d:\n", i + 1);
//        for (int j = 0; j < m; j++) {
//            start = (start - c[j] + n) % n;
//            for (int k = 0; k < n; k++) {
//                putchar(s[(start + k) % n]);
//            }
//            putchar('\n');
//        }
//    }
//    return 0;
//}
//问题 J: Co-string
//#include<stdio.h>
//#include<string.h>
//int process(int s,int e,char *str){
//	int len=e-s+1;
//	for(int i=0;i<len/2;i++){
//		if(str[s+i]!=str[e-i]){
//			return 0;
//		}
//	}
//	return len;
//}
//int main(){
//	char str[1001]={};
//	int T=0;
//	scanf("%d",&T);
//	while(T--){
//		scanf("%s",str);
//		int max = 0;
//		int len = strlen(str);
//		for(int i=0;i<len;i++){
//			//检测2n
//			for(int j=len-1;j>i;j++){
//				if((j-i)%2){
//					int cs=process(i,len-2,str);
//					if(max<cs){
//						max=cs;
//						printf("%d %d\n",i,len-2);
//					}
//				} else {
//					int cs=process(i,len-1,str);
//					if(max<cs){
//						printf("%d %d\n",i,len-1);
//						max=cs;
//					}
//				}				
//			}
//
//		}
//		printf("%d\n",max);
//	}
//	return 0;
//}
//改进(错误点：需要每一处要测试)
//#include <stdio.h>
//#include <string.h>
//int process(char *str,int s,int e){
//	int cs=(e-s+1)/2;
//	for(int i=0;i<cs;i++){
//		if(str[s+i]!=str[s+i+cs]){
//			return 0;
//		}
//	}
//	return e-s+1;	
//}
//int main(){
//	int T=0,max=0,len=0,number=0,cs;
//	char str[1001]={};
//	scanf("%d",&T);
//	while(T--){
//		scanf("%s",str);
//		max=0;
//		len=strlen(str);
//		for(int i=0;i<len;i++){
//			if((len-i)%2==0){
//				cs=len-1;
//			}else{
//				cs=len-2;
//			}
//			for(int j=cs;j>i;j-=2){
//				number=process(str,i,j);
//				if(max<number){
//					max = number; 	
//				}
//			}
//		}
//		printf("%d\n",max);
//	}
//	return 0;
//}
