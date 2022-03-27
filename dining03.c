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
    t_phi *phi = (t_phi*)arg;
    t_din *din;

    while (!(din->count))
    {
        printf("Thread %d created.\n", phi->id);
    }
    return (NULL);
}

int ft_din_create(t_din *din, int n)
{
    int i;
    t_phi *phi;

    phi = din->phi;

    i = 0;
    while (i < n)
    {
        if (pthread_create(&phi[i].thr, NULL, mythread, &phi[i]))
            ft_err_msg("creating thread.");
            usleep(500000);
        i++;
    }

    ft_din_join(din, n);

    return (0);
}

int    ft_din_join(t_din *din, int n)
{
    int i;
    t_phi *phi;

    phi = din->phi;
    i = 0;
    while (i < n)
    {
        if (pthread_join(phi[i].thr, NULL))
            ft_err_msg("joining thread");
        i++;
    }
    free(phi);
    return (0);
}

int    ft_init_din(t_din *din, char **argv)
{
    t_phi *phi;

    phi = malloc(sizeof(t_phi) * ft_myatoi(argv[1]));
    if (!phi)
        return (1);
    din->num_thr = ft_myatoi(argv[1]);

    int i;

    din = malloc(sizeof(t_din) * n);
    if (!din)
        return (1);
    din->num_thr = n;
    din->count = 0;
    while (i < n)
    {
        din[i].phi->id = i;
        din[i].phi->left = i;
        din[i].phi->right = (i % n) + 1;
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_din din;
    
    
    if (!(ft_init_din(&din, ft_myatoi(argv[1]))))
        return (1);

    printf("%d \n", din.count);
//    if (ft_din_create(&din, ft_myatoi(argv[1])));
//        return (1);
    return (0); 
}