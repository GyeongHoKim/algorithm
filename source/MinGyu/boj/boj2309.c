#include <stdio.h>

#define ARR_LEN 9

void view_arr(int arr[]){
   for(int j=2;j<ARR_LEN;j++){
     printf("%d \n",arr[j]);
   } 
}

int* pick_seven(int arr[],int sum)
{
  int twoSum;
  for(int i=0;i<ARR_LEN;i++){
    for(int j=i+1;j<ARR_LEN;j++){
      twoSum = arr[i]+arr[j];
      if(sum-twoSum==100){
        arr[i]=0;
        arr[j]=0;
        return arr;
      }
    }
  }
  return arr;
}

int* sort_arr(int arr[])
{
  int temp;
  for(int i=1;i<ARR_LEN-1;i++){
    for(int j=0;j<ARR_LEN-i;j++){
      if(arr[j]>arr[j+1]){
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
  return arr;
}

int main()
{
  int arr[9];
  int* rArr;
  int sum;
  sum=0;

  for(int i=0;i<ARR_LEN;i++){
    scanf("%d",&arr[i]);
    sum += arr[i];
  }

  rArr = pick_seven(arr,sum);
  rArr = sort_arr(rArr);
  
  view_arr(rArr);

}