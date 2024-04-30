/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:51:54 by mremenar          #+#    #+#             */
/*   Updated: 2024/04/25 17:58:20 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Two cases to handle regarding OLDPWD:
// - if we start minishell without changing directory in bash first (OLDPWD
//	without value), we don't get OLDPWD in envp
// - however, if we start minishell after changing directory in bash (OLDPWD 
//	has a value) we get the OLDPWD in envp
void	save_env(t_env **ms_env, char **env)
{
	int		oldpwd_flag;
	int		i;

	oldpwd_flag = 0;
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "OLDPWD", 6))
			oldpwd_flag++;
		lstadd_back(ms_env, lstnew(env[i]));
		i++;
	}
	if (!oldpwd_flag)
		lstadd_back(ms_env, lstnew("OLDPWD"));
}

void	print_env(t_env **env, int export_flag)
{
	t_env	*curr;
	int		i;
	int		size;

	curr = *env;
	size = lstsize(*env, EXPORT_FLAG);
	if (export_flag && !curr->i_sort)
		sort_env(env);
	i = 1;
	while (size--)
	{
		if (export_flag)
		{
			curr = find_var(*env, i++, NULL);
			print_export(curr);
		}
		else if (curr->exported_flag && curr->equal_flag)
		{
			printf("%s=", curr->name);
			if (curr->value)
				printf("%s", curr->value);
			printf("\n");
		}
		curr = curr->next;
	}
}

void	print_export(t_env *curr)
{
	if (!curr || ft_strncmp(curr->name, "_", 2) == 0 || !curr->exported_flag)
		return ;
	printf("declare -x %s", curr->name);
	if (curr->equal_flag)
	{
		printf("=\"");
		if (curr->value)
			printf("%s", curr->value);
		printf("\"");
	}
	printf("\n");
}

void	add_variable(t_env **env, char *new_var, int i, int export_flag)
{
	t_env	*curr;

	lstadd_back(env, lstnew(new_var));
	curr = lstlast(*env);
	if (!export_flag)
		curr->exported_flag = NOT_EXPORTED;
	if (new_var[i] == '=')
		curr->equal_flag = EQUAL_FLAG;
}

void	handle_variable(t_env **env, char *var_new, int export_flag)
{
	t_env	*curr;
	char	*tmp;
	int		i;

	i = 0;
	tmp = get_substr(var_new, &i, ST_EQ);
	curr = find_var(*env, 0, tmp);
	if (!curr)
		add_variable(env, var_new, i, export_flag);
	else
		update_variable(&curr, ++i, var_new, export_flag);
	init_i_sort(env);
	free(tmp);
}
