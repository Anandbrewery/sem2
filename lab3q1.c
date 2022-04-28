// U.ANANDHAKUMAR EC21B1087
#include <stdio.h>
int encrypt(int row,int col, int a[row][col], int e[row][col])// encrypter task1 it is used to encrypt the code as per question
{
    int i,j;// iterating elements
    for(i=0 ; i<row ; i++)// acess each and every element by row column major order
            {
                for(j=0 ; j<col ; j++)
                    {
                           if((i==0 || i==row-1)||(j==0||j==col-1))// for boundary elements incrementing by i+1
                           {
                                e[i][j]=a[i][j]+i+1; 
                                
                           }
                           else// for inner elements decrementing by j
                           {
                                e[i][j]=a[i][j]-j;
                           }
                }
            }
            return 0;
}
int decrypt(int row,int col, int a[row][col], int e[row][col])// decrypter task2 it is used to decrypt the code as per question
{
    int i,j;// iterating elements
    for(i=0 ; i<row ; i++)// acess each and every element by row column major order
            {
                for(j=0 ; j<col ; j++)
                    {
                       if((i==0 || i==row-1)||(j==0||j==col-1))// for boundary elements decrementing by i+1
                           {
                                e[i][j]=e[i][j]-i-1; 
                                
                           }
                           else// for inner elements incrementing by j
                           {
                                e[i][j]=e[i][j]+j;
                           }
                     }
            }
            return 0;
}
int main()
{
    int row=0 , col=0 , i , j , choice , flag=0;// matrix parts row and column , choice for alice or bob
    while(row<=0 || col<=0)// getting postive row and column input
    {
        printf("ENTER THE NUMBER OF ROWS: ");
        scanf("%d",&row);
        printf("ENTER THE NUMBER OF COLUMNS: ");
        scanf("%d",&col);
        if(row>0 && col>0)// getting postive row and column input
        {
            int a[row][col];// declaring input array
            int e[row][col];// declaring output array
            printf("ENTER THE ELEMENTS BY COLUMN MAJOR METHOD:");// coumn method allocation of memory 
            for(i=0 ; i<col ; i++)
            {
                for(j=0 ; j<row ; j++)
                {
                    printf("\nENTER A[%d][%d] ELEMENT: ",j,i);
                    scanf("%d",&a[j][i]);
                }
            }
            printf("ENTER WHETHER YOU ARE ALICE(1) OR BOB(2): ");
            scanf("%d",&choice);
            while(choice<3)// choice for alice or bob or termination
            {
                if(choice==1 )// alice working and encrypting task1
                    {
                        encrypt(row,col,a,e);// calling encrypter
                        flag=1;
                        printf("the 2d array :\n");
                        for(i=0 ; i<row ; i++)//printing encrypted array
                        {
                            for(j=0 ; j<col ; j++)
                            {
                                
                                printf("%d\t",e[i][j]);
                            }
                            printf("\n");
                        }
                    }
                else if(choice==2 && flag==1)// bob recieving decrypted message task2
                    {
                        decrypt(row,col,a,e);//calling decrypter
                        printf("the 2d array :\n");// printing decrypted array
                        for(i=0 ; i<row ; i++)
                        {
                            for(j=0 ; j<col ; j++)
                            {
                                
                                printf("%d\t",e[i][j]);
                            }
                            printf("\n");
                        }
                    }
                
                printf("choice:");//getting choice from the user
                scanf("%d",&choice);
            }
            
        }
        else// invalid row column input
        {
            printf("ROW AND COLUMN SHOULD HAVE NON NEGATIVE VALUES:");
        }
       
    }
}
