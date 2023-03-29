<?php
$Temp = $_GET['temp'];                  
$Humidity = $_GET['hum'];   
$Wind = $_GET['wind'];
$Lux = $_GET['lux'];

$date = date('d/m/Y h:i:s a', time());  


$fileContent = "Temp is ".$Temp."°C and Humidity is ".$Humidity."% Lux is ".$Lux." Wind is ".$Wind."ms at ".$date."\n";


$status = file_put_contents('log.txt',$fileContent,FILE_APPEND);



//File writing status
if($status)
    echo "Data written successfully.";
else
    echo "Something went wrong!";
?>