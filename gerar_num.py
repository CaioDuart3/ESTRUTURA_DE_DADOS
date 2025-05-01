import random

with open("input_proib.txt", "w") as f:
    numeros = [str(random.randint(1, 1000)) for _ in range(900000)]
    f.write(" ".join(numeros))
