import numpy as np
import build.example as example

ex = example.MyClass()

a = ex.get_matrix()
print(f"a: \n{a}")

x = np.array([[1, 2, 3], [4, 5, 6],[0,0,0]], dtype=np.float64, order='F') 
ex.set_matrix(x)

print(f"x: \n{x}")

print(f"before get again: \n{a}")


a = ex.get_matrix()
print(f"after get again: \n{a}")