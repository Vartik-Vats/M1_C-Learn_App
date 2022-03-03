PROJ_NAME= banking
SRC= bankingsystem.c 

TEST_SRC=test_bankingsystem.c, unity.c, bankingsystem.c

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

Build:
  gcc $(SRC) -O $(call FixPath,$(PROJ_NAME).$(EXEC)) 
run:Build
  ./$(call FixPath,$(PROJ_NAME).$(EXEC)) 

Build_test:
  gcc $(TEST_SRC) -O $(call FixPath,$(PROJ_NAME).$(EXEC)) 
run_test:Build_test
  ./$(call FixPath,$(PROJ_NAME).$(EXEC)) 