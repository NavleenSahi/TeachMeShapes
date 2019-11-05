// This #include statement was automatically added by the Particle IDE.
#include <InternetButton.h>
InternetButton b = InternetButton();

int si = -1;
int rot;

void setup() {
    b.begin();
    rot = 0;
    
    Particle.function("rotate", rotationcheck);
}

void loop() {
    sidesInput();
}

void sidesInput(){
    if(b.buttonOn(2)){
        b.allLedsOn(255, 255, 255);
        b.allLedsOff();
        si = 0;
        Particle.publish("sid", String(si));
    }
    
    if(b.buttonOn(3)){
        b.allLedsOn(255, 255, 255);
        b.allLedsOff();
        si = 3;
        Particle.publish("sid", String(si));
    }
    
    if(b.buttonOn(4)){
        b.allLedsOn(255, 255, 255);
        b.allLedsOff();
        si = 4;
        Particle.publish("sid", String(si));
    }
    
    
}

int rotationcheck(String command){
    if(command == "check"){
        rot = b.readY();
        Particle.publish("rotation", String(rot));
    }
    
    return 1;
}