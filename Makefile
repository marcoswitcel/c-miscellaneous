main: main.c
	$(CC) main.c -o bin/main -Wall -Wextra -pedantic -std=c17
run: main
	@echo ./bin/main
	@echo "================"
	@./bin/main
	@echo "\n================\n"
