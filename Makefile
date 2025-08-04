CC = gcc

b:
	@mkdir -p obj
	$(CC) src/$(f).c -o obj/$(f).o
	@chmod u+x obj/$(f).o
	@echo "[CC] src/$(f).c -> obj/$(f).o"
	obj/$f.o

bd:
	@mkdir -p obj
	$(CC) -g src/$(f).c -o obj/$(f).d.o
	@chmod u+x obj/$(f).o
	@echo "[CC] src/$(f).c -> obj/$(f).d.o"
	
all:
	@echo "Use: make b f=<name>"
	@echo "     make bd f=<name>"
	

clean:
	rm -f obj/*.o

.PHONY: build all clean
