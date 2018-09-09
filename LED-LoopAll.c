void Loopallleds()
{
  //Creating an array of the outside LED's
  int outisdeloop[12] = {0,1,2,3,7,11,15,14,13,12,8,4};
  //Creating an array of the inside LED's
  int insideloop[4] = {5,6,10,9};
  //Delays in the program (in ms)
  int delay1 = 15;
  int delay2 = 25;
  
  //This function turns all of the LED's off.
  AllLedsOff();
  
  //Loops four times for all of the layers
	for(int j = 3; j >= 0; j--)
	{
	  digitalWrite(layer[j], 1);
	  //Loops around all of the outside LED's turning them on and then off.
	  for(int i = 0; i<12; i++)
	  {
		digitalWrite(column[array[i]], 0);
		delay(delay1);
		digitalWrite(column[array[i]], 1);
		delay(delay1);
	  }
	  digitalWrite(layer[j], 0);
	}
	
	//Loops around all of the inside LED's turning them on and then off.
	for(int j = 0; j < 4; j++)
	{
	  digitalWrite(layer[j], 1);
	  for(int i = 0; i < 4; i++)
	  {
		digitalWrite(column[array2[i]], 0);
		delay(delay2);
		digitalWrite(column[array2[i]], 1);
		delay(delay2);
	  }
	  digitalWrite(layer[j], 0);
	}
}
