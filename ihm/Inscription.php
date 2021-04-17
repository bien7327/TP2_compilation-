<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "client";


  $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
  
  //prepRrion de la requette
  $sql = "INSERT INTO clients VALUES (NULL, :nom,:prenom , :mail , :passeword)";
  $pdostat = $conn->prepare($sql);

  // on lie chaque marqueur a une valeur
    $pdostat->bindValue(':nom', $_POST['nom'],PDO::PARAM_STR);
    $pdostat->bindValue(':prenom', $_POST['prenom'],PDO::PARAM_STR);
    $pdostat->bindValue(':mail', $_POST['mail'],PDO::PARAM_STR);
    $pdostat->bindValue(':passeword', $_POST['passeword'],PDO::PARAM_STR);
 //execution de la requette preparer

 $insert = $pdostat->execute();

 if ($insert){
     $message = 'ajout avec syccere';
 }
 else{
     $message = 'echeque';
 }
    ?>
  <!DOCTYPE html>
  <html lang="en">
  <head>
      <meta charset="UTF-8">
      <meta http-equiv="X-UA-Compatible" content="IE=edge">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Document</title>
  </head>
  <body>
      <H1>insertion </H1>
      <p> <?php echo $message; ?>  </p>
  </body>
  </html>