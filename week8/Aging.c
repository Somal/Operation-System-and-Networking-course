#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

int main(void)
{
    char pageReferences[40], filename[40], filePages[10], pageCond;
    int fs,i,j,x,y, pageFaultCount, counters[10], max,maxInd, startValue;
    FILE *file;
    system("clear");
    printf("Enter the page reference filename: ");
    gets(filename);
//    printf("%s\n",filename);


    file=fopen(filename,"r");
    if (file){
		printf("File opened\n");
		fgets(pageReferences,sizeof(pageReferences),file);
	//	fprintf(stdout,"%s",prs);
    }
    else {
		printf("Error !!!\n");
    }
	

    fclose(file);
    printf("Enter the frame size: ");
    scanf("%d",&fs);
   
    for(i = 0; i < fs; i++)
    {
        filePages[i] = 'x';
    }


	startValue=1;
	startValue=startValue<<7;
	for (i=0; i<10;++i)
		counters[i]=0;
    
    system("clear");
    
    printf("PAGE REPLACEMENT TECHNIQUE: Aging algorithm using 8-bit counters\n");
    printf("———————————–\n");
    printf("F: Page Fault\tH: Page Hit\n");
  
	pageFaultCount=0;
	x=5;
	
    for(i = 0; i < strlen(pageReferences)-1; i++, x += 2)
    {
		pageCond='F';
		for (j=0; j<fs; ++j)
			if (filePages[j]==pageReferences[i])  {
				pageCond='H';
				counters[j]=counters[j]>>1+startValue;
			}
			else
				counters[j]=counters[j]>>1;
			
		if (pageCond=='F'){
			max=counters[0];
			maxInd=0;
			for (j=1;j<fs;++j)
				if (counters[j]<max) {
					max=counters[j];
					maxInd=j;
				}

			counters[maxInd]=startValue;
			filePages[maxInd]=pageReferences[i];
			pageFaultCount++;
		}


		y=5;
		gotoxy(x,y);
//		printf("%d\n",i);
		printf("%c",pageReferences[i]);
		y++;
		gotoxy(x,y);
		printf("- ");
		y++;

		for (j=0;j<fs;++j,++y){
			gotoxy(x,y);
			printf("%c",filePages[j]);
		}
		gotoxy(x,y);
		printf("- ");
		gotoxy(x,++y);
		printf("%c",pageCond);

    }
	
    printf("\n\n\n\n\n\nTotal page faults = %d\n", pageFaultCount);
    getch();
}
