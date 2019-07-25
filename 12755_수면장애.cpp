#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int start=0, finish=9;
int lv, N; //자리수, 위치. 

char len(int x, int y){
	char buf[20];
	sprintf(buf,"%lld", x);
	return buf[y];
} 

int main(){
 scanf("%d", &N);
 
 for(lv = 1; ; lv++){//자리수 찾기.
  if(start<N && N<=finish) break;//자리수 찾으면 반환.
  start = finish;//아니면 처음위치 늘리고.
  finish = (lv+1)*(pow(10,lv+1)-pow(10,lv))+finish;
 }
 
 int idx = N - start ;//그 자리수만 생각할때 위치.(-1이유는 나누어지면 다음수로 넘어가기 때문.) 
 int lev = pow(10,lv-1);
 printf("%c", len(lev+(idx/lv), idx%lv));
 
 
}
 
