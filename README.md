# numconv1 opg 

## Kompilering

For at kompilere dette projekt på en ARM-baseret Mac M2, kan du bruge følgende kommando i terminalen:

```bash
mkdir -p build
gcc \
src/convert_num2.c \
src/main.c \
src/num_test.c \
src/num_ui.c \
-o build/num
```