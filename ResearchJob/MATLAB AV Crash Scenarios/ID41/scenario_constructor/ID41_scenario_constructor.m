%%%% For users to create scenario
clear;
close all;
% load relevent files to get variable values
load('ID41_scenario.mat'); disp('ID #41 Scenario Loaded')
load('lanes.mat'); disp('Lane values loaded')
load('incidentDetails.mat'); disp('Incident details loaded');
close all;

% provide the variables necessary for 'road()'
roadWidth = 6;

% create plot    
    hFigure = figure;
    hAxes = axes(hFigure);
    plot(scenario,'Parent',hAxes,'Centerline','on','Waypoints','off','RoadCenters','off');
    hold on
    title("ID #"+ID);
    dimension = [4.1225e-05 3.7e-06 1 1];
    cityState = [city,', ',state];
    incidentLocation = ['Location: ',cityState];
    time = ['Time: ',crashTime];
    summ = ['Factors: ',otherCrashElement];
    company = ['Company: ',avCompany];
    make = ['Make: ',vehManufacturer];
    model = ['Model: ',vehModel];                                               
    annotation('textbox',dimension,'String',sprintf('%c%c%c%c%c%c%c%c%c%c%c',incidentLocation,newline,time,newline,summ,newline,company,newline,make,newline,model),'FitBoxToText','on','EdgeColor','none');
    xArrow = [0.50297619047619,0.574404761904762]; yArrow = [0.794444444444444,0.692857142857143];
    marker = annotation('textarrow',xArrow,yArrow,'String','Incident Location');%marks incident location
% record scenario
actorPositions = record(scenario);
