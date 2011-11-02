/*
 * Depends on jQuery 1.6.2+
 *
 * Uses JSONFitTXC, JSONFitPWX and JSONFitGPX
 *
 *
 * {{ "JSONFIT":
 *     { "version": 1.0 },
 *  },
 *
 *  { "laps":
 *      { timeOffset: { "duration": seconds,
 *                      "label": "" },
 *       ...
 *      },
 *  },
 *  
 *  { "definition":
 *      ["heartRate", "position", "direction", "altitude", "power", "cadence"]
 *  },
 *  
 *  { "data":
 *      { timeOffset: { [] },
 *        ... }
 *  },
 *   
 *  { "athlete":
 *      { "name": "",
 *        "age": "" }
 *  },
 *  
 *   { "device":
 *      { "name": "",
 *        "version": "" }
 *  }
 * };
 */

function JSONFit()
{
    var version = 1.0;
    var laps = {};
    var definition = [];
    var data = {};

    return {
        setVersion: function(v)
        {
            version = v;
        },

        addLap: function(timeOffset, duration)
        {
        },

        setDefinition: function(definition)
        {
            this.definition = definition;
        },

        addDataPoint: function(timeOffset, data)
        {
            data[timeOffset] = data;
        },

        fromJSON: function()
        {
        },

        toJSON: function()
        {
        }
    };
};