#include<stdio.h>
void initialize(int park[6][8])
{
    int i,j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<8;j++)
        {
            park[i][j]=0;  //considering all the slots are zero
        }
    }
}
void allow(int park[6][8], int row, int colmn)
{
    if(park[row][colmn]==0)
    {
        park[row][colmn]==1;    //when parked a vehicle here
    }
}
void move(int park[6][8], int row, int colmn)
{
    if(park[row][colmn]==1)
    {
        park[row][colmn]=0;  //when vehicle moved from here
    }
}
void display(int park[6][8])
{
    int i,j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<8;j++)
        {
            printf("%d ",park[i][j]);
        }
        printf("\n");
    }
}
void spaces(int park[6][8])
{
    int i,j,count=0;
    for(i=0;i<6;i++)
    {
        for(j=0;j<8;j++)
        {
            if(park[i][j]==0)
            {
                count=count+1;  //get the space count
            }
        }
    }
    printf("\n%d",count);
}
void mostempty(int park[6][8])
{


    int i,j;
    int maxrow=0;
    int most=0;
    for(i=0;i<6;i++)
    {
        int empty=0;
        for(j=0;j<8;j++)
        {
            if(park[i][j]==0)
            {
                empty++;
            }
        }
        if(empty>most)
        {
            most=empty;   //which row has the most spaces
            maxrow=i;
        }
    }

        printf("\n max slots has the %d row ",maxrow);


}
void consecutive(int park[6][8])
{
    int space=2,i,j;
    for(i=0;i<6;i++)
    {
        int consecutive=0;
        for(j=0;j<8;j++)
        {
            if(park[i][j]==0)
            {
                consecutive++;
            }
            else
            {
                consecutive=0;
            }
            if(consecutive==space)
            {
                printf("\n %d row has consecutive slots",i);
            }
        }
    }
}
void vip(int park[6][8], int row, int colmn)
{
    int i,j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<8;j++)
        {
            if(park[row][colmn]==0)
            {
                park[row][colmn]==2;  //vip slot reserved as 2
            }
        }
    }
}

int main()
{
    int park[6][8];

    initialize(park);
    display(park);
    allow(park,1,2);
    move(park,2,3);
    vip(park,3,4);
    mostempty(park);
    spaces(park);

    return 0;

}
