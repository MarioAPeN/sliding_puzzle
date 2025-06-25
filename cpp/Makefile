#TEST_FILE should be any c file that contains the code provided in this
#repository.
CPP_SRCS := sliding_puzzle.cpp cicles.cpp fisher_yates.cpp manhattanNo.cpp
TEST_FILE := sp_demo.cpp
DEMO_NAME := sp_app

$(DEMO_NAME): $(TEST_FILE)
	@echo "Buidling example..."
	@g++ $(TEST_FILE) $(CPP_SRCS) -o $(DEMO_NAME)

clean:
ifneq ("$(wildcard $(DEMO_NAME))","") 
	@echo "Removing sp_app.."
	@rm sp_app
else
	@echo "No application found."
endif
