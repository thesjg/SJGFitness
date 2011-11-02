$(document).ready(function(){
    $("#calendar .controls").live({
        mouseenter: function() {
            $(this).fadeTo("fast", 1.0);
        },
        mouseleave: function() {
            $(this).fadeTo("fast", 0.2);
        }
    });
});