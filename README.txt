////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                                          ///
///       DIY Robot Arm                                                                                                      ///
///       Piece 3D : https://howtomechatronics.com/tutorials/arduino/diy-arduino-robot-arm-with-smartphone-control/          ///
///       Code et réalisation : Jules MAUMY, Antoine DEBBASCH - ECEBORG 10-2019 - ECE PARIS                                  ///
///                                                                                                                          ///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Le bras robot est un projet open source trouvé sur le site : https://howtomechatronics.com/tutorials/arduino/diy-arduino-robot-arm-with-smartphone-control/
Suite à la reproduction de ce projet, nous avons constaté que le robot ne marchait pas avec le code donné (full bug).
Nous sommes reparti de 0 pour le code et l'application.
Nous avons aussi rajouté une commande locale avec des potentiomètres.

Ce dossier contient : 
	- Les fichier STL pour le bras robot (OPENSOURCE sur le site du tuto)
	- Le fichier Fusion360 pour le boitier de commande (un peu petit) (Jules MAUMY)
	- Le fichier APK pour l'application sur Androïd
	- Le fichier MIT pour modifier l'application
	- Le fichier arduino pour le code

Matériels utilisés : 
	- Arduino Nano (ou Uno)
	- HC-05 (HC-06 a des bugs)
	- 3 servo-moteurs MG996R
	- 3 servo-moteurs SG90

Les 6 servo-moteurs sont controlés soit avec l'application bluetooth par l'envoi d'un octet à chaque action, soit par un potentiomètre lu avec des valeurs analogiques par l'arduino.
Le bluetooht marche très bien sans latence.
Concernant les potentiomètres, nous avons un problème d'interférence entre les fils qui fausse la lecture analogique. Pour essayer de rémédier à ce problème, nous avons ajouté un delay d'actualisation des lectures analogiques.

Un switch permet de choisir le mode de commande et stoppe celui qui n'est pas utilisé.
