const int VALOR_EN_AIRE = 620;  //valor maximo que da el sensor en aire
const int VALOR_EN_AGUA = 310;  //valor maximo que da el sensor totalmente submergido

int valorSensorHumedad = 0;
int porcentajeValorSensorHumedad = 0;

void setup() {
    Serial.begin(9600);     //abre el puerto serial
}

//En estas funcion es donde se estara ejecutando el codigo de la placa en bucle
void loop() {

}

int leerHumedadSuelo() {
    
}