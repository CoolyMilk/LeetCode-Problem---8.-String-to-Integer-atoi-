// Note that this does not contain all the code sonce leetcode most likely adds stuff to my code to make it able to run


bool check_top(int output, int value) { // Just checking edge case and if it is actually valid
  return (INT_MAX/10 < output) || (value > 7 && INT_MAX/10 <= output);
}

bool check_bottom(int output, int value) { // The same thing but for the other boundary :D
  return (INT_MIN/10 > output) || (value < -8 && INT_MIN/10 >= output);
}

// Instead of checking if output is over boundary
// We check it if it's under
// I think I know the math behind it
// 1 * 5 > 50 == 1 > 10
// Both false because they're the same thing
// When you change both sides the same linearly
// You can expect the same result
// It's like a ratio or normalization idk it seems similar well it is definitely not but it helps make it clear
// It's not always the same non-linearly though
// A number 7 problem solution I checked after solving it helped
// I had to come up with my own since the solution I remember there
// wasn't working

int myAtoi(char *start){
  char *current = start; //Skip to the relevant part
  while (*current == ' ') { current++; }

  bool negative = false; 
  if (*current == '-') { //Checking if number is negative or positive
    negative = true; 
    current++; 
  } else if (*current == '+') { 
    current++; 
  }
  
  bool trim = true; // The trim basically skips all the leading zeroes
  int output = 0;
  while (*current >= '0' && *current <= '9') { // Get all the numbers
    int value = *current - '0'; // Turn character into number
    if (negative) { value = -value; }
    
    if (trim == true && value == 0) {  // Trims leading zeroes
      current++; continue; 
    }
    trim = false; //Trips off the trim so it knows now to mess up future zeros

    // Just checking boundaries and I just made sure that it is true
    if (check_top(output, value) == true) { 
      return INT_MAX; 
    } else if (check_bottom(output, value) == true) { 
      return INT_MIN; 
    }

    output = output * 10 + value;  //Add it like a stack
    current++; // onwards!!!
  }
  
  return output; // well I guess bye output? 
}
