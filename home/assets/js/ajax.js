window.onload = function () {
  $.ajax({
    type: "POST",
    url: "/assets/php/webupdate.php",
    data: {},
    dataType: 'text',
    cache: false,
    // beforeSend: function() {
    //   alert("beforesend activated");
    // }
    success: function(response) {
      // alert(response);
      var array = jQuery.parseJSON(response); // Turn text response into JS object
      // if(array == null){
      //   alert("The array is null");
      // }
      console.log(array);
      console.log(array["ECEB"]);
      // alert(array.ECEB);
      $.each(array, function( index, value ) {
        // alert( index + ": " + value );
        roomname = "." + index + " > .occupancy";
        // alert(roomname);
        occupancy = value + " ";
        // alert(occupancy);
        $(roomname).html(occupancy);
      });
    // $("#feed").html(response);
    }
    });
  $("#refresh").click(function() {
    $.ajax({
      type: "POST",
      url: "/assets/php/webupdate.php",
      data: {},
      dataType: 'text',
      cache: false,
      // beforeSend: function() {
      //   alert("beforesend activated");
      // }
      success: function(response) {
        // alert(response);
        var array = jQuery.parseJSON(response); // Turn text response into JS object
        // if(array == null){
        //   alert("The array is null");
        // }
        console.log(array);
        console.log(array["ECEB"]);
        // alert(array.ECEB);
        $.each(array, function( index, value ) {
          // alert( index + ": " + value );
          roomname = "." + index + " > .occupancy";
          // alert(roomname);
          occupancy = value + " ";
          // alert(occupancy);
          $(roomname).html(occupancy);
        });
      // $("#feed").html(response);
      }
      });

  });
}
