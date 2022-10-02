#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{

  //beginning_________________________________________________________________________________________

  int columns;
  int rows;
  printf("Type the rows number:");
  scanf("%d", &rows);
  printf("Type the columns number:");
  scanf("%d", &columns);

  int col[rows][columns];
  int rowres[rows];

  printf("\n");
  printf("Note: The first number at the coefficient reader is your row, the second is a column\n\n");

  //coef reader______________________________________________

  for (int r = 1; r <= rows; r++)
  {
    for (int c = 1; c <= columns; c++)
      {
        printf("Type the coefficient\t %d.%d \t", r, c, "\n");
        scanf("%d", &col[r][c]);
      }
  }

  //matrix print and control_________________________________
  
  bool hom;
  char answer;
  printf("\nIs your matrix homogeneous? Y/N\t");
  scanf(" %c", &answer);
  printf("Answer is %c\n", answer);
  if (answer == 'N' || answer == 'n')
  {
      bool hom = false; 
      link:
      printf("Write the rows results:\n");
      for (int i = 1; i <= rows; i++)
        {
          scanf("%d", &rowres[i]);
        }     
    
    printf("\nIs this your answers? Y/N\t");
    scanf(" %c", &answer);
    printf("Answer is %c\n", answer);
    if (answer == 'N' || answer == 'n')
    {
      goto link;
    }
    
      
    int c = 1;

     for (int r = 1; r <= rows; r++)
    { 
      printf("\n");
      for (int c = 1; c <= columns; c++)
        {
          printf("%d", col[r][c]);
          printf("\t");
        }
      printf("=\t");
      printf("%d", rowres[c]);
      c++;  
    }

    char answer;
    printf("\n\nIs this your matrix? Y/N\t");
    scanf(" %c", &answer);
    printf("Answer is %c\n", answer);
    if (answer == 'N' || answer == 'n')
    {
      main();
    }
  }
  else
  {
    bool hom = true; 
     for (int r = 1; r <= rows; r++)
    { 
      printf("\n");
      for (int c = 1; c <= columns; c++)
        {
          printf("%d", col[r][c]);
          printf("\t");
        }
        printf("\t=\t0");
    }

    char answer;
    printf("\nIs this your matrix? Y/N\t");
    scanf(" %c", &answer);
    printf("Answer is %c\n", answer);
    if (answer == 'N' || answer == 'n')
    {
      main();
    }
  }

// the solve_____________________________________________________

if (hom == true)
  {
      
      if (col [1][1] == 1)
      {
           for (int r = 2; r <= rows; r++)
          {
            int a;
            a = (-1) * col[r][1];
            for (int c = 0; c <= columns; c++)
            {
              col [r][c+1] = col [1][c+1] * (a) + col [r][c+1];
            }
          } 

        //int a;
        //col [2][1] = col [1][1] * (a = (-1) * col[2][1]) + col [2][1];
        //col [2][2] = col [1][2] * (a) + col [2][2];
        //col [2][3] = col [1][3] * (a) + col [2][3];
        ////
        //int b;
        //col [3][1] = col [1][1] * (b = (-1) * col[3][1]) + col [3][1];
        //col [3][2] = col [1][2] * (b) + col [3][2];
        //col [3][3] = col [1][3] * (b) + col [3][3];
      }
       for (int r = 1; r <= rows; r++)
      { 
        printf("\n");
        for (int c = 1; c <= columns; c++)
          {
            printf("%d", col[r][c]);
            printf("\t");
          }
          printf("\t=\t0");
      }
     
  }

 return 0;
}
