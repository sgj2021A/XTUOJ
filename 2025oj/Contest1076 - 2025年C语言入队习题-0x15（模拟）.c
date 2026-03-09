#define _CRT_SECURE_NO_WARNINGS
///问题 A: 黑棋和白棋

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main(){
//      int T;
//      scanf("%d",&T);
//      while(T--){
//              int n;
//              scanf("%d",&n);
//              
//              //BW.
//              char **map = (char**)malloc(sizeof(char*) * (n + 1));
//              for(int i = 0;i < n + 1;i++){
//                      map[i] = (char*)malloc(sizeof(char) * n);
//              }
//              
//              for(int i = 0;i < n;i++){
//                      scanf("%s",map[i]);
//              }
//              
//              //map[y][x]
//              char temp = '\0';
//              int total_B = 0;
//              int total_W = 0;
//              int temp_W = 0;
//              int temp_B = 0;
//              
//              //处理|
//              temp = 0;
//              for(int x = 0;x < n;x++){
//                      temp_B = 0;
//                      temp_W = 0;
//                      for(int y = 0;y < n;y++){
//                              if(temp != map[y][x]){
//                                      if(temp_B >= 3){
//                                              total_B++;
//                                      }else if(temp_W >= 3){
//                                              total_W++;
//                                      }                                       
//                                      temp_B = 0;
//                                      temp_W = 0;
//                                      temp = map[y][x];
//                              }
//                              if(temp == 'B'){
//                                      temp_B++;
//                              }else if(temp == 'W'){
//                                      temp_W++;
//                              }
//                      }
//                      if(temp_B >= 3){
//                              total_B++;
//                      }else if(temp_W >= 3){
//                              total_W++;
//                      }                       
//              }
//              //处理-
//              temp = 0;
//              for(int y = 0;y < n;y++){
//                      temp_B = 0;
//                      temp_W = 0;
//                      for(int x = 0;x < n;x++){
//                              if(temp != map[y][x]){
//                                      if(temp_B >= 3){
//                                              total_B++;
//                                      }else if(temp_W >= 3){
//                                              total_W++;
//                                      }
//                                      temp_B = 0;
//                                      temp_W = 0;
//                                      temp = map[y][x];
//                              }
//                              if(temp == 'B'){
//                                      temp_B++;
//                              }else if(temp == 'W'){
//                                      temp_W++;
//                              }
//                      }
//                      if(temp_B >= 3){
//                              total_B++;
//                      }else if(temp_W >= 3){
//                              total_W++;
//                      }                       
//              }
//              //处理斜角
//              temp = 0;
//              for(int i = 0;i < n;i++){
//                      temp_B = 0;
//                      temp_W = 0;
//                      int y = 0;
//                      for(int x = i;x < n;x++){
//                              if(temp != map[y][x]){
//                                      if(temp_B >= 3){
//                                              total_B++;
//                                      }else if(temp_W >= 3){
//                                              total_W++;
//                                      }
//                                      temp_B = 0;
//                                      temp_W = 0;
//                                      temp = map[y][x];
//                              }
//                              if(temp == 'B'){
//                                      temp_B++;
//                              }else if(temp == 'W'){
//                                      temp_W++;
//                              }
//                              y++;
//                      }
//                      if(temp_B >= 3){
//                              total_B++;
//                      }else if(temp_W >= 3){
//                              total_W++;
//                      }
//              }
//              
//              temp = 0;
//              for(int i = n - 1;i >= 0;i--){
//                      int y = n - 1;
//                      temp_B = 0;
//                      temp_W = 0;
//                      for(int x = i;x >= 0;x--){
//                              if(temp != map[y][x]){
//                                      if(temp_B >= 3){
//                                              total_B++;
//                                      }else if(temp_W >= 3){
//                                              total_W++;
//                                      }
//                                      temp_B = 0;
//                                      temp_W = 0;
//                                      temp = map[y][x];
//                              }
//                              if(temp == 'B'){
//                                      temp_B++;
//                              }else if(temp == 'W'){
//                                      temp_W++;
//                              }
//                              y--;
//                      }
//                      if(temp_B >= 3){
//                              total_B++;
//                      }else if(temp_W >= 3){
//                              total_W++;
//                      }
//              }
//              
//              temp = 0;
//              for(int i = 1;i < n;i++){
//                      int x = 0;
//                      temp_B = 0;
//                      temp_W = 0;
//                      for(int y = i;y < n;y++){
//                              if(temp != map[y][x]){
//                                      if(temp_B >= 3){
//                                              total_B++;
//                                      }else if(temp_W >= 3){
//                                              total_W++;
//                                      }
//                                      temp_B = 0;
//                                      temp_W = 0;
//                                      temp = map[y][x];
//                              }
//                              if(temp == 'B'){
//                                      temp_B++;
//                              }else if(temp == 'W'){
//                                      temp_W++;
//                              }
//                              x++;
//                      }
//                      if(temp_B >= 3){
//                              total_B++;
//                      }else if(temp_W >= 3){
//                              total_W++;
//                      }
//              }
//              
//              temp = 0;
//              for(int i = n - 1;i >= 1;i--){
//                      int x = n - 1;
//                      temp_B = 0;
//                      temp_W = 0;
//                      for(int y = i;y >= 1;y--){
//                              if(temp != map[y][x]){
//                                      if(temp_B >= 3){
//                                              total_B++;
//                                      }else if(temp_W >= 3){
//                                              total_W++;
//                                      }
//                                      temp_B = 0;
//                                      temp_W = 0;
//                                      temp = map[y][x];
//                              }
//                              if(temp == 'B'){
//                                      temp_B++;
//                              }else if(temp == 'W'){
//                                      temp_W++;
//                              }
//                              x--;
//                      }
//                      if(temp_B >= 3){
//                              total_B++;
//                      }else if(temp_W >= 3){
//                              total_W++;
//                      }
//              }
//              
//              printf("%d %d\n",total_B,total_W);
//              
//              for(int i = 0;i < n;i++){
//                      free(map[i]);
//              }               
//              free(map);
//      }
//      return 0;
//}
//修改
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main(){
//    int T;
//    scanf("%d",&T);
//    while(T--){
//        int n;
//        scanf("%d",&n);
//        
//        // 分配内存
//        char **map = (char**)malloc(sizeof(char*) * n);
//        for(int i = 0; i < n; i++){
//            map[i] = (char*)malloc(sizeof(char) * (n + 1)); // +1 for null terminator
//        }
//        
//        for(int i = 0; i < n; i++){
//            scanf("%s", map[i]);
//        }
//        
//        int total_B = 0;
//        int total_W = 0;
//        
//        // 检查水平方向
//        for(int y = 0; y < n; y++){
//            int count_B = 0, count_W = 0;
//            for(int x = 0; x < n; x++){
//                if(map[y][x] == 'B'){
//                    count_B++;
//                    count_W = 0;
//                } else if(map[y][x] == 'W'){
//                    count_W++;
//                    count_B = 0;
//                } else {
//                                      count_B = 0;
//                                      count_W = 0;
//                              }
//                
//                if(count_B == 3){
//                    total_B++;
//                }
//                if(count_W == 3){
//                    total_W++;
//                }
//            }
//        }
//        
//        // 检查垂直方向
//        for(int x = 0; x < n; x++){
//            int count_B = 0, count_W = 0;
//            for(int y = 0; y < n; y++){
//                if(map[y][x] == 'B'){
//                    count_B++;
//                    count_W = 0;
//                } else if(map[y][x] == 'W'){
//                    count_W++;
//                    count_B = 0;
//                } else {
//                                      count_B = 0;
//                                      count_W = 0;
//                              }
//                
//                if(count_B == 3){
//                    total_B++;
//                }
//                if(count_W == 3){
//                    total_W++;
//                }
//            }
//        }
//        
//        // 检查主对角线方向
//        for(int start = 0; start < n; start++){
//            // 从第一行开始的对角线
//            int count_B = 0, count_W = 0;
//            for(int y = 0, x = start; y < n && x < n; y++, x++){
//                if(map[y][x] == 'B'){
//                    count_B++;
//                    count_W = 0;
//                } else if(map[y][x] == 'W'){
//                    count_W++;
//                    count_B = 0;
//                } else {
//                    count_B = count_W = 0;
//                }
//                
//                if(count_B == 3){
//                    total_B++;
//                }
//                if(count_W == 3){
//                    total_W++;
//                }
//            }
//            
//            // 从第一列开始的对角线（跳过重复的第一个）
//            if(start > 0){
//                count_B = 0; count_W = 0;
//                for(int y = start, x = 0; y < n && x < n; y++, x++){
//                    if(map[y][x] == 'B'){
//                        count_B++;
//                        count_W = 0;
//                    } else if(map[y][x] == 'W'){
//                        count_W++;
//                        count_B = 0;
//                    } else {
//                        count_B = count_W = 0;
//                    }
//                    
//                    if(count_B == 3){
//                        total_B++;
//                    }
//                    if(count_W == 3){
//                        total_W++;
//                    }
//                }
//            }
//        }
//        
//        // 检查副对角线方向（右上到左下）
//        for(int start = 0; start < n; start++){
//            // 从第一行开始的对角线
//            int count_B = 0, count_W = 0;
//            for(int y = 0, x = start; y < n && x >= 0; y++, x--){
//                if(map[y][x] == 'B'){
//                    count_B++;
//                    count_W = 0;
//                } else if(map[y][x] == 'W'){
//                    count_W++;
//                    count_B = 0;
//                } else {
//                    count_B = count_W = 0;
//                }
//                
//                if(count_B == 3){
//                    total_B++;
//                }
//                if(count_W == 3){
//                    total_W++;
//                }
//            }
//            
//            // 从最后一列开始的对角线（跳过重复的最后一个）
//            if(start > 0){
//                count_B = 0; count_W = 0;
//                for(int y = start, x = n - 1; y < n && x >= 0; y++, x--){
//                    if(map[y][x] == 'B'){
//                        count_B++;
//                        count_W = 0;
//                    } else if(map[y][x] == 'W'){
//                        count_W++;
//                        count_B = 0;
//                    } else {
//                        count_B = count_W = 0;
//                    }
//                    
//                    if(count_B == 3){
//                        total_B++;
//                    }
//                    if(count_W == 3){
//                        total_W++;
//                    }
//                }
//            }
//        }
//        
//        printf("%d %d\n", total_B, total_W);
//        
//        // 释放内存
//        for(int i = 0; i < n; i++){
//            free(map[i]);
//        }       
//        free(map);
//    }
//    return 0;
//}

//-----------------------------------------
//问题 B: 拼图

//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//
//#define R 4
//static int com(char* a, char* b) {
//	if (tolower(*a) != tolower(*b)) return 0;
//	if (*a == *b) return 0; // 必须大小写不同
//	return 1;
//}
//static int find(char* A, char* B, char* C, char* D) {
//	int found = 0;
//	
//	for (int a = 0; a < R; a++) {
//		for (int b = 0; b < R; b++) {
//			for (int c = 0; c < R; c++) {
//				for (int d = 0; d < R; d++) {
//					if (com(&A[a], &B[(b + 1) % R]) && com(&A[(a + 1) % R], &C[c]) && com(&B[b], &D[(d + 1) % R]) && com(&D[d], &C[(c + 1) % R])) {
//						found = 1;
//					}
//					//if (com(&A[(a + 1) % R], &B[(b + 3) % R]) &&
//					//	com(&A[(a + 2) % R], &C[c]) &&
//					//	com(&B[(b + 2) % R], &D[d]) &&
//					//	com(&C[(c + 1) % R], &D[(d + 3) % R])) {
//					//	found = 1;
//					//}
//				}
//				if (found) break;
//			}
//			if (found) break;
//		}
//		if (found) break;
//	}
//	return found;
//}
//int main() {
//	//test
//	//char a, b;
//	//a = getchar();
//	//b = getchar();
//	//printf("%d\n",com(&a,&b));
//	//test
//	int T;
//	scanf("%d", &T);
//
//	while (T--) {
//		char block[4][5];
//		
//		for (int i = 0; i < 4; i++) {
//			scanf("%s", block[i]);
//		}
//
//	int found = 0;
//	////0|1
//	////---
//	////2|3
//	//found = find(block[0], block[1], block[2], block[3]);
//
//	////0|1
//	////---
//	////3|2
//	//if (!found) {
//	//	found = find(block[0], block[1], block[3], block[2]);
//	//}
//
//	////0|2
//	////---
//	////3|1
//	//if (!found) {
//	//	found = find(block[0], block[2], block[3], block[1]);
//	//}
//
//	for (int i0 = 0; i0 < 4 && !found; i0++) {
//		for (int i1 = 0; i1 < 4 && !found; i1++) {
//			if (i1 == i0) continue;
//			for (int i2 = 0; i2 < 4 && !found; i2++) {
//				if (i2 == i0 || i2 == i1) continue;
//				for (int i3 = 0; i3 < 4 && !found; i3++) {
//					if (i3 == i0 || i3 == i1 || i3 == i2) continue;
//					found = find(block[i0], block[i1], block[i2], block[i3]);
//				}
//			}
//		}
//	}
//
//	if (found) printf("Yes\n");
//		else printf("No\n");
//	}
//
//	return 0;
//}

//-----------------------------------------
//问题 C: 3个矩形与1个正方形

//#include <stdio.h>
//int condition_1(int arr[3][2]) {
//	int temp = 0;
//	int result = 0;
//	for (int i = 0; i < 2; i++) {
//		temp = arr[0][i];
//		for (int j = 0; j < 2; j++) {
//			if (temp == arr[1][j]) {
//				for (int z = 0; z < 2; z++) {
//					if (temp == arr[2][z]) {
//						result = result > temp ? result : temp;
//					}
//				}
//			}
//		}
//	}
//	return result;
//}
//
//
//int main() {
//	int T;
//	scanf("%d", &T);
//
//	while (T--) {
//		int arr[3][2];
//		for (int i = 0; i < 3; i++) {
//			scanf("%d %d", &arr[i][0], &arr[i][1]);
//		}
//		
//		//printf("%d\n", condition_1(arr));
//		//condition_1 |||
//		int max = condition_1(arr);
//		if (max != 0) {
//			int total = 0;
//			for (int i = 0; i < 3; i++) {
//				if (max != arr[i][0])total += arr[i][0];
//				else total += arr[i][1];
//			}
//			//printf("total : %d\n", total);
//			if (total == max) {
//				printf("Yes\n");
//				continue;
//			}
//		}
//
//		//conitidion_2 :  |—
//		//                |—
//		int found = 0; 
//		int a = 0, b = 0, c = 0;
//		for (int i = 0; i < 2; i++) {
//			for (int j = 0; j < 2; j++) {
//				for (int z = 0; z < 2; z++) {
//					if (arr[0][i] == arr[1][j]) {
//						b = arr[0][i] + arr[2][(z + 1) % 2];
//						a = arr[2][z];
//						c = arr[0][(i + 1) % 2] + arr[1][(j + 1) % 2];
//					}
//					if (a == b && a != 0 && b != 0 && a == c) {
//						found = 1;
//					}
//					a = 0, b = 0, c = 0;
//					if (arr[0][i] == arr[2][z]) {
//						b = arr[0][i] + arr[1][(j + 1) % 2];
//						a = arr[1][j];
//						c = arr[0][(i + 1) % 2] + arr[2][(z + 1) % 2];
//					}
//					if (a == b && a != 0 && b != 0 && a == c) {
//						found = 1;
//					}
//					a = 0, b = 0, c = 0;
//					if (arr[1][j] == arr[2][z]) {
//						b = arr[1][j] + arr[0][(i + 1) % 2];
//						a = arr[0][i];
//						c = arr[1][(j + 1) % 2] + arr[2][(z + 1) % 2];
//					}
//					if (a == b && a != 0 && b != 0 && a == c) {
//						found = 1;
//					}
//					a = 0, b = 0, c = 0;
//				}
//				if (found)break;
//			}
//			if (found)break;
//		}
//
//		if (found) {
//			printf("Yes\n");
//		}
//		else {
//			printf("No\n");
//		}
//	}
//
//	return 0;
//}

//-----------------------------------------
//问题 D: 表格

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define R 21
//
//int main() {
//	int T;
//	scanf("%d", &T);
//	
//	while (T--) {
//		int r, l;
//		scanf("%d %d", &r, &l);
//
//		char* control = (char*)malloc(sizeof(r) * (l + 1));
//		char*** map = (char***)malloc(sizeof(char**) * r);
//		//map[r][l][21]
//		for (int i = 0; i < r; i++) {
//			map[i] = (char**)malloc(sizeof(char*) * l);
//		}
//		for (int i = 0; i < r; i++) {
//			for (int j = 0; j < l; j++) {
//				map[i][j] = (char*)malloc(sizeof(char) * R);
//			}
//		}
//
//		//input
//		scanf("%s", control);
//		for (int i = 0; i < r; i++) {
//			for (int j = 0; j < l; j++) {
//				scanf("%s", map[i][j]);
//			}
//		}
//
//		int* size = (int*)calloc(l, sizeof(int));
//		for (int i = 0; i < l; i++) {
//			for (int j = 0; j < r; j++) {
//				int temp = strlen(map[j][i]) + 2;
//				size[i] = size[i] > temp ? size[i] : temp;
//				
//			}
//		}
//
//		//for (int i = 0; i < l; i++) {
//		//	printf("%d ", size[i]);
//		//}
//
//		for (int i = 0; i < l; i++) {
//			printf("+");
//			for(int j = 0;j < size[i];j++){
//				printf("-");
//			}
//		}
//		printf("+\n");
//
//		for (int i = 0; i < r; i++) {
//			//字符输出算法
//			for (int j = 0; j < l; j++) {
//				int len = strlen(map[i][j]);
//				int blank = (size[j] > len) ? (size[j] - len) : 2;
//				printf("|");
//
//				if (control[j] == 'l') {
//					printf(" %s",map[i][j]);
//					for (int z = 0; z < blank - 1; z++) {
//						printf(" ");
//					}
//				}
//				else if (control[j] == 'r') {
//					for (int z = 0; z < blank - 1; z++) {
//						printf(" ");
//					}
//					printf("%s ", map[i][j]);
//				}
//				else {
//					int blank_left = blank / 2;
//					int blank_right = (blank + 1) / 2;
//					for (int z = 0; z < blank_left; z++) {
//						printf(" ");
//					}
//					printf("%s", map[i][j]);
//					for (int z = 0; z < blank_right; z++) {
//						printf(" ");
//					}
//				}
//			}
//
//			printf("|\n");
//			for (int j = 0; j < l; j++) {
//				printf("+");
//				for (int z = 0; z < size[j]; z++) {
//					printf("-");
//				}
//			}
//			printf("+\n");
//		}
//
//		//free
//		free(size);
//		free(control);
//		for (int i = 0; i < r; i++) {
//			for (int j = 0; j < l; j++) {
//				free(map[i][j]);
//			}
//		}
//		for (int i = 0; i < r; i++) {
//			free(map[i]);
//		}
//		free(map);
//	}
//
//	return 0;
//}

//-----------------------------------------
//问题 F: 素数螺旋

//#include <string.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <stdio.h>
//#define R 2000
//void output(char** map, int rows, int cols,int top_min) {
//	for (int col = cols - 1; col >= 0; col--) {
//		int top = 0, bottom = rows - 1;
//		while (top < rows && map[top][col] == '\0') {
//			top++;
//		}
//		if (top >= rows) {
//			continue; 
//		}
//		while (bottom >= 0 && map[bottom][col] == '\0') {
//			bottom--;
//		}
//		for (int row = top_min; row <= bottom; row++) {
//			if (map[row][col] != '|' && map[row][col] != '_') {
//				printf(" ");
//			}
//			else {
//				printf("%c", map[row][col]);
//			}
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//int* isPrime() {
//	bool* prime = (bool*)malloc(sizeof(bool) * 1000);
//	int* total = (int*)malloc(sizeof(int) * 200);
//	int index = 0;
//
//	for (int i = 0; i < 1000; i++) {
//		prime[i] = true;
//	}
//	prime[0] = false;
//	prime[1] = false;
//	for (int i = 2; i < 1000; i++) {
//		if (prime[i]) {
//			total[index++] = i;
//		}
//		for (int j = 0; j < index && i * total[j] < 1000; j++) {
//			prime[i * total[j]] = false;
//			if (i % total[j] == 0)break;
//		}
//	}
//
//	free(prime);
//	return total;
//}
//
//int main() {
//	int* prime = isPrime();
//	char** map = (char**)malloc(sizeof(char*) * R);
//	for (int i = 0; i < R; i++) {
//		map[i] = (char*)malloc(sizeof(char) * R);
//	}
//	//map[x][y]
//
//	//test
//	//printf("prime : ");
//	//for (int i = 0; i < 168; i++) {
//	//	printf("%d ", prime[i]);
//	//}
//	//printf("\n");
//	//test
//	
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		//init
//		int top_min = 1000;
//		for (int i = 0; i < R; i++) {
//			for (int j = 0; j < R; j++) {
//				map[i][j] = '\0';
//			}
//		}
//
//		//input
//		int n = 0;
//		scanf("%d", &n);
//
//		int x = 1000, y = 1000;
//		int toword = 0;//0 右边 1 上边 2 左边 3 下边
//		//map[x][y]
//		for (int i = 0; i < n; i++) {
//			if (toword == 0) {//0 右边
//				for (int j = 0; j < prime[i]; j++) {
//					map[x++][y] = '_';
//				}
//			}
//			else if (toword == 1) {//1 上边
//				for (int j = 0; j < prime[i]; j++) {
//					map[x][y++] = '|';
//				}
//				x--;
//			}
//			else if (toword == 2) {//2 左边
//				for (int j = 0; j < prime[i]; j++) {
//					map[x--][y] = '_';
//				}
//				y--;
//			}
//			else {//3 下边
//				for (int j = 0; j < prime[i]; j++) {
//					map[x][y--] = '|';
//				}
//				y++;
//				x++;
//			}
//			if (i < n - 1) {
//				top_min = top_min < x ? top_min : x;
//			}
//			else if (i == n - 1) {
//				if(toword == 2){
//					top_min = top_min < x + 1 ? top_min : x + 1;
//				}
//				else {
//					top_min = top_min < x ? top_min : x;
//				}
//			}
//			toword = (toword + 1) % 4;
//		}
//		output(map, R, R, top_min);
//	}
//		
//	free(prime);
//	for (int i = 0; i < R; i++) {
//		free(map[i]);
//	}
//	free(map);
//	return 0;
//}

//-----------------------------------------
//问题 G: Patchouli的金字塔

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int T = 0;
//	scanf("%d", &T);
//	
//	//init
//	int lay[33];
//	lay[0] = 1;
//	for (int i = 1; i < 33; i++) {
//		lay[i] = lay[i - 1] + 2;
//	}
//	int pre[33];
//	pre[0] = lay[0];
//	for (int i = 1; i < 33; i++) {
//		pre[i] = pre[i - 1] + lay[i];
//	}
//	for (int i = 0; i < 33; i++) {
//		lay[i] -= i;
//	}
//	while (T--) {
//		int n;
//		scanf("%d", &n);
//		//find enough lay
//		int enough = 1;
//		for (; enough < 33; enough++) {
//			if (n <= pre[enough])break;
//		}
//		int out = n - pre[enough - 1];
//
////		printf("enough : %d out : %d\n", enough,out);
//
//		int blank = 0;
//		if (out == 0) {
//			blank = lay[enough - 1] * 4 + 1;
//			blank = blank / 2;
//		}
//		else {
//			blank = lay[enough] * 4 + 1;
//			blank = blank / 2;
//		}
//
//
//		for (int i = 0; i < blank; i++) {
//			printf(" ");
//		}
//		printf("*\n");
//
//		//输出满行数据
//		for (int i = 0; i < enough; i++) {
//			//输出
//			blank -= 2;
//			for (int j = 0; j < blank; j++) {
//				printf(" ");
//			}
//			for (int j = 0; j < lay[i]; j++) {
//				printf(" / \\");
//			}
//			printf("\n");
//			for (int j = 0; j < blank; j++) {
//				printf(" ");
//			}
//			printf("*");
//			for (int j = 0; j < lay[i]; j++) {
//				printf(" - *");
//			}
//			printf("\n");
//		}
//		//输出多余行
//		if (out != 0) {
//			blank -= 2;
//			int change = 0;
//			for (int j = 0; j < blank; j++) {
//				printf(" ");
//			}
//			if (out >= 1) {
//				printf(" / \\");
//				out--;
//			}
//			for (int j = 0; j < out; j++) {
//				if (change == 0) {
//					printf(" /");
//					change = 1;
//				}
//				else {
//					change = 0;
//					printf(" \\");
//				}
//			}
//			printf("\n");
//			for (int j = 0; j < blank; j++) {
//				printf(" ");
//			}
//			printf("* - *");
//			change = 1;
//			for (int j = 0; j < out; j++) {
//				if (change == 0) {
//					printf(" - *");
//					change = 1;
//				}
//				else {
//					change = 0;
//				}
//			}
//			printf("\n");
//		}
//	}
//
//	return 0;
//}

//-----------------------------------------
//问题 H: 菱形 I

//#include <stdio.h>
//
//int main() {
//	int n;
//	int lay[100];
//	lay[0] = 1;
//	for (int i = 1; i < 100; i++) {
//		lay[i] = lay[i - 1] + 1;
//	}
//	int pre[20];
//	pre[0] = 1;
//	for (int i = 1; i < 20; i++) {
//		pre[i] = 0;
//		for (int j = 0; j < i; j++) {
//			pre[i] += lay[j] * 2;
//		}
//		pre[i] += lay[i];
//	}
//
//	int lay_up[100];
//	lay_up[0] = lay[0];
//	for (int i = 1; i < 100; i++) {
//		lay_up[i] = lay[i] + lay_up[i - 1];
//	}
//	while (1) {
//		scanf("%d", &n);
//		if (n == 0)return 0;
//		
//		if (n == 1) {
//			printf("/\\\n\\/\n");
//			continue;
//		}
//
//		int k = 0;
//		for (; k < 20; k++) {
//			if (n <= pre[k])break;
//		}
//
//		int half = (pre[k] + lay[k]) / 2;
//		//printf("half : %d\n", half);
//		
//		int blank = 0;
//		if (n > half) {//在下面
//			blank = lay[k] - 1;
//			for (int i = 0; i <= k; i++) {
//				for (int j = 0; j < blank; j++) {
//					printf(" ");
//				}
//				blank -= 1;
//				for (int j = 0; j < lay[i]; j++) {
//					printf("/\\");
//				}
//				printf("\n");
//				
//			}
//			for (int j = 0; j < blank; j++) {
//				printf(" ");
//			}
//			for (int j = 0; j < lay[k]; j++) {
//				printf("\\/");
//			}
//			printf("\n");
//			blank = 0;
//			int out = n - half;
//			int temp = 0;
//			int index = k - 1;
//			if (out != 0) {
//				blank++;
//				printf(" ");
//				for (int i = 0; i < out; i++) {
//					if (temp >= lay[index]) {
//						index--;
//						printf("\n");
//						temp = 0;
//						blank++;
//						for (int j = 0; j < blank; j++) {
//							printf(" ");
//						}
//					}
//					printf("\\/");
//					temp++;
//				}
//				printf("\n");
//			}
//		}
//		else {//在上面
//			blank = lay[k] - 1;
//			int enough = 0;
//			for (; enough < 20; enough++) {
//				if (n <= lay_up[enough])break;
//			}
//			int out;
//			if(n == lay_up[enough]){
//				out = 0;
//			}else{
//				out = n - lay_up[enough - 1];
//			}
//			
////			printf("out : %d enough : %d\n",out,enough);
//			int temp_1 = 0;
//			if(out == 0){
//				for(int i = 0;i <= enough;i++){
//					for(int j = 0;j < blank;j++){
//						printf(" ");
//					}
//					blank--;
//					for(int j = 0;j < lay[i];j++){
//						printf("/\\");
//						temp_1 = j;
//					}
//					printf("\n");
//				}
//				for(int j = 0;j < lay[temp_1];j++){
//					printf("\\/");
//				}
//				printf("\n");
//			}else{
//				int temp_2 = 0;
//				for(int i = 0;i <= enough - 1;i++){
//					for(int j = 0;j < blank;j++){
//						printf(" ");
//					}
//					blank--;
//					for(int j = 0;j < lay[i];j++){
//						printf("/\\");
//						temp_2 = j;
//					}
//					printf("\n");					
//				}
//				
//				printf("/");
//				for(int i = 0;i <= temp_2;i++){
//					printf("\\/");
//				}
//				printf("\n");
//				for(int i = 0;i < out;i++){
//					printf("\\/");
//				}
//				printf("\n");
//			}
//
//		}
//	}
//	return 0;
//}

//---------------------------------------------
//问题 E: 正方形

//#include <stdio.h>
//#include <stdlib.h>
//
//int heng[55][55],shu[55][55];
//
//void Init(int n){
//	for(int i = 0;i <= n + 1;i++){
//		for(int j = 0;j <= n + 1;j++){
//			heng[i][j] = 1;
//			shu[i][j] = 1;
//		}
//	}
//}
//
//void Delete(int n,int det){
//	int p = det % (2 * n + 1);
//	int x = det / (2 * n + 1) + 1;
//	
//	if(p >= 1 && p <= n){
//		heng[x][p] = 0;
//	}else if(p == 0){
//		shu[x - 1][n + 1] = 0;
//	}else if(p > n && p <= 2 * n){
//		shu[x][p - n] = 0;
//	}
//}
//
//int hl(int index,int left,int right){
//	int total = 0;
//	for(;left<=right;left++){
//		total += heng[index][left];
//	}
//	return total;
//}
//
//int sl(int index,int bottom,int top){
//	int total = 0;
//	for(;bottom <= top;bottom++){
//		total += shu[bottom][index];
//	}
//	return total;
//}
//
//
//int count(int len,int n){
//	int i,j,sum=0;
//	for(i = 1;i+len <= n;i++)
//	{
//		for(j = 1;j+len <= n;j++)
//		{
//			if((hl(i,j,j+len)==len+1) && (sl(j,i,i+len)==len+1) && (hl(i+len+1,j,j+len)==len+1) && (sl(j+len+1,i,i+len)==len+1))
//			{
//				sum++;
//			}
//		}
//	}
//	return sum;
//}
//	
//int main(){
//	int T;
//	scanf("%d",&T);
//	
//	while(T--){
//		int n;
//		scanf("%d",&n);
//		Init(n);
//		
//		int S = 0;
//		scanf("%d",&S);
//		while(S--){
//			int temp = 0;
//			scanf("%d",&temp);
//			Delete(n,temp);
//		}
//		int ans = 0;
//		for(int len = 0;len < n;len++)
//		{
//			ans += count(len,n);
//		}
//		printf("%d\n",ans);
//		
//		
//	}
//	
//	return 0;
//}
