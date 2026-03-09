#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//int main(){
//	int n=0;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++){
//		
//	}
//} 

//问题 A: 三点共线
//int main(){
//	int N = 0;
//	double X[3] = {},Y[3] = {};
//	double x,x2,y,y2;
//	scanf("%d",&N);
//	for(int i = 0;i < N;i++){
//		for(int j=0;j<3;j++)
//			scanf("%lf %lf",&X[j],&Y[j]);
//        // 计算向量AB和AC的叉积
//        double cross = (X[1] - X[0]) * (Y[2] - Y[0]) - 
//                       (Y[1] - Y[0]) * (X[2] - X[0]);
//        
//        // 考虑浮点精度误差
//        if (fabs(cross) < 1e-9) {
//            printf("Yes\n");
//        } else {
//            printf("No\n");
//        }
//	} 
//} 

//问题 B: 区间相交
//int main(){
//	int N=0;
//	int X1=0,X2=0,Y1=0,Y2=0;
//	scanf("%d",&N);
//	for(int i=0;i<N;i++){
//		scanf("%d %d\n%d %d",&X1,&Y1,&X2,&Y2);
//		if(Y1 >= X2 && Y2 >= X1){
//			printf("Yes\n");			
//		}else{
//			printf("No\n");
//		}
//	} 	
//}

//问题 C: A+B I
//int main(){
//	int n=0;
//	int a,b,c;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++){
//		scanf("%d+%d=%d",&a,&b,&c);
//		if(a+b==c){
//			printf("Yes\n");
//		}else{
//			printf("No\n");
//		}
//	}
//} 

//问题 D: Average
//int main(){
//	int n=0;
//	double average=0,a=0,b=0;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++){
//		scanf("%lf %lf",&a,&b);
//		average=(a+b)/2;
//		if(a>b){
//			printf("Bob %g\n",a-average);	
//		}else if(a<b){
//			printf("Alice %g\n",b-average);
//		}else{
//			printf("None\n");
//		}
//	}
//} 

//问题 E: 平方数
//int main(){
//	int n=0;
//	int a=0,c=0,d=0;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++){
//		scanf("%d",&a);
//		c=sqrt(a)-3;
//		d=sqrt(a)+5;
//		for(int i=c;i<d;i++){
//			if(i*i==a){
//				printf("Yes\n");
//				break;
//			}else if(i==d-2){
//				printf("No\n");
//			}
//		}
//	}
//} 

//? Pig Bank ?
//int main(){
//	int n = 0;
//	int a = 0,b = 0,c = 0;
//	scanf("%d",&n);
//	for(int i = 0;i < n;i++){
//		scanf("%d %d %d",&a,&b,&c);
//		if(c - a <= 0){
//			printf("0\n");
//		}else if(c - b < 0){
//			printf("1\n");			
//		}else if((c - a)%b>0){
//			printf("%d\n",(c - a)/b + 1);
//		}else if(c == b){
//			printf("1\n");			
//		}else{
//			printf("%d\n",(c - a)/b);			
//		}
//	}
//}

//问题 G: 象限
//? 象限 ?
//int main(){
//	int n = 0;
//	int x,y;
//	scanf("%d",&n);
//	for(int i = 0;i <n;i++){
//		scanf("%d %d",&x,&y);
//		if(x > 0){
//			if(y > 0){
//				printf("1\n");
//			}else{
//				printf("4\n");				
//			}
//		}else{
//			if(y > 0){
//				printf("2\n");
//			}else{
//				printf("3\n");				
//			}			
//		}
//	}
//}

//问题 H: 直线
//int main(){
//	double a=0,b=0,c=0;
//	double a1=0,b1=0,c1=0;
//	scanf("%lf %lf %lf",&a,&b,&c); 
//	scanf("%lf %lf %lf",&a1,&b1,&c1);
//	if(a*b1!=a1*b){
//		if(a*a1+b*b1==0){
//			printf("vertical");
//		}else{
//			printf("intersect");
//		}
//	}else if(a*b1==a1*b&&a*c1!=a1*c&&b*c1!=b1*c){
//		printf("parallel");
//	}else{
//		printf("collinear");
//	}
//} 
//------------优化 
//#define EPSILON 1e-9
// 
//int isZero(double x) {
//    return fabs(x) < EPSILON;
//}
// 
//int main() {
//    double a, b, c;
//    double a1, b1, c1;
//    scanf("%lf %lf %lf", &a, &b, &c);
//    scanf("%lf %lf %lf", &a1, &b1, &c1);
// 
//    // 1. 判断垂直（法向量点积为 0）
//    if (isZero(a * a1 + b * b1)) {
//        printf("vertical\n");
//    }
//    // 2. 判断平行（叉积为 0）
//    else if (isZero(a * b1 - a1 * b)) {
//        // 检查是否共线（C 系数是否成比例）
//        if (isZero(a * c1 - a1 * c) && isZero(b * c1 - b1 * c)) {
//            printf("collinear\n");
//        } else {
//            printf("parallel\n");
//        }
//    }
//    // 3. 否则相交
//    else {
//        printf("intersect\n");
//    }
// 
//    return 0;
//}

//问题 I: 3个数
//#define EPSILON 1e-9
//bool answer;
//int cs1=0,cs2=0;
//bool isZero(double x) {
//    return fabs(x) < EPSILON;
//}
//double add(double a,double b){
//	return a+b;
//}
//double subtraction(double a,double b){
//	return a-b;
//}
//double multiplication(double a,double b){
//	return a*b; 
//}
//double division(double a,double b){
//	return a/b;
//}
//
//void judgement(int cs,int factor,double a,double b){
//	switch(factor){
//		case 1:
//			if(isZero(add(a,b))){
//				cs1=cs;
//				cs2=factor;
//				answer=true;
//			}
//			break;
//		case 2:
//			if(isZero(subtraction(a,b))){
//				cs1=cs;
//				cs2=factor;				
//				answer=true;
//			}
//			break;
//		case 3:
//			if(isZero(multiplication(a,b))){
//				cs1=cs;
//				cs2=factor;
//				answer=true;
//			}
//			break;
//		case 4:
//			if(b==0){
//				break;
//			}else{
//				if(isZero(division(a,b))){
//					cs1=cs;
//					cs2=factor;
//					answer=true;
//				}
//				break;
//			}
//	}
//}
//
//int main(){
//	int n=0;
//	double a,b,c;
//	scanf("%d",&n);
//	for(int k=0;k<n;k++){
//		scanf("%lf %lf %lf",&a,&b,&c);
//		answer=false;
//		for(int i=1;i<=4;i++){
//			for(int j=0;j<=4;j++){
//				cs1=0,cs2=0;
//				if(answer==true)
//					break;
//				switch(i){
//					case 1:
//						judgement(i,j,add(a,b),c);
//						break;
//					case 2:
//						judgement(i,j,subtraction(a,b),c);
//						break;
//					case 3:
//						judgement(i,j,multiplication(a,b),c);
//						break;
//					case 4:
//						if(b==0){
//							break;
//						}else{
//							judgement(i,j,division(a,b),c);
//							break;
//						}
//				}				
//			}
//			if(answer==true)
//				break;
//		}
//		if(answer==true){
//			printf("Yes\n");
//		}else{
//			printf("No\n");
//		}
//	}
//} 
//------------------优化；错误原因 当a+b*c时 以上算法为(a+b)*c而不是a+b*c 
//注意的是，由于运算顺序是从左到右，所以对于表达式 like a + b * c，我们实际计算的是 (a + b) * c，而不是 a + (b * c)。因为没有括号，所以我们必须按照从左到右的顺序计算。
//#define EPS 1e-9
//
//int main() {
//    int T;
//    scanf("%d", &T);
//    char operators[] = {'+', '-', '*', '/'};
//    
//    while (T--) {
//        int a, b, c;
//        scanf("%d %d %d", &a, &b, &c);
//        int found = 0;
//        
//        for (int i = 0; i < 4; i++) {
//            for (int j = 0; j < 4; j++) {
//                double intermediate;
//                switch (operators[i]) {
//                    case '+': intermediate = a + b; break;
//                    case '-': intermediate = a - b; break;
//                    case '*': intermediate = a * b; break;
//                    case '/': intermediate = (double)a / b; break;
//                }
//                
//                double result;
//                switch (operators[j]) {
//                    case '+': result = intermediate + c; break;
//                    case '-': result = intermediate - c; break;
//                    case '*': result = intermediate * c; break;
//                    case '/': result = intermediate / c; break;
//                }
//                
//                if (fabs(result) < EPS) {
//                    found = 1;
//                    break;
//                }
//            }
//            if (found) break;
//        }
//        
//        if (found) {
//            printf("Yes\n");
//        } else {
//            printf("No\n");
//        }
//    }
//    
//    return 0;
//}
//------------------------------------优化
#include <stdio.h>
int main(){
	double t,a,b,c;
	scanf("%lf",&t);
	while(t--){
		scanf("%lf %lf %lf",&a,&b,&c);
		if(a+b+c==0){
			printf("Yes\n");
			continue;
		}
		if(a+b-c==0){
			printf("Yes\n");
			continue;
		}
		if(a+b*c==0){
			printf("Yes\n");
			continue;
		}
		if(a+b/c==0){
			printf("Yes\n");
			continue;
		}
		if(a-b+c==0){
			printf("Yes\n");
			continue;
		}
		if(a-b-c==0){
			printf("Yes\n");
			continue;
		}
		if(a-b*c==0){
			printf("Yes\n");
			continue;
		}
		if(a-b/c==0){
			printf("Yes\n");
			continue;
		}
		if(a*b+c==0){
			printf("Yes\n");
			continue;
		}
		if(a*b-c==0){
			printf("Yes\n");
			continue;
		}
		if(a*b*c==0){
			printf("Yes\n");
			continue;
		}
		if(a*b/c==0){
			printf("Yes\n");
			continue;
		}
		if(a/b+c==0){
			printf("Yes\n");
			continue;
		}
		if(a/b-c==0){
			printf("Yes\n");
			continue;
		}
		if(a/b*c==0){
			printf("Yes\n");
			continue;
		}
		if(a/b/c==0){
			printf("Yes\n");
			continue;
		}
		printf("No\n");
	}
}

//问题 J: 时间
//int main(){
//	int n = 0;
//	int seconds = 0;
//	int hours = 0, minutes = 0;  
//	scanf("%d",&n);
//	for(int i = 0;i <n;i++){
//		scanf("%d",&seconds);
//		hours = (seconds/60)/60;
//		minutes = seconds/60-hours*60;
//		seconds -= minutes*60+hours*3600;
//		printf("%02d:%02d:%02d\n",hours,minutes,seconds);
//	}		
//}


