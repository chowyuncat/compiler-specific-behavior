#include <stdio.h>

int main()
{
    signed char c = 0xc8;
    printf( "%hu\n", (short) c );
    printf( "%hu\n", ((short)(c)) & 0x00FF );
    printf( "%hu\n", ((short) c & 0x00FF) );
    printf( "%hu\n", ((short)c & ~0xFF00) );
    
    return 0;
}
// ((wchar_t)MbString[i] & ~0xFF00);

