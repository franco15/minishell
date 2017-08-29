#include <stdlib.h>
#include <stdio.h>

// void	*ft_memset(void *b, int c, size_t len)
// {
// 	unsigned char	*s;
//
// 	s = b;
// 	while (len-- > 0)
// 		*s++ = c;
// 	return (b);
// }
//
// void	*ft_memalloc(size_t size)
// {
// 	char	*p;
// 	size_t	i;
//
// 	i = 0;
// 	p = malloc(size);
// 	if (!p)
// 		return (NULL);
// 	ft_memset(p, 0, size);
// 	return (p);
// }
//
int main()
{
	char *s;
	int i = 0;

	s = (char*)malloc(sizeof(char) * 10 + 1);
	if (!s)
		return (0);
	s[0] = '1';
	s[1] = '2';
	s[2] = '3';
	s[3] = '4';
	s[4] = '5';
	s[5] = '6';
	s[6] = '7';
	s[7] = '8';
	s[8] = '9';
	s[9] = '0';
	s[10] = 0;
	printf("%s\n", s);
	free(s);
	while (1)
	{
		i++;
	}
	return (0);
}
