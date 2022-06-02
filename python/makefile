pylib = D:\\python\\libs\\*
callc.dll: callc.c 
	g++ -fdiagnostics-color=always -g $^ -L $(pylib) -fPIC -shared  -o $@

.PHONY:clean
clean :
    del callc.dll