# import ipdb
import subprocess
import os

# os.system("cmd /c echo aaaa")
pwd = os.getcwd()

# p = subprocess.Popen('echo aaaa', shell=True)

print("Fudeu")

all_files = os.listdir(pwd)

c_files = [file for file in all_files if file[-2::] == ".c"]
h_files = [file for file in all_files if file[-2::] == ".h"]

print(c_files)
print(h_files)

c_files_cli = " ".join(c_file for c_file in c_files)
h_files_cli = " ".join(h_file for h_file in h_files)

files_to_compile = c_files_cli + " " + h_files_cli

print(files_to_compile)

p = subprocess.Popen(['echo {files_to_compile}'], shell=True, stdin=None,
                     stdout=subprocess.PIPE, stderr=subprocess.PIPE)
stderror = p.communicate()
print(stderror)
