#include<stdio.h>
int main()
{
    int nop,t,wt[10],twt,tat[10],ttat,i,j,p[10],b[10],tmp;
    float awt, atat;
    awt=0.0;
    atat=0.0;
    printf("\n\nEnter the number of process: ");
    scanf("%d",&nop);
    for(i=0;i<nop;i++)
    {
        printf("Enter the burst time of  Process %d: ",i+1);
        scanf("%d",&b[i]);
    }
    for(i=0;i<nop;i++)
    {
        printf("Enter the priority number of each Process %d: ",i+1);
        scanf("%d",&p[i]);
    }
    for(i=0;i<nop;i++)
    {
        for(j=i+1;j<nop;j++)
        {
            if(p[i]>p[j])
            {
                t=p[i];
                p[i]=p[j];
                p[j]=t;
                tmp=b[i];
                b[i]=b[j];
                b[j]=tmp;
            }
        }
    }
    wt[0]=0;
    tat[0]=b[0];
    twt=wt[0];
    ttat=tat[0];
    for(i=1;i<nop;i++)
    {
        wt[i]=wt[i-1]+b[i-1];
        tat[i]=wt[i]+b[i];
        twt+=wt[i];
        ttat+=tat[i];
    }
    awt=(float)twt/nop;
    atat=(float)ttat/nop;
    printf("\n\nProcess No:\tPriority:\tBurst Time:\tWaiting Time\tTurnaround Time:\n");
    for(i=0;i<nop;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i+1, p[i], b[i], wt[i], tat[i]);
    }
    printf("\n\nTotal Turn Around Time: %d",ttat);
    printf("\nTotal Waiting Time: %d",twt);
    printf("\nAverage Waiting Time: %f",awt);
    printf("\nAverage Turn Around Time: %f",atat);
    return 0;
}
