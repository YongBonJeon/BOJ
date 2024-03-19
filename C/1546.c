#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; //과목 수
    double *score; //과목 별 점수
    double *nscore;
    double sum=0;
    int i,check=0;
    int maxIdx=0;

    scanf("%d",&n); 
    if(n<0||n>1000)
        return 0;

    score=(double*)malloc(sizeof(double)*n);
    nscore=(double*)malloc(sizeof(double)*n);
    
    for(i=0;i<n;i++)
    {
        scanf("%lf",&score[i]);
        if(score[i]<0||score[i]>100) //과목별 점수 조건 확인
            return 0;
        if(score[i]==0) //적어도 ~ 조건 확인
            check++;
        if(score[i]>=score[maxIdx]) //최고점 찾기
            maxIdx=i;
    }
    if(check==n)
        return 0;
    
    for(i=0;i<n;i++)
        nscore[i]=(score[i]/score[maxIdx])*100;
    
    for(i=0;i<n;i++)
        sum+=nscore[i];

    printf("%lf\n",sum/(double)n);

    return 0;

}