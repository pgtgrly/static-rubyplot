# static-rubyplot
Creating static plots in Ruby. Will be integrated to https://github.com/SciRuby/rubyplot  

17-05-2018
Created a basic backend layer with Figure Canvas and Basic renderer functionality in Cairo. it can be found in backends folder and compiled using
```sh

g++ test.cpp -o cairo $(pkg-config --cflags --libs cairo)
./cairo


```
