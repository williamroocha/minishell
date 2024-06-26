/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:13:50 by joaocard          #+#    #+#             */
/*   Updated: 2024/05/17 18:32:59 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_c_env(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (env[i])
			free(env[i]);
		env[i] = NULL;
		i++;
	}
	free(env);
	env = NULL;
}

void	free_cmd_paths(char **cmd_paths)
{
	int	i;

	i = 0;
	while (cmd_paths[i])
	{
		free(cmd_paths[i]);
		cmd_paths[i] = NULL;
		i++;
	}
	free(cmd_paths);
	cmd_paths = NULL;
}

void	free_env(void)
{
	t_env	*current;
	t_env	*next;

	current = shell()->v_env;
	while (current)
	{
		next = current->next;
		if (current->name)
		{
			free(current->name);
			current->name = NULL;
		}
		if (current->value)
		{
			free(current->value);
			current->value = NULL;
		}
		free(current);
		current = NULL;
		current = next;
	}
	shell()->v_env = NULL;
}
