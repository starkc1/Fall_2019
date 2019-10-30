%%%% For users to create scenario
clear;
close all;
% load relevent files to get variable values
load('ID12_scenario.mat'); disp('ID #12 Scenario Loaded')
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

    title("ID #12");
    dimension = [4.1225e-05 3.7e-06 1 1];
    cityState = [city,', ',state];
    incidentLocation = ['Location: ',cityState];
    time = ['Time: ',crashTime];
    summ = ['Factors: ',otherCrashElement];
    company = ['Company: ',avCompany];
    make = ['Make: ',vehManufacturer];
    model = ['Model: ',vehModel];
    annotation('textbox',dimension,'String',sprintf('%c%c%c%c%c%c%c%c%c%c%c',incidentLocation,newline,time,newline,summ,newline,company,newline,make,newline,model),'FitBoxToText','on','EdgeColor','none');
    xArrow = [0.599404761904762,0.548214285714286]; yArrow = [0.626190476190477,0.529365079365081];
    marker = annotation('textarrow',xArrow,yArrow,'String','Incident Location');%marks incident location
    
% record scenario
actorPositions = record(scenario);
