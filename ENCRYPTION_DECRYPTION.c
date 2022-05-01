//
#include <stdio.h>
int main()
{
    int row=0,col=0,colA=1,colB=1,l=0,i,j,k=1,K=1;
    
    while(row<=0 || col<=0)
    {
      printf("enter the size of matrix: ");
      scanf("%d%d",&row,&col);  
      if(row>0 && col)
      {
          int   a[row][col],b[row][col];
          for(l=0 ; l<2 ; l++)
          {
              if(l==0)
              {printf("ENTER ELEMENTS OF A:\n");}
              else
              {printf("ENTER ELEMENTS OF B:\n");}
              for(i=0 ; i<row ; i++)
              {
                  for(j=0 ; j<col; j++)
                  {
                      if(l==0)
                      {
                          
                          printf("ELEMENT A[%d][%d]:",i,j);
                          scanf("%d",&a[i][j]);
                      }
                      else
                      {
                        printf("ELEMENT B[%d][%d]:",i,j);
                        scanf("%d",&b[i][j]);  
                      }
                  }
              }
          }
          for(i=0 ; i<row ; i++)
          {
              for(j=0 ; j<col ; j++)
              {
                  if(a[i][j]!=0)
                  {
                      colA+=1;
                  }
                  if(b[i][j]!=0)
                  {
                      colB+=1;
                  }
              }
          }
          
          
          //TASK_1
          
          int A[3][colA],B[3][colB];
          for(i=0 ; i<row ; i++)
          {
              for(j=0 ; j<col ; j++)
              {
                  if(a[i][j]!=0)
                  {
                      A[0][k]=i+1;
                      A[1][k]=j+1;
                      A[2][k]=a[i][j];
                      k+=1;
                  }
                  if(b[i][j]!=0)
                  {
                      B[0][K]=i+1;
                      B[1][K]=j+1;
                      B[2][K]=b[i][j];
                      K+=1;
                  }
              }
          }
          A[0][0]=3;
          A[1][0]=6;
          A[2][0]=k-1;
          B[0][0]=3;
          B[1][0]=6;
          B[2][0]=K-1;
          for(l=0 ; l<2 ; l++)
          {
              if(l==0)
              {printf("\nELEMENTS OF A:\n");}
              else
              {printf("\nELEMENTS OF B:\n");}
              for(i=0 ; i<3 ; i++)
              {
                  if(l==0)
                  {
                      for(j=0 ; j<colA; j++)
                      {
                        printf("%d\t",A[i][j]);
                      }
                      printf("\n");
                  }
                  else
                  {
                      for(j=0 ; j<colB ; j++)
                      {
                              printf("%d\t",B[i][j]);
                      }
                      printf("\n");
                  }
              }
          }
          printf("\n\n TASK2\n\n");
          // TASK_2
          int c[3][k+K],l=0,flag=0;
          for(i=1 ; i<colA ; i++)
          {
            for(j=1 ; j<colB ; j++)
                {
                  if(a[0][i]==b[0][j] && a[1][i]==b[1][j])
                  {
                      c[0][l]=a[0][i];
                      c[1][l]=a[1][i];
                      c[2][l]=a[2][i]+b[2][j];
                      b[2][j]=0;
                      flag=1;
                      l+=1;
                  }
                }
            if(flag==0)
              {
                  c[0][l]=a[0][i];
                  c[1][l]=a[1][i];
                  c[2][l]=a[2][i];
                  l+=1;
              }
            flag=0;
          }
          for(i=0 ; i<colB ; i++)
          {
                  if(b[2][i]!=0)
                  {
                      c[0][l]=b[0][i];
                      c[1][l]=b[1][i];
                      c[2][l]=b[2][i];
                      l+=1;
                  }
          }
          for(i=0 ; i<3 ; i++)
          {
              for(j=0 ; j<l ; j++)
              {
                 printf("%d\t",c[i][j]); 
              }
              printf("\n");
          }
      }
      else
      {
          printf("INVALID SIZE OF ARRAY!");
      }
    }
}
