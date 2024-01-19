/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:26:38 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/19 16:04:31 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_env	*find_env_var(t_env *env, char *name)
{
	while (env)
	{
		if (ft_strcmp(env->name, name) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}
void	get_var(t_env *new, char *envp, char *equal_pos)
{
	new->name = ft_strndup(envp, (equal_pos - envp));
	new->value = ft_strdup(equal_pos + 1);
	new->next = NULL;
}

void new_var(t_env *head, t_env *tail, t_env *new)
{
	if (tail)
	{
		tail->next = new;
		(void)head;
	}
	else
		head = new;
}

void check_new_malloc(t_env *new)
{
	if (!new)
	{
		printf("minishell: %s\n", strerror(errno));
		exit(shell()->status);
	}
}
t_env	*env_cpy(char **envp)
{
	t_env	*head;
	t_env	*tail;
	t_env	*new;
	char	*equal_pos;

	head = NULL;
	tail = NULL;
	new = malloc(sizeof(t_env));
	check_new_malloc(new);
	while (*envp)
	{
		equal_pos = ft_strchr(*envp, '=');
		if (equal_pos)
		{
			get_var(new, *envp, equal_pos);
			new_var(head, tail, new);
			tail = new;
		}
		else
			free(new);
		envp++;
	}
	return (head);
}
