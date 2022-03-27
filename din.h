#ifndef DIN_H
#define DIN_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct t_din
{
    struct t_phi *phi;
    int     num_thr;
    int     count;
}   t_din;

typedef struct t_phi
{
    pthread_t thr;
    int id;
    int left;
    int right;
}   t_phi;

int ft_strlen(char *s);
int	ft_error_message(char *msg);
int	ft_isnum(char *str);
int	ft_myatoi(char *str);
void    ft_err_msg(char *str);
void    *mythread(void *arg);
int ft_din_create(t_din *din, int n);
int    ft_din_join(t_din *din, int n);
int main(int argc, char **argv);


#endif