using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Text;
using System.Web.Http;
using System.Web;
using Newtonsoft.Json;
using AemClient;

namespace AEMWebsite.Controllers
{
    public class JsonFile1Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem1.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }
    public class JsonFile2Controller : ApiController
    {
        public HttpResponseMessage Get()
        {
            var json = File.ReadAllText(System.Web.HttpContext.Current.Server.MapPath(@"~/App_Data/newitem2.json"));

            return new HttpResponseMessage()
            {
                Content = new StringContent(json, Encoding.UTF8, "application/json"),
                StatusCode = HttpStatusCode.OK
            };
        }
    }
}

