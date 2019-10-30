%%%% For users to create scenario
clear;
close all;
% load relevent files to get variable values
load('ID14_scenario.mat'); disp('ID #14 Scenario Loaded')
load('lanes.mat'); disp('Lane values loaded')
load('incidentDetails.mat'); disp('Incident details loaded')
close all;

% provide the variables necessary for 'road()'
roadWidth = 6;

% create plot    
    hFigure = figure;
    hAxes = axes(hFigure);
    plot(scenario,'Parent',hAxes,'Centerline','on','Waypoints','off','RoadCenters','off');
    hold on

    title("ID #14");
    dimension = [4.1225e-05 3.7e-06 1 1];
    cityState = [city,', ',state];
    incidentLocation = ['Location: ',cityState];
    time = ['Time: ',crashTime];
    %summ = 'Summary: Pedestrian crossing in front of autonomous vehicle was struck and fatally wounded. AV test supervisor was distracted. AV safety features were disabled.';
    summ = ['Factors: ',otherCrashElement];
    company = ['Company: ',avCompany];
    make = ['Make: ',vehManufacturer];
    model = ['Model: ',vehModel];
    annotation('textbox',dimension,'String',sprintf('%c%c%c%c%c%c%c%c%c%c%c',incidentLocation,newline,time,newline,summ,newline,company,newline,make,newline,model),'FitBoxToText','on','EdgeColor','none');
    xArrow = [0.600595238095238,0.532738095238095]; yArrow = [0.286507936507937,0.380158730158733];
    marker = annotation('textarrow',xArrow,yArrow,'String','Incident Location');%marks incident location

% record scenario
actorPositions = record(scenario);
