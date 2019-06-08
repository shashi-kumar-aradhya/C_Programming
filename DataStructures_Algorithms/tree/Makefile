GCC=gcc -g -Wall 

tree_lib:
	${GCC} tree_lib.c -o tree_lib.exe
	${GCC} tree_lib_1.c -o tree_lib_1.exe
tree_lib_iterative:
	${GCC} tree_lib.c tree_empty_stack.c iterative_preorder.c iterative_inorder.c -o iterative.exe

tree_lib_example:
	${GCC} iterative_example.c -o iterative_example.exe
clean:
	rm -rf *.exe

