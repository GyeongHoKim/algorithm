#include<stdio.h>
int main(){
  int c;
  scanf("%d",&c);
  while(c--){
    int n,i,sum=0,avg=0,count=0;
    double percent;
    int score[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&score[i]);
      sum += score[i];
    }

    avg = sum/n;

   for(i=0;i<n;i++){
      if(score[i]>avg){
        count += 1;
        }
    }
  
    percent = count/(double)n * 100;
    printf("%.3lf%%\n",percent);
  }

}