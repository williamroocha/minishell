/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:26:20 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/25 15:27:04 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/builtins.h"

// // TODO: The return status is zero unless an invalid option is supplied, one of the names
// is not a valid shell variable name.
void	export(char *arg)
{
	t_env	*env;
	t_env	*new;
	char	*name;
	char	*value;
	char	*equal;

	env = shell()->v_env;
	if (!arg)
		display_exp_var(env);
	else
	{
		new = malloc(sizeof(t_env));
		equal = get_equal(arg);
		if (equal)
		{
			name = get_var_name(arg, equal);
			value = ft_strdup(equal + 1);
		}
		else
		{
			name = ft_strdup(arg);
			value = get_var_value(env, name);
		}
		update_envl(env, new, name, value);
	}
}

t_env	*create_var(t_env *new, char *name, char *value)
{
	new->name = name;
	new->value = value;
	new->next = shell()->v_env;
	shell()->v_env = new->next;
	return (new);
}

char	*get_var_name(char *arg, char *equal)
{
	char *name;
	
	name = malloc(sizeof(char) * ((equal - arg) + 1));
	ft_strncpy(name, arg, equal - arg);
	name[equal - arg] = '\0';
	return (name);
}

t_env	*update_envl(t_env *env, t_env *new, char *name, char *value)
{
	while (env && ft_strcmp(env->name, name) != 0)
		env = env->next;
	if (env)
		env->value = ft_strdup(value);
	else if (!value)
		create_var(new, name, value);
	return (env);
}

char	*get_equal(char *arg)
{
	char	*equal;
	
	equal = ft_strchr(arg, '=');
	return (equal);
}
