/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:26:16 by rmonney           #+#    #+#             */
/*   Updated: 2022/03/31 15:28:49 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_readline2(t_para *para)
{
	if (*para->current != '\0')
	{
		if (current_parser(para))
			error_handler(current_parser(para), para);
		else
		{
			if (search_redirect(para))
				launch_redirect(para);
			else
			{
				para->cmd = search_fct(para->out);
				do_fct(para->cmd, para);
			}
		}
	}
}

void	ft_readline(t_para *para)
{
	para->current = readline(para->prompt);
	if (para->current != NULL)
	{
		if (para->current[0])
		{
			add_history(para->current);
			while (*para->current == ' ')
				para->current++;
			ft_readline2(para);
		}
	}
	else
		exit (0);
}