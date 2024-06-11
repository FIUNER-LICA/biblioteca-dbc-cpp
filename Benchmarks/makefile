# Name of the program
PROGRAM = benchmark

# Compiler
CC = g++

# Compiler options
# CFLAGS = -std=c++17 -O3
CFLAGS = $(flags)

# Sources
SRCS = MetodoTrapecio/main.cpp MetodoTrapecio/metodotrapecio.cpp MetodoTrapecio/contract.cpp

# Objects
OBJS = $(SRCS:.cpp=.o)

# Check if ASSERT and INVARIANT are specified
ifndef ASSERT_MODE
$(error ASSERT_MODE no especificado. Ejemplo: make ASSERT_MODE=ASSERT_FUNCTION)
endif

# List of valid ASSERT modes
ASSERT_MODES = ASSERT_MACRO ASSERT_FUNCTION ASSERT_CLASS ASSERT_NONE

# Check if ASSERT_MODE is in the list
ifeq (,$(filter $(ASSERT_MODE),$(ASSERT_MODES)))
$(error ASSERT_MODE debe ser uno de: $(ASSERT_MODES))
endif

ifndef INVARIANT_MODE
$(error INVARIANT_MODE no especificado. Ejemplo: make INVARIANT_MODE=INVARIANT_LAMBDA)
endif

# List of valid INVARIANT modes
INVARIANT_MODES = INVARIANT_LAMBDA INVARIANT_MACRO INVARIANT_NONE

# Check if INVARIANT_MODE is in the list
ifeq (,$(filter $(INVARIANT_MODE),$(INVARIANT_MODES)))
$(error INVARIANT_MODE debe ser uno de: $(INVARIANT_MODES))
endif

# Regla de compilación
$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) -D$(ASSERT_MODE) -D$(INVARIANT_MODE) $(OBJS)

# Regla para generar los objetos
%.o: %.cpp
	$(CC) $(CFLAGS) -D$(ASSERT_MODE) -D$(INVARIANT_MODE) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJS) $(PROGRAM)
