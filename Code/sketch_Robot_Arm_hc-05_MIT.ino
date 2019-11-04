////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                                          ///
///       DIY Robot Arm                                                                                                      ///
///       Piece 3D : https://howtomechatronics.com/tutorials/arduino/diy-arduino-robot-arm-with-smartphone-control/          ///
///       Code : Jules MAUMY, Antoine DEBBASCH - ECEBORG 10-2019 - ECE PARIS                                                 ///
///                                                                                                                          ///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Bibliothèque pour créer un port série virtuel pour communiqué avec le HC-05
#include <SoftwareSerial.h>
// Bibliothèque pour commander les servo-moteurs
#include <Servo.h>

// Port série
#define rxPin 2
#define txPin 3

// Potentiomètre
#define potoS1 A3
#define potoS2 A2
#define potoS3 A1
#define potoS4 A6
#define potoS5 A5
#define potoS6 A4

// Switch choix de la commande
#define switchHC05 11

#define baudrate 9600

// Déclaration servo moteur
Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;

// Déclaration variable de position de chaque servo
int positionS1 = 90;
int positionS2 = 90;
int positionS3 = 90;
int positionS4 = 90;
int positionS5 = 90;
int positionS6 = 90;

// Valeur de l'octet reçu => bouton appuyé
int state = 0;

// Vitesse de base
int vitesse = 10;

// Etat du switch de commande
int etatSwitchHC05 = 0;

// Déclaration de port série virtuel
SoftwareSerial hc05(rxPin,txPin);

void setup()
{
    // Pin de chaque servo
    servo01.attach(5);
    servo02.attach(6);
    servo03.attach(7);
    servo04.attach(8);
    servo05.attach(9);
    servo06.attach(10);

    // Setup des positions des servo
    servo01.write(90);
    servo02.write(90);
    servo03.write(90);
    servo04.write(90);
    servo05.write(90);
    servo06.write(90);
    
    // Pin du switch de commande
    pinMode(switchHC05, INPUT);

    // Pin de chaque potentiomètre
    pinMode(potoS1, INPUT);
    pinMode(potoS2, INPUT);
    pinMode(potoS3, INPUT);
    pinMode(potoS4, INPUT);
    pinMode(potoS5, INPUT);
    pinMode(potoS6, INPUT);

    // Initialisation des ports séries
    pinMode(rxPin,INPUT);
    pinMode(txPin,OUTPUT);
    Serial.begin(9600);
    hc05.begin(baudrate);
}
void loop()
{   
    // On lit l'etat du bouton de commande pour savoir quelle commande activer
    etatSwitchHC05 = digitalRead(switchHC05);

    // Si le bluetooth est selectionné alors on exécute le code bluetooh
    if(etatSwitchHC05 == HIGH){
    
        // Si des octets sont envoyés alors attribuer le nombre reçu dans la valeur state (et ecrire dans la console)
        if (hc05.available()>0)
        {
            state = hc05.read();
            Serial.println(state);
        }
    
        ////////////////////////////////
        ///         SERVO 1          ///
        ////////////////////////////////
        
        // Bouton plus
    
        // Si la valeur state est égale à 1 (bouton enfoncé) et que le position est situé entre 0 et 180 alors...
        if ((state == 3) && (positionS1<=180) && (positionS1>=0))
        {
            //...augmenter de 1 degres tant que cette condition est vrai. Stopper d'incrémenter à 180 pour éviter de dépasser les capacités des servos
            if (positionS1 != 180)
            {
                positionS1+=1;
            }

            // Cette ligne n'est pas utile juste une info
            Serial.println(positionS1);
            
            // delay de la vitesse pour ralentir la vitesse des servo moteur
            delay(vitesse);

            // Et on envoie l'ordre au servo
            servo01.write(positionS1);
        }
    
        // Si la valeur state est égale à 2 (bouton relaché) alors stopper le servo et ecrire stop dans la console et mettre à 0 le state pour stopper les boucles
        else if (state == 4)
        {
          Serial.println(positionS1);
            Serial.println("Stop");
            state = 0;
        }

        // De la même façon pour tous les autres moteurs
        
        // Bouton moins
        else if ((state == 1) && (positionS1<=180) && (positionS1>=0))
        {
            if (positionS1 != 0)
            {
                positionS1-=1;
            }
            delay(vitesse);
            servo01.write(positionS1);
        }
        else if (state == 2)
        {
            Serial.println("Stop");
            state = 0;
        }
    
        ////////////////////////////////
        ///         SERVO 2          ///
        ////////////////////////////////
        else if ((state == 7) && (positionS2<=180) && (positionS2>=0))
        {
            if (positionS2 != 180)
            {
                positionS2+=1;
            }
            delay(vitesse);
            servo02.write(positionS2);
        }
        else if (state == 8)
        {
            Serial.println("Stop");
            state = 0;
        }
    
        else if ((state == 5) && (positionS2<=180) && (positionS2>=0))
        {
            if (positionS2 != 0)
            {
                positionS2-=1;
            }
            delay(vitesse);
            servo02.write(positionS2);
        }
        else if (state == 6)
        {
            Serial.println("Stop");
            state = 0;
        }
    
        ////////////////////////////////
        ///         SERVO 3          ///
        ////////////////////////////////
        else if ((state == 9) && (positionS3<=180) && (positionS3>=0))
        {
            if (positionS3 != 180)
            {
                positionS3+=1;
            }
            delay(vitesse);
            servo03.write(positionS3);
        }
        else if (state == 10)
        {
            Serial.println("Stop");
            state = 0;
        }
    
        else if ((state == 11) && (positionS3<=180) && (positionS3>=0))
        {
            if (positionS3 != 0)
            {
                positionS3-=1;
            }
            delay(vitesse);
            servo03.write(positionS3);
        }
        else if (state == 12)
        {
            Serial.println("Stop");
            state = 0;
        }
    
        ////////////////////////////////
        ///         SERVO 4          ///
        ////////////////////////////////
        else if ((state == 13) && (positionS4<=180) && (positionS4>=0))
        {
            if (positionS4 != 180)
            {
                positionS4+=1;
            }
            delay(vitesse);
            servo04.write(positionS4);
        }
        else if (state == 14)
        {
            Serial.println("Stop");
            state = 0;
        }
    
        else if ((state == 15) && (positionS4<=180) && (positionS4>=0))
        {
            if (positionS4 != 0)
            {
                positionS4-=1;
            }
            delay(vitesse);
            servo04.write(positionS4);
        }
        else if (state == 16)
        {
            Serial.println("Stop");
            state = 0;
        }
    
        ////////////////////////////////
        ///         SERVO 5          ///
        ////////////////////////////////
        else if ((state == 19) && (positionS5<=180) && (positionS5>=0))
        {
            if (positionS5 != 180)
            {
                positionS5+=1;
            }
            delay(vitesse);
            servo05.write(positionS5);
        }
        else if (state == 20)
        {
            Serial.println("Stop");
            state = 0;
        }
    
        else if ((state == 17) && (positionS5<=180) && (positionS5>=0))
        {
            if (positionS5 != 0)
            {
                positionS5-=1;
            }
            delay(vitesse);
            servo05.write(positionS5);
        }
        else if (state == 18)
        {
            Serial.println("Stop");
            state = 0;
        }
    
        ////////////////////////////////
        ///         SERVO 6          ///
        ////////////////////////////////
        else if ((state == 21) && (positionS6<=180) && (positionS6>=0))
        {
            if (positionS6 != 180)
            {
                positionS6+=1;
            }
            delay(vitesse);
            servo06.write(positionS6);
        }
        else if (state == 22)
        {
            Serial.println("Stop");
            state = 0;
        }
    
        else if ((state == 23) && (positionS6<=180) && (positionS6>=0))
        {
            if (positionS6 != 0)
            {
                positionS6-=1;
            }
            delay(vitesse);
            servo06.write(positionS6);
        }
        else if (state == 24)
        {
            Serial.println("Stop");
            state = 0;
        }
    
        ////////////////////////////////
        ///          SPEED           ///
        ////////////////////////////////
        else if (state == 25)
        {
            Serial.println("Vitesse : Faible");
            vitesse = 20;
            state = 0;
        }
        else if (state == 26)
        {
            Serial.println("Vitesse : Moyen");
            vitesse = 10;
            state = 0;
        }
        else if (state == 27)
        {
            Serial.println("Vitesse : Rapide");
            vitesse = 5;
            state = 0;
        }
    }

    // Si le switch est selectionné sur local alors on exécute ce code
    else if(etatSwitchHC05 == LOW){

        // On lit la valeur de chaque potentiomètre
        positionS1 = analogRead(potoS1);

        // On map pour adapter la valeur entre 0 et 180 (5 et 175 sont préférable car les servos vont jamais jusqu'à fond
        positionS1 = map(positionS1,0,1023,5,175);

        // Puis on donne l'ordre au servo à partir de la valeur du potentiomètre
        servo01.write(positionS1);

        positionS2 = analogRead(potoS2);
        positionS2 = map(positionS2,0,1023,5,175);
        servo02.write(positionS2);

        positionS3 = analogRead(potoS3);
        positionS3 = map(positionS3,0,1023,5,175);
        servo03.write(positionS3);

        positionS4 = analogRead(potoS4);
        positionS4 = map(positionS4,0,1023,5,175);
        servo04.write(positionS4);

        positionS5 = analogRead(potoS5);
        positionS5 = map(positionS5,0,1023,5,175);
        servo05.write(positionS5);

        positionS6 = analogRead(potoS6);
        positionS6 = map(positionS6,0,1023,5,175);
        servo06.write(positionS6);

        // Ce delay permet d'atténuer les interférences, il peut etre modifier en fonction des installations
        delay(50);
    }
}
