all:
	@echo -n "compile source files..."
	@gcc ./environment-variables.c -o environment-variables
	@gcc ./called_func.c -o called_func
	@echo " finished."
	@echo "run ./enviroment-variables or make run"

run: all
	./environment-variables

.PHONY: all run