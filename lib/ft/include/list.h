
#ifndef LIST_H
# define LIST_H

typedef struct s_list	t_list;

struct		s_list
{
	char	data;
	t_list	*next;
};

#endif
