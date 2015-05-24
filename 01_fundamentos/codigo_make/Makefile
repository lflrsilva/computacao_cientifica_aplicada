# Preparo das regras do Makefile em arquivo texto
#
# #comentario
# target:  dependency1 dependency2 ...
# <tab> command
#
# :> make -f Makefile

#construcao do executavel
execc: codigo.o
	gcc -o execc codigo.o

# compilacao do codigo
codigo.o: codigo.c
	gcc -c codigo.c

# limpando o diretorio
clean:
	rm codigo.o