# import ipdb
import subprocess
import os

cwd = os.getcwd()

# Recebe todos os arquivos na pasta
all_files = os.listdir(cwd)

# Separa em arquivos .c e .h
c_files = [file for file in all_files if file[-2::] == ".c"]
h_files = [file for file in all_files if file[-2::] == ".h"]

# Agrupa os arquivos .c e .h
# c_files_cli = " ".join(c_file for c_file in c_files)
# h_files_cli = " ".join(h_file for h_file in h_files)
c_files_cli = " ".join(cwd+"\\"+c_file for c_file in c_files)
h_files_cli = " ".join(cwd+"\\"+h_file for h_file in h_files)

# Reúne todos os arquivos que serão compilados
files_to_compile = c_files_cli + " " + h_files_cli
print(f'Arquivos a serem compilados: {files_to_compile}')

# Executa um subprocess e invoca o comando do GCC de compilação
# p = subprocess.run(["gcc", "-o", "mutexList.exe", files_to_compile],
#                    capture_output=True, shell=True, cwd=cwd)
p = subprocess.Popen(['gcc', '-o', 'mutexList.exe', files_to_compile],
                     stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True, cwd=cwd)

# Debug

print(p.communicate()[1].rstrip())
