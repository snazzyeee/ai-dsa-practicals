// Practical 6: Infix to postfix conversion and evaluation
//
// precedence:
// Return priority 3 for exponent, 2 for multiply/divide,
// 1 for add/subtract, and 0 for other characters.
//
// infixToPostfix:
// Start with an empty operator stack and output string.
// Send operands directly to output; push opening parentheses.
// On a closing parenthesis, pop operators up to the opening parenthesis.
// For an operator, pop higher-priority operators first.
// Also pop equal-priority operators, except when the new operator is exponent.
// Push the new operator, then pop remaining operators after reading the input.
// End the output string and report success, or failure for invalid input.
//
// evaluatePostfix:
// Push digits as numbers; ask for each letter's value once and reuse it.
// On an operator, pop right operand first, then left operand.
// Calculate left operator right and push the answer.
// Reject missing operands, division by zero or an unsupported operator.
// The final stack must hold one value; store it as the result.
//
// main:
// Repeat Convert/evaluate or Exit using do-while and switch.
// Read an expression, convert it and print the postfix form.
// Evaluate it and print the result or an error message.
