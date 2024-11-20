#include "../ft_printf.h"
#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>

int main() {
    int i;

    // Basic format specifiers
    i = printf("%d %i %u %s %c %x %X %p\n", -42, 42, 42, "hello", 'A', 0xFF, 0xFF, &i);
    printf("%d\n", i);
    i = ft_printf("%d %i %u %s %c %x %X %p\n", -42, 42, 42, "hello", 'A', 0xFF, 0xFF, &i);
    printf("%d\n", i);

    // Flags and Width
    i = printf("%+10d |%-10d |%#10x |%#10X\n", -123, 123, 0xABC, 0xABC);
    printf("%d\n", i);
    i = ft_printf("%+10d |%-10d |%#10x |%#10X\n", -123, 123, 0xABC, 0xABC);
    /*printf("%d\n", i);*/
    /**/
    i = printf("|%#10X|\n", 0xABC);
    printf("%d\n", i);
    i = ft_printf("|%#10X|\n", 0xABC);
    printf("%d\n", i);
    // Precision
    i = printf("%5d %5i %5u %5s %5c %5x %5X\n", 123456789, -123456789, 123456789, "hello world", 'A', 0xABCDEF, 0xABCDEF);
    printf("%d\n", i);
    i = ft_printf("%5d %5i %5u %5s %5c %5x %5X\n", 123456789, -123456789, 123456789, "hello world", 'A', 0xABCDEF, 0xABCDEF);
    printf("%d\n", i);

    // Combinations
	   i = printf("%+010d % 10d %#010x %#010X\n", -123, 123, 0xABC, 0xABC);
	   printf("%d\n", i);
	   i = ft_printf("%+010d % 10d %#010x %#010X\n", -123, 123, 0xABC, 0xABC);
	   printf("%d\n", i);
	i = printf("%+010d\n", 123);
	ft_printf("%d\n", i);
	i = ft_printf("%+010d\n", 123);
	ft_printf("%d\n", i);
	i = printf("% 010d|\n", 123);
	   printf("%d\n", i);
	i = ft_printf("% 010d|\n", 123);
	   printf("%d\n", i);
    // Pointer
    i = printf("%p\n", &i);
    printf("%d\n", i);
    i = ft_printf("%p\n", &i);
    printf("%d\n", i);
    // Edge Cases
	   i = printf("%d %d %d\n", 0, -0, 0);
	   printf("%d\n", i);
	   i = ft_printf("%d %d %d\n", 0, -0, 0);
	   printf("%d\n", i);
	/**/
	i = printf("%+10d\n", 123);
	ft_printf("%d\n", i);
	i = ft_printf("%+10d\n", 123);
	ft_printf("%d\n", i);
	/**/
	i = printf("%+010d\n", 123);
	ft_printf("%d\n", i);
	i = ft_printf("%+010d\n", 123);
	ft_printf("%d\n", i);

	i = printf("%50p\n", &i);
	ft_printf("%d\n", i);
	i = ft_printf("%50p\n", &i);
	ft_printf("%d\n", i);


    return 0;
}
