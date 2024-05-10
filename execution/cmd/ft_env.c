/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudar <hboudar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:01:14 by hboudar           #+#    #+#             */
/*   Updated: 2024/05/10 18:16:18 by hboudar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int ft_env(t_env *env)
{
    int i;

    i = 0;
    while (env)
    {
        if (env->value && (env->print == PRINT || env->print == ENV_PRINT))
        {
            ft_putstr_fd(env->key, 1);
            ft_putstr_fd(env->value, 1);
            ft_putstr_fd("\n", 1);
        }
        env = env->next;
    }
    return (0);
}
