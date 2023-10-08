// Dijkstra C Program 

#include <stdio.h>
#define infinity 999

void dij(int n,int v,int cost[10][10],int dist[])
{
 int i,u,count,w,flag[10],min;
 for(i=1;i<=n;i++)
  flag[i]=0,dist[i]=cost[v][i];
 count=2;
 while(count<=n)
 {
  min=99;
  for(w=1;w<=n;w++)
   if(dist[w]<min && !flag[w])
    min=dist[w],u=w;
  flag[u]=1;
  count++;
  for(w=1;w<=n;w++)
   if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
    dist[w]=dist[u]+cost[u][w];
 }
}

void main()
{
 int n,v,i,j,cost[10][10],dist[10];
 int count=0;
 printf("\nEnter the number of nodes: ");
 scanf("%d",&n);
 printf("\nEnter the cost matrix:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
     count++;
   scanf("%d",&cost[i][j]);
   if(cost[i][j]==0)
    cost[i][j]=infinity;
  }
 printf("\nEnter the source: ");
 scanf("%d",&v);
 dij(n,v,cost,dist);
 printf("\nPath -> Costs:\n");
 printf("1->0\n");
 for(i=1;i<=n;i++)
 {
  if(i!=v){
   printf("%d->%d\n",i,dist[i]);
    }
 }
    printf("Time Complexity=%d\n",count);
}


/*OUTPUT
Enter the number of nodes: 6
Enter the cost matrix:
0 7 0 0 0 3
7 0 4 0 0 2
0 4 0 8 5 5
0 0 8 0 3 0
0 0 5 3 0 6
3 2 3 0 6 0
Enter the source: 1
Path -> Costs:
1->0
2->5
3->6
4->12
5->9
6->3
Time Complexity=36
 */
