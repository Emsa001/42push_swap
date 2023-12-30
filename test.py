import random
import subprocess

def generate_random_input(size):
    return random.sample(range(0, 1000), size)

def generate_push_swap_commands(numbers):
    command_list = []
    for num in numbers:
        command_list.append(str(num))
    return ' '.join(command_list)

def generate_100_sets_and_commands():
    for _ in range(100):
        size = 500  # You can adjust the range of the size as needed
        max_operations = 5500

        random_numbers = generate_random_input(size)
        push_swap_commands = generate_push_swap_commands(random_numbers)
        lines_command = f"./push_swap {push_swap_commands} | wc -l"
        checker_command = f"./push_swap {push_swap_commands} | ./checker_linux {push_swap_commands}"
        
        # Execute the command and fetch the output
        result = subprocess.run(lines_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        result2 = subprocess.run(checker_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

        output = result.stdout.strip()
        output2 = result2.stdout.strip()
        count = int(output)

        if count < max_operations and output2 == "OK":
            print(f"\033[92mCount: {count}, Status: Passed\033[0m")
        else:
            if count > max_operations and output2 == "OK":
                print(f"\033[93mCount: {count}, Status: Warning: Too many operations\033[0m")
            if output2 != "OK":
                print(f"\033[93mCount: {count}, Status: Failed: {output2}\033[0m")

if __name__ == "__main__":
    generate_100_sets_and_commands()
