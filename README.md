# c-plus-plus-forays
C++ through experiential learning

## Requirements:
- [gcc](https://gcc.gnu.org/)
- [libstdc++](https://gcc.gnu.org/onlinedocs/libstdc++/faq.html)

## Optional:
- [bash](https://www.gnu.org/software/bash/)
- [Node.js](https://nodejs.org/en/)
- [npm](https://www.npmjs.com/get-npm)
- [nodemon](https://www.npmjs.com/package/nodemon)

## Building (from the root folder):
Ordinary GCC build with Bash. C++ option is specified, libstdc++ is specified, output object takes the extension `.o`. 
```
// template
gcc -x c++ ./src/<<example file>>.cpp -lstdc++ -o ./out/<<example file>>.o

// example
gcc -x c++ ./src/Palindrome.cpp -lstdc++ -o ./out/Palindrome.o
```
Node.js through Bash allows the `nodemon` module to watch a target file for changes and automatically recompile the file.
```
// template
npm install -g nodemon
bash ./autoCompile.sh <<example file name without path>>
// example
npm install -g nodemon
bash ./autoCompile.sh Palindrome.cpp
```
And `Palindrome.o` will automatically be placed in the `/out` folder. THE `-g` FLAG IS IMPORTANT!!! This option specifies that nodemon be registered globally. This way, one does not have to specify `./node_modules/nodemon/bin/nodemon.js` explicitly!
