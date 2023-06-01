import numpy as np
from qiskit import QuantumCircuit, transpile
from qiskit_aer import QasmSimulator
from qiskit.visualization import plot_histogram

circuit = QuantumCircuit(2, 2) #initiallizing 2 qubits in the zero state and 2 classical bits set to 0

circuit.h(0) #Hadamard Gate, puts a qubit into superposition
circuit.cx(0, 1) #CNOT Gate, entangles 2 qubits
circuit.measure([1,0], [1,0]) #if you pass the entire quantum and classical registers to measure, the ith qubit’s measurement result will be stored in the ith classical bit.

print(circuit.draw())

simulator = QasmSimulator()
compiled_circuit = transpile(circuit, simulator)
job = simulator.run(compiled_circuit, shots=1000)
result = job.result()
counts = result.get_counts(circuit)
print("\nTotal count for 00 and 11 are:",counts)
plot_histogram(counts, filename='new_hist.png')