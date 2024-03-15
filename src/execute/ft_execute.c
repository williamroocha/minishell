/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:30:49 by joaocard          #+#    #+#             */
/*   Updated: 2024/03/15 18:59:43 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_simple_cmds(t_node *node)
{
	no_cmd_file_redir(node);
	if (node->cmd->arg[0] == NULL)
		return ;
	else if (is_builtin(node) == 1)
		exec_builtin(node);
	else if (is_builtin(node) == 2)
		exec_cmd(node);
}

void	ft_exec_piped(t_node *node)
{
	int		pipe_end[2];
	pid_t	left_pid;
	pid_t	right_pid;
	int		n_heredoc_left;
	int		n_heredoc_right;
	int 	i;
	int		j;

	n_heredoc_left = count_redir(node->left);
	n_heredoc_right = count_redir(node->right);
	i = 1;
	if (pipe(pipe_end) < 0)
	{
		perror("Error at pipe");
		exit_shell(EXIT_FAILURE);
	}
	left_pid = fork();
	while (left_pid > 0 && n_heredoc_left && i <= n_heredoc_left)
	{
		j = 0;
		if (node->left->fd_in)
			close(node->left->fd_in);
		heredoc_check(node->left, j);
		j++;
		i++;
	}
	if (node->left->cmd->heredoc && node->left->fd_in)
		close(node->left->fd_in);
	left_node_process(node, pipe_end, left_pid);
	right_pid = fork();
	while ((right_pid > 0 && left_pid != 0) && n_heredoc_right && i <= n_heredoc_right)
	{
		i = 1;
		j = 0;
		if (node->right->fd_in)
			close(node->right->fd_in);
		heredoc_check(node->right, j);
		j++;
		i++;
	}
	if (node->right->cmd->heredoc && node->right->fd_in)
		close(node->right->fd_in);
	right_node_process(node, pipe_end, right_pid);
	parent_pipe_exec_control(node, pipe_end, left_pid, right_pid);
}

void	heredoc_check(t_node *node, int i)
{
	if (node->cmd && node->cmd->heredoc)
	{
		node->fd_in = heredoc(node, i);
		if (node->fd_in < 0)
		{
			shell()->status = EXIT_FAILURE;
			exit_shell(shell()->status);
		}
	}
}

void	ft_execute(t_node *node)
{
	if (node->type == TYPE_COMMAND)
		ft_simple_cmds(node);
	if (node->type == TYPE_PIPE)
		ft_exec_piped(node);
	
}
