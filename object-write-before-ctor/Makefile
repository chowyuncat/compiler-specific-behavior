# Optimization must be enabled to induce UB
.PHONY: test-object-write-before-ctor

test: object-write-before-ctor
	./object-write-before-ctor

object-write-before-ctor: object-write-before-ctor.cpp
	$(CC) -O2 -x c++ $^ -o $@

clean:
	rm -f object-write-before-ctor
