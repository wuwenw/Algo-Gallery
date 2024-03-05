CXX = clang++
CXXFLAGS = -g -std=c++20 -O2  -fsanitize=address
TARGET := main

.PHONY: all run clean
all: clean $(TARGET) run

# bits/stdc++.h:
# 	mkdir -p bits
# 	wget 'https://raw.githubusercontent.com/tekfyl/bits-stdc-.h-for-mac/master/stdc%2B%2B.h' -O bits/stdc++.h

# $(TARGET): $(wildcard *.cpp) bits/stdc++.h
# 	$(CXX) $(CXXFLAGS) bits/stdc++.h $< -o $@
$(TARGET): $(wildcard *.cpp)
	$(CXX) $(CXXFLAGS) $< -o $@

in := input.txt
out := output.txt

run:
	./$(TARGET) < $(in)

clean:
	rm -f $(TARGET)

debug: clean
	$(CXX) $(CXXFLAGS_DEBUG) $(wildcard *.cpp) -o $(TARGET)