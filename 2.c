#include <sstream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <iomanip>
#include "math.h"
int main(int argc, char **argv)
{
    FILE *fp = NULL; 
    char *line,*record; 
    char buffer[100];
    unsigned long int l_data[110][110];
    int line_x,line_y,i,j,line_max,temp1,temp2, line_num,a,b;
    memset(l_data,0,sizeof(l_data));
    if ((fp = fopen(argv[1], "r")) != NULL) 
    {
        char delims[] = ",";
        char *result = NULL;
        j = 0;
        //int line_num=0;
        while ((line = fgets(buffer, sizeof(buffer), fp))!=NULL) 
        { 
            record = strtok(line, ","); 
            while (record != NULL) 
            { 
                if(0 == line_num)
                {
                    if(0 == j)
                    {
                        sscanf(record,"%d",&line_y);
                    }
                    else if(1 == j)
                    {
                        sscanf(record,"%d",&line_x);
                        if(line_y<1 || line_x<1)
                        {
                          printf("data error");
                            return 0;
                        } 
						   if(line_y>100 || line_x>100)
                        {
                          printf("data error");
                            return 0;
                        } 
                    }
                }
                else
                {
                    sscanf(record,"%ld",&l_data[line_x-(line_num-1)][line_y-j]);
                }
                record = strtok(NULL, ","); 
                j++; 
            } 
            j = 0; 
            line_num++;
        }
        fclose(fp); 
        fp = NULL; 
    }
    else
    {
        printf("Open File failed.\n");
        return 0;    
    }
    line_num=0;
    line_max=line_x>line_y ? line_x:line_y;
    line_x=line_max;
    line_y=line_max;
    for(line_num=1;line_num <= line_max;line_num++)
    {
        a=line_num<line_x?line_num:line_x;
        b=line_num<line_y?line_num:line_y;
        //update line_num,line_num data
        temp1=l_data[a][b]+l_data[a-1][b];
        temp2=l_data[a][b]+l_data[a][b-1];
        l_data[a][b]=temp1>temp2?temp1:temp2;


        for(i=a+1;i<line_x+1;i++)
        {
            temp1=l_data[i][b]+l_data[i-1][b];
            temp2=l_data[i][b]+l_data[i][b-1];
            l_data[i][b]=temp1>temp2?temp1:temp2;
        }
        for(i=b+1;i<line_y+1;i++)
        {
            temp1=l_data[a][i]+l_data[a-1][i];
            temp2=l_data[a][i]+l_data[a][i-1];
            l_data[a][i]=temp1>temp2?temp1:temp2;
        }
    }
printf("%ld\n",l_data[line_x][line_y]);
return 0;
}
