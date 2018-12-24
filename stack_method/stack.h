bool isOperator(char character) {
    if (character == '+' || character == '-' || character == '*' || character == '/') {
        return true;
    }
    return false;
}

bool isOperand(char character) {
    if (!isOperator(character) && character != '(' && character != ')') {
        return true;
    }
    return false;
}

int compareOperators(char op1, char op2) {
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) { return -1; }
    else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) { return 1; }
    return 0;
}

string infixtopostfix(char* input)
{
    stack<char> opStack;
    string postFixString = "";

    char *cPtr = input;

    while (*cPtr != '\0') {
        if (isOperand(*cPtr)) { postFixString += *cPtr; }
        else if (isOperator(*cPtr)) {
            while (!opStack.empty() && opStack.top() != '(' && compareOperators(opStack.top(),*cPtr) <= 0) {
                postFixString += opStack.top();
                opStack.pop();
            }
            opStack.push(*cPtr);
        }
        else if (*cPtr == '(') { opStack.push(*cPtr); } 
        else if (*cPtr == ')') {
            while (!opStack.empty()) {
                if (opStack.top() == '(') { opStack.pop(); break; }
                postFixString += opStack.top();
                opStack.pop();
            }
        }
        cPtr++;
    }

    while (!opStack.empty()) {
        postFixString += opStack.top();
        opStack.pop();
    }

    return postFixString;
}
char checkForOperator(char a)
{
    switch(a)
    {
        case '+':case '-':case '/':case '*':return a;
        default: return 0;  
    }
}
ld operater(char a,ld inp,ld outp)
{
    switch(a)
    {
        case '+':   return inp+outp;
        case '-':   return inp-outp;
        case '/':   return inp/outp;
        case '*':   return inp*outp;
    }
}

ld evaluate(ld x)
{
    vector<ld> v(0);
    for(int i=0;i<expression.size();i++)
    {
        char c;
        if(c=checkForOperator(expression[i]))
        {
            int k=v.size();
            v[k-2]=operater(c,v[k-2],v[k-1]); 
            v.pop_back();
        }
        else if(expression[i]=='x')
            v.push_back(x);
        else v.push_back(expression[i]-48);
    }
    return v[0];
}