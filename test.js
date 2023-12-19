const { execSync } = require('child_process');

function permutations(arr) {
  if (arr.length === 1) {
    return [arr];
  }

  const result = [];

  for (let i = 0; i < arr.length; i++) {
    const rest = [...arr.slice(0, i), ...arr.slice(i + 1)];
    const restPermutations = permutations(rest);

    for (const perm of restPermutations) {
      result.push([arr[i], ...perm]);
    }
  }

  return result;
}

const numbers = [1, 2, 3, 4, 5];
const permutationsList = permutations(numbers);

for (const perm of permutationsList) {
  const command = `./push_swap ${perm.join(' ')}`;

  try {
    const output = execSync(command, { encoding: 'utf-8' });

    // Extract and print the "Results" part
    const resultsIndex = output.indexOf('Results:');
    if (resultsIndex !== -1) {
      const results = output.substring(resultsIndex);
      console.log(`Command: ${command}\n${results}`);
    } else {
      console.error(`Results not found in the output for command: ${command}`);
    }
  } catch (error) {
    console.error(`Error executing command: ${command}`);
    console.error(error.stdout.toString());
    console.error(error.stderr.toString());
  }
}
