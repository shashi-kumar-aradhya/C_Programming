all :
	rm -rf xtree.txt xtree_helgrind.txt
	valgrind --leak-check=yes --show-reachable=yes --vgdb=full --xtree-memory=full --xtree-memory-file=xtree.txt ./$(exe)
helgrind:
	valgrind --tool=helgrind --vgdb=full --read-var-info=yes --xtree-memory=full --xtree-memory-file=xtree_helgrind.txt ./$(exe)
callgrind:
	valgrind --tool=callgrind --dump-instr=yes --collect-jumps=yes ./$(exe)
