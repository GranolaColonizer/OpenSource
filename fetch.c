#include <stdio.h>
#include <my_global.h>
#include <mysql.h>

int container;

void fetch_temperature(MYSQL * con,double temperature)
{
	mysql_query(con, "SELECT * FROM `mixer_temp`");
	MYSQL_RES *confres = mysql_store_result(con);
	int totalrows = mysql_num_rows(confres);
	int numfields = mysql_num_fields(confres);
	MYSQL_FIELD *mfield;
	MYSQL_ROW *row;
	FILE *fp;
	fp = fopen("output.csv","a+");
	


	while((row = mysql_fetch_row(confres)))
	{
	    int i = 0;
	    while(i<numfields)
	    {
	        char *val = row[i];
		if(i==0)	{
			fprintf(fp,val);
			fprintf(fp,",");
		
		}
		if(i==2)	{
			
			printf("Value = %s\n",val);
			fprintf(fp,val);
			fprintf(fp,"\n");
	        // do something with val...
	 	}

		i++;
		
	    }

	}
	fclose(fp);
}
int main()
{
	printf("Creating CSV file\n");
	FILE *fp;
	
	fp = fopen("output.csv","w+");
	fprintf(fp,"EID,Temperature Value\n");
	fclose(fp);	

	int i;
	MYSQL *con=mysql_init(NULL);
	if (con==NULL)
	{
		fprintf(stderr,"%s\n",mysql_error(con));
		exit(1);
		
	}
	if (mysql_real_connect(con,"localhost","root","c09784101","process_control",0,NULL,0)==NULL)
	{
		fprintf(stderr,"%s\n",mysql_error(con));
		exit(2);
	}
	for (i=0;i<100;i++)
	{
		fetch_temperature(con,sin(2.0*3.141592 * (double)i/100.0));
	}
	mysql_close(con);
	exit(0);
}








