// ajouter le header 42

#ifndef FT_MACROS_H
# define FT_MACROS_H

# define OR ||
# define AND &&

typedef enum e_bool			t_bool;
typedef enum e_exit			t_exit;

// FALSE 0, TRUE 1
enum e_bool
{
	FALSE,
	TRUE
};

// SUCCESS 0, ERROR 1
enum e_exit
{
	SUCCESS,
	ERROR
};

#endif
