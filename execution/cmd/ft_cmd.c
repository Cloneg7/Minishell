/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:26:19 by hboudar           #+#    #+#             */
/*   Updated: 2024/06/09 16:22:53 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int    no_cmd(t_prompt *prompt, t_env **env, int *fd)
{
    extern int g_caught;

    printf("no_cmd\n");
    if (fd[0] != 0)
        close(fd[0]);
    if (g_caught)
    {
        g_caught = 0;
        return (1);
    }
    redirection(prompt, env);
    return (prompt->exit_state);
}

int	execute_builtin(t_prompt *prompt, t_env **env, int *fd)
{
    extern int g_caught;

    printf("execute_builtin\n");
    if (g_caught)
    {
        g_caught = 0;
        return (1);
    }
    else
        close(fd[0]);
    redirection(prompt, env);
	return (prompt->exit_state);
}

int	ft_cmd(t_prompt *prompt, t_env **env)
{
    extern int g_caught;
    int i;
    int fd[2];

    printf("ft_cmd\n");
	expand_cmd(prompt, *env);
	if (!prompt->cmd)
	{
		perror("malloc");
		return (1);
	}
    (1) && (i = -1, fd[0] = 0, fd[1] = 1, g_caught = 0);
    while (prompt->cmd->limiter && !g_caught && prompt->cmd->limiter[++i])
        here_doc(prompt, i, fd);
    if (!prompt->cmd->args)
		return (no_cmd(prompt, env, fd));
	else if (is_builtin(prompt))
		return (execute_builtin(prompt, env, fd));
	return (execute_nonebuiltin(prompt, *env, fd));
}
