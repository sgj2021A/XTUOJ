//Contest1066 - 2025年C语言作业-0x0B（模拟）

//问题 A: Balls
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <stdbool.h>
////字符串删除函数 
//void delStr(char *str,bool *change) {
//	int location = 0;
//	int total = 1;
//	bool if_change = change[0];
//	int len = strlen(str);
//	
//	if(len == 0)return;
//	
//	for(int i = 1;i <= len;i++){
//		if(str[i] == str[i - 1]){
//			total++;
//			if(change[i])if_change = true;
//			continue;
//		}
//		if(total >= 3 && if_change){
//		}else{
//			for(int j = 0;j < total;j++){
//				str[location + j] = str[i - total + j];
//			}
//			location += total;			
//		}        
//		if(i < len) {
//            total = 1;
//            if_change = change[i];
//        }
//	}
//	str[location] = '\0';
//}
////交换函数 
//void swap(char *str,int a,int b){
//	char temp = str[a];
//	str[a] = str[b];
//	str[b] = temp;
//}
//
//int main(){
//	//输入样例个数 
//	int k = 0;
//	scanf("%d",&k);
//	while(k--){
//		//输入字符串 
//		bool if_change[100];
//		char str[100] = {0};
//		scanf("%s",str);
//		//输入改变操作
//		int change_num = 0;
//		scanf("%d",&change_num);
//		while(change_num--){
//			for(int i = 0;i < 100;i++){
//				if_change[i] = false;
//			}
//			//输入改变位置 
//			int change;
//			scanf("%d",&change);
//			//改变位置
//			swap(str,change - 1,change);
//			if_change[change - 1] = true;
//			if_change[change] = true;
//			//printf("change : %s\n",str); 
//			//删除字符串
//			delStr(str,if_change);
//			if(strlen(str) == 0){
//				printf("Over \n");
//			}else{
//				printf("%s \n",str);
//			}
//		}
//		printf(" \n"); 
//	}
//	return 0;
//}

//问题 B: Cycle
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//int main(){
//	//输入测试个数 
//	int T = 0;
//	scanf("%d",&T);
//	while(T--){
//		//数组大小 
//		int n;
//		scanf("%d",&n);
//		//创建数组
//		bool *number = (bool*)malloc(sizeof(bool) * n);
//		for(int i = 0;i < n;i++){
//			number[i] = false;
//		}//注意 i 为 指代数 i + 1 
//		//生成被抛出数步长 k - 1
//		int* change = (int *)malloc(sizeof(int) * (n - 1));
//		int index = 0;//当前位置 
//		scanf("%d %d",&change[0],&change[1]);
//		//生成步长数组 
//		for(int i = 2;i < n - 1;i++){
//			change[i] = (change[i - 1] + change[i - 2]) % n + 1;
//			//printf("%d ",change[i]);//cs
//		}
//		//printf("\n");//cs
//		//更改number数组
//        for(int i = 0;i < n - 1;i++){
//            int step = change[i];
//            int count = 0;
//            int pos = index;
//            
//            // 数step个有效数字
//            while(count < step){
//                if(!number[pos]){
//                    count++;
//                    if(count == step){
//                        // 删除当前位置的数字
//                        number[pos] = true;
//                        break;
//                    }
//                }
//                pos = (pos + 1) % n;
//            }
//            
//            // 找到下一个起始位置（下一个未被删除的数字）
//            if(i < n - 2){
//                do {
//                    index = (index + 1) % n;
//                } while(number[index]);
//            }
//        }
//		//查询最后一个数
//		int cs = 0;
//		while(!number[cs++]){	
//		}	
//		printf("%d\n",cs + 1);	
//		free(change);
//		free(number);	
//	}
//	return 0; 
//} 
//上面的代码有问题，但是也不想改了,时间会超时
//#include <stdio.h>
//#include <stdlib.h>
////约瑟夫环的问题
//int main(){
//	int T;
//	scanf("%d",&T);
//	while(T--){
//		int n,a1,a2;
//		scanf("%d %d %d",&n,&a1,&a2);
//		int* circle = (int*)malloc(n * sizeof(int));
//		for(int i = 0;i < n;i++){
//			circle[i] = i + 1;
//		}
//		int size = n;
//		int index = 0;
//		int x1 = a1, x2 = a2;
//		//移除n - 1个数字
//		for(int i = 1; i < n;i++){
//			int step;
//			if(i == 1){
//				step = x1;
//			}else if(i == 2){
//				step = x2;
//			}else{
//				step = (x1 + x2) % n + 1;
//				x1 = x2;
//				x2 = step;
//			}
//			int move = (index + step - 1) % size;
//			for(int j = move; j < size - 1;j ++){
//				circle[j] = circle[j + 1];
//			}
//			size--;
//			index = move % size;
//		}
//		printf("%d\n",circle[0]);
//		free(circle);
//	}	
//	return 0;
//} 

//问题 C: 数码串
//#include <stdio.h>
//#include <string.h>
//#define MaxRange 100010
//char min(char base){
//	return base + 1 < '9' ? base + 1 : '9';
//}
//int main(){
//	char number[MaxRange];
//	int T = 0;
//	scanf("%d",&T);
//	while(T--){
//		scanf("%s",number);
//		int len = strlen(number);
//		int index = 0;
//		while(1){
//			if(index == len - 1){
//				break;
//			}
//			if(number[index] <= number[index + 1]){
//				index++;
//				continue;
//			}else{
//				char temp = min(number[index]);
//				for(int i = index;i < len - 1;i++){
//					number[i] = number[i + 1];
//				}
//				number[len - 1] = temp;	
//			}
//		}
//		printf("%s\n",number);
//	}
//	return 0;
//}
//时间超限
//#include<stdio.h>
//#include<string.h>
//char c[1000010];
//
//int main(){
//	int t;
//	scanf("%d",&t);
//	while(t--){
//		scanf("%s",c);
//		int start=0;
//		int len=strlen(c);
//		
//		while(start<len-1){
//			if(c[start]=='\0'||c[start]<=c[start+1]){
//				start++;
//			}else{
//				if(c[start]+1<='9'){
//					c[len]=c[start]+1;
//				}else{
//					c[len]='9';
//				}
//				c[start]='\0';
//				len++;
//			}
//		}
//		
//		for(int i=0;i<len;i++){
//			if(c[i]!='\0'){
//				printf("%c",c[i]);
//			}
//		}
//		puts("");
//	}
//	
//	return 0;
//}

//问题 D: Dice I
//#include <stdio.h>
//int main(){
//    char instruct[205];
//    int i,temp;
//    int pose[3];
//    while(scanf("%s",instruct)!=EOF){
//        pose[0]=1;pose[1]=5;pose[2]=3;
//        for(i=0;instruct[i];++i)
//        {
//            if(instruct[i]=='U'){
//                temp=7-pose[0];
//                pose[0]=pose[1];
//                pose[1]=temp;
//            }
//            else if(instruct[i]=='D'){
//                temp=7-pose[1];
//                pose[1]=pose[0];
//                pose[0]=temp;
//            }
//            else if(instruct[i]=='L'){
//                temp=7-pose[2];
//                pose[2]=pose[0];
//                pose[0]=temp;
//            }
//            else if(instruct[i]=='R'){
//                temp=7-pose[0];
//                pose[0]=pose[2];
//                pose[2]=temp;
//            }
//            else if(instruct[i]=='X'){
//                temp=7-pose[2];
//                pose[2]=pose[1];
//                pose[1]=temp;
//            }
//            else if(instruct[i]=='Y'){
//                temp=7-pose[1];
//                pose[1]=pose[2];
//                pose[2]=temp;
//            }
//        }
//        printf("%d\n",pose[0]);
//    }
//    return 0;
//}

//问题 E: 21 Points
//#include<stdio.h>
//#include<string.h>
//int main(){
//	int t;
//	scanf("%d",&t);
//	while(t--){
//		char s[12];
//		scanf("%s",s);
//		int len = strlen(s);
//		int A_time = 0;
//		int count = 0;
//		for(int i = 0;i < len; i++){
//			if(s[i] >= '2' && s[i] <= '9'){
//				count += s[i] - '0';
//			}
//			if(s[i] == '1'){
//				count += 10;
//				i++;
//			}
//			if(s[i] == 'A'){
//				A_time++;
//			}
//			if(s[i] == 'J' || s[i] == 'K' || s[i] == 'Q'){
//				count += 10;
//			}
//		}
//		count += A_time;//把A 作为 1 
//		if(count > 21){
//			printf("Boom\n");
//			continue;
//		}
//		//处理A的情况
//		//先处理10
//		int A_10 = 0;
//		for(int i = 1;i <= A_time;i++){
//			if(count + 9 <= 21){
//				A_10++;
//				count += 9;
//			}else{
//				break;
//			}
//		}
//		//处理11 
//		for(int i = 1;i <= A_10;i++){
//			if(count + 1 <= 21){
//				count++;
//			}else{
//				break;
//			}
//		}
//		//输出结果
//		printf("%d\n",count); 
//	}
//}
//问题 G: Robot
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main() {
//    int k = 0;
//    scanf("%d", &k);
//    
//    while(k--) {
//        long long x = 0, y = 0;
//        int face = 0; // 1 -> 右； 3 -> 左；0 -> 上；2 -> 下
//        
//        int total_control = 0;
//        scanf("%d", &total_control);
//        
//        for(int i = 0; i < total_control; i++) {
//            char control[100];
//            scanf("%s", control);
//            
//            if(strcmp(control, "RIGHT") == 0) {
//                face = (face + 1) % 4;
//            } else if(strcmp(control, "LEFT") == 0) {
//                face = (face + 3) % 4;
//            } else if(strcmp(control, "BACK") == 0) {
//                face = (face + 2) % 4;
//            } else if(strcmp(control, "FORWORD") == 0) {
//                int forword;
//                scanf("%d", &forword);
//                
//                switch(face) {
//                    case 0: // 上
//                        y += forword;
//                        break;
//                    case 1: // 右
//                        x += forword;
//                        break;
//                    case 2: // 下
//                        y -= forword;
//                        break;
//                    case 3: // 左
//                        x -= forword;
//                        break;
//                }
//            }
//        }
//        
//        // 输出最终坐标
//        printf("%lld %lld\n", x, y);
//    }
//    
//    return 0;
//}

//问题 F: ASCII
//#include <stdio.h>
//#include <string.h>
//int main(){
//        unsigned char str[100000] = {0};
//        char c; 
//        int n = 0;
//    	while ((c = getchar()) != EOF) {
//        	str[n++] = (unsigned char)c;
//    	}
//        int len = n;
//        int total = 0;
//        if(len % 16 == 0){
//                total = len / 16;       
//        }else{
//                total = len / 16 + 1;
//        }
//        int location = 0;
//        for(int i = 0;i < total;i++){
//                printf("%05X",i);
//                for(int i = 0;i < 16;i++){
//                    printf(" %02X",str[location]);
//                    location++;    
//                    if(location == len - 1){
//                    	break;
//					}
//                }
//                
//                printf("\n");
//        }
//        return 0;
//}

//问题 H: Alice and Bob
//#include <stdio.h>
//// 获取点数的权重值（1最大，然后是6,5,4,3,2）
//int get_weight(int x) {
//    if (x == 1) return 6;
//    if (x == 6) return 5;
//    if (x == 5) return 4;
//    if (x == 4) return 3;
//    if (x == 3) return 2;
//    if (x == 2) return 1;
//    return 0;
//}
////type 3表示豹子号，2表示对子号，1表示点子号 ，v1表示第一值，如在相同的豹子号中权重最大的一个 
//void analyze(int a, int b, int c, int *type, int *v1, int *v2) {
//    int count[7] = {0};
//    count[a]++; count[b]++; count[c]++;
//    // 检查豹子（三个相同）
//    for (int i = 1; i <= 6; i++) {
//        if (count[i] == 3) {
//            *type = 3;
//            *v1 = get_weight(i);
//            *v2 = 0;//豹子号没有第二值 
//            return;
//        }
//    }
//    // 检查对子（两个相同）
//    for (int i = 1; i <= 6; i++) {
//        if (count[i] == 2) {
//            *type = 2;
//            *v1 = get_weight(i);
//            for (int j = 1; j <= 6; j++) {
//                if (count[j] == 1) {
//                    *v2 = get_weight(j);
//                    return;
//                }
//            }
//        }
//    }
//    // 否则是点子
//    *type = 1;
//    *v1 = a + b + c;  // 点数和
//    *v2 = 0;
//}
//// 比较结果
//int compare(int a1, int a2, int a3, int b1, int b2, int b3) {
//    int typeA, v1A, v2A;
//    int typeB, v1B, v2B;
//    analyze(a1, a2, a3, &typeA, &v1A, &v2A);
//    analyze(b1, b2, b3, &typeB, &v1B, &v2B);
//    // 先比较类型
//    if (typeA > typeB) return 1;  // Alice赢
//    if (typeA < typeB) return -1; // Bob赢
//    // 类型相同，比较第一值
//    if (v1A > v1B) return 1;
//    if (v1A < v1B) return -1;
//    // 第一值相同，比较第二值
//    if (v2A > v2B) return 1;
//    if (v2A < v2B) return -1;
//    return 0; // 平局
//}
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    
//    for (int i = 0; i < T; i++) {
//        int a1,a2,a3,b1,b2,b3;
//        scanf("%d %d %d",&a1,&a2,&a3);
//        scanf("%d %d %d",&b1,&b2,&b3);
//        int result = compare(a1, a2, a3, b1, b2, b3);
//        if (result == 1) {
//            printf("Alice\n");
//        } else if (result == -1) {
//            printf("Bob\n");
//        } else {
//            printf("Draw\n");
//        }
//    }
//    return 0;
//}


//问题 I: 矩阵
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//void move(int *arr,int n,int y){
//	int *temp = (int *)malloc(sizeof(int) * n);
//	for(int i = 0;i < n;i++){
//		temp[i] = arr[(i + y) % n];
//	}
//    for (int i = 0; i < n; i++) {
//        arr[i] = temp[i];
//    }
//    free(temp);
//}
//
//int main(){
//	int k = 0;
//	scanf("%d",&k);
//	while(k--){
//		int n = 0,s = 0;
//		scanf("%d %d",&n,&s);
//		//创建二维数组 
//		int **arr = (int **)malloc(sizeof(int*) * n);
//		for(int i = 0;i < n;i++){
//			arr[i] = (int *)malloc(sizeof(int) * n);
//		} 
//		//赋值二维数组
//		int a = 1;
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < n;j++){
//				arr[i][j] = a++;
//			}
//		} 
//		//输入更改样例
//		while(s--){
//			char control;
//			int x,y;
//			scanf(" %c %d %d",&control,&x,&y);
//			//如果为 L x y : x行循环左移y次
//			if(control == 'L'){
//				move(arr[x - 1],n,y);
//				continue;
//			}
//			//R x y	x行循环右移y次
//			if(control == 'R'){
//				move(arr[x - 1],n,n - y);
//				continue;
//			}			
//			//U x y	x列循环上移y次
//			if(control == 'U'){
//				int *temp1 = (int *)malloc(sizeof(int) * n);
//				for(int i = 0;i < n;i++){
//					temp1[i] = arr[i][x - 1];
//				}
//				move(temp1,n,y);
//				for(int i = 0;i < n;i++){
//					arr[i][x - 1] = temp1[i];
//				}
//				free(temp1);
//				continue;
//			}
//			//D x y	x列循环下移y次
//			if(control == 'D'){
//				int *temp2 = (int *)malloc(sizeof(int) * n);
//				for(int i = 0;i < n;i++){
//					temp2[i] = arr[i][x - 1];
//				}
//				move(temp2,n,n - y);
//				for(int i = 0;i < n;i++){
//					arr[i][x - 1] = temp2[i];
//				}
//				free(temp2);
//				continue;
//			}
//		}
//		//测试二维数组
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < n;j++){
//				printf("%d ",arr[i][j]);
//			}
//		} 
//		printf("\n");
//		//printf("\n--------------------------------------\n");
//		//销毁二维数组
//		for(int i = 0;i < n;i++)free(arr[i]);
//		free(arr); 
//	}
//}

//问题 J: 数字折叠
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main(){
//	char number[15];
//	int k = 0;
//	scanf("%d",&k);
//	while(k--){
//		char number_lift[10],number_right[10];
//		long long num = 0;
//		scanf("%s",number);
//		int len = strlen(number);
//		num = strtoll(number,NULL,10);
//		while(num >= 10){
//			int len = strlen(number);
//			//初始化 
//			memset(number_lift,0,sizeof(number_lift));
//			memset(number_right,0,sizeof(number_right));
//			
//			if(len % 2 == 1){//位数为奇数 
//				number_lift[0] = '0';
//				for(int i = 1;i < (len + 1) / 2;i++){
//					number_lift[i] = number[i - 1];
//				}
//				int index = 0;
//				for(int i = len - 1;i >= (len - 1) / 2 - 1;i--){
//					number_right[index++] = number[i];
//				}
//				len = (len + 1) / 2;
//				number_lift[len] = '\0';
//				number_right[len] = '\0';
//				num = strtoll(number_lift,NULL,10) + strtoll(number_right,NULL,10);
//				sprintf(number, "%lld", num); 								
//			}else{//位数为偶数 
//				for(int i = 0,j = len - 1;j > i;i++,j--){
//					number_lift[i] = number[i];
//					number_right[i] = number[j]; 
//				}
//				len = len / 2;
//				number_lift[len] = '\0';
//				number_right[len] = '\0';
//				num = strtoll(number_lift,NULL,10) + strtoll(number_right,NULL,10);
//				sprintf(number, "%lld", num); 
//			}
//		}
//		printf("%lld\n",num);
//
//	}
//	return 0;
//}
