#TEST_FILE should be any c file that contains the code provided in this
#repository.
C_SRCS := sliding_puzzle.c findCicles.c fisher_yates.c manhattanNo.c
TEST_FILE := sp_demo.c
DEMO_NAME := sp_app

$(DEMO_NAME): $(TEST_FILE)
	@echo "Buidling example..."
	@gcc $(TEST_FILE) $(C_SRCS) -o $(DEMO_NAME)

clean:
ifneq ("$(wildcard $(DEMO_NAME))","") 
	@echo "Removing sp_app.."
	@rm sp_app
else
	@echo "No application found."
endif