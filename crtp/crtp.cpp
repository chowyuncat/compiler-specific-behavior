#include <stdio.h>

template <class T>
class BaseTask
{
public:
    void Run()
    {
        printf("BaseTask::Run()\n");
    }

    void Common()
    {
        printf("BaseTask::Common()\n");
    }
};

class RtrTask : public BaseTask<RtrTask>
{
public:
    void Run()
    {
        printf("RtrTask::Run()\n");
    }
};

typedef BaseTask<void> Task;

int main()
{
	Task task;
	task.Run();
	task.Common();

	RtrTask rtr;
	rtr.Run();
	rtr.Common();
}
