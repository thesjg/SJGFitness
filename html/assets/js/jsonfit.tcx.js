/*
 * Depends on jQuery 1.6.2+
 */

function JSONFitTCX()
{

    /*
     * Takes an XML string
     */
    var parseTCX = function(data)
    {
        var xmlDoc = $.parseXML(data);
        var xml = $(xmlDoc);

        var heartRateEnabled = false;
        var positionEnabled = false;
        var directionEnabled = false;
        var altitudeEnabled = false;
        var powerEnabled = false;
        var cadenceEnabled = false;

        var data = [];

        xml.find("Activity").each(function(){
            var activity = $(this);
            activity.find("Lap").each(function(){
                var lap = $(this);

                var lapStartTime = 0;
                var lapEndTime = 0;
                var lapDuration = 0;

                lap.find("Trackpoint").each(function(){
                    var trackpoint = $(this);

                    var time = trackpoint.find("Time").text();

                    var heartRate = 0;
                    trackpoint.find("HeartRateBpm").each(function(){
                        heartRateEnabled = true;
                        heartRate = parseInt($(this).find("Value").text());
                    });

                    var position = [];
                    trackpoint.find("Position").each(function(){
                        positionEnabled = true;
                        var lat = parseFloat($(this).find("LatitudeDegrees").text());
                        var lng = parseFloat($(this).find("LongitudeDegrees").text());
                        position = [lat, lng];
                    });

                    var direction = 0;
                    /* Implement direction */

                    var altitude = 0;
                    if (altitude = parseFloat(trackpoint.find("AltitudeMeters").text()))
                        altitudeEnabled = true;

                    var power = 0;
                    trackpoint.find("Extensions").each(function(){
                        if (power = parseInt($(this).find("Watts").text()))
                            powerEnabled = true;
                    });

                    var cadence = parseInt(trackpoint.find("Cadence").text());

                    data.push([time, heartRate, position, direction, altitude, power, cadence]);
                });
            });
        });

        console.log("Creating new JSONFit instance");

        var fit = new JSONFit();
        fit.setVersion(1.0);

        var definitions = [];
        if (heartRateEnabled)
            definitions.push("heartRate");
        if (positionEnabled)
            definitions.push("position");
        if (directionEnabled)
            definitions.push("direction");
        if (altitudeEnabled)
            definitions.push("altitude");
        if (powerEnabled)
            definitions.push("power");
        if (cadenceEnabled)
            definitions.push("cadence");

        console.log("Setting JSONFit definitions to: " + definitions);
        fit.setDefinition(definitions);

        $.each(data, function(index, point){
            var timeOffset = point.shift();
console.log("Working with timeOffset: " + timeOffset);
            var rpoint = [];
            if (heartRateEnabled) rpoint.push(point[0]);
            if (positionEnabled) rpoint.push(point[1]);
            if (directionEnabled) rpoint.push(point[2]);
            if (altitudeEnabled) rpoint.push(point[3]);
            if (powerEnabled) rpoint.push(point[4]);
            if (cadenceEnabled) rpoint.push(point[5]);
console.log("Setting Data Point: " + rpoint);
            fit.addDataPoint(timeOffset, rpoint); 
        });

        console.log("JSONFit Object: " + fit);
    }

    return {
        fromTCX: function(data)
        {
            if (typeof(data) == "string")
                parseTCX(data);
        },

        toJSON: function()
        {
        }    
    };
};