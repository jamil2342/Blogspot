﻿using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AemClient
{
    class Utility
    {
        public static string getFileName(string hreflink)
        {
            Uri uri = new Uri(hreflink);
            string filename="";
            if (uri.IsFile)
            {
                 filename = System.IO.Path.GetFileName(uri.LocalPath);
            }
            return filename;
        }


        public static string GetRegValue(string path,string key)
        {

            RegistryKey OurKey = Registry.LocalMachine;
            OurKey = OurKey.OpenSubKey(path, true);
            string str = OurKey.GetValue(key).ToString();
            return str;


        }
    }
}
