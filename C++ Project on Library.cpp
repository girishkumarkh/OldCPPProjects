#include
#include
#include
#include
#include
#include
#include
#include
#include
class lib
{
public:
char name[20];
int clas,rollno;
void get()
{cout<<"*******enter the details of the student:"<<<"enter the name:"<<<"enter the class:"<>clas;
cout<<"enter the rollno:"<>rollno;
}
void show()
{
cout<<"********DETAILS ADDED ARE***********:"<<<<<<<<<"enter your choice:"<<<"1   TO ADD:"<<<"2 TO SHOW:"<<<"3 TO SEARCH:"<<<"4 TO MODIFY:"<<<"5 TO DELETE:"<<<"6 TO EXIT:"<>x;
switch(x)
{
case 1:
{
 char ch='y';
lib s;
fstream t;
t.open("navi_arora.txt",ios::binary|ios::out|ios::app|ios::in);
while(ch=='y'||ch=='Y')
{
s.get();
t.write((char*)&s,sizeof(lib));
cout<<"do you want to add more(y/n)....:"<>ch;
}
}

case 2:
{
lib s;
fstream t;
t.open("navi_arora.txt",ios::binary|ios::out|ios::app|ios::in);
t.seekg(0);
while(t.read((char*)&s,sizeof(lib)))
{
s.show();
}
}
break;
case 3:
{ int a[20];
lib s;
fstream t;
t.open("navi_arora.txt",ios::binary|ios::out,ios::app|ios::in);
t.seekg(0);
cout<<"enter the name you want to search:"<>a[i];
while(t.read((char*)&s,sizeof(lib)))
{

s.show();
}
cout<<"name not found:";
}
}
}
}
