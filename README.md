# minishell1
Remake of the tcsh terminal

Functions created by me:

-cd :

  cd + folder in current directory
  
  cd + folder in directory specified by ../../etc
  
  cd + / (starts from usr root)
  
  cd + ~ (starts from usr home)
  
  cd / cd -- / cd ~ / cd home --> changes dir to home dir
  

-env :

  - setenv + name + value (creates a new env variable with a name and value)
  
  - setenv + name (creates a new env variable with a name and value)
  
  - setenv (prints env)
  
  - env (displays env)
  
  - unsetenv + name (unsets variable from env)
  
  - unsetenv + name_1 + name_2... name_n (unsets all given variables from env)
  
 
 You can also execute files that are in a directory by providing the path to said file e.g: ./a.out
 
 You can run system functions that are in the env path variable such as ls, echo, etc.
