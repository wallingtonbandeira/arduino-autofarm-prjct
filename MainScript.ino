
/**Para obtener el valor de VALOR EN AIRE y VALOR EN AGUA es necesario hacer pruebas 
 * antes, cada sensor puede dar valores distintos
 */
const int VALOR_EN_AIRE = 620; //valor maximo que da el sensor en aire
const int VALOR_EN_AGUA = 310; //valor maximo que da el sensor totalmente submergido
const int PIN_SENSOR_HUMEDAD = A0;
const int PIN_RELE = 10;

int valorSensorHumedad = 0;
int porcentajeValorSensorHumedad = 0;

void setup()
{
    Serial.begin(9600); //abre el puerto serial
    pinMode(PIN_RELE, OUTPUT);
}

//En estas funcion es donde se estara ejecutando el codigo de la placa en bucle
void loop()
{
}

//Actualiza las variables con una lectura del sensor
void leerHumedadSuelo()
{
    valorSensorHumedad = analogRead(PIN_SENSOR_HUMEDAD);
    porcentajeValorSensorHumedad = map(valorSensorHumedad, VALOR_EN_AIRE, VALOR_EN_AGUA, 0, 100);
}

int getValorSensorHumedad()
{
    leerHumedadSuelo();        //actualiza variables
    return valorSensorHumedad; //devuelve el valor del sensor sin transformar
}

int getPorcentajeHumedad()
{
    leerHumedadSuelo();                  //actualiza variables
    return porcentajeValorSensorHumedad; //devuelve el porcentaje de humedad
}

/**
 * Deja activo el rele durante el tiempo que le pasemos en millisegundos
 * (1000 = 1 segundo)
 */
void activarRele(long tiempo)
{
    bool salir = false;
    long horaActivada = millis();
    digitalWrite(PIN_RELE, HIGH);
    while (salir == false)
    {
        if (millis() - horaActivada > tiempo)
        {
            digitalWrite(PIN_RELE, LOW);
            salir = true;
        }
    }
}