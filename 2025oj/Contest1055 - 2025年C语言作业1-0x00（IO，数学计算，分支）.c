#include <stdio.h>
#include <math.h>
#define M_IP 3.14159265
//问题 A: if3
//int main(){
//	int n;
//	scanf("%d",&n);
//	int a=n%10,b=n/10%10,c=n/100;
//	if(a==b&&a!=c&&b!=c){
//		printf("Yes");
//	}else if(a!=b&&a==c&&b!=c){
//		printf("Yes");		
//	}else if(a!=b&&a!=c&&b==c){
//		printf("Yes");			
//	}else{
//		printf("No");
//	}
//	return 0;
//} 

//问题 B: if4
//int main(){
//	double a=0,b=0,c=0;
//	scanf("%lf %lf %lf",&a,&b,&c);
//	
//	if(a+b>c&&a+c>b&&b+c>a){
//		double d=(a+b+c)/2;
//		double s=sqrt(d*(d-a)*(d-b)*(d-c));
//		printf("%.2f\n",s);
//	}else{
//		printf("Not a triangle.");
//	}
//	return 0;
//}

//问题 C: switch
//int main(){
//	double n=0;
//	scanf("%lf",&n);
//	if(n>=0&&n<10){
//		double y=cos(n+3.0);
//		printf("%.5lf",y);
//	}else if(n>=10&&n<20){
//		double y=pow(cos(n+7.5),2);
//		printf("%.5lf",y);
//	}else if(n>=20&&n<30){
//		double y=pow(cos(n+4.0),4);
//		printf("%.5lf",y);
//	}else{
//		printf("Not define");
//	}
//} 

//问题 D: 最大最小数
//void swap(int *x, int *y) {
//    int temp = *x;
//    *x = *y;
//    *y = temp;
//}
//void sort(int a[],int size){
//	for(int i=0;i<size;i++){
//		for(int j=i+1;j<size;j++){
//			if(a[i]>a[j])
//				swap(&a[i],&a[j]);
//		}
//	}
//}
//int main(){
//	int a[3];
//	scanf("%d %d %d",&a[0],&a[1],&a[2]);
//	sort(a,3);
//	printf("%d %d",a[2],a[0]);
//	return 0;
//}

//问题 E: 输入输出1
//int main(){
//	int a=0;
//	scanf("%d",&a);
//	printf("%d,%X",a,a);
//}

//问题 F: io4
//int main(){
//	double a=0;
//	scanf("%lf",&a);
//	printf("%.8lf",a);
//}

//问题 G: io5
//int main(){
//	char a='a';
//	scanf("%c",&a);
//	printf("The ASCII of '%c' is %d.",a,a);
//}

//问题 H: 三角形的另一边
//int main(){
//	double a,b,c;
//	scanf("%lf %lf %lf",&a,&b,&c);
//	double d=c*M_IP/180;
//	printf("%g",sqrt(a*a+b*b-2*a*b*cos(d)));
//}

//问题 I: 求两点间的距离
//int main(){
//	double xa,ya,xb,yb;
//	scanf("%lf %lf %lf %lf",&xa,&ya,&xb,&yb);
//	printf("%g",sqrt(pow(xa-xb,2)+pow(ya-yb,2)));
//}

//问题 J: 三角形面积
//int main(){
//	int n=0;
//	double b=0,h=0;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++){
//		scanf("%lf %lf",&b,&h);
//		printf("%.1lf\n",b*h/2);
//	}
//}
