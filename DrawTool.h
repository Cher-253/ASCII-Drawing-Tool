#ifndef _DRAWTOOL_H
#define _DRAWTOOL_H
#define CODE4_SIZE_MAX 20
void MapPrintingInstructions();
void MapInitializer(char a[][CODE4_SIZE_MAX],int *userArraySize);//sending a pointer of character type
void MapPrinter(char a[][CODE4_SIZE_MAX], int userArraySize);
void DrawToolPoint(char MapArrayPtr[][CODE4_SIZE_MAX],int xCoordinate,int yCoordinate,char character_replace);
void DrawToolLine(char MapArrayPtr[][CODE4_SIZE_MAX],int userArraySize,int xStart,int yStart,int userLength,char character_replace,char VorH);
#endif
