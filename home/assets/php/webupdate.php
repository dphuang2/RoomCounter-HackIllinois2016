<?php
  include("connect.php");
  $link = Connection();

  $query = "SELECT `name`, `count` FROM `counts` WHERE 1";

  $result = mysql_query($query,$link);

  $firstquery = 1;

  echo "{";
  while ($row = mysql_fetch_array($result, MYSQL_ASSOC)) {
    if($firstquery > 0){
      echo '"' . $row["name"]. '": ' . '"' .$row["count"] . '"';
      $firstquery--;
    } else{
      echo ', "' . $row["name"]. '": ' . '"' .$row["count"] . '"';
    }
  }
  echo "}";
?>
