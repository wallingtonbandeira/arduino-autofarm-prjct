const int VALOR_EN_AIRE = 620;  //valor maximo que da el sensor en aire
const int VALOR_EN_AGUA = 310;  //valor maximo que da el sensor totalmente submergido
const int PIN_SENSOR_HUMEDAD = A0;

int valorSensorHumedad = 0;
int porcentajeValorSensorHumedad = 0;

void setup() {
    Serial.begin(9600);     //abre el puerto serial
}

//En estas funcion es donde se estara ejecutando el codigo de la placa en bucle
void loop() {
    
}

//Actualiza las variables con una lectura del sensor
void leerHumedadSuelo() {
    valorSensorHumedad = analogRead(PIN_SENSOR_HUMEDAD);
    porcentajeValorSensorHumedad = map(valorSensorHumedad, VALOR_EN_AIRE, VALOR_EN_AGUA, 0, 100);
}

int getValorSensorHumedad() {
    leerHumedadSuelo();
    return valorSensorHumedad;
}

int getPorcentajeHumedad() {
    leerHumedadSuelo();
    return porcentajeValorSensorHumedad;
}