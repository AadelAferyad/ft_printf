#include "../ft_printf.h"
#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>

#include <stdio.h>

int main() {
    int i;

    // Test %d and %i with flags
    i = printf("|%+10d|\n", 42);
    ft_printf("%d\n", i);
    i = ft_printf("|%+10d|\n", 42);
    ft_printf("%d\n", i);

    i = printf("|% 10i|\n", -12345);
    ft_printf("%d\n", i);
    i = ft_printf("|% 10i|\n", -12345);
    ft_printf("%d\n", i);

    i = printf("|%010d|\n", 12345);
    ft_printf("%d\n", i);
    i = ft_printf("|%010d|\n", 12345);
    ft_printf("%d\n", i);

    // Test %u with flags
    i = printf("|%-10u|\n", 98765);
    ft_printf("%d\n", i);
    i = ft_printf("|%-10u|\n", 98765);
    ft_printf("%d\n", i);

    i = printf("|%010u|\n", 429496729);
    ft_printf("%d\n", i);
    i = ft_printf("|%010u|\n", 429496729);
    ft_printf("%d\n", i);

    // Test %s with flags
    i = printf("|%10.6s|\n", NULL);
    ft_printf("%d\n", i);
    i = ft_printf("|%10.6s|\n", NULL);
    ft_printf("%d\n", i);

    i = printf("|%-15s|\n", "Hello, World!");
    ft_printf("%d\n", i);
    i = ft_printf("|%-15s|\n", "Hello, World!");
    ft_printf("%d\n", i);

    i = printf("|%10s|\n", "42");
    ft_printf("%d\n", i);
    i = ft_printf("|%10s|\n", "42");
    ft_printf("%d\n", i);

    // Test %c with flags
    i = printf("|%-5c|\n", 'A');
    ft_printf("%d\n", i);
    i = ft_printf("|%-5c|\n", 'A');
    ft_printf("%d\n", i);

    i = printf("|%5c|\n", 'Z');
    ft_printf("%d\n", i);
    i = ft_printf("|%5c|\n", 'Z');
    ft_printf("%d\n", i);

    // Test %x and %X with flags
    i = printf("|%#10x|\n", 255);
    ft_printf("%d\n", i);
    i = ft_printf("|%#10x|\n", 255);
    ft_printf("%d\n", i);

    i = printf("|%-#10X|\n", 255);
    ft_printf("%d\n", i);
    i = ft_printf("|%-#10X|\n", 255);
    ft_printf("%d\n", i);

    i = printf("|%08x|\n", 0x1234ABCD);
    ft_printf("%d\n", i);
    i = ft_printf("|%08x|\n", 0x1234ABCD);
    ft_printf("%d\n", i);

    // Test %%
    i = printf("|%%|\n");
    ft_printf("%d\n", i);
    i = ft_printf("|%%|\n");
    ft_printf("%d\n", i);

    // Test %p
    int var = 42;
    i = printf("|%20p|\n", &var);
    ft_printf("%d\n", i);
    i = ft_printf("|%20p|\n", &var);
    ft_printf("%d\n", i);

    i = printf("|%-20p|\n", &var);
    ft_printf("%d\n", i);
    i = ft_printf("|%-20p|\n", &var);
    ft_printf("%d\n", i);

    i = printf("|%p|\n", NULL);
    ft_printf("%d\n", i);
    i = ft_printf("|%p|\n", NULL);
    ft_printf("%d\n", i);

    // Edge cases and combinations
    i = printf("|%#-10.5x|\n", 1234);
    ft_printf("%d\n", i);
    i = ft_printf("|%#-10.5x|\n", 1234);
    ft_printf("%d\n", i);

    i = printf("|%+010d|\n", -98765);
    ft_printf("%d\n", i);
    i = ft_printf("|%+010d|\n", -98765);
    ft_printf("%d\n", i);

    i = printf("|%-10s%5c|\n", "42", 'C');
    ft_printf("%d\n", i);
    i = ft_printf("|%-10s%5c|\n", "42", 'C');
    ft_printf("%d\n", i);

    return 0;
}

