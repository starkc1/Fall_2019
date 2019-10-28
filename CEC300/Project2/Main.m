%{
    Class: CEC 300
    Assignment: Project 2
    By: Cameron Stark

    Function: Function to convert the provided and correct 4 digit octal
code to the the associated Gilham Binary Pulse, to check if octal the
values providedneed to be less then 8

    Instructions: To run predefined samples run the main function, 
otherwise run the DME function such as ACTRBS(#, #, #, #) where # < 8
%}

%Main Function for predefined samples
function Main()
    ATCRBS(0,0,4,0);
    ATCRBS(0,4,4,0);
    ATCRBS(0,0,6,2);
    ATCRBS(1,2,3,9);
end

%ATCRBS function for taking in the four octal values, checking if the are
%valid and performing the conversion
function ATCRBS(value1, value2, value3, value4) 
    if (checkIfOctal(value1) == false)
        fprintf("Invalid Input\n");
        return;
    end
    
    if (checkIfOctal(value2) == false)
        fprintf("Invalid Input\n");
        return;
    end
    
    if (checkIfOctal(value3) == false)
        fprintf("Invalid Input\n");
        return;
    end
    
    if (checkIfOctal(value4) == false)
        fprintf("Invalid Input\n");
        return;
    end
       
    grayValue1 = getGrayCode(value1);
    grayValue2 = getGrayCode(value2);
    grayValue3 = getGrayCode(value3);
    grayValue4 = getGrayCode(value4);
       
    C1 = grayValue3(3:3);
    A1 = grayValue1(3:3);
    C2 = grayValue3(2:2);
    A2 = grayValue1(2:2);
    C4 = grayValue3(1:1);
    A4 = grayValue1(1:1);
    B1 = grayValue2(3:3);
    D1 = grayValue4(3:3);
    B2 = grayValue2(2:2);
    D2 = grayValue4(2:2);
    B4 = grayValue2(1:1);
    D4 = grayValue4(1:1);
    
    fprintf("Pulse: " + '0' + D2 + D4 + " " + A1 + A2 + A4 + " " + B1 + B2 + B4 + " " + C1 + C2 + C4 + "\n");
end

%function to check if the value is less then 8
function result = checkIfOctal(value)
    if (value >= 8)
       result = false;
       return;
    end
    result = true;
    return;
end

%function to convert the octal value to binary
function result = getGrayCode(value)
    if (value == 0)
        result = '000';
    elseif (value == 1)
        result = '001';
    elseif (value == 2)
        result = '010';
    elseif (value == 3)
        result = '011';
    elseif (value == 4)
        result = '100';
    elseif (value == 5)
        result = '101';
    elseif (value == 6)
        result = '110';
    elseif (value == 7)
        result = '111';
    end
end