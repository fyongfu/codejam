#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>


int get_data(char *buf,int *outdata)
{
int result = 0;
char ch;
char count,i;

count=0;
while((ch = *(buf++)) != '\r')
{ 
if(ch == ',')
{
	*(outdata+count)=result;
	result=0;
	count++;
}
if(ch >= '0' && ch <= '9')
{
result = result*10 + ch-'0';

}

}
*(outdata+count)=result;
count++;
/*
for(i=0;i<count;i++)
{
	printf("%d ",*(outdata+i));
}
printf("%d \r\n",count);
*/

return count;
}

int main(int argc, char **argv)
{
		FILE *fp = NULL; 
	     char *line,*record; 
		 char buffer[100];
		 char j;
		 int count;
		 int out_data[20];
		 char *list;
		 char testlineNum,userNum;
	 if ((fp = fopen("3.csv", "r")) != NULL) 
    {
		 char delims[] = ",";
        char *result = NULL;
        j = 0;
        //int line_num=0;
        while ((line = fgets(buffer, sizeof(buffer), fp))!=NULL) 
        { 
			count=get_data(line,&out_data[0]);
			
			if(j==0)
			{
				if(count==2)
				{
					testlineNum=out_data[0];
					userNum=out_data[1];
					printf("testlineNum =%d userNum=%d \r\n",testlineNum,userNum);
					
				}
			}
			else
			{
				
			}
			
		//	printf("%d \n",data);
			//printf("%d %s",j,line);
				j++;
		}
	
		
	}
	else
	{
		printf("error\n");
		return 0;
	}
    printf("%d\n", 0);
    return 0;        
}
