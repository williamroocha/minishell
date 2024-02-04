/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:36:14 by wiferrei          #+#    #+#             */
/*   Updated: 2024/02/04 17:12:04 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	end_shell(void)
{
	// free(shell()->v_env);
	// free(shell()->line);
	if (shell()->lexer)
		free(shell()->lexer);
	if (shell()->parser)
		free_parser(shell()->parser);
	
	exit(shell()->status);
}