#include <stdio.h>

class Base
{
public:
	Base() 
	// : m_array()
	{

	}

	int m_array[2];
};

static void show_base_members(const char *desc, const Base *b)
{
	printf("%s: m_array[0]: %d, m_array[1]: %d\n",
	       desc, 
		   b->m_array[0],
		   b->m_array[1]);
}

static Base b_static;

int main()
{
	Base b_stack;
	Base *b_heap = new Base();

	show_base_members("static", &b_static);
	show_base_members("stack ", &b_stack);
	show_base_members("heap  ", b_heap);

	delete b_heap;

	return 0;
}