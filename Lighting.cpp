void onOccSensor(String sensorId, int state){
occSensors.sensorId.state = state;
if(state == 1){
clearTimeout(occSensors.sensorId.timer);
for(int i=0;i<sizeof(occSensors.sensorId.lights);i++){
setLight(occSensors.sensorId.lights[i], 1);
}
if(state == 0){
setTimeout(occSensors.sensorId.timer, occTimer(sensorId));
}
}

void occTimer(String sensorId){
for(int i=0;i<sizeof(occSensors.sensorId.lights);i++){
setLight(occSensors.sensorId.lights[i], 0);
}

