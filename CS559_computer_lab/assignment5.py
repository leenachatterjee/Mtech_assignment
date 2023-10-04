#!/usr/bin/env python
# coding: utf-8

# In[2]:


class Stack:
    def __init__(self):
        self.stack = []

    def push(self, value):
        self.stack.append(value)

    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        else:
            return None

    def is_empty(self):
        return len(self.stack) == 0

def execute_instructions(instructions):
    stack = Stack()

    for instruction in instructions:
        if instruction.startswith("PUSH"):
            value = int(instruction.split()[1])
            stack.push(value)
        elif instruction == "POP":
            stack.pop()
        elif instruction == "ADD":
            if len(stack.stack) >= 2:
                operand2 = stack.pop()
                operand1 = stack.pop()
                result = operand1 + operand2
                stack.push(result)
            else:
                print("Error: Not enough operands for ADD instruction.")
                return
        elif instruction == "SUB":
            if len(stack.stack) >= 2:
                operand2 = stack.pop()
                operand1 = stack.pop()
                result = operand1 - operand2
                stack.push(result)
            else:
                print("Error: Not enough operands for SUB instruction.")
                return

    return stack

if __name__ == "__main__":
    N = int(input("Enter the number of instructions: "))
    instructions = []
    
    for _ in range(N):
        instruction = input("Enter instruction: ")
        instructions.append(instruction)

    result_stack = execute_instructions(instructions)

    if not result_stack.is_empty():
        result = result_stack.pop()
        print("Final result:", result)
    else:
        print("Stack is empty after executing instructions.")


# Let's go through the instructions step by step to see how we get the result of 12:
# 
# 1. PUSH 10: Pushes the value 10 onto the stack. Stack: [10]
# 2. PUSH 5: Pushes the value 5 onto the stack. Stack: [10, 5]
# 3. ADD: Pops the top two values from the stack (5 and 10), adds them together (10 + 5 = 15), and pushes the result back onto the stack. Stack: [15]
# 4. PUSH 3: Pushes the value 3 onto the stack. Stack: [15, 3]
# 5. SUB: Pops the top two values from the stack (3 and 15), subtracts the second from the first (15 - 3 = 12), and pushes the result back onto the stack. Stack: [12]
# 6. POP: Pops the top value from the stack and discards it. Stack: []
# 
# After executing all these instructions, the final value left on the stack is indeed 12. So, the result of the sequence of instructions is 12.

# In[ ]:




