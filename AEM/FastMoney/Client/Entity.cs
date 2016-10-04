using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AemClient
{

    public class Rootobject
    {
        public Newslist[] newsList { get; set; }
        public string fallBackFileReference { get; set; }
        public object timeStamp { get; set; }
    }

    public class Newslist
    {
        public string image { get; set; }
        public string imagelocalfolder { get; set; }
        public string video { get; set; }
        public string videolocalfolder { get; set; }
        public string headline { get; set; }
        public string _abstract { get; set; }
        public string category { get; set; }
        public DateTime jcrcreated { get; set; }
        public DateTime cqlastmodified { get; set; }
        public string newsappauthor { get; set; }
        public string jcruuid { get; set; }
        public DateTime onTime { get; set; }



        public string[] cqtags { get; set; }
        //public string cqtagsStr
        //{
        //    get
        //    {
        //        if (cqtags==null)
        //        {
        //            return "";
        //        }
        //        string str = "";
        //        foreach (var item in cqtags)
        //        {
        //            str += item;
        //        }
        //        return str;
        //    }

        //}
        public object offTime { get; set; }

    }

    class Entity
    {
    }
}
