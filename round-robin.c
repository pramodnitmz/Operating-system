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
void merge(struct process p[], int l, int m, int r) 
{ 
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
     struct process L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = p[l + i];
    for (j = 0; j < n2; j++)
        R[j] = p[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i].at <= R[j].at)
        {
            p[k] = L[i];
            i++;
        }
        else
        {
            p[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        p[k]= L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        p[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(struct process p[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        merge_sort(p, l, m);
        merge_sort(p, m+1, r);

        merge(p, l, m, r);
    }
}
int main(int argc ,char *argv[])
{   
   int i,j,count,time,quantum,remain, flag=0;
   double awt=0, atat=0;
   FILE  *fp=fopen(argv[1],"r");
   int c=0;

  while(fscanf(fp,"%d,%d,%d",&p[c].pid,&p[c].at,&p[c].bt)!=EOF)
  {  
  	p[c].rem=p[c].bt;
  	c++;
  }
  merge_sort(p, 0, c-1);// sorting acording to arrival time
  printf("enter time quantum");
  scanf("%d",&quantum);
   remain=c;
  for (time=0,count=0; remain!=0;)
  { 
    if (p[count].rem <= quantum && p[count].rem>0)
    {
      time+=p[count].rem;
      p[count].rem=0;
      flag=1;
    }
    else if(p[count].rem>0)
    {
      p[count].rem-=quantum;
      time+=quantum;
    }
    if(p[count].rem==0 && flag==1)
    {
      remain--;
      p[count].complete=time;
  
      flag=0;
    }
    if (count==c)
      count=0;
    else if (p[count+1].at<=time)
      count++;
    else
      count=0;
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