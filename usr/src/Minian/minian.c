#define minian_RL_BUFSIZE 1024
void minian_loop(void)
{
  char *line;
  char **args;
  int status;

  do 
  {
    printf("> ");
    line = minian_read_line();
    args = minian_split_line(line);
    status = minian_execute(args);

    free(line);
    free(args);
  } while (status);
}
char *minian_read_line(void)
{
  char *line = NULL;
  int64_t bufsize = 0; // have getline allocate a buffer for us

  if (getline(&line, &bufsize, stdin) == -1){
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);  // We recieved an EOF
    } 
    else  
    {
      fputs("read error\n", stderr);
      exit(EXIT_FAILURE);
    }
  }
  return line;
}
#define minian_TOK_BUFSIZE 64
#define minian_TOK_DELIM " \t\r\n\a"
char **minian_split_line(char *line)
{
  int bufsize = minian_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) 
  {
    fprintf(stderr, "minian: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, minian_TOK_DELIM);
  while (token != NULL) 
  {
    tokens[position] = token;
    position++;

    if (position >= bufsize) 
    {
      bufsize += minian_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) 
      {
        fprintf(stderr, "minian: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, minian_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}
int minian_launch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) 
  {
    // Child process
    if (execvp(args[0], args) == -1) 
    {
      fprintf(stderr, "%s: command not found\n", args[0]);
    }
    exit(EXIT_FAILURE);
  } 
  else if (pid < 0) 
  {
    perror("fork");
  } 
  else 
  {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}
int minian_cd(char **args)
{
  if (args[1] == NULL) 
  {
    fprintf(stderr, "minian: expected argument to \"cd\"\n");
  } 
  else 
  {
    if (chdir(args[1]) != 0) 
    {
      perror("cd");
    }
  }
  return 1;
}
