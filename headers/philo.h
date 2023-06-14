#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h> 
# include <stdio.h>
# include <assert.h>
# include <pthread.h>

typedef struct s_phils
{
    int id; // id of the philosophers
    int meals; //meals done
    bool ate; // ate or not
    long long last_meal; // last meal timestamp
    int left_fork_id; // left fork id
    int right_fork_id; // right fork id
    pthread_t thread_id; // thread id
}   t_phils;

typedef struct s_main
{
    t_phils *phils;
    int num; // number of philosophers
    int tdie; // time to die
    int teat; // time to eat
    int tsleep; // time to sleep
    int mtodo; // number of meals to do
    int i; // counter
    long long first_timestamp;
	pthread_mutex_t		*forks;
}   t_main;

//Functions
    //Error Managament
int     err(int error);
    //Utils
int     ctm_atoi(t_main *main, char *str);
void    print(int timestamp, int k, char *c);
int     get_time(t_main *main, bool firstime);
    //Init
int     init(t_main *main, char **argv);
int     init_philo(t_main *main);
    //Philo
void    philo(t_main *main);

#endif