void Layersflashandfall()
{
  //Delays in the program (in ms)
  int delay1 = 100;
  //This array stores the column numbers of the cube
  int allcolumns[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 ,14, 15};
  //Maximum index number of the array
  int arrindex = 15;
  //Size of the array
  int arrsize = 16;
  
  //Loops through all four of the layers turning them off
  for(int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 0);
  }
	
	//Loops through all of the layers.
	for(int i = 4; i !=0; i--)
	{
	  //Flashes the layer on quicker increments 
	  int delvar = 150;
	  while (delvar != 0)
	  {
		digitalWrite(layer[i-1], 1);
		delay(delvar);
		digitalWrite(layer[i-1], 0);
		delay(delvar);
		delvar -= 15;
	  }
	  //Keeps the layer lit up after it has flashed on
	  if (i == 4)
	  {
		digitalWrite(layer[i-1], 1);
	  }
	  else if (i == 3)
	  {
		digitalWrite(layer[i-1], 1);
	  }
	  else if(i == 2)
	  {
		digitalWrite(layer[i-1], 1);
	  }
	  else
	  {
		digitalWrite(layer[i-1], 1); 
	  }
	}

  delay(500);
	
  //Turns all of the LED's off
  AllLedsOff();
  
  //Produces the rain effect 16 times as one LED is removed each time
  for(int i = 0; i != 16; i++)
  {
	//Turns all of the columns on
    for(int p = 0; p < arrindex; p++)
    {
      digitalWrite(column[p], 0);
    }
	
	//Turns on the top LED of each column and the one below it adding, 
	//a delay afterwards to create the rain effect.
    digitalWrite(layer[0], 1);
    delay(delay1+50);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 1);
    delay(delay1);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[2], 1);
    delay(delay1);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 1);
    delay(delay1+50);
    digitalWrite(layer[3], 0);
	
	//Turns all of the columns off
    for(int p = 0; p < arrindex; p++)
    {
      digitalWrite(column[p], 1);
    }
	
	//Turns a random column off by removing a column from the array.
    int randomColumn = random(0,arrsize);
    for(int i = 0; i < arrsize; i++)
    {
      if(allcolumns[i] == randomColumn)
      {
        for(int j = i; j < arrsize; j++)
        {
          allcolumns[j] = allcolumns[j+1];
        }
        arrsize--;
      }
    }   
    arrindex--;
  }
}