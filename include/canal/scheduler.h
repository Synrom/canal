#include <vector>

// the main condition for the scheduler to work is that all scheduled analyzers analyze the same kinds of operations

class scheduler{
public:
	void increase();
	bool look_up();

	// scheduler & is the child -> increases with increase, but doesnt decrease with look_up
	scheduler(scheduler *);

	scheduler() = default;
	~scheduler() = default;
	scheduler(scheduler &&) = default;
	scheduler(const scheduler &) = default;
	scheduler &operator =(const scheduler &) = default;
	scheduler &operator =(scheduler &&) = default;
private:
	unsigned int count{0};
	void decrease();
	scheduler *child{NULL};
};
