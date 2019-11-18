%{
    Class: CEC 300
    Assignment: Project 3
    By: Cameron Stark

    Function: Create a gold code sequence

    Instructions: Run the Main method which will start with the
    initialization of 10 1's for each register or run GoldCode() with the
    two parameters of arrays with 10 values in each of only 1's and 0's
%}

function Main()
    GoldCode([1,1,1,1,1,1,1,1,1,1], [1,1,1,1,1,1,1,1,1,1]);
end

function GoldCode(register1, register2)
    goldCode = [0,0,0,0,0,0,0,0,0,0];
    goldCodeCount = 0;
    
    while (goldCodeCount < 10)
        register1 = G1_Op(register1);
        register2 = G2_Op(register2);

        goldCode(goldCodeCount + 1) = genPRN(register1, register2);

        goldCodeCount = goldCodeCount + 1;
    end
    disp(goldCode);
end

function result = genPRN(register1, register2)
    
    reg2Val = xor(register2(2), register2(6));
    prn = xor(register1(10), reg2Val);

    result = prn;
end

function result = G1_Op(register)
    newVal = xor(register(3), register(10));
    register = shiftRight(register);
    register(1) = newVal;
    
    result = register;
end

function result = G2_Op(register)
    newRegister = register;
    newVal = xor(register(2), register(3));
    newRegister = shiftRight(newRegister);
    newRegister(1) = newVal;
    
    newVal = xor(register(6), register(8));
    newRegister = shiftRight(newRegister);
    newRegister(1) = newVal;
    
    newVal = xor(register(9), register(10));
    newRegister = shiftRight(newRegister);
    newRegister(1) = newVal;

    result = newRegister;
end

function result = shiftRight(register)
    result = [1,1,1,1,1,1,1,1,1,1];
    resultCount = 2;
    for num = register
        if (resultCount == 10) 
            break;
        else 
            result(resultCount) = num;
            resultCount = resultCount + 1;
        end
    end
    
    result(1) = result(2);
end