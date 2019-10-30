%%%% For users to create scenario
clear;
close all;
% load relevent files to get variable values
load('ID2_scenario.mat'); disp('ID #2 Scenario Loaded')
load('lanes.mat'); disp('Lane values loaded')
load('incidentDetails.mat'); disp('Incident details loaded')
close all;

% provide the variables necessary for 'road()'
roadWidth = 6;

% create plot
    hAxes = axes(figure);
    xArrow = [0.682738095238095,0.554166666666667]; yArrow = [0.583920634920635,0.434126984126984];
    plot(scenario,'Parent',hAxes,'Centerline','on','Waypoints','off','RoadCenters','off');
    marker = annotation('textarrow',xArrow,yArrow,'String','Incident Location');%marks incident location
    hold on
    title("ID #2");
    dimension = [4.1225e-05 3.7e-06 1 1];
    cityState = [city,', ',state];
    incidentLocation = ['Location: ',cityState];
    time = ['Time: ',crashTime];
    summ = ['Factors: ',otherCrashElement];
    company = ['Company: ',avCompany];
    make = ['Make: ',vehManufacturer];
    model = ['Model: ',vehModel];
    annotation('textbox',dimension,'String',sprintf('%c%c%c%c%c%c%c%c%c%c%c',incidentLocation,newline,time,newline,summ,newline,company,newline,make,newline,model),'FitBoxToText','on','EdgeColor','none');

 accessoryPath=struct2array(load('accessoryPath.mat'));
 trajectory(scenario.Actors(7),accessoryPath(end:-1:1,:) +[1.5,1.5,0],55);

% record scenario
actorPositions = record(scenario);
