# NCU MIS 109403019

from qiskit import QuantumRegister, ClassicalRegister, QuantumCircuit, execute, Aer

all_inputs=[]
for q4 in ['0','1']: 
    for q3 in ['0','1']:
        for q2 in ['0','1']:
            for q1 in ['0','1']:
                for q0 in ['0','1']:
                    all_inputs.append(q4+q3+q2+q1+q0)
# print(all_inputs)  

print("input --> output")
for the_input in all_inputs:
    # create the circuit
    qaux = QuantumRegister(2,"qaux") # 輔助量子寄存器，用於儲存過程中的中間值
    q = QuantumRegister(5,"q")
    c = ClassicalRegister(5,"c")
    qc = QuantumCircuit(q,qaux,c)
    # set the initial value of the circuit w.r.t. the input
    if the_input[0] =='1': qc.x(q[4])
    if the_input[1] =='1': qc.x(q[3])
    if the_input[2] =='1': qc.x(q[2])
    if the_input[3] =='1': qc.x(q[1])
    if the_input[4] =='1': qc.x(q[0])
    
    
    # your code is here

    # Apply X gates to invert their states
    # These are for applying NOT (X gate) when the state is |1010>
    qc.x(q[1])
    qc.x(q[3])
    
    qc.ccx(q[1],q[2],qaux[0])
    qc.ccx(q[3],q[4],qaux[1])
    
    qc.ccx(qaux[0],qaux[1],q[0])
    
    qc.ccx(q[3],q[4],qaux[1])
    qc.ccx(q[1],q[2],qaux[0])
    
    # Revert the X gates applied to the control qubits
    qc.x(q[3])
    qc.x(q[1])

    # measure the main quantum register 
    qc.measure(q,c)
    
    # execute the circuit
    job = execute(qc,Aer.get_backend('qasm_simulator'),shots=1)
    counts = job.result().get_counts(qc)
    for key in counts: the_output = key
    printed_str = the_input[0:4]+" "+the_input[4]+" --> "+the_output[0:4]+" "+the_output[4]
    if (the_input!=the_output): printed_str = printed_str + " the output is different than the input"
    print(printed_str)

