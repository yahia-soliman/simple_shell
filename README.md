# simple_shell
A POSIX Compliant command-line interpreter for unix


## Install
make sure you have `gcc` and `make` installed, then to compile the program write make
```sh
# build the binary
make

# execute the binary
./sish
```


## Features
- Executing commands in `$PATH` and passing arguments to them
```txt
$ish >>> echo Hello There
Hello There
$ish >>> ls
AUTHORS   README.md   core.c ...
$ish >>> ls not_found
ls: cannot access 'not_found': No such file or directory
$ish >>> not_a_command
./sish: 4: not_a_command: not found
$ish >>> exit
```

- Command chaining
```txt
$ish >>> echo first line; sleep 1; echo second line
first line
second line
$ish >>>
```

- File as input
```sh
bash$ cat test/file
ls -l
ls
echo "asdf"
bash$ ./sish test/file
total 80
-rw-r--r-- 1 user user   119 Aug 15 20:13 AUTHORS
-rw-r--r-- 1 user user   160 Aug 15 20:19 Makefile
...
-rw-r--r-- 1 user user   327 Aug 15 20:13 util.h
AUTHORS Makefile ...  util.h
"asdf"
```

- Non-interactive mode
```sh
bash$ echo ls | ./sish
AUTHORS Makefile ...  util.h
```
