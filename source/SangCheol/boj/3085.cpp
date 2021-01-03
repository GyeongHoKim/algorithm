#include<iostream>
using namespace std;

void get_color(char* p,int n);

bool change_down(char* p,int x, int y);
bool change_right(char* p,int x, int y);

int count_col(char *p,int x,int n);
int count_row(char *p,int y,int n);
int count_all(char *p,int n);

int change_down_count(int *p,max);
int change_right_count(int *p,max);
	
char board[50][50];

int n;
int M=1;

int main(){
	cin>>n;
	get_color(board,n);
	M=count_all(board,n);
	M=change_right_count(board,M);
	M=change_down_count(board,M);
	cout<<M;
}

int change_down_count(int *p,max){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(change_down(board,i,j)){
				int m1=count_col(board,i,n);
				int m2=count_row(board,j,n);
				int m3=count_row(board,j+1,n);
				max=Max(m1,m2,m3,M);
			}
		}
	}
	return max;
}

int change_right_count(int *p,max){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n;j++){
			if(change_right(board,i,j)){
				int m1=count_row(board,i,n);
				int m2=count_col(board,j,n);
				int m3=count_col(board,j+1,n);
				max=Max(m1,m2,m3,M);
			}
		}
	}
	return max;
}

void get_color(char* p,int n){
	for(int i=0;i<n;i++){
		
	}
}

bool change_down(char* p,int x, int y){
	if(p[y][x]!=p[y][x+1]){
		swap(p[y][x],p[y][x+1]);
		return 1;
	}
	else
		return 0;
}

bool change_right(char* p,int x, int y){
	if(p[y][x]!=p[y+1][x]){
		swap(p[y][x],p[y+1][x+1]);
		return 1;
	}
	else
		return 0;
}

int count_col(char *p,int x,int n){
	int max=1;
	for(int i=0;i<n-1,i++){
		if(p[i][x]==p[i+1][x])
			max++;
		else
			max=1;
	}
	return max;
}

int count_row(char *p,int y,int n){
		int max=1;
	for(int i=0;i<n-1;i++){
		if(p[y][i]==p[i+1][x])
			max++;
		else
			max=1;
	}
	return max;
}

int count_all(char *p,int n){
	int max=1, int temp=0;
	for(int i=0;i<n;i++){
		temp=count_col(p,i,n);
		if(max<temp)
			max=temp;
	}
	for(int i=0;i<n;i++){
		temp=count_row(p,i,n);
		if(max<temp)
			max=temp;
	}
	return max;
}
