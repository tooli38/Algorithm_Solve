#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, ans;

int main(){
	scanf("%d %d", &n, &m);
	
	if(n == 1 || m == 1) {
		printf("0");	
		return 0; //둘중 하나가 1이면 만들 수 없음. 
	}
	
	if(n>m) {//순서 맞추기. 
		int temp = n; 
		n = m;
		m = temp;
	}
	
	int t1 = 0;//t1은 2*2, 3*3크기. 
	for(int i = 2; i<=n; i++){
		if(i-1>=0)
			t1 = t1 + 4 * (i-1) * (i-1);
	}
	
	int t4 = 0;
	for(int i = 3; i<=n; i=i+2){
		for(int j = 2; j<=n; j++){
			t4 = t4 + 4 * (n-i+1) * (n-j+1);
		}
	}
	
	int t3 = 0;
	int t5 = 0; //가중치. 
	if(n%2 == 0)//짝수일 경우. 
		for(int i = n+1; i<=m; i++){
			if(i%2 == 1)//홀수일 경우. 
				for(int j = 2; j<=n; j++){//해당하는 가중치 증가. 
					t5 = t5+2*(n-j+1); 
			}
			t3 = t3+t5;
		}
	
	if(n%2 == 1)//홀수일 경우. 이미 추가되어있는 상황이므로, 2를 더한거부터 시작.
	  	for(int i = n+2; i<=m; i++){
	  		if(i%2 == 1)//홀수일 경우. 
				for(int j = 2; j<=n; j++){//해당하는 가중치 증가. 
					t5 = t5+2*(n-j+1); 
			}
			t3 = t3+t5;
		}	
	  
	//조건에 충족하면 가장 큰 이등변삼각형은 2개만 나온다.
	
	ans = (t1+t4) * (m-n+1) + t3; 
	
	printf("%d", ans);
}
