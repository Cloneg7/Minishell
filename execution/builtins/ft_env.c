/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:01:14 by hboudar           #+#    #+#             */
/*   Updated: 2024/05/02 14:46:19 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int ft_env(t_prompt *prompt, t_env *env)
{
    int i;

    i = 0;
    while (env)
    {
        if (env->value)
        {
            ft_putstr_fd(env->key, 1);
            ft_putstr_fd("=", 1);
            ft_putstr_fd(env->value, 1);
            ft_putstr_fd("\n", 1);
        }
        env = env->next;
        prompt->exit_state = 0;
    }
    return (prompt->exit_state);
}
