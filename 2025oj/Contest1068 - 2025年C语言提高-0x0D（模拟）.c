//Contest1068 - 2025年C语言提高-0x0D（模拟）

//问题 A: Alice and Bob
//#include <stdio.h>
//#include <string.h>
//
//int main() {
//    char s[201];
//    int results[40000][2];
//    
//    while (scanf("%s", s) != EOF) {
//        int n = strlen(s);
//        int total = 0;
//        
//        // 枚举所有可能的S和G
//        for (int S = 1; S <= n; S++) {
//            for (int G = 1; G <= n; G++) {
//                int winA = 0, winB = 0; // Alice和Bob赢的局数
//                int a = 0, b = 0; // 当前局得分
//                int i;
//                
//                for (i = 0; i < n; i++) {
//                    if (s[i] == 'L') {//计算Alice的得分 
//                        b++;
//                    } else {
//                        a++;
//                    }
//                    
//                    // 检查当前局是否结束
//                    if (a >= S || b >= S) {
//                        if (a > b) {
//                            winA++;
//                        } else {
//                            winB++;
//                        }
//                        a = 0;
//                        b = 0;
//                        
//                        // 检查比赛是否结束
//                        if (winA == G || winB == G) {
//                            break;
//                        }
//                    }
//                }
//                // 验证
//                if (i == n - 1 && winA == G && winB < G && a == 0 && b == 0) {
//                    results[total][0] = S;
//                    results[total][1] = G;
//                    total++;
//                }
//            }
//        }
//        
//        // 输出结果
//        printf("%d\n", total);
//        // 按S升序，S相同时按G升序
////        for (int i = 0; i < total; i++) {
////            for (int j = i + 1; j < total; j++) {
////                if (results[i][0] > results[j][0] || 
////                   (results[i][0] == results[j][0] && results[i][1] > results[j][1])) {
////                    int tempS = results[i][0];
////                    int tempG = results[i][1];
////                    results[i][0] = results[j][0];
////                    results[i][1] = results[j][1];
////                    results[j][0] = tempS;
////                    results[j][1] = tempG;
////                }
////            }
////        }
//        
//        for (int i = 0; i < total; i++) {
//            printf("%d %d\n", results[i][0], results[i][1]);
//        }
//    }
//    
//    return 0;
//}
//时间超限

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//typedef struct{
//	int a,b;
//}item;
//item res[40000];
//int index;
//char str[520];
//int compare(const void *a,const void *b){
//    item *item1 = (item*)a;
//    item *item2 = (item*)b;
//    if(item1->a != item2->a)
//        return item1->a - item2->a;
//    return item1->b - item2->b;
//}
//int process(int n){//n是目标得分 
//	int len = strlen(str);
//	int a = 0,b = 0,cnt = 0,a_w = 0,b_w = 0;//cnt是总局数 
//	for(int i = 0;i < len;i++){
//		if(str[i] == 'W')a++;
//		else b++;
//		if(a == n)cnt++,a_w++,a = 0,b = 0;
//		else if(b == n)cnt++,b_w++,a = 0,b = 0;
//	}
//	if(a != 0 || b != 0 || a_w <= b_w || a_w == 0)return 0;
//	return a_w;	
//}
//int main(){
//	while(scanf("%s",str) != EOF){
//		index = 0;
//		int len = strlen(str);
//		for(int i = 1;i <= len;i++){
//			int cnt = process(i);
//			if(cnt != 0)res[index].a = i,res[index].b = cnt,index++;
//		}
//		qsort(res,index,sizeof(item),compare);
//		if(index == 0)printf("0\n");
//		else{
//			printf("%d\n",index);
//			for(int i = 0;i < index;i++){
//				printf("%d %d\n",res[i].a,res[i].b);
//			}	
//		}
//	}
//}
//--------------------------------------------------

//问题 B: Maze
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main(){
//	int k,n,m,d;
//	scanf("%d",&k);
//	char map[101][101];
//	int map_turn[101][101];
//	int unfound,total,start_x,start_y,end_x,end_y,x,y,turn;
//	while(k--){
//		scanf("%d %d %d",&n,&m,&d);
//
//		getchar();
//		//n行 m列 map[x][y]
//		for(int i = 1;i <= n;i++){//y
//			for(int j = 1;j <= m;j++){//x
//				map[j][i] = getchar();
//				if(map[j][i] == 'S'){
//					start_x = j;
//					start_y = i;
//				}else if(map[j][i] == 'E'){
//					end_x = j;
//					end_y = i;
//				}
//			}
//			getchar();
//		}
//		for(int i = 0;i <= n + 1;i++){
//			map[0][i] = '*';
//			map[m + 1][i] = '*';
//		}
//		for(int i = 0;i <= m + 1;i++){
//			map[i][0] = '*';
//			map[i][n + 1] = '*';
//		}
//		//初始化转向地图
//		for(int i = 0;i <= n + 1;i++){
//			for(int j = 0;j <= m + 1;j++){
//				map_turn[j][i] = 0;
//			}
//		}
//
//		//计算总路程
//		total = 0; unfound = 0;
//		x = start_x; y = start_y; turn = d;
//
//		while(1){
//			printf("total: %d location : (%d,%d) , turn : %d\n",total,x,y,turn);
//
//			if(unfound)break;
//			if(x == end_x && y == end_y)break;
//
//			if(turn == 1){//上
//
////				if(map[x][y - 1] == '*'){
////					if(map[x + 1][y] != '*'){
////						if(map_turn[x][y] != turn){
////							map_turn[x][y] = turn;
////						}else{
////							unfound = 1;
////						}
////					}
////					turn = 2;
////				}else{
////					total++;
////					y -= 1;
////				}
//			}else if(turn == 2){//右
//
//				if(map[x + 1][y] == '*'){
//					if(map[x][y + 1] != '*'){
//						if(map_turn[x][y] != turn){
//							map_turn[x][y] = turn;
//						}else{
//							unfound = 1;
//						}
//					}
//					turn = 3;
//				}else{
//					total++;
//					x += 1;
//				}
//			}else if(turn == 3){//下
//
//				if(map[x][y + 1] == '*'){
//					if(map[x - 1][y] != '*'){
//						if(map_turn[x][y] != turn){
//							map_turn[x][y] = turn;
//						}else{
//							unfound = 1;
//						}
//					}
//					turn = 4;
//				}else{
//					total++;
//					y += 1;
//				}
//			}else{//左 turn == 4
//
//				if(map[x - 1][y] == '*'){
//					if(map[x][y - 1] != '*'){
//						if(map_turn[x][y] != turn){
//							map_turn[x][y] = turn;
//						}else{
//							unfound = 1;
//						}
//					}
//					turn = 1;
//				}else{
//					total++;
//					x -= 1;
//				}
//			}
//		}
//
//		//输出
//		if(unfound){
//			printf("Impossible\n");
//		}else{
//			printf("%d\n",total);
//		}
//
//		//cs
////		printf("start:(%d,%d) end:(%d,%d)\n",start_x,start_y,end_x,end_y);
////		for(int i = 0;i <= n + 1;i++){
////			printf("%d : ",i);
////			for(int j = 0;j <= m + 1;j++){
////				putchar(map[j][i]);
////			}
////			printf("\n");
////		}
//		//cs
//
//	}
//	return 0;
//}
//超时
//#include <stdio.h>
//
//int main(){
//    char maps[105][105];
//	int T,n,m,d,x,y,ans,flag;
//	int tags[6][3] = {{0,0},{-1,0},{0,1},{1,0},{0,-1}};
//
//	scanf("%d",&T);
//
//    while (T--)
//    {
//        int flagS = 1;
//        scanf("%d %d %d",&n,&m,&d);
//        for (int i = 1; i <= n; i ++)
//        {
//            scanf("%s",maps[i]+1);
//            if (flagS)
//            {
//                for(int j = 1; j <= m; j ++)
//                {
//                    if (maps[i][j] == 'S')
//                        x = i, y = j, flagS = 0;   // x,y是矩阵里的行列数, x是行、y是列，放在直角坐标系里(x为纵坐标、y为横坐标)
//                }
//            }
//        }
//        flag = ans = 0;
//        while (maps[x][y] != 'E')
//        {
//            if ((d==1 && x==1) || (d==2 && y==m) || (d==3 && x==n) || (d==4 && y==1) || maps[x+tags[d][0]][y+tags[d][1]] == '*')
//            {
//                d = d%4+1;                          // 右转向
//                flag ++;
//            }
//            else
//            {
//                x += tags[d][0], y += tags[d][1];   // 移动
//                flag = 0, ans ++;
//            }
//            if (ans > n*m || flag > 4)  {ans = 0;break;}    // 无答案条件
//        }
//        if (ans)    printf("%d\n",ans);
//        else        puts("Impossible");
//    }
//    return 0;
//}

//------------------------------------------------------
//问题 C: 奇偶数位
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main(){
//	int T;
//	scanf("%d",&T);
//
//	char number[20],number_even[20],number_odd[20];
//	long long total,len,index,index_i;
//
//	while(T--){
//		total = 0;
//
//		scanf("%s",number);
//
//		len = strlen(number);
//
//		if(len == 1){
//			printf("0\n");
//			continue;
//		}
//
//		while(len != 1){
//			total++;
//			//构建奇数数序列
//			for(index = 0,index_i = 0;index < len;index += 2,index_i++){
//				number_odd[index_i] = number[index];
//			}
//			number_odd[index_i] = '\0';
//			//构建偶数序列
//			for(index = 1,index_i = 0;index < len;index += 2,index_i++){
//				number_even[index_i] = number[index];
//			}
//			number_even[index_i] = '\0';
//			//重新构建数列
//			sprintf(number,"%lld",atoll(number_odd) * atoll(number_even));
//			len = strlen(number);
//		}
//
//		printf("%d\n",total);
//	}
//
//	return 0;
//}

//------------------------------------------------------
//问题 E: Diagram
//#include <stdio.h>
//#include <string.h>
//
//int gcd(int a,int b){
//	return b == 0 ? a : gcd(b, a % b);
//}
//
//int main(){
//
//	char str[1001],total[26][1001];
//	int len,max,total_character,g,num[26];
//
//	while(scanf("%s",str) != EOF){
//		//initialize num[26];
//		g = 0,max = 0,total_character = 0;
//		for(int i = 0;i < 26;i++){
//			num[i] = 0;
//		}
//
//		len = strlen(str);
//
//
//		for(int i = 0;i < len;i++){
//			num[str[i] - 'A']++;
//		}
//
//		for(int i = 0;i < 26;i++){
//			if(num[i] != 0){
//
//				if(g == 0){
//					g = num[i];
//				}else{
//					g = gcd(g,num[i]);
//				}
//
//				if(max < num[i]){
//					max = num[i];
//				}
//				total_character++;
//			}
//		}
//
//		//initialize_total[][]
//		max /= g;
//
////		//test
////		printf("--------------------------\n");
////		printf("max : %d g : %d total_character : %d\n",max,g,total_character);
////		for(int i = 0;i < 26;i++){
////			printf("%c ",i + 'A');
////		}
////		printf("\n");
////		for(int i = 0;i < 26;i++){
////			printf("%d ",num[i]);
////		}
////		printf("\n");
////		//test
//
//		//initialize total[][]
//
//		for(int i = 0;i < max;i++){
//			for(int j = 0;j < total_character;j++){
//				total[j][i] = ' ';
//			}
//		}
//
//		//writing total[][]
//		for(int i = 0,index = 0;i < 26;i++){
//			if(num[i] != 0){
//				int number = num[i] / g;
//
//				for(int j = 0;j < number;j++){
//					total[index][j] = '*';
//				}
//
//				index++;
//			}
//		}
//
////		//test
////
////		for(int i = 0;i < max;i++){
////			for(int j = 0;j < total_character;j++){
////				printf("%c",total[j][i]);
////			}
////			printf("\n");
////		}
////		printf("--------------------------\n");
////		//test
//
//		//output total[][]
//		for (int i = max - 1; i >= 0; i--) {
//		    int j = total_character - 1;
//		    while (j >= 0 && total[j][i] == ' ') {
//		        j--;
//		    }
//		    for (int k = 0; k <= j; k++) {
//		        printf("%c", total[k][i]);
//		    }
//		    printf("\n");
//		}
//
//		for(int i = 0;i < 26;i++){
//			if(num[i] != 0){
//				printf("%c",'A' + i);
//			}
//		}
//		printf("\n");
//		printf("\n");
//
//	}
//
//
//	return 0;
//}

//------------------------------------------------------
//问题 I: UTF-8 字符串切片
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <stdint.h>//uint8_t 含义：uint：Unsigned Integer（无符号整数）占用 8 位（1 字节）_t：表示类型（type）。
//
//uint8_t uft16_to_byte(char high, char low){
//	int h = (high >= '0' && high <= '9') ? (high - '0') : (high >= 'a' && high <= 'f') ? (high - 'a' + 10) : (high - 'A' + 10);
//	int l = (low >= '0' && low <= '9') ? (low - '0') : (low >= 'a' && low <= 'f') ? (low - 'a' + 10) : (low - 'A' + 10);
//	return (h << 4) | l;//将两个 4 位值合并为一个 8 位值
//}
//
//int get_utfitem_len(uint8_t byte){
//	if((byte & 0x80) == 0x00)return 1;//在这里byte会只取最高位的值比较
//	if((byte & 0xE0) == 0xC0)return 2;
//	if((byte & 0xF0) == 0xE0)return 3;
//	if((byte & 0xF8) == 0xF0)return 4;
//}
//
//int main(){
//	int n,m;
//
//	scanf("%d %d",&n,&m);
//
//	char *utf = (char*)malloc(2 * n + 1);
//
//	scanf("%s",utf);
//
//	uint8_t* data = (uint8_t*)malloc(n);//uint8_t是二进制整型，不是10进制整型
//
//	for(int i = 0;i < n;i++){
//		data[i] = uft16_to_byte(utf[2 * i],utf[2 * i + 1]);
//	}
//
//	int* utf_start = (int *)malloc(sizeof(int) * n);
//	int* utf_len = (int *)malloc(sizeof(int) * n);
//
//	int count = 0;
//
//	int k = 0;
//
//	while(k < n){
//		int len = get_utfitem_len(data[k]);
//		utf_start[count] = k;
//		utf_len[count] = len;
//		count++;
//		k += len;
//	}
//
//	for(int q = 0;q < m;q++){
//		int pos,cnt;
//		scanf("%d %d",&pos,&cnt);
//		int end = pos + cnt;
//		if(end > count){
//			end = count;
//		}
//
//		int start_byte = utf_start[pos];
//		int end_byte = utf_start[end - 1] + utf_len[end - 1];
//
//        for (int g = start_byte; g < end_byte; g++) {
//            printf("%02x", data[g]);
//        }
//		printf("\n");
//	}
//    free(utf);
//    free(data);
//    free(utf_start);
//    free(utf_len);
//    return 0;
//}

//问题 F: 交叉点
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//int main(){
//	int S,n,m;
//	char map[34][34];
//	bool map_bool[34][34];
//	//n是行，m是列
//	scanf("%d",&S);
//	int case_num = S;
//	while(S--){
//		scanf("%d %d",&n,&m);
//		getchar();
//
//		for(int i = 0;i <= n + 3;i++){
//			for(int j = 0;j <= m + 3;j++){
//				map[i][j] = '.';
//				map_bool[i][j] = false;
//			}
//		}
//
//		for(int i = 2;i <= n + 1;i++){
//			for(int j = 2;j <= m + 1;j++){
//				map[i][j] = getchar();
//			}
//			getchar();
//		}
//
//		int total = 0;
//		for(int i = 2;i <= n + 1;i++){
//			for(int k = 2;k <= m + 1;k++){
//				if(map[i][k] == '.')continue;
//				int num = 0;
//				//横
//				if(map[i - 1][k] == '*' && map[i + 1][k] == '*'){
//					num++;
//				}else if(map[i - 1][k] == '*' && map[i - 2][k] == '*'){
//					num++;
//				}else if(map[i + 1][k] == '*' && map[i + 2][k] == '*'){
//					num++;
//				}
//				//竖
//				if(map[i][k + 1] == '*' && map[i][k - 1] == '*'){
//					num++;
//				}else if(map[i][k + 1] == '*' && map[i][k + 2] == '*'){
//					num++;
//				}else if(map[i][k - 1] == '*' && map[i][k - 2] == '*'){
//			 		num++;
//				}
//				//*
//				// *
//				//  *
//				if(map[i - 1][k - 1] == '*' && map[i + 1][k + 1] == '*'){
//					num++;
//				}else if(map[i + 1][k + 1] == '*' && map[i + 2][k + 2] == '*'){
//					num++;
//				}else if(map[i - 1][k - 1] == '*' && map[i - 2][k - 2] == '*'){
//					num++;
//				}
//				//  *
//				// *
//				//*
//				if(map[i + 1][k - 1] == '*' && map[i - 1][k + 1] == '*'){
//					num++;
//				}else if(map[i + 1][k - 1] == '*' && map[i + 2][k - 2] == '*'){
//					num++;
//				}else if(map[i - 1][k + 1] == '*' && map[i - 2][k + 2] == '*'){
//					num++;
//				}
//
//				if(num >= 2){
////					printf("%d %d %d\n",i,k,num);
//					total++;
//					map_bool[i][k] = true;
//				}
//			}
//		}
//
//		printf("Case %d:%d\n",case_num - S,total);
//
//		for(int i = 2;i <= n + 1;i++){
//			for(int j = 2;j <= m + 1;j++){
//				if(map_bool[i][j]){
//					printf("%d %d\n",i - 2,j - 2);
//				}
//			}
//		}
//
//		//cs
////		printf("----------------------\n测试\n");
////		printf("n : %d m : %d\n",n,m);
////		for(int i = 0;i <= n + 3;i++){
////			for(int j = 0;j <= m + 3;j++){
////				printf("%c",map[i][j]);
////			}
////			printf("\n");
////		}
////		for(int i = 0;i <= n + 2;i++){
////			for(int j = 0;j <= m + 2;j++){
////				if(map_bool[i][j]){
////					printf("*");
////				}else{
////					printf(" ");
////				}
////			}
////			printf("\n");
////		}
////		printf("----------------------\n");
//		//cs
//	}
//
//	return 0;
//}

//------------------------------------------------------
//问题 G: 2048
//#include <stdio.h>
//#include <string.h>
//#include <stdbool.h>
//#define size 4
//void swap(int *a,int *b) {
//	int c = *b;
//	*b = *a;
//	*a = c;
//}
//void swap_bool(bool *a,bool *b) {
//	bool c = *b;
//	*b = *a;
//	*a = c;
//}
//int main() {
//	int k;
//	scanf("%d",&k);
//
//	int map[size][size];
//	bool map_bool[size][size];
//	while(k--) {
//		char control[10];
//
//		for(int i = 0; i < size; i++) {
//			for(int j = 0; j < size; j++) {
//				scanf("%d",&map[i][j]);
//				map_bool[i][j] = true;
//			}
//		}
//
//		scanf("%s",control);
//
//		if(control[0] == 'L') { //LEFT
//			//printf("LEFT\n");//cs
//
//			for(int k = 0; k < size; k++) {
//				for(int i = 1; i < size; i++) {
//					for(int j = 0; j < size; j++) {
//						if(map[j][i] == 0)continue;
//
//						if(map[j][i - 1] == 0) {
//							swap(&map[j][i],&map[j][i - 1]);
//							swap_bool(&map_bool[j][i],&map_bool[j][i - 1]);
//							
//						}else if(map[j][i] == map[j][i - 1] && map_bool[j][i - 1] && map_bool[j][i]) {
//							map[j][i - 1] += map[j][i];
//							map[j][i] = 0;
//							map_bool[j][i - 1] = false;
//						}
//					}
//				}
//			}
//
//		} else if(control[0] == 'D') { //DOWN
//			//printf("DOWN\n");//cs
//
//			for(int k = 0; k < size; k++) {
//				for(int i = size - 2; i >= 0; i--) {
//					for(int j = 0; j < size; j++) {
//						if(map[i][j] == 0)continue;
//						
//						if(map[i + 1][j] == 0) {
//							swap(&map[i][j],&map[i + 1][j]);
//							swap_bool(&map_bool[i][j],&map_bool[i + 1][j]);
//						}else if(map[i][j] == map[i + 1][j] && map_bool[i + 1][j] && map_bool[i][j]) {
//							map[i + 1][j] += map[i][j];
//							map[i][j] = 0;
//							map_bool[i + 1][j] = false;
//						}
//					}
//				}
//			}
//
//		} else if(control[0] == 'R') { //RIGHT
//			//printf("RIGHT\n");//cs
//			for(int k = 0; k < size; k++) {
//				for(int i = size - 2; i >= 0; i--) {
//					for(int j = 0; j < size; j++) {
//						if(map[j][i] == 0)continue;
//						
//						if(map[j][i + 1] == 0) {
//							swap(&map[j][i],&map[j][i + 1]);
//							swap_bool(&map_bool[j][i],&map_bool[j][i + 1]);
//						}else if(map[j][i] == map[j][i + 1] && map_bool[j][i + 1] && map_bool[j][i]) {
//							map[j][i + 1] += map[j][i];
//							map[j][i] = 0;
//							map_bool[j][i + 1] = false;
//						}
//					}
//				}
//			}
//
//		} else { //UP
//			//printf("UP\n");//cs
//
//			for(int k = 0; k < size; k++) {
//				for(int i = 1; i < size; i++) {
//					for(int j = 0; j < size; j++) {
//						if(map[i][j] == 0)continue;
//						
//						if(map[i - 1][j] == 0) {
//							swap(&map[i][j],&map[i - 1][j]);
//							swap_bool(&map_bool[i][j],&map_bool[i - 1][j]);
//						}else if(map[i][j] == map[i - 1][j] && map_bool[i - 1][j] && map_bool[i][j]) {
//							map[i - 1][j] += map[i][j];
//							map[i][j] = 0;
//							map_bool[i - 1][j] = false;
//						}
//					}
//				}
//			}
//
//		}
//
//		for(int i = 0; i < size; i++) {
//			for(int j = 0; j < size; j++) {
//				printf("%d ",map[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//		//test
////		printf("---------test----------\n");
////		for(int i = 0; i < size; i++) {
////			for(int j = 0; j < size; j++) {
////				if(!map_bool[i][j]) {
////					printf("* ");
////				} else {
////					printf("  ");
////				}
////			}
////			printf("\n");
////		}
////		printf("\n");
//		//test
//	}
//	return 0;
//}
//------------------------------------------------------
//问题 H: 轨迹
//图形打印都有很多的限定条件，而题目也没有仔细说明，全要靠我们自己去看样例或者试错去挖掘。这题难点就在这儿了。 下面我们来看看有哪些需要避坑和注意的点。
//题目保证 “轨迹图的宽与高不会超过600”，但轨迹怎么走是无法预测的，所以要申请一个保证能存下轨迹图的数组
//因为起点在数组中心位置，所以不可能再从 第1行，第1列 一直输出到 第1210行，第1210列。因此我们需要定义几个标记变量
//每一步指令执行结束后，轨迹点停留的坐标(stx,sty) 在最后一步的下一格
//当前指令和上一个指令方向相反时。符号输入不再从 “下一格”开始输入了，而是从 “最后一步” 所在的位置原路返回。
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//typedef struct step{
//	char d;
//	int n;
//}step;
//
//int main(){
//	int n = 1,m = 1,x = 0,y = 0,index_x = 0,index_y = 0;
//	int k = 0;
//	scanf("%d",&k);
//
//	step *s = (step*)malloc(sizeof(step) * k);
//
//	//创建地图
//	for(int i = 0;i < k;i++){
//		scanf(" %c",&s[i].d);
//		scanf("%d",&s[i].n);
//
//		if(s[i].d == 'R'){
//			if(x + 1 + s[i].n > n){
//				n = x + 1 + s[i].n;
//				x = x + 1 + s[i].n;
//			}
//			index_x += 1 + s[i].n;
//		}
//		if(s[i].d == 'L'){
//			if(x - 1 - s[i].n < 0){
//				n += abs(x - 1 - s[i].n);
//				x = 0;
//				index_x = 0;
//			}else{
//				x = x - 1 - s[i].n;
//				index_x = index_x - 1 - s[i].n;
//			}
//		}
//
//		if(s[i].d == 'U'){
//			if(y + 1 + s[i].n > m){
//				m = y + 1 + s[i].n;
//				y = y + 1 + s[i].n;
//			}
//			index_y += 1 + s[i].n;
//		}
//		if(s[i].d == 'D'){
//			if(y - 1 - s[i].n < 0){
//				m += abs(y - 1 - s[i].n);
//				y = 0;
//				index_y = 0;
//			}else{
//				y = y - 1 - s[i].n;
//				index_y = index_y - 1 - s[i].n;
//			}
//		}
//		//printf("x:y ? %d %d\n",index_x,index_y);
//	}
//	//printf("%d*%d\n%d %d\n",n,m,index_x,index_y);
////	char **map = (char**)malloc(sizeof(char*) * m);
////	for(int i = 0;i < m;i++)map[i] = (char*)malloc(sizeof(char) * n);
//	char map[1000][1000];
//	//初始化地图
//	for(int i = 0;i < m;i++){
//		for(int j = 0;j < n;j++){
//			map[i][j] = ' ';
//		}
//	}
//	//制作地图
//	for(int i = k - 1;i >= 0;i--){
//		if(s[i].d == 'R'){
//			index_x--;
//			for(int j = 0;j < s[i].n;j++){
//				if(map[index_y][index_x] != '|'){
//					//printf("R:%d %d\n",index_x,index_y);
//					map[index_y][index_x--] = '_';
//				}
//			}
//		}else if(s[i].d == 'L'){
//			index_x++;
//			for(int j = 0;j < s[i].n;j++){
//				if(map[index_y][index_x] != '|'){
//					//printf("L:%d %d\n",index_x,index_y);
//					map[index_y][index_x++] = '_';
//				}
//			}
//		}else if(s[i].d == 'U'){
//			for(int j = 0;j < s[i].n;j++){
//				index_y--;
//				//printf("U:%d %d\n",index_x,index_y);
//				map[index_y][index_x] = '|';
//			}
//		}else{//D
//			for(int j = 0;j < s[i].n;j++){
//				//printf("D:%d %d\n",index_x,index_y);
//				map[index_y++][index_x] = '|';
//			}
//		}
//	}
//
//    // 输出地图（去掉行末空格）
//    for (int i = m - 1; i >= 0; i--) {
//        int end = n - 1;
//        // 从后往前找到第一个非空格字符
//        while (end >= 0 && map[i][end] == ' ') {
//            end--;
//        }
//        // 输出有效字符
//        for (int j = 0; j <= end; j++) {
//            printf("%c", map[i][j]);
//        }
//        printf("\n");
//    }
//
//	//for(int i = 0;i < m;i++)free(map[i]);
//	//free(map);
//	free(s);
//	return 0;
//}
//修正
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//typedef struct step{
//    char d;
//    int n;
//}step;
//
//int main(){
//    int k = 0;
//    scanf("%d", &k);
//
//    step *s = (step*)malloc(sizeof(step) * k);
//
//    // 初始化地图
//    char map[1210][1210];
//    for(int i = 0; i < 1210; i++){
//        for(int j = 0; j < 1210; j++){
//            map[i][j] = ' ';
//        }
//    }
//
//    // 边界记录数组，记录每行的最右位置
//    int tags[1210] = {0};
//
//    // 初始位置和边界
//    int x = 500, y = 500;  // 当前位置
//    int ups = 500, downs = 500, lefts = 500;  // 上下左边界
//    char prev_d = ' ';  // 上一个方向
//
//    // 绘制地图
//    for(int i = 0; i < k; i++){
//        scanf(" %c", &s[i].d);
//        scanf("%d", &s[i].n);
//
//        char d = s[i].d;
//        int n = s[i].n;
//
//        if(d == 'L'){
//            if(prev_d == 'R') y--;  // 如果上一步向右，先退一格
//            if(prev_d == 'D') x--;  // 如果上一步向下，在同一行左移
//            if(prev_d == 'U' || prev_d == 'D') y--;  // 如果上一步向上/下，起始位置左移一步
//
//            if(x < ups) ups = x;  // 更新上边界
//
//            // 记录当前行的最右位置
//            if(tags[x] < y) tags[x] = y;
//
//            // 绘制水平线
//            for(int j = 0; j < n; j++, y--){
//                if(map[x][y] != '|'){  // '|'优先级更高
//                    map[x][y] = '_';
//                }
//            }
//
//            if(y < lefts) lefts = y + 1;  // 更新左边界
//        }
//        else if(d == 'R'){
//            if(prev_d == 'L') y++;  // 如果上一步向左，先退一格
//            if(prev_d == 'D') x--;  // 如果上一步向下，在同一行右移
//            if(prev_d == 'U' || prev_d == 'D') y++;  // 如果上一步向上/下，起始位置右移一步
//
//            if(x < ups) ups = x;  // 更新上边界
//
//            // 绘制水平线
//            for(int j = 0; j < n; j++, y++){
//                if(map[x][y] != '|'){  // '|'优先级更高
//                    map[x][y] = '_';
//                }
//            }
//
//            // 记录当前行的最右位置
//            if(tags[x] < y) tags[x] = y - 1;
//        }
//        else if(d == 'U'){
//            if(prev_d == 'D') x--;  // 如果上一步向下，先退一格
//
//            if(y < lefts) lefts = y;  // 更新左边界
//
//            // 绘制垂直线
//            for(int j = 0; j < n; j++, x--){
//                map[x][y] = '|';
//                if(tags[x] < y) tags[x] = y;  // 记录当前行的最右位置
//            }
//
//            if(x < ups) ups = x + 1;  // 更新上边界
//        }
//        else if(d == 'D'){
//            if(prev_d == 'U') x++;  // 如果上一步向上，先退一格
//            if(prev_d == 'L' || prev_d == 'R') x++;  // 如果上一步左右移动，从下一行开始
//
//            if(y < lefts) lefts = y;  // 更新左边界
//
//            // 绘制垂直线
//            for(int j = 0; j < n; j++, x++){
//                map[x][y] = '|';
//                if(tags[x] < y) tags[x] = y;  // 记录当前行的最右位置
//            }
//
//            if(x > downs) downs = x - 1;  // 更新下边界
//        }
//
//        prev_d = d;  // 记录当前方向作为下一个的上一个方向
//    }
//
//    // 输出地图（根据边界优化输出）
//    for(int i = ups; i <= downs; i++){
//        for(int j = lefts; j <= tags[i]; j++){
//            printf("%c", map[i][j]);
//        }
//        printf("\n");
//    }
//
//    free(s);
//    return 0;
//}

//------------------------------------------------------
//问题 J: 神经网络
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(){
//	int T,n,m;
//	int connect[101],process[101],process_temp[101],result[101][101];
//	scanf("%d",&T);
//	
//	while(T--){
//		//m层 n个神经节 
//		scanf("%d %d",&n,&m);
//		
//		for(int i = 1;i <= n;i++){
//			scanf("%d",connect + i);
//		} 
//		
//		//test		
////		printf("connect : ");
////		for(int i = 1;i <= n;i++){
////			printf("%d ",connect[i]); 
////		}		
////		printf("\n");		
//		//test	
//			
//		for(int i = 1;i <= n;i++){
//			//过程量整体初始化
//			for(int j = 1;j <= n;j++){
//				process_temp[j] = 0;
//			} 
//			
//			//printf("new : \n");	
//			
//			//计算过程量 
//			for(int j = 1;j < m;j++){
//				
//				//过程量初始化 
//				if(j == 1){
//					if(connect[i] != 1){
//						process_temp[connect[i]] = 1;
//						process_temp[connect[i] - 1] = 1;
//					}else{
//						process_temp[1] = 1;
//					} 
//				}else{
//					for(int k = 1;k <= n;k++){
//						if(process_temp[k] != 0){
//							if(connect[k] != 1){
//								process[connect[k]] = 1;
//								process[connect[k] - 1] = 1;
//							}else{
//								process[1] = 1;
//							} 						
//						}	
//					}	
//					
//					for(int j = 1;j <= n;j++){
//						process_temp[j] = process[j];
//						process[j] = 0;
//					}					
//				}	
//				
//				//test
////				printf("process : ");
////				for(int i = 1;i <= n;i++){
////					printf("%d ",process_temp[i]); 
////				}		
////				printf("\n");
//				//test
//							
//			}
//			
//			//最后一次过程量就是列答案
//			for(int j = 1;j <= n;j++){
//				result[j][i] = process_temp[j];
//			}
//		}
//		//输出结果
//		for(int i = 1;i <= n;i++){
//			for(int j = 1;j <= n;j++){
//				printf("%d",result[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");		
//	}
//
//	return 0;
//} 
