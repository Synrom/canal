#include <stdio.h>
#include <sys/time.h>
#include <stdarg.h>

class debugger{
public:
	static void debug_print(const char *, const int);
	static void info_print(const char *, const int);
	static void warning_print(const char *, const int);
	static void error_print(const char *, const int);
	static void init_debugger();
private:
	static struct timeval start_time;
	static void print_timestamp();
};


#ifdef DEBUG

#define debug_conditional(condition,...) if(condition){debug(__VA_ARGS__);}
#define debug(...) debugger::debug_print( __FILE__ , __LINE__); printf(__VA_ARGS__); printf("\n")
#define info_conditional(condition,...) if(condition){info(__VA_ARGS__);}
#define info(...) debugger::info_print( __FILE__ , __LINE__); printf(__VA_ARGS__); printf("\n")
#define warning_conditional(condition,...) if(condition){warning(__VA_ARGS__);}
#define warning(...) debugger::warning_print(__FILE__,__LINE__); printf(__VA_ARGS__); printf("\n")
#define error_conditional(condition,...) if(condition){error(__VA_ARGS__);}
#define error(...) debugger::error_print(__FILE__,__LINE__); printf(__VA_ARGS__); printf("\n")
#define INIT_DEBUGGER debugger::init_debugger();

#elif INFO

#define debug_conditional(condition,...) 
#define debug(...) 
#define info_conditional(condition,...) if(condition){info(__VA_ARGS__);}
#define info(...) debugger::info_print( __FILE__ , __LINE__); printf(__VA_ARGS__); printf("\n")
#define warning_conditional(condition,...) if(condition){warning(__VA_ARGS__);}
#define warning(...) debugger::warning_print(__FILE__,__LINE__); printf(__VA_ARGS__); printf("\n")
#define error_conditional(condition,...) if(condition){error(__VA_ARGS__);}
#define error(...) debugger::error_print(__FILE__,__LINE__); printf(__VA_ARGS__); printf("\n")
#define INIT_DEBUGGER debugger::init_debugger();

#elif WARNING

#define debug_conditional(condition,...) 
#define debug(...) 
#define info_conditional(condition,...) 
#define info(...) 
#define warning_conditional(condition,...) if(condition){warning(__VA_ARGS__);}
#define warning(...) debugger::warning_print(__FILE__,__LINE__); printf(__VA_ARGS__); printf("\n")
#define error_conditional(condition,...) if(condition){error(__VA_ARGS__);}
#define error(...) debugger::error_print(__FILE__,__LINE__); printf(__VA_ARGS__); printf("\n")
#define INIT_DEBUGGER debugger::init_debugger();

#elif ERROR

#define debug_conditional(condition,...) 
#define debug(...) 
#define info_conditional(condition,...) 
#define info(...) 
#define warning_conditional(condition,...)
#define warning(...) 
#define error_conditional(condition,...) if(condition){error(__VA_ARGS__);}
#define error(...) debugger::error_print(__FILE__,__LINE__); printf(__VA_ARGS__); printf("\n")
#define INIT_DEBUGGER debugger::init_debugger();

#else

#define debug_conditional(condition,...) 
#define debug(...) 
#define info_conditional(condition,...) 
#define info(...)
#define warning_conditional(condition,...)
#define warning(...)
#define error_conditional(condition,...)
#define error(...)
#define INIT_DEBUGGER 

#endif
