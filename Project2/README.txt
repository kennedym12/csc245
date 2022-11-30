Project 2
Kennedy Mays
CSC 245

PART 1 | Postfix Evaluator (calculator)

Overview
- code a client program that accepts an equation as a string in postfix format then evaluates it, showing all the stack operations taken

Input
- valid inputs: +, -, *, /, %, and multi-digit numbers
- ints can be separated by spaces or '_', the latter indicates a -ve number
- store input as string then parse into data types (int/char) that can be evaluated
- loop with internal switch statement for each possibility
- get token, perform stack manipulation, until the end of the string is reached

Parsing
- '_': get the following int(s)
- ' ': get the following char/int
- operator: pop top two values then push resultant value
- num: get remaining ints (if they exist)

Evaluation
- parse at: '_', ' ', & data type changes to get token
- for operands, push integers to stack
- for operators, pop top two values then push resultant value

Exceptions
- use try, catch, & throw for exception handling
- catch: 0 div, invalid input, full/empty stack
- check for invalid input during parsing  
- check others during stack manipulation

PART 2 | Binary Expression Tree

Overview
- read infix formatted expressions from a .dat file then output the preorder traversal of a binary expression tree (BET)
- one loop through should include the conversion of 1 expression

Input
- read in ons line as an expression from the .dat file

getPostfix(string s)
- uses a stack to convert Infix to Postfix
- add the numbers to the output string
- push the '(' to the stack
- check for operators of >= curr operator on top of stack, pop them to the output string, push the curr operator to the stack
- pop operators to output string when ')' until '(' is found
- pop remaining operators at the end of the expression

prec(char c)
- accompanies the getPostfix() in providing the precedence of each operator
- allows the aforementioned function to work properly

getTree(string s)
- create a stack to hold BetNode pointers
- loop through string to create pointer for each char & interact w/ stack accordinly
- for operand: create pointer then push to stack
- for operator: create pointer, pop top two pointers & assign them as children, then push the operator pointer

isOperator(char c)
- assists get tree in knowing how to treat a char based on whether or not it's an operator
- returns true if the character is in the string of valid operators

preorder(BetNode* h)
- recursive method that prints the contents of the BET in preorder
- also serves as the postfix format of the original expression