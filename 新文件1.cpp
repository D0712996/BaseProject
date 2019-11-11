#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
 
int main(){ 
 
int o=50000,rrr; 
int n,m,count=0,go; 
int i,j,k,data,data_i,data_j; 
int array[22][42],data_count[22][42]; 
int start_i,start_j; 
srand(time(NULL)); 
 
while(scanf("%d %d %d %d",&m,&n,&start_i,&start_j)){ 
if(m>40 || m<=2 || n<2 || n>20 || start_i<2 || start_i>20 || start_j<=2 || start_i>40)printf("ERROR!!\n"); 
else break; 
} 
 
for(i=0 ; i<m ; i++){ 
for(j=0 ; j<n ; j++){ 
array[j][i]=0; 
data_count[j][i]=0; 
} 
} 
 
/*for(i=0 ; i<m ; i++){ 
for(j=0 ; j<n ; j++){ 
printf("%d ",array[j][i]); 
} 
printf("\n"); 
} 
printf("\n\n");*/ 
 
array[start_j][start_i]++; 
while(o--){ 
data=0; 
count++; 
//printf("%d %d\n",start_i,start_j); 
data_i = start_i; 
data_j = start_j; 
 
data_count[start_j][start_i]=1; 
go = rand()%8; 
//printf("go = %d\n",go); 
switch(go){ 
case 0: 
start_i--; 
start_j--; 
break; 
 
case 1: 
start_j--; 
break; 
 
case 2: 
start_i++; 
start_j--; 
break; 
 
case 3: 
start_i++; 
break; 
 
case 4: 
start_i++; 
start_j++; 
break; 
 
case 5: 
start_j++; 
break; 
 
case 6: 
start_i--; 
start_j++; 
break; 
 
case 7: 
start_i--; 
break; 
} 
 
//printf("%d %d\n",start_i,start_j); 
 
if(start_i>m || start_j>n || start_i<0 || start_j<0){ 
start_i = data_i; 
start_j = data_j; 
} 
else{ 
array[start_j][start_i]++; 
data_count[start_j][start_i]=1; 
} 
rrr=0; 
for(j=0 ; j<m ; j++){ 
for(k=0 ; k<n ; k++){ 
if(data_count[k][j]==1)data=1; 
if(data_count[k][j]==0){ 
data=0; 
rrr=1; 
break; 
} 
} 
if(rrr==1)break; 
} 
if(data==1){ 
break; 
} 
} 
 
printf("\n\n"); 
for(i=0 ; i<m ; i++){ 
for(j=0 ; j<n ; j++){ 
printf("%d ",array[j][i]); 
} 
printf("\n"); 
} 
printf("\n\n"); 
 
/*for(i=0 ; i<m ; i++){ 
for(j=0 ; j<n ; j++){ 
printf("%d ",data_count[j][i]); 
} 
printf("\n"); 
}*/ 
 
printf("count = %d\n",count); 
 
FILE *ptr; 
ptr = fopen("out.csv","w"); 
for(i=0 ; i<m ; i++){ 
for(j=0 ; j<n ; j++){ 
fprintf(ptr,"%d  ",array[j][i]); 
} 
fprintf(ptr,"\n"); 
} 
fprintf(ptr,"count = %d",count); 
 
fclose(ptr); 
 
return 0; 
} 

