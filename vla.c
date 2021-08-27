/*
gcc -x c vla.c -Wvla
gcc -x c++ vla.c -Wvla
*/

int main()
{
	const int k_BufferSize = 2 * sizeof(int);
    char buffer[k_BufferSize];

	return 0;
}
