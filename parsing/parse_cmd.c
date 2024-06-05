/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoulahra <aoulahra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:36:31 by aoulahra          #+#    #+#             */
/*   Updated: 2024/06/05 19:57:59 by aoulahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	replace_exit_state(t_prompt *prompt, t_data *data)
{
	char	*tmp;

	tmp = ft_itoa(prompt->exit_state);
	if (data->arg)
		free(data->arg);
	data->arg = tmp;
}

void	fill_args(t_cmd *cmd, int i)
{
	char	**new_data;
	t_data	*data;

	new_data = malloc(sizeof(char *) * (i + 1));
	ft_bzero(new_data, sizeof(char *) * (i + 1));
	data = cmd->data;
	i = 0;
	while (data)
	{
		new_data[i] = ft_strdup(data->arg);
		data = data->next;
		i++;
	}
	new_data[i] = NULL;
	cmd->args = new_data;
	i = 0;
	while(new_data[i])
	{
		printf("args[%d] = %s\n", i, new_data[i]);
		i++;
	}
}

void	get_cmd(t_cmd **cmd, t_token *token)
{
	int		i;
	t_data	*data;
	t_token	*tmp;

	tmp = token;
	i = 0;
	data = NULL;
	while (tmp)
	{
		if (data)
		{
			data->next = (t_data *)malloc(sizeof(t_data));
			data = data->next;
		}
		else
		{
			data = (t_data *)malloc(sizeof(t_data));
			(*cmd)->data = data;
		}
		ft_bzero(data, sizeof(t_data));
		data->arg = ft_strdup(tmp->data);
		data->joinable = tmp->joinable;
		data->type = tmp->type;
		tmp = tmp->next;
	}
}

void	get_args(t_cmd *cmd)
{
	int		i;
	char	*tmp;
	t_data	*data;

	data = cmd->data;
	while (data)
	{
		if (data->next && data->next->joinable)
		{
			tmp = data->arg;
			data->arg = ft_strjoin(data->arg, data->next->arg);
			free(tmp);
			data->next = data->next->next;
		}
		else
			data = data->next;
	}
	data = cmd->data;
	i = 0;
	while (data)
	{
		i++;
		data = data->next;
	}
	fill_args(cmd, i);
}
