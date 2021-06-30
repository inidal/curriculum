#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum companies {GOOGLE, FACEBOOK, XEROX, YAHOO = 13, EBAY, MICROSOFT};

    printf("Xerox value: %i\n", XEROX);
    printf("Google value: %i\n", GOOGLE);
    printf("Ebay value: %i\n\n", EBAY);

    return 0;
}