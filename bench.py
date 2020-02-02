import example
import sys
import time

r= example.test_float(int(sys.argv[1]))
start = time.time()
for i in r:
	continue
end = time.time()
print(f"VectorFloat: {end - start}")

l = [float(a) for a in range(int(sys.argv[1]))]
ll = tuple(l)
start = time.time()
for i in ll:
       continue
end = time.time()
print(f"tuple: {end - start}")


start = time.time()
for i in l:
       continue
end = time.time()
print(f"list: {end - start}")


d = [a for a in range(int(sys.argv[1]))]
cpp = example.test_cpp(d)
print(f"cpp pylist: {cpp}")

cpp = example.test_vector(int(sys.argv[1]))
print(f"cpp vector: {cpp}")


