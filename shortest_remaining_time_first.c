#include <stdio.h>
#include <stdlib.h>

FILE *fp;

struct process {
    int pid;    
    int at;     
    int bt;     
    int complete;   
    int tat;    
    int wt;
    int rem;
};
struct process p[10];
// for sorting according to arrival time

int main(int argc ,char *argv[])
{   
   int i,j,count=0,time,smallest;
   double awt=0, atat=0;
   FILE  *fp=fopen(argv[1],"r");
   int c=0;

  while(fscanf(fp,"%d,%d,%d",&p[c].pid,&p[c].at,&p[c].bt)!=EOF)
  {  
  	p[c].rem=p[c].bt;
  	c++;
  }
  p[9].rem=9999;
  for(time=0;count!=c;time++)
  {
    smallest=9;
    for(i=0;i<c;i++)
    {
      if (p[i].at<=time && p[i].rem<p[smallest].rem && p[i].rem>0)
      {
        smallest=i;
      }
    }
      p[smallest].rem--;

      if (p[smallest].rem==0)
      {
        count++;
        p[smallest].complete=time+1;
      }
    }
  for( int i=0;i<c;i++)
  {
    p[i].tat=p[i].complete-p[i].at;
    p[i].wt=p[i].tat-p[i].bt;
    awt=awt+p[i].wt;
    atat=atat+p[i].tat;
  }
  printf("pid\tat\tbt\tct\ttat\twt\n");
  for( int i=0;i<c;i++)
  {
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].complete, p[i].tat,p[i].wt);
  }
  printf("average turnaround time=%f\n",atat/c );
  printf("average waiting time=%f\n",awt/c);
} 