#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct process
{
	int pid;
	int at;
	int bt;
	int ct;
};
// for sorting according to arrival time
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

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
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
    int i,j;
    struct process  p[10];
    int tat[10]; int wt[10];
    double awt=0, atat=0;
  FILE  *fp=fopen(argv[1],"r");
  int c=0;
  if(fp!=NULL){
  while(fscanf(fp,"%d,%d,%d",&p[c].pid,&p[c].at,&p[c].bt)!=EOF)
  { 
  	c++;
  }
 merge_sort(p, 0, c-1);// sorting acording to arrival time
 p[0].ct=p[0].at+p[0].bt;
 	tat[0]=p[0].ct-p[0].at;
 	wt[0]=tat[0]-p[0].bt;
  for(i=1;i<c;i++)
  { 
 	p[i].ct=p[i-1].ct+p[i].bt;
 	tat[i]=p[i].ct-p[i].at;
 	wt[i]=tat[i]-p[i].bt;
   }
   for(i=0;i<c;i++)
   {
     printf("turn around time of process %d = %d\n",p[i].pid,tat[i]);
     printf(" wait time of process %d=%d\n",p[i].pid,wt[i]);
     awt=awt+ wt[i];
     atat= atat+tat[i];
    }
    printf(" average wait time =%f\n",awt/c);
    printf(" averagwe turn around time =%f",atat/c);
    fclose(fp);
     return 0;
    }
}
