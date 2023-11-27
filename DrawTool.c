#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DrawTool.h"
void MapInitializer(char ArrayPtr1[][CODE4_SIZE_MAX],int *userArraySize)//pointer to user array size
{

	do
	{
		printf("How big is the array? (Enter a value between 1 and 20)");
		scanf("%d",userArraySize);
		if (*userArraySize < 1 || *userArraySize > CODE4_SIZE_MAX)
		{
			printf("That value is outside of the max bounds of the array.  Please reenter\n\n");
		}
		
	}while(*userArraySize < 1 || *userArraySize > CODE4_SIZE_MAX);

	char BackgroundCharacter =' ';
	printf("What is the background character? ");
	scanf(" %c\n",&BackgroundCharacter);

    int x,y=0;
    for(x=0; x<*userArraySize; x++)
    {
       for(y=0; y<*userArraySize; y++)
       {
          *(*(ArrayPtr1 + x ) + y)=BackgroundCharacter;//putting the background characters into the array
       }//just like [0,0]--> then *(*(ArrayPtr1 + 0 ) + 0) and [2,3],*(*(ArrayPtr1 + 2 ) + 3)
    }
}
void MapPrintingInstructions()
{
	printf("Draw commands start with\n\n\tP for a single point\n\tH for a horizontal"); 
	printf("line\n\tV for a vertical line\n\nAfter the P/V/H, enter a row,col coordinate and"); 
	printf("the number of spots to mark enclosed in () and separated by commas and then the"); 
	printf("character for the mark.'X' will be used if a mark is not entered.  For example,\n\n\t");
	printf("P(2,3,1)*\tstart at point 2,3 in the array and mark one spot\n\t\t\t with an *.  For P,");
	printf("the 3rd parameter is ignored.\n\n\tV(1,2,3)$\tstart at point 1,2 in the array ");
	printf("and mark the next\n\t\t\t3 spots down from the current position with $\n\n\tH(4,6,7)#\t");
	printf("start at point 4,6 in the array and mark the next\n\t\t\t7 spots to the right with #\n\n");
	printf("Coordinates out of range and lines drawn past the borders are not allowed.\n\nEnter Q ");
	printf("at the draw command prompt to quit\n\nPress <ENTER>to continue\n");
}
void MapPrinter(char ArrayPtr1[][CODE4_SIZE_MAX],int userArraySize)
{
    int x,y=0;
    for(x=0; x<userArraySize; x++)
    {
       for(y=0; y<userArraySize; y++)
       {
          printf("%c", *(*(ArrayPtr1 + x ) + y));// printing each element of the array
       }
       printf("\n");
    }
}
void DrawToolPoint(char MapArrayPtr[][CODE4_SIZE_MAX],int xCoordinate,int yCoordinate,char character_replace)
{
    //char MapArrayPtr = &Map;
    *(*(MapArrayPtr+xCoordinate)+yCoordinate)=character_replace;
}
void DrawToolLine(char MapArrayPtr[][CODE4_SIZE_MAX],int userArraySize,int xStart,int yStart,int userLength,char character_replace,char VorH)
{   
    //char *start= (MapArrayPtr+(x*userArraySize)+y);
    int xEnd= xStart+userLength-1;
    //printf("start =%d\n",start);
    //char *end=(start+userLength);
    int yEnd =yStart;//END FOR horizontal(yEnd=yStart)
    //printf("end =%d\n",end);
    
    if(VorH=='V')
    {
        if((xStart+userLength)>(userArraySize))
        {
            printf("The draw command is out of range\n ");
            return;
        }
    }
    else
    {
        yEnd = yStart+userLength-1;
        xEnd = xStart;
        if((yStart+userLength)>(userArraySize)) //this is a check for knowing if userinput in coordinates is larger than the array size
        {
            printf("The draw command is out of range\n ");
            return;//it will exit out of the function
        }
    }
     //when start/userArraySize!=end/userArraySize
    //char *i=start;
    int x,y=0;
    //printf("%d %d %d %d",xStart,xEnd,yStart,yEnd);
    for(x=xStart; x<=xEnd; x++)
    {
       for(y=yStart; y<=yEnd; y++)
       {
          *(*(MapArrayPtr + x ) + y)=character_replace;//putting the background characters into the array
       }
    }
}


