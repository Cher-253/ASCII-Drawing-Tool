#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "DrawTool.h"

int main(void)
{
	char *Token = NULL;
	int xCoordinate,yCoordinate,userLength=0;
	char character_replace =' ';
    int flag =0;
	char Map[CODE4_SIZE_MAX][CODE4_SIZE_MAX];
	int userArraySize=0;
	char inputTemp[15];// temp array to store draw commands
	char tempChar =' ';
	
	MapPrintingInstructions();//
	MapInitializer(Map, &userArraySize);//passing address of user array size (pointer)

	do
	{//draw map or print map with characters and userinput size
	    MapPrinter(Map, userArraySize);
		printf("\nEnter draw command(enter Q to quit)\n");
		scanf("%s\n",(char *)&inputTemp);
		if(inputTemp[0]!='q'&& inputTemp[0]!='Q')
		{   
			
			Token = strtok(inputTemp,"(");
			//printf("First char is %s\n", Token);
			xCoordinate =atoi(strtok(NULL, ",")); 
			//printf("The second word is %d\n",xCoordinate);
			yCoordinate = atoi(strtok(NULL,","));
			//printf("The third word is %d\n",yCoordinate);
			userLength = atoi(strtok(NULL,")"));
			//printf("The fourth word is %d\n",userLength);
			character_replace=strtok(NULL,"\n");
			if(character_replace == NULL)
			{
				character_replace="X";
			}
			
			if(inputTemp[0]=='P')//If entry is P(1,1,2)H
			{
			    DrawToolPoint(Map,xCoordinate,yCoordinate,character_replace);
			}
            else if(inputTemp[0]=='V'||inputTemp[0]=='H')
            {
                DrawToolLine(Map,userArraySize,xCoordinate,yCoordinate,userLength,character_replace,inputTemp[0]);
            }
			else
			{
				printf("The draw command is out of range\n ");
			}
			
		}
	}
	while(inputTemp[0]!='q'&& inputTemp[0]!='Q');
	//MapPrintingInstructions();//todo: wait for enter character..any character
}

