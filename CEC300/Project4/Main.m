%{
    Class: CEC 300
    Assignment: Project 4
    By: Cameron Stark

    Function: Calculates the trajectory and movement of two aircraft based
    off of starting latitude and longitude with the provided speed and
    heading for each aircraft

    Instructions: To run with predefined setup from assignment doc, run the
    main function other wise run ADSB(A_lat, A_lng, B_lat, B_lng, A_speed,
    B_speed, A_alt, B_alt, A_head, B_head, stepTime, totalTime
%}

function Main()
    ADSB(29.177661, -81.062119, 29.188851, -82.220902, 500, 510, 30000, 30050, 315, 45, 5, 8); 
end

function ADSB(A_lat, A_lng, B_lat, B_lng, A_speed, B_speed, A_alt, B_alt, A_head, B_head, stepTime, totalTime)
    Aspeed = convertKnotsToMPS(A_speed);
    Adistance = calculateDistanceInterval(Aspeed, stepTime);
    Bspeed = convertKnotsToMPS(B_speed);
    Bdistance = calculateDistanceInterval(Bspeed, stepTime);
    time = datetime('now');
    
    A_Lats = zeros(1, numel(totalTime/stepTime));
    A_Lngs = zeros(1, numel(totalTime/stepTime));
    B_Lats = zeros(1, numel(totalTime/stepTime));
    B_Lngs = zeros(1, numel(totalTime/stepTime));
    
    counter = 2;
    
    fileID = fopen("output.txt", 'wt');
    if (fileID == -1)
        disp("DID NOT WORK");
    end
    fprintf(fileID, "[%s %s %s %s %s]\n", "Aircraft", "TimeStamp", "Latitude", "Longitude", "Speed");
    
    timePassed = 0;
    A_Lats(1) = A_lat;
    A_Lngs(1) = A_lng;
    
    B_Lats(1) = B_lat;
    B_Lngs(1) = B_lng;
    fprintf('[%s, %s, %.6f, %.6f, %d]\n', "A", time, A_lat, A_lng, A_speed);
    fprintf('[%s, %s, %.6f, %.6f, %d]\n', "B", time, B_lat, B_lng, B_speed);
    totalTime = convertMinsToSecs(totalTime);
    while (timePassed < totalTime)
        A_lat = calculateLatMove(A_lat, A_head, Adistance);
        A_lng = calculateLngMove(A_lng, A_head, Adistance);
        A_Lats(counter) = A_lat;
        A_Lngs(counter) = A_lng;
        
        
        
        B_lat = calculateLatMove(B_lat, B_head, Bdistance);
        B_lng = calculateLngMove(B_lng, B_head, Bdistance);
        B_Lats(counter) = B_lat;
        B_Lngs(counter) = B_lng;
        
        printToFile("A", time, A_lat, A_lng, A_speed, fileID);
        printToFile("B", time, B_lat, B_lng, B_speed, fileID);
        fprintf('[%s, %s, %.6f, %.6f, %d]\n', "A", time, A_lat, A_lng, A_speed);
        fprintf('[%s, %s, %.6f, %.6f, %d]\n', "B", time, B_lat, B_lng, B_speed);
        time = time + seconds(stepTime);
        

        timePassed = timePassed + stepTime;
        counter = counter + 1;
        
        hold on;
        plot(A_Lats, A_Lngs, '+');
        hold on;
        plot(B_Lats, B_Lngs, 'x');
    end
    fclose(fileID);

end

function result = convertMinsToSecs(time)
    result = time * 60;
end

function result = convertKnotsToMPS(speed)
    result = speed * .51444444444;
end

function result = calculateDistanceInterval(speed, time)
    result = (speed * time);
end

function printToFile(aircraft, time, lat, lng, speed, file)
    time = datestr(time);
    fprintf(file, '[%s, %s, %.6f, %.6f, %d]\n', aircraft, time, lat, lng, speed);
    

end

function result = calculateLatMove(lat, head, distance)
    singleDegreeLat =  111.3;

    distanceTraversed = distance * sin(head);

    latTraversed = distanceTraversed / singleDegreeLat;
    
    result = lat + latTraversed;
end

function result = calculateLngMove(lng, head, distance)
    singleDegreeLng = 97.1;
    
    distanceTraversed = distance * cos(head);
    
    lngTraversed = distanceTraversed / singleDegreeLng;
    
    result = lng + lngTraversed;
end