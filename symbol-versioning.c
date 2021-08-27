
__asm__(".symver getauxval,getauxval@VERS_1.1");
unsigned long getauxval(unsigned long parameter)
{
	return 1;
}

int main()
{
	return 0;
}