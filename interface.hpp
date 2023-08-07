#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <iostream>
#include <string>

#define	RED "\033[1;31m"
#define	GREEN "\033[1;32m"
#define	YELLOW "\033[1;93m"
#define	BLUE "\033[1;34m"
#define	MAGENTA "\033[1;35m"
#define	CYAN "\033[1;36m"
#define	WHITE "\033[1;37m"
#define	GREY "\033[1;90m"
#define	RESET "\033[0m"

#define LEVEL_NONE 0
#define LEVEL_ERROR 1
#define LEVEL_WARNING 2
#define LEVEL_LOG 3
#define PRINT_LEVEL LEVEL_LOG

#define PRINT(x) std::cout << x << std::endl

#if PRINT_LEVEL >= LEVEL_LOG
# define PRINT_LOG(x) do {\
  std::cerr << GREY;\
  std::cerr << x << std::endl;\
  std::cerr << RESET;\
} while (false)
# else
# define PRINT_LOG(x) do {} while (false)
#endif

#if PRINT_LEVEL >= LEVEL_WARNING
# define PRINT_WARNING(x) do {\
  std::cerr << YELLOW;\
  std::cerr << x << std::endl;\
  std::cerr << RESET;\
} while (false)
# else
# define PRINT_WARNING(x) do {} while (false)
#endif

#if PRINT_LEVEL >= LEVEL_ERROR
# define PRINT_ERROR(x) do {\
  std::cerr << RED;\
  std::cerr << x << std::endl;\
  std::cerr << RESET;\
} while (false)
# else
# define PRINT_ERROR(x) do {} while (false)
#endif




#endif