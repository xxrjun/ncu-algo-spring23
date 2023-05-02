# NCU MIS 109403019

import numpy as np
from qiskit import QuantumCircuit, Aer
from qiskit.visualization import array_to_latex

# Create a 2-qubit quantum circuit
qc = QuantumCircuit(2)
qc.h(0)
qc.x(1)
qc.h(1)
qc.cx(0, 1)

# Draw the quantum circuit using the matplotlib drawer
# display(qc.draw('mpl'))

# Get the unitary simulator backend
sim = Aer.get_backend('aer_simulator')

# Save the unitary of the circuit
qc.save_unitary()

# Run the circuit on the simulator and get the unitary result
unitary = sim.run(qc).result().get_unitary()

# Convert the unitary matrix to a NumPy array
unitary_np = np.array(unitary)

# Format the unitary matrix elements to strings with two decimal places
formatted_unitary = [['{:.2f}'.format(item) for item in sublist] for sublist in unitary_np]

# Print the formatted unitary matrix
print(formatted_unitary)