all:
	make -C src/server all
	make -C src/client all

clean:
	rm -rf *~ src/*~ src/.*.swp src/.*.swo
	make -C src/server clean
	make -C src/client clean

fclean:
	rm -rf src/*.o
	make -C src/server fclean
	make -C src/client fclean

re:	fclean all
