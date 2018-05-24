#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
#define maxn 101
using namespace std;
struct block{
    bool been;
    bool tow[4];
}maze[maxn][maxn];
char print[303][303];
bool make_sure(int x,int y){
    return ~(maze[x][y+1].been|maze[x][y-1].been|maze[x+1][y].been|maze[x-1][y].been);
}
void sub_make(int x,int y,int n){
    maze[x][y].been=true;
    if(!make_sure(x,y)) return ;
    else{
        srand(time(0));
        int start=rand()%4;
        int ss=start;
        do{
            switch (ss){
                case 0:{
                        if(!maze[x][y+1].been){
                            maze[x][y+1].tow[0]=true;
                            sub_make(x,y+1,n);
                        }
                    }
                    break;
                case 1:{
                        if(!maze[x][y-1].been){
                            maze[x][y-1].tow[1]=true;
                            sub_make(x,y-1,n);
                        }
                    }
                    break;
                case 2:{
                        if(!maze[x-1][y].been){
                            maze[x-1][y].tow[2]=true;
                            sub_make(x-1,y,n);
                        }
                    }
                    break;
                case 3:{
                        if(!maze[x+1][y].been){
                            maze[x+1][y].tow[3]=true;
                            sub_make(x+1,y,n);
                        }
                    }
                    break;
                default:
                    break;
            }
            ss++;
            if(ss==4) ss=0;
        }while(ss!=start);
    }
    return ;
}
void build_maze(int n){
    for(int i=0;i<=n+1;i++){
        maze[i][0].been=true;
        maze[0][i].been=true;
        maze[i][n+1].been=true;
        maze[n+1][i].been=true;
    }
    int start_x,start_y;
    srand(time(0));
    start_x=rand()%n+1;
    start_y=rand()%n+1;
    sub_make(start_x,start_y,n);
    return ;
}
void trans2print(int n){
    for(int i=1,j=1;i<=n;i++,j+=3){
        for(int p=1,q=1;p<=n;p++,q+=3){
            print[j+1][q+1]='#';
            print[j+1][q-1]='#';
            print[j-1][q+1]='#';
            print[j-1][q-1]='#';
            if(!maze[i][p].tow[0]) print[j-1][q]='#';
            if(!maze[i][p].tow[1]) print[j+1][q]='#';
            if(!maze[i][p].tow[2]) print[j][q-1]='#';
            if(!maze[i][p].tow[3]) print[j][q+1]='#';
        }
    }
    return ;
}
int main(){
    int n;
    scanf("%d",&n);
    build_maze(n);
    trans2print(n);
    for(int i=0;i<=3*n+1;i++){
        for(int j=0;j<=3*n+1;j++){
            printf("%c",print[i][j]);
        }
        printf("\n");
    }
    return 0;
}
