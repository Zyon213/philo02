#include "din.h"


int ft_strlen(char *s)
{
  	int	i;

	i = 0;
	while (s[i])
		i++;
    return (i);
}

int	ft_error_message(char *msg)
{
    int l;

    l = ft_strlen(msg);
	write(2,"Error ", 6);
	write(2, msg, l);
	write(2, "\n", 1);
	return (1);
}
int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_myatoi(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (str[i] == '+')
		i++;
	if (ft_isnum(&str[i]))
	{
		while (str[i])
		{
			n = n * 10 + (str[i] - 48);
			i++;
		}
		if (n >= 0 && n <= 2147483647)
			return (n);
		else
			return (ft_error_message("Out of range."));
	}
	else
		return (ft_error_message("Invalid argument."));
}

void    ft_err_msg(char *str)
{
    printf("Error %s\n",str);
    exit (1);
}

void    *mythread(void *arg)
{
    int i = *(int*)arg;
    printf("Thread %d created.\n",i);
    return (NULL);
}

int ft_din_create(t_din *din, int n)
{
    int i;

    din->pth = malloc(sizeof(pthread_t) * n);
    if (!din->pth)
        return (1);

    i = 0;
    while (i < n)
    {
        if (pthread_create(&din->pth[i], NULL, mythread, &i))
            ft_err_msg("creating thread.");
        i++;
    }

    return (0);
}

int    ft_din_join(t_din *din, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (pthread_join(din->pth[i], NULL))
            ft_err_msg("joining thread");
        i++;
    }
    free(din->pth);
    return (0);
}

int main(int argc, char **argv)
{
    t_din din;

    if (ft_din_create(&din, ft_myatoi(argv[1])));
        return (1);
    if (ft_din_join(&din, ft_myatoi(argv[1])))
        return (1);
    return (0); 
}