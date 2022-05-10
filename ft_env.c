/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:19:29 by rmonney           #+#    #+#             */
/*   Updated: 2022/05/10 03:03:57 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ft_export(t_para *para)
{
	char	*arg;
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	if (para->out[6] == '\0')
		return (empty_export(para));
	arg = ft_strdup(para->current + ft_strstr(para->current, "export "));
	split = ft_split(arg, ' ');
	free(arg);
	while (para->env[j] != NULL)
		j++;
	while (split[i] != NULL)
	{
		if (!ft_strstr(split[i], "="))
			i++;
		else
			para->env[j++] = ft_strdup(split[i++]);
	}
	free_malloc2(split);
	para->env[j] = NULL;
	return (1);
}

void	ft_unset2(t_para *para, char *arg)
{
	int	i;

	i = 0;
	while (ft_strstr(para->env[i], arg) != (ft_strlen(arg)))
		i++;
	if (para->env[i] == NULL)
		return ;
	if (!env_cmp(arg, para))
		free_malloc(para->env[i]);
	while (para->env[i + 1] != NULL)
	{
		para->env[i] = para->env[i + 1];
		i++;
	}
	para->env[i] = NULL;
}

int	ft_unset(t_para *para)
{
	char	*arg;
	char	**split;
	int		i;

	i = 0;
	if (ft_strstr(para->out, "="))
	{
		error_handler(8, para);
		return (0);
	}
	arg = ft_strdup(para->out + ft_strstr(para->out, "unset "));
	split = ft_split(arg, ' ');
	while (split[i] != NULL)
	{
		if (ft_getenv(para, split[i]) == NULL)
			i++;
		else
		{
			ft_unset2(para, split[i]);
			i++;
		}
	}
	(free(arg), free_malloc2(split));
	return (1);
}

void	ft_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
		printf("%s\n", env[i++]);
}

char	*ft_getenv(t_para *para, char *var)
{
	int	i;

	i = 0;
	while (para->env[i] != NULL)
	{
		if (ft_strstr(para->env[i], var) == ft_strlen(var))
			return (&(*(para->env[i] + ft_strlen(var) + 1)));
		else
			i++;
	}
	return (NULL);
}
