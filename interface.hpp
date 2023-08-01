#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <iostream>
#include <string>

#define	RED "\033[1;31m"
#define	GREEN "\033[1;32m"
#define	YELLOW "\033[1;33m"
#define	BLUE "\033[1;34m"
#define	MAGENTA "\033[1;35m"
#define	CYAN "\033[1;36m"
#define	WHITE "\033[1;37m"
#define	GREY "\033[1;90m"
#define	RESET "\033[0m"

#define LOG 1

#define PRINT(x) std::cout << x << std::endl
#define PRINT_ERROR(x) std::cout << RED << x << RESET << std::endl

#ifdef LOG
# define PRINT_LOG(x) do {\
  std::cerr << GREY;\
  std::cerr << x << std::endl;\
  std::cerr << RESET;\
} while (false)
# else
# define PRINT_LOG(x) do {} while (false)
#endif

#endif