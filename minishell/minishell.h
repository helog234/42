/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:59:42 by hgandar           #+#    #+#             */
/*   Updated: 2024/04/26 20:10:01 by hgandar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdbool.h>
# include <signal.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h> 
# include <string.h>
# include <termios.h>
# include <dirent.h>

# define DEBUG
# define ST_EQ '='
# define STOP_AT_ENDSTR '\0'

# define EXPORT_FLAG 1
# define NOT_EXPORTED 0
# define EQUAL_FLAG 1
# define PIPE_FLAG 1
# define FD_NOT_SET -1
# define STDOUT 1
# define BOTH_PIPES 0
# define PIPE_A 1
# define PIPE_B 2
# define HEREDOC_FLAG -2
# define CHILD_FLAG 1
# define PARENT_WO_CHILD 0
# define PARENT_WITH_CHILD -1

typedef enum e_token_type
{
	BUILT_IN = 1,
	CMD,
	FILES,
	REDIR,
	ARG,
	UNDEF
}	t_token_type;

typedef struct s_env
{
	int				i_sort;
	char			*name;
	char			*value;
	int				exported_flag;
	int				equal_flag;
	struct s_env	*prev;
	struct s_env	*next;
}				t_env;

typedef struct s_word
{
	int		start;
	int		end;
	char	*data;
}				t_word;

typedef struct s_file
{
	int		fd;
	char	*limiter;
	char	*data;
	char	*path_to_file;
	char	*pwd;
}				t_file;

typedef struct s_redir
{
	int		fd_in;
	int		fd_out;
	t_file	*heredoc;
	char	*limiter;
	char	*content;
	char	*data;
}				t_redir;

typedef struct s_arg
{
	char			*data;
	int				index;
	bool			flag;
	struct s_arg	*prev;
	struct s_arg	*next;
}				t_arg;

typedef struct s_cmd
{
	int		fd;
	char	*path_to_cmd;
	char	*data;
	t_arg	*first_arg;
}				t_cmd;

typedef struct s_token
{
	void			*type;
	int				class;
	struct s_token	*prev;
	struct s_token	*next;
	bool			needs_file;
	bool			dollar;
	t_word			*word;
}				t_token;

typedef struct s_var
{
	char			*name;
	char			*value;
	struct s_var	*prev;
	struct s_var	*next;
}			t_var;

typedef struct s_exe
{
	t_token	*lst_cmd;
	int		fd_pipe_a[2];
	int		fd_pipe_b[2];
	int		*pids;
	int		no_pipes;
}				t_exe;

typedef struct s_f_err
{
	char			*err_msg;
	int				err_num;
	struct s_f_err	*next;
}				t_f_err;

typedef struct s_clean
{
	int		i;
	int		j;
	int		exit_status;
	char	target;
	t_token	*token;
	char	*file_error;
	int		err_num;
	t_token	**head;
	size_t	size;
	bool	in_single_quote;
	bool	in_double_quote;
	char	*line;
	t_env	*env;
	char	*path_history;
}			t_clean;

// env.c
void	save_env(t_env **ms_env, char **env);
void	print_env(t_env **env, int export_flag);
void	print_export(t_env *curr);
void	add_variable(t_env **env, char *new_var, int i, int export_flag);
void	handle_variable(t_env **env, char *var_new, int export_flag);

// tools_env_lst.c
void	lstadd_back(t_env **lst, t_env *new);
t_env	*lstnew(char *content);
t_env	*lstlast(t_env *lst);
int		lstsize(void *lst, int type_flag);
void	lstremove(t_env **lst, char *var);

// tools_env_lst2.c
t_env	*find_var(t_env *env, int index, char *var);
void	rm_node(t_env *curr, t_env **lst);
void	lstremove(t_env **lst, char *var);
void	init_i_sort(t_env **lst);
void	free_lst_env(t_env **env);

// tools_env.c
char	*get_substr(char *str, int *start, char stop);
void	sort_env(t_env **env);
void	update_variable(t_env **env, int i, char *var_new, int export_flag);

// history.c
void	load_history(char *path);
void	history_log(char *line, char *path);

// signal_handeling.c
void	handle_signal_child(int signal);
void	handle_signal_wo_child(int signal);
void	handle_signal_heredoc(int signal);
void	handle_signal(struct sigaction *sa, t_token *head);
void	set_signals(t_token *head, int flag);

// set_prompt.c
bool	line_is_empty(char **line);
char	*get_line(t_clean *utils);
t_clean	*init_clean_utils(t_clean *utils, t_token \
**head, t_env *env, char *path);
int		set_prompt(t_env *ms_env, t_token **head, char *path_history);
int		set_prompt2(t_clean *utils, char *line, \
int *exec_status, t_env *ms_env);

// parsing.c
t_token	*set_arg(t_token *token, t_token *tmp);
void	parse_line(char *line, t_clean *utils);
int		init_parsing(char *line, t_clean *utils);

// tokens_lst.c
int		next_word(char *line, int i);
t_token	*add_token(t_token *previ, int w_start, int w_end);
t_token	*create_lst(int start, int end, t_token	*token, t_token **head);

// parse_line.c
int		get_limiter(char *line, int i, int start);
int		handle_redir(int start, int i, char *line);
int		is_word_str(char *str, int start);

// ctr_input_utils
char	*add_back_line(char *add, char *line);
int		check_unclosed_pipe(int i, char *str);
int		check_unclosed_quote(int i, char *str);
int		check_quote_and_pipe(char *str);
t_cmd	*get_token_cmd(t_token *token);

// check_data.c
int		is_separator(char c);
int		is_quote(char c);
int		is_str(int start, char *str);
int		is_flag(char *str, t_token *token);
char	*is_capital(char *str);

// get_char_str.c
int		get_pipe_char(char *line, int i, int start);
int		get_quote_char(char *line, int i);
int		get_dollar_str(char *line, int i);
int		is_left_redir(char c);
int		is_right_redir(char c);

// token.c
void	init_token(char *str, int flag, t_token *token, t_env *env);
char	*check_line(char *line, t_token *token, t_clean *utils);
t_token	*get_first_cmd(t_token *token);
void	define_token(char *arg, t_token *token, t_clean *utils);

// run_line.c
void	run_single_quote(char **result, int *i, int *j, t_clean *utils);
void	run_double_quote(int *i, t_clean *utils);
void	prep_dollar(char **result, int *i, int *j, t_clean *utils);
char	*run_line(int *i, int *j, t_clean *utils, t_token *token);

//check_dollar.c
char	*copy_arg(int len, int *i, t_clean *utils);
void	get_last_exit_code(char **result, int *i, int *j, t_clean *utils);
void	get_cmd_dollar(char **result, int *i, int *j, t_clean *utils);
bool	check_expansion(char *expanded, char **result, int *j, t_clean *utils);
void	expand_dollar(char **result, int *i, int *j, t_clean *utils);

// handle_dollar.c
void	get_previous_cmd(t_env *env, char **str);
char	*env_last_cmd(t_env *env);
char	*dollar_expansion(char *str, t_env *env);
void	manage_special_dollar(char *var_name, char *old_str, \
		char **str, t_clean *utils);
void	handle_dollar(char **str, t_env *env, int start, t_clean *utils);

// check_data_2.c
int		is_dollar(char *str);
bool	is_heredoc_separator(char c);
bool	exp_separ(char c);
bool	is_special_dollar(char *str, t_clean *utils);
bool	is_dollar_question_mark(char *str, int i);

// is_token_type.c
int		is_redir(char *data);
bool	is_built_in(char *lower, char *data);
int		is_cmd(char *data, t_env *env, t_token *token);
int		is_arg(char *str, t_token *token);
int		read_cmd_special(t_token *token);

// init_type.c
t_cmd	*init_cmd(char *str, t_token *token, t_env *env);
t_redir	*init_redir(char *str, t_token *token);
t_file	*init_file(char *str, t_token *token);
void	set_arg_in_place(char *str, t_token *token, t_arg *arg);
t_arg	*init_arg(char *str, t_token *token, t_env *env);

// add_type.c
t_arg	*add_arg(char *str, t_token *token);
t_cmd	*add_cmd(t_token *token, t_cmd	*cmd);
t_redir	*add_redir(t_token *token, t_redir *redir);

// utils_type.c
char	*here_doc_sub(char *str, t_redir *redir);
t_word	*init_word(int begin, int stop);
void	place_arg(t_arg *arg, t_cmd *cmd);
char	*get_file_path(char **str);

// path.c
void	free_paths(char **all);
char	*get_path(char *cmd, char *env_paths[]);
char	*extract_path(t_env *env, char *cmd);
char	*ft_strstr(const char *hstack, const char *needle);

// syntax.c
void	ctr_file_error(t_clean *utils, int *i);
int		check_invalid_token(t_redir *redir, t_clean *utils);
bool	read_cmd(t_clean *utils, t_token **token);
int		check_redir(int flag, t_clean *utils);
int		check_syntax(t_clean *utils);

// check_intput.c
t_token	*add_new_arg_read(t_token *cmd_token, t_env *env);
t_token	*add_new_arg(t_token **cmd_token, t_arg *arg);
void	manage_grep_cat(t_clean *utils);
bool	manage_reconversion(t_token **token);
void	set_error(t_clean *utils, char *err_msg);

// set_redir.c
void	input_file(t_file *file, t_redir *redir, t_clean *utils);
void	output_file(t_file *file, t_redir *redir, t_clean *utils, int flag);
void	set_fd(t_file *fd, t_redir *redir, t_clean *utils);
void	set_heredoc(t_redir *redir, t_file *tmp, t_env *env, \
		t_clean *utils);
void	open_output(int flag, t_file *file);

// global_utils.c
bool	is_pipe(t_token *token);
t_token	*get_last(t_token *head);
void	ft_put_nbr(int n, char **str, char *old_str);
void	strjoin_andfree(char **line, char *str);
void	set_message_err(t_clean *utils, char *err_msg, t_file *file);

// errors.c
void	error_message(int flag, char *file);
void	error_return_prompt(t_clean *utils, int flag, char *c);
void	errors_execution(t_env **env, t_token *lst_token, int flag);
void	error_execve(char *cmd, char *slash);
void	errors(t_token *curr, int flag);

// free_token.c
void	free_redir(t_token *token);
void	free_types_data(t_token *token);
void	free_one_token(t_token **curr, bool flag);
void	free_tokens(t_token *curr);
void	free_utils(t_clean *utils);

// free_data_type.c
void	free_cmd(t_token *token);
void	free_redir(t_token *token);

// print_utils.c
// void	print_types_data(t_token *token);
// void	print_list(t_token *token);

// check_heredoc.c
void	gnl_argv(t_file *file, t_env *env, t_clean *utils);
void	clean_heredoc(char **line, t_env *env, t_clean *utils);
void	heredoc_dollar(char **word, t_env *env, t_clean *utils);
void	ignore_ctrld(struct termios *original_term);
void	restore_ctrld(struct termios *original_term);

// execution.c
int		execution(t_env **env, t_token *lst_cmd);
int		exec_bi(t_env **env, t_token *cmd_bi);
void	init_exec(t_exe *data, t_token *lst_token);
int		forking(t_exe *data, int i, t_env **env);
int		exec_exit(t_env **env, t_token *lst_token);

// tools_exec.c
int		get_no_pipe(t_token *lst_token);
int		open_pipes(t_exe *data, int flag);
char	*form_err_msg(char *s1, char *s2, char *s3);
void	update_last_cmd(t_env **env, char *val);
char	*get_last_cmd(t_token *lst);

// tools_exec2.c
int		check_dir(t_env **env, t_cmd *cmd);
void	set_parent_pipes(t_exe *data, int i);
char	*update_value(t_env *curr_env, char *temp, char *slash);
void	verify_cmd(t_token *curr_cmd, t_env **env);
int		all_vars(t_token **lst_token);

// tools_exec3.c
int		has_special_char(char *str);
void	handle_var_arg(char *function, char *data);
int		get_exit_code(int code);
bool	builtin_to_exec(t_token *lst_token);
int		catch_error(int wstatus, t_token *lst_token, t_env **env);

// tools_exec4.c
t_cmd	*verifications(char **slash, t_token *curr_cmd, t_env **env);
void	handle_exit_error(char *arg, int *exit_code);
char	*find_last_arg(t_cmd *cmd);

// exec_exp_unset.c
void	exec_export(t_env **env, t_token cmd_export);
int		exec_var(t_env **env, t_token *lst_token);
int		exported_var(t_arg *curr_arg, t_env **env);
int		exec_unset(t_env **env, t_arg *lst_var);
void	remove_exported_flag(t_env **env, char *var);

// exec_cd_pwd.c
int		exec_cd(t_env **env, t_token cmd_cd);
int		change_dir(t_env **env, char *new_path);
void	get_parent_dir(char **arg_data);
void	exec_pwd(t_env **env, t_token cmd_pwd);
int		exec_demi_cd(t_env **env, t_token cmd_cd);

// exec_env_echo.c
int		exec_env(t_env **env, t_token cmd_env);
void	exec_echo(t_env **env, t_token cmd_echo);

// child_process.c
t_token	*set_redir(t_exe *data, int i);
void	set_i_o(t_token *token, int pipe, int std);
t_token	*get_cmd(t_token *lst_token);
char	**get_exec_cmd(t_cmd *cmd);
char	**get_exec_env(t_env *env, char *slash);

// tools_child_proc.c
bool	is_redir_in(t_token *token);
bool	is_redir_out(t_token *token);
void	do_redir(int pipe, int std);
int		find_redir(t_token *token, int pipe, int std);
void	close_pipes(t_exe *data, int flag);

// tools_child_proc2.c
// void	verify_minishell(t_token *t_redir);
void	verify_msh(t_cmd *cmd, char *slash);
void	set_pipes(int i, int (*pipe_used)[2], t_exe *data);

#endif
