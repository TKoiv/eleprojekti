<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

<title>Sääasema</title>
<link rel="stylesheet" type="text/css" href="pinkkisivu.css">
</head>
<body>


<div class="grid-container">

<div class="grid-child purple">
<?php
        $file = fopen("log.txt", "r") or die("Errori ei aukia");
        fseek($file, -1, SEEK_END);
        $line = fgets($file);
        while(fread($file, 1) != "\n") 
{
    fseek($file, -2, SEEK_CUR);
}
        $last_line = fgets($file);
        fclose($file);
        $filtered = substr($last_line, 37, 13); // get a substring starting at position 10 with a length of 5
        echo ""; echo $filtered;
        ?>
</div>

    <div class="grid-child green">
        <?php
        $file = fopen("log.txt", "r") or die("Errori ei aukia");
        fseek($file, -1, SEEK_END);
        $line = fgets($file);
        while(fread($file, 1) != "\n") 
{
        fseek($file, -2, SEEK_CUR);
}
        $last_line = fgets($file);
        fclose($file);
        $filtered = substr($last_line, 18, 8); // get a substring starting at position 10 with a length of 5
        echo ""; echo $filtered;
        ?>
    </div>
  
</div>

<h1> <a href="https://ryhma5eleprojekti.000webhostapp.com/">Refresh</a> </h1>

<div class="grid-container">

    <div class="grid-child purple">
        
        <?php
        $file = fopen("log.txt", "r") or die("Errori ei aukia");
        fseek($file, -1, SEEK_END);
        $line = fgets($file);
        while(fread($file, 1) != "\n") 
{
        fseek($file, -2, SEEK_CUR);
}
        $last_line = fgets($file);
        fclose($file);
        $filtered = substr($last_line, 1, 12);
        echo ""; echo $filtered;
        ?>
    </div>

    <div class="grid-child green">
        <?php
        $file = fopen("log.txt", "r") or die("Errori ei aukia");
        fseek($file, -1, SEEK_END);
        $line = fgets($file);
        while(fread($file, 1) != "\n") 
{
        fseek($file, -2, SEEK_CUR);
}
        $last_line = fgets($file);
        fclose($file);
        $filtered = substr($last_line, 33, 11);
        
        echo ""; echo $filtered;
        ?>
    </div>
  
</div>

</body>
</html>
