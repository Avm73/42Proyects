/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:29:37 by anvilla-          #+#    #+#             */
/*   Updated: 2025/07/30 20:39:22 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lexer.h"

t_token	*new_token(token_type type, const char *str)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = ft_strdup(str);
	token->next = NULL;
	return (token);
}

void	add_token(t_token **head, t_token *new)
{
	t_token	*tmp;

	tmp = *head;
	if (!tmp)
	{
		*head = new;
		return ;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return ;
}

const char *token_to_string(token_type token)
{
    switch (token)
    {
		case TOKEN_WORD:	return "TOKEN_WORD";
		case TOKEN_PIPE:	return "TOKEN_PIPE";
		case TOKEN_REDIR_IN:	return "TOKEN_REDIR_IN";
		case TOKEN_REDIR_OUT:	return "TOKEN_REDIR_OUT";
		case TOKEN_APPEND:	return "TOKEN_APPEND";
		case TOKEN_HEREDOC:	return "TOKEN_HEREDOC";
		case TOKEN_END:	return "TOKEN_END";
		default:	return "UNKNOWN_TOKEN";
    }
}

void	print_token(t_token *head)
{
	t_token	*tmp;

	tmp = head;
	while (tmp)
	{
		printf("%s: %s\n", token_to_string(tmp->type), tmp->value);
		tmp = tmp->next;
	}
	return ;
}

t_token	*get_token(const char *str)
{
	t_token	*token;
	char	buffer[256];
	int		i;
	int		j;

	i = 0;
	j = 0;
	token = NULL;
	while (*str)
	{
		if(*str == ' ')
			str++;
		else if (*str == '|')
		{
			buffer[0] = *str;
			buffer[1] = '\0';
			add_token(&token, new_token(TOKEN_PIPE, buffer));
		}
		else if (*str == '<')
		{
			str++;
			if (*str == '<')
			{
				buffer[0] = '<';
				buffer[1] = '<';
				buffer[2] = '\0';
				add_token(&token, new_token(TOKEN_HEREDOC, buffer));
			}
			else if (*str != '<')
			{
				buffer[0] = '<';
				buffer[1] = '\0';
				add_token(&token, new_token(TOKEN_REDIR_OUT, buffer));
			}
		}
		else if (*str == '>')
		{
			str++;
			if (*str == '>')
			{
				buffer[0] = '>';
				buffer[1] = '>';
				buffer[2] = '\0';
				add_token(&token, new_token(TOKEN_APPEND, buffer));
			}
			else if (*str != '>')
			{
				buffer[0] = '>';
				buffer[1] = '\0';
				add_token(&token, new_token(TOKEN_REDIR_IN, buffer));
			}
		}
		else if (ft_isalnum(*str))
		{
			while (ft_isalnum(*str) || *str == '.')
				buffer[j++] = *str++;
			buffer[j] = '\0';
			add_token(&token, new_token(TOKEN_WORD, buffer));
		}
		j = 0;
		str++;
	}
	return (token);
}
			
			// las comillas simples conservan el valor literal de cada caracter
			// no se puede usar una comilla simple incluso cuando va precedida de una '\'

			//las comillas dobles tambien conservan el valor literales de cada caracter 
			// con la excepcion de '$' y cuando la expansion del historial esta habilitada,'!'.
			//el \ conserva su valor cuando va precedido de '$',''','"','\' or '\n'

void	signal_handler(int sig)
{
	if (sig == SIGINT)
		exit(1);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_token	*token;

	signal(SIGINT, signal_handler);
	while (1)
	{
		char	*line = readline("minishell$ ");
		if (!line)
			break;
		add_history(line);
		token = get_token(line);
		print_token(token);
		free(line);
	}
	return (0);
}

// void compare_tokens()
// {
// 	if(token1)
// 	if(tokenn)
// 	if(token1)
// 	if(token1)
// 	if(token1)
// 	if(token1)
// 	if(token1)
// 	if(token1)
// }

// void compare_tokens()
// {
// 	if(token1)
// 	if(tokenn)
// 	if(token1)
// 	if(token1)
// }



// typedef int (*t_ptr_fn)(void *param1, void *param2, void *param3, void *param4);

// t_ptr_fn table[]=
// {
// 	[TOKEN_HEREDOC] = "helloi",
// 	[TOKEN_PIPE] =" welcome";
// }


// table[TOKEN_CURR](param1, param2....);