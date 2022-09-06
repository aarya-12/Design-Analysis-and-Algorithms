# Design-Analysis-and-Algorithms
## Activity selection problem
Modify the selection criteria and suggest a logic to select an activity with maximum time duration of resource usage.

## Approach
To select an activity based on maximum time duration, we need to calculate the duration of each activity first.
We used a struct which contains the index, start time, end time, duration and overlap count of each activity. Overlap count is the number of activities that the given activity overlaps. It is initialised to 0 in the beginning.
We take the start time and end time of each activity as input from the user. Using these, we calculate the duration of each activity.
Next step is to sort the activities based on their duration. We need to select an activity which has maximum duration and maximum resource usage too.
Now we check which activity overlaps majority of the other activities. Lastly we choose the activity which overlapped majority of the activities while having the maximum time duration at the same time.

## Language used
C language was used to write the code.

## Code
```C

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
 

  


```
## Example
|Index  |  0 | 1  |  2 | 3  |  4 |  5 | 6  |  7 |  8 | 9  | 10  | 11  |
|-------|---|---|---|---|---|---|---|---|---|---|---|---|
|Start time  |  1 |  3 | 0  |  5 |  3 | 5  | 6  |  8 | 8  | 2  | 12  | 5  |
|End time   |  4 | 5  | 6  | 7  | 8  |  9 | 10  | 11  | 12  | 13  | 14  | 17  |

These are the start and end times that we used in the example. The activity 9 has the duration of 11 and overlaps 8 activities. Thus activity 9 is selected.

## Output screenshots
<img src="https://github.com/aarya-12/Design-Analysis-and-Algorithms/blob/main/Screenshot%202022-09-06%20at%207.40.59%20PM.png">
<br>
<img src="https://github.com/aarya-12/Design-Analysis-and-Algorithms/blob/main/Screenshot%202022-09-06%20at%207.41.29%20PM.png">

## How to use?
Enter the number of activities and then input each activity's start and end times. In the output, the selected activity with its duration and how many activities it overlaps is displayed.


