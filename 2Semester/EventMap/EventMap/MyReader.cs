﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EventMap
{
    public class MyReader
    {
        public int ourDogLine;
        public int ourDogCollumn;

        public string[] ReadMapFromFile()
        {
            FileStream file = new FileStream(@"C:\Users\Пользователь\Desktop\2semester\EventMap\EventMap\bin\Debug\Map.txt", FileMode.Open, FileAccess.ReadWrite);
            StreamReader reader = new StreamReader(file, System.Text.Encoding.Default);

            string line;
            int numberOfLines = 0;
            string[] arrayOfMap = new string[6];

            while ((line = reader.ReadLine()) != null)
            {
                arrayOfMap[numberOfLines] = line;
                numberOfLines++;
            }

            int numberOfCollumns = arrayOfMap[0].Length;

            ourDogLine = 0;
            ourDogCollumn = 0;
            for (int i = 0; i < numberOfLines; ++i)
            {
                for (int j = 0; j < numberOfCollumns; ++j)
                {
                    if (System.Convert.ToChar(arrayOfMap[i].ElementAt(j)) == '@')
                    {
                        ourDogLine = i;
                        ourDogCollumn = j;
                        break;
                    }
                }
            }
            return arrayOfMap;
        }
    }
}
