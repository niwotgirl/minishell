/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelkis <aabelkis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:02:37 by aabelkis          #+#    #+#             */
/*   Updated: 2025/10/23 16:02:56 by aabelkis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_n_flag(const char *arg)
{
	int	i;

	if (!arg || arg[0] != '-')
		return (0);
	if (arg[0] == '\'' || arg[0] == '"')
		return (0);
	i = 1;
	if (arg[i] != 'n')
		return (0);
	while (arg[i] == 'n')
		i++;
	return (arg[i] == '\0');
}

void	print_args(t_command *cmd)
{
	int	i;

	if (!cmd || !cmd->args)
	{
		printf("No arguments\n");
		return ;
	}
	i = 0;
	while (cmd->args[i])
	{
		printf("args[%d]: [%s]\n", i, cmd->args[i]);
		i++;
	}
}

int	echo_cmd(t_command *cmd)
{
	int		i;
	int		new_line;

	i = 1;
	new_line = 1;
	while (cmd->args[i] && is_n_flag(cmd->args[i]))
	{
		new_line = 0;
		i++;
	}
	while (cmd->args[i] != NULL)
	{
		printf("%s", cmd->args[i]);
		if (cmd->args[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (new_line == 1)
		printf("\n");
	return (0);
}
