/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:48:40 by rmonney           #+#    #+#             */
/*   Updated: 2022/03/23 20:16:20 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	welcome(void)
{
	welcome1();
	welcome2();
	welcome3();
	welcome4();
	welcome5();
	welcome6();
	welcome7();
	welcome8();
	welcome9();
	welcome10();
}

char	**cpy_env(char **env)
{
	int		len;
	int		i;
	char	**cpy;

	len = 0;
	while (env[len])
		len++;
	cpy = (char **)ft_calloc(sizeof(char *), (len + 1));
	if (!cpy)
		return (0);
	i = 0;
	while (i < len)
	{
		cpy[i] = ft_strdup(env[i]);
		i++;
	}
	return (cpy);
}

void	init_para(t_para **para, char **argv, char **env)
{
	(*para) = (t_para *)malloc(sizeof(t_para));
	(*para)->argv = argv;
	(*para)->env = env;
	g_glob.exit_status = 0;
}

void	ft_readline(char **env, t_para *para)
{
	(void)env;
	para->current = readline(para->prompt);
	if (para->current != NULL)
	{
		if (para->current[0])
		{
			add_history(para->current);
			while (*para->current == ' ')
				para->current++;
			if (*para->current != '\0')
			{
				if (current_parser(para))
					error_handler(current_parser(para), para);
				else
				{
					para->cmd = search_fct(para->out);
					do_fct(para->cmd, para);
				}
			}
		}
	}
	else
		exit (0);
}

int	main(int argc, char **argv, char **env)
{
	t_para	*para;

	if (argc > 2)
	{
		error_handler(4, NULL);
		return (0);
	}
	welcome();
	ft_signal();
	init_para(&para, argv, env);
	ft_termios(para);
	para->prompt = prompt_init(argc, argv);
	while (1)
		ft_readline(env, para);
	return (0);
}
