#define BUFBUMP 1024
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>

char *read_line(void){
  int bufsize = BUFBUMP;
  int position = 0;
  char *carray = malloc(sizeof(char) * bufsize);
  char c;
  if (!carray) {
    fprintf(stderr, "allocation error\n");
    exit(EXIT_FAILURE);
  }
  while (1) {
    // Read a character
    c = getchar();
    // If we hit EOF, replace it with a null character and return.
    if (c == EOF || c == '\n') {
    //**PUT YOUR CODE HERE (1 line)**
    // this will put \0 charachter there so 
    // the system now know where the input is ended.
    carray[position] = '\0';
    return carray;
  } else {
    carray[position] = c;
  }
  position++;
  // If we have exceeded the carray, reallocate.
  if (position >= bufsize) {
    bufsize += BUFBUMP;
    carray = realloc(carray, bufsize);
    if (!carray) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
    }
  }
 }
}

char **split_line(char *line){
  char **tokens = malloc(sizeof(char) * BUFBUMP);
  char *token;
  int i = 0;
  token = strtok(line, " ");
  while(token != NULL){
	printf("%s\n", token);
	tokens[i] = token;
	token = strtok(NULL, " ");
	i++;
	if (i >= BUFBUMP) {
        int bufsize = bufsize +  BUFBUMP;
     	  tokens = realloc(tokens, bufsize * sizeof(char*));
          if (!tokens) {
            fprintf(stderr, "lsh: allocation error\n");
            exit(EXIT_FAILURE);
          }
        }
  }
  tokens[i] = NULL;
  return tokens;
}

int execute(char **args){
  pid_t pid, wpid;
  int status;
  if(strcmp(args[0],"exit") == 0) return 0;
  pid = fork();
  if(!pid){
    execvp(args[0], args);
    exit(EXIT_FAILURE);
  }else{
    do{
      wpid = waitpid(pid, &status, WUNTRACED);
    }while(!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

void shell(){
  char *line;
  char** tokens;
  int status = 0;
  do{
    printf("csis> ");
    line = read_line();
    tokens = split_line(line);
    status = execute(tokens);
    printf("\n");
  }while(status);
}

int main(){
  shell();
  return 0;
}
