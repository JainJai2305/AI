#include<stdio.h>
#include<stdlib.h>
void board(char arr[],char user,char comp )
{
    for(int x=1;x<=9;x++)
    {
        printf("%c  ",arr[x]) ;
        if(x%3==0)
        {
            printf("\n") ;
        }
    }
}
int move (char arr[],char mover,char comp)
{
    int ch=0 ;
    for(int x=1;x<=9;x++)
    {
        if(arr[x]==mover)
        {
            
            if(x==4 || x==5 || x==6)
            {
                if(arr[x-3]==mover && arr[x+3]=='e')
                {
                    printf("1 \n") ;
                    arr[x+3]=comp ;
                    ch++ ;
                    break ;
                }
                if(arr[x+3]==mover && arr[x-3]=='e')
                {
                    printf("2 \n") ;
                    arr[x-3]=comp ;
                    ch++ ;
                    break ;
                }
            }
            if(x==2 || x==5 || x==8)
            {
                if(arr[x-1]==mover && arr[x+1]=='e')
                {
                    printf("3 \n") ;
                    arr[x+1]=comp ;
                    ch++ ;
                    break ;
                }
                if(arr[x+1]==mover && arr[x-1]=='e')
                {
                    printf("4 \n") ;
                    arr[x-1]=comp ;
                    ch++ ;
                    break ;
                }
            }
            if(x==5)
            {
                if(arr[x-4]==mover && arr[x+4]=='e')
                {
                    printf("5 \n") ;
                    arr[x+4]=comp ;
                    ch++ ;
                    break ;
                }
                if(arr[x+4]==mover && arr[x-4]=='e')
                {
                    printf("6 \n") ;
                    arr[x-4]=comp ;
                    ch++ ;
                    break ;
                }
                if(arr[x-2]==mover && arr[x+2]=='e')
                {
                    printf("7 \n") ;
                    arr[x+2]=comp ;
                    ch++ ;
                    break ;
                }
                if(arr[x+2]==mover && arr[x-2]=='e')
                {
                    printf("8 \n") ;
                    arr[x-2]=comp ;
                    ch++ ;
                    break ;
                }

            }
            if(arr[1]== mover && arr[7]==mover && arr[4]=='e')
            {
                printf("9 \n") ;
                arr[4]=comp ;
                ch++ ;
                break ;
            }
            if((arr[2]== mover && arr[8]==mover) || (arr[1]==mover && arr[9]==mover) || (arr[3]==mover && arr[7]==mover)||(arr[4]==mover && arr[6]==mover))
            {
                if( arr[5]=='e')
                {
                    printf("10 \n") ;
                    arr[5]=comp ;
                    ch++ ;
                    break ;
                }
                
            }
            if(arr[3]== mover && arr[9]==mover)
            {
                if( arr[6]=='e')
                {
                    printf("11 \n") ;
                    arr[6]=comp ;
                    ch++ ;
                    break ;
                }
            }
            if(arr[1]==mover && arr[3]==mover)
            {
                if( arr[2]=='e')
                {
                    printf("12 \n") ;
                    arr[2]=comp ;
                    ch++ ;
                    break ;
                }
                
            }
            if(arr[7]== mover && arr[9]==mover)
            {
                if(arr[8]=='e')
                {
                    printf("13 \n") ;
                    arr[8]=comp ;
                    ch++ ;
                    break ;
                }
                
            }
            
        
        }
        
    }
    return ch ;
}
void challenge(char arr[],char user,char comp)
{
    int ch=0 ;
    int count=0 ;
    for(int x=1;x<10;x++)
    {
        if(arr[x]=='e')
        {
            count++ ;
        }
    }
    if(count==0)
    {
        printf("the game is over press -1 to end... \n") ;
        return ;
    }
    ch=move( arr, comp,comp) ;
    
    if (ch==0)
    {
        ch=move( arr, user, comp) ;
    }
    if(ch==0)
    {
        int f=rand()%10 ;
        while(arr[f]!='e' || f==0)
        {
            f=rand()%10 ;
        }
        arr[f]=comp ;
    }
}

int main()
{
    printf("player 1(X) or 2(O) \n") ;
    int ch ;
    scanf("%d",&ch) ;
    char user,comp ;
    if(ch==1)
    {
        user='X' ;
        comp='O' ;
    }
    else
    {
        user='O' ;
        comp='X' ;
    }
    char arr[]={'e','e','e','e','e','e','e','e','e','e'} ;
    if(ch==2)
    {
        int pl=rand()%9 ;
        arr[pl]=comp ;
    }
    while(ch!=-1)
    {
        printf("enter the place(1-9) u want to put \n") ;
        scanf("%d",&ch) ;
        if(ch!=-1)
        {
            printf("%d \n",ch) ;
            arr[ch]=user ;
            
            challenge( arr, user,comp) ;
            board( arr, user, comp ) ;
        }
        
    }

}
