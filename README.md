*This project has been created as part of the 42 curriculum by andrpetr.*

# ft_printf

## Description

`ft_printf` reimplements a subset of C's `printf`. It writes to standard output with `write` and returns the byte count on success.

**Mandatory conversions**

| Conversion | Output |
| --- | --- |
| `%c` | A single character |
| `%s` | A string |
| `%p` | A pointer address in hexadecimal |
| `%d`, `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` | An unsigned hexadecimal integer with lowercase digits |
| `%X` | An unsigned hexadecimal integer with uppercase digits |
| `%%` | A literal percent sign |

**Bonus** adds minimum field width, precision, and the `-`, `0`, `#`, `+`, and space flags where applicable.

## Instructions

Run `make` from the repository root to build `libftprintf.a`. The library built by `make` already includes bonus formatting. The 42 Moulinette uses `make bonus` for the bonus evaluation, which rebuilds the same library.

Save this example as `example.c` and compile it from the repository root.

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! %06d in decimal is %#x in hex.\n", "42", 42, 42u);
    return (0);
}
```

```sh
make
cc -Wall -Wextra -Werror -Ilibs example.c libftprintf.a -o example
./example
```

Expected output

```text
Hello, 42! 000042 in decimal is 0x2a in hex.
```

`make clean` removes the object files, `make fclean` also removes the library, and `make re` rebuilds it.

## Algorithm and data structures

The formatter scans left to right, writing literal characters directly. At each `%`, it parses the options and uses the conversion type to fetch the next argument with `va_arg`. A forward scan keeps conversions and arguments in order and avoids buffering the full output.

A stack-allocated `t_data` holds the byte count and the current conversion state. It groups parsed options in `t_flags` and computed space and zero padding in `t_format`, so the output helpers can place signs and prefixes correctly. The `t_arg` union lets numeric values and string pointers share storage because each conversion uses only one member.

Numeric helpers count digits using division by 10 or 16 so padding can be calculated before output. Decimal digits are printed recursively from most to least significant. Hexadecimal digits are written into a fixed-size buffer from right to left using remainders as digit-table indexes.

## Resources

- A reference for C format strings. [C format reference from École Polytechnique](https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html)

AI helped draft this README, review the formatting logic, and check flag interactions and edge cases.
