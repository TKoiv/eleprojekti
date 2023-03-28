<?php
$Temp = $_GET['temp'];                  
$Humidity = $_GET['hum'];               
$date = date('d/m/Y h:i:s a', time());  


$fileContent = "Temp is ".$Temp."°C and humidity is ".$Humidity."% at ".$date."\n";

.
$status = file_put_contents('log.txt',$fileContent,FILE_APPEND);
$status = file_put_contents('current.txt',$fileContent);



//File writing status
if($status)
    echo "Data written successfully.";
else
    echo "Something went wrong!";
?>