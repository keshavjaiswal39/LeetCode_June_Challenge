#include<iostream>
using namespace std;


// W,N,E,S
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int R;
int C;

void printMat(char input[][50]){

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout<<input[i][j];
		}
		cout<<endl;
	}

}

// ch is character to be replaced
// color is the character to be added

void floodfill(char mat[][50],int i,int j,char ch,char color)
{
	// base case - matrix bounds
	if(i<0 || j<0 || i>=R || j>=C)
	{
		return;
	}
	
	// figure boundary condition
	if(mat[i][j]!=ch)
	{
		return;
	}
	
	// recursive case
	mat[i][j]=color;
	
	for(int k=0;k<4;k++)
	{
		floodfill(mat,i+dx[k],i+dy[k],ch,color);
	}
	
}


int main()
{
	cin>>R>>C;
	
	char input[15][50];
	
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cin>>input[i][j];
		}
	}
	
	printMat(input);
	cout<<endl;
	
	floodfill(input,1,2,'.','r');
	
	cout<<endl;
	
	floodfill(input,0,0,'.','!');
	
	return 0;
}




