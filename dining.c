#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct t_philo
{
    pthread_mutex_t fork[200];
    pthread_mutex_t meal;
    pthread_mutex_t message;
    pthread_t phi_thr;
    int left_fork;
    int right_fork;
}   t_philo;
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
int main(int argc, char **argv)
{
    pthread_t pht[10];
    int i;

    i = 0;
    while (i < 10)
    {
        if (pthread_create(&pht[i], NULL, mythread, &i))
            ft_err_msg("creating thread.");
        i++;
    }
    i = 0;

    while (i < 10)
    {
        if (pthread_join(pht[i], NULL))
            ft_err_msg("joining thread");
        i++;
    } 
}