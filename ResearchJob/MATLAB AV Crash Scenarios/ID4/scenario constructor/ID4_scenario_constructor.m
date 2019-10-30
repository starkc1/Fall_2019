%%%% For users to create scenario
clear;
close all;
% load relevent files to get variable values
load('ID4_scenario.mat'); disp('ID #3 Scenario Loaded')
load('lanes.mat'); disp('Lane values loaded')
load('incidentDetails.mat'); disp('Incident details loaded')
close all;

% provide the variables necessary for 'road()'
roadWidth = 6;

% create plot
    hAxes = axes(figure);
    plot(scenario,'Parent',hAxes,'Centerline','on','Waypoints','off','RoadCenters','off');
    hold on
    
    xArrow = [0.549404761904762,0.479166666666667]; yArrow = [0.565873015873016,0.45952380952381];
    marker = annotation('textarrow',xArrow,yArrow,'String','Incident Location');%marks incident location
    title("ID #4");
    
    dimension = [4.1225e-05 3.7e-06 1 1];
    cityState = [city,', ',state];
    incidentLocation = ['Location: ',cityState];
    time = ['Time: ',crashTime];
    summ = ['Factors: ',otherCrashElement];
    company = ['Company: ',avCompany];
    make = ['Make: ',vehManufacturer];
    model = ['Model: ',vehModel];
    annotation('textbox',dimension,'String',sprintf('%c%c%c%c%c%c%c%c%c%c%c',incidentLocation,newline,time,newline,summ,newline,company,newline,make,newline,model),'FitBoxToText','on','EdgeColor','none');

% record scenario
actorPositions = record(scenario);
