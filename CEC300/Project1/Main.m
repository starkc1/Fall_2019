%{
    Class: CEC 300
    Assignment: Project 1
    By: Cameron Stark

    Function: Function to perfrom DME calculations on 4 signal times, two for the transmitted and 2 for the reply signal times.
        function returns results stating, which channel and distance, if signal is FRUIT, or if signal is garbled
    
    Instructions: To run predefined samples run the main function, other wise run the DME function such as DME(####, ####, ####, ####)
%}
function Main()
    DME(572, 584, 772, 784) %Channel X
    DME(1011, 1047, 1361, 1391) %Channel Y
    DME(1671, 1683, 2081, 2117)
    DME(2307, 2319, 2337, 2349) %Channel X Garbled
    DME(5181, 5217, 7767, 7797) %Channel Y
    DME(8011, 8047, 8300, 8322)
end

function DME(transmit1, transmit2, receive1, receive2)
    
    timeBetweenTransmit = transmit2 - transmit1;
    timeBetweenReceive = receive2 - receive1;
    
    timeBetweenFirstSignal = receive1 - transmit1;
    timeBetweenSecondSignal = receive2 - transmit2;
    distance = (timeBetweenFirstSignal - 50) / 12.36;
    
    if (timeBetweenFirstSignal < 50 || timeBetweenSecondSignal < 50)
        garbled()
    elseif (timeBetweenTransmit == 12 && timeBetweenReceive == 12)
        channelX(distance)
    elseif (timeBetweenTransmit == 36 && timeBetweenReceive == 30)
        channelY(distance)
    elseif ((timeBetweenTransmit == 12 && timeBetweenReceive == 30) || (timeBetweenTransmit == 36 && timeBetweenReceive == 12))
        fruit()
    elseif ((timeBetweenTransmit == 12 && timeBetweenReceive == 36) || (timeBetweenTransmit == 30 && timeBetweenReceive == 12))
        fruit()
    else 
        fruit()
    end
end

function garbled()
    fprintf("Signal Garbled\n")
end

function channelX(distance)
    if (distance > 200)
        fprintf("Channel is X, no reply\n")
    else 
        fprintf("Channel is X; distance is " + distance + " nautical miles\n")
    end
end

function channelY(distance)
    if (distance > 200)
        fprintf("Channel is Y, no reply\n")
    else
        fprintf("Channel is Y; distance is " + distance + " nautical miles\n")
    end 
end

function fruit()
    fprintf("FRUIT detected\n")
end