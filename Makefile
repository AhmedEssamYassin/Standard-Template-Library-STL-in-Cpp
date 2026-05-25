CXX = g++
CXXFLAGS = -O3 -std=c++2b -Wall -Wextra -DLOCAL

# Find all .cpp files
SRCS = $(wildcard */*.cpp)
# Determine targets by stripping the extension
BINS = $(SRCS:.cpp=.exe)

all: $(BINS) run

# Rule to compile each .cpp file into an executable in the same directory
%.exe: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Target to run all executables and generate Output.txt
run: $(BINS)
	@for %%f in ($(BINS)) do ( \
		echo Running "%%f"... && \
		pushd "%%~dpf" && \
		"%%~nxf" && \
		popd \
	)

clean:
	-del /S /Q *.exe Output.txt 2>nul

.PHONY: all run clean
