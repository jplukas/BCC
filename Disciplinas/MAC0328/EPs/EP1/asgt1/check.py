import os

for i in range(9, 10):
   os.popen(f"./a.out < tests/in0{i} | cat > check/out0{i}")
   
for i in range(10, 13):
   os.popen(f"./a.out < tests/in{i} | cat > check/out{i}")
   