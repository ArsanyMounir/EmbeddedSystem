/*
 * Ex3_Transpose_of_Matrix.c
 *
 *  Created on: Jul 11, 2021
 *      Author: Arsany
 */
#include"stdio.h"
void main()
{
	int i,j,rows,columns,matrix[10][10],transpose[10][10];
	printf("Enter rows and column of matrix: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&rows,&columns);
	while(rows>10||rows<0||columns<0||columns>10)
	{
		printf("invalid input (range between 0 and 10)\nPlease re-enter data");
		fflush(stdin);
		fflush(stdout);
		scanf("%d %d",&rows,&columns);
	}
	printf("Enter elemets of matrix:\n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			printf("Enter elements a%d%d: ",i+1,j+1);
			fflush(stdin);
			fflush(stdout);
			scanf("%d",&matrix[i][j]);

		}
	}
	printf("Entered Matrix:\n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			transpose[j][i]=matrix[i][j];
			printf("%d\t",matrix[i][j]);
		}
		printf("\n\n");
	}
	printf("Transpose of Matrix:\n");
	for(i=0;i<columns;i++)
	{
		for(j=0;j<rows;j++)
		{
			printf("%d\t",transpose[i][j]);
		}
		printf("\n\n");
	}

}

