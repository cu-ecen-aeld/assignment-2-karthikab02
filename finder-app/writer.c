#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
	openlog("writer", LOG_PID, LOG_USER);

	if(argc != 3)
	{
		syslog(LOG_ERR, "Invalid number of arguments: %d", argc);
		closelog();
		return 1;
	}


	const char *filepath = argv[1];
	const char *text = argv[2];

	FILE *fp = fopen(filepath, "w");
	if(fp == NULL)
	{
		syslog(LOG_ERR, "Error opening file %s", filepath);
		closelog();
		return 1;
	}

	syslog(LOG_DEBUG, "Writing %s to %s", text, filepath);


	if(fprintf(fp, "%s", text) < 0)
	{
		syslog(LOG_ERR, "Error writing to file %s", filepath);
		fclose(fp);
		closelog();
		return 1;
	}

	fclose(fp);
	closelog();
	return 0;
}
