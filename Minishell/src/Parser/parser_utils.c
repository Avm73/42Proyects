/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:08:12 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/04 13:05:19 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_assignment_word(const char *s)
{
	int	i;

	if (!s || (!ft_isalpha(s[0]) && s[0] != '_'))
		return (0);
	i = 1;
	while (s[i] && (ft_isalnum(s[i]) || s[i] == '_'))
		i++;
	return (s[i] == '=');
}

char	**grow_array(char **arr, int count)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (count + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new[i] = arr[i];
		i++;
	}
	new[count] = NULL;
	new[count + 1] = NULL;
	free(arr);
	return (new);
}

char	*merge_words(t_token **tok)
{
	char	*result;
	char	*tmp;
	t_token	*t;

	result = ft_strdup((*tok)->value);
	t = *tok;
	while (t->next && t->next->type == TOKEN_WORD)
	{
		tmp = ft_strjoin(result, t->next->value);
		free(result);
		result = tmp;
		t = t->next;
	}
	*tok = t;
	return (result);
}
