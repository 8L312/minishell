/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:48:07 by rmonney           #+#    #+#             */
/*   Updated: 2022/03/19 16:43:46 by rmonney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	welcome1(void)
{
	char	*s0;
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;

	s0 = "──────── Welcome to the ────────";
	s1 = "    ██▄   ▄██                   ";
	s2 = "    ██ ▀▄▀ ██ ██          ██    ";
	s3 = "    ██     ██                   ";
	s4 = "    ██     ██ ██ █▄█████▄ ██    ";
	printf("%s\n%s\n%s\n%s\n%s\n", s0, s1, s2, s3, s4);
}

void	welcome2(void)
{
	char	*s0;
	char	*s1;
	char	*s2;
	char	*s3;

	s0 = "    ██     ██ ██ ██    ██ ██    ";
	s1 = "    ██     ██ ██ ██    ██ ██    ";
	s2 = "    ██     ██ ██ ██    ██ ██    ";
	s3 = "    ██     ██ ██ ██    ██ ██    ";
	printf("%s\n%s\n%s\n%s\n", s0, s1, s2, s3);
}

void	welcome3(void)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;

	s1 = "                                ";
	s2 = "        ▄███████████████▄       ";
	s3 = "       ███████████████████      ";
	s4 = "     ██████▀   ██   ▀███████    ";
	s5 = "   ████████    ██    ████████   ";
	printf("%s\n%s\n%s\n%s\n%s\n", s1, s2, s3, s4, s5);
}

void	welcome4(void)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;

	s1 = "  ███   ▀███   ██   ███▀   ███  ";
	s2 = "  ████    ██   ██   ██    ████  ";
	s3 = " ██████   ██   ██   ██   ██████ ";
	s4 = " ██  ██   ██   ██   ██   ██  ██ ";
	s5 = " ██   ██   ██  ██  ██   ██   ██ ";
	printf("%s\n%s\n%s\n%s\n%s\n", s1, s2, s3, s4, s5);
}

void	welcome5(void)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;

	s1 = "███   ██   ██  ██  ██   ██   ███";
	s2 = "███    ██  ██  ██  ██  ██    ███";
	s3 = "████   ██  ██  ██  █   ██   ████";
	s4 = "██ ██   ██  █  ██  █  ██   ██ ██";
	s5 = "██  ██  ██  ██ ██ ██  ██  ██  ██";
	printf("%s\n%s\n%s\n%s\n%s\n", s1, s2, s3, s4, s5);
}
