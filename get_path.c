#include "shell.h" 
#include <sys/stat.h>


char *_getenv(char *path_name) 
{ 
  char **environ_cursor, *env_ptr, *name_ptr; 
  
  environ_cursor = environ; 
  while (*environ_cursor) 
    { 
      env_ptr = *environ_cursor; 
      name_ptr = path_name; 
      while (*env_ptr == *name_ptr) 
	{ 
	  if (*env_ptr == '=') 
	    break; 
	  env_ptr++; 
	  name_ptr++; 
	} 
      if ((*env_ptr == '=') && (*name_ptr == '\0')) 
	return (env_ptr + 1); 
      environ_cursor++; 
    } 
  return (NULL); 
}

int get_path(char* argv)
{
	char *ptr = _getenv("PATH");
	char *ptr1;
	int n = 0;
	char *arg[10];

	ptr1 = strtok(ptr, ":");
	while(ptr1)
	{
		arg[n] = ptr1;
		n++;
		printf("PATH : %s\n", ptr1);
		ptr1= strtok(NULL, ":");
	}
	struct stat st;
	size_t i = 0;

	while(arg[i])
	{
		if ((stat(arg[i], &st)) == 0)
			break;
		i++;
	}

	printf("PATH YOU SEEK IS: %s\n", arg[0]);
  return 0;
}

int main(int argc, char *argv[], char *envp[])
{
	get_path(argv[1]);

return (0);
}

/**
 * main - a fubction that locate the path to a dike in the environ.
 * @argc: vector count
 * @argv: vector array pointer to strings
 * @envp: environ variable
 * Return: pointer to part.
 */

