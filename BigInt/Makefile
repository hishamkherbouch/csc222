CC=g++
STD=c++11

build/%.o: BigIntsrc/%.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	$(CC) -c -o $@ $< -std=$(STD)

build/test_bigint: build/test_bigint.o build/bigint.o
	$(CC) -o $@ $^ -std=$(STD)

-include build/*.d

.PHONY: test all clean

test: build/test_bigint
	./build/test_bigint

clean:
	rm -rf build
