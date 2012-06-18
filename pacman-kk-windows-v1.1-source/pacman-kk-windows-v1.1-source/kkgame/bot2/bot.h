#include<cstdio>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<unistd.h>
char map_state[100][100];

int map_row,map_col,s1,s2;
void read_state();
int move_pacman(void);
int move_ghost(int N);
int randnum;
struct loc
{	int r;
	int c;
};
struct loc pac1,pac2,ghosts1[4],ghosts2[4];

void read_state()
{
	int i,j;	
	int p_set_flag=0;
	scanf("%d",&map_row);
	scanf("%d",&map_col);
	
	for(i=0;i<map_row;i++)
	{	
		for(j=0;j<map_col;j++)
		{
			scanf("%c ",&map_state[i][j]); 
			randnum += (i*j*map_state[i][j])/2;
			switch (map_state[i][j])
			{
				case 'P' : 
					pac1.r=i;pac1.c=j;
					if(p_set_flag==0)
					{					
						pac2.r=i;pac2.c=j;
					}
				break;
				case 'p' :
					pac2.r=i;pac2.c=j;
					p_set_flag=1;
				break;

				case 'A' :
				case 'B' :
				case 'C' :
				case 'D' :
					ghosts1[map_state[i][j]-'A'].r=i;
					ghosts1[map_state[i][j]-'A'].c=j;
				break;

				case 'a' :
				case 'b' :
				case 'c' :
				case 'd' :
					ghosts2[map_state[i][j]-'a'].r=i;
					ghosts2[map_state[i][j]-'a'].c=j;
				break;				
			}
		}
	}
	scanf("%d",&s1);
	scanf("%d",&s2);
	srand(time(NULL));
}


