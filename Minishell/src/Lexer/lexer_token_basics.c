/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_basics.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:28:58 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/10 11:47:50 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_new(t_token_type type, char *value)
{
	t_token	*tok;

	tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->type = type;
	tok->value = value;
	tok->single_quoted = 0;
	tok->double_quoted = 0;
	tok->concat = 0;
	tok->next = NULL;
	return (tok);
}

void	token_add_back(t_token **list, t_token *new)
{
	t_token	*tmp;

	if (!*list)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_token	*get_last_token(t_token *tokens)
{
	t_token	*t;

	t = tokens;
	if (!t)
		return (NULL);
	while (t->next)
		t = t->next;
	return (t);
}

void	merge_concat_tokens(t_token **tokens)
{
	t_token	*t;
	t_token	*next;
	char	*joined;

	if (!tokens || !*tokens)
		return ;
	t = *tokens;
	while (t && t->next)
	{
		if (t->concat == 1)
		{
			next = t->next;
			joined = ft_strjoin(t->value, next->value);
			free(t->value);
			t->value = joined;
			t->concat = next->concat;
			t->next = next->next;
			free(next->value);
			free(next);
		}
		else
			t = t->next;
	}
}
