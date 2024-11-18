#include <stdio.h>




int	main(void)
{
	int	i, num = 75;
	/*printf("using - with space \n");*/
	/*printf("|%-8d|\n", 42);*/
	/*printf("|% -8d|\n", 42);*/
	/*printf("|%- 8d|\n", 42);*/
	/*printf("|% 8d|\n", 42);*/
	/*printf("|%8d|\n", 42);*/
	/**/
	/*printf("using - with zero\n");*/
	/*printf("|%-8d|\n", 42);*/
	/*printf("|%0-8d|\n", 42);*/
	/*printf("|%-08d|\n", 42);*/
	/*printf("|%08d|\n", 42);*/
	/**/
	/*printf("using - with hashtag\n");*/
	/*printf("|%#-8x|\n", 255);*/
	/*printf("|%-#8x|\n", 255);*/
	/*printf("|%-8x|\n", 255);*/
	/*printf("|%#8x|\n", 255);*/
	/**/
	/*printf("using - with +\n");*/
	/*printf("|%-+8d|\n", 42);*/
	/*printf("|%+-8d|\n", 42);*/
	/*printf("|%-8d|\n", 42);*/
	/*printf("|%+8d|\n", 42);*/
	/**/
	/**/
	/*printf("using space with width\n");*/
	/*printf("|%8 d|\n", 42); invalid*/
	/*printf("|% 8d|\n", 42);*/
	/*printf("|%8d|\n", 42);*/
	/**/
	/**/
	/*printf("using space with -\n");*/
	/*printf("|% -8d|\n", 42);*/
	/*printf("|% -8d|\n", 42);*/
	/*printf("|% 8-d|\n", 42);invalid*/
	/**/
	/**/
	/*printf("using space with zero\n");*/
	/*printf("|% 8d|\n", 42);*/
	/*printf("|%0 8d|\n", 42);*/
	/*printf("|% 08d|\n", 42);*/
	/*printf("|%08d|\n", 42);*/
	/**/
	/*printf("using space with hashtag\n");*/
	/*printf("|%# 8x|\n", 255);*/
	/*printf("|% #8x|\n", 255);*/
	/*printf("|% 8x|\n", 255);*/
	/*printf("|%#8x|\n", 255);*/
	/**/
	/*printf("using space with +\n");*/
	/*printf("|% +8d|\n", 42);*/
	/*printf("|%+ 8d|\n", 42);*/
	/*printf("|% 8d|\n", 42);*/
	/*printf("|% 8d|\n", 42);*/

	i = 22;
	i = printf("%s|\n", (char *)0);
	printf("%d%d\n", num, i);
	return (0);
}
