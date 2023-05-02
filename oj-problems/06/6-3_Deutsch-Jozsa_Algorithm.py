# NCU MIS 109403019
from qiskit import QuantumRegister, ClassicalRegister, QuantumCircuit, execute, Aer

def dj_problem_oracle(problem):
    """Returns a 5-qubit Deutsch-Joza Oracle"""
    qc = QuantumCircuit(5)
    int(problem)
    if problem == 1:
        for q in range(4):
            qc.cx(q, 4)
    elif problem == 2:
        qc.cx(0, 4)
        qc.cx(0, 4)
    elif problem == 3:
        qc.cx(2,4)
    else:
        print("There are only currently 3 oracles in this problem set, returning empty (balanced) gate")
    return qc.to_gate()

def deutsch_jozsa_algorithm(problem):
    oracle = dj_problem_oracle(problem)
    qr = QuantumRegister(5)
    cr = ClassicalRegister(4)
    qc = QuantumCircuit(qr, cr)
    
    # Initialize the qubits
    qc.x(4)
    qc.h(range(5))
    
    # Apply the oracle
    qc.append(oracle, range(5))
    
    # Apply Hadamard gates to the first four qubits
    qc.h(range(4))
    
    # Measure the first four qubits
    qc.measure(range(4), range(4))

    # Run the simulation
    backend = Aer.get_backend('qasm_simulator')
    job = execute(qc, backend, shots=1024)
    result = job.result()
    counts = result.get_counts(qc)
    
    # Find the highest value
    highest_value = max(counts, key=counts.get)
    return highest_value

# Read the input
n = int(input())
problems = [int(input()) for _ in range(n)]

# # Solve the problems and output the results
for problem in problems:
    print(deutsch_jozsa_algorithm(problem))