#include
#include
#include
#include
#include
#include 

#define ESC 27
#define UPARR 72
#define LEFTARR 75
#define DOWNARR 80
#define RIGHTARR 77
#define SAVE 60
#define LOAD 61 

main()
{
void starting(void);
void make_xy(char **,char **);
void getrand(char *,char *,char *,char *,char *,int,char);
char getkey(char,char);
void savegame(char *,char *,int,char);
int loadgame(char *,char *,char *);
void win_message(void); 

char *x,*y,pos_x,pos_y,num,out=0,old_ch=0,ch=0,new_ch,new_x,new_y,old_num=0;
int i,length=6; 

starting();
make_xy(&x,&y);
getrand(&pos_x,&pos_y,&num,x,y,length,ch); 

while(!out){
if((new_ch=getkey(old_ch,ch))==ESC)
out=2;
if(out)
break;
if(new_ch==SAVE)
savegame(x,y,length,old_ch);
else if(new_ch==LOAD){
length=loadgame(x,y,&ch);
getrand(&pos_x,&pos_y,&num,x,y,length,ch);
}
else
ch=new_ch;
new_x=x[0];
new_y=y[0];
if(ch==UPARR)
new_y=y[0]-1;
else if(ch==LEFTARR)
new_x=x[0]-1;
else if(ch==DOWNARR)
new_y=y[0]+1;
else if(ch==RIGHTARR)
new_x=x[0]+1;
old_ch=ch;
if((new_x<2)|(new_y<2)|(new_x>79)|(new_y>22))
out=1; /* HIGHEST POSSIBLE SCORE ї (78*21-6)*5 = 8160 ї 10,000 */
for(i=1;i0;i--){
x[i]=x[i-1];
y[i]=y[i-1];
if(i==1){
gotoxy(x[i],y[i]);
putchar('л');
}
}
x[0]=new_x;
y[0]=new_y;
gotoxy(x[0],y[0]);
printf("\b"); /* USE THE FUNCTION _setcursortype() */
if(out)
break;
delay(99);
}
if(out==1){
gotoxy(1,24);
printf("The snake collided with the wall or with itself!\n"
"GAME OVER!!\t\t(Press 'q' to terminate...)");
gotoxy(x[0],y[0]);
while(toupper(getch())!='Q');
}
clrscr();
printf("Hope you enjoyed the game\n\n\t\tBye!\n");
return 0;
} 

/*-------------------------------------------------------------------------*/ 

void starting()
{
char i; 

clrscr(); /* FIRST TO DRAW A BOUNDARY for THE GAME */
putchar('Щ');
for(i=0;i<78;i++)
putchar('Э');
putchar('Л');
gotoxy(1,23);
putchar('Ш');
for(i=0;i<78;i++)
putchar('Э');
putchar('М');
window(1,2,1,23);
for(i=0;i<21;i++)
cprintf("К");
window(80,2,80,23);
for(i=0;i<21;i++)
cprintf("К"); /* THE BOUNDARY IS DRAWN */
window(1,1,80,25);
gotoxy(38,12);
printf("ллллл"); /* THE "SNAKE" IS PUT for THE FIRST TIME */
gotoxy(1,24);
printf("Welcome to the game of SNAKE!\n(Press any arrow key to start now,"
" Escape to leave at any time...)"); /* WELCOME MESSAGE */
gotoxy(43,12);
while(!kbhit());
gotoxy(30,24);
delline();delline(); /* REMOVING MESSAGE */
cprintf("\n( EAT THE NUMBER !! ) Score = 0");
gotoxy(43,12); /* GO TO THE HEAD OF THE SNAKE */
} 

void make_xy(char **px,char **py)
{
char i; 

*px=(char *)malloc(1638*sizeof(char)); /*EARLIER IT WAS 6, NOT 1638; BUT*/
*py=(char *)malloc(1638*sizeof(char)); /*realloc IS NOT COPYING PROPERLY*/
for(i=0;i<6;i++){
(*px)[i]=43-i;
(*py)[i]=12;
} /* THE TWO ARRAYS for COORDINATES OF THE SNAKE ARE SIMULATED */
} 

void getrand(char *px,char *py,char *pn,char *x,char *y,int length,char ch)
{
int allowed=0,i; /* i AND length MUST BE int */ 

while(!allowed){
allowed=1;
srand((unsigned)time(0));
*px=rand()%78+2; /* GENERATING RANDOM POSITIONAL COORDINATES for */
srand((unsigned)time(0));
*py=rand()%21+2; /* PUTTING A RANDOM NUMBER */
if(ch==UPARR){
if((*px==x[0])&(*py==y[0]-1))
allowed=0;
}
else if(ch==DOWNARR){
if((*px==x[0])&(*py==y[0]+1))
allowed=0;
}
else if(ch==LEFTARR){
if((*px==x[0]-1)&(*py==y[0]))
allowed=0;
}
else if((ch==RIGHTARR)&(*px==x[0]+1)&(*py==y[0]))
allowed=0;
for(i=0;(i