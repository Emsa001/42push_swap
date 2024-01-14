import random
import subprocess
import sys

def generate_random_input(size):
    return random.sample(range(-size * 2, size * 2), size)

def generate_push_swap_commands(numbers):
    command_list = []
    for num in numbers:
        command_list.append(str(num))
    return ' '.join(command_list)

def generate_sets_and_commands(size, max_operations):
    i = 0
    for i in range(1000):
        random_numbers = generate_random_input(size)
        push_swap_commands = generate_push_swap_commands(random_numbers)
        lines_command = f"./push_swap {push_swap_commands} | wc -l"
        checker_command = f"./push_swap {push_swap_commands} | ./checker_Mac {push_swap_commands}"
        
        result = subprocess.run(lines_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        result2 = subprocess.run(checker_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

        output = result.stdout.strip()
        output2 = result2.stdout.strip()
        count = int(output)

        if count < max_operations and output2 == "OK":
            print(f"\033[0m{i}. \033[92mCount: \033[1;37m{count}\033[92m, Status: Passed\033[0m")
        else:
            if count > max_operations and output2 == "OK":
                print(f"\033[0m{i}. \033[93mCount: \033[1;37m{count}\033[93m, Status: Warning: Too many operations\033[0m")
            if output2 != "OK":
                print(f"\033[0m{i}. \033[93mCount: \033[1;37m{count}\033[93m, Status: Failed: {output2}\033[0m")
        i += 1

if __name__ == "__main__":
    size = 100
    max_operations = 700
    if len(sys.argv) >= 2:
        size = int(sys.argv[1])
    if len(sys.argv) >= 3:
        max_operations = int(sys.argv[2])
    generate_sets_and_commands(size, max_operations)