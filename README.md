*This project has been created as part of the 42 curriculum by pkruszyn*

# Libft
 
## Description
 
Libft is a custom C library that reimplements a set of standard `libc` functions
(prefixed with `ft_`) and adds a collection of additional string, memory, and
linked-list utility functions. The goal of the project is to build a solid
understanding of how these fundamental functions work under the hood, and to
produce a reusable toolbox for future C projects at 42.
 
The library is split into three parts:
- **Part 1** — reimplementation of standard `libc` functions.
- **Part 2** — additional string/array utility functions (not present in `libc`,
  or present in a different form).
- **Part 3** — a singly linked list (`t_list`) and its manipulation functions.
## Instructions
 
### Build
 
```bash
make        # builds libft.a in the root of the repository
make clean  # removes .o files
make fclean # removes .o files and libft.a
make re     # fclean + all
```
 
### Use in your own project
 
```bash
cc your_file.c -I/path/to/libft -L/path/to/libft -lft -o your_program
```
 
Make sure `libft.h` is reachable via `-I` and `libft.a` via `-L`.
 
```c
#include "libft.h"
```
 
## Resources
 
- The [Linux man-pages project](https://man7.org/linux/man-pages/) — used to look
  up exact prototypes and behaviors for every Part 1 function (`man 3 <function>`).
- [cppreference.com](https://en.cppreference.com/w/c) — C standard library reference,
  used to double check edge-case behaviors (e.g. `strlcpy` return value, `calloc`
  overflow handling).
- 42 Libft subject PDF — the source of truth for prototypes, return values, and
  the `t_list` structure.
### AI usage
 
An AI assistant (Claude) was used to assist in:
- Structuring and formatting this README.md document.
- Help design test cases.
- Explain Makefile mechanics (pattern rules, automatic variables, dependency
  tracking) so I could write and understand my own Makefile rather than copying one.
All function logic was written and typed by hand; the AI's role was limited to
explanation, code review, and test-case suggestions.
 
## Library content
 
Complexity notation below refers to **n = length of the relevant input**
(string length, or number of bytes/elements processed), unless stated otherwise.
 
### Part 1 — Libc functions
 
| Function | Description | Complexity |
|---|---|---|
| `ft_isalpha` | Checks if `c` is a letter (a-z, A-Z) | O(1) |
| `ft_isdigit` | Checks if `c` is a digit (0-9) | O(1) |
| `ft_isalnum` | Checks if `c` is a letter or digit | O(1) |
| `ft_isascii` | Checks if `c` is in the ASCII range (0-127) | O(1) |
| `ft_isprint` | Checks if `c` is printable (32-126) | O(1) |
| `ft_strlen` | Returns the length of a string | O(n) |
| `ft_memset` | Fills a memory block with a byte value | O(n) |
| `ft_bzero` | Zeroes out `n` bytes of a memory block | O(n) |
| `ft_memcpy` | Copies `n` bytes from `src` to `dst` (non-overlapping) | O(n) |
| `ft_memmove` | Copies `n` bytes from `src` to `dst`, safe for overlapping buffers | O(n) |
| `ft_strlcpy` | Copies a string into a buffer with a size limit | O(n) |
| `ft_strlcat` | Appends a string to a buffer with a size limit | O(n) |
| `ft_toupper` | Converts a lowercase letter to uppercase | O(1) |
| `ft_tolower` | Converts an uppercase letter to lowercase | O(1) |
| `ft_strchr` | Finds the first occurrence of a character in a string | O(n) |
| `ft_strrchr` | Finds the last occurrence of a character in a string | O(n) |
| `ft_strncmp` | Compares two strings up to `n` characters | O(n) |
| `ft_memchr` | Finds the first occurrence of a byte in `n` bytes of memory | O(n) |
| `ft_memcmp` | Compares `n` bytes of two memory blocks | O(n) |
| `ft_strnstr` | Finds a substring within the first `len` bytes of a string | O(n·m)* |
| `ft_atoi` | Converts a string to an integer | O(n) |
| `ft_calloc` | Allocates and zero-initializes memory for an array | O(n) |
| `ft_strdup` | Allocates and returns a copy of a string | O(n) |
 
\* where `n` = length of `haystack` and `m` = length of `needle` (naive search).
 
### Part 2 — Additional functions
 
| Function | Description | Complexity |
|---|---|---|
| `ft_substr` | Returns a newly allocated substring of `s` | O(len) |
| `ft_strjoin` | Concatenates two strings into a newly allocated string | O(n + m) |
| `ft_strtrim` | Trims a set of characters from both ends of a string | O(n) |
| `ft_split` | Splits a string into an array of strings using a delimiter | O(n) |
| `ft_itoa` | Converts an integer to a newly allocated string | O(digits) |
| `ft_strmapi` | Applies a function to each character, building a new string | O(n) |
| `ft_striteri` | Applies a function to each character in place | O(n) |
| `ft_putchar_fd` | Writes a character to a file descriptor | O(1) |
| `ft_putstr_fd` | Writes a string to a file descriptor | O(n) |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor | O(n) |
| `ft_putnbr_fd` | Writes an integer to a file descriptor | O(digits) |
 
### Part 3 — Linked list (`t_list`)
 
```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```
 
| Function | Description | Complexity |
|---|---|---|
| `ft_lstnew` | Creates a new list node | O(1) |
| `ft_lstadd_front` | Adds a node at the beginning of the list | O(1) |
| `ft_lstsize` | Counts the number of nodes in the list | O(n) |
| `ft_lstlast` | Returns the last node of the list | O(n) |
| `ft_lstadd_back` | Adds a node at the end of the list | O(n) |
| `ft_lstdelone` | Frees a single node and its content | O(1) |
| `ft_lstclear` | Frees an entire list, node by node | O(n) |
| `ft_lstiter` | Applies a function to each node's content | O(n) |
| `ft_lstmap` | Applies a function to each node's content, building a new list | O(n) |
 
where `n` = number of nodes in the list.

## License

This project is provided as open‑source under the terms of the [MIT License](https://opensource.org/licenses/MIT). Feel free to use, modify, and distribute it in your own projects.

---