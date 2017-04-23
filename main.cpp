#include<graphics.h>
#include<bits/stdc++.h>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<windows.h>
#define NO_OF_CHARS 256

using namespace std;
int counter=0;
int pk=0;

void prefix(char* p,int m,int *a){


 a[1]=0;
 int k=0;
  for(int q=1; q<m;q++)
  {
     while(k>0&&p[k]!=p[q])
	 {
        k=a[k];
     }
     if(p[k]==p[q])
        {
            k=k+1;
        }
    a[q+1]=k;
  }

}

void kmp(char* t,char* p){

 int m=strlen(p);
int n=strlen(t);
 int *a=(int *)malloc(sizeof(int)*m);
 prefix(p,m,a);
int q=0;
 for(int i=0;i<n;i++)
    {
       while (q>0 and p[q]!=t[i])
    {
    q=a[q];
    }

    if(p[q]==t[i])
        {
            q=q+1;
    }
    if(q==m)
        {
         counter++;
        q=a[q];
    }
 }

}


//fsa

int getNextState(char *pat, int M, int state, int x)
{
    if (state < M && x == pat[state])
        return state+1;

    int ns, i;
    for (ns = state; ns > 0; ns--)
    {
        if(pat[ns-1] == x)
        {
            for(i = 0; i < ns-1; i++)
            {
                if (pat[i] != pat[state-ns+1+i])
                    break;
            }
            if (i == ns-1)
                return ns;
        }
    }

    return 0;
}


void computeTF(char *pat, int M, int TF[][NO_OF_CHARS])
{
    int state, x;
    for (state = 0; state <= M; ++state)
        for (x = 0; x < NO_OF_CHARS; ++x)
           TF[state][x] = getNextState(pat, M,  state, x);
}

void search(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int TF[M+1][NO_OF_CHARS];

    computeTF(pat, M, TF);


    int i, state=0;
    for (i = 0; i < N; i++)
    {
       state = TF[state][txt[i]];
       if (state == M)
       {
         counter++;
       }
    }
}

// boyer moore

int max(int a, int b)
{

    if(a>b)
        return a;
    else
        return b;

}


void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS])
{
    int i;


    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}


void searchbm(char *txt, char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
           counter++;

            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;



            }



        else
            s += max(1, j - badchar[txt[s + j]]);

    }

}

void code()
{
cleardevice();
setcolor(4);
outtextxy(220,30,"VIRUS-DETECTED !");
setcolor(0);
int xaxis=10,yaxis=100;
char buf[1000];
for(int loop=1;loop<=60;loop++)
{
    //cleardevice();
 string c;
 FILE *fp;
 string a="G:\\devc++\\PSAP\\" ;
 string b=".txt";
	stringstream ss;
	ss<<loop;
 string i=ss.str();
  a.append(i);
  c.append(a);
  c.append(b);

char  t[100000];
int j,fu;
j=0;
  char * cstr = new char [c.length()+1];
  strcpy (cstr, c.c_str());

  fp=fopen(cstr,"r");
   if (fp== NULL)
    {
    settextstyle(1,0,2);
   cout<<"Dont Work";
   outtextxy(xaxis,yaxis,"Dont Work");
   yaxis+=30;
   }
        while (feof(fp) == 0)
        {
               t[j]=getc(fp);
           j++;
                }
                t[j-1]='\0';
  //cout<<t<<"\n";

  int ctr=0;

for(int loop1=1;loop1<=7;loop1++)
{
  string v;
  	stringstream ss1;
	ss1<<loop1;
	string s2=ss1.str();
  string i1="virus";
  i1.append(s2);
  string a1="G:\\devc++\\VirusDefinitions\\" ;
 string b1=".txt";
  a1.append(i1);
  v.append(a1);
  v.append(b1);
  char p[1000][1000];
  j=0;
  char q;
  int temp;
  int def=0;
  char * cstr1 = new char [v.length()+1];
  strcpy (cstr1, v.c_str());
  fp=fopen(cstr1,"r");
  while(feof(fp)==0)
    {
        j=0;
        if (fp== NULL)
		{
		    settextstyle(1,0,2);
			cout<<"Dont Work";
			outtextxy(xaxis,yaxis,"Dont Work");
			yaxis+=30;
			}
        while(!feof(fp))
        {
            q=getc(fp);
            if(q!='\n')
            {
                p[def][j]=q;
                j++;
            }
            else
                break;
        }

                p[def][j]='\0';def++;

              }
                p[def-1][j-1]='\0';
	int yo=0;
	string fa=p[0];
	if(fa.compare("kmp")==0)
	{
	for(int pat=1;pat<def;pat++)
	{
	counter=0;
	kmp(t,p[pat]);/*cout<<" " ;*/
	if(counter>1)
	{
	    counter=1;
	    }

		  if(counter==1)
		  {
		      yo++;
		      }
  	 }
	}


  	else if(fa.compare("fsa")==0)
  	{
	for(int pat=1;pat<def;pat++)
	{
	counter=0;
     search(p[pat],t);    /*cout<<" " ;*/
	if(counter>1)
	{
	    counter=1;
	    }

		  if(counter==1)
		  {
		      yo++;
		      }
  	 }
	}

	else if(fa.compare("bm")==0)
  	{
	for(int pat=1;pat<def;pat++)
	{
	counter=0;
     searchbm(t,p[pat]);    /*cout<<" " ;*/

	if(counter>1)
	{
	    counter=1;
	    }

		  if(counter==1)
		  {
		      yo++;
		      }
  	 }
	}


	if(yo>=def-1)
	{
		cout<<"virus "<<loop1<<" in file "<<loop<<".txt\n";
		settextstyle(1,0,1);
		sprintf( buf, "virus %d in file %d.txt", loop1 ,loop);
        outtextxy(xaxis, yaxis, buf );
        free(buf);
        yaxis+=30;
		ctr++;

		}
	}

	if(ctr==0)
	{
	    cout<<"no virus in file "<<loop<<".txt\n";
	 settextstyle(1,0,1);
     sprintf( buf, "no virus in file %d.txt",loop);
        outtextxy(xaxis, yaxis, buf );
        free(buf);
        yaxis+=30;
}

if(yaxis==550)
   {
       pk++;
       if(pk==1)
       {
           xaxis=270;
       yaxis=100;
       }
       if(pk==2)
       {
           xaxis=550;
           yaxis=100;
       }
       if(pk==3)
       {
           xaxis=890;
           yaxis=100;
       }
       if(pk==4)
       {
           xaxis=1150;
           yaxis=100;
       }

   }


    for(int lop=0;lop<100000;lop++)
    {
        t[lop]='\0';
    }

}


}


void scan()
{

    int c=0;
    readimagefile("main.bmp",0,0,1000,610);
    setbkcolor(15);
    setcolor(0);
    settextstyle(1,0,5);
    outtextxy(260,30,"SCANNING");
    int i,j;

    while(c!=1)
    {
        i=300,j=100;
        for(i=300;i<=600;i+=20)
    {
        readimagefile("glass.bmp",i,j,i+200,j+200);
        delay(40);
        readimagefile("main.bmp",0,0,1000,610);
    setcolor(0);
        settextstyle(1,0,5);
        outtextxy(260,30,"SCANNING.");
    }
    for(j=100;j<=300;j+=20)
    {
        readimagefile("glass.bmp",i,j,i+200,j+200);
        delay(40);
        readimagefile("main.bmp",0,0,1000,610);
    setcolor(0);
        settextstyle(1,0,5);
        outtextxy(260,30,"SCANNING..");
    }
    for(i=800;i>=500;i-=20)
    {
        readimagefile("glass.bmp",i-200,j,i,j+200);
        delay(40);
        readimagefile("main.bmp",0,0,1000,610);
        setbkcolor(15);
    setcolor(0);
        settextstyle(1,0,5);
        outtextxy(260,30,"SCANNING...");
    }
    for(j=500;j>=300;j-=20)
    {
        readimagefile("glass.bmp",i-200,j-200,i,j);
        delay(40);
        readimagefile("main.bmp",0,0,1000,610);
        setcolor(0);
        settextstyle(1,0,5);
        outtextxy(260,30,"SCANNING");
    }
    c++;
    }

    code();


}



void home()
{

    readimagefile("home.bmp",0,0,1000,610);

     settextstyle(1,0,5);

        outtextxy(280,30,"PRO-ANTIVIRUS");

        readimagefile("logo.bmp",10,10,200,200);

          settextstyle(1,0,4);

          outtextxy(150,400,"  Location : G:\\devc++\\PSAP");

        outtextxy(150,270,"PRESS ENTER TO SCAN VIRUS");
        if(getch()==13)
        {
              scan();
             //   code();

        }
        else
          home();

}


int main()
{

    int gd=0,gm=0;
    initgraph(&gm,&gd,"");
    initwindow(1500,610);
    home();

    getch();

    return 0;

}
