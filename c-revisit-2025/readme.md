```c
#include <stdio.h>

int main(void){
  puts("Hello word");
  return 0;
}

```

### Install buil Essentials
```bash
Linux: Install GCC (sudo apt install build-essential)
```

Compile with
```bash
gcc hello.c -o hello 
```

Run with 
```bash
./hello
```

Use warning 
```bash
gcc -Wall -Wextra -Werror -o hello hello.c
```


### Run with clang 
```bash
sudo apt update
sudo apt install clang
```

### Then use
```bash
clang hello.c -o hello
```
