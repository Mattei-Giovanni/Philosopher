#include "../headers/philo.h"

int init_philo(t_main *main)
{
    main->i = main->num;
    while(main->i > 0)
    {
        main->phils[main->i].id = main->i;
        main->phils[main->i].meals = 0;
        main->phils[main->i].ate = false;
        main->phils[main->i].last_meal = 0;
        if(main->i == main->num)
            main->phils[main->i].left_fork_id = 1;
        else
            main->phils[main->i].left_fork_id = main->i + 1;
        if(pthread_mutex_init(&main->forks[main->i], NULL))
            return(-1);
        main->phils[main->i].right_fork_id = main->i;
        main->i--;
    }
    return(0);
}

int init(t_main *main, char **argv)
{
    main->phils = malloc(sizeof(t_phils) * main->num);
    main->forks = malloc(sizeof(pthread_mutex_t) * main->num);
    main->num = ctm_atoi(main, argv[1]);
    main->tdie = ctm_atoi(main, argv[2]);
    main->teat = ctm_atoi(main, argv[3]);
    main->tsleep = ctm_atoi(main, argv[4]);
    if(main->num < 2 || main->tdie < 0 || main->teat < 0 || main->tsleep < 0)
        return(err(2));
    if(argv[5])
    {
        main->mtodo = ctm_atoi(main, argv[5]);
        if(main->mtodo <= 0)
            return(err(2));
    }
    else
        main->mtodo = -1;
    if(init_philo(main) == -1)
        return(err(5));
    return(0);
}
