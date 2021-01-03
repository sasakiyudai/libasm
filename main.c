#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t			ft_strlen(char *str);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
ssize_t			ft_write(int fd, const void *buf, size_t n);
ssize_t			ft_read(int fd, void *buf, size_t n);
char			*ft_strdup(const char *s1);

int main(void)
{
	char *long_str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char *kara = "";
	char *hello = "hello";

	printf("\n******************************\n");
	printf("*****     ft_strlen      *****\n");
	printf("******************************\n\n");

	printf("input: %s real: %zu output: %zu\n", long_str, strlen(long_str), ft_strlen(long_str));
	printf("input: %s real: %zu output: %zu\n", kara, strlen(kara), ft_strlen(kara));
	printf("input: %s real: %zu output: %zu\n", hello, strlen(hello), ft_strlen(hello));

	printf("\n******************************\n");
	printf("*****     ft_strcpy      *****\n");
	printf("******************************\n\n");

	char *dst;
	dst = malloc(1025);

	printf("input: %s real: %s output: %s\n", long_str, strcpy(dst, long_str), ft_strcpy(dst, long_str));
	printf("input: %s real: %s output: %s\n", kara, strcpy(dst, kara), ft_strcpy(dst, kara));
	printf("input: %s real: %s output: %s\n", hello, strcpy(dst, hello), ft_strcpy(dst, hello));

	printf("\n******************************\n");
	printf("*****     ft_strcmp      *****\n");
	printf("******************************\n\n");

	char *short_str = "bbb";
	char *one_str = "a";
	char *evening = "evening";

	printf("input: %s %s real: %d output: %d\n", long_str, short_str, strcmp(long_str, short_str), ft_strcmp(long_str, short_str));
	printf("input: %s %s real: %d output: %d\n", kara, one_str, strcmp(kara, one_str), ft_strcmp(kara, one_str));
	printf("input: %s %s real: %d output: %d\n", hello, evening, strcmp(hello, evening), ft_strcmp(hello, evening));
	
	printf("input: %s %s real: %d output: %d\n", long_str, long_str, strcmp(long_str, long_str), ft_strcmp(long_str, long_str));
	printf("input: %s %s real: %d output: %d\n", kara, kara, strcmp(kara, kara), ft_strcmp(kara, kara));
	printf("input: %s %s real: %d output: %d\n", hello, hello, strcmp(hello, hello), ft_strcmp(hello, hello));
	
	printf("\n******************************\n");
	printf("*****     ft_write       *****\n");
	printf("******************************\n\n");

	printf("\ninput: %s \n", long_str);
	write(1, "real: ", 6);
	write(1, long_str, 1024);
	write(1, "\nmine: ", 7);
	ft_write(1, long_str, 1024);

	printf("\ninput: %s \n", kara);
	write(1, "real: ", 6);
	write(1, kara, 0);
	write(1, "\nmine: ", 7);
	ft_write(1, kara, 0);

	printf("\ninput: %s\n", hello);
	write(1, "real: ", 6);
	write(1, hello, 5);
	write(1, "\nmine: ", 7);
	ft_write(1, hello, 5);

	printf("\ninput: %s\n", short_str);
	write(1, "real: ", 6);
	write(1, short_str, 3);
	write(1, "\nmine: ", 7);
	ft_write(1, short_str, 3);

	printf("\ninput: %s\n", one_str);
	write(1, "real: ", 6);
	write(2, one_str, 1);
	write(1, "\nmine: ", 7);
	ft_write(2, one_str, 1);

	printf("\ninput: %s\n", evening);
	write(1, "real: ", 6);
	write(2, evening, 4);
	write(1, "\nmine: ", 7);
	ft_write(2, evening, 4);

	printf("\n******************************\n");
	printf("*****     ft_read        *****\n");
	printf("******************************\n\n");

	char real_buf[1000];
	char mine_buf[1000];
	int fd;

	printf("input: Makefile\n");

	fd = open("Makefile", O_RDONLY);
	read(fd, real_buf, 500);
	printf("real: %s", real_buf);
	close(fd);
	printf("\n");
	fd = open("Makefile", O_RDONLY);
	ft_read(fd, mine_buf, 500);
	printf("mine: %s", mine_buf);
	close(fd);

	printf("\n******************************\n");
	printf("*****     ft_strdup      *****\n");
	printf("******************************\n\n");

	char *ret1;
	char *ret2;

	ret1 = strdup(long_str);
	ret2 = ft_strdup(long_str);
	printf("\n");
	printf("input: %s", long_str);
	printf("\nreal: %s",ret1);
	printf("\nmine: %s",ret2);


	ret1 = strdup(hello);
	ret2 = ft_strdup(hello);
	printf("\n");
	printf("input: %s", hello);
	printf("\nreal: %s",ret1);
	printf("\nmine: %s",ret2);

	ret1 = strdup(kara);
	ret2 = ft_strdup(kara);
	printf("\n");
	printf("input: %s", kara);
	printf("\nreal: %s",ret1);
	printf("\nmine: %s",ret2);

	ret1 = strdup(one_str);
	ret2 = ft_strdup(one_str);
	printf("\n");
	printf("input: %s", one_str);
	printf("\nreal: %s",ret1);
	printf("\nmine: %s",ret2);

	ret1 = strdup(evening);
	ret2 = ft_strdup(evening);
	printf("\n");
	printf("input: %s", evening);
	printf("\nreal: %s",ret1);
	printf("\nmine: %s",ret2);
}