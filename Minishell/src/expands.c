/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:01:34 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/04 12:51:06 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*append_char(char *result, char c)
{
	char	buf[2];
	char	*tmp;

	buf[0] = c;
	buf[1] = '\0';
	tmp = ft_strjoin(result, buf);
	free(result);
	return (tmp);
}

static char	*append_expansion(char *result, char *exp)
{
	char	*tmp;

	tmp = ft_strjoin(result, exp);
	free(result);
	free(exp);
	return (tmp);
}

void	expand_tokens(t_token *tok, t_shell *sh)
{
	char	*new;

	while (tok)
	{
		if (tok->type == TOKEN_WORD && !tok->single_quoted)
		{
			new = expand_word(tok->value, sh);
			free(tok->value);
			tok->value = new;
		}
		tok = tok->next;
	}
}

char	*expand_word(char *word, t_shell *sh)
{
	char	*result;
	char	*exp;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (word[i])
	{
		if (word[i] == '$')
		{
			exp = expand_dollar(word, &i, sh);
			result = append_expansion(result, exp);
		}
		else
		{
			result = append_char(result, word[i]);
			i++;
		}
	}
	return (result);
}

char	*expand_dollar(char *word, int *i, t_shell *sh)
{
	char	*name;
	char	*value;
	int		start;

	(*i)++;
	if (word[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(sh->last_status));
	}
	if (!ft_isalpha(word[*i]) && word[*i] != '_')
		return (ft_strdup("$"));
	start = *i;
	while (ft_isalnum(word[*i]) || word[*i] == '_')
		(*i)++;
	name = ft_substr(word, start, *i - start);
	value = get_var_value(name, sh);
	free(name);
	return (value);
}
