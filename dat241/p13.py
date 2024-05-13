import multiprocessing

def fibonacci(n):
    fib = [0, 1]
    for i in range(2, n):
        fib.append(fib[-1] + fib[-2])
    return fib

def main():
    num_terms = 1000
    num_processors = multiprocessing.cpu_count()

    pool = multiprocessing.Pool(processes=num_processors)
    results = pool.map(fibonacci, [num_terms // num_processors] * num_processors)
    pool.close()
    pool.join()

    fib_sequence = []
    for result in results:
        fib_sequence.extend(result)

    print("Secuencia de Fibonacci generada:")
    print(fib_sequence)

if __name__ == "__main__":
    main()
