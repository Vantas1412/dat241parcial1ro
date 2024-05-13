from multiprocessing import Process, Queue

def gen(n, re):
    s = [i for i in range(2, n + 1, 2)] 
    re.put(s)

def main():
    n = int(input("Ingrese el número N para la serie: "))
    m = int(input("Ingrese el número de vectores (procesadores): "))
    
    paso = 2
    inicio = 2
    fin = n * paso + inicio

    re = Queue()
    procesos = []

    for _ in range(m):
        proceso = Process(target=gen, args=(fin, re))
        procesos.append(proceso)

    for proceso in procesos:
        proceso.start()

    for proceso in procesos:
        proceso.join()

    ss = []
    while not re.empty():
        ss.append(re.get())
    
    print("Series generadas:")
    for i in range(len(ss)):
        print("Serie ",i+1,": ",*ss[i])

if __name__ == "__main__":
    main()
