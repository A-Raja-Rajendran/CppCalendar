// CB.EN.U4CSE19101   --->    A.RAJA RAJENDRAN
// this is a program which prints the yearly calendar or the monthly calendar of any year according to our choice

#include<stdio.h>
int z=1;
int calculations(int,int);               //for calculating the day in which the month starts
int calendarmonthly(int,int,int);        //for getting monthly calendar
int calendaryearly(int,int);             //for getting yearly calendar
struct calendar
{
	int month,year;	
};
int main()
{
	struct calendar input;
	char type,choice='y';
	
	while(choice=='y'||choice=='Y')
	{
	printf("\nfor yearly calendar press 'y', for monthly calendar press 'm': ");
	scanf("%s",&type);
	if(type=='m'||type=='M')
	{
		printf("\nenter the year: ");
		scanf("%d",&input.year);
		printf("\nenter the month number(ie 1 for jan, 2 for feb....12 for dec): ");
		scanf("%d",&input.month);
		
		if(input.month>=3&&input.month<=12)
		{
			input.month=input.month-2;
		}
		else if(input.month==1)
		{
			input.month=11;
			input.year--;
		}
		else if(input.month==2)
		{
			input.month=12;
			input.year--;
		}
		else
		{
			printf("\ninvalid input!!!");
			return 0;
		}
		
		int day;
		day=calculations(input.month,input.year);
		calendarmonthly(day,input.month,input.year);
	}
	else
	{
		printf("\nenter the year: ");
		scanf("%d",&input.year);
		calendaryearly(input.year,z);
	}
	
	printf("\n\n press 'y' to go again!: ");
	scanf("%s",&choice);
	}
	printf("\n\nBYE!!!");
	return 0;
}
int calculations(int month,int year)         // finding day using zeller's rule
{
	int yearf,yearl,x,y;
	yearf = year/100;
	yearl = year%100;
	
	x = (1+((13*month-1)/5)+(yearl/4)+yearl+(yearf/4)-2*yearf);
	
	if(x>=0)
	{
		y=x%7;
	}
	else
	{
		y=7+(x%7);
	}
	return y;
}
int calendarmonthly(int day,int month,int year)                 //for monthly calendar
{
	int x,k=0;
	x=day-1;
	printf("\n\n\n\n\n");
	
	if(month==2||month==4||month==7||month==9)
	{
		switch(month)
		{
			case 2:
				printf("                    APRIL  %d\n\n",year);
				break;
			
			case 4:
				printf("                    JUNE  %d\n\n",year);	
				break;
				
			case 7:
				printf("                   SEPTEMBER  %d\n\n",year);	
				break;	
				
			case 9:
				printf("                   NOVEMBER  %d\n\n",year);
				break;		
				
		}
		printf("   MON     TUE     WED    THUR     FRI     SAT    SUN  \n");
		if(x==-1)
		{
			for(int j=0;j<6;j++)
			{
				printf(" |    | ");
			}
		}
		else
		{
			for(int j=0;j<x;j++)
			{
				printf(" |    | ");
			}
		}	
		for(int i=1;i<=30;i++)
		{	
			k++;
			if(i<10)
			{
				printf(" | 0%d | ",k);
			}
			else
			{
				printf(" | %d | ",k);
			}
			
			if((i+x)%7==0)
			{
				printf("\n");
			}	
		}
	}
	else if(month==11||month==1||month==3||month==5||month==6||month==8||month==10)
	{
		switch(month)
		{
			case 11:
				printf("                    JANUARY  %d\n\n",year+1);
				break;
			
			case 1:
				printf("                     MARCH  %d\n\n",year);	
				break;
			
			case 3:
				printf("                      MAY  %d\n\n",year);	
				break;
			
			case 5:
				printf("                     JULY  %d\n\n",year);	
				break;
			
			case 6:
				printf("                    AUGUST  %d\n\n",year);	
				break;
			
			case 8:
				printf("                    OCTOBER  %d\n\n",year);
				break;
				
			case 10:
				printf("                    DECEMBER  %d\n\n",year);	
				break;	
							
		}
		printf("   MON     TUE     WED    THUR     FRI     SAT    SUN  \n");
		if(x==-1)
		{
			for(int j=0;j<6;j++)
			{
				printf(" |    | ");
			}
		}
		else
		{
			for(int j=0;j<x;j++)
			{
				printf(" |    | ");
			}
		}
			
		for(int i=1;i<=31;i++)
		{	
			k++;
			if(i<10)
			{
				printf(" | 0%d | ",k);
			}
			else
			{
				printf(" | %d | ",k);
			}
			
			if((i+x)%7==0)
			{
				printf("\n");
			}
			
		}
	}
	else
	{
		printf("                    FEBRUARY  %d\n\n",year+1);
		printf("   MON     TUE     WED    THUR     FRI     SAT    SUN  \n");
		if(x==-1)
		{
			for(int j=0;j<6;j++)
			{
				printf(" |    | ");
			}
		}
		else
		{
			for(int j=0;j<x;j++)
			{
				printf(" |    | ");
			}
			if((year+1)%4==0)
			{
				for(int i=1;i<=29;i++)
				{	
					k++;
					if(i<10)
					{
						printf(" | 0%d | ",k);
					}
					else
					{
						printf(" | %d | ",k);
					}
				
					if((i+x)%7==0)
					{
						printf("\n");
					}
				}
			}
			else
			{
				for(int i=1;i<=28;i++)
				{	
					k++;
					if(i<10)
					{
						printf(" | 0%d | ",k);
					}
					else
					{
						printf(" | %d | ",k);
					}
				
					if((i+x)%7==0)
					{
						printf("\n");
					}
				}
			}
		}
	}
	
	return 0;
}
int calendaryearly(int year,int z)                              //for yeary calendar
{
	int day,y;
	
	if(z==1)
	{
		y=11;
		day=calculations(y,year-1);
		calendarmonthly(day,y,year-1);
	}
	else if(z==2)
	{
		y=12;
		day=calculations(y,year-1);
		calendarmonthly(day,y,year-1);
	}
	else if(z>2&&z<=12)
	{
		y=z-2;
		day=calculations(y,year);
	calendarmonthly(day,y,year);
	}
	if(z<12)
	{
		z++;
		calendaryearly(year,z);
	}
	else
	{
		return 0;
	}
	
	return 0;
}
