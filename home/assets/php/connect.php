<?php
	function Connection(){
		$server="engr-cpanel-mysql.engr.illinois.edu";
		$user="resumepi_admin";
		$pass="people";
		$db="resumepi_occupancy";

		$connection = mysql_connect($server, $user, $pass);

		if (!$connection) {
	    	die('MySQL ERROR: ' . mysql_error());
		}

		mysql_select_db($db) or die( 'MySQL ERROR: '. mysql_error() );

		return $connection;
	}
?>
