<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "chcnaq";


  $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
  
  //prepRrion de la requette
  var_dump ($_POST) ;
  $sql = "INSERT INTO contact VALUES (NULL, :nom,:prenom , :mail , :objet , :messag)";
  $pdostat = $conn->prepare($sql);

  // on lie chaque marqueur a une valeur
    $pdostat->bindValue(':nom', $_POST['firstname'],PDO::PARAM_STR);
    $pdostat->bindValue(':prenom', $_POST['lastname'],PDO::PARAM_STR);
    $pdostat->bindValue(':mail', $_POST['mail'],PDO::PARAM_STR);
    $pdostat->bindValue(':objet', $_POST['objet'],PDO::PARAM_STR);
    $pdostat->bindValue(':massag', $_POST['message'],PDO::PARAM_STR);
 //execution de la requette preparer

 $insert = $pdostat->execute();

 if ($insert){
     $message = 'votre message a ete prix en concideration';
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