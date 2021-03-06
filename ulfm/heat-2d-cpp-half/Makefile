COM_COLOR    := \033[0;34m
OBJ_COLOR    := \033[0;36m
OK_COLOR     := \033[0;32m
ERROR_COLOR  := \033[0;31m
WARN_COLOR   := \033[0;33m
NO_COLOR     := \033[m
OK_STRING    := "[OK]"
ERROR_STRING := "[ERROR]"
WARN_STRING  := "[WARNING]"
COM_STRING   := "Compiling"
CREAT_STRING := "Creating"
CLEAN_STRING := "Cleaning"

CXX          := g++
MPICXX       := mpicxx
CFLAGS       := -g -Wall -O2
LDFLAGS      := -lm
STDFLAGS     := -std=c++11
DMPI         := -D MPI_SUPPORT
DULFM        := -D ULFM_SUPPORT
DKILL        := -D KILLING_TEST

BUILD_DIR    := build

all: heat-2d heat-2d-kill

heat-2d-kill:
	@mkdir -p $(BUILD_DIR)
	@RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(CREAT_STRING)$(OBJ_COLOR) $(BUILD_DIR)" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(CREAT_STRING)$(OBJ_COLOR) $(BUILD_DIR)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	fi;
	@cp slurm-kill.job $(BUILD_DIR)/slurm-kill.job
	@cp torque-kill.job $(BUILD_DIR)/torque-kill.job
	@$(MPICXX) $(CFLAGS) $(LDFLAGS) $(STDFLAGS) $(DMPI) $(DULFM) $(DKILL) \
	Utils.cpp \
	Grid.cpp \
	Task.cpp \
	FailureSimulator.cpp \
	-o $(BUILD_DIR)/$@ heat-2d-compute-redundancy.cpp; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	fi;

heat-2d:
	@mkdir -p $(BUILD_DIR)
	@RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(CREAT_STRING)$(OBJ_COLOR) $(BUILD_DIR)" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(CREAT_STRING)$(OBJ_COLOR) $(BUILD_DIR)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	fi;
	@cp slurm.job $(BUILD_DIR)/slurm.job
	@cp torque.job $(BUILD_DIR)/torque.job
	@$(MPICXX) $(CFLAGS) $(LDFLAGS) $(STDFLAGS) $(DMPI) $(DULFM) \
	Utils.cpp \
	Grid.cpp \
	Task.cpp \
	-o $(BUILD_DIR)/$@ heat-2d-compute-redundancy.cpp; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	fi;

debug:
	@mkdir -p $(BUILD_DIR)/$@
	@RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(CREAT_STRING)$(OBJ_COLOR) $(BUILD_DIR)" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(CREAT_STRING)$(OBJ_COLOR) $(BUILD_DIR)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	fi;
	@$(CXX) $(CFLAGS) $(LDFLAGS) $(STDFLAGS) \
	Grid.cpp \
	Task.cpp \
	-o $(BUILD_DIR)/$@/$@ unit-test/$@.cpp -D DEBUG; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	fi;

test:
	@mkdir -p $(BUILD_DIR)/unit-$@
	@RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(CREAT_STRING)$(OBJ_COLOR) $(BUILD_DIR)" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(CREAT_STRING)$(OBJ_COLOR) $(BUILD_DIR)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	fi;
	@cxxtestgen --error-printer -o $(BUILD_DIR)/unit-$@/runner.cpp unit-$@/GridTaskTestSuite.h;
	@$(CXX) $(CFLAGS) $(LDFLAGS) $(STDFLAGS) \
	Grid.cpp \
	Task.cpp \
	-o $(BUILD_DIR)/unit-$@/unit-$@ $(BUILD_DIR)/unit-$@/runner.cpp -I$CXXTEST; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	fi;

clean:
	@rm -Rf $(BUILD_DIR)
	@RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(CLEAN_STRING)$(OBJ_COLOR) $(BUILD_DIR)" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(CLEAN_STRING)$(OBJ_COLOR) $(BUILD_DIR)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	fi;
