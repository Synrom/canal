#include <stdio.h>
#include <sys/time.h>

class debugger{
public:
	static void debug_print(const char *, const char *, const int );
	static void info_print(const char *, const char *, const int );
	static void warning_print(const char *, const char *,const int );
	static void error_print(const char *, const char *, const int );
	static void init_debugger();
private:
	static struct timeval start_time;
	static void print_timestamp();
};


#ifdef DEBUG

#define debug_conditional(condition,msg) if(condition){debug(msg);}
#define debug(msg) debugger::debug_print(msg, __FILE__ , __LINE__)
#define info(msg) debugger::info_print(msg, __FILE__ , __LINE__)
#define warning_conditional(condition,msg) if(condition){warning(msg);}
#define warning(msg) debugger::warning_print(msg, __FILE__ , __LINE__)
#define error_conditional(condition,msg) if(condition){error(msg);}
#define error(msg) debugger::error_print(msg, __FILE__ , __LINE__)
#define INIT_DEBUGGER debugger::init_debugger();

#elif INFO

#define debug_conditional(condition,msg) 
#define debug(msg) 
#define info(msg) debugger::info_print(msg, __FILE__ , __LINE__)
#define warning_conditional(condition,msg) if(condition){warning(msg);}
#define warning(msg) debugger::warning_print(msg, __FILE__ , __LINE__)
#define error_conditional(condition,msg) if(condition){error(msg);}
#define error(msg) debugger::error_print(msg, __FILE__ , __LINE__)
#define INIT_DEBUGGER debugger::init_debugger();

#elif WARNING

#define debug_conditional(condition,msg) 
#define debug(msg) 
#define info(msg) 
#define warning_conditional(condition,msg) if(condition){warning(msg);}
#define warning(msg) debugger::warning_print(msg, __FILE__ , __LINE__)
#define error_conditional(condition,msg) if(condition){error(msg);}
#define error(msg) debugger::error_print(msg, __FILE__ , __LINE__)
#define INIT_DEBUGGER debugger::init_debugger();

#elif ERROR

#define debug_conditional(condition,msg) 
#define debug(msg) 
#define info(msg) 
#define warning_conditional(condition,msg) 
#define warning(msg) 
#define error_conditional(condition,msg) if(condition){error(msg);}
#define error(msg) debugger::error_print(msg, __FILE__ , __LINE__)
#define INIT_DEBUGGER debugger::init_debugger();

#else

#define debug_conditional(condition,msg) 
#define debug(msg) 
#define info(msg)
#define warning(msg)
#define error(msg)
#define error_conditional(condition,msg)
#define INIT_DEBUGGER 

#endif
