<?php
  include("connect.php");

  $link=Connection();

  $location=mysql_real_escape_string($_POST['location']);
  $count=intval($_POST['count']);

  // $location = 'ECEB';
  // $location = mysql_real_escape_string($location);
  // $count = intval(2);
  //
  // if (is_null($_POST["location"]) || is_null($_POST["count"])) {
  //   $location = 'Grainger';
  //   $location = mysql_real_escape_string($location);
  //   $count = intval(5);
  // }

  $query = "UPDATE `counts` SET `count`= `count` + $count WHERE `name` = '$location'";

  mysql_query($query,$link);
  mysql_close($link);

  header("Location: ../../index.php");
?>
