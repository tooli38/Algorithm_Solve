#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, ans;

int main(){
	scanf("%d %d", &n, &m);
	
	if(n == 1 || m == 1) {
		printf("0");	
		return 0; //���� �ϳ��� 1�̸� ���� �� ����. 
	}
	
	if(n>m) {//���� ���߱�. 
		int temp = n; 
		n = m;
		m = temp;
	}
	
	int t1 = 0;//t1�� 2*2, 3*3ũ��. 
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
	int t5 = 0; //����ġ. 
	if(n%2 == 0)//¦���� ���. 
		for(int i = n+1; i<=m; i++){
			if(i%2 == 1)//Ȧ���� ���. 
				for(int j = 2; j<=n; j++){//�ش��ϴ� ����ġ ����. 
					t5 = t5+2*(n-j+1); 
			}
			t3 = t3+t5;
		}
	
	if(n%2 == 1)//Ȧ���� ���. �̹� �߰��Ǿ��ִ� ��Ȳ�̹Ƿ�, 2�� ���Ѱź��� ����.
	  	for(int i = n+2; i<=m; i++){
	  		if(i%2 == 1)//Ȧ���� ���. 
				for(int j = 2; j<=n; j++){//�ش��ϴ� ����ġ ����. 
					t5 = t5+2*(n-j+1); 
			}
			t3 = t3+t5;
		}	
	  
	//���ǿ� �����ϸ� ���� ū �̵�ﰢ���� 2���� ���´�.
	
	ans = (t1+t4) * (m-n+1) + t3; 
	
	printf("%d", ans);
}
