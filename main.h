#ifndef MAIN_H
#define MAIN_H

/* Headers */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <signal.h>

/* Macros */
#define BUFFER_SIZE 5024
#define MAX_ARGS 1024
#define MAX_NUM_Aliases 100
#define UNUSED  __attribute__((unused))

static char *cmd __attribute__((unused));
extern char **environ UNUSED;
extern int ex_code;


/**
* struct Node - singly linked list
* @str: string - (malloc'ed string)
* @next: points to the next node
*/
struct Node
{
	char *str;
	struct Node *next;
};

static struct Node *new_node(char *str) UNUSED;
/**
 * new_node - Creates a new node for a linked list
 * @str: String value to be stored in the new node
 * Return: Pointer to the newly created node
 */
static struct Node *new_node(char *str)
{
	struct Node *node = malloc(sizeof(struct Node));

	if (node == NULL)
		return (NULL);

	node->str = str;
	node->next = NULL;
	return (node);
}

static void add_node(struct Node **head, struct Node *node) UNUSED;
/**
 * add_node - Adds a node to the end of a linked list
 * @head: Pointer to the head of the linked list
 * @node: Node to be added to the linked list
 */
static void add_node(struct Node **head, struct Node *node)
{
	if (*head == NULL)
		*head = node;
	else
	{
		struct Node *current = *head;

		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}


/**
 * struct alias_s - a structure representing an alias
 * @name: the name of the alias
 * @value: the value of the alias
 * @next: a pointer to the next alias in the linked list
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;



/* Functions Prototypes */
char *getline_cust(void);
char *read_stdin_input(void);
void remove_comment_hash(char *buff);
int str_cmp(const char *str1, const char *str2);
int str_len(const char *str);
int strn_cpy(char *dest, char *src, int size);
void *mem_cpy(void *dest, void *src, size_t n);
void *realloc_cust(void *ptr, size_t size);
char *find_executable(char *command);
char *str_tok(char *str, char const *delim);
char *get_env(char *str);
int strn_cmp(const char *str1, const char *str2, size_t len);
int str_cpy(char *dest, char *src);
char *str_cat(char *dest, const char *src);
char *str_dup(char *s);
void rmv_all_part_space(char *str);
void tokenize_str(char *command, char *argv[MAX_ARGS]);
int num_args(char *argv[]);
void _exec(char **_argum, char *av, int count);
int _1exit(char *status __attribute__((unused)), int c, char *a, char **ag);
int _atoi(const char *str);
void cd(char *path);
int process_command(char **argv);
void init_standard_aliases(alias_t **aliases);
int alias_cmd_exec(char *argv[MAX_ARGS], int num_arg __attribute__((unused)));
char *str_chr(const char *str, int character);
void print_alias(alias_t *alias);
void set_new_alias(alias_t **aliases, char *name, char *value);
void print_all_aliases(alias_t *aliases);

void execve_cust(char *c, char **p, char **r);
void print_error(char *err, int count, char *c);
void print_cust(char *s);
void print_number(int n);
int putchar_cust(char c);
int access_file_check(char **arg, char *cmd, char *err, int c, char **e);
void print_errore(char *err, int count, char *c, char *arg);
void print_llist(struct Node *head);
void free_llist(struct Node *head);
int env_cust(void);
int unsetenv_cust(const char *name);
int setenv_cust(const char *name, const char *value);
void add_new_env_var(struct Node **head, const char *name, const char *value);
void update_env(struct Node *head);
void sigint_handle(int signo __attribute__((unused)));
void rmwspaces(char *s);
int white_space(char s);



#endif /* MAIN_H */
