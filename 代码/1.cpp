#include <cstdio>
#include <iostream>
#include <cstring>
#include <conio.h>
#include <windows.h>
using namespace std;
#define N 8
#define M 50

int map[N][M];
struct SNAKE
{
	int x,y;
	int len;
}snake;

int tr(int f[N])
{
	int num=0;
	for (int i=0;i<N;i++) num+=f[i]*(1<<(7-i));
	return num;
}

void up(){snake.x<=0?0:snake.x--;}
void down(){snake.x>=N-1?0:snake.x++;}
void left(){snake.y=(snake.y==0?M-1:(snake.y)-1);}
void right(){snake.y=(snake.y==M-1?0:(snake.y)+1);}

void draw()
{
	memset(map,0,sizeof(map));
	for (int i=0;i<snake.len;i++) map[snake.x][(snake.y+i)%M]=1;
}

void print()
{
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<M;j++) cout<<(map[i][j]?'$':'.');
		printf("\n");
	}
}

int main()
{
	snake.x=snake.y=0;
	snake.len=10;
	char key;
	draw();
	print();
	while (1)
	{
		key=getch();
		system("cls");
		switch (key)
		{
			case 'w':
				up();
				break;
			case 's':
				down();
				break;
			case 'a':
				left();
				break;
			case 'd':
				right();
				break;
		}
		draw();
		print();
	}
	
	return 0;
}
