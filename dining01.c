#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct t_din
{
    pthread_t pth[100];
}   t_din;

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

int ft_din_create(t_din *din)
{
    int i;

    i = 0;
    while (i < 10)
    {
        if (pthread_create(&din->pth[i], NULL, mythread, &i))
            ft_err_msg("creating thread.");
        i++;
    }
    return (0);
}

int    ft_din_join(t_din *din)
{
    int i;

    i = 0;
    while (i < 10)
    {
        if (pthread_join(din->pth[i], NULL))
            ft_err_msg("joining thread");
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_din din;
    int i;
    if (ft_din_create(&din))
        return (1);
    if (ft_din_join(&din))
        return (1);
    return (0); 
}