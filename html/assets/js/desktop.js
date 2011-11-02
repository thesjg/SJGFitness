function filesImporting()
{
}

function filesImported(data)
{
    var tcx = new JSONFitTCX();

    $.each(data, function(filename, data) {
        console.log("Filename: " + filename);
        tcx.fromTCX(data);
    });
}

$(document).ready(function(){
    if (window.SJGFitDesktop) {
        window.SJGFitDesktop.filesImporting.connect(this, filesImporting);
        window.SJGFitDesktop.filesImported.connect(this, filesImported);
    }
});