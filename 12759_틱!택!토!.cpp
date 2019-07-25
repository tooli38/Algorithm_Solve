#include <cstdio>
#include <algorithm>

using namespace std;

int dp[3][7];//1은 1행, 2는 2행, 3은 3행, 4는 1열, 5는 2열, 6은 3열. 
int sm;
int x, y;
void vingo(int a, int b, int c)//a는 플레이어, b는 행, c는 열 
{
	dp[a][b]++;
	dp[a][c+3]++; 
}

int main(){
	int n;
	scanf("%d", &n);//시작 플레이어 입력.
	
	for(int i = 0; i<9; i++){//최대칸이 9칸이므로 최대 9번만 그릴 수 있다. 
		
		scanf("%d %d", &x, &y);//위치 입력.
		vingo(n,x,y); 
		
		if(dp[n][x] == 3 || dp[n][y+3] == 3)
		{
			printf("%d",n);
			return 0;
		}
		
		if(n == 1) n = 2;
		else n = 1;
	}
	printf("0");
	 
}
