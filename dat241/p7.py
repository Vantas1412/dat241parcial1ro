import multiprocessing

def f(x):
    return 4 / (x**2 + 1)

def integrate_range(start, end, steps):
    dx = (end - start) / steps
    total = 0
    for i in range(steps):
        x0 = start + i * dx
        x1 = start + (i + 1) * dx
        total += 0.5 * (f(x0) + f(x1)) * dx
    return total

def main():
    num_processes = 4
    num_steps = 100000 
    step_range = 1.0 / num_processes
    
    pool = multiprocessing.Pool(processes=num_processes)
    results = pool.starmap(integrate_range, [(i * step_range, (i + 1) * step_range, num_steps) for i in range(num_processes)])
    pool.close()
    pool.join()

    pi_estimate = sum(results)
    print("Estimación de Pi:", pi_estimate)

if __name__ == "__main__":
    main()
