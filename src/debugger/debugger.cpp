#include <stdio.h>
#include <sys/time.h>

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

	printf("[ %.8d:%.6d ]",now.tv_sec, now.tv_usec);
}

void debugger::debug_print(const char *msg, const char *file, const int line){
	
	print_timestamp();
	printf(" DEBUG   %s\n",msg);

}

void debugger::info_print(const char *msg, const char *file, const int line){

	print_timestamp();
	printf(" INFO    %s\n",msg);
		
}

void debugger::warning_print(const char *msg, const char *file, const int line){

	print_timestamp();
	printf(" WARNING %s\n",msg);
	print_timestamp();
	printf(" WARNING %s:%d\n",file,line);


}

void debugger::error_print(const char *msg, const char *file, const int line){

	print_timestamp();
	printf(" ERROR   %s\n",msg);
	print_timestamp();
	printf(" ERROR   %s:%d\n",file,line);
	

}
