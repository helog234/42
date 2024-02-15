/* #include <stdio.h>
#include <sys/resource.h>

int main(void) {
    struct rlimit limit;

    if (getrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("Soft limit: %lld\n", (long long)limit.rlim_cur);
        printf("Hard limit: %lld\n", (long long)limit.rlim_max);
    } else {
        perror("getrlimit");
    }

    return 0;
} */

#include <stdio.h>
# include "so_long/mlx/mlx.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	printf("%i\n", keycode);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 53, close, &vars);
	mlx_loop(vars.mlx);
}
