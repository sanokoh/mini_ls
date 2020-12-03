#include <stdio.h>
#include "libft.h"
char*ft_strtrim(char const *s1, char const *set);
int main()
{
char *s1 = " abaaab";
char *s2 = "";
char *ret = ft_strtrim(s1, "b");
 printf("%s\n", ret);

 return 0;
}
