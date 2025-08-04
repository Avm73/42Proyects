typedef enum e_token_type {
	TOK_WORD,
	TOK_PIPE,
	TOK_REDIR_IN,
	TOK_REDIR_OUT,
	TOK_HEREDOC,
	TOK_APPEND,
	TOK_EOF,
	TOK_ERROR
}	t_token_type;


typedef struct s_token {
	t_token_type	type;
	char			*value;
    struct s_token  *next
}	t_token;

typedef enum e_lex_state {
	LEX_GENERAL,    // leyendo palabras
	LEX_IN_SQUOTE,  // dentro de comillas simples
	LEX_IN_DQUOTE,  // dentro de comillas dobles
	LEX_REDIR,  // leyendo redirecciones
	LEX_ERROR
}	t_lex_state;

t_token	*lexer(const char *input)
{
	t_lex_state	state = LEX_GENERAL;
	t_token		*tokens = NULL;

	while (*input)
	{
		if (state == LEX_GENERAL)
			handle_general(&input, &tokens, &state);
		else if (state == LEX_IN_SQUOTE)
			handle_squote(&input, &tokens, &state);
		else if (state == LEX_IN_DQUOTE)
			handle_dquote(&input, &tokens, &state);
		else if (state == LEX_REDIR)
			handle_redir(&input, &tokens, &state);
		else
			break; // error o fin
	}
	return tokens;
}

void handle_general(const char **input, t_token **tokens, t_lex_state *state)
{
	char buffer[1024];
	int i = 0;

	while (**input && !isspace(**input))
	{
		if (**input == '\'')
		{
			*state = LEX_IN_SQUOTE;
			(*input)++;
			return;
		}
		else if (**input == '"')
		{
			*state = LEX_IN_DQUOTE;
			(*input)++;
			return;
		}
		else if (**input == '|')
		{
			add_token(tokens, TOK_PIPE, strdup("|"));
			(*input)++;
			return;
		}
		else if (**input == '<' || **input == '>')
		{
			*state = LEX_REDIR;
			return;
		}
		else if (isspace(**input))
			break;

		buffer[i++] = **input;
		(*input)++;
	}
	if (i > 0)
	{
		buffer[i] = '\0';
		add_token(tokens, TOK_WORD, strdup(buffer));
	}
	while (**input && isspace(**input))
		(*input)++; // salta espacios
}

void handle_squote(const char **input, t_token **tokens, t_lex_state *state)
{
	char buffer[1024];
	int i = 0;

	while (**input && **input != '\'')
	{
		buffer[i++] = **input;
		(*input)++;
	}
	if (**input == '\'')
		(*input)++; // cerrar comilla

	buffer[i] = '\0';
	add_token(tokens, TOK_WORD, strdup(buffer));
	*state = LEX_GENERAL;
}

void handle_dquote(const char **input, t_token **tokens, t_lex_state *state)
{
	char buffer[1024];
	int i = 0;

	while (**input && **input != '"')
	{
		buffer[i++] = **input;
		(*input)++;
	}
	if (**input == '"')
		(*input)++; // cerrar comilla

	buffer[i] = '\0';
	add_token(tokens, TOK_WORD, strdup(buffer));
	*state = LEX_GENERAL;
}

void handle_redir(const char **input, t_token **tokens, t_lex_state *state)
{
	t_token_type type;
	char *token_val;

	if (**input == '>' && *(*input + 1) == '>')
	{
		type = TOK_APPEND;
		token_val = strdup(">>");
		(*input) += 2;
	}
	else if (**input == '<' && *(*input + 1) == '<')
	{
		type = TOK_HEREDOC;
		token_val = strdup("<<");
		(*input) += 2;
	}
	else if (**input == '>')
	{
		type = TOK_REDIR_OUT;
		token_val = strdup(">");
		(*input)++;
	}
	else if (**input == '<')
	{
		type = TOK_REDIR_IN;
		token_val = strdup("<");
		(*input)++;
	}
	else
	{
		*state = LEX_ERROR;
		return;
	}

	add_token(tokens, type, token_val);
	while (**input && isspace(**input))
		(*input)++;
	*state = LEX_GENERAL;
}
