# Optimization must be enabled to induce UB
CFLAGS := -O2

CFLAGS += "-DCOMPILER_DESC=\"$(shell $(CC) --version | head -n 1)\""

.PHONY: test-object-write-before-ctor

test: object-write-before-ctor
	./object-write-before-ctor

object-write-before-ctor: object-write-before-ctor.cpp
	$(CC) -x c++ $^ write-object.cpp -o $@  $(CFLAGS) -fno-exceptions

clean:
	rm -f object-write-before-ctor
