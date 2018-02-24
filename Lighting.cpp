void onOccSensor(String sensorId, int state){
  if(state == 1 && occSensors.sensorId.state == 0){
    occSensors.sensorId.state = 1;
    xTimerDelete(occSensors.sensorId.timer);
    for(int i=0;i<sizeof(occSensors.sensorId.lights);i++){
      setLight(occSensors.sensorId.lights[i], 1);
    }
  }
  if(state == 0 && occSensors.sensorId.state == 1){
    occSensors.sensorId.state = 0;
    occSensors.sensorId.timer = xTimerCreate("", occSensors.sensorId.time, pdFALSE, occTimer(sensorId));
  }
}

void occTimer(String sensorId){
  for(int i=0;i<sizeof(occSensors.sensorId.lights);i++){
  setLight(occSensors.sensorId.lights[i], 0);
  }
}

void setLight(String lightId, int state){
  lights.lightId.state = state;
  if(state == 0){
    sendRequest("PUT", lights.lightId.address + "/bright", 0);
  }
  if(state == 1){
    sendRequest("PUT", lights.lightId.address + "/bright", lights.lightId.brightness);
  }
}

void onLightSensor(String sensorId, int value){
  if(value >= lightSensors.sensorId.thresh){
    lightSensors.sensorId.state = 0;
  }
  if(value <= lightSensors.sensorId.thresh){
    lightSensors.sensorId.state = 1;
  }
  for(int i=0;i<sizeof(lightSensors.sensorId.lights);i++){
    setLight(lightSensors.sensorId.lights[i], state);
  }
}

