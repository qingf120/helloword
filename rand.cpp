#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
FILE *fout=freopen("outfile.txt","w",stdout);
//随机产生数
int main(){
//随机分几组
int cow,tt;
int a[31]={0},b[31]={0},c[31]={0},low=0,high=0;
int randi=0,kick=0,ti,ki,kj;
srand((unsigned long)time(0));
printf("请输入随机产生 几组\n");
scanf("%d",&ti);
    for(int tj=0;tj<ti;tj++){
        for(ki=1;ki<=9;){
            randi= rand()%29+1;
            if(b[randi]<=low&&c[randi]==0){
               b[randi]++;
               c[randi]=1;
               ki++;

               low= b[randi];
               for(int kk=1;kk<30;kk++){
                if(low>b[kk])low=b[kk];
               } //end for kk
            }  //end if
        } //end for ki
        for(tt=0;tt<30;tt++){

            if(c[tt]==1){
                if(tt==29)printf(",%d",tt+1);
                else printf(",%d",tt);
            }
            c[tt]=0;
        }
        printf("\n");
        


        
    } //end tj
         //    for(tt=0;tt<30;tt++){
        //     printf(" %.2d",b[tt]);
     //   }
     //   printf("\n");
return 0;

}
