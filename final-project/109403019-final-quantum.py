"""
Course: NCU CSIE Algorithms 2023 Spring Final Project 
Final Project: Quantum Computing Shor’s Algorithm
Student Info: NCU MIS 109403019
Date: 2023/05/30
"""

# Importing libraries
from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister, execute, Aer
from qiskit.visualization import plot_histogram
from qiskit.providers.aer import AerSimulator
from qiskit import execute
from fractions import Fraction
from math import pi

# References:QBook Ch7 p.242
def qc_mod15(a, power, show=False):
    assert a in [2, 4, 7, 8, 11, 13], 'Invalid value of argument a:' + str(a)
    qrt = QuantumRegister(4, 'target')
    U = QuantumCircuit(qrt)
    
    # Apply the appropriate gates based on the value of a
    for i in range(power):
        if a in [2, 13]:
            U.swap(0, 1)
            U.swap(1, 2)
            U.swap(2, 3)
        if a in [7, 8]:
            U.swap(2, 3)
            U.swap(1, 2)
            U.swap(0, 1)
        if a in [4, 11]:
            U.swap(1, 3)
            U.swap(0, 2)
        if a in [7, 11, 13]:
            for j in range(4):
                U.x(j)
    
    # Display the circuit if show is True
    if show:
        print('Below is the circuit of U of ' + f'"{a}^{power} mod 15":')
        display(U.draw('mpl'))
    U = U.to_gate()
    U.name = f'{a}^{power} mod 15'
    C_U = U.control()
    
    return C_U

                
# References: QBook ch7 p.221
def iqft(n):
    br = QuantumRegister(n, 'b')
    qc = QuantumCircuit(br)

    # Apply the inverse QFT
    for sbit in range(n//2):  # sbit: for swap qubit
        qc.swap(sbit, n - sbit - 1)
    for hbit in range(0, n, 1):  # hbit: for h-gate qubit
        for cbit in range(hbit - 1, -1, -1):  #cbit: for count qubit
            qc.cp(-pi/2**(hbit-cbit), cbit, hbit)
        qc.h(hbit)
    
    
    return qc


def qpf15(count_no, a):
    qrc = QuantumRegister(count_no, 'count')  # Counting quantum register
    qry = QuantumRegister(4, 'y') # Counting quantum register
    clr = ClassicalRegister(count_no, 'c') # Classical register for measurement results
    qc = QuantumCircuit(qrc, qry, clr)
    
    # Apply Hadamard gates to the counting register
    for cbit in range(count_no):
        qc.h(cbit)
        
    # Set the input of qc_mod15 to |1>, where y0 is the least significant bit
    qc.x(qry[0])
    
    # Apply qc_mod15 gates to the corresponding qubits
    for cbit in range(count_no):
        qc.append(qc_mod15(a, 2**cbit), [cbit] + list(range(count_no, count_no + 4)))
    
    # Apply inverse quantum Fourier transform
    qc.append(iqft(count_no).to_gate(label='IQFT'), range(count_no))
   
    # Perform measurement
    qc.measure(range(count_no), range(count_no))
            
    return qc


n = int(input())
test_cases = []
for i in range(n):
    c, a = list(input().split())
    test_cases.append([int(c), int(a)])
    
for test_case in test_cases:
    c, a = test_case[0], test_case[1]
    qc = qpf15(c, a)


    # Execute the quantum circuit using a simulator
    sim = AerSimulator()
    job = execute(qc, backend=sim, shots=1000)
    res = job.result()
    counts = res.get_counts(qc)
    
    sorted_counts = dict(sorted(counts.items()))

    # Calculate and output the measurement results, phase, fraction, and period for each quantum state
    for akey in sorted_counts.keys():
        dec = int(akey, base = 2)
        phase = dec / (2**c)
        frac = Fraction(phase).limit_denominator(15)
        period = frac.denominator
        print('%s %s' % (akey, period))