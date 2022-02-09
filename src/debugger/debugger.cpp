#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <execinfo.h>

#include <canal/debugger.h>

void debugger::init_debugger(){
	gettimeofday(&start_time, NULL);
}

struct timeval debugger::start_time;

void debugger::print_timestamp(){

	struct timeval now;
	gettimeofday(&now, NULL);

	now.tv_sec -=  start_time.tv_sec;
	now.tv_usec -= start_time.tv_usec;

	printf("[ %.8ld:%.6ld ]",now.tv_sec, now.tv_usec);
}

void debugger::debug_print(const char *file, const int line){
	
	print_timestamp();
	printf(" DEBUG   ");

}

void debugger::info_print(const char *file, const int line){

	print_timestamp();
	printf(" INFO    ");
		
}

void debugger::warning_print(const char *file, const int line){

	print_timestamp();
	printf(" WARNING %s:%d    ",file,line);


}

void debugger::error_print(const char *file, const int line){

	print_timestamp();
	printf(" ERROR %s:%d    ",file,line);
}
void debugger::error_backtrace_dump(){
	void *backtrace_buffer[100];
	char **backtrace_strings;
	int size = backtrace(backtrace_buffer, 100);
	backtrace_strings = backtrace_symbols(backtrace_buffer, size);
	if(backtrace_strings == NULL){
		printf("failed to convert backtrace buffer to strings\n");
		exit(0);
	}
	for(int i = 0;i < size;i++)
		printf("%s\n",backtrace_strings[i]);
	free(backtrace_strings);
}
