#include<stdio.h> 
 
int main() 
{ 
      int i, l, total=0, x, count = 0, quantum; 
      int wtime = 0, tat = 0, atime[10], btime[10], k[10]; 
      float avgwtime, avgtat;
      printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &l); 
      x = l; 
      for(i=0; i < l; i++) 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &atime[i]);
            printf("Burst Time:\t");
            scanf("%d", &btime[i]); 
            k[i]=btime[i];
      } 

  if(l>=1)
  {
    quantum=3;
  }
  else
  {
    quantum=3;
  }
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i=0; x != 0;) 
      { 
            if(k[i] <= quantum && k[i] > 0) 
            { 
                  total = total + k[i]; 
                  k[i] = 0; 
                  count = 1; 
            } 
            else if(k[i] > 0) 
            { 
                  k[i] = k[i] - quantum; 
                  total = total + quantum; 
            } 
            if(k[i] == 0 && count == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, btime[i], total - atime[i], total - atime[i] - btime[i]);
                  wtime = wtime + total - atime[i] - btime[i]; 
                  tat = tat + total - atime[i]; 
                  count = 0; 
            } 
            if(i == l - 1) 
            {
                  i = 0; 
            }
            else if(atime[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      avgwtime = wtime * 1.0 / l;
      avgtat = tat * 1.0 / l;
      printf("\n\nAverage Waiting Time:\t%f", avgwtime); 
      printf("\nAvg Turnaround Time:\t%f\n", avgtat); 
      return 0; 
}
