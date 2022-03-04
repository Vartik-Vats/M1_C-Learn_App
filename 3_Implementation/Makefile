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

INC=-Iinc\
-Iunity\


Build : $(SRC) 
	gcc $(SRC) $(INC) -o $(call FixPath,$(PROJ_NAME).$(EXEC)) -lm

run : Build
	./$(call FixPath,$(PROJ_NAME).$(EXEC))


Build_test : 
	gcc $(TEST_SRC) $(INC) -o $(call FixPath,$(PROJ_NAME).$(EXEC)) -lm

run_test : Build_test
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

static_analysis:
	cppcheck --enable=all $(SRC)