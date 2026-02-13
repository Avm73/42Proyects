/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:15:35 by andres            #+#    #+#             */
/*   Updated: 2026/02/12 15:38:33 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_shell(t_shell *sh, char **envp)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	sh->env = dup_env(envp);
	sh->last_status = 0;
	tcgetattr(STDIN_FILENO, &sh->original_term);
}

static int	process_line(char *line, t_shell *sh)
{
	t_token	*tokens;
	t_cmd	*cmds;

	if (line[0] != '\0')
		add_history(line);
	tokens = lexer(line);
	free(line);
	if (!tokens)
		return (0);
	if (validate_tokens(tokens))
	{
		free_tokens(tokens);
		return (0);
	}
	expand_tokens(tokens, sh);
	merge_concat_tokens(&tokens);
	cmds = parse_tokens(tokens);
	free_tokens(tokens);
	if (!cmds)
		return (0);
	sh->last_status = execute_pipeline(cmds, sh);
	free_cmds(cmds);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_shell	sh;

	(void)argc;
	(void)argv;
	init_shell(&sh, envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			free_split(sh.env);
			break ;
		}
		process_line(line, &sh);
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
		tcsetattr(STDIN_FILENO, TCSANOW, &sh.original_term);
	}
	return (0);
}
