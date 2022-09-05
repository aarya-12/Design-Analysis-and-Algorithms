#include<stdio.h>
void swap(int *, int *);
struct Activity 
{ 
    int index;
    int start_time;
    int end_time;
    int duration;
    int overlap;
}; 
int main(){
    int i,j,t;
    int scrum_master;
    int n;   //number of activities
    printf("Enter the number of activities:\n");
    scanf("%d",&n);
    struct Activity a[n];
    for(int i = 0; i < n; i++){
        printf("Enter the start time and end time of activity %d:\n", i);
        a[i].index = i;
        scanf("%d",&a[i].start_time);
        scanf("%d",&a[i].end_time);
        a[i].overlap = 0;
    }
    //calculating the duration of each activity
    for(int i = 0; i < n; i++){
       a[i].duration = a[i].end_time-a[i].start_time;
    }
    //sorting according to duration
    for(i=0; i<(n-1); i++)
    {
    for(j=0; j<(n-i-1); j++)
    {
      if (a[j].duration > a[j+1].duration)
      {
        swap(&a[j].duration,&a[j+1].duration);
        swap(&a[j].index,&a[j+1].index);
        swap(&a[j].start_time,&a[j+1].start_time);
        swap(&a[j].end_time,&a[j+1].end_time);
      }
     }

    }
    printf("\n------------------------------------------------------------------------------------------------------------------\n");
    printf("Sorting the activities according to their duration:\n");
    printf("Index\t\t\tStart Time\t\tEnd Time\t\tDuration\n");
    for(int i = 0; i < n; i++){
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",a[i].index,a[i].start_time,a[i].end_time,a[i].duration);
    }
    //checking for maximum overlap
    
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
      if(a[j].start_time>=a[i].start_time && a[j].end_time<=a[i].end_time){
        a[i].overlap++;
      }
    }
    }
    printf("\n------------------------------------------------------------------------------------------------------------------\n");
    printf("Checking how many activities are overlapping other activities:\n");
    printf("Index\t\t\tStart Time\t\tEnd Time\t\tDuration\t Overlap count\n");
    for(int i = 0; i < n; i++){
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t%d\n",a[i].index,a[i].start_time,a[i].end_time,a[i].duration,a[i].overlap);
    }
    //checking for scrum master
    int max = a[0].overlap;  
    int max2 = a[0].duration;      
    for(int i = 0; i < n; i++){
    if (a[i].overlap > max && a[i].duration > max2){
        max = a[i].overlap;
        max2 = a[i].duration;
        scrum_master = a[i].index;
    }
    }
    printf("\n------------------------------------------------------------------------------------------------------------------\n");
    printf("The scrum master is activity %d which has duration of %d and overlaps %d activities",scrum_master, max2, max);
return 0;
}


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 

  

