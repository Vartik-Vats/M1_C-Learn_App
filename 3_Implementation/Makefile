PROJ_NAME= bankingsystem
SRC=src/bankingsystem.c\

TEST_SRC=test/test_bankingsystem.c\
unity/unity.c\
src/bankingsystem.c\

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

INC=-Iinclude\
-Iunity\

Build:
	gcc $(SRC) $(INC) -o $(call FixPath,$(PROJ_NAME).$(EXEC)) 
run:Build
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

Build_test:
	gcc $(TEST_SRC) $(INC) -o $(call FixPath,$(PROJ_NAME).$(EXEC)) 
run_test:Build_test
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

staticcheck:
	cppcheck --enable=all -iunity .
dynamiccheck:Build
	valgrind ./$(call FixPath,$(PROJ_NAME).$(EXEC))
coverage:
	gcc -fprofile-arcs -ftest-coverage $(SRC) $(INC) -o $(call FixPath,$(PROJ_NAME).$(EXEC)) 
	gcov -a ./$(call FixPath,$(PROJ_NAME).$(EXEC))